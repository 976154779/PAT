#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define maxsize 65535

int main(){

	int M;
	int i,j;
	int first=0;
	int last=0;
	char id[maxsize][15];
	char in[maxsize][8],out[maxsize][8];
	scanf("%d",&M);
	for(i=0;i<M;i++){
		scanf("%s%s%s",&id[i],&in[i],&out[i]);
	}
	
	
	for(i=1;i<=M-1;i++){
		if(strcmp(in[first],in[i])>0){
			first=i;
		}
		if(strcmp(out[last],out[i])<0){
			last=i;
		}
	}

	printf("%s %s",id[first],id[last]);

	return 0;
}
 
