#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef map<int, int> mi;
typedef set<int> si;
#define VV(T) vector<vector< T > >
#define dump(x)  cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl

#define rep(i, n) REP(i, 0, n)                              // 0, 1, ..., n-1
#define REP(i, x, n) for(int i = x; i < n; i++)             // x, x + 1, ..., n-1
#define invrep(i, n) for(int i = (n)-1; i >= 0; i--)        // n-1, n-2, ..., 0
#define invREP(i, x, n) for(int i = (n)-1; i >= (x; i--)    // n-1, n-2, ..., x
#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(v) (v).begin() , (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

#define PB push_back

#define COUT(x) cout << (x) << endl
#define VECCIN(x) for(auto&youso_: (x) )cin>>youso_
#define VECCOUT(x) for(auto&youso_: (x) )cout<<youso_<<" ";cout<<endl

int main(){
    int T, N, M; cin >> T >> N;
    vi A(100), B(100);
    int used[100];
    rep(i, 100) used[i] = 0;
    rep(i, N) cin >> A[i];
    cin >> M;
    rep(i, M) cin >> B[i];
    int f = 0;
    rep(i, M){
        f = 0;
        rep(j, N){
            if(A[j] <= B[i] && B[i] <= A[j] + T){
                used[j] = 1;
                f = 1;
                break;
            }
        }
        int k = 0;
        rep(j, N) if(!used[j]) A[k++] = A[j];
        if(!f) break;
    }
    if(f) COUT("yes");
    else COUT("no");
}