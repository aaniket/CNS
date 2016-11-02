#include <stdio.h>
#include <gmp.h>
#define null NULL
mpz_t x,y,zero,one,mone;
void ExtEuc(mpz_t a,mpz_t b){

	if(!mpz_cmp(b,zero)){
		mpz_set(x,one);
		mpz_set(y,zero);
		//gmp_printf("%Zd %Zd\n", x, y);
		return;
	}
	mpz_t mod1;
	mpz_init(mod1);
	mpz_mod(mod1,a,b);
	//gmp_printf("%Zd %Zd\n", a, b);
	ExtEuc(b,mod1);	

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
int main(){
while(1){
	mpz_inits(x,y,zero,one,mone,null);

	mpz_set_ui(x,0);
	mpz_set_ui(y,0);
	mpz_set_ui(zero,0);
	mpz_set_ui(one,1);
	mpz_set_ui(mone,-1);

	mpz_t a,b;
	mpz_inits(a,b,NULL);
	gmp_scanf("%Zd %Zd", a, b);
	//mpz_abs(a,a);
	//mpz_abs(b,b);
	
	
	
	//gmp_printf("%Zd %Zd\n", a, b);
	//a positive and b negative
	if(mpz_sgn(a)==1 && mpz_sgn(b)==1){
		mpz_t subs;
		mpz_init(subs);
		mpz_sub(subs,a,b);
		ExtEuc(a,b);
	
		gmp_printf("%Zd %Zd\n",x,y);
	}
	else if(mpz_sgn(a)!=1 && mpz_sgn(b)!=1){
		mpz_t _x,_y;
		mpz_inits(_x,_y,NULL);
	
		mpz_abs(a,a);
		mpz_abs(b,b);
		mpz_t subs;
		mpz_init(subs);
		mpz_sub(subs,a,b);

		ExtEuc(a,b);

		
		mpz_neg(_x,x);
		mpz_neg(_y,y);
		//gmp_printf("%Zd %Zd\n",x,y);
		gmp_printf("%Zd %Zd\n",_x,_y);
	}
	else if(mpz_sgn(a)==1 && mpz_sgn(b)!=1){
		ExtEuc(a,b);
		gmp_printf("%Zd %Zd\n",x,y);

	}
	else if(mpz_sgn(a)!=1 && mpz_sgn(b)==1){
		ExtEuc(a,b);
		gmp_printf("%Zd %Zd\n",x,y);

	}
	
	
}
return 0;
}
