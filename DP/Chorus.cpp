//题目来源：牛客网-网易笔试编程题
//题目：合唱团 
//	有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
//	要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
//*******************************************************************************************************************

//f[i][j]分别表示，以第i个人为最后一个（也是必选的）人，加上这个人，已经选了 j 个人，最大可能的乘积和最小可能的乘积。 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[55];
ll f[55][15][2];

int main(){
	int n, kk, d;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	scanf("%d%d", &kk, &d);
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		f[i][1][0] = f[i][1][1] = a[i];
		for (int j = 2; j <= kk; ++j){
			for (int k = i - 1; k >= max(i - d, 1); --k){
				f[i][j][0] = max(f[i][j][0], max(f[k][j - 1][0] * a[i], f[k][j - 1][1] * a[i]));
				f[i][j][1] = min(f[i][j][1], min(f[k][j - 1][0] * a[i], f[k][j - 1][1] * a[i]));
			}
		}
		ans = max(ans, max(f[i][kk][0], f[i][kk][1]));
	}
	printf("%lld\n", ans);
	return 0;
}
