/*
 * Problem Name: Money_Sums
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int> x(n);
    int max_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        max_sum += x[i];
    }
 
    vector<bool> dp(max_sum+1, false);
    dp[0] = true;
 
    for(int coin : x){
        for(int sum = max_sum; sum >= coin; sum--){
            if(dp[sum-coin]){
                dp[sum] = true;
            }
        }
    }
 
    vector<int> ans;
    for(int sum = 1; sum <= max_sum; sum++){
        if(dp[sum]){
            ans.push_back(sum);
        }
    }
 
    cout << ans.size() << "\n";
    for(auto &i : ans) cout << i << " ";
    cout << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}