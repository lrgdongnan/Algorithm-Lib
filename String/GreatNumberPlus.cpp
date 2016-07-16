//作者：李荣贵
//时间：2016-07-16
//问题描述：用字符串实现大数运算
//******************************************************************************************

#include <iostream>
#include <string>
using namespace std;
#define PAIR pair<string,int>

//一般涉及到大数乘法，一个为大数，而另一个为非大数，运算过程中将非大数看作一个整体进行运算，
//可大大提高效率
string StrMulPlus(string str, int num)
{
	if (num == 0) return "0";
	if (num == 1) return str;
	int n = str.length(), val, carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		val = num*(str[i] - '0') + carry;
		str[i] = '0' + val % 10;
		carry = val / 10;
	}
	if (carry == 0) return str;
	return to_string(carry) + str;
}

PAIR StrDivPlus(string dividend, int divisor)
{
	if (divisor == 0) return PAIR("0", -1);
	if (divisor == 1) return PAIR(dividend, 0);
	int n = dividend.length(), m = to_string(divisor).length();
	if (n < m) return PAIR("0", stoi(dividend));
	string res(n, '0');
	int left;
	if (m == 1) left = 0;
	else left=stoi(dividend.substr(0, m - 1));
	for (int k = m - 1; k < n; k++)
	{
		left = left * 10 + (dividend[k] - '0');
		if (left < divisor) continue;
		res[k] = '0' + left / divisor;
		left = left%divisor;
	}
	int pos = res.find_first_not_of('0');
	if (pos == string::npos) res = "0";
	else if (pos>0) res = res.substr(pos);
	return PAIR(res, left);
}

int main()
{
	cout << StrMulPlus("143", 17) << endl;

	system("pause");
	return 0;
}
