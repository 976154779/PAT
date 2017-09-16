#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int N, M, K;	
int a[1000][1000];
int a_new[1000][1000];//副本
int b[100000000][2];
int c[1000];

bool isAllZero(int x){
	for (int i = 1; i <= N; i++){
		if (a[x][i] == 1){
			return false;
		}
	}
	return true;
}

void Repaire(int x, int c1){
	for (int i = 1; i <= N; i++){
		if(i != c1 && i != x){
			a[x][i] = 1;
			a[i][x] = 1;
			return;
		}
	}
}

int main()
{

	cin >> N >> M >> K;

	//初始化
	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < 1000; j++){
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++){
		cin >> b[i][0] >> b[i][1];
		a[b[i][0]][b[i][1]] = 1;
		a[b[i][1]][b[i][0]] = 1;
	}
	for (int i = 0; i < K; i++){
		cin >> c[i];
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			a_new[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < K; i++){//c[i]
		int count = 0;
		for (int j = 0; j < N; j++){
				a[j][c[i]] = 0;//c[i]这一列全为0
		}
		for (int j = 0; j < N; j++){
			a[c[i]][j] = 0;//c[i]这一行全为0
		}

		for (int k = 1; k <= N; k++){
			if (k == c[i]){
				continue;
			}
			if (isAllZero(k) == true){
				Repaire(k, c[i]);
				count++;
			}
		}
		cout << count << endl;

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				a[i][j] = a_new[i][j];
			}
		}
	}

	system("pause");
	return 0;
}
