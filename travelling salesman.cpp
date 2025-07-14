#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
int n;
int dis[20][20];
bool vis[20];
int ans;

void all_poss(vector <int> &nod){
    int st = 0;
    int temp = 0;
    if(nod.size() == n-1){
        for(auto v: nod){
            temp += dis[st][v];
            st = v;
        }
        temp += dis[st][0];
        ans = min(ans, temp);
        return;
    }

    for(int i = 1; i<n; i++){
        if(!vis[i]){
            vis[i] = 1;
            nod.push_back(i);
            all_poss(nod);
            nod.pop_back();
            vis[i] = 0;
        }
    }



}

void solve(){

    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> dis[i][j];
        }
    }

    memset(vis, 0, sizeof (vis));

    ans = INT_MAX;
    vector <int> nod;

    all_poss(nod);

    cout << ans << endl;


}

int main(){

    int cas;
    cas = 1;
    cin >> cas;

    while(cas--){
        solve();
    }

    return 0;
}