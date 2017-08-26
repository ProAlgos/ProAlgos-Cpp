#pragma once
#include<stack>

using namespace std;

struct Disk {
	//Size will determine which disk is bigger or smaller. Goes from smallest (top) to biggest (bottom, largest)
	int size;
};

struct Peg {
	stack<Disk> disks_on_peg;
};



class TowerOfHanoi
{
private:
	Peg Source;
	Peg Destination;
	Peg Temp;

	int num_of_disks;
	Disk * disk_array;
	TowerOfHanoi();

	void Solve_Hanoi_Recursive(int n, Peg& Source, Peg& Destination, Peg& temp);
	void Move_Disks(Peg& source, Peg& destination);
public:
	void Solve_Hanoi();

	TowerOfHanoi(int num_of_disks);
	~TowerOfHanoi();
};

