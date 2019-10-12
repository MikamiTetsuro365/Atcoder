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

const ll dx[5] = {0, 0, 0, -1};
const ll dy[5] = {0, -1, 1, 0};

ll solv(vector<vector<ll > > in){

    ll m = 1000;
    //一行目の踏み方 bit全探査
    //vector<vector<ll > > a(N, vector<ll >(M, 0));
    vector<vector<ll > > ans(N, vector<ll >(M, 0));
    for(ll s = 0; s < (1<<M); s++){
        vector<vector<ll > > flip(N, vector<ll >(M, 0));
        for(ll j = 0; j < M; j++){
            if( s >> j & 1) flip[0][M-j-1] = 1; 
            //cout << flip[0][M-j-1];
        }

        ll flip_num = 0;

        for(ll row = 0; row < N - 1; row++){
            for(ll col = 0; col < M; col++){
                ll c = in[row][col];
                for(ll posi = 0; posi < 4; posi++){
                    ll x = row + dx[posi];
                    ll y = col + dy[posi];

                    //範囲内を参照していれば
                    if(0 <= x && x < M && 0 <= y && y < N){
                        //XOR
                        c ^= flip[x][y]; 
                    }
                }
                flip[row + 1][col] = c;
            }            
        }

        bool f = true;
        for(ll col = 0; col < M; col++){
            ll c = in[M-1][col];
            for(ll posi = 0; posi < 4; posi++){
                ll x = M-1 + dx[posi];
                ll y = col + dy[posi];

                if(0 <= x && x < M && 0 <= y && y < N){
                    //XOR
                    c ^= flip[x][y]; 
                }               
            }
            if(c != 0){
                f = false;
                break;
            }
        }

        if(f == true){
            for(ll row = 0; row < N; row++){
                for(ll col = 0; col < M; col++){
                    flip_num += flip[row][col];
                }        
            }
            if(flip_num < m){
                m = flip_num;
                for(ll row = 0; row < N; row++){
                    for(ll col = 0; col < M; col++){
                        ans[row][col] = flip[row][col];
                    }        
                }
            }
        }
    }

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    } 


}

int main(){

    ll ans = -1;

    cin >> N >> M;

    
    

    in.assign(N, vector<ll >());
    for(ll row = 0; row < N; row++){
        for(ll col = 0; col < M; col++){
            ll t = 0; cin >> t;
            in[row].push_back(t);
        }        
    }

    solv(in);



    

}