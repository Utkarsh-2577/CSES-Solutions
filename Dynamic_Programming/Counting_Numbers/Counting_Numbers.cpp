/*
 * Problem Name: Counting_Numbers
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-02
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll dp[20][11][2][2];
 
ll count_valid(ll n){
    if(n < 0) return 0;
    if(n == 0) return 1;
 
    string s = to_string(n);
    int len = s.size();
    memset(dp, -1, sizeof(dp));
 
    auto f = [&](int idx, int last, bool tight, bool leading_zero, auto &&f) -> ll {
        if(idx == len) return 1;
        if(dp[idx][last][tight][leading_zero] != -1) return dp[idx][last][tight][leading_zero];
 
        ll ans = 0;
        int limit = tight ? (s[idx]-'0') : 9;
 
        for(int d = 0; d <= limit; d++){
            if(!leading_zero && d == last) continue;
            ans += f(idx+1, d, tight && (d == limit), leading_zero && (d == 0), f);
        }
 
        return dp[idx][last][tight][leading_zero] = ans;
    };
 
    return f(0, 10, true, true, f);
}
 
void solve(){
    ll a, b;
    cin >> a >> b;
    cout << count_valid(b)-count_valid(a-1) << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}