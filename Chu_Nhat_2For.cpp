#include <stdio.h>
int main () {
	int m,n;
	printf("chieu doc= ");scanf("%d",&m);printf("chieu ngang= ");scanf("%d",&n);
	for(int i=1;i<=m;i++){		
		for(int j=1;j<=n;j++)
			printf("*");
		printf("\n");	
	}
}
