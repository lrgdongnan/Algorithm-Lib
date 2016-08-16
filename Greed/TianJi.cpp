//题目来源：杭电OJ-[1052]Tian Ji -- The Horse Racing
//时间：2016-08-16
//*******************************************************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int T[1000];
int K[1000];

int main(){
	int n, ans, front, back, head, tail;
	cin >> n;
	while (n)
	{
		for (int i = 0; i < n; i++) cin >> T[i];
		sort(T, T + n, greater<int>());
		for (int i = 0; i < n; i++) cin >> K[i];
		sort(K, K + n, greater<int>());
		ans = 0;
		front = head = 0;
		back = tail = n - 1;
		while (front < back)
		{
			if (T[front]>K[head]) //如果田忌最快的马比齐王最快的马快，两者相比
			{
				ans++;
				front++, head++;
			}
			else if (T[front] < K[head]) //如果如果田忌最快的马比齐王最快的马慢，用田忌最慢的马与齐王最快的马相比
			{
				ans--;
				back--, head++;
			}
			else //如果田忌最快的马与齐王最快的马一样快
			{
				if (T[back]>K[tail]) //若同时田忌最慢的马比齐王最慢的马快，让两者相比
				{
					ans++;
					back--, tail--;
				}
				else //否则用田忌最慢的马与齐王最快的马相比
				{
					if(T[back]<K[head]) ans--;
					back--, head++;
				}
			}
		}
		if (T[front] > K[head]) ans++;
		else if (T[front] < K[head]) ans--;
		cout << ans * 200 << endl;

		cin >> n;
	}
	system("pause");
	return 0;
}
