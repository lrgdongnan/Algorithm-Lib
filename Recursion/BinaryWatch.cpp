//作者：李荣贵
//时间：2016-07-28
//题目来源：hihoCoder太阁最新面经算法竞赛10-A
//题目描述：Consider a binary watch with 5 binary digits to display hours (00 - 23) and 6 
//			binary digits to display minutes (00 - 59).For example 11:26 is displayed as 01011:011010.  
//			Given a number x, output all times in human-readable format "hh:mm" when exactly x digits are 1.  
//************************************************************************************************************

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Time
{
	int h, m;
	Time(int a, int b) :h(a), m(b){}
};

vector<Time> T;

bool Comp(const Time& t1,const Time& t2)
{
	if (t1.h == t2.h) return t1.m<t2.m;
	return t1.h<t2.h;
}

void DFS(int n, int pos, int left)
{
	if ((n / 64>23) || (n % 64>59)) return;
	if (left>11 - pos) return;
	if (left == 0){
		T.push_back(Time(n / 64, n % 64));
		return;
	}
	if (left == 11 - pos)
	{
		n |= (((1 << left) - 1) << pos);
		if ((n / 64>23) || (n % 64>59)) return;
		T.push_back(Time(n / 64, n % 64));
		return;
	}
	int m = n | (1 << pos);
	DFS(m, pos + 1, left - 1);
	DFS(n, pos + 1, left);
}

int main()
{
	int x;
	cin >> x;
	if (x == 0) { cout << "00:00\n"; return 0; }
	DFS(0, 0, x);
	sort(T.begin(), T.end(), Comp);
	for (int i = 0; i < T.size(); i++)
	{
		if (T[i].h < 10) cout << 0;
		cout << T[i].h << ":";
		if (T[i].m < 10) cout << 0;
		cout << T[i].m << endl;
	}

	return 0;
}
