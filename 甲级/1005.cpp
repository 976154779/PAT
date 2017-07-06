#include<stdio.h>
#include<stdlib.h>

void print(int num){
	switch(num){
		case 0:printf("zero");break;
		case 1: printf("one");break;
		case 2: printf("two");break;
		case 3: printf("three");break;
		case 4: printf("four");break;
		case 5: printf("five");break;
		case 6: printf("six");break;
		case 7: printf("seven");break;
		case 8: printf("eight");break;
		case 9: printf("nine");break;
	}
}
			
int main(){

	int i=1,j=1;
	int sum=0;
	char a;
	int  b[100];
	for(i=1;i<100;i++){
		b[i]=-1;
	} 
	while((a=getchar())!='\n'){
		sum+=(int)(a-48);
	}
//	printf("%d",sum);

	while(1){
		b[j]=sum%10;
		j++;
		sum/=10;
		if(sum==0){
			break;
		}
	}
	for(i=99;i>=2;i--){
		if(b[i]!=-1){
			print(b[i]);
			printf(" "); 
		}
	}
	print(b[1]);

	return 0;
}
