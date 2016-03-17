//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();

bool avis[101];
bool ares[101];
vector<vector<int>> v(101);
void adfs(int n, int k) {
	if (k)
		avis[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		int ch = v[n][i];
		if (!avis[ch])
			adfs(ch, k + 1);
	}
	if (k || avis[n])
		ares[n] = true;
}

//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
	// 280 - Vertex
	int n, from, to;
	while (cin >> n && n) {
		for (int i = 1; i <= n; i++)
			v[i].clear();
		while (cin >> from)
			if (from == 0) {
				int num, test;
				cin >> num;
				while (num--) {
					cin >> test;
					memset(avis, 0, sizeof(avis));
					memset(ares, 0, sizeof(ares));
					vector<int> res;
					adfs(test, 0);
					for (int i = 1; i <= n; i++) {
						if (!ares[i])
							res.push_back(i);
					}
					cout << res.size();
					for (int i = 0; i < res.size(); i++) {
						if (i < res.size())
							cout << " ";
						cout << res[i];
					}
					cout << endl;
				}
				goto hell;
			} else
				while (cin >> to && to) {
					v[from].push_back(to);
				}
		hell: ;
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
