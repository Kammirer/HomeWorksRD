#pragma once
#include <cstdlib>

template<class T>
class DynamicArray
{
public:
	DynamicArray();

	DynamicArray(std::size_t size);

	DynamicArray(const DynamicArray<T>& other);

	~DynamicArray();

	DynamicArray& operator=(const DynamicArray<T>& other);

	T& operator[](std::size_t index);

	void setSize(std::size_t newSize);
	std::size_t getSize() const;

	void clear();

	void push_back(T element);

	// New methods
	void reserve(std::size_t reservedSpace);
	std::size_t getCapacity() const;
	void shrinkToFit();
	void pop_back();
	T back() const;
	bool operator==(const DynamicArray<T>& other) const;

private:
	std::size_t sizeDyn;
	std::size_t capacity = 0;
	T* arrayDyn;
};

//default c-tor
template<class T>
DynamicArray<T>::DynamicArray() {
	sizeDyn = 0;
	capacity = 0;
	arrayDyn = nullptr;
}

//c-tor with size
template<class T>
DynamicArray<T>::DynamicArray(std::size_t size) {
	sizeDyn = size;
	capacity = 0;
	arrayDyn = new T[size];
}

//copy c-tor
template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
	sizeDyn = other.sizeDyn;
	arrayDyn = new T[other.sizeDyn];
	capacity = other.capacity;
	std::memcpy(arrayDyn, other.arrayDyn, sizeDyn * sizeof(T));
}

//free allocated memory (d-tor)
template<class T>
DynamicArray<T>::~DynamicArray() {
	delete[] arrayDyn;
}

// operator=
template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
	delete[] arrayDyn;
	sizeDyn = other.sizeDyn;
	capacity = other.capacity;
	arrayDyn = new T[sizeDyn];
	std::memcpy(arrayDyn, other.arrayDyn, sizeDyn * sizeof(T));
	return *this;
}

// operator[] (return element by index)
template<class T>
T& DynamicArray<T>::operator[](std::size_t index) {
	return arrayDyn[index];
}

// new Size by array
template<class T>
void DynamicArray<T>::setSize(std::size_t newSize) {
	if (newSize > sizeDyn) {
		T* newArray = new T[newSize];
		std::memcpy(newArray, arrayDyn, newSize * sizeof(T));
		delete[] arrayDyn;
		sizeDyn = newSize;
		arrayDyn = newArray;
	}
}

// get size
template<class T>
std::size_t DynamicArray<T>::getSize() const {
	return sizeDyn;
}

// clear memory & reset data
template<class T>
void DynamicArray<T>::clear() {
	delete[] arrayDyn;
	sizeDyn = 0;
	capacity = 0;
	arrayDyn = nullptr;
}

// push_back
template<class T>
void DynamicArray<T>::push_back(T element) {
	T* newArray = new T[sizeDyn + 1];
	std::memcpy(newArray, arrayDyn, sizeDyn * sizeof(T));
	newArray[sizeDyn] = element;
	delete[] arrayDyn;
	sizeDyn++;
	arrayDyn = newArray;
}

// Reserve memory
template<class T>
void DynamicArray<T>::reserve(std::size_t reservedSpace) {
	if (reservedSpace > capacity) {
		T* newArray = new T[reservedSpace];
		std::memcpy(newArray, arrayDyn, sizeDyn * sizeof(T));
		delete[] arrayDyn;
		capacity = reservedSpace;
		arrayDyn = newArray;
	}
}

// Get capacity
template<class T>
std::size_t DynamicArray<T>::getCapacity() const {
	return capacity;
}

// Shrink to fit
template<class T>
void DynamicArray<T>::shrinkToFit() {
	if (sizeDyn < capacity) {
		T* newArray = new T[sizeDyn];
		std::memcpy(newArray, arrayDyn, sizeDyn * sizeof(T));
		delete[] arrayDyn;
		capacity = sizeDyn;
		arrayDyn = newArray;
	}
}

// Pop back
template<class T>
void DynamicArray<T>::pop_back() {
	if (sizeDyn > 0) {
		--sizeDyn;
	}
}

// Return last element
template<class T>
T DynamicArray<T>::back() const {
	return arrayDyn[sizeDyn - 1];
}

// Equality operator
template<class T>
bool DynamicArray<T>::operator==(const DynamicArray<T>& other) const {
	if (sizeDyn != other.sizeDyn) {
		return false;
	}
	for (std::size_t i = 0; i < sizeDyn; ++i) {
		if (arrayDyn[i] != other.arrayDyn[i]) {
			return false;
		}
	}
	return true;
}