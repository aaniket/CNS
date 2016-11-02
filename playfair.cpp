#include <bits/stdc++.h>
using namespace std;
char grid[5][5];
int marked[26];
void fill(string key){
	for(int f=0;f<26;f++){
		marked[f]=0;
	}

for(int i=0;i<5;i++){for(int j=0;j<5;j++){grid[i][j]='`';}}

	int i=0,j=0;
	int l=key.length();
	for(int k=0;k<l;k++){
		if(marked[key[k]-'a']==0){
			marked[key[k]-'a']=1;
			grid[i][j]=key[k];
			j++;
			if(j==5){
				i++;
				j=0;
			}
		}	
	}
	for(int x=0;x<5;x++){
		for(int y=0;y<5;y++){
			if(grid[x][y]=='`'){
				for(int k=0;k<26;k++){
					if(marked[k]==0){
						marked[k]=1;
						grid[x][y]=(char)(k+'a');
						break;
					}
				}
			}
	}
for(int i=0;i<5;i++){for(int j=0;j<5;j++){cout<<grid[i][j]<<" ";}cout<<endl;}
}
}
/*
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
}*/
int main(){
	string key;
	cout<<"Enter key: ";
	cin>>key;
	fill(key);
	return 0;
}
