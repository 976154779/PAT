#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int k1,k2,k3=0;
	int i,j;
	double a[10][2],b[10][2],c[20][2];
	for(i=0;i<10;i++){
		for(j=0;j<2;j++){
			a[i][j]=0;
			b[i][j]=0;
		}
	}
	for(i=0;i<20;i++){
		for(j=0;j<2;j++){
			c[i][j]=0;
		}
	}

	scanf("%d",&k1);
	for(i=0;i<k1;i++){
		scanf("%lf%lf",&a[i][0],&a[i][1]);
	}
	scanf("%d",&k2);
	for(i=0;i<k2;i++){
		scanf("%lf%lf",&b[i][0],&b[i][1]);
	}

	int flags=0;
	for(i=0;i<k1;i++){
		flags=0;
		for(j=0;j<k2;j++){
			if(a[i][0]==b[j][0]){
				c[k3][0]=a[i][0];
				c[k3][1]=a[i][1]+b[j][1];
				k3++;
				flags=1;
			}
		}
		if(flags==0){
			c[k3][0]=a[i][0];
			c[k3][1]=a[i][1];
			k3++;
		}
	}
	for(i=0;i<k2;i++){
		flags=0;
		for(j=0;j<k1;j++){
			if(b[i][0]==a[j][0]){
				//c[k3][0]=a[i][0];
				//c[k3][1]=a[i][1]+b[j][1];
				//k3++;
				flags=1;
			}
		}
		if(flags==0){
			c[k3][0]=b[i][0];
			c[k3][1]=b[i][1];
			k3++;
		}
	}
	//Ã°ÅÝÅÅÐò£¬½µÐò
	double temp1,temp2;
	for(i=0;i<k3-1;i++){
		for(j=0;j<k3-1-i;j++){
			if(c[j][0]<c[j+1][0]){
				temp1=c[j][0];
				temp2=c[j][1];
				c[j][0]=c[j+1][0];
				c[j][1]=c[j+1][1];
				c[j+1][0]=temp1;
				c[j+1][1]=temp2;
			}
		}
	}

	printf("%d",k3);
	for(i=0;i<k3;i++){
		if(c[i][1]!=0){
			printf(" %.0lf %.1lf",c[i][0],c[i][1]);
		}
		else{
			printf(" %.0lf %.0lf",c[i][0],c[i][1]);
		}
	
	}

	return 0;
}



