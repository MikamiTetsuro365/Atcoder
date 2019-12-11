#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N, D, K; cin >> N >> D >> K;
    vector<pi> plan;

    for(ll i = 0; i < D; i++){
        ll x, y; cin >> x >> y;
        plan.push_back(make_pair(x, y));
    }

    vector<ll > all_ans;
    for(ll k = 0; k < K; k++){
        ll s, e; cin >> s >> e;
        ll t_s = s;
        ll ans = 0;

        //s < e または s > eの時がある
        for(ll d = 0; d < D; d++){
            //すすめる範囲内ならすすめるところまで進むのが一番良い
            ans = d;
            if(t_s >= plan[d].first && t_s <= plan[d].second){
                if(s < e){
                    if(e <= plan[d].second) break;
                    t_s = plan[d].second;
                }else{
                    if(e >= plan[d].first) break;
                    t_s = plan[d].first;
                }
            }
        }

        all_ans.push_back(ans+1);
    }

    for(ll i = 0; i < all_ans.size(); i++){
        cout << all_ans[i] << endl;
    }

}