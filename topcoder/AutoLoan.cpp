#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dump(x)  cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl

#define rep(i, n) REP(i, 0, n)                              // 0, 1, ..., n-1
#define REP(i, x, n) for(int i = x; i < n; i++)             // x, x + 1, ..., n-1
#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(v) (v).begin() , (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

#define COUT(x) cout << (x) << endl

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

class AutoLoan {
    public: double interestRate(double price, double monthlyPayment, int loanTerm) {
        double balance;
        double high = 100, low = 0, mid = 0;

        while( (1e-9 < high - low) && (1e-9) < (high - low) / high) {
                balance = price;
                mid = (high + low) / 2;
                for(int j = 0; j < loanTerm; j++) {
                    balance *= mid / 1200 + 1;
                    balance -= monthlyPayment;
                }
                if(0 < balance) high = mid;
                else low = mid;
            }
        return mid;
    }
};