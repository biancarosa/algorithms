#define MAX 10000001
#include <iostream>
using namespace std;

bool primes[MAX];
int prime[MAX];

/** Generates a boolean array where you can check if first 10.000.000 numbers are primes
 * using if (primes[i])  **/
int fillPrimes(){
    for (unsigned long long i = 0; i < MAX; ++i) {
        primes[i] = true;
    }
    primes[0] = primes[1] = false;
    for (unsigned long long i = 2; i < MAX; ++i) {
        if (primes[i]){
           for (unsigned int j = 2; i * j < MAX; ++j){
               primes[i*j] = false;
           }
        }
    }
    return 0;
}

/** It does the same as the first method but 
 *  also generates an array with the first 10.000.000 prime numbers.
	You can get the n-th prime with prime[i] **/
int fillPrime() {
	int c = 1;
	for (unsigned long long i = 0; i < MAX; ++i) {
        primes[i] = true;
    }
    primes[0] = primes[1] = false;
    for (unsigned long long i = 2; i < MAX; ++i) {
        if (primes[i]){
           prime[c++] = i;
           for (unsigned int j = 2; i * j < MAX; ++j){
               primes[i*j] = false;
           }
        }
    }
    return 0;
}

int main() {
	fillPrimes(); fillPrime();
	cout << "2 is not prime " << primes[2] << endl;
	cout << "49 is not prime " << primes[49] << endl; 
	cout << "63 is  prime " << primes[63] << endl; 
	cout << "2nd prime " << prime[2] << endl;
	cout << "49th prime " << prime[49] << endl; 
	cout << "63th prime " << prime[63] << endl; 
	return 0;
}
