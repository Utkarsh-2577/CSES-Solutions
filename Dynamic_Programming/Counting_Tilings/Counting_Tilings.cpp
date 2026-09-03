/*
 * Problem Name: Counting_Tilings
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
int n;
void precompute(int row, int current_mask, int next_mask, vector<int> &next_states){
    if(row == n){
        next_states.push_back(next_mask);
        return;
    }
    if(current_mask & (1 << row)){
        precompute(row+1, current_mask, next_mask, next_states);
    } else{
        precompute(row+1, current_mask, next_mask | (1 << row), next_states);
        if(row+1 < n && !(current_mask & (1 << (row+1)))){
            precompute(row+2, current_mask, next_mask, next_states);
        }
    }
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> dp(m+1, vector<int>((1 << n), 0));
    dp[0][0] = 1;
 
    vector<vector<int>> all_masks(1 << n);
    for(int mask = 0; mask < (1 << n); mask++){
        precompute(0, mask, 0, all_masks[mask]);
    }
 
    for(int col = 0; col < m; col++){
        for(int mask = 0; mask < (1 << n); mask++){
            if(!dp[col][mask]) continue;
            for(int next_mask : all_masks[mask]){
                dp[col+1][next_mask] = (dp[col+1][next_mask]+dp[col][mask])%MOD;
            }
        }
    }
 
    cout << dp[m][0] << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}