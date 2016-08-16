//��Ŀ��Դ������OJ-[1052]Tian Ji -- The Horse Racing
//ʱ�䣺2016-08-16
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
			if (T[front]>K[head]) //�����������������������죬�������
			{
				ans++;
				front++, head++;
			}
			else if (T[front] < K[head]) //����������������������������������������������������������
			{
				ans--;
				back--, head++;
			}
			else //������������������������һ����
			{
				if (T[back]>K[tail]) //��ͬʱ������������������������죬���������
				{
					ans++;
					back--, tail--;
				}
				else //��������������������������������
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
