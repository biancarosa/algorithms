#define MAX 10000001
using namespace std;

bool primes[MAX];

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
