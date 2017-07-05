#include<stdio.h>
#include<stdlib.h>
#define Inf 65535
int main(){
	
	int n,m,c1,c2;
	int a[500];
	int b[1000][3];
	int m[500][500];//矩阵
	int i,j;
	//输入
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
	}
	//初始化邻接矩阵
	for(int i=0;i<500;i++){
		for(j=0;j<500;j++{
			m[i][i]=0;
		}
	}
	for(int i=0;i<500;i++){
		m[i][i]=Inf;
	}
	for(i=0;i<m;i++){
		m[b[i][0]][b[i][1]]=b[i][2];
	}

	//最短路径算法



	return 0;
}



