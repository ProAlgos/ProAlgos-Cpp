#include "TowerOfHanoi.hpp"
/*

	Tower of Hanoi Problem
	-------------------
	PROBLEM:
	Find a way to move an entire stack of disks from one rod to another.

	The puzzle starts with the disks in a neat stack in ascending order of size on one rod,
	the smallest at the top, thus making a conical shape.

	The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

	1. Only one disk can be moved at a time.
	2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.
	3. No disk may be placed on top of a smaller disk.

	SOLUTION:
		START
			Procedure Hanoi(disk, source, dest, aux)

				IF disk == 1, THEN
					move disk from source to dest             
				ELSE
					Hanoi(disk - 1, source, aux, dest)     // Step 1
					move disk from source to dest          // Step 2
					Hanoi(disk - 1, aux, dest, source)     // Step 3
				END IF
			END Procedure
		STOP

	Time complexity
	---------------
	2^n - 1, where n is the number of disks

	Space complexity
	----------------
	No idea... I think its O(1)
	O(...), where <description of variable(s)>
*/


TowerOfHanoi::TowerOfHanoi()
{
	disk_array = nullptr;
}

TowerOfHanoi::TowerOfHanoi(int num_of_disks)
{
	this->num_of_disks = num_of_disks;

	//Initialize the disk arrays
	disk_array = new Disk[num_of_disks];
	for (int i = 0; i < num_of_disks; i++) {
		disk_array[i].size = i;
	}

	//Initialize pegs so that n will be at bottom and 0 will be at top
	for (int i = num_of_disks - 1; i >= 0; i--) {
		Source.disks_on_peg.push(disk_array[i]);
	}
}

TowerOfHanoi::~TowerOfHanoi()
{
	if (disk_array != nullptr) {
		delete disk_array;
	}
}

void TowerOfHanoi::Solve_Hanoi()
{
	Solve_Hanoi_Recursive(num_of_disks, Source, Destination, Temp);
}

void TowerOfHanoi::Solve_Hanoi_Recursive(int currentSize, Peg& Source, Peg& Destination, Peg& temp)
{
	if (currentSize == 1) {
		Move_Disks(Source, Destination);
	}
	else {
		Solve_Hanoi_Recursive(currentSize - 1, Source, temp, Destination);
		Move_Disks(Source, Destination);
		Solve_Hanoi_Recursive(currentSize - 1, temp, Destination, Source);
	}
}

//Since we use stacks, we do not need to know which disk we are moving, except that we are moving disks.
void TowerOfHanoi::Move_Disks(Peg& Source, Peg& Destination)
{
	Destination.disks_on_peg.push(Source.disks_on_peg.top());
	Source.disks_on_peg.pop();
}
