#include <bits/stdc++.h>
using namespace std;
int _sum(int x, int y){
	return (x^y);
}
int _sub(int x, int y){
	return (x^y);
}
int _mul(int fx, int gx, int mx, int n){
	int _mx=mx^(1<<n);
	int ans=0;
	for(int i=0; i<n; i++){
		if((1<<i)&fx){
			int s=gx;
			for(int j=0; j<i; j++){
				s<<=1;
				if((1<<n)&s){
					s=s^(1<<n);
					s=_sum(s, _mx);
				}
			}
			ans=_sum(ans, s);
		}
	}
	return  ans;
}
int main(){
	int n;
	cout<<"Length?\n";
	cin>>n;
	cout<<"Enter 1"<<endl;
	int fx=0,x;
	for(int i=0; i<n; i++){
		cin>>x;
		if(x)fx+=(1<<i);
	}
	cout<<"Enter 2"<<endl;
	int gx=0;
	for(int i=0; i<n; i++){
		cin>>x;
		if(x)gx+=(1<<i);
	}
	cout<<"Addition "<<endl;
	int sum=_sum(fx,gx);
	for(int i=0; i<n; i++){
		if((1<<i)&sum){
			if(i==0)cout<<1<<" ";
			else cout<<i<<" ";
		}
	}	
	cout<<endl;
	int mx=0;
	mx=(1<<0)+(1<<1)+(1<<3)+(1<<4)+(1<<8);
	int ans=_product(fx, gx, mx, n);
	cout<<"Mukltiplication "<<endl;
	for(int i=0; i<n; i++){
		if((1<<i)&ans){
			if(i==0)cout<<1<<" ";
			else cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}
