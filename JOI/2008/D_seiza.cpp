#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll limit = 1000000;
ll N, M;

int main(){

    cin >> N;
    ll base_x, base_y; cin >> base_x >> base_y;

    vector<pi> seiza;
    //seiza.push_back(make_pair(0, 0));
    for(ll i = 0; i < N-1; i++){
        ll x, y; cin >> x >> y;
        seiza.push_back(make_pair(x, y));
        //cout << base_x - x << endl;
    }
    cin >> M;
    map<pi, ll> mp;
    for(ll i = 0; i < M; i++){
        ll x, y; cin >> x >> y;
        mp[make_pair(x, y)] = 1;
    }

    //1点を固定して検索
    ll cn = 0;
    ll t_x, t_y;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        cn = 0;
        t_x = iter->first.first - base_x;
        t_y = iter->first.second - base_y;
        //cout << t_x << " " << t_y << endl;
        for(ll i = 0; i < N-1; i++){
            ll x = seiza[i].first;
            ll y = seiza[i].second;
            //cout << x - t_x << "," <<  y - t_y << endl;
            if(x + t_x >= 0 && x + t_x <=limit && y + t_y >= 0 &&  y + t_y <=limit){
                pair<ll, ll> p = make_pair(x + t_x, y + t_y);
                if(mp.find(p) != mp.end()){
                    cn++;
                }
            }
        }
        //星座の個数と同じならループを抜ける
        if(cn == N-1) break;
    }

    cout << t_x << " " << t_y << endl;

}