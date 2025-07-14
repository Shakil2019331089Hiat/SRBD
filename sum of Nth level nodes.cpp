#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
#include <climits>
#include <stack>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    string tree;
    cin >> tree;

    stack <char> st;
    int ans = 0;
    int temp = 0;

    for(int i = 0; i < tree.size(); i++){

        if(st.size() == n+1 && tree[i] - '0' > 0 && tree[i] - '0' <=9){
            if(temp == 0){
                temp += tree[i] -'0';
            }
            else{
                temp *= 10 ;
                temp +=  tree[i] -'0';
            }     
        }
        else if(tree[i] == '('){
            ans += temp;
            temp  = 0;
            st.push('(');
        }
        
        else if(tree[i] == ')'){
            ans += temp;
            temp = 0;
            st.pop();
        }
        
    }

    cout << ans << endl;

    return 0;
}