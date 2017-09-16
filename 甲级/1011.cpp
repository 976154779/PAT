<<<<<<< HEAD
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
	double a[3][3];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cin >> a[i][j];
		}
	}
	double maxProfit = 1;
	for (int i = 0; i < 3; i++){
		double max = a[i][0];
		for (int j = 1; j < 3; j++){
			if (a[i][j]>max){
				max = a[i][j];
			}
		}
		for (int j = 0; j < 3; j++){
			if (a[i][j] == max){
				switch (j){
				case 0:cout << "W "; break;
				case 1:cout << "T "; break;
				case 2:cout << "L "; break;
				}
			}
		}
		maxProfit *= max;
	}
	maxProfit = (maxProfit*0.65 - 1) * 2;
	printf("%.2f", maxProfit);


	system("pause");
	return 0;
}
=======
#include
>>>>>>> 1192d43b6afb390bb7be8d40699f4f1a5e9256bc
