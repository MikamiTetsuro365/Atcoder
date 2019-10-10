#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  

int main(){

    ll N, Ma, Mb; cin >> N >> Ma >> Mb;

    vector<pii > input;

    for(ll i = 0; i < N; i++){
        ll a, b, c; cin >> a >> b >> c;
        input.push_back(make_pair(make_pair(a, b), c));
    }

    ll ans = 11451451919;
    map<pi, ll> dp;
    dp[make_pair(0, 0)] = 0;

    for(ll i = 0; i < N; i++){
        vector<pii > tmp;

        auto begin = dp.begin(), end = dp.end();
        for (auto iter = begin; iter != end; iter++) {
            //使わないとき
            ll t_a = iter -> first.first;
            ll t_b = iter -> first.second;
            ll t_c = iter -> second;
            //cout <<  t_c << endl;

            tmp.push_back(make_pair(make_pair(t_a, t_b), t_c));

            t_a += input[i].first.first;
            t_b += input[i].first.second;
            t_c += input[i].second;   
            tmp.push_back(make_pair(make_pair(t_a, t_b), t_c));

            //cout <<  t_c << endl;
            
        }

        //更新
        for(ll j = 0; j < tmp.size(); j++){
            //初期化 まだ出てきていない組み合わせ
            ll t_a = tmp[j].first.first;
            ll t_b = tmp[j].first.second;
            if(dp[make_pair(t_a, t_b)] == 0){
                dp[make_pair(t_a, t_b)] = 1145141919;
            }
            
            //cout << tmp[j].first.first << "," << tmp[j].first.second << " " << tmp[j].second << " ";
            dp[tmp[j].first] = min(tmp[j].second, dp[tmp[j].first]);

            //答え更新
            if(t_a != 0 && t_b != 0 ){
                //比率が一緒ですか？
                if(t_a / Ma == t_b / Mb && t_a % Ma == 0 && t_b % Mb == 0){
                    //cout << t_a << " " << t_b << endl;
                    ans = min(ans, dp[tmp[j].first] );
                }   
            }

        }
       // cout << endl;

    }

    /*
    auto begin = dp.begin(), end = dp.end();
    for (auto iter = begin; iter != end; iter++) {
        ll t_a = iter -> first.first;
        ll t_b = iter -> first.second;
        ll t_c = iter -> second;
        cout << "[" << t_a << "," << t_b << "] " << t_c << endl; 
    }
    */
    
    if(ans == 11451451919){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    
}