#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//すべてのりんごの値段が違うということが肝
//ということは入力された数列で最大の利益がでる価格のペアが必ず1種類ある
//そのペアは数列を走査していった時に順番に見つかった最小値と最大値である，
//同じような最大利益が出るペアも発生するが，結局，最小値→最大値→最小値．．．の順番
//に発生するので今までに見つかった最大の利益を覆すようなことはない（表現が悪いかも）
int main() {

    ll N, T; cin >> N >> T;

    map<ll, ll> mp;

    ll mn = INF;
    ll mx = -1;

    for(ll i = 0; i < N; i++){
        ll a; cin >> a;
        if(mn > a){
            mn = a;
        }
        if(mx < a-mn){
            mx = a-mn;
        }
        mp[a-mn]++;
    }


    cout << mp[mx] << endl;

}