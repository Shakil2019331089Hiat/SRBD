#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<vector>
#include<utility>
#include<cstring>
#include<queue>

using namespace std;

int grid[100][100];
bool vis[100][100];
int n,m;
vector <pair<int,int>> mv = {{1,0}, {-1,0}, {0,1}, {0,-1}};


bool valid(int a, int b){
    if(a >= 0 && a < n && b >=0 && b <m){
        return true;
    }
    return false;
}

bool up(int a){
    return (a == 1 || a == 2 || a ==  4 ||  a == 7);
}

bool down(int a){
    return (a == 1 || a == 2 || a ==  5 ||  a == 6);
}

bool right(int a){
    return (a == 1 || a == 3 || a ==  4 ||  a == 5);
}

bool left(int a){
    return (a == 1 || a == 3 || a ==  6 ||  a == 7);
}


int bfs(int start_i, int start_j, int len){

    if(grid[start_i][start_j] == 0){
        return 0;
    }

    queue<pair<pair<int, int>, int>> q;

    q.push({{start_i, start_j}, 1});
    vis[start_i][start_j] = 1;

    int ans  = 0;

    while(!q.empty()){

        pair<pair<int, int>, int> p;
        p = q.front();

        q.pop();

        int i = p.first.first;
        int j = p.first.second;
        int l = p.second;

        if(l > len){
            return ans;
        }

        ans ++;

        for(int a = 0; a<4; a++){
            int curr_i = i + mv[a].first;
            int curr_j = j + mv[a].second;

            if(valid(curr_i, curr_j) && !vis[curr_i][curr_j] && grid[curr_i][curr_j] != 0){


                if(a == 0 && down(grid[i][j]) && up(grid[curr_i][curr_j])){
                    vis[curr_i][curr_j]  =1;
                    q.push({{curr_i, curr_j}, l+1});
                }

                if(a == 1 && down(grid[curr_i][curr_j]) && up(grid[i][j])){
                    vis[curr_i][curr_j] =1 ;
                    q.push({{curr_i, curr_j}, l+1});
                }

                if(a == 2 && right(grid[i][j]) && left(grid[curr_i][curr_j])){
                    vis[curr_i][curr_j]= 1;
                    q.push({{curr_i, curr_j}, l+1});
                }
                if(a == 3 && right(grid[curr_i][curr_j]) && left(grid[i][j])){
                    vis[curr_i][curr_j]=1;
                    q.push({{curr_i, curr_j}, l+1});
                }
            }
        }




    }

    return ans;
}

void solve(){

    int start_i, start_j, len;
    cin >> n>>m>>start_i>>start_j >> len;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            vis[i][j] = false;
            cin >> grid[i][j];
        }
    }

    int ans = bfs(start_i, start_j , len);
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