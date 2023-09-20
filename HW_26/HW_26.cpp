#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <numeric>

std::vector<int> generateVector(int sizeVector) {
	std::vector<int> resultVector;
	srand(time(nullptr));
	for (int i = 0; i < sizeVector; i++) {
		int randNumber = rand() % 9;
		resultVector.push_back(randNumber);
	}
	return resultVector;
}

int sumNumVector(const std::vector<int>& vector, int numThreads) {
	int chunk = vector.size() / numThreads; // parts of the initial vector (depending on the number of threads passed to the function)
	std::vector<std::thread> threads; // threads vector
	std::vector<int> results(numThreads, 0); // vector with sum, results of sub_vector

	for (int i = 0; i < numThreads; ++i) {
		int start = i * chunk;
		int end = (i == numThreads - 1) ? vector.size() : (i + 1) * chunk;

		threads.emplace_back([start, end, &vector, &results, chunk]() {
			int sum = 0;
			for (int j = start; j < end; ++j) {
				sum += vector[j];
			}
			results[start / chunk] = sum; // sum chank & add to vector
			});
	}

	for (std::thread& t : threads) { // end all thread
		t.join();
	}

	return std::accumulate(results.begin(), results.end(), 0); // final sum
}

int main()
{
	const int sizeVector = 100'000'000;
	std::vector<int> myVector = generateVector(sizeVector);
	int sumVector = 0;
	int numThreads = std::thread::hardware_concurrency(); // 8

	// 1 thread
	const auto begin1 = std::chrono::high_resolution_clock::now();

	sumVector = sumNumVector(myVector, 1);

	const auto end1 = std::chrono::high_resolution_clock::now();
	const auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
	std::cout << "1 thread, sum vector: " << sumVector << ", time: " << duration1.count() << std::endl;

	// 2 threads
	const auto begin2 = std::chrono::high_resolution_clock::now();

	sumVector = sumNumVector(myVector, 2);

	const auto end2 = std::chrono::high_resolution_clock::now();
	const auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
	std::cout << "2 thread, sum vector: " << sumVector << ", time: " << duration2.count() << std::endl;

	// hardware_concurrency()
	const auto begin3 = std::chrono::high_resolution_clock::now();

	sumVector = sumNumVector(myVector, numThreads);

	const auto end3 = std::chrono::high_resolution_clock::now();
	const auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - begin3);
	std::cout << "hardware_concurrency (" << numThreads << ") thread, sum vector: " << sumVector << ", time: " << duration3.count() << std::endl;

	// hardware_concurrency() * 2
	const auto begin4 = std::chrono::high_resolution_clock::now();

	sumVector = sumNumVector(myVector, numThreads * 2);

	const auto end4 = std::chrono::high_resolution_clock::now();
	const auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - begin4);
	std::cout << "hardware_concurrency * 2 (" << numThreads * 2 << ") thread, sum vector: " << sumVector << ", time: " << duration4.count() << std::endl;

	return 0;
}