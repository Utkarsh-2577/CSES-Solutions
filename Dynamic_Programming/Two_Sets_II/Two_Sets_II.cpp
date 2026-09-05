/*
 * Problem Name: Two_Sets_II
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-05
 */

#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
 
void solve(){
    int n;
    cin >> n;
    int sum = n*(n+1)/2;
    if(sum%2 != 0){
        cout << 0 << "\n";
        return;
    }
 
    int target = sum/2;
    vector<int> dp(target+1, 0);
    dp[0] = 1;
 
    for(int i = 1; i < n; i++){
        for(int x = target; x >= i; x--){
            dp[x] = (dp[x]+dp[x-i])%MOD;
        }
    }
 
    cout << dp[target] << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}