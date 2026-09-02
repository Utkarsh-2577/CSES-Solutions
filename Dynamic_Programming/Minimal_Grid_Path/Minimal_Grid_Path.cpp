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
    string ans = "";
    ans += grid[0][0];
    vector<pair<int, int>> cur;
    cur.push_back({0, 0});
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vis[0][0] = true;
 
    for(int step = 0; step < 2*n-2; step++){
        char min_char = 'Z'+1;
        for(auto &[r, c] : cur){
            if(r+1 < n && grid[r+1][c] < min_char){
                min_char = grid[r+1][c];
            }
            if(c+1 < n && grid[r][c+1] < min_char){
                min_char = grid[r][c+1];
            }
        }
        ans += min_char;
        vector<pair<int, int>> next_cur;
        for(auto &[r, c] : cur){
            if(r+1 < n && grid[r+1][c] == min_char && !vis[r+1][c]){
                vis[r+1][c] = true;
                next_cur.push_back({r+1, c});
            }
            if(c+1 < n && grid[r][c+1] == min_char && !vis[r][c+1]){
                vis[r][c+1] = true;
                next_cur.push_back({r, c+1});
            }
        }
        cur = move(next_cur);
    }
    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}