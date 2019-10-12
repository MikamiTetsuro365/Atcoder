#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
vector<vector<ll > > in;
ll MOD = 1000000007;
ll N, M;

const ll dx[5] = {-1, 0, 0, 0, 1};
const ll dy[5] = {0, -1, 0, 1, 0};

ll get(vector<vector<ll > > flip, ll x, ll y){
    ll c = in[x][y];
    for(ll d = 0; d < 5; d++){
        ll x2 = x + dx[d];
        ll y2 = y + dy[d];
        if(0 <= x2 && x2 < M && 0 <= y2 && y2 < N){
            //反転できる場所
            c += flip[x2][y2];
        }
    }
    return c % 2;
}

//塗りつぶし判定
ll calc(vector<vector<ll > > flip){
    for(ll row = 1; row < N; row++){
        for(ll col = 0; col < M; col++){
            if(get(flip, row - 1, col) != 0){
                flip[row][col] = 1;
            }
        }        
    }

    for(ll col = 0; col < M; col++){
        if(get(flip, N - 1, col) != 0){
            //解なし
            return -1;
        }     
    }

    //反転回数をカウント
    ll ans = 0;
    for(ll row = 1; row < N; row++){
        for(ll col = 0; col < M; col++){
            ans += flip[row][col];
        }        
    }
    return ans;
}

int main(){

    ll ans = -1;

    cin >> N >> M;

    vector<vector<ll > > opt(N, vector<ll >(M, 0));

    in.assign(N, vector<ll >());
    for(ll row = 0; row < N; row++){
        for(ll col = 0; col < M; col++){
            ll t = 0; cin >> t;
            in[row].push_back(t);
        }        
    }

    //1行目を試す 1行目のひっくり返し方から決まる解しかない
    for(ll col = 0; col < (1<<M); col++){
        vector<vector<ll > > flip(N, vector<ll >(M, 0));
        for(ll j = 0; j < M; j++){
            if( col >> j & 1) flip[0][M-j-1] = 1; 
            //cout << flip[0][M-j-1];
        }
        //cout << endl;
        ll num = calc(flip);
        if(num >= 0 && (ans < 0 || ans > num)){
            ans = num;
            //コピー
            for(ll i = 0; i < N; i++){
                for(ll j = 0; j < M; j++){
                    opt[i][j] = flip[i][j];
                }        
            }         
        }
        //cout << ans << endl;
    }


    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            cout << opt[i][j] << " ";
        }
        cout << endl;
    } 
    

}