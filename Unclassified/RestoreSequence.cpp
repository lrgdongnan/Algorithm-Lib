//��Ŀ��Դ��ţ����-���ױ��Ա����
//��Ŀ�����л�ԭ
//	ţţ����ҵ������һ������Ϊ n ������ A��������а����˴�1��n��n������������ΪһЩԭ��������һЩλ�ã������� 10 �����������ˣ�
//	����ţţ�ǵ��������˳��Ե������� k��˳�����ָ���� i < j �� A[i] < A[j] �Ķ����������ţţ��������������Ҫ��ĺϷ����е���Ŀ��
//************************************************************************************************************************************

//˼·��
//��ͳ����Щ��û���֣���Щλ��ȱ����ֵ�� 
//Ȼ���Ǽ��㡣 
//10!=3628800 
//�����ÿ�����л��������㣨~100*100�����ⲻ�У�̫���� 
//����Ԥ�ȼ���һ���֡� 
//��˳�����=�Ѿ����ȥ����֮���˳�����+û�����ȥ����֮���˳�����+�Ѿ����ȥ��û�����ȥ����֮���˳����� 
//��һ���֣�Ԥ����һ��ͺ��� 
//�ڶ����֣�ֻ��10*10���������� 
//�������֣�Ԥ�ȴ���ÿ�������ڿ�λ�ϣ�������Ԥ�����ȥ������ɵ�˳����� 
//��������ӣ��жϵȲ�����k���С�

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
