/*
 * Problem Name: Flight_Discount
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll INF = 1e18;
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
 
    vector<vector<ll>> dist(n+1, vector<ll>(2, INF));
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
 
    dist[1][0] = 0;
    pq.push({0, 1, 0}); //{cost,u,coupon}
 
    while(!pq.empty()){
        auto [d, u, c] = pq.top();
        pq.pop();
 
        if(d > dist[u][c]){
            continue;
        }
 
        for(auto& edge : adj[u]){
            int v = edge.first;
            ll w = edge.second;
 
            if(c == 0){
                if(dist[v][0] > d+w){
                    dist[v][0] = d+w;
                    pq.push({dist[v][0], v, 0});
                }
                if(dist[v][1] > d+w/2){
                    dist[v][1] = d+w/2;
                    pq.push({dist[v][1], v, 1});
                }
            }
            if(c == 1){
                if(dist[v][1] > d+w){
                    dist[v][1] = d+w;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }
 
    cout << min(dist[n][0], dist[n][1]) << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}