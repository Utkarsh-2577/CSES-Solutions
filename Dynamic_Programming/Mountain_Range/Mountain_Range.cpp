/*
 * Problem Name: Mountain_Range
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-04
 */

#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
 
    vector<int> l(n, -1), r(n, -1);
    vector<int> st;
 
    for(int i = 0; i < n; i++){
        while(!st.empty() && h[st.back()] <= h[i]){
            st.pop_back();
        }
        if(!st.empty()){
            l[i] = st.back();
        }
        st.push_back(i);
    }
 
    st.clear();
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && h[st.back()] <= h[i]){
            st.pop_back();
        }
        if(!st.empty()){
            r[i] = st.back();
        }
        st.push_back(i);
    }
 
    vector<int> dp(n, -1);
    auto get_dp = [&](int i, auto &&get_dp) -> int {
        if(dp[i] != -1) return dp[i];
        int res = 1;
        if(l[i] != -1){
            res = max(res, 1+get_dp(l[i], get_dp));
        }
        if(r[i] != -1){
            res = max(res, 1+get_dp(r[i], get_dp));
        }
        return dp[i] = res;
    };
 
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, get_dp(i, get_dp));
    }
 
    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}