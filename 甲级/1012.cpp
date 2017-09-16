#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
	int N, M;
	int a[2000][5];
	int b[2000];
	int rank[2000][5];

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
		a[i][4] = (int)((a[i][1] + a[i][2] + a[i][3]) / 3);
		rank[i][0] = a[i][0];
	}
	for (int i = 0; i < M; i++){
		cin >> b[i];
	}

	//cout << "a C M E A" << endl;
	//for (int i = 0; i < N; i++){
	//	cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << " " << a[i][3] << " " << a[i][4] << endl;
	//}
	//cout << "b" << endl;
	//for (int i = 0; i < M; i++){
	//	cout << b[i] << endl;
	//}
	//cout << "rank A C M E" << endl;
	//for (int i = 0; i < N; i++){
	//	cout << rank[i][0] << " " << rank[i][1] << " " << rank[i][2] << " " << rank[i][3] << " " << rank[i][4] << endl;
	//}

	int i, j;
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++){
			if (rank[j][0] == b[i]){
				
				int rank1 = 0, rank2 = 0, rank3 = 0, rank4 = 0;
				for (int k = 0; k < N; k++){
					if (a[j][1]>a[k][1]){
						rank1++;
					}
					if (a[j][2]>a[k][2]){
						rank2++;
					}
					if (a[j][3]>a[k][3]){
						rank3++;
					}
					if (a[j][4]>a[k][4]){
						rank4++;
					}
				}
				rank1 = N - rank1;//C
				rank2 = N - rank2;//M
				rank3 = N - rank3;//E
				rank4 = N - rank4;//A

				rank[j][1] = rank4;//A
				rank[j][2] = rank1;//C
				rank[j][3] = rank2;//M
				rank[j][4] = rank3;//E
				
				int min = rank[j][1];
				for (int k = 2; k < 5; k++){
					if (rank[j][k] < min){
						min = rank[j][k];
					}
				}
				for (int k = 1; k < 5; k++){
					if (rank[j][k] == min){
						cout << rank[j][k]<<" ";
						switch (k){
							case 1:cout << "A" <<endl; break;
							case 2:cout << "C" << endl; break;
							case 3:cout << "M" << endl; break;
							case 4:cout << "E" << endl; break;
						}
					break;
					}	
				}
				break;
			}
		}
		if (j == N){
			cout << "N/A" << endl;
		}
	}

	system("pause");
	return 0;
}
