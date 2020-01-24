#include <bits/stdc++.h>
using namespace std;


int linear_search(int elm, int arr[], int n){
	int index = -1;

	for(int i=0;i<n;i++){
		if (arr[i]==elm){
			index = i;
		}
	}
	if (index == -1) cout<<"Not found"<<endl;
	return index;
}

int binary_search(int elm, int arr[], int n){
	//assumes sorted array

	int low = 0;
	int high = n - 1;
	int mid;
	bool found = false;

	while (low + 1 < high){
		mid = (low + high)/2;
		if (elm ==arr[low]) return low;
		if (elm == arr[high]) return high; 
		// if (elm <= arr[low] or elm>=arr[high]) return -1;
		if (elm > arr[mid]) low = mid;
		else if (elm < arr[mid]) high = mid;
		else {
			found = true;
			return mid;
		}
	}

	if (!found){
		mid = -1;
		cout<<"Not found"<<endl;
	}
	return mid;
}

int main(){
	srand (time(NULL));
	int n = 10;
	int val_limit = 100;
	int arr[] = {12,23,34,45,56,67,78,89,90,99};
	int element = rand()%val_limit;
	cout<<"element = "<<element<<endl;

	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	int linear_search_val = linear_search(element, arr, n);
	cout<<"linear search index = "<<linear_search_val<<endl;

	// this will return the index for a sorted array
	int binary_search_val = binary_search(element, arr, n);
	cout<<"binary search index = "<<binary_search_val<<endl;

	return 0;

}
