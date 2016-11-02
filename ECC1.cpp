#include<iostream>
#include<gmp.h>
using namespace std;
mpz_t x1,x2,x3,y1,y2,y3,a,b,c,lambda,lambda1,two,three,e1,e2,prime,inverse;

void calculateLambda(){
	
	mpz_sub(e1,y2,y1);
	mpz_sub(e2,x2,x1);
	mpz_invert(inverse,e2,prime);
	mpz_mul(e2,e1,inverse);
	
	mpz_set(lambda1,e2);
	mpz_mod(lambda1,lambda1,prime);

	mpz_mul(e2,e2,e2);
	mpz_mod(lambda,e2,prime);

}

void addition(){

	calculateLambda();

	mpz_add(e1,x1,x2);
	mpz_mod(e1,e1,prime);
	mpz_sub(x3,lambda,e1);
	//mpz_mod(lambda,lambda,prime);
	mpz_mod(x3,x3,prime);

	mpz_sub(e1,x1,x3);
	mpz_mul(e2,lambda1,e1);
	mpz_sub(y3,e2,y1);
	mpz_mod(y3,y3,prime);
	
} 

void doubling(){
	
	mpz_mul(e1,x1,x1);
	mpz_mul(e1,e1,three);
	mpz_add(e1,e1,a);
	
	mpz_mul(e2,y1,two);
	mpz_invert(inverse,e2,prime);

	mpz_mul(e1,e1,inverse);
	mpz_set(c,e1);

	mpz_mul(e1,e1,e1);
	mpz_mod(e1,e1,prime);
	mpz_mul(e2,x1,two);
	mpz_sub(x3,e1,e2);
	mpz_mod(x3,x3,prime);

	mpz_sub(e1,x1,x3);
	mpz_mod(e1,e1,prime);
	mpz_mul(e2,e1,c);
	mpz_mod(e2,e2,prime);
	mpz_sub(y3,e2,y1);
	mpz_mod(y3,y3,prime);

}

void multiply(){
	mpz_set_ui(x2,0);
	mpz_set_ui(y2,0);
	cout<<"enter k: ";int k;cin>>k;
	int flag=0;
	while(k>0){
		int mod=k%2;
		k/=2;
		if(mod==1){
			if(flag==0){		
				//Set Q for first time
				mpz_set(x2,x1);
				mpz_set(y2,y1);
				flag=1;
			}
			else{
				addition();
				mpz_set(x2,x3);
				mpz_set(y2,y3);
			}
			gmp_printf("Addition Q:(%Zd,%Zd)\n",x2,y2);
		}
		doubling();
		mpz_set(x1,x3);
		mpz_set(y1,y3);
		gmp_printf("Doubling P:(%Zd,%Zd)\n",x1,y1);
	}
	gmp_printf("x1:%Zd y1:%Zd\n",x2,y2);
			
}

int main(){
	mpz_inits(x1,x2,x3,y1,y2,y3,a,b,c,lambda,lambda1,two,three,e1,e2,prime,inverse,NULL);
	mpz_set_ui(prime,29);
	mpz_set_ui(a,4);
	mpz_set_ui(b,20);
	mpz_set_ui(two,2);
	mpz_set_ui(three,3);
	int c;
	cout<<"1.Addition\n2.Doubling\n3.Multiply\n";	
	while(1){
		cout<<"1|2|3?\n";
		cin>>c;
		//if(c!=1 || c!=2 || c!=3) break;
		switch(c){
			case 1:	cout<<"enter x1,y1,x2,y2\n";
					gmp_scanf("%Zd%Zd%Zd%Zd",x1,y1,x2,y2);
					addition();
					gmp_printf("x3:%Zd y3:%Zd\n",x3,y3);
					break;
			case 2:	cout<<"enter x1,y1\n";
					gmp_scanf("%Zd%Zd%",x1,y1);
					doubling();
					gmp_printf("x3:%Zd y3:%Zd\n",x3,y3);
					break;
			case 3:	cout<<"enter x1,y1\n";
					gmp_scanf("%Zd%Zd%",x1,y1);
					multiply();
					break;
			default:break;
		}
	

	}	
	return 0;
}
