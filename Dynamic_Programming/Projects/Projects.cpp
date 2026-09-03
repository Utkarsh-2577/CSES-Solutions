/*
 * Problem Name: Projects
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(){
    int n;
    cin >> n;
    vector<array<ll, 3>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i][1] >> p[i][0] >> p[i][2];
    }
 
    sort(p.begin(), p.end());
 
    vector<ll> ends(n);
    for(int i = 0; i < n; i++){
        ends[i] = p[i][0];
    }
 
    vector<ll> dp(n+1, 0);
 
    for(int i = 0; i < n; i++){
        int k = lower_bound(ends.begin(), ends.begin()+i, p[i][1]) - ends.begin();
        dp[i+1] = max(dp[i], p[i][2]+dp[k]);
    }
 
    cout << dp[n] << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}