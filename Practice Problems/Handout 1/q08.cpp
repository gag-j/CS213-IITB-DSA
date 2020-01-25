// Amicable numbers are two different numbers that are related such that the sum of the
// proper divisors (proper divisor of a number is a positive integer divisor other than the number itself,
// e.g. the proper divisors of 6 are 1, 2, and 3.) of each is equal to the other. This concept is related to
// that of a perfect number, which is a number which equals the sum of its own proper divisors (said to
// form an aliquot sequence of period 1), amicable numbers form an aliquot sequence of period 2.
// For example, (220, 284) is the smallest pair of amicable numbers . Sum of proper divisors of 220 is
// 284 = 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110; while sum of proper divisors of 284 is 220
// = 1 + 2 + 4 + 71 + 142. Around 12,000,000 amicable pairs were known till 2007. The first few
// amicable pairs are: (220, 284), (1184, 1210), (2620, 2924), (5020, 5564), (6232, 6368).
// Determine and report as many amicable numbers as you possibly can.

#include <bits/stdc++.h>
using namespace std;


void amicable(){

	for (long long int n=1; n<1000000;n++){
		long long int m = 1;
		for(long long int i=2;i*i<=n;i++){
			if (n%i ==0) 
				if (i*i!=n) m = m + i + n/i;
				else m += i;
		}
		long long int p = 1;
		for(long long int i=2;i*i<=m;i++){
			if (m%i ==0) 
				if (i*i!=m) p = p + i + m/i;
				else p += i;
		}

		if (n == p and n<m) cout<<"("<<n<<","<<m<<")"<<endl;
	}
}

int main(){
	amicable();
	return 0;
}