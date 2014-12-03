// Slightly changed for my own needs, based on (http://codepad.org/vAGMSNKG)

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

void findPalindromes(string s) {
	  int N = s.length();
	  int i, j, k,   // iterators
      rp,        // length of 'palindrome radius'
      R[2][N+1]; // table for storing results (2 rows for odd- and even-length palindromes 
	  
	  s = "@" + s + "#"; // insert 'guards' to iterate easily over s
	
	  for(j = 0; j <= 1; j++) {
	    R[j][0] = rp = 0; i = 1;
	    while(i <= N) {
	      while(s[i - rp - 1] == s[i + j + rp]) rp++;
	      R[j][i] = rp;
	      k = 1;
	      while((R[j][i - k] != rp - k) && (k < rp)) {
	        R[j][i + k] = min(R[j][i - k],rp - k);
	        k++;
	      }
	      rp = max(rp - k,0);
	      i += k;
	    }
	  }
	  
	 s = s.substr(1,N); // remove 'guards'
	
	 for(i = 1; i <= N; i++) {
	    for(j = 0; j <= 1; j++) {
	      for(rp = R[j][i]; rp > 0; rp--) {
	         cout << s.substr(i - rp - 1,2 * rp + j) << endl;
	      }
	    }
	  }
	  
	  cout << endl;	
}

int main() {
	findPalindromes("arara");
	findPalindromes("onibus");
	return 0;
} 
