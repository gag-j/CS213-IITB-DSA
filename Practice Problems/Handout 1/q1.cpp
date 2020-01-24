
// Problem 1 : 1, 4, 9,.... are numbers that are known as perfect squares. We would like to know the
// density of perfect squares in the universe of natural numbers. Specifically, it is required to list all
// perfect squares (including how many) among natural numbers with d decimal digits, 5 <= d <= 10.


//perfect squares between 10000 and 9999999999
//10000 is a perfect square
//add (2*100+1)**2 to 10000 to get the next one!

#include <bits/stdc++.h>
#include <chrono>
using namespace std;

bool is_square(long int n){
	int m = sqrt(n);
	if (m*m==n) return 1;
	return 0;
}

void list_squares_algo1(long int a, long int b){
	int cnt = 0;
	for (long int i=a; i<=b;i++){
		if(is_square(i)) {
			// cout<<i<<endl;
			cnt++;
		}
	}
	cout<<"No. of perfect squares  = " << cnt<<endl;
}

void list_squares_algo2(long int a, long int b){
	int cnt = 0;
	bool found_first = false;
	int root;

	for (long int i=a; found_first == false;i++){
		if (is_square(i)){
			found_first = true;
			// cout<<i<<endl;
			cnt++;
			root = sqrt(i);
		}
	}

	for (long int i=root*root; i<=b;root++){
		i = (long) i + 2*root + 1;
		if (i<=b) {
			// cout<<i<<endl;
			cnt++;
		}
	}
	cout<<"No. of perfect squares  = " << cnt<<endl;
}

int main(){
	long int a = 10000;
	long int b = 9999999999;
	cout<<"a = "<<a<<" b = "<<b<<endl;

	std::chrono::time_point<std::chrono::system_clock> start_algo1, start_algo2, end_algo2;

	start_algo1 = std::chrono::system_clock::now();
	list_squares_algo2(a,b);
	start_algo2 = std::chrono::system_clock::now();
	std::chrono::duration<double> algo1_time = start_algo2 - start_algo1;
	cout<<"algo1_time "<<algo1_time.count()<<endl<<endl;

	list_squares_algo1(a,b);
	end_algo2 = std::chrono::system_clock::now();
	std::chrono::duration<double> algo2_time = end_algo2 - start_algo2;
	cout<<"algo2_time "<<algo2_time.count()<<endl<<endl;

	return 0;
}

