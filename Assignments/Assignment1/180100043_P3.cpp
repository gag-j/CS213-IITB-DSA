// The chocolate-packing problem is the following. You are a shopkeeper. On any given day, you
// are able to produce n chocolates. Using these n chocolates, you must create different packets, where
// each packet can contain any number of chocolates. You are given a table of prices , where the i th
// entry represents the price of selling i chocolates in one packet. Using this, determine the maximum
// revenue obtainable by distributing the n chocolates into different packets. You can assume that all
// packets will be sold (There will be no packet that does not generate any revenue).
// Input:
// The first line contains the number of chocolates n. 1 <= n <= 10 4
// The second line contains n space separated integers where the i th number represents the revenue
// obtained when a packet containing i chocolates is sold. 1 <= i <= n; 1 <= p i <= 10 3
// Output:
// The maximum amount of revenue obtained after packaging the chocolates.
// Sample:
// Input:
// 2
// 3 4
// Output:
// 6
// Hint: If you are getting the correct answer but your program is taking too long as n increases,
// think of some things you are computing more number of times than required. Is there any way you
// can make this process more efficient?

#include <bits/stdc++.h>
using namespace std;

int max_revenue(int n, vector <int> prices){
	vector <int> revenue;

	for(int i=0;i<=n;i++){
		revenue.push_back(0);
	}

	for (int i=0;i<=n;i++){
		for(int j=0;j<n;j++){
			if (j+1<=i){
				revenue[i] = max(revenue[i], revenue[i-j-1]+prices[j]);
			}
		}
	}
	// for(int i=0;i<=n;i++){
 //    	cout<<revenue[i]<<" ";
 //    }
 //    cout<<endl;

	return revenue[n];
}

int main(){
	int n;
	cin>>n;
	vector <int> prices;
	int data;
	for(int i=0;i<n;i++){
		cin>>data;
		prices.push_back(data);
	}
	cout<<max_revenue(n, prices);
}