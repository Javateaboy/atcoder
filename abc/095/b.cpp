#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    int a[n];
    int sum;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a,a+n);
    cout << ((x-sum)/a[0])+n<<endl;
}