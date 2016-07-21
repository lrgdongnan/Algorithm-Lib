//作者：李荣贵
//时间：2016-07-21
//题目来源：hihoCoder太阁最新面经算法竞赛9-C
//描述
//	Consider the following sequence S which is constrcuted by writting nature numbers one by one : "012345678910111213...".
//	The first digit of S, S[0], is 0. The second digit S[1] is 1. And the 11th digit S[10] is 1.
//	Given an integer N, can you find the digit S[N] ?
//输入
//	An integer N. (0 <= N <= 1018)
//输出
//	Digit S[N].
//****************************************************************************************************************************

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define ll  long long

using namespace std;

ll bits[18];

int DigitN(ll n)
{
	if (n < 10) return (int)n;
	ll temp = 10;
	int k = 2;
	while (bits[k] <= n){ k++; temp *= 10; }
	n -= bits[k-1];
	ll low = temp, high = temp * 10, middle, value;
	while (low <= high)
	{
		middle = low + (high - low) / 2;
		value = (middle - temp)*k;
		if (n < value) high = middle - 1;
		else if (n >= value + k) low = middle + 1;
		else break;
	}
	n -= value;
	int res = to_string(middle)[(int)n] - '0';
	return res;
}

int main()
{
	bits[1] = 10;
	ll temp = 10;
	for (int i = 2; i < 18; i++)
	{
		bits[i] = bits[i - 1] + (temp * 10 - temp)*i;
		temp *= 10;
	}
	ll n;
	cin >> n;
	cout << DigitN(n) << endl;

	system("pause");
	return 0;
}