#include <iostream>
#include <bits/stdc++.h>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;
vector <mpz_t> v;
vector <mpz_t> v1;
vector <mpz_t> v2;
int main(){

	mpz_t arr[50],arr1[50],arr2[50],inv[50];
	for(int i=0;i<50;i++){
		mpz_inits(arr[i],arr1[i],arr2[i],inv[i],NULL);
	}
	mpz_t inverse,a,b,c,d,pro,divs;
	int val=1;
	mpz_inits(inverse,a,b,c,d,pro,divs,NULL);
	int n;
	cout<<"Length : ";
	cin>>n;
	mpz_set_ui(pro,1);
	mpz_set_ui(d,0);
	mpz_set(arr[0],pro);
	//gmp_printf("----%Zd---\n", arr[0]);
	//v.push_back(pro);

	for(int i=0;i<n;i++){
		gmp_scanf("%Zd%Zd",a,b);
		mpz_set(arr1[i],a);
		mpz_set(arr2[i],b);
		mpz_mul(pro,pro,b);
		
	}

	for(int i=0;i<n;i++){
		mpz_fdiv_q(divs,pro,arr2[i]);
		mpz_set(arr[i],divs);
	}
	gmp_printf("----%Zd---\n", pro);
	cout<<endl;
	for(int i=0;i<n;i++){
		gmp_printf("%Zd ",arr[i]);	
	}
	for(int i=0;i<n;i++){
		mpz_invert(inv[i],arr[i],arr2[i]);
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		gmp_printf("%Zd ",inv[i]);	
	}
	//cout<<37*49<<endl;
	//mpz_set_ui(pro,1);
	for(int i=0;i<n;i++){
		mpz_mul(c,arr[i],arr1[i]);
		mpz_mul(c,c,inv[i]);
		//mpz_mul(pro,pro,c);
		mpz_add(d,d,c);	
	}
	cout<<endl;
	mpz_mod(d,d,pro);
	gmp_printf("%Zd ",d);

	return 0;
}