//作者：tyh24689
//题目来源：hihoCoder太阁最新面经算法竞赛9-B
//题目描述：滑动解锁
//****************************************************************************

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

typedef long long LL;
const int MOD = 1e9 + 7;
const int INF = 0x7fffffff;
const int N = 10;

int n, m;
int G[N][N], c[N][N], vis[N], ans;

void dfs(int u, int deep, int cnt) {
    if(deep >= 4 && cnt == n) {
        ans++;
    }
    for(int v = 1; v <= 9; v++) {
        if(!vis[v] && (!G[u][v] || vis[G[u][v]])) {
            vis[v] = 1;
            int x = cnt;
            if(c[u][v] == 1) x++;
            dfs(v, deep + 1, x);
            vis[v] = 0;
        }
    }
}
int main() {
#ifdef TYH
    freopen("in.txt", "r", stdin);
#endif // TYH
    int T;
    memset(G, 0, sizeof(G));
    G[1][3] = G[3][1] = 2;
    G[4][6] = G[6][4] = 5;
    G[7][9] = G[9][7] = 8;
    G[1][7] = G[7][1] = 4;
    G[2][8] = G[8][2] = 5;
    G[3][9] = G[9][3] = 6;
    G[1][9] = G[9][1] = 5;
    G[3][7] = G[7][3] = 5;
    scanf("%d" , &T);
    while(T--) {
        scanf("%d", &n);
        memset(c, 0, sizeof(c));
        int x, y;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            c[x][y] = c[y][x] = 1;
        }
        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
