/*
 * Problem Name: Subordinates
 * Language: C++
 * Category: Tree_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 200005;
vector<int> adj[MAXN];
int sz[MAXN];
 
void dfs(int u){
    sz[u] = 1;
    for(int v : adj[u]){
        dfs(v);
        sz[u] += sz[v];
    }
}
 
void solve(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << sz[i]-1 << (i == n ? "" : " ");
    }
    cout << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}