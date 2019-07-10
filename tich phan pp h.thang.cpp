#include<stdio.h>
#include<math.h>
#define e pow(10,-10)//sai so
double f(double x){
	return sin(x)*sin(x)*cos(x);
}
double tinh( double a,double b,unsigned int n){//a,b la ca tren duoi// n la so buoc
	double h=(b-a)/n;
	double t=0;
	for(unsigned int i=0;i<n;i++){
		t+=0.5* (f(a+i*h) +f(a+(i+1)*h));
	}
	return t*h;
}
int main(){
	unsigned n = 10;
 	double a = 0; //can duoi
 	double b = 1.5708; /* pi/2 *///can tren
 	double t, t1;
 	t1 =tinh( a, b, n );
 	do{
 		t=t1;
 		n*=2;
 		t1 =tinh( a, b, n );
 		
	} while ( fabs( t1 - t ) / 3 > e);
	printf("ket qua: %f",t1);

}
