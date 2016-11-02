#include <bits/stdc++.h>
using namespace std;
string CaesarE(string s,int key){
	string ret;
	int l=s.length();
	for(int i=0;i<l;i++)
		ret+=char((((int)s[i]-int('a')+key)%26)+int('a'));
	return ret;
}
string CaesarD(string s,int key){
	string ret;
	int l=s.length();
	for(int i=0;i<l;i++)
		ret+=char(((((int)s[i]-int('a')-key)+26)%26)+int('a'));
	return ret;
}
int main(){
	while(1){
		string s;
		int key;
		cout<<"s & key\n";
		cin>>s>>key;
		string res=CaesarE(s,key);
		string dec=CaesarD(res,key);
		cout<<"Encryption:"<<res<<endl;
		cout<<"Decryption:"<<dec<<endl;
	}
	return 0;
}