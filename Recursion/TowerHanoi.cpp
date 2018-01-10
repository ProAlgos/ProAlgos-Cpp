/*
@Author Davide Spataro www.davidespataro.it

Tower Of Hanoi
-------------------
Solves the tower of hanoi problem (https://en.wikipedia.org/wiki/Tower_of_Hanoi)
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
#include <array>
#include <vector>

using std::cout;
using std::endl;
using std::array;
using std::cin;
using std::vector;

/*
  Class HanoiTowerSolver. it exposes a simple interface for solving
  hanoi tower problem.
*/
class HanoiTowerSolver {
 protected:
  using HanoiPiles = array<vector<int>, 3>;

  const unsigned mNum_discs;
  unsigned mNmoves;

  HanoiPiles piles;

  void drawHanoi() const;
  void solveHanoi(int start, int end, int from, int to);

  // initialize all disks on pile number zero
  void initialize() {
    for (int i = mNum_discs - 1; i >= 0; i--) piles[0].push_back(i);
  }


 public:

  unsigned solve() {
    solveHanoi(0, mNum_discs - 1, 0, 2);
    return mNmoves;
  }

  HanoiTowerSolver(const int _num_discs) : mNum_discs(_num_discs), mNmoves(0) {
    initialize();
  }
};


/**
  Function that solves the tower of hanoi problem
  It returns the number of moves.
*/

void HanoiTowerSolver::solveHanoi(int start, int end, int from, int to) {
  /* Which pile should we use as support pile?
     The logic behind is that since we have three piles and we are trying to
     move from
     pile "from" to pile "to" we have only one choice for the supporting pile.
     As an example imagine: from=0, to=2 then the only pile we can choose is 1.
     Since from and to are always different we can hardcode their values in a
     lookuptable
     0+1 -> 2 moving from pile 0 to 1 has to have support pile 2 (same in the
     other way round)
     0+2 -> 1 moving from pile 0 to 2 has to have support pile 1 (same in the
     other way round)
     1+2 -> 0 moving from pile 1 to 2 has to have support pile 0 (same in the
     other way round)
  */
  constexpr static int lookup_support_table[] = {2, 1, 0};
  int support = lookup_support_table[from + to - 1];

  if (end - start == 0) {
    piles[to].push_back(piles[from].back());
    piles[from].pop_back();
    drawHanoi();
    ++mNmoves;
  } else {
    solveHanoi(start, end - 1, from, support);
    solveHanoi(end, end, from, to);
    solveHanoi(start, end - 1, support, to);
  }
}

/**
  Function that prints the current status of the piles
*/
void HanoiTowerSolver::drawHanoi() const {
  auto printNtimes = [](char c, int n) {
    for (int i = 0; i < n; i++) printf("%c", c);
  };

  for (int i = mNum_discs; i >= 0; --i) {
    for (int j = 0; j < 3; j++) {
      printf(" | ");
      if (piles[j].size() > (unsigned)i) {
        int n = piles[j][i] + 1;
        printNtimes('=', n);
        printNtimes(' ', mNum_discs - n + 1);
      } else
        printNtimes(' ', mNum_discs + 1);
      printf(" | ");
    }
    printf("\n");
  }
  printf("\n\n");
}



int main() {
  int num_discs;
  cout << "How many disks?...\n";
  cin >> num_discs;

  HanoiTowerSolver hanoi_solver(num_discs);
  unsigned nmoves = hanoi_solver.solve();

  printf("solved in %d moves\n", nmoves);

  return 0;
}