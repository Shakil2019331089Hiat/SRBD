#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
int n, ans;
int st_i, st_j, end_i, end_j;
int holes[100][5];
bool vis[100];
int dist(int x1, int y1, int x2, int y2){
   return abs(x1-x2)+abs(y1-y2);
}
void wormholes(int st_i, int st_j, int cost){
   ans = min(ans, cost + dist(st_i, st_j, end_i, end_j));

   for(int i = 0;i<n; i++){
      if(!vis[i]){
         vis[i] = true;
         int temp = cost + dist(st_i, st_j, holes[i][0], holes[i][1]) + holes[i][4];
         wormholes(holes[i][2], holes[i][3], temp);
         
         temp = cost + dist(st_i, st_j, holes[i][2], holes[i][3]) + holes[i][4];
         wormholes(holes[i][0], holes[i][1], temp);
         vis[i] = false;
      }
   }
}


void solve(){
   cin >> n;
   cin >> st_i >> st_j >> end_i >> end_j;
   for(int i= 0; i<n; i++){
      for(int j=0; j<5; j++){
         cin >> holes[i][j];
      }      
   }
   memset(vis, 0, sizeof vis);

   ans = INT_MAX;
   wormholes(st_i, st_j, 0);
   cout << ans << endl;
}


int main(){
   int cas;
   cin >> cas;
   while(cas --){
      solve();
   }
   return 0;
}
