/*
    RSA cryptosystem with small keys
    ----------------
    Encryption and decryption of a given input string.
	
    Time complexity
    ---------------
    O(N), for encryption where N is the length of the string
    O(N), for decryption where N is the length of the string
 
    Space complexity
    ----------------
    O(1), constant amount of extra space
 */


#include <iostream>
#include <cmath>
#include <string.h>
#include <vector>
#include <time.h> 

using namespace std;


//This function returns the great common divisor of a and b.
long long int gcd(long long int a, long long int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

//It result of the (val^pow)mod m 
long long int mod_pow(int pow, unsigned long val, int m){
   if(pow == 0)
      return 1;
   int v = mod_pow(pow/2, val, m);
   if(pow % 2 == 0)
      return (v*v) % m; 
   else
      return (((v*val) % m) * v) % m;
}

// Computes the equation a*x = (1 mod m) for x.
int mod_inverse(long long int a, long long int m)
{
    a = a%m;
    for (long long int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}


//It is based on the idea that all prime numbers are in form of 6k+-1, so I'm only testing 2, 3 and numbers in form 6+-1
bool is_prime(long long int number)
{
    if (number == 2 || number == 3)
        return true;

    if (number % 2 == 0 || number % 3 == 0)
        return false;

    int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number) {
        if (number % (divisor - 1) == 0)
            return false;

        if (number % (divisor + 1) == 0)
            return false;

        divisor += 6;
    }

    return true;
}


// This function returns the smaller prime number which is greater than num. 
int next_prime(long long int num) {
    long long int temp = num;
    while(!is_prime(temp)) {
        temp++;
    }
    return temp;
}

//This function generates two random numbers between 0 and upper_limit
void generate_prime_numbers(long long int &prime1, long long int &prime2, int upper_limit) {
    srand(time(NULL));
    
    prime1 = rand() % upper_limit+10;
    prime2 = rand() % upper_limit+10;

    prime1 = next_prime(prime1);
    cout << "First prime is : " << prime1 << endl;

    prime2 = next_prime(prime2+1);
    cout << "Second prime is : " << prime2 << endl;
}


void keygen(long long int &n, int &e, long long int &private_key) {
    long long int prime1, prime2, phiValue, greatCommonDivisor;
    bool flag = true;
    

    //Generate two large prime numbers
    generate_prime_numbers(prime1, prime2, 100);

    
    //Compute the value of 'n' which is equal to prime1*prime2
    n = prime1*prime2;

    //Compute the totient phi(n)=(prime1 - 1)*(prime2 - 1)
    phiValue = (prime1 - 1) * (prime2 - 1);
    cout << "Phi value : " << phiValue << endl;
    
    //Choose 'e' value such as 1 < e < phi(n) and 'e' is not a factor of phi(n) which means that gcd(e, phi) = 1.
    e = 2; // e > 1
    while((e < phiValue)) {
        e = next_prime(e);        
        greatCommonDivisor = gcd(e, phiValue);
        if(greatCommonDivisor == 1)
            break;
        e++;
    }

    private_key = mod_inverse(e, phiValue);
}



void encrypt(vector<int> plain_text, vector<long long int> &cipher_text ,long long int public_key_n, int public_key_e) {    
    for(int i=0; i<plain_text.size(); i++) {
        cipher_text.push_back(mod_pow(public_key_e, plain_text.at(i), public_key_n)); 
    }
    
}


void decrypt(vector<long long int> cipher_text, vector<long long int> &deciphered_text, long long int public_key_n, long long int private_key) {
    for(int i=0; i<cipher_text.size(); i++) {
        deciphered_text.push_back(mod_pow(private_key, cipher_text.at(i), public_key_n)); 
    }
}

void read_input(vector<int> &plain_text) {
    string input;
    
    cout << endl << endl;
    cout << "-> Insert the input string : " << endl;
    getline(cin, input);
    
    int temp;
    for(int i=0; i < input.length(); i++) {
        temp = (int)input.at(i);
        plain_text.push_back(temp);
    }
}




int main(int argc, char** argv) {
    int public_key_e;
    long long int public_key_n, private_key;
    vector<long long int> deciphered_text, cipher_text;
    vector<int> plain_text;
    
    //key generation function
    keygen(public_key_n, public_key_e, private_key);
    
    cout << endl;

    cout << "Public key n : " << public_key_n << endl;
    cout << "Public key e : " << public_key_e << endl;
    cout << "Private key : " << private_key << endl;
    
    //read the input from user
    read_input(plain_text);
    
    //encryption function
    encrypt(plain_text, cipher_text, public_key_n, public_key_e);
    
    //decryption function
    decrypt(cipher_text, deciphered_text, public_key_n, private_key);
    
    
    
    //Results
    string plain_string, deciphered_string;
    cout << endl;
    cout << endl << "-> Results: " << endl << endl; 
    cout << "Plain text : ";
    for(int i=0; i<plain_text.size(); i++) {
        cout << static_cast<char>(plain_text.at(i));
        plain_string += plain_text.at(i)+"";
    }
    cout << endl;
    
    cout << "Cipher text : ";
    for(int i=0; i<cipher_text.size(); i++) {
        cout << cipher_text.at(i);
    }
    cout << endl;
    
    cout << "Deciphered text : ";
    for(int i=0; i<deciphered_text.size(); i++) {
        cout << static_cast<char>(deciphered_text.at(i));
        deciphered_string += deciphered_text.at(i) + "";
    }
    cout << endl;

    
    if(!plain_string.compare(deciphered_string))
        cout << endl << "--- IT WORKS!!! ---" << endl;
    else 
        cout << endl << "--- FAIL ---" << endl;
    
    return 0;
}
