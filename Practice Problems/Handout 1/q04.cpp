// Determine all prime numbers, having d decimal digits. Compare experimentally the
// density of prime numbers with that of perfect squares in the universe of natural numbers for a
// given d.

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

bool is_square(long int n){
	int k = sqrt(n);
	if (k*k==n) return 1;
	return 0;
}

void primes_with_d_digits(int d){
	int cnt_prime = 0;
	int cnt_square = 0;
	for (long int i = pow(10,d-1); i<pow(10,d); i++){
		if (is_prime(i)){
			cnt_prime++;
			// cout<<"prime "<<i<<endl;
		}
		if (is_square(i)){
			cnt_square++;
			// cout<<"square "<<i<<endl;
		}
	}

	float prime_density = cnt_prime;
	float square_density = cnt_square;
	prime_density /= (9*pow(10,d-1));
	square_density /= (9*pow(10,d-1));
	cout<<"count prime = "<<cnt_prime<<endl;
	cout<<"count square = "<<cnt_square<<endl;
	cout<<"prime_density = "<<prime_density<<endl;
	cout<<"square_density = "<<square_density<<endl;	
}

int main(){
	int d=6;
	primes_with_d_digits(d);
	return 0;
}