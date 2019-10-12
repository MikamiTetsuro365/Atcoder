#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N;
    cin >> N;

    vector<ll > ans; 

    vector<pii > input;

    for(ll i = 0; i < N - 1; i++){
        ll c, s, f; cin >> c >> s >> f;
        input.push_back(make_pair(make_pair(c, s), f));
    }

    for(ll i = 0; i < N; i++){
        ll time = 0;
        //cout << i << endl;
        for(ll j = i; j < N - 1; j++){
            ll c = input[j].first.first;
            ll s = input[j].first.second;
            ll f = input[j].second;

            //出発タイミング
            if(time < s){
                //電車が動き始めていない
                time = s;
            }else if(time % f == 0){
                //間髪入れずにすぐ出発できる
            }else{
                //ホームで待ち時間が発生
                //残差分引く
                time = time + f - (time % f);
            }

            time += c;

        }
        ans.push_back(time);

    }

    ans.push_back(0);


    for(ll i = 0; i < N; i++){
        cout << ans[i] << endl;
    }

}