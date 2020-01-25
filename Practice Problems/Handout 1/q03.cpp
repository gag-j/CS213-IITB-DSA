// The 3-digit number 153 has the following interesting property: 1 3 + 5 3 + 3 3 = 153. In
// other words, the sum of the digits, raised to the power of the number of digits, is the number itself.
// One is curious to know whether this is an exception or there are other numbers with the same
// characteristic. In particular, find and report all such numbers with d decimal digits, 3 <= d <= 10.

//need a better method
#include <bits/stdc++.h>
using namespace std;

bool is_digit_cube_num(long int n){
	long int copy_n = n;
	int cnt = (int)log10(n) + 1;
	// cout<<"in func bool "<<n<<endl;
	long int sum = 0;

	n = copy_n;

	while(n!=0){
		sum += (long)pow(n%10,cnt);
		n = n/10;
	}
	// cout<<" sum "<<sum<<endl;
	if (sum == copy_n) return 1;
	return 0;
}

void digit_cube_num(){
	int cnt = 0;
	for(long int i=100;i<9999999;i++){
		if (is_digit_cube_num(i)){
			cnt++;
			cout<<i<<endl;
		}
	}
	cout<<"count = "<<cnt<<endl;
}

int main(){
	digit_cube_num();
	return 0;
} 