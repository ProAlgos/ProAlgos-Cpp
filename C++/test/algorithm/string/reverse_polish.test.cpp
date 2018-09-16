#include "reverse_polish.cpp"
#include "gtest/gtest.h"


class OperatorOperationsTest : public :: testing::Test{

protected:
	virtual void SetUp() override {
		//
	}
	virtual void TearDown() {
		//
	}
	OperatorOperations test_operations;
	vector <string> input_vector;
	vector <string> result_vector;
};


TEST_F(OperatorOperationsTest,validCase){

	input_vector.push_back("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3");
	input_vector.push_back("3+4 * 2 /( 1 - 5 ) ^ 2 ^ 3");
	input_vector.push_back("3 ^ 1 / (5 * 6) + 10");

	result_vector = test_operations.to_reverse_polish(input_vector);

	EXPECT_EQ(result_vector.at(0), "342*15-23^^/+");
	EXPECT_EQ(result_vector.at(1), "342*15-23^^/+");
	EXPECT_EQ(result_vector.at(2), "31^56*/10+");


}
TEST_F(OperatorOperationsTest,emptyCase){

	input_vector.push_back(" ");
	input_vector.push_back("");

	result_vector = test_operations.to_reverse_polish(input_vector);

	EXPECT_EQ(result_vector.at(0), "");
	EXPECT_EQ(result_vector.at(1), "");


}

TEST_F(OperatorOperationsTest,invalidCase){

	input_vector.push_back("hello");
	input_vector.push_back("he2o");
	input_vector.push_back("hell0");

	result_vector = test_operations.to_reverse_polish(input_vector);

	EXPECT_EQ(result_vector.at(0), "hello");
	EXPECT_EQ(result_vector.at(1), "he2o");
	EXPECT_EQ(result_vector.at(2), "hell0");

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
