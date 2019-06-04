#include <random>
#include <limits>
#include "third_party/catch.hpp"
#include "algorithm/sorting/bubble_sort.hpp"

// Prototypes
int generate_random_int(int, int);
vector<int> generate_unsorted_vector();

// Pointer to function
using sorting_function = void(*)(vector<int>&, int, bool);

TEST_CASE("Sort in ascending order", "[sorting]") {
	// Sorting algorithms
	vector<sorting_function> sorting_functions = {
			bubble_sort
	};

	vector<int> original, algo_sorted, std_sorted;

	int times_to_run = 20;
	while (times_to_run--) {
		original = algo_sorted = std_sorted = generate_unsorted_vector();
		std::sort(std_sorted.begin(), std_sorted.end());

		// Run tests
		for (auto sorting_algo : sorting_functions) {
			sorting_algo(algo_sorted, 1, false);
			REQUIRE(algo_sorted == std_sorted);
			algo_sorted = original;
		}
	}
}

TEST_CASE("Sort in descending order", "[sorting]") {
	// Sorting algorithms
	vector<sorting_function> sorting_functions = {
			bubble_sort
	};

	vector<int> original, algo_sorted, std_sorted;

	int times_to_run = 20;
	while (times_to_run--) {
		original = algo_sorted = std_sorted = generate_unsorted_vector();
		std::sort(std_sorted.rbegin(), std_sorted.rend());

		// Run tests
		for (auto sorting_algo : sorting_functions) {
			sorting_algo(algo_sorted, -1, false);
			REQUIRE(algo_sorted == std_sorted);
			algo_sorted = original;
		}
	}
}

/*
	generate_unsorted_vector
	------------------------
	Generates a vector with a random size (up to 100) and fills with random integers.
*/
vector<int> generate_unsorted_vector() {
	vector<int> v;
	auto vectorSize = (size_t) generate_random_int(1, 1000);
	v.reserve(vectorSize);

	for (int i = 0; i < (int) vectorSize; i++) {
		v.push_back(generate_random_int(-32767, 32767));
	}
	return v;
}

/*
	generate_random_int
	-------------------
	Generates a random int between min and max.
*/
int generate_random_int(int min, int max) {
	std::default_random_engine generator(std::random_device{}());
	std::uniform_int_distribution<> intRange(min, max);
	return intRange(generator);
}
