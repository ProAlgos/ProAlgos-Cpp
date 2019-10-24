#include "algorithm/string/shunting_yard.hpp"
#include "third_party/catch.hpp"

TEST_CASE("Valid cases", "[string][shunting_yard]") {
    OperatorOperations test_operations;
    std::vector <string> test_input_vector;
    std::vector <string> test_result_vector;
    std::vector <string> test_expected_result_vector;

    test_input_vector.emplace_back("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3");
	test_input_vector.emplace_back("3+4 * 2 /( 1 - 5 ) ^ 2 ^ 3");
	test_input_vector.emplace_back("3 ^ 1 / (5 * 6) + 10");
	test_expected_result_vector.emplace_back("342*15-23^^/+");
	test_expected_result_vector.emplace_back("342*15-23^^/+");
	test_expected_result_vector.emplace_back("31^56*/10+");
	test_result_vector = test_operations.to_reverse_polish(test_input_vector);
	REQUIRE(test_expected_result_vector == test_result_vector);
}

TEST_CASE("Empty cases", "[string][shunting_yard]") {
    OperatorOperations test_operations;
    std::vector <string> test_input_vector;
    std::vector <string> test_result_vector;
    std::vector <string> test_expected_result_vector;

    test_input_vector.emplace_back(" ");
	test_input_vector.emplace_back("");
	test_expected_result_vector.emplace_back("");
	test_expected_result_vector.emplace_back("");
	test_result_vector = test_operations.to_reverse_polish(test_input_vector);
	REQUIRE(test_expected_result_vector == test_result_vector);
}

TEST_CASE("Invalid cases", "[string][shunting_yard]") {
    OperatorOperations test_operations;
    std::vector <string> test_input_vector;
    std::vector <string> test_result_vector;
    std::vector <string> test_expected_result_vector;

    test_input_vector.emplace_back("hello");
	test_input_vector.emplace_back("he2o");
	test_input_vector.emplace_back("hell0");
	test_expected_result_vector.emplace_back("hello");
	test_expected_result_vector.emplace_back("he2o");
	test_expected_result_vector.emplace_back("hell0");
	test_result_vector = test_operations.to_reverse_polish(test_input_vector);
	REQUIRE(test_expected_result_vector == test_result_vector);
}
