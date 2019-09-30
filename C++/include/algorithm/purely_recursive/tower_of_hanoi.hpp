/*
    Tower of Hanoi
    ---------------
    This is a puzzle fashioned after the ancient Tower of Brahma Ritual.
    Read about it here: https://en.wikipedia.org/wiki/Tower_of_Hanoi

    There are three towers A, B and C. On tower A, there are n disks of varying sizes
    fitted such that the size of the disks decrease top to bottom. The task is to 
    move the disks from tower A to tower B while using tower C as intermediate storage.
    However, there are 2 restrictions:
        1. The disks can only be moved one at a time.
        2. At no time, can a disk be on top of a smaller disk.

    This algorithm prints out the instructions for moving the disks according to
    the requirement.

    Time complexity
    ---------------
    O(2^N), where N is the number of disks.

    Space complexity
    ----------------
    O(1), constant space complexity.
*/

#ifndef TOWER_OF_HANOI_HPP
#define TOWER_OF_HANOI_HPP

#include <iostream>

using std::endl;
using std::cout;

// Function prints instructions recursively and returns total moves done
int tower_of_hanoi(int num_disks, char tower_a, char tower_b, char tower_c, int total_moves = 0, int move = 0)
{
    if(num_disks >= 1)
    {
        // Disks from tower A are moved to tower C through the first recursive chain.
        total_moves = tower_of_hanoi(num_disks-1, tower_a, tower_c, tower_b, total_moves, move+1);
        cout << "Move disk" << num_disks << " from tower " << tower_a << " to tower " << tower_b << endl;

        // Disks from tower C are moved to tower B through the second recursive chain.
        total_moves = tower_of_hanoi(num_disks-1, tower_c, tower_b, tower_a, total_moves);
    }
    else
        total_moves += move;    // Once the recursion ends, calculate the total moves done

    return total_moves;
}

#endif