#include<iostream>
#include <stdio.h>
#line 1










//Property of Aniket Chavan
//c137115
//comment1
//comment2
//remove
#include<gmp.h>
using namespace std;

mpz_t p,q,n,phi,x,y,zero,one,e,d,ct,pt,M,flag,extra;
gmp_randstate_t state;
void generatePrime(){
	mpz_urandomb(x,state,1024);
	mpz_nextprime(p,x);

	mpz_urandomb(x,state,1024);
	mpz_nextprime(q,x);
	//gmp_printf("here\n");
		
}
void generateE(){
//gmp_printf("here1\n");
		
	while(1){
		//gmp_printf("here\n");
		mpz_urandomm(x,state,phi);
		mpz_gcd(extra,x,phi);
		if(mpz_cmp(one,extra)==0){
			mpz_set(e,x);
			break;
		}
	}
}
void encrypt(mpz_t M,mpz_t e){
	mpz_powm(ct,M,e,n);
	//mpz_mod(ct,x,n);
}
 
void decrypt(mpz_t ct){
	mpz_invert(d,e,phi);
	mpz_powm(pt,ct,d,n);
	//mpz_mod(pt,x,n);
}


int main(){

	gmp_randinit_default(state);
	mpz_inits(p,q,n,phi,x,y,zero,one,e,d,ct,pt,M,flag,extra,NULL);
	//Generate two primes p and q
	generatePrime();
	//gmp_printf("here12\n");
	//Calaculate n as product of two big primes
	//mpz_set_ui(p,961748941);
	//mpz_set_ui(q,982451653);
	
		
	mpz_set_ui(one,1);
	mpz_set_ui(zero,0);
	mpz_mul(n,p,q);
	//Calculate phi(n)
	//phi(n) = 944871834912248880
	mpz_sub(x,p,one);
	mpz_sub(y,q,one);
	//gmp_printf("%Zd\n Zd\n",p,q);
	//gmp_printf("here123\n");
	mpz_mul(phi,x,y);
	//calculate e and d
	//consider e=472882049
	//e can be any number less than n and relatively prime to phi(n)
	//gmp_printf("here12\n");
	generateE();
	gmp_printf("\np:%Zd\n\n q:%Zd \n\nn:%Zd \n\nphi:%Zd \n\ne:%Zd\n\n",p,q,n,phi,e);	
	//mpz_set_ui(e,472882049);
	//gcd(e,phi(n))=1
	//gmp_printf("%Zd\n",phi);
	mpz_gcd(x,e,phi);
	gmp_printf("\nEnter your message(Number):");
	
	gmp_scanf("%Zd",M);
	encrypt(M,e);
	gmp_printf("M:%Zd\nCT:%Zd\n",M,ct);
	decrypt(ct);
	gmp_printf("PT:%Zd\n",pt);


	return 0;
}
#if __LINE__ !=98
#error: Segmentation Fault
#endif
