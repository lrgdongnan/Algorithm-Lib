//作者：tyh24689
//题目来源：hihoCoder太阁最新面经算法竞赛9-A
//***********************************************************

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7fffffff;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int main() {
#ifdef TYH
    freopen("in.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    map<string, int> M;
    map<int, string> rM;
    for(int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        rM[i] = name;
        if(M.find(name) != M.end()) {
            cout << "Cache" << endl;
            int id = M[name];
            rM.erase(rM.find(id));
            M.erase(M.find(name));
        } else {
            cout << "Internet" << endl;
            if(M.size() == m) {
                string X = rM.begin()->second;
                M.erase(M.find(X));
                rM.erase(rM.begin());
            }
        }
        rM[i] = name;
        M[name] = i;
    }
    return 0;
}
