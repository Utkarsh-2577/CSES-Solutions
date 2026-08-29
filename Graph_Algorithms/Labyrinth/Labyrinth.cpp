/*
 * Problem Name: Labyrinth
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    int start_r = -1, start_c = -1;
    int end_r = -1, end_c = -1;
 
    for(int i = 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                start_r = i;
                start_c = j;
            } else if(grid[i][j] == 'B'){
                end_r = i;
                end_c = j;
            }
        }
    }
 
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, char>>> parent(n, vector<pair<int, char>>(m, {-1, ' '}));
    
    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    vis[start_r][start_c] = true;
 
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};
 
    bool found = false;
    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
 
        if(r == end_r && c == end_c){
            found = true;
            break;
        }
 
        for(int i = 0; i < 4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
 
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] != '#'){
                vis[nr][nc] = true;
                parent[nr][nc] = {i, dir[i]};
                q.push({nr, nc});
            }
        }
    }
 
    if(!found){
        cout << "NO\n";
    } else{
        cout << "YES\n";
        string path = "";
        int curr_r = end_r, curr_c = end_c;
        while(curr_r != start_r || curr_c != start_c){
            int d_idx = parent[curr_r][curr_c].first;
            char move_char = parent[curr_r][curr_c].second;
            path += move_char;
            curr_r -= dr[d_idx];
            curr_c -= dc[d_idx];
        }
        reverse(path.begin(), path.end());
        cout << path.length() << "\n";
        cout << path << "\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}