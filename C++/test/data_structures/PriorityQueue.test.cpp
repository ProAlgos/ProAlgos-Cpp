#define PRIORITY_QUEUE_TEST
#define CATCH_CONFIG_MAIN

#include "../../include/third_party/catch.hpp"
#include "../../include/data_structures/PriorityQueue.cpp"

TEST_CASE("Checking max() and remove() functions return the expected value", "[PriorityQueue]"){

	PriorityQueue pq; // creating PriorityQueue class object
	pq.insert(100);
	pq.insert(120);
	pq.insert(200);
	pq.insert(180);

	REQUIRE(pq.max() == 200);
	REQUIRE(pq.remove() == 200);
	REQUIRE(pq.remove() == 180);
	REQUIRE(pq.max() == 120);

	pq.insert(300);
	pq.insert(110);

	REQUIRE(pq.max() == 300);
	REQUIRE(pq.remove() == 300);
	REQUIRE(pq.remove() == 120);
	REQUIRE(pq.max() == 110);
	REQUIRE(pq.remove() == 110);


}
TEST_CASE("Checking after inserting the same priorities we are getting expected value", "[PriorityQueue]"){

	PriorityQueue pq; // creating PriorityQueue class object
	pq.insert(10);
	pq.insert(12);
	pq.insert(20);
	pq.insert(12);
	pq.insert(20);

	REQUIRE(pq.max() == 20);
	REQUIRE(pq.remove() == 20);
	REQUIRE(pq.remove() == 20);
	REQUIRE(pq.max() == 12);
	REQUIRE(pq.remove() == 12);
	REQUIRE(pq.remove() == 12);
	REQUIRE(pq.max() == 10);
	REQUIRE(pq.remove() == 10);
	REQUIRE(pq.max() == -1); // Priority queue is empty
}
TEST_CASE("Checking whether max() and remove() return -1 if priority queue is empty", "[PriorityQueue]"){

	PriorityQueue pq;

	pq.insert(20);
	pq.insert(22);
	pq.insert(30);
	pq.insert(28);

	REQUIRE(pq.max() == 30);
	REQUIRE(pq.remove() == 30);
	REQUIRE(pq.remove() == 28);
	REQUIRE(pq.max() == 22);

	pq.insert(40);
	pq.insert(21);

	REQUIRE(pq.max() == 40);
	REQUIRE(pq.remove() == 40);
	REQUIRE(pq.remove() == 22);
	REQUIRE(pq.max() == 21);
	REQUIRE(pq.remove() == 21);
	REQUIRE(pq.remove() == 20);
	REQUIRE(pq.remove() == -1); // priority queue is empty, nothing to remove
	REQUIRE(pq.max() == -1) ;//     priority queue is empty

}

#undef PRIORITY_QUEUE_TEST
