//作者：李荣贵
//时间：2016-06-27
//题目来源：hihoCoder太阁最新面经算法竞赛6-1
//题目描述：小Hi想知道，如果他每次都按照一种固定的顺序重排数组，那么最少经过几次重排之后数组会恢复初始的顺序？
//具体来讲，给定一个1 - N 的排列 P，小Hi每次重排都是把第 i 个元素放到第 Pi个位置上。例如对于 P = (2, 3, 1)，
//假设初始数组是(1, 2, 3)，重排一次之后变为(3, 1, 2)，重排两次之后变为(2, 3, 1)，重排三次之后变回(1, 2, 3)。
//被排数组中的元素可以认为是两两不同的。
//****************************************************************************************************************

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<bool> isUsed;

int Cycle(int pos)
{
	int Count = 0;
	int p = pos;
	isUsed[p] = true;
	while (vec[p] != pos + 1)
	{
		p = vec[p] - 1;
		isUsed[p] = true;
		Count++;
	}
	return ++Count;
}
int gdc(int a, int b)
{
	int c = a%b;
	if (c == 0) return b;
	return gdc(b, c);
}
int main() {
	int n;
	cin >> n;
	vec.assign(n, 0);
	isUsed.assign(n, false);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	int times = 1, currentTimes;
	for (int k = 0; k < n; k++)
	{
		if (isUsed[k]) continue;
		currentTimes = Cycle(k);
		times = currentTimes / gdc(currentTimes, times) * times; //先进行除法后进行乘法运算，防止溢出
	}
	cout << times << endl;

	return 0;
}
