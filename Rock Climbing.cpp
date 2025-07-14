#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
int nod[20][20];
int vis[20][20]; 
bool is_possible;

void dfs(int i, int j, int l){

    if(i < 0 || i>=n){
        return;
    }
    if(j < 0 || j >= m){
        return;
    }
    if(vis[i][j]){
        return;
    }

    vis[i][j] = 1;

    if(nod[i][j] == 3){
        is_possible = true;
        return;
    }

    if(j+1 < m && j+1 >=0 && nod[i][j+1] != 0 && !vis[i][j+1]){
        dfs(i, j+1, l);
    }
    if(j-1 < m && j-1 >=0 && nod[i][j-1] != 0 && !vis[i][j-1]){
        dfs(i, j-1, l);
    }

    for(int a = 1; a <= l; a++){
        if(i+a < n && i+a >=0 && nod[i+a][j] !=0 && !vis[i+a][j]){
            dfs(i+a, j, l);
        }
        if(i-a < n && i-a >=0 && nod[i-a][j] !=0 && !vis[i-a][j]){
            dfs(i-a, j, l);
        }
    }

}

void solve(){
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> nod[i][j];
        }
    }

    for(int i = 0; i <= n; i++){
        is_possible = false;
        memset(vis, 0, sizeof (vis));
        dfs(n-1, 0, i);
    
        if(is_possible){
            cout << i << endl;
            return;
        }
    }
    cout << "Not Possible" << endl;
    return;
}

int main(){

    int cas;
    cas = 1;
    //cin >> n;

    while(cas--){
        solve();
    }

    return 0;
}