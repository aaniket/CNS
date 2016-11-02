#include<stdio.h>
#include<gmp.h>
#include<time.h>
mpz_t ze;
void gcd(mpz_t a,mpz_t b,mpz_t c){

	if(!mpz_cmp(a,ze)){mpz_set(c,b);return;}
	if(!mpz_cmp(b,ze)){mpz_set(c,a);return;}
	mpz_t mod1;mpz_init(mod1);
	mpz_mod(mod1,b,a);
	gcd(mod1,a,c);
	mpz_clear(mod1);
	return;
}
int main(){
int bit=10;
gmp_randstate_t state;
gmp_randinit_default(state);
int t=5;
while(t--){
	clock_t start=clock();
	mpz_t a,b,c;
	//printf("sfg");
	mpz_inits(a,b,c,NULL);
	mpz_init(ze);
	mpz_set_ui(ze,0);
	mpz_urandomb(a,state,bit);
	mpz_urandomb(b,state,bit);
	//mpz_inp_str(a,NULL,10);
	//mpz_inp_str(b,NULL,10);
	
	//printf("sfg");
mpz_abs(a,a);
mpz_abs(b,b);
	if(-1*mpz_cmp(a,b))gcd(a,b,c);
	else gcd(b,a,c);
	clock_t end=clock();
	float sec=(float)(end-start)/CLOCKS_PER_SEC;
	//mpz_out_str(NULL,10,c);
printf("bit:%d time:%lf\n",bit,sec*1000);
mpz_clear(a);
mpz_clear(b);
mpz_clear(c);
bit*=10;
}
mpz_clear(ze);
	return 0;
}
