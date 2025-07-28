#include <iostream>
#include <utility>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(){

    int n;
    string stream;
    cin >> n;
    cin >> stream;

    stack <int> st;

    int len = stream.size();
    int ans = 0;
    int answer = 0;

    for(int i = 0; i< len; i++){
        if(stream[i] == '('){
            answer+=ans;
            ans = 0;
            st.push('(');
        }
        else if(stream[i] == ')'){
            answer += ans;
            ans = 0;
            st.pop();
        }
        else if(st.size() == n+1){
            ans *= 10;
            ans += stream[i] - '0';
        }
    }

    cout << answer << endl;

    return 0;
}
