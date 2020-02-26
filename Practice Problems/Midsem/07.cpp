#include <bits/stdc++.h>
using namespace std;

void print(stack <int> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}

stack <int> copy(stack <int> input){
	stack <int> output;
	int first;
	int n = input.size();
	for(int i=0;i<n;i++){
		first = input.top();
		input.pop();
		for(int j=i+1;j<n;j++){
			output.push(input.top());
			input.pop();
		}
		input.push(first);
		while (!output.empty()){
			input.push(output.top());
			output.pop();
		}
	}
	while(!input.empty()){
		output.push(input.top());
		input.pop();
	}
	return output;
}



int main(){
	stack <int> input;
	stack <int> output;

	for(int i=0;i<12;i++){
		input.push(rand()%9);
	}
	print(input);
	output = copy(input);
	print(output);
	return 0;
}