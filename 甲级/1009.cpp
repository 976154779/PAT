#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int k1,k2,k3=0;
	int i,j,k;
	double a[10][2],b[10][2],c[100][2];
	for(i=0;i<10;i++){
		for(j=0;j<2;j++){
			a[i][j]=0;
			b[i][j]=0;
		}
	}
	for(i=0;i<100;i++){
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
	
	for(i=0;i<k1;i++){
		for(j=0;j<k2;j++){
			c[k3][0]=a[i][0]+b[j][0];
			c[k3][1]=a[i][1]*b[j][1];
			k3++;	
		}
	}

	for(i=0;i<k3;i++){
		for(j=i+1;j<k3;j++){
			if(c[i][0]==c[j][0]){
				c[i][1]+=c[j][1];
				for(k=j;k<k3-1;k++){
					c[k][0]=c[k+1][0];
					c[k][1]=c[k+1][1];	
				}
				k3--;
			}
		}	
	}
	//ð�����򣬽���
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



