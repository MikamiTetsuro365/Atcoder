#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    string s;
    cin >> s;

    stack<char > st;

    for(ll i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            st.push('0');
        }else if(s[i] == '1'){
            st.push('1');
        }else{
            if(!st.empty()) st.pop();
        }
    }

    //表示
    string ans;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

}