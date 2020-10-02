## 'Sieve of Eratosthenes'

Sieve of Eratosthenes is a concept of Number theory which is used to compute all the prime numbers in the range 1 to N, where N is taken as an input from the user.
It is a very important algorithm used in Computer Programming and Sport Programming as well. The function basically makes an array of boolean values. Initiallly all the values are marked true.
Then we iterate on the array and the values which are marked true, for those values we again iterate and mark all its multiples as false. And finally, we store all values which are marked true 
at the end of all iterations.


### Input
-### 'primeLimit'
 Type: 'const unsigned int&'

 The given algorithm takes input a constant unsigned integer as input, and finds all the prime numbers from 1 uptill that number, including that number.

### Output
-### 'Vector of integers - getPrimes'

 The vector stores all the prime numbers in the given range i.e. from 1 to N.

### Time Complexity
-#### Worst Case
 _O_(**Nlog(log(N))**), where **N** is the maximum value upto which primes are to be found.
-### Space Complexity
-#### Worst Case
 _O_(**N**), where **N** is the maximum value upto which primes are to be found.

 