#include<bits/stdc++.h>
int arr1[3],arr2[3];
void add(){
	for(int i=0;i<3;i++)cout<<arr1[i] ^ arr2[i]<<" ";
	cout<<endl;
}

void sub(){
	for(int i=0;i<3;i++)cout<<arr1[i] ^ arr2[i]<<" ";
	cout<<endl;
}

void mul(){
	
}

void div(){

}

void init(){
	for(int i=0;i<3;i++){
		arr1[i]=0;
		arr2[i]=0;
	}
	return;
}

void inp(){
	cout<<"Enter polynomials\n";
	for(int i=0;i<3;i++)cin>>arr1[i];
	for(int i=0;i<3;i++)cin>>arr2[i];
	return;
}
int main(){
	while(1){
		init();
		inp();
		add();	
		sub();
		mul();
		div();
	}
	return 0;
}
