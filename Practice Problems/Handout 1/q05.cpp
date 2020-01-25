// A pair of prime numbers are called twin primes if they differ by 2, for example (5,7),
// (11, 13) are twin primes. Find and report all twin primes having d decimal digits.

#include <bits/stdc++.h>
using namespace std;

bool is_prime(long int n){
	// cout<<"in function is_prime "<<n<<endl;

	bool prime = true;
	if (n==1) return false;
	for (long long int i=2;i<=sqrt(n);i++){
		// cout<<i<<endl;
		if (n%i == 0) prime = false;
		// cout<<prime<<endl;
	}
	return prime;
}

void twin_primes(int d){
	int cnt = 0;
	for (long int i = pow(10,d-1); i<pow(10,d); i++){
		if (is_prime(i) and is_prime(i+2) and (int)log10(i)==(int)log10(i+2)){
			cout<<"("<<i<<","<<i+2<<")"<<endl;
			cnt++;
		}
	}
	cout<<"count "<<cnt<<endl;
}

int main(){
	twin_primes(10);
	return 0;
}