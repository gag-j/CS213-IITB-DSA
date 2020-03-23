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

int stoi(string s){
	int num = 0;
	if (!isnum(s)) return -1;
	else{
		for(int i=0;i<s.length();i++){
			num *= 10;
			num += s[i]-48;
		}
	}
	return num;
}

float stof(string s){
	float integer = 0.0;
	float fraction = 0.0;
	float num = 0.0;
	int cnt = 0;
	if (!isreal(s)) return -1.0;
	else{
		bool decimal = false;
		for(int i=0;i<s.length();i++){
			if (!decimal and s[i]!='.') {
				integer *= 10;
				integer += s[i]-48;
			}
			else if (s[i]=='.') decimal = true;
			else if (decimal and s[i]!='.') {
				cnt++;
				fraction *= 10;
				fraction += s[i]-48;
			}	
		}
		fraction /= pow(10,cnt);
		num = integer + fraction;	
	}
	return num;
}

int main(){
	cout<<stoi("1234")<<" "<<stoi("ab353")<<" "<<stoi("123.21")<<endl;
	cout<<stof("1234")<<" "<<stof("ab353")<<" "<<stof("123.21")<<" "<<stof("12.21.2")<<" "<<stof(".123")<<" "<<stof("123.")<<endl;
}