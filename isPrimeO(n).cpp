//Primality Test with complexity O(n)

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)  return false;
 
    // Check from 2 to n-1
    for (int i=2; i<n; i++)
        if (n%i == 0)
            return false;
 
    return true;
}