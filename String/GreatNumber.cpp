//作者：李荣贵
//时间：2016-07-15
//描述：用字符串实现大数据之间的加，减，乘，除法运算
//***********************************************************************************

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define PAIR pair<string,string>

string StrAdd(string s1, string s2)
{
	if (s1.empty()) return s2;
	if (s2.empty()) return s1;
    if (s1.length()<s2.length())
     {
          string temp = s1;
          s1 = s2;
          s2 = temp;
     }
	int n = s1.length(), m = s2.length();
	s2 = string(n - m, '0') + s2;
	for (int i = n - 1; i >= 0; i--)
	{
		s1[i] += s2[i] - '0';
		if (s1[i] - '0' >= 10 && i>0)
		{
			s1[i] -= 10;
			s1[i - 1] += 1;
		}
	}
	if (s1[0] - '0' < 10) return s1;
	s1[0] -= 10;
	return "1" + s1;
}
//两个正整数相减
string StrSub(string s1, string s2)
{
	int n = s1.length(), m = s2.length();
	bool flag = true;
	if (n < m || (n == m && s1 < s2))
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
		flag = false;
	}
	if (m < n)
		s2 = string(n - m, '0') + s2;
	for (int i = n - 1; i >= 0; i--)
	{
		s1[i] -= s2[i] - '0';
		if (s1[i] - '0' < 0)
		{
			s1[i] += 10;
			s1[i - 1]--;
		}
	}
	int pos = s1.find_first_not_of('0');
	if (pos == string::npos) return "0";
	if(flag) return s1.substr(pos);
	return '-' + s1.substr(pos);
}
//字符串乘以一个小于10的正整数
string Mul(string s,int m)
{
	if (m == 0) return "0";
	if (m == 1) return s;
	int n = s.length(),val, carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		val = (s[i] - '0')*m + carry;
		s[i] = '0' + val % 10;
		carry = val / 10;
	}
	if (carry == 0) return s;
	char ch = '0' + carry;
	return ch + s;
}

string StrMul(string s1, string s2)
{
	string res;
	int m = s1.length(), n = s2.length();
	if (m<n)
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}
	for (int i = 0; i < n; i++)
	{
		if (s2[n - 1 - i] == '0') continue;
		res = StrAdd(res, Mul(s1, s2[n - 1 - i] - '0') + string(i, '0'));
	}
	if (res.empty()) return "0";
	return res;
}
int Div(string& s1, string s2)
{
	int low = 1, high = 9, middle;
	string str1, str2;
	while (low <= high)
	{
		middle = (low + high) / 2;
		str1 = Mul(s2, middle);
		if (str1.length()>s1.length() ||
			(str1.length() == s1.length() && str1 > s1))
		{
			high = middle - 1;
		}
		else
		{
			if (middle == 9 || str1==s1) break;
			str2 = Mul(s2, middle + 1);
			if (str2.length() > s1.length() ||
				(str2.length() == s1.length() && str2 > s1))
				break;
			low = middle + 1;
		}
	}
	s1 = StrSub(s1, str1);
	if (s1 == "0") s1 = "";
	return middle;
}
//字符串对的第一个值为商，第二个值为余数
PAIR StrDiv(string dividend, string divisor)
{
	if (divisor == "0") return PAIR(0, 0);
	int n = dividend.length(), m = divisor.length(), k;
	if (n < m || (n == m && dividend < divisor)) return PAIR("0", dividend);
	string res(n - m + 1, '0'), left;
	left = dividend.substr(0, m - 1);
	for (int i = m - 1; i < n;i++)
	{
		left += dividend[i];
		if (left.length() < m || left.length() == m && left < divisor) continue;
		k = Div(left, divisor);
		res[i - m + 1] += k;
	}
	int pos = res.find_first_not_of('0');
	return PAIR(res.substr(pos), left);
}
int main() {
	PAIR ans = StrDiv("199145", "19");
	cout << ans.first << " " << ans.second << endl;

	system("pause");
	return 0;
}
