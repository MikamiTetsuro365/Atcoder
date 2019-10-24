#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll N, M;

int main(){

    cin >> N >> M;
    vector<vector<ll > > wether(N, vector<ll >(M, -1));
    vector<vector<ll > > ans(N, vector<ll >(M, -1));
    //入力
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
           char s; cin >> s;
           if(s == 'c'){
               wether[i][j] = 1;
               ans[i][j] = 0;
           } 
        }        
    }
    //処理
    for(ll i = 0; i < N; i++){
        ll cn = -1;
        for(ll j = 0; j < M; j++){
            if(ans[i][j] == 0)cn=0;
            ans[i][j] = cn;
            if(cn != -1) cn++;
        }        
    }
    //出力
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            cout << ( j ? " " : "" ) << ans[i][j];
        }
        cout << endl;
    }


}