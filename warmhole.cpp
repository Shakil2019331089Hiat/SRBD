#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int hole[100][5];
int vis[100];
int ans;
int n;

int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
} 

void dfs(int stx, int sty, int enx, int eny, int cost){
    ans = min(ans, cost + dist(stx, sty, enx, eny));

    for(int i = 0; i<n; i++){
        
        if(!vis[i]){
              
            vis[i] = 1;

            int temp = cost + dist(stx, sty, hole[i][0], hole[i][1]) + hole[i][4];
            dfs(hole[i][2], hole[i][3], enx, eny, temp);

            temp = cost + dist(stx, sty, hole[i][2], hole[i][3]) + hole[i][4];
            dfs(hole[i][0], hole[i][1], enx, eny, temp);

            vis[i] = false;

        }
    }

}


void solve(){

    cin >> n;
    int start_x, start_y, dest_x, dest_y;
    cin >> start_x >> start_y >> dest_x >> dest_y;

    for(int i = 0; i < n; i++){
        for(int j = 0; j<5; j++){
            cin >> hole[i][j];
        } 
    }

    memset(vis, 0, sizeof vis);

    ans = INT_MAX;

    dfs(start_x, start_y, dest_x, dest_y, 0);

    cout << ans << endl;


}


int main(){

    int cas;
    cin >> cas;
    while(cas--){
        solve();
    }
    return 0;
}