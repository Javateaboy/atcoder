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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m, n;
    cin >> m;

    vector<pair<int, int>> mxy(m), nxy, vec(m - 1);
    set<pair<int, int>> nSet;

    rep(i, m) cin >> mxy[i].first >> mxy[i].second;

    cin >> n;
    nxy.resize(n);

    rep(i, n) {
        int x, y;
        cin >> x >> y;
        nxy[i].first  = x;
        nxy[i].second = y;
        nSet.insert({x, y});
    }

    rep(i, m - 1) {
        vec[i].first  = (mxy[i + 1].first - mxy[i].first);
        vec[i].second = (mxy[i + 1].second - mxy[i].second);
    }

    REP(i, 1, m - 1) {
        vec[i].first += vec[i - 1].first;
        vec[i].second += vec[i - 1].second;
    }

    int ansX, ansY;
    rep(i, n) {
        bool flg = true;
        for(const auto &a : vec) {
            int x = nxy[i].first + a.first;
            int y = nxy[i].second + a.second;
            // cout << x << " " << y << endl;
            if(nSet.find({x, y}) == nSet.end()) { // 対応する座標が無ければ終了
                flg = false;
                // cout << "break" << endl;
                break;
            }
        }
        if(flg) {
            ansX = nxy[i].first - mxy[0].first;
            ansY = nxy[i].second - mxy[0].second;
        }
    }
    cout << ansX << " " << ansY << endl;
}
