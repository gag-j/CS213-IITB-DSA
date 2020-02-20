// You are given prices for a particular stock for the next n days, say p 1 , p 2 , ....p n . You want to buy
// one stock on one of the upcoming days and sell it on a later day. Both buying and selling should
// be done within the next n days. You want to find out which buying and selling days will maximize
// your profit. If multiple of these options are possible print with the earliest buying date. The time
// complexity should not exceed O(n).
// Input:
// The first line contains number of days n. 1 <= n <= 10 8
// The second line contains prices separated by space
// Output:
// The first line prints maximum profit possible.
// The second line prints the earliest buy date possible such that profit is maximised.
// Sample:
// Input:
// 5
// 100 10 1110 5000 4000
// Output:
// 4990
// 2

#include <bits/stdc++.h>
using namespace std;

// int naive_algo(vector <int> prices, int n){

// 	int profit = 0;
// 	int curr_profit = 0;
// 	int buy_counter = 0;
// 	for (int i=0;i<prices.size();i++){
// 		for (int j=i+1;j<prices.size();j++){
// 			curr_profit = prices[j] - prices[i];
// 			if (curr_profit > profit) {
// 				buy_counter = i;
// 			}
// 			profit = max(profit, curr_profit);
			
// 		}
		
// 		// profit = max(profit, curr_profit);
// 		curr_profit = 0;

// 	}
// 	cout<<"profit "<<profit<< " counter "<<buy_counter<<endl; 
// 	return profit;
// }

void machau_algo(vector <int> prices, int n){

	int profit = 0;
	int max_diff_so_far = prices[1] - prices[0];
	int min_ele = prices[0];
	int buy_counter = 0;
	int p = 0;

	for(int i=0;i<n;i++){
		if (prices[i] < min_ele){
			min_ele = prices[i];
			p = i+1;	
		}
		
		if (prices[i] > min_ele + max_diff_so_far){
			max_diff_so_far = prices[i] - min_ele;
			buy_counter = p;
		}
		

	}
	cout<<max_diff_so_far<<endl<<buy_counter;
	// return max_diff_so_far;
}

int main(){

	// srand (time(NULL));

	int n;
	cin>>n;
	// cout<<"n "<<n<<endl;
	vector <int> prices;
	int input;
	for(int i=0;i<n;i++){
		cin>>input;
		prices.push_back(input);
		// cout<<input<<" ";
	}
	// cout<<endl;
	// naive_algo(prices, n);
	// machau_algo(prices, n);
	// if (naive_algo(prices,n)!=machau_algo(prices,n)) cout<<"Ke kya hua kaise hua kyu hua";
	// else cout<<"terminate ho";
	machau_algo(prices,n);
	
}