#include <bits/stdc++.h>
using namespace std;

bool balanced(string expression){
	stack <char> s;
	char x;
	int open = 0;
	int close = 0;
	for(int i=0;i<expression.length();i++){
		if (expression[i] == '('){
			s.push(expression[i]);
			open = close + 1;
			close++;
		}
		else if (expression[i] == ')'){
			if (s.empty()){
				cout<<"unbalanced at position "<<open<<endl;
				return 0;
			}
			if (s.top() == '('){
				s.pop();
				close++;
			}
			else {
				cout<<"unbalanced at position "<<++close<<endl;
				return 0;
			}
		}
	}
	if (!s.empty()) cout<<"unbalanced at position "<<++close<<endl;;
	return s.empty();
}

int main(){
	string expression;
	cin>>expression;
	cout<< balanced(expression);
	return 0;
}	