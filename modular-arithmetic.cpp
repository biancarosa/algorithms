
#include <iostream>
#include <string>
#include <sstream>
#define ULL unsigned long long
using namespace std;
using namespace std;

/** useful for big numbers, read it as a string */
bool isDivisible_Str(string s, ULL n){
	ULL lastRemainder = 0;
	int sz = s.length();
	for (int i = 0; i < sz; ++i) {
		lastRemainder = (lastRemainder * 10 + (s[i] - '0')) % n;
	}
	return (lastRemainder==0?true:false);
}

/** it also works for smaller numbers */
bool isDivisible(ULL p, ULL q){
	ULL lastRemainder = 0;
	ULL r;
	int digits[1000];
	int count = 0;
	while (p > 0) {
		digits[count++] = p % 10;
		p /= 10;
	}
	for (int i = count-1; i >= 0; --i) {
		lastRemainder = (lastRemainder * 10 + digits[i]) % q;
	}
	return (lastRemainder==0?true:false);
}
    
ULL modular_pow(ULL base, ULL exponent, ULL modulus) {
	ULL result = 1;
	base = base % modulus;
	while(exponent > 0) {
		if (exponent % 2 == 1) {
			result = (result * base) % modulus;
		} 	
		exponent = exponent >> 1;
		base = (base*base) % modulus;
	}
	return result;
}

int main() {
	cout << modular_pow(2, 1, 5) << endl;
	cout << modular_pow(2, 2, 5) << endl;
	cout << modular_pow(2, 3, 5) << endl;
	cout << modular_pow(2, 4, 5) << endl;
	cout << modular_pow(2, 5, 5) << endl;
	cout << isDivisible_Str("2000", 2) << endl;
	cout << isDivisible(2000,2) << endl;
	cout << isDivisible_Str("2001", 2) << endl;
	cout << isDivisible(2001,2) << endl;
	return 0;
}
