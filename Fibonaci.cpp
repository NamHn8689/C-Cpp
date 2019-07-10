#include <stdio.h>
int main () {
	int n,a=1,b=1,s;
	printf("n= ");scanf("%d",&n);printf("%d ",a);printf("%d ",b);
	for(int i=2	;i!=n;i++){
		s=a+b;
		printf("%d ",s);
		b=a;a=s;
	}
}
