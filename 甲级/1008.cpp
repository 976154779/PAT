#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define maxsize 65535


int main(){
	
	int n,a[maxsize];
	int i;
	int now,next;
	int sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	now=0;
	next=a[0];
	for(i=0;i<n;i++){
		if(next-now>0){
			sum+=(next-now)*6;
			sum+=5;
		}
		else{
			sum+=(now-next)*4;
			sum+=5;
		}
		now=next;
		next=a[i+1];
	}
	printf("%d",sum);




	
	return 0;
}  
