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

    ll N, M; cin >> N >> M;

    //1000円
    for(ll i = 0; i <= N; i++){
        //5000円
        for(ll j = 0; j <= N - i; j++){
            //cout << i << " " << j << endl;
            ll zan = M - (i * 1000) - (j * 5000);
            ll k = zan / 10000;
            if(zan % 10000 != 0) continue;
            if(i + j + k == N){
                cout << k << " " << j << " " << i << endl;
                return 0;
            }
        }      
    }

    cout << "-1 -1 -1" << endl;

}