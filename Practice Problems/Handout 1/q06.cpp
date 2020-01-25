// A reputed mathematician claims that reciprocals of the divisors of a perfect number
// must add up to 2. She illustrates this for the first two perfect numbers :
// • For 6, we get 1 / 6 + 1 / 3 + 1 / 2 + 1 / 1 = 2;
// • For 28, we get 1 / 28 + 1 / 14 + 1 / 7 + 1 / 4 + 1 / 2 + 1 / 1 = 2
// One wishes to verify experimentally whether her claim is true for other perfect numbers also.

#include <bits/stdc++.h>
#include <chrono>
using namespace std;

bool is_prime(long long int n){
	// cout<<"in function is_prime "<<n<<endl;

	bool prime = true;
	for (long long int i=2;i<=sqrt(n);i++){
		// cout<<i<<endl;
		if (n%i == 0) prime = false;
		// cout<<prime<<endl;
	}
	return prime;
}

void perfect_numbers(){

	for (int i=2;i<=15;i++){
		if (is_prime(pow(2,i)-1)){
			float sum = 0;
			long long int perfect = pow(2,i-1)*(pow(2,i)-1);
			for (int i=2;i*i<=perfect;i++){
				if (perfect%i==0){
					if (i*i!=perfect) sum += 1./i + 1.*i/perfect;
					else sum += 1./i;
				}
			}
			if (sum - 2 > 0.001) cout<<"Claim false"<<endl;
			else cout<<"Claim holds for "<<perfect<<endl;
		}
	}
}

int main(){
	perfect_numbers();
	return 0;
}