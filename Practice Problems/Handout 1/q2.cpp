// The number 6, has an interesting property that sum of all its factors (except the
// number itself) is the given number (for ex, 6 = 1 + 2 + 3). Numbers that satisfy this property are
// known as perfect numbers. Another perfect number is 28. It is desired to find all perfect numbers
// that are computationally possible in 8 byte unsigned integers.

#include <bits/stdc++.h>
#include <chrono>
using namespace std;

bool is_perfect(long long int n){

	long long int sum = 1;
	for(long long int i=2;i*i<=n;i++){
		if (n%i ==0) 
			if (i*i!=n) sum = sum + i + n/i;
			else sum += i;
	}

	if (sum==n and n!=1) return 1;
	return 0;
}

void perfect_numbers_algo2(){
	int cnt = 0;
	for (long long int i=1; i<LLONG_MAX; i++){
		if (is_perfect(i)) {
			cout<<i<<endl;
			cnt++;
		}
	}
	cout<<"count "<<cnt<<endl;

}

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

// a number of the form 2^p*(2^p - 1) is perfect if 2^p - 1 is prime!

void perfect_numbers_algo1(){

	for (int i=2;i<=31;i++){
		if (is_prime(pow(2,i)-1)) cout<<(long long)pow(2,i-1)*(pow(2,i)-1)<<endl;
	}
}

int main(){

	std::chrono::time_point<std::chrono::system_clock> start_algo1, start_algo2, end_algo2;

	start_algo1 = std::chrono::system_clock::now();
	perfect_numbers_algo1();
	start_algo2 = std::chrono::system_clock::now();
	std::chrono::duration<double> algo1_time = start_algo2 - start_algo1;
	cout<<"algo1_time "<<algo1_time.count()<<endl<<endl;

	//You may wait for the second algo to finish if you don't have a life :p
	perfect_numbers_algo2();
	end_algo2 = std::chrono::system_clock::now();
	std::chrono::duration<double> algo2_time = end_algo2 - start_algo2;
	cout<<"algo2_time "<<algo2_time.count()<<endl<<endl;
	
	return 0;
}