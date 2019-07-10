// dam la keo 
// 123 choi 0 thoat
// dem ty so
#include<stdio.h>
#include<stdlib.h>// ham chua rand()
#include<time.h>// chua srand()
#include<windows.h>// chua Sleep()
void dungdem(char x);
void kbb(int x);
int main(){
	srand (time(NULL));
	int op1,op;
	printf("^_^ Keo-Bua-Bao ^_^\n");
	printf("Chon 1 de Choi =))\n");
	printf("Khong choi\nHay chon 1 so khac 1 :((\n");
	printf("Lua chon cua ban la \t");scanf("%d",&op);
	if(op!=1){
		printf("\nGood bye !\nHave  nice day.\n\n");
		system("pause");
		return 0;
	}
	else{
		system("cls");
		printf("\t   OK\nTro choi se bat dau sau 5s\n        ");
		dungdem(5);
		unsigned int p1=0,p2=0,op2;
		do{
			system("cls");
			printf("\n\t P1 - P2\n\t  Ty so\n\t %d  -  %d\n",p1,p2);
			printf("   1. Keo\n");
			printf("   2. Bua\n");
			printf("   3. Bao\n");
			printf("So khac de thoat\n");
			scanf("%d",&op1);
			printf("\t");
			kbb(op1);
			printf(" - ");
			switch(op1){
				case 1: 				
					switch (rand()%3+1){
						case 1:
							kbb(1);
							Sleep(1000);
							break;
						case 2:
							p2++;
							kbb(2);
							Sleep(1000);
							break;
						case 3:
							p1++;
							kbb(3);
							Sleep(1000);
					}
					break;
				case 2: 				
					switch (rand()%3+1){
						case 1: 
							p1++;
							kbb(1);
							Sleep(1000);
							break;
						case 2:
							kbb(2);
							Sleep(1000);
							break;
						case 3:
							p2++;
							kbb(3);
							Sleep(1000);							
					}
					break;
				case 3:		
					switch (rand()%3+1){
						case 1: 
							p2++;
							kbb(1);
							Sleep(1000);
							break;
						case 2:
							p1++;
							kbb(2);
							Sleep(1000);
							break;
						case 3:
							kbb(3);
							Sleep(1000);
					}
					break;
				default :
					printf("Good bye !\nHave  nice day.");
					return 0;
			}					
		}
		while(1);
	}
}
void dungdem(char x){
	for (char i=x;i>=1;i--){
			printf("%d ",i);
			Sleep(1000);
		}
}
void kbb(int x){
	if (x==1)
		printf("Keo");
	if(x==2)	
		printf("Bua");
	if (x==3) 
		printf("Bao");	
}
