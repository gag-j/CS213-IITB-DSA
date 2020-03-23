#include <bits/stdc++.h>
using namespace std;

string trimall(string s){
	string r;
	int cnt = 1;
	for(int i=0;i<s.length();i++){
		if (s[i]==' ' and cnt<7) {
			cnt++;
			r.push_back(' ');
		}
		else if ((s[i]==',' or s[i]==';' or s[i]==';' 
			or s[i]=='.' or s[i]=='!' or s[i]=='?' or s[i]==':' 
			or s[i]=='\'' or s[i]=='\"') and cnt>=7){
			cnt = 1;
			r.push_back(s[i]);
			if (i+2<s.length() and s[i+1]==' ') i+=1;
			r.push_back(10);
		}
		else if (s[i]==10 and s[i+1]==10) {
			i++;
			r.push_back(10);
		}
		else if (!(s[i-1]==',' or s[i-1]==';' or s[i-1]==';' 
			or s[i-1]=='.' or s[i-1]=='!' or s[i-1]=='?' or s[i-1]==':' 
			or s[i-1]=='\'' or s[i-1]=='\"') and s[i]==10) r.push_back(' ');
		else if (s[i]!=10) r.push_back(s[i]);
	}
	return r;
}

int main(){
	string s = "Lightly, O lightly we bear her along, She sways like a flower in the wind of our\n"
"song; She skims like a bird on the foam of a stream, She floats like a laugh from\n"
"the lips of a dream. Gaily, O gaily we glide and we sing, We bear her along like\n"
"a pearl on a string.\n\n"
"Softly, O softly we bear her along, She hangs like a star in the dew of our song;\n"
"She springs like a beam on the brow of the tide, She falls like a tear from the\n"
"eyes of a bride. Lightly, O lightly we glide and we sing, We bear her along like\n"
"a pearl on a string.\n";
cout<<trimall(s);
}