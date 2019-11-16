#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
 
ll MOD = 1000000007;
int main(){
 
    ll X, Y;
    cin >> X >> Y;
 
    ll ans = 0;

    map<pi, ll> dp;
    dp[make_pair(0, 0)] = 0;

    queue<pii> que;
    que.push(make_pair(make_pair(0, 0), 0));
 
    for(;;){
        cout << que.size() << endl;
        map<pi, ll> tmp;

        if(que.size() == 0){
            break;
        }

        while(!que.empty()){
            ll t_x = que.front().first.first;
            ll t_y = que.front().first.second;
            ll t_c = que.front().second;
            que.pop();
            if(t_x + 1 <= X && t_y + 2 <= Y){
                dp[make_pair(t_x + 1, t_y + 2)] = (t_c + 1) % MOD;
                tmp[make_pair(t_x + 1, t_y + 2)] += dp[make_pair(t_x + 1, t_y + 2)] % MOD; 
            }
            if(t_x + 2 <= X && t_y + 1 <= Y){
                dp[make_pair(t_x + 2, t_y + 1)] = (t_c + 1) % MOD;
                tmp[make_pair(t_x + 2, t_y + 1)] += dp[make_pair(t_x + 2, t_y + 1)] % MOD; 
            }
        }
        auto begin = tmp.begin(), end = tmp.end();
        for (auto iter = begin; iter != end; iter++) {
            ll t_x = iter -> first.first;
            ll t_y = iter -> first.second;
            ll t_c = iter -> second;
            if(t_x <= X && t_y <= Y){
                que.push(make_pair(make_pair(t_x, t_y), t_c));
            }
        }

    }

    cout << dp[make_pair(X, Y)] << endl;;

}