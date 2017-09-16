#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#include<set>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>


using namespace std;


int main()
{
	int M, N, S;
	cin >> M >> N >> S;
	string nikename[2000];
	for (int i = 0; i < M; i++){
		cin >> nikename[i];
	}


	set<string> winner;
	if (S>M){
		cout << "Keep going..." << endl;
		system("pause");
		return 0;
	}
	cout << nikename[S-1] << endl;
	int count = N;
	for (int i = S - 1; i < M; i++){
		if (count == 0){
			if (winner.find(nikename[i]) == winner.end()){
				cout << nikename[i] << endl;
				winner.insert(nikename[i]);
				count = N;
			}
			else{
				continue;
			}
		}
		count--;
	}
	system("pause");
	return 0;
}
