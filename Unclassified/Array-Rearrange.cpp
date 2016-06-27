//���ߣ����ٹ�
//ʱ�䣺2016-06-27
//��Ŀ��Դ��hihoCoder̫�������澭�㷨����6-1
//��Ŀ������СHi��֪���������ÿ�ζ�����һ�̶ֹ���˳���������飬��ô���پ�����������֮�������ָ���ʼ��˳��
//��������������һ��1 - N ������ P��СHiÿ�����Ŷ��ǰѵ� i ��Ԫ�طŵ��� Pi��λ���ϡ�������� P = (2, 3, 1)��
//�����ʼ������(1, 2, 3)������һ��֮���Ϊ(3, 1, 2)����������֮���Ϊ(2, 3, 1)����������֮����(1, 2, 3)��
//���������е�Ԫ�ؿ�����Ϊ��������ͬ�ġ�
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
		times = (currentTimes*times) / gdc(currentTimes, times);
	}
	cout << times << endl;

	return 0;
}