#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
vector<vector<pair<ll, double > > > G;

bool check(ll N, vector<pi > SH, ll mid){

}

int main(){

    ll N; cin >> N;
    double mx_dist = 0;
    vector<pi > z;

    for(ll i = 0; i < N; i++){
        double x, y; cin >> x >> y;
        z.push_back(make_pair(x, y));
    }

    G.assign(N, vector<pair<ll, double > >());
    //グラフ入力
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(i == j) continue;
            double dist = sqrt(pow(z[i].first-z[j].first,2)-pow(z[i].second-z[j].second,2));
            G[i].push_back(make_pair(j, dist));
            mx_dist = max(dist, mx_dist);
        }
    }

    /*
    ll left = -1; ll right = mx + 1;

    //最小値を求める
    //rightを寄せていく
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        if(check(N, SH, mid)){
            right = mid;
        }else{
            left = mid;
        }
        //cout << right << endl;
    }
    //最小値
    cout << right << endl;
    */
}