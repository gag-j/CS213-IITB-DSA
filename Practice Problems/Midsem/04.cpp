#include <bits/stdc++.h>
using namespace std;

int minima(int a[], int l, int r){
	int m = (l+r)/2;
	if (a[m] < a[m-1] && a[m] < a[m+1]) return m;
	else if (a[m]>=a[m-1]) return minima(a, l, m-1);
	else if (a[m]<=a[m+1]) return minima(a, m+1, r);
}

int main(){
	int n=6;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<minima(a, 0, n-1);
	return 0;
}