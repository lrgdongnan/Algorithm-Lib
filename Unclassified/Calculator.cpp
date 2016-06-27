//作者：李荣贵
//时间：2016-06-27
//题目来源：hihoCoder太阁最新面经算法竞赛6-3
//题目描述：编写一个程序可以完成基本的带括号的四则运算。其中除法(/)是整除，并且在负数除法时向0取整。
//(C/C++/Java默认的除法就是向0取整，python默认的是向负无穷取整。)
//例如计算 100 * (2 + 12) - (20 / 3) * 2, 结果是1388。
//***************************************************************************************************

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;
int Operate(int num1, int num2, char oper)
{
	switch (oper)
	{
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1*num2;
	case '/':return num1 / num2;
	}
}
bool isEqual(char op1, char op2)
{
	if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-')) return true;
	if ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/')) return true;
	return false;
}
int Cal(string& formu)
{
	stack<int> nums;
	stack<char> oper;
	int num = 0, n = formu.length(), num1, num2;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (formu[i] >= '0' && formu[i] <= '9')
		{
			flag = true;
			num = num * 10 + formu[i] - '0';
			continue;
		}
		if (flag) { nums.push(num); num = 0; flag = false; }
		
		if (formu[i] == ')')
		{
			while (oper.top() != '(')
			{
				num2 = nums.top();
				nums.pop();
				num1 = nums.top();
				nums.pop();
				nums.push(Operate(num1, num2, oper.top()));
				oper.pop();
			}
			oper.pop();
		}
		else if ((!oper.empty() && oper.top() == '(') || formu[i] == '(') oper.push(formu[i]);
		else if (!oper.empty() && (isEqual(oper.top(),formu[i]) || 
			formu[i] == '+' || formu[i] == '-'))
		{
			num2 = nums.top();
			nums.pop();
			num1 = nums.top();
			nums.pop();
			nums.push(Operate(num1, num2, oper.top()));
			oper.pop();
			if(formu[i]==')') oper.pop();
			else i--;
		}
		else
			oper.push(formu[i]);
	}
	if (flag) nums.push(num);
	while (!oper.empty())
	{
		num2 = nums.top();
		nums.pop();
		num1 = nums.top();
		nums.pop();
		nums.push(Operate(num1, num2, oper.top()));
		oper.pop();
	}
	return nums.top();
}

int main() {
	fstream in("data.txt");
	string formu;
	in >> formu;
	cout << Cal(formu) << endl;

	system("pause");
	return 0;
}