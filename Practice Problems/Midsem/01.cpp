#include <bits/stdc++.h>
using namespace std;

int increasing_subsequences(int a[], int n){
	int count =0;
	int cnt[n];
	for(int i=0;i<n;i++){
		cnt[i] = 1;
		for(int j=i;j<n-1;j++){
			if (a[j]>=a[j+1]) break;
			else{
				cnt[i]++;
			}
		}
		count += cnt[i];
	}
	return count;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<increasing_subsequences(a,n);
	return 0;
}