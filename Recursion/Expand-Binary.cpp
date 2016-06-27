//作者：李荣贵
//时间：2016-06-27
//题目来源：hihoCoder太阁最新面经算法竞赛6-2
//题目描述：我们都知道二进制数的每一位可以是0或1。有一天小Hi突发奇想：如果允许使用数字2会发生什么事情？
//小Hi称其为扩展二进制数，例如(21)ii = 2 * 21 + 1 = 5, (112)ii = 1 * 22 + 1 * 21 + 2 = 8。
//很快小Hi意识到在扩展二进制中，每个数的表示方法不是唯一的。例如8还可以有(1000)ii, (200)ii, (120)ii 三种表示方法。
//对于一个给定的十进制数N，小Hi希望知道它的扩展二进制表示有几种方法？
//****************************************************************************************************************

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Recursion(int n, int left, int& Count)
{
	if (left<0 || left>((int)pow(2, n + 2) - 2)) return;
	if (left == 0 || n == 0) { Count++; return; }
	Recursion(n - 1, left, Count);
	Recursion(n - 1, left - (int)pow(2, n), Count);
	Recursion(n - 1, left - (int)pow(2, n + 1), Count);
}

int main() {
	int num, n = 0, Count = 0;
	cin >> num;
	if (num == 0) { cout << 1 << endl; return 0; }
	while ((int)pow(2, n) <= num) n++;
	Recursion(n - 1, num, Count);
	cout << Count << endl;

	return 0;
}