// Given a number as input find and report the prime exponent representation of the number. For
// the input 180, the expected output is of the form
// Prime exponent representation of 180 is
// prime 2 exponent 2
// prime 3 exponent 2
// prime 5 exponent 1
// 180 has three prime factors and sum of exponents is 5

#include <bits/stdc++.h>
using namespace std;

map<int, int> prime_exp;

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

void prime_exp_rep(int n){
	// cout<<" in func prime_exp_rep"<<endl;
	int copy_n = n;

	 
	int prime, exponent;

	for (int i=2;i<=n;i++){
		if (is_prime(i)){
			// cout<<"in for loop"<<i<<endl;
			prime = i;
			exponent = 0;
			while (copy_n%i == 0){
				copy_n = copy_n/i;
				exponent++;
			}
			// cout<<prime<<" "<<exponent<<endl;
			if (exponent!=0) prime_exp.insert(pair<int, int> (prime, exponent));
		}
	}

	cout<<"Prime exponent representation of "<< n<<" is"<<endl;
	map<int, int>::iterator itr;
	int sum = 0;
	for (itr = prime_exp.begin(); itr != prime_exp.end(); ++itr) { 
		sum += itr->second;
        cout << "prime " << itr->first 
             << " exponent " << itr->second << endl; 
    } 
    cout << n<<" has "<<prime_exp.size()<<" prime factors and sum of exponents is "<<sum<<endl;

}

int main(){
	srand(time(NULL));
	int n = rand()%99999;
	prime_exp_rep(n);
	return 0;
}
