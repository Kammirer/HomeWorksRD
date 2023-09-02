#pragma once
#include <cstdlib>

template<class T, int size>
class InplaceArray
{
public:
	InplaceArray();
	InplaceArray(const InplaceArray<T, size>& other);

	~InplaceArray();

	InplaceArray& operator=(const InplaceArray<T, size>& other);

	T& operator[](int index);

	int getSize() const;
	std::size_t getCapacity() const;

	void clear();
	void push_back(T element);
	void pop_back();
	T back() const;
	bool operator==(const InplaceArray<T, size>& other) const;

private:
	std::size_t sizeInplace;
	T arrayInplace[size];
};

//default c-tor
template<class T, int size>
InplaceArray<T, size>::InplaceArray() {
	sizeInplace = size;
}

//copy c-tor
template<class T, int size>
InplaceArray<T, size>::InplaceArray(const InplaceArray<T, size>& other) : sizeInplace(size) {
	for (int i = 0; i < size; ++i) {
		arrayInplace[i] = other.arrayInplace[i];
	}
}

//free allocated memory (d-tor)
template<class T, int size>
InplaceArray<T, size>::~InplaceArray() {
}

// operator=
template<class T, int size>
InplaceArray<T, size>& InplaceArray<T, size>::operator=(const InplaceArray<T, size>& other) {
	sizeInplace = other.sizeInplace;
	arrayInplace = new T[size];
	std::memcpy(arrayInplace, other.arrayInplace, sizeInplace * sizeof(T));
	return *this;
}

// operator[] (return element by index)
template<class T, int size>
T& InplaceArray<T, size>::operator[](int index) {
	return arrayInplace[index];
}

// get size
template<class T, int size>
int InplaceArray<T, size>::getSize() const {
	return sizeInplace;
}

// clear memory & reset data
template<class T, int size>
void InplaceArray<T, size>::clear() {
	delete[] arrayInplace;
	sizeInplace = 0;
	arrayInplace = nullptr;
}


template<class T, int size>
void InplaceArray<T, size>::push_back(T element) {
	arrayInplace[sizeInplace] = element;
	sizeInplace++;
}

// Get capacity
template<class T, int size>
std::size_t InplaceArray<T, size>::getCapacity() const {
	return size;
}

// Pop back
template<class T, int size>
void InplaceArray<T, size>::pop_back() {
	if (sizeInplace > 0) {
		sizeInplace--;
	}
}

// Return last element
template<class T, int size>
T InplaceArray<T, size>::back() const {
	return arrayInplace[sizeInplace - 1];
}

// Equality operator
template<class T, int size>
bool InplaceArray<T, size>::operator==(const InplaceArray<T, size>& other) const {
	if (sizeInplace != other.sizeInplace) {
		return false;
	}
	for (std::size_t i = 0; i < sizeInplace; ++i) {
		if (arrayInplace[i] != other.arrayInplace[i]) {
			return false;
		}
	}
	return true;
}