#include <bits/stdc++.h>
using namespace std;
map<char,char> me,md;
void fill(){
	char ch,ch1;
	cout<<"Enter the table(for 4)\n";
	for(int ch1='a';ch1<='d';ch1++){
		cin>>ch;
		me[ch1]=ch;
		md[ch]=ch1;
	}
}

string MonoalphabeticE(string s){
	int l=s.length();
	string ret;
	for(int i=0;i<l;i++){
		ret+=me[s[i]];
	}
	return ret;
}

string MonoalphabeticD(string s){
	int l=s.length();
	string ret;
	for(int i=0;i<l;i++){
		ret+=md[s[i]];
	}
	return ret;
}


int main(){
	string s;
	fill();
	while(1){
		cout<<"String ?\n";
		cin>>s;
		string res=MonoalphabeticE(s);
		cout<<"Enc: "<<res<<endl;
		cout<<"Dec: "<<MonoalphabeticD(res)<<endl;
	}
	return 0;
}
