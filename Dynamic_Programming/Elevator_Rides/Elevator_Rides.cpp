/*
 * Problem Name: Elevator_Rides
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
 
    vector<pair<int, ll>> dp(1 << n, {n+1, 0});
    dp[0] = {1, 0};
 
    for(int mask = 1; mask < (1 << n); mask++){
        for(int p = 0; p < n; p++){
            if(mask & (1 << p)){
                auto prev = dp[mask ^ (1 << p)];
                if(prev.second+w[p] <= x){
                    prev.second += w[p];
                }
                else{
                    prev.first++;
                    prev.second = w[p];
                }
                dp[mask] = min(dp[mask], prev);
            }
        }
    }
 
    cout << dp[(1 << n)-1].first << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}