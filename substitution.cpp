#include <bits/stdc++.h>
using namespace std;
map<char,char> me,md;
vector <int> otpk,enc,dec,value;
void populate(){
	for(int i=0;i<256;i++){
		int val=rand()%2;
		otpk.push_back(val);
	}
}
string CaesarE(string s,int key){
	string ret;
	int l=s.length();
	for(int i=0;i<l;i++)
		ret[i]=char((((int)s[i]-int('a')+key)%26)+int('a'));
	return ret;
}
string CaesarD(string s,int key){
	string ret;
	int l=s.length();
	for(int i=0;i<l;i++)
		ret[i]=char(((((int)s[i]-int('a')-key)+26)%26)+int('a'));
	return ret;
}
string MonoalphabeticE(string s){
	int l=s.length();
	string ret;
	for(int i=0;i<l;i++){
		ret[i]=me[s[i]];
	}
	return ret;
}

string MonoalphabeticD(string s){
	int l=s.length();
	string ret;
	for(int i=0;i<l;i++){
		ret[i]=md[s[i]];
	}
	return ret;
}

void OTPE(){
	int l=value.size();
	for(int i=0;i<l;i++){
		enc.push_back(value[i]^otpk[i]);
	}
}
void OTPD(){
	int l=value.size();
	for(int i=0;i<l;i++){
		dec.push_back(value[i]^otpk[i]);
	}
}
string playfairE(string s){
	int l=s.length();
	string ret,res;
	
	for(int i=0;i<l-1;i++){
		if(s[i]==s[i+1]){
			ret[i]=s[i];
			ret[i+1]='x';
		}
		else{
			ret[i]=s[i];
			ret[i+1]=s[i+1];
			i++;
		}
	}
	int l1=ret.length();
	if(ret.length()%2==1)ret+='x';
	for(int i=0;i<l1;i++){
		int r1=getRow(ret[i]);
		int c1=getCol(ret[i]);
		int r2=getRow(ret[i+1]);
		int c2=getCol(ret[i+1]);
		if(r1==r2){
			res[i]=grid[r1][(c1+1)%5];
			res[i+1]=grid[r2][(c2+1)%5];
		}
		else if(c1==c2){
			res[i]=grid[(r1+1)%5][c1];
			res[i+1]=grid[(r2+1)%5][c2];
		}
		else{
			res[i]=grid[r1][c2];
			res[i+1]=grid[r2][c1];
		}
	}
}
string polyalphaE(string s,string key){
	int l=s.length(),kl=key.length();
	string ret;
	for(int i=0;i<l;i++){
		ret[i]=grid1[key[i%kl]-'a'][s[i]-'a'];
	}
	return ret;
}

string polyalphaD(string s,string key){
	int l=s.length(),kl=key.length();
	string ret;
	for(int i=0;i<l;i++){
		ret[i]=grid1[key[i%kl]-'a'][s[i]-'a'];
	}
	return ret;
}
int main(){
	populate();
	return 0;
}