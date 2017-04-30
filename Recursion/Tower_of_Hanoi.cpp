#include <iostream>

using namespace std;


//Recursive algorithm to solve the towers of Hanoi problem.



int moves = 0;
void Hanoi(int m, char a, char b, char c);


void Hanoi(int m, char a, char b, char c){
  moves++;
  if(m == 1){
    cout << "Move disc " << m << " from " << a << " to " << c << endl;
  }else{
    Hanoi(m-1, a,c,b);
    cout << "Move disc " << m << " from " << a << " to " << c << endl;
    Hanoi(m-1,b,a,c);
  }
}

int main(){

  int discs;
  cout << "Enter the number of discs: " << endl;
  cin >> discs;
  Hanoi(discs, 'A', 'B', 'C');
  cout << "It took " << moves << " moves. " << endl;


}
