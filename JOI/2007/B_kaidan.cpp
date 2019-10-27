#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  

ll MOD = 1000000007;
ll INF = 1145141919;

//2点を固定して求める
int main(){

    ll N; cin >> N;
    vector<pi> c;
    bool grid[5001][5001];

    for(ll i = 0; i <= 5000; i++){
        for(ll j = 0; j <= 5000; j++){
            grid[i][j] = false;
        }
    }

    for(ll i = 0; i < N; i++){
        ll x, y; cin >> x >> y;
        c.push_back(make_pair(x, y));
        grid[x][y] = true; 
    }

    ll ans = -1;
    for(ll i = 0; i < N; i++){
        ll x1 = c[i].first;
        ll y1 = c[i].second;
        for(ll j = i + 1; j < N; j++){
            ll x2 = c[j].first;
            ll y2 = c[j].second;

            ll dx = x1 - x2;
            ll dy = y1 - y2;

            ll area = 0;

            //上下調べる
            if(x1+dy>=0 && y1-dx>=0 && x2+dy>=0 && y2-dx>=0 && x1+dy<=5000 && y1-dx<=5000 && x2+dy<=5000 && y2-dx<=5000){
                //そこに座標はあるか確認
                if(grid[x1+dy][y1-dx] && grid[x2+dy][y2-dx]){
                    //あり
                    area = pow(x1-x2,2) + pow(y1-y2,2);
                }
            }

            ans = max(area, ans);
        }        
    }
    
    cout << ans << endl;

}