#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin() , v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)


int main() {
	int n, h, w; cin >> n >> h >> w;
	int cnt = 0;
	rep(i, n) rep(j, n) {
		if (i + w <= n && j + h <= n) cnt++;
	}
	cout << cnt << endl;
}