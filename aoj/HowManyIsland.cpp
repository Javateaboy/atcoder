/*
　　こんにちは。あたしはｶｳｶﾞｰﾙ。
　　redcoderになるためAtCoderを巡る旅をしてます。

　　　 　 ＿_
　　　 ヽ|＿_|ノ　　　　ﾓｫ
　　　　||‘‐‘||ﾚ　　_)_, ―‐ 、
　　　　/(Ｙ (ヽ＿ /・ ヽ　　 ￣ヽ
　　　　∠ ＿ ゝ　 ｀^ヽ ﾉ.::::_(ノヽ
　　　　 _/ヽ　 　　  /ヽ￣￣/ヽ
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl

#define rep(i, n) REP(i, 0, n)                  // 0, 1, ..., n-1
#define REP(i, x, n) for(int i = x; i < n; i++) // x, x + 1, ..., n-1
#define FOREACH(x, a) for(auto &(x) : (a))

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

#define COUT(x) cout << (x) << endl

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int W, H;
vector<vector<int>> field;

void dfs(int h, int w) {
    field[h][w] = 0;

    for(int dh = -1; dh <= 1; ++dh) {
        for(int dw = -1; dw <= 1; dw++) {
            int nh = h + dh, nw = w + dw;

            if(nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if(field[nh][nw] == 0) continue;

            dfs(nh, nw);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(cin >> W >> H) {
        if(H == 0 || W == 0) break;
        field.assign(H, vector<int>(W, 0));
        rep(h, H) rep(w, W) cin >> field[h][w];

        int count = 0;
        rep(h, H) {
            rep(w, W) {
                if(field[h][w] == 0) continue;
                dfs(h, w);
                ++count;
            }
        }
        cout << count << endl;
    }
}
