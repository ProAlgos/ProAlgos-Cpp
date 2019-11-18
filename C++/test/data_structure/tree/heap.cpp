#include "third_party/catch.hpp"
#include "data_structure/tree/heap.hpp"

bool Max_Comparator(int& t1, int& t2){	//Verify if t1 is greater or equal than t2 (used in min heap)
	if(t1 >= t2){
		return true;
	}

	return false;
}

bool Min_Comparator(int& t1, int& t2){  //Verify if t1 is lesser than t2 (used in max heap)
	if(t1 < t2){
		return true;
	}

	return false;
}



TEST_CASE("Add and remove values in a max heap", "[heap]"){
    Heap<int, Min_Comparator> tree;

    //Inserts elements
    tree.Push_Heap(12);	
    tree.Push_Heap(29);
    tree.Push_Heap(21);
    tree.Push_Heap(32);
    tree.Push_Heap(35);
    tree.Push_Heap(5);
    tree.Push_Heap(23);
    tree.Push_Heap(21);
    tree.Push_Heap(3);
    tree.Push_Heap(9);
    tree.Push_Heap(1);

    //Verify the size
    REQUIRE(tree.Get_Size() == 11);

    //Verify the top of the tree
    REQUIRE(tree.Pop_Heap() == 35);
    REQUIRE(tree.Pop_Heap() == 32);
    REQUIRE(tree.Pop_Heap() == 29);
    REQUIRE(tree.Pop_Heap() == 23);
    REQUIRE(tree.Pop_Heap() == 21);
    REQUIRE(tree.Pop_Heap() == 21);
    REQUIRE(tree.Pop_Heap() == 12);
    REQUIRE(tree.Pop_Heap() == 9);
    REQUIRE(tree.Pop_Heap() == 5);
    REQUIRE(tree.Pop_Heap() == 3);
    REQUIRE(tree.Pop_Heap() == 1);

    //Verify the final size
    REQUIRE(tree.Get_Size() == 0);

}

TEST_CASE("Add and remove values in a min heap", "[heap]"){
    Heap<int, Max_Comparator> tree;

    //Inserts elements
    tree.Push_Heap(12);	
    tree.Push_Heap(29);
    tree.Push_Heap(21);
    tree.Push_Heap(32);
    tree.Push_Heap(35);
    tree.Push_Heap(5);
    tree.Push_Heap(23);
    tree.Push_Heap(21);
    tree.Push_Heap(3);
    tree.Push_Heap(9);
    tree.Push_Heap(1);

    //Verify the size
    REQUIRE(tree.Get_Size() == 11);

    //Verify the top of the tree
    REQUIRE(tree.Pop_Heap() == 1);
    REQUIRE(tree.Pop_Heap() == 3);
    REQUIRE(tree.Pop_Heap() == 5);
    REQUIRE(tree.Pop_Heap() == 9);
    REQUIRE(tree.Pop_Heap() == 12);
    REQUIRE(tree.Pop_Heap() == 21);
    REQUIRE(tree.Pop_Heap() == 21);
    REQUIRE(tree.Pop_Heap() == 23);
    REQUIRE(tree.Pop_Heap() == 29);
    REQUIRE(tree.Pop_Heap() == 32);
    REQUIRE(tree.Pop_Heap() == 35);

    //Verify the final size
    REQUIRE(tree.Get_Size() == 0);
}

TEST_CASE("Exceptions from the heap", "[heap]"){
	Heap<int, Min_Comparator> tree;

	//Attempt of remove from an empty heap tree
	try{
		tree.Pop_Heap();
	}catch(int exception){
		REQUIRE(exception == -1);
	}

	//Attempt of get the top element from an empty heap tree
	try{
		tree.Get_Top();
	}catch(int exception){
		REQUIRE(exception == -1);
	}
}
