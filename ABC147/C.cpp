#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {

    ll N; cin >> N;
    vector<map<ll, ll > > v(N);
    vector<ll > tr(N, 0);
    vector<ll > fl(N, 0);


    for(ll i = 0; i < N; i++){
        ll t; cin >> t; 
        for(ll j = 0; j < t; j++){
            ll a, b; cin >> a >> b;
            a--;

            if(b == 0){
                b = 2;
            }
            v[i][a] = b;
        }
    }

    ll ans = 0;
    for(ll i = 0; i <= (1<<N); i++){
        //ビットの位置を数える
        ll t_ans = 0;
        bool f = true;
        map<ll, ll> tr;
        for(ll j = 0; j < N; j++){
            //右シフトして最下位で立っているかどうか判定
            if((i >> j) & 1 == 1){
                t_ans++;
                tr[j] = 1;
            }
        } 
        //本物は全員同じ発言をしていないとだめ
        //一つでも矛盾があるとだめ
        auto begin1 = tr.begin(), end1 = tr.end();
        for (auto iter = begin1; iter != end1; iter++) {
            //正直者と仮定している人
            ll trr = iter -> first;
            //cout << trr << endl;
            auto begin = v[trr].begin(), end = v[trr].end();
            for (auto iter = begin; iter != end; iter++) {
                //証言
                ll a = iter -> first;
                ll b = iter -> second;

                if(b == 2){
                    //正直者がうそつきといった人が正直者と仮定されていたらfalse
                    if(tr[a] == 1){
                        f = false;
                    }
                }else{
                    //正直者が正直者といった人が正直者と仮定されていなかったらfalse
                    if(tr[a] != 1 || v[a][trr] == 2){
                        f = false;
                    }         
                }

            }  
        }
        if(f == true){
            ans = max(t_ans, ans);
        }
    }

    cout << ans << endl;

}