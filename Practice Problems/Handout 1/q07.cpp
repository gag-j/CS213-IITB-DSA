// Mersenne number, named in honour of Father Marin Mersenne (1588 - 1648), is a
// positive integer that is one less than a power of two. A Mersenne prime is a Mersenne number that
// is a prime, it is of the form 2 p – 1, where p is a prime.
// The first four Mersenne primes are 3(2 2 – 1), 7(2 3 – 1), 31(2 5 – 1) and 8191(2 13 – 1). However,
// 2047(2 11 – 1) is composite having 23 and 89 as factors. Only 47 such primes are known till October
// 2009, the last one discovered is (2 43,112,609 − 1) which is also the largest known prime known till
// date.
// All the Mersenne primes in the last decade have been discovered by GIMPS (Great Internet
// Mersenne Prime Search) a distributed computing project on the internet. To get a feel for the size of
// the 47 th Mersenne prime, it has more than 10 million decimal digits (needs 3461 pages with 75
// decimal digits per line and 50 lines per page for its representation).
// Find and report as many Mersenne primes as you possibly can in 8 byte unsigned integer. For every
// integer of the form 2^p – 1, where p is a prime, display its prime factors if it is not a Mersenne prime.

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n){
	// cout<<"in function is_prime "<<n<<endl;

	bool prime = true;
	for (int i=2;i<=sqrt(n);i++){
		// cout<<i<<endl;
		if (n%i == 0) prime = false;
		// cout<<prime<<endl;
	}
	return prime;
}

bool is_prime2(unsigned long long int n){
	// cout<<"in function is_prime "<<n<<endl;
	unsigned long long int copy_n = n;
	bool prime = true;
	for (unsigned long long int i=2;i<copy_n;i++){
		// cout<<i<<endl;
		if (n%i == 0){
			cout<<" "<<i<<" ";
			while(n%i==0) n/=i;
			prime = false;
		}
	}
	if (!prime) cout<<endl;
	return prime;
}

void Mersenne_primes(){
	int cnt =0;
	for (int i=2;i<35;i++){
		if (is_prime(i)){
			cout << (long)pow(2,i)-1<<" ";
			if (is_prime2(pow(2,i)-1)) cout<<"Mersenne"<<endl;
		}
	}
}

int main(){
	Mersenne_primes();
	return 0;
}

