/*
 * Problem Name: Building_Roads
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;
 
class dsu{
    vector<int> parent;
public:
    dsu(int size){
        parent.resize(size);
        for(int i = 0; i < size; i++){
            parent[i] = i;
        }
    }
    int find_set(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find_set(parent[i]);
    }
    void union_sets(int i, int j){
        int irep = find_set(i);
        int jrep = find_set(j);
        parent[irep] = jrep;
    }
};
 
void solve(){
    int n, m;
    cin >> n >> m;
    
    dsu d(n+1);
 
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        d.union_sets(u, v);
    }
 
    vector<int> roots;
    for(int i = 1; i <= n; i++){
        if(d.find_set(i) == i){
            roots.push_back(i);
        }
    }
 
    cout << roots.size()-1 << "\n";
    for(int i = 0; i < (int)roots.size()-1; i++){
        cout << roots[i] << " " << roots[i+1] << "\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}