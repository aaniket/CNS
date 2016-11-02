#include <bits/stdc++.h>
using namespace std;
vector<int> otpk;
vector<int> encx;
vector<int> decx;
vector<int> value;
void populate(){
	for(int i=0;i<256;i++){
		int val=rand()%2;
		otpk.push_back(val);
	}
}
void OTPE(){
	int l=value.size();
	for(int i=0;i<l;i++){
		encx.push_back(value[i]^otpk[i]);
	}
}
void OTPD(){
	int l=value.size();
	for(int i=0;i<l;i++){
		decx.push_back(encx[i]^otpk[i]);
	}
}
int main(){
	populate();
	cout<<"Key:";
	for(int i=0;i<otpk.size();i++){
		cout<<otpk[i];
	}
	cout<<endl;
	while(1){
		cout<<"length & PlainText\n";
		int l;
		cin>>l;
		encx.clear();
		decx.clear();
		value.clear();
		while(l--){
			int i;
			cin>>i;
			value.push_back(i);
		}
		OTPE();
		cout<<"Encryption : ";
		for(int i=0;i<encx.size();i++){
			cout<<encx[i];
		}
		cout<<endl;
		OTPD();
		cout<<"Decryption : ";
		for(int i=0;i<decx.size();i++){
			cout<<decx[i];
		}
		cout<<endl;

	}
}