#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int n;
int sx, sy, ex, ey;
vector <pair<int, int>> nod(20);
bool vis[20];
int ans;

void kim(vector <int> &vec){

    if(vec.size() == n){

        int stx = sx;
        int sty = sy;
        int temp = 0;

        for(auto v: vec){
            temp += abs(nod[v].first - stx) + abs(nod[v].second - sty);
            stx = nod[v].first;
            sty = nod[v].second;
        }
        temp +=  abs(ex - stx) + abs(ey - sty);
        ans = min (ans, temp);
        return;
    }


    for(int  i = 0; i<n; i++){
        if(!vis[i]){
            vis[i] = 1;
            vec.push_back(i);
            kim(vec);
            vec.pop_back();
            vis[i] = 0;
        }
    }


}

void solve(int num){

    cin >> n;

    cin >> sx >> sy;
    cin >> ex >> ey;

    for(int i = 0; i < n; i++){
        cin >> nod[i].first >> nod[i].second;
    }
    memset(vis, 0, sizeof(vis));

    ans = INT_MAX;
    vector<int>vec;

    kim(vec); 

    cout << "# "<< num << " " << ans << endl;
}

int main(){

    int cas;
    int ok;
    cas = 10;
    ok = cas;
    //cin >> cas;

    while(cas--){
        solve(ok-cas);
    }

    return 0;
}