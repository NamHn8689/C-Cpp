#include<stdio.h>
void doi(int &x,int &y){
	int a;
	a=x;x=y;y=a;
}
int main(){
	int a[255],n;
	printf("Nap so phan tu\nn= ");scanf("%d",&n);
	for ( int i = 0; i<n ; i++){
    	printf(" a[%d]=",i+1);
    	scanf("%d", &a[i]);
	}
 	for (int i = 0; i < n; i++){
    	for (int j = i + 1; j < n;j++){
			if (a[j] < a[i])
				doi(a[i],a[j]);
        }
    }
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
}
