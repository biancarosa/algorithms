#include <iostream>
#define ULL unsigned long long
using namespace std;

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
	return 0;
}
