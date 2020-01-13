#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

using namespace std;

ll a, b, c;

bool check(ll mid){
    //条件をた満たすか確認
    ll nokori = a * c - mid * b;
    ll downlowd_num = nokori / b;
    if(nokori % b > 0){
        downlowd_num++;
    }
    if(downlowd_num <= c){
        return true;
    }
    return false;
}

int main(){

    cin >> a >> b >> c;

    //無限に待つと絶対に動画を止めずに見られる
    //二分探査

    //最小の値なのでngは当てはまらない数, okはずっと条件に当てはまる数
    //検索対数：待機時間
    ll ng = -1; ll ok = 11451419;

    while(ng + 1 < ok){
        ll mid = (ng + ok) / 2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    //最小値
    cout << ok << endl;

}