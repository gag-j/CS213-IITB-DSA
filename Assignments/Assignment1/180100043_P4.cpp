// Alternate approach to sorting: Most of you have learned some basic sorting algorithms in CS
// 101. Here we discuss an alternate approach to sorting an nums_ay.
// We will not be giving the algorithm, but an approach to do so is by trying to first solve this
// subproblem:
// Suppose I represent a set of integers using an nums_ay that holds the integers in sorted order. Given
// two such nums_ays representing two sets. Can you think of an algorithm to combine the elements into
// a single sorted nums_ay?
// Do not implement any other algorithm for sorting.
// Input:
// The first line number of integers n. 1 <= n <= 10 8
// The second line contains n space separated integers
// Output:
// The same n integers in sorted order
// Sample:
// Input:
// 3
// 3 1 2
// Output:
// 1 2 3

#include <bits/stdc++.h>
using namespace std;

void merge_sorted(int nums[], int left, int right, int mid){
	int left_ = left;
	int mid_ = mid + 1;
	int m = 0;
	int nums_[right-left+1];

	for (int i= left; i<= right; i++){
		if (left_ > mid){
			nums_[m++] = nums[mid_++];
		}
		else if (mid_ > right){
			nums_[m++] = nums[left_++];
		}
		else if (nums[left_]<nums[mid_]){
			nums_[m++] = nums[left_++];
		}
		else {
			nums_[m++] = nums[mid_++];
		}

	}
	for(int i=0;i<m;i++){
		nums[left++] = nums_[i];
	}

}

void recursive_sort(int nums[], int left, int right){
	if (left<right){
		int mid = (left+right)/2;

		recursive_sort(nums, left, mid);
		recursive_sort(nums, mid+1, right);

		merge_sorted(nums, left, right, mid);
	}
}

int main(){
	int n;
	// n = rand()%100000000;
	cin>>n;
	int nums[n];
	for(int i=0;i<n;i++){
		cin>>nums[i];
		// nums[i] = rand()%1001;
	}
	recursive_sort(nums, 0, n-1);
	for(int i=0;i<n;i++){
		cout<<nums[i]<<" ";
	}
}