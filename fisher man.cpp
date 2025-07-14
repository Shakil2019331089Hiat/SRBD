#include <bits/stdc++.h>

using namespace std;
int dp [20][20];
int n;
int len;
vector<int> v;
int gates[3];

int dpf(int i, int j){

    if(i >= n){
        if(j == len){
            return 0;
        }
        else{
            return 9999999;
        }
    }
    if(j==len){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int r = dpf(i+1,j);
    int l = dpf(i+1, j+1)  + abs(v[j]- i- 1) + 1;



    return dp[i][j] = min(r,l);
}

void solve(){
    cin >> n;

    

    for(int i = 0; i < 3; i++){
        cin >> gates[i];
    }
    for(int i = 0; i<3; i++){
        int a;
        cin >> a;
        for(int j = 0; j<a; j++){
            v.push_back(gates[i]);
        }
    }

    len = v.size();
    memset(dp, -1, sizeof dp);

    cout << dpf(0,0) << endl;

    
}

int main(){

    int n;
    n = 1;
    //cin >> n;
    while(n--){
        solve();
    }
    return 0;
}