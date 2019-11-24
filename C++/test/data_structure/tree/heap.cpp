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
    tree.insert(12);	
    tree.insert(29);
    tree.insert(21);
    tree.insert(32);
    tree.insert(35);
    tree.insert(5);
    tree.insert(23);
    tree.insert(21);
    tree.insert(3);
    tree.insert(9);
    tree.insert(1);

    //Verify the size
    REQUIRE(tree.get_size() == 11);

    //Verify the top of the tree
    REQUIRE(tree.remove() == 35);
    REQUIRE(tree.remove() == 32);
    REQUIRE(tree.remove() == 29);
    REQUIRE(tree.remove() == 23);
    REQUIRE(tree.remove() == 21);
    REQUIRE(tree.remove() == 21);
    REQUIRE(tree.remove() == 12);
    REQUIRE(tree.remove() == 9);
    REQUIRE(tree.remove() == 5);
    REQUIRE(tree.remove() == 3);
    REQUIRE(tree.remove() == 1);

    //Verify the final size
    REQUIRE(tree.get_size() == 0);

}

TEST_CASE("Add and remove values in a min heap", "[heap]"){
    Heap<int, Max_Comparator> tree;

    //Inserts elements
    tree.insert(12);	
    tree.insert(29);
    tree.insert(21);
    tree.insert(32);
    tree.insert(35);
    tree.insert(5);
    tree.insert(23);
    tree.insert(21);
    tree.insert(3);
    tree.insert(9);
    tree.insert(1);

    //Verify the size
    REQUIRE(tree.get_size() == 11);

    //Verify the top of the tree
    REQUIRE(tree.remove() == 1);
    REQUIRE(tree.remove() == 3);
    REQUIRE(tree.remove() == 5);
    REQUIRE(tree.remove() == 9);
    REQUIRE(tree.remove() == 12);
    REQUIRE(tree.remove() == 21);
    REQUIRE(tree.remove() == 21);
    REQUIRE(tree.remove() == 23);
    REQUIRE(tree.remove() == 29);
    REQUIRE(tree.remove() == 32);
    REQUIRE(tree.remove() == 35);

    
    //Verify the final size
    REQUIRE(tree.get_size() == 0);
}

TEST_CASE("Exceptions from the heap", "[heap]"){
    Heap<int, Min_Comparator> tree;

    //Attempt of remove from an empty heap tree
    try{
        tree.remove();
    }catch(int exception){
        REQUIRE(exception == -1);
    }

    //Attempt of get the top element from an empty heap tree
    try{
        tree.top();
    }catch(int exception){
        REQUIRE(exception == -1);
    }
}

