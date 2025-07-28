#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<cmath>
#include<numeric>
#include<climits>
using namespace std;
int n, e;
vector<vector<int>> adj_list(100);
bool vis[100];
vector <int> path;
vector <int> best;
int ans;

void dfs(int i){
   vis[i] = 1;
   path.push_back(i);

   for(auto it: adj_list[i]){
      if(!vis[it]){
         dfs(it);
      }
      else{
         auto v = find(path.begin(), path.end(), it);
         if(v != path.end()){
            vector <int> cycle(v, path.end());
            int a = accumulate(cycle.begin(), cycle.end(),0);
            if(a < ans){
               best = cycle;
               ans = a;
            }
         }
      }

   }


   path.pop_back();
   vis[i] = 0;
}

int main(){
   cin >> n >> e;
   for(int i = 0; i<e; i++){
      int a, b;
      cin >> a >>b;
      adj_list[a].push_back(b);
   }

   ans = INT_MAX;

   for(int i = 1; i<=n; i++){
      dfs(i);
   }

   if(best.empty()){
      cout << "-1" << endl;
   }
   else{
      sort(best.begin(), best.end());
      for(auto it: best){
         cout << it << " ";
      }
      cout << endl;
   }

   return 0;
}
