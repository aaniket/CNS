#include <bits/stdc++.h>
using namespace std;
char grid[26][26];
void fill(){
	int k=0;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			grid[i][j]=char((j+k)%26+(int)('a'));
		}
		k++; 	
	}
for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			cout<<grid[i][j];
		}
		cout<<endl;
	}
cout<<endl;
}

string polyalphaE(string s,string key){
	int l=s.length(),kl=key.length();
	string ret;
	for(int i=0;i<l;i++){
		ret+=grid[key[i%kl]-'a'][s[i]-'a'];
	}
	return ret;
}

string polyalphaD(string s,string key){
	int l=s.length(),kl=key.length();
	string ret;
	for(int i=0;i<l;i++){
		for(int j=0;j<26;j++){
			if(grid[key[i%kl]-'a'][j]==s[i]){
				ret+=(char)('a'+j);
				break;
			}		
		}
	}
	return ret;
}

int main(){
	fill();
	// for(int i=0;i<26;i++){
	// 	for(int j=0;j<26;j++)
	// 		cout<<grid[i][j];
	// 	cout<<endl;
	// }
	cout<<"Key\n";
	string key;
	cin>>key;
	while(1){
		string s;
		cout<<"PlainText\n";
		cin>>s;
		string ans=polyalphaE(s,key);
		cout<<"Enc: "<<ans<<endl;
		cout<<"Dec: "<<polyalphaD(ans,key)<<endl;
	}
	return 0;
}
