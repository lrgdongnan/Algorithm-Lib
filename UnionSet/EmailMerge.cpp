//作者：zp19911109
//时间：
//来源：hihoCoder太阁最新面经算法竞赛7-2
//问题：You are given a list of usernames and their email addresses in the following format:
//        alice 2 alice@hihocoder.com alice@gmail.com
//        bob 1 bob@qq.com
//        alicebest 2 alice@gmail.com alice@qq.com
//        alice2016 1 alice@qq.com
//      Your task is to merge the usernames if they share common email address: 
//        alice alicebest alice2016
//        bob


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef unsigned int UI;

const int N = 10100;
map<string, int> emailMap; // email -> user_label
map<int, int> visit; // fa -> ret index
vector<string> userNames;
vector<vector<string>> ret;
int fa[N];

int findset(int x) {
	return x == fa[x] ? x : fa[x] = findset(fa[x]);
}

void unionset(int x, int y) {
	int fx = findset(x);
	int fy = findset(y);
	fa[fx] = fy;
}

int main() {
	// freopen("input", "r", stdin);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		fa[i] = i;
	}
	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		userNames.push_back(name);
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			string email; cin >> email;
			if (emailMap.find(email) == emailMap.end()) {
				emailMap[email] = i;
			}
			else {
				int other = emailMap[email];
				if (other != i) {
					unionset(other, i);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int f = findset(i);
		if (visit.find(f) == visit.end()) {
			ret.push_back({ userNames[i] });
			visit[f] = ret.size() - 1;
		}
		else {
			ret[visit[f]].push_back(userNames[i]);
		}
	}

	for (int i = 0, l = ret.size(); i < l; i++) {
		for (int j = 0, ll = ret[i].size(); j < ll; j++) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}