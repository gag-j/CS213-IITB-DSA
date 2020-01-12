//Find the maximum contiguous positive sum in a list of numbers

//TO DO : Divide and Conquer Algorithm for the same problem

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <climits>
#include <chrono>


using namespace std; 

vector <int> data;

const int VALUE_LIMIT = 10000;
const int COUNT_LIMIT = 100000;

void generate_sequence(){

	ofstream inputFile;
	inputFile.open("/media/gagan/Home & Insti/IITB GAGAN/Spring 2020/CS213/Codes/Lecture Illustrations/Lecture 1/input.txt", ios::out);

	if (!inputFile) cout<<"Error in Creating Input File"<<endl;

	int count = rand()%COUNT_LIMIT;
	int inputValue;

	for (int i=0;i<count;i++){

		inputValue = rand()%VALUE_LIMIT - VALUE_LIMIT/2;
		inputFile << inputValue << endl;
	}

	inputFile.close();

	cout<< "File created successfully"<<endl;

}

void file_to_vector(){
	ifstream inputFile("/media/gagan/Home & Insti/IITB GAGAN/Spring 2020/CS213/Codes/Lecture Illustrations/Lecture 1/input.txt");

	if (inputFile){
		double val;

		while (inputFile >> val){
			data.push_back(val);
		}
	}
	cout << "Data feeded into vector"<<endl;
}

int algo1(vector <int> a){
	
	int currMax = INT_MIN;
	int maxSoFar = INT_MIN;
	int sumSoFar = 0;

	for (int i=0;i<data.size();i++){
		sumSoFar = data[i];
		currMax = max(currMax, data[i]);
		for (int j=i+1;j<data.size();j++){
			sumSoFar = sumSoFar + data[j];
			currMax = max(currMax, sumSoFar);
		}
		maxSoFar = max(maxSoFar, currMax);
		currMax = INT_MIN;
	}
	return maxSoFar;
}

int algo2(vector <int> a) { 
   int maxSoFar = a[0]; 
   int currMax = a[0]; 
  
   for (int i = 1; i < a.size(); i++){ 
        currMax = max(a[i], currMax+a[i]); 
        maxSoFar = max(maxSoFar, currMax); 
   } 
   return maxSoFar; 
} 

int main(){

	std::chrono::time_point<std::chrono::system_clock> start_file_generation, start_file_to_vector, start_algo1, start_algo2, end_algo2; 

	start_file_generation = std::chrono::system_clock::now(); 
	generate_sequence();
	start_file_to_vector = std::chrono::system_clock::now();
	std::chrono::duration<double> file_generation_time = start_file_to_vector - start_file_generation;
	cout<<"file_generation_time "<<file_generation_time.count()<<endl<<endl;

	 
	file_to_vector();
	start_algo1 = std::chrono::system_clock::now();
	std::chrono::duration<double> file_to_vector_time = start_algo1 - start_file_to_vector;
	cout<<"file_to_vector_time "<<file_to_vector_time.count()<<endl<<endl;
	cout<<"algo1 output "<<algo1(data)<<endl;
	
	start_algo2 = std::chrono::system_clock::now();
	std::chrono::duration<double> algo1_time = start_algo2 - start_algo1;
	cout<<"algo1_time "<<algo1_time.count()<<endl<<endl;
	cout<<"algo2 output "<<algo2(data)<<endl;
	
	end_algo2 = std::chrono::system_clock::now();
	std::chrono::duration<double> algo2_time = end_algo2 - start_algo2;
	cout<<"algo2_time "<<algo2_time.count()<<endl<<endl;
	
	return 0;
}

