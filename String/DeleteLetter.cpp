//��Ŀ��Դ��2017΢���＾У԰��Ƹ���߱�̱���
//��Ŀ��
//Alice writes an English composition with a length of N characters. However, her teacher requires that M 

//illegal pairs of characters cannot be adjacent, and if 'ab' cannot be adjacent, 'ba' cannot be adjacent either.

//In order to meet the requirements, Alice needs to delete some characters.

//Please work out the minimum number of characters that need to be deleted.
//˼·���������������������� Ȼ����ԭʼ����������ɣ�
//******************************************************************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <array>
#include <list>

using namespace std;

char table[100001];
int dp[26] = {0};   //�Ե�'a'+i���ַ���β�����������
bool m[26][26];     //�����ж�����char�Ƿ��������
int main(int argc, char **argv)
{
    int N = 0, M = 0;
    scanf("%d\n", &N);
    scanf("%s", table);
    scanf("%d\n", &M);
    char ch1, ch2;
    for (int i=0; i!=M; ++i)
    {
        cin >> ch1 >> ch2;
        m[ch1 - 'a'][ch2 - 'a'] = true;
        m[ch2 - 'a'][ch1 - 'a'] = true;
    }

    for (int i=0; i<N; ++i)
    {
        char ch1 = table[i];
        int temp = 1;
        for (int j=0; j!=26; ++j)
        {
            if (m[ch1 - 'a'][j])
                continue;
            else
                temp = max(temp, dp[j] + 1);
        }
        dp[ch1 - 'a'] = temp;
    }

    cout << N - *max_element(dp, dp+26) << endl;
    return 0;
}