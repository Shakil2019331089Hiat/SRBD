#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

vector <vector<int>> pos; 

int plane(int i, int j, int bomb, int cnt){
    if(i<0 || j<0 || j>=5){
        return 0;
    }

    if(pos[i][j] == 2){
        if(bomb && cnt >5){
            return 0;
        }
        else if(!bomb){
            bomb = 1;
        }
    }

    int val = 0;

    for(int k = -1; k<=1; k++){
        if(bomb){
            val = max(val, plane(i-1, j+k, 1, cnt+1));
        }
        else{
            val = max(val, plane(i-1, j+k, 1, cnt+1));
            val = max(val, plane(i-1, j+k, 0, 1));
        }
    }

    return val + (pos[i][j] == 1);

}

void solve(int cas){
    int n,ans;
    cin >> n;
    
    pos.clear();
    pos.resize(n+1, vector<int> (5,0));

    for(int i = 0; i<n;i++){
        for(int j=0; j<5; j++){
            cin >> pos[i][j];
        }
    }

    ans = plane(n,2,0,0);

    cout << "#" << cas << " " << ans << endl;
}
int main(){
    int cas;
    cin >> cas;
    int temp = cas;

    while(cas--){
        solve(temp - cas);
    }
    return 0;
} 