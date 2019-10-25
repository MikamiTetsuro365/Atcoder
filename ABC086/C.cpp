#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1<<28;
//たどり着けたら時間まで目標地点と１歩先を行き来する
//行き来に2秒かかるのでちょうど戻れないとダメ
int main(){

    ll N; cin >> N;
    ll p_x = 0;
    ll p_y = 0;
    ll pt = 0;
    for(ll i = 0; i < N; i++){
        ll t, x, y; cin >> t >> x >> y;
        ll dis = abs(p_x - x) + abs(p_y - y);
        ll l_dis = abs(t - pt);
        if(p_x == x && p_y == y){
            cout << "No" << endl;
            return 0;              
        }
        if(!(dis <= l_dis)){
            cout << "No" << endl;
            return 0;            
        }
        if((l_dis - dis) % 2 == 1){
            cout << "No" << endl;
            return 0;               
        }
        p_x = x;
        p_y = y;
        pt = t;

    }
    cout << "Yes" << endl;

}