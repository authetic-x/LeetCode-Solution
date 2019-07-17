#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll core(ll n) {
    if (n < 4) return n-1;
    ll k;
    for (ll i = 2; i <= sqrt(n)+1; i ++ ) {
        if (i*i > n) {
            k = i-1;
        }
    }
    ll cnt = n - (k*k) + 1;
    return cnt+core(k);
}

int main() {
    long long n;
    cin >> n;
    ll ans = core(n);
    cout << ans << endl;
    return 0;
}