#include <bits/stdc++.h>

using namespace std;

void solve(){
    int r, c, n;
    cin >> r >> c >> n;
    unordered_map <int, int> cnt;

    for(int i = 0; i<r; i++){
        int z_count = 0;
        int init_mask = 0;

        for(int j = 0; j<c; j++){
            int a;
            cin >> a;
            if(a == 0){
                z_count ++;
            }
            init_mask = (init_mask << 1) | a;
        }
        if(z_count <= n && (n-z_count) % 2 == 0)
            cnt[init_mask]++;

    }

    int mx = 0;

    for(auto [a,b] : cnt){
        mx = max(mx,b);
    }

    cout << mx << endl;

}

int main(){

    int n;
    //cin >> n;
    n = 1;
    while(n--){
        solve();
    }
    return 0;
}