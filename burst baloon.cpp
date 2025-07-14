#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <utility>
#include <climits>

using namespace std;
int dp[20][20];
vector <int> balloons;

int burst(int st, int ed, int flag){
    if(st>ed){
        return 0;
    }
    if(dp[st][ed] != -1){
        return dp[st][ed];
    }

    int mx = INT_MIN;

    for(int i = st; i<=ed; i++){
        if(flag == 0){
            mx = max(mx, burst(st, i-1, 1) + burst(i+1, ed, 1) + balloons[i]);
        }
        else{
            mx = max(mx, burst(st, i-1, 1) + burst(i+1, ed, 1) + balloons[st-1]* balloons[ed+1]);
        }
    }

    return dp[st][ed] = mx;

}



int main(){

    int n;
    cin >> n;
    
    

    balloons.push_back(1);
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        balloons.push_back(a);
    }
    balloons.push_back(1);

    int ans;

    memset(dp, -1, sizeof dp);

    ans = burst(1, n, 0);


    cout << ans << endl;


    return 0;
}
