//题目来源：牛客网-网易笔试编程题
//题目：数列还原
//	牛牛的作业薄上有一个长度为 n 的排列 A，这个排列包含了从1到n的n个数，但是因为一些原因，其中有一些位置（不超过 10 个）看不清了，
//	但是牛牛记得这个数列顺序对的数量是 k，顺序对是指满足 i < j 且 A[i] < A[j] 的对数，请帮助牛牛计算出，符合这个要求的合法排列的数目。
//************************************************************************************************************************************

//思路：
//先统计哪些数没出现，哪些位置缺少数值。 
//然后考虑计算。 
//10!=3628800 
//如果是每种排列还暴力计算（~100*100），这不行，太慢了 
//考虑预先计算一部分。 
//总顺序对数=已经填进去的数之间的顺序对数+没有填进去的数之间的顺序对数+已经填进去和没有填进去的数之间的顺序对数 
//第一部分：预先算一遍就好了 
//第二部分：只有10*10，暴力计算 
//第三部分：预先处理，每个数填在空位上，和其他预先填进去的数组成的顺序对数 
//三部分相加，判断等不等于k就行。

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[105];
bool appear[105];
int missidx[15];
int missnum[15];
int misscnt = 0;
int smaller[105][105];
int larger[105][105];

int calc_orderedPairs(int *num, int n){
	int ans = 0;
	for (int i = 1; i<n; i++){
		if (num[i])
		for (int j = 0; j<i; j++){
			if (num[j] && num[j]<num[i]){
				++ans;
			}
		}
	}
	return ans;
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	if (k>n*(n - 1) / 2){
		puts("0");
		return 0;
	}
	for (int i = 0; i<n; i++){
		scanf("%d", &a[i]);
		if (!a[i])missidx[misscnt++] = i;
		else appear[a[i]] = 1;
	}
	misscnt = 0;
	for (int i = 1; i <= n; i++){
		if (!appear[i]){
			missnum[misscnt++] = i;
		}
	}

	//given inner
	int given = calc_orderedPairs(a, n);
	if (given>k){
		puts("0");
		return 0;
	}

	//given and not given
	for (int i = 0; i<misscnt; ++i){
		int small = 0, large = 0;
		for (int j = 0; j<n; j++){
			if (!a[j]){
				smaller[j][missnum[i]] = small;
			}
			else if (a[j]<missnum[i])++small;
		}
		for (int j = n - 1; j >= 0; --j){
			if (!a[j]){
				larger[j][missnum[i]] = large;
			}
			else if (a[j]>missnum[i])++large;
		}
	}

	int ans = 0;
	//not given
	do{
		int inner = calc_orderedPairs(missnum, misscnt);
		for (int i = 0; i<misscnt; ++i){
			inner += smaller[missidx[i]][missnum[i]];
			inner += larger[missidx[i]][missnum[i]];
		}
		if (inner + given == k) ++ans;
	} while (next_permutation(missnum, missnum + misscnt));

	printf("%d\n", ans);
	return 0;
}
