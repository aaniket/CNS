#include<iostream>
#include <stdio.h>
#include<gmp.h>
using namespace std;

mpz_t p1,p2,p3,p4,p5,prime;

mpz_t xa,ya,xb,yb,p,q,two,one,zero,five,b,product,gcd;
mpz_t rn,n,gp;
gmp_randstate_t state;
mpz_t lb,ub,bound;


void findKeys(){
	
	mpz_urandomb(xa,state,20);
	mpz_mod(xa,xa,n);
	mpz_powm(ya,rn,xa,n);

	gmp_printf("\nNumber n : %Zd\nGenrator : %Zd\nPublic Key : %Zd\nPrivate Key:%Zd\n\n\n",n,rn,ya,xa);

}



void findGenerator(){

	int flag=0;
	mpz_set_ui(one,1);
while(1){	
	//FIND A PRIME LESS THAN N
	while(1){
		mpz_urandomb(prime,state,20);
		mpz_nextprime(prime,prime);
		if(mpz_cmp(prime,n) < 0 ) break;
	}
	 	
	//Find product

	mpz_set_ui(lb,0);
	mpz_set_ui(ub,0);
	mpz_cdiv_q(bound,n,five);
	mpz_add(ub,ub,bound);
	mpz_set_ui(product,1);

	for(int i=0;i<5;i++){
		while(1){
			mpz_set_ui(one,1);
			mpz_urandomb(xb,state,20);
			mpz_gcd(gcd,xb,n);
			//gmp_printf("num:%Zd gcd:%Zd\n",xb,gcd);
			if(mpz_cmp(gcd,one)==0 ){
				mpz_mul(product,product,xb);	
				mpz_add(lb,lb,bound);
				mpz_add(ub,ub,bound);	
				break;			
			}
		}
	}
	
	//FIND PRODUCT CONGRUNCE MOD PRIME
	mpz_mod(product,product,prime);

	mpz_set(rn,product);


		while(1){
			mpz_urandomb(rn,state,20);
			if(mpz_cmp(rn,n) < 0) break;
		}
		
		mpz_cdiv_q(gp,n,p1);
		mpz_powm(b,rn,gp,n);
		if(mpz_cmp(b,one)==0)flag=1;

		mpz_cdiv_q(gp,n,p2);
		mpz_powm(b,rn,gp,n);
		if(mpz_cmp(b,one)==0)flag=1;

		/*mpz_cdiv_q(gp,n,p3);
		mpz_powm(b,rn,gp,n);
		if(mpz_cmp(b,one)==0)flag=1;

		mpz_cdiv_q(gp,n,p4);
		mpz_powm(b,rn,gp,n);
		if(mpz_cmp(b,one)==0)flag=1;

		mpz_cdiv_q(gp,n,p5);
		mpz_powm(b,rn,gp,n);
		if(mpz_cmp(b,one)==0)flag=1;
		*/
		if(flag==0) break;
	}

}


void generateN(){
	mpz_set(n,one);
	mpz_urandomb(gp,state,20);
	
	mpz_set_ui(lb,0);
	mpz_set_ui(ub,0);
	mpz_cdiv_q(bound,gp,five);
	mpz_add(ub,ub,bound);

	/*for(int i=0;i<2;i++){
		while(1){*/
			mpz_set_ui(n,1);
			mpz_urandomb(rn,state,20);
			mpz_nextprime(prime,rn);
			for(int i=0;i<2;i++)
				mpz_mul(n,n,rn);
	mpz_set(prime,rn);
	mpz_set(p1,prime);
 	mpz_set(p2,prime);
 	/*mpz_set(p3,prime);
			/*
			if(mpz_cmp(prime,lb) > 0 && mpz_cmp(prime,ub) <=0){
				
				mpz_mul(n,n,prime);
				mpz_add(lb,lb,bound);
				mpz_add(ub,ub,bound);	
				if(i==0)mpz_set(p1,prime);
				else if(i==1) mpz_set(p2,prime);
				else if(i==2) mpz_set(p3,prime);
				else if(i==3) mpz_set(p4,prime);
				else if(i==4) mpz_set(p5,prime);			
				break;			
			}
		/*}
	}*/
	
   // gmp_printf("n:%Zd\n",n);
	//return;
	findGenerator(); //rn is the generator

	findKeys();

	
}

int main(){

	mpz_inits(xa,ya,xb,yb,p,q,two,one,zero,lb,ub,bound,five,product,gcd,b,NULL);
	mpz_inits(rn,n,gp,NULL);
	mpz_inits(p1,p2,p3,p4,p5,prime,NULL);
	mpz_set_ui(five,5);
	mpz_set_ui(zero,0);
	mpz_set_ui(one,1);
	mpz_set_ui(two,2);

	gmp_randinit_default(state);
	
generateN();
return 0;
}
