// Suppose you are given k sorted arrays, each with n elements, and you want to combine them into
// a single array of kn elements.
// Consider the following approach. Using the solution to the problem described above, you merge
// the first 2 arrays, then merge the 3 rd given array with this merged version of the first two arrays,
// then merge the 4 th given array with the merged version of the first three arrays, and so on until
// you merge in the final (k th ) input array. What is the running time taken by this successive merging
// algorithm, as a function of k and n?
// The above method, for the given problem specification turns out to be too slow. Lets try something
// else. Let us make a bigger array of size nk and fill it with the elements of all the arrays. Now
// lets apply the sorting algorithm on this array. What would be the running time of this algorithm?
// While this would be faster than the above method in some cases, it still is not good enough to meet
// the constrains of the problem.
// Can you think of a faster way to do the k-way merge procedure?
// Implement this optimised merge procedure on C++.
// Constraints:
// 1 <= n <= 10 8
// 1 <= k <= 10 6
// 1 <= nk <= 10 8
// Input:
// First line - n seperated with k
// Each of the next k lines contain a sorted list of integers of size n
// Output:
// kn integers in a single line in sorted order
// Sample:
// Input:
// 43
// 1279
// 3 4 11 14
// 3 6 8 10
// Output:
// 1 2 3 3 4 6 7 8 9 10 11 14

#include <bits/stdc++.h>
using namespace std;
 
void merge(int left, int right, int* sorted, int n){ 

    int size_first = ((right + left)/2 - left + 1)*n; 
    int size_second = (right - (left + right)/2)*n;

    int first_index = left*n;
    int second_index = ((left + right)/2 + 1)*n; 

    int left_arr[size_first], right_arr[size_second]; 

    for (int i = 0; i < size_first; i++) 
        left_arr[i] = sorted[first_index + i];  
    for (int i = 0; i < size_second; i++) 
        right_arr[i] = sorted[second_index + i]; 
   
    int current_first = 0;
    int current_second = 0; 

    int main_index = first_index; 

    while (current_first + current_second < size_first + size_second){ 
        if (current_second == size_second || (current_first != size_first && left_arr[current_first] < right_arr[current_second])){
            sorted[main_index] = left_arr[current_first];
            current_first++;
            main_index++; 
        }
        else{
            sorted[main_index] = right_arr[current_second];
            current_second++;
            main_index++;
		} 
    } 
} 
  
void divide(int left, int right, int* sorted, int n, int *arr){

    if (left == right){ 
        for (int i = 0; i < n; i++) 
            sorted[left*n + i] = *((arr + left*n) + i); 
        return; 
    } 
    divide(left, (left + right)/2, sorted, n, (int *)arr); 
    divide((left + right)/2 + 1, right, sorted, n, (int *)arr); 
    merge(left, right, sorted, n); 
} 

int main(){
	int n; 
    int k;
    cin>>n>>k;
    int arr[k][n];
    for(int i=0;i<k;i++){
    	for(int j=0;j<n;j++){
    		cin>>arr[i][j];
    		// arr[i][j] = rand()%101;
    	}
    } 

    int* sorted = new int[n*k]; 
  
    divide(0, k - 1, sorted, n, (int *)arr); 

    for (int i = 0; i < n*k; i++){
        cout << sorted[i] << " "; 
    }
}