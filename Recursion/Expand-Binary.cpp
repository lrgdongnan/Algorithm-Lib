//���ߣ����ٹ�
//ʱ�䣺2016-06-27
//��Ŀ��Դ��hihoCoder̫�������澭�㷨����6-2
//��Ŀ���������Ƕ�֪������������ÿһλ������0��1����һ��СHiͻ�����룺�������ʹ������2�ᷢ��ʲô���飿
//СHi����Ϊ��չ��������������(21)ii = 2 * 21 + 1 = 5, (112)ii = 1 * 22 + 1 * 21 + 2 = 8��
//�ܿ�СHi��ʶ������չ�������У�ÿ�����ı�ʾ��������Ψһ�ġ�����8��������(1000)ii, (200)ii, (120)ii ���ֱ�ʾ������
//����һ��������ʮ������N��СHiϣ��֪��������չ�����Ʊ�ʾ�м��ַ�����
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