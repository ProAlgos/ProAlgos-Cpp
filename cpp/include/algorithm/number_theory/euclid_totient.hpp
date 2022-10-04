/* euclid totient
--------------------------------------------------
Euler's totient function (a.k.a. phi function) counts the number 
of positive integers from 1 to given number N that are coprime to N. 
That is, phi(N) is a number of positive integer m 
such that 1 <= m <= N and GCD(m, N) = 1.

Time Complexity
--------------------------------------------------
O(N^2) where N is the limit

Space Complexity
--------------------------------------------------
O(1) It doesn't use any extra space

*/






#ifndef EUCLID_TOTIENT_HPP
#define EUCLID_TOTIENT_HPP
int euclid_totient(int limit){
  int n1 =1;
  int n2 =limit;
  int count = 0;
  while(n1<n2){
    int gcd = 0;
    for(int i = 1 ; i<=n1 && i<=n2; i++){
      if(n1%i == 0 && n2%i == 0){
        gcd = i;
      }
    }
    if(gcd == 1){
      count++;
    }
    n1++;
  }
  return count;
}

#endif //EUCLID_TOTIENT_HPP  
