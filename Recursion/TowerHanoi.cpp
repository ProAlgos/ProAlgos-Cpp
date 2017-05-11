/*
@Author Davide Spataro www.davidespataro.it

Tower Of Hanoi
-------------------
Solves the tower of hanoi problem ( https://en.wikipedia.org/wiki/Tower_of_Hanoi )
  using a recursive approach.


Time complexity
---------------
O(2^n),where n is the number of disks

Space complexity
----------------
O(n), where n is the number of disks 
(not considering the stack space for the required by recursion). 
*/



#include <iostream>
#include<array>
#include<vector>
#include <stack>
#include <unistd.h>
using namespace std;



int ndisks;
int sleeptime = 9000;
int nmoves = 0;

//prints the current status of the piles
void drawHanoi(auto& piles) {

  auto printNtimes = [](char c, int n) {
    for (int i = 0 ; i < n; i++)
      printf("%c", c);
  };

  std::array<int,3> sep= {ndisks, ndisks, ndisks};

  for (int  i = ndisks ; i >= 0; --i) {
    for (int j = 0; j < 3; j++) {
      printf(" | ");
      if (piles[j].size() > (unsigned)i) {
        int n = piles[j][i] + 1;
        printNtimes('=', n);
        printNtimes(' ', sep[j] - n + 1);
      } else
        printNtimes(' ', sep[j] + 1);

      printf(" | ");
    }
    printf("\n");
  }
  printf("\n\n");

  usleep(sleeptime);
}


/**
  Function that solves the towe of hanoi problem
*/
void solveHanoi(int start, int end, int from, int to, auto& piles) {
  //which pile should we use as support pile?
  int support = (from + to) % 4;
  support = support == 0 ? 2 : support;

  if (end - start == 0 ) {

    piles[to - 1].push_back(piles[from - 1].back());
    piles[from - 1].pop_back();
    drawHanoi(piles);
    nmoves++;
  }

  else {
    solveHanoi(start, end - 1, from, support, piles);
    solveHanoi(end, end, from, to, piles);
    solveHanoi(start, end - 1, support, to, piles);
  }

}



int main() {

  int np;
  cout << "How many disks?...\n";
  cin >> np;
  np--;

  vector<vector<int>> piles(3, vector<int>());
  ndisks = np;

  //initialize all disks on pile number one
  for (int i = np; i >= 0; i--)
    piles[0].push_back(i);

  solveHanoi(0, np, 1, 3, piles);

  printf("solved using %d moves\n", nmoves);

  return 0;
}