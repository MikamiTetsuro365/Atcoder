#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

map<ll, ll> mp;
queue<ll > que;
vector<ll > ans;

int main(){

    ll N;
    cin >> N;

    for(ll i = 1; i <= 9; i++){
        que.push(i);
    }

    for(;;){
        if(ans.size() >= 100000) break;
        
        ll in = que.front();
        ans.push_back(in);
        string c = to_string(in);
        que.pop();
        for(ll j = 0; j <= 9; j++){
            if(abs(c[c.length()-1] - ('0' + j)) <= 1){
                char tt = '0' + j;
                string tmp = c + tt;
                ll num = stoll(tmp);
                que.push(num);
                //cout << num << endl;
            }
        }        
    }

    // for(ll i = 0; i < N; i++){
    //     cout << ans[i] << endl;
    // }
    cout << ans[N-1] << endl;

}