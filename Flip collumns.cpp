#include <iostream>
#include <cstring>
#include <numeric>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;
int n, ans;
int distances[100][100];
int vis[100];

void travel(vector<int>&vec){
    
}


void solve(){
    
    int r, c, toggle;
    cin >> r >> c >> toggle;
    
    unordered_map <int, int> cnt;
    
    for(int i = 0; i<r; i++){
        int init_mask = 0;
        int z_cnt = 0;
        
        for(int j = 0; j<c; j++){
            int a;
            cin >> a;
            if(a == 0){
                z_cnt++;
            }
            init_mask = init_mask << 1| a;
        }
        
        if(z_cnt <= toggle && (toggle - z_cnt) % 2 == 0){
            cnt[init_mask]++;
        }
    }
    
    int mx = 0;
    
    for(auto [a,b] : cnt){
        mx = max(mx, b);
    }
    
    cout << mx << endl; 
    
}


int main(){
    int cas;
    cas = 1;
    while(cas --){
        solve();
    }
    return 0;
}
