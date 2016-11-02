#include<stdio.h>
#include<gmp.h>
#include<time.h>
mpz_t ze,result,gcd,gcdN,one,x,y;

void eucGcd(mpz_t a,mpz_t b){

	if(!mpz_cmp(a,ze)){mpz_set(gcd,b);return;}
	if(!mpz_cmp(b,ze)){mpz_set(gcd,a);return;}
	mpz_t mod1;
	mpz_init(mod1);
	mpz_mod(mod1,b,a);
	eucGcd(mod1,a);
	mpz_clear(mod1);
	return;

}

void extEuc(mpz_t a,mpz_t b){

	if(!mpz_cmp(b,ze)){
		mpz_set(x,one);
		mpz_set(y,ze);
		//gmp_printf("%Zd %Zd\n", x, y);
		return;
	}
	mpz_t mod1;
	mpz_init(mod1);
	mpz_mod(mod1,a,b);
	//gmp_printf("%Zd %Zd\n", a, b);
	extEuc(b,mod1);	

	mpz_t quotient,mul,sub,temp,tempmod,tempsub,tempa;
	mpz_inits(quotient,mul,sub,temp,tempmod,tempsub,tempa,NULL);
	
	mpz_mod(tempmod,a,b);
	//gmp_printf("%Zd %Zd %Zd\n", tempmod, a, b);
	mpz_sub(tempa,a,tempmod);	
	//printf("%Zd\n", a);
	
	mpz_cdiv_q(quotient,tempa,b);
	mpz_mul(mul,quotient,y);
	mpz_sub(sub,x,mul);
	
	mpz_set(temp,y);
	mpz_set(y,sub);
	mpz_set(x,temp);
	
	return;

}

void makeCoprime(mpz_t a,mpz_t b){
	mpz_t tempa,tempb;
	mpz_inits(tempa,tempb,NULL);
	mpz_set(tempa,a);
	mpz_set(tempb,b);	
	eucGcd(tempa,tempb);
	mpz_div(a,a,gcd);
	mpz_div(b,b,gcd);
}

void checkPossible(mpz_t a, mpz_t n){
	mpz_t tempa,tempb;
	mpz_inits(tempa,tempb,NULL);
	mpz_set(tempa,a);
	mpz_set(tempb,n);	
	eucGcd(tempa,tempb);

	if(!mpz_cmp(gcd,one))mpz_set(gcdN,one);	
	else mpz_set(gcdN,ze);
}

void modMul(mpz_t a,mpz_t b,mpz_t n){
	mpz_t mul,mod;
	mpz_inits(mul,mod,NULL);
	mpz_mul(mul,a,b);
	mpz_mod(mod,mul,n);
	mpz_set(result,mod);
}

void modSum(mpz_t a,mpz_t b,mpz_t n){
	mpz_t add,mod,mod1,mod2,sub;
	mpz_inits(add,mod,mod1,mod2,sub,NULL);
	mpz_mod(mod1,a,n);
	mpz_mod(mod2,b,n);
	mpz_add(sub,mod1,mod2);
	mpz_add(add,sub,n);
	mpz_mod(mod,add,n);
	mpz_set(result,mod);
}

void modSub(mpz_t a,mpz_t b,mpz_t n){
	mpz_t newb;
	mpz_init(newb);
	mpz_neg(newb,b);
	modSum(a,newb,n);
}

void modDiv(mpz_t a,mpz_t b,mpz_t n){
	mpz_t m;
	mpz_init(m);
	mpz_set(m,n);
	makeCoprime(a,b);
	checkPossible(b,n);
	if(mpz_cmp(gcdN,one)){printf("Not Possible \n");return;}
	extEuc(b,n);
	gmp_printf("%Zd %Zd\n",b,n);
	modMul(a,x,m);
}

int main(){
		
	printf("Cases\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n\n");
	while(1){
		int case1;
		mpz_t a,b,n;
		mpz_inits(a,b,n,ze,result,gcd,gcdN,one,x,y,NULL);
		mpz_set_ui(ze,0);
		mpz_set_ui(one,1);
		scanf("%d",&case1);
		gmp_scanf("%Zd%Zd%Zd",a,b,n);
		switch(case1){
			case 1:	{modSum(a,b,n);
					gmp_printf("%Zd\n",result);
					break;}
			case 2:	{modSub(a,b,n);
					gmp_printf("%Zd\n",result);
					break;}
			case 3:	{modMul(a,b,n);
					gmp_printf("%Zd\n",result);
					break;}
			case 4:	{modDiv(a,b,n);
					gmp_printf("%Zd\n",result);
					break;}
			Default:{printf("Invalid input\n");
					break;}
		}
	}
	return 0;
}
