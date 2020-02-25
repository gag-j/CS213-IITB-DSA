#include <bits/stdc++.h>
using namespace std;

void sort_my_array(int a[], int m, int n){
	int count[n+1];
	for(int i=0;i<=n;i++){
		count[i] = 0;
	}
	for (int i=0;i<m;i++){
		count[a[i]]++;
	}
	int j=0;
	for (int i=1;i<=n;i++){
		while (count[i]!=0){
			a[j] = i;
			j++;
			count[i]--;
		}
	}
}

int main(){
	int m,n;
	cin>>m>>n;
	int a[m];
	for(int i=0;i<m;i++){
		a[i] = rand()%(n)+1;
	}
	for(int i=0;i<m;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	sort_my_array(a,m,n);
	for(int i=0;i<m;i++){
		cout<<a[i]<<" ";
	}
}