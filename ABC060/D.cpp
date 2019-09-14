#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <map>


using namespace std;
typedef long long ll;
ll N;
//mapで節約してみた>成功！
//とても気持ちの良いDP
int main(){

    ll N, W;
    cin >> N >> W;

    vector<pair <ll, ll > > p;

    for(ll i = 0; i < N; i++){
        ll w, v;
        cin >> w >> v;
        p.push_back(make_pair(w, v));
    }

    //お気持ちソート
    sort(p.begin(), p.end());

    map<ll, ll> dp;
    dp[0] = 0;
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        vector<pair <ll, ll > > tmp;
        auto begin = dp.begin(), end = dp.end();
        //挿れたとき挿れなかったとき///
        for (auto iter = begin; iter != end; iter++) {
            //cout << iter -> first << " " <<  iter -> second << endl;
            tmp.push_back(make_pair(iter->first, iter->second));
            if(p[i].first + iter->first <= W ){
                tmp.push_back(make_pair(p[i].first + iter->first, p[i].second + iter->second));
            }
            
        }
        //更新
        for (ll j = 0; j < tmp.size(); j++) {
            dp[tmp[j].first] = max(tmp[j].second, dp[tmp[j].first]);
            ans = max(ans, dp[tmp[j].first]);
        }       
    }

    cout << ans << endl;

}