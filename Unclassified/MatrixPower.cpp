//作者：李荣贵
//时间：2016-07-17
//问题描述：矩阵快速求幂，见《编程之美》P163
//************************************************************

#include <iostream>
#include <string>
using namespace std;

class Matrix
{
	int a, b, c, d;
public:
	Matrix(int aa, int bb, int cc, int dd)
		:a(aa), b(bb), c(cc), d(dd){}
	Matrix operator*(Matrix& m)
	{
		Matrix res(0, 0, 0, 0);
		res.a = a*m.a + b*m.c;
		res.b = a*m.b + b*m.d;
		res.c = c*m.a + d*m.c;
		res.d = c*m.b + d*m.d;
		return res;
	}
	void Print()
	{
		cout << a << " " << b << endl;
		cout << c << " " << d << endl;
	}
};

int main()
{
	Matrix A(1, 2, 3, 4);
	int n;
	cin >> n;
	Matrix res(1, 0, 0, 1), temp = A;
	while (n)
	{
		if (n & 1) res = res* temp;
		n = n >> 1;
		temp = temp* temp;
	}
	res.Print();

	system("pause");
	return 0;
}