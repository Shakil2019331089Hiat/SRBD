#include <bits/stdc++.h>

using namespace std;

void dfs(vector <int> &best, int &mn, vector<int> &cycle, vector<vector<int>> &adj_list, vector<bool> &vis, vector<int> &path, int u ){

    vis[u] = 1;
    path.push_back(u);

    for(int v : adj_list[u]){
        if(!vis[v]){
             dfs(best, mn, cycle, adj_list, vis, path, v);
        }
        else{
            auto it = find(path.begin(), path.end(), v);
                
            if(it != path.end()){
                vector <int > cycle(it, path.end());
                int sum = accumulate(cycle.begin(), cycle.end(), 0);
                if(sum < mn){
                    mn = sum;
                    best = cycle;
                }
            }
        }
    }


    vis[u] = 0;
    path.pop_back();

}

void solve(){
    int n, e;
     
    vector <int> path, best;
    vector <int> cycle;
    int mn = 999999999;

    cin >> n >> e;

    vector <bool> vis(n+1, 0);
    vector <vector<int>> adj_list(n+1);

    for(int i =0; i<e;i++){
        int s, t;
        cin >> s >> t;
        adj_list[s].push_back(t);
    }



    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(best, mn, cycle, adj_list, vis, path, i);
        }
    }
    
    if(best.empty()){
        cout << -1 << endl;    
    }
    else{
        sort(best.begin(), best.end());
        for(int it : best){
            cout << it << " ";
        }
        cout << endl;
    }

}




int main(){

    int n = 1;
    while(n--){
        solve();
    }
    return 0;
}