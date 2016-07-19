//Author: Bailing
//From: hihoCoder太阁最新面经算法竞赛8-A
//Problem: Little Hi and Little Ho are playing a game. There is an integer array in front of them. 
//They take turns (Little Ho goes first) to select a number from either the beginning or the end of the array. 
//The number will be added to the selecter's score and then be removed from the array. 
//Given the array what is the maximum score Little Ho can get? Note that Little Hi is smart and he always uses the optimal strategy.
//**************************************************************************************************************************************

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int N;
int dp[MAXN][MAXN];
int var[MAXN];

int main(){
	cin >> N;
	for (int i = 1; i <= N; ++i){
		cin >> var[i];
	}

	for (int j = 1; j <= N; ++j){
		for (int i = j; i >= 1; --i){
			if (j - i >= 2){
				int maxStart = var[i] + min(dp[i + 1][j - 1], dp[i + 2][j]);
				int maxEnd = var[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);
				dp[i][j] = max(maxStart, maxEnd);
			}
			else{
				dp[i][j] = max(var[i], var[j]);
			}
		}
	}
	cout << dp[1][N];
	return 0;
}