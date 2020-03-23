#include <bits/stdc++.h>
using namespace std;

bool isnum(string s){
	for (int i=0;i<s.length();i++){
		if (s[i]>57 or s[i]<48) return false;
	}
	return true;
}


bool isreal(string s){
	bool decimal = false;
	for (int i=0;i<s.length();i++){
		if ((s[i]>57 or s[i]<48) and s[i]!=46) return false;
		else if (!decimal and s[i]==46) decimal = true;
		else if (decimal and s[i]==46) return false;
	}
	return decimal;
}

string trimall(string s){
	string r;
	for(int i=0;i<s.length();i++){
		if (s[i]!=32 and s[i]!=9 and s[i]!=10) r.push_back(s[i]);
	}
	return r;
}

int main(){
	cout<<isnum("1234")<<" "<<isnum("ab353")<<" "<<isnum("123.21")<<" "<<isnum("12.21.2")<<endl;
	cout<<isreal("1234")<<" "<<isreal("ab353")<<" "<<isreal("123.21")<<" "<<isreal("12.21.2")<<endl;
	cout<<trimall("abcd")<<" "<<trimall("\nsh js		ls\n")<<endl;
}