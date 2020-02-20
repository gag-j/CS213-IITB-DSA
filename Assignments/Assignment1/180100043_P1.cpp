// 1. You are provided with a list of students with their marks in the DSA course. The task is to find all
// the students having marks between the specified range (x,y) (inclusive of x and y), the final output
// should be printed in decreasing order of marks. You may make use of STL for this question.
// (a) Create a data structure to take input of students and their marks.
// (b) Create a function for fetchMarksQuery(list of students,x,y) which takes input the range
// (x,y) and returns the list of students having marks in the specified range. (Hint: Use Searching)
// (c) The main function should have a loop over the queries
// (d) The complexity of the sorting algorithm should not exceed O(nlogn) and the query part
// should not exceed O(p+logn), where p is the number of students to be returned for that
// particular query.
// Input:
// The first line contains number of students n. 1 <= n <= 106
// The next n lines contains each students ID along with his corresponding marks.
// The line following this would be the number of queries say q.
// The next q lines should contain pairs x space seperated with y, the range of marks for each query
// Output:
// For each query, the first line prints x seperated with y.
// The next p lines prints the list of students having marks in this range.
// Sample:
// Input:
// 4
// 214050009 89
// 214050006 90
// 214050001 78
// 214050002 99
// 2
// 98 99
// 80 90
// Output:
// 98 99
// 214050002
// 80 90
// 214050009
// 214050006

#include <bits/stdc++.h>
using namespace std;



class Marklist{
	int n;
	vector <pair <string, int> > student ;
	pair <string, int> student_info;

public:
	Marklist(){
		int n_;
		// cout<<"No. of students in class\n";
		cin>>n_;
		n = n_;

		string id_;
		int marks_;

		for (int i=0;i<n_;i++){
			
			// cout<<"Student ID\n";
			cin>>id_;
			// student_info.first = id_;

			
			// cout<<"Marks\n";
			cin>>marks_;
			// student_info.second = marks_;

			student_info = make_pair(id_, marks_);
			student.push_back(student_info);
		}
	}

	static bool sortbysec(const pair<string,int> &a, const pair<string,int> &b) { 
    	return (a.second < b.second); 
	}

	void fetchMarksQuery(int x, int y){
		sort(student.begin(), student.end(), sortbysec);

		int low = 0;
		int high = student.size() - 1;
		
		int mid = (low+high)/2;
		int topper_index = mid;
		bool found = false;

		while (low<=high and student[mid].second != y){
			mid = (low+high)/2;

			if (student[mid].second == y) {
				topper_index = mid;
				found  = true;
			}
			else if (student[mid].second > y) high = mid - 1;
			else low = mid + 1;
			
		} 

		if (!found){
			while (student[mid+1].second <= y){
				mid++;
				found = true;
			}
			while (student[mid-1].second >= y and found == false){
				mid--;
				found = true;
			}
		}
		topper_index = mid;

		if (student[mid].second == y){
			while (mid<high) {
					if (student[mid + 1].second == y) mid++;
					else break;
				}
			topper_index = mid;
		}
		// cout<<topper_index<<endl;
		for (int i = topper_index; student[i].second >= x; i--){
			cout<<student[i].first<<endl;
		}
	}
};

int main(){
	Marklist cs213;

	int q;
	cin>>q;

	int x, y;
	for (int i=0;i<q;i++){
		cin>>x>>y;
		cs213.fetchMarksQuery(x, y);
	}
	// cs213.fetchMarksQuery(25, 30);
}