/*
 * Problem Name: Minimal_Grid_Path
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-02
 */

#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
 
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dp[0][0] = true;
 
    string ans = "";
    ans += grid[0][0];
 
    for(int d = 0; d < 2*n-2; d++){
        char min_char = 'Z'+1;
 
        for(int r = 0; r < n; r++){
            int c = d-r;
            if(c < 0 || c >= n || !dp[r][c]) continue;
 
            if(r+1 < n) min_char = min(min_char, grid[r+1][c]);
            if(c+1 < n) min_char = min(min_char, grid[r][c+1]);
        }
 
        ans += min_char;
 
        for(int r = 0; r < n; r++){
            int c = d-r;
            if(c < 0 || c >= n || !dp[r][c]) continue;
 
            if(r+1 < n && grid[r+1][c] == min_char){
                dp[r+1][c] = true;
            }
            if(c+1 < n && grid[r][c+1] == min_char){
                dp[r][c+1] = true;
            }
        }
    }
 
    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}