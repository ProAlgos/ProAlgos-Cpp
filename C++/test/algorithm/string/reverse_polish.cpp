#include "algorithm/string/reverse_polish.hpp"
#include "third_party/catch.hpp"

class UniqueTestsFixture {
	protected:
		OperatorOperations test_operations;
		std::vector <string> test_input_vector;
		std::vector <string> test_result_vector;
		std::vector <string> test_expected_result_vector;
};

TEST_CASE_METHOD(UniqueTestsFixture, "valid cases"){
	test_input_vector.push_back("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3");
	test_input_vector.push_back("3+4 * 2 /( 1 - 5 ) ^ 2 ^ 3");
	test_input_vector.push_back("3 ^ 1 / (5 * 6) + 10");
	test_expected_result_vector.push_back("342*15-23^^/+");
	test_expected_result_vector.push_back("342*15-23^^/+");
	test_expected_result_vector.push_back("31^56*/10+");
	test_result_vector = test_operations.to_reverse_polish(test_input_vector);
	REQUIRE(test_expected_result_vector == test_result_vector);
}

TEST_CASE_METHOD(UniqueTestsFixture, "empty cases") {
	test_input_vector.push_back(" ");
	test_input_vector.push_back("");
	test_expected_result_vector.push_back("");
	test_expected_result_vector.push_back("");
	test_result_vector = test_operations.to_reverse_polish(test_input_vector);
	REQUIRE(test_expected_result_vector == test_result_vector);
}

TEST_CASE_METHOD(UniqueTestsFixture, "invalid cases") {
	test_input_vector.push_back("hello");
	test_input_vector.push_back("he2o");
	test_input_vector.push_back("hell0");
	test_expected_result_vector.push_back("hello");
	test_expected_result_vector.push_back("he2o");
	test_expected_result_vector.push_back("hell0");
	test_result_vector = test_operations.to_reverse_polish(test_input_vector);
	REQUIRE(test_expected_result_vector == test_result_vector);
}
