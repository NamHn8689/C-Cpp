#include<stdio.h>
#include<math.h>
double f(double x){
	return 1/(2*x+1);
}
double tinh( double a,double b,unsigned int n){//a,b la ca tren duoi// n la so buoc
	double h=(b-a)/2/n;
	double t=0;
	t=f(a)+f(b);
	for(unsigned int i=1;i<2*n;i++){
		if(i%2!=0)
			t+=4*f(a+i*h);
		else 
			t+=2*f(a+i*h);	
	}
	return t*h/3;
}
int main(){
	unsigned int n=10;
	double a=0,b=1,t,t1;
	t1=tinh(a,b,n);
	do{
 		t=t1;
 		n*=2;
 		t1 =tinh( a, b, n );
 		
	} while ( fabs( t1 - t )> pow(10,-10));
	printf("ket qua: %f",t1);
}
