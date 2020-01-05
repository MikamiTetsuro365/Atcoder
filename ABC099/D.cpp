#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//三色の選び方：最大30*29*28なので前探査すると間に合う？
//Dに対してすべてを確認していく方法を取ると当然間に合わないので
//最初Cで塗られているマスが何個あるかを列挙しておいて，そこから別の色に変化させたときのコストを計算する

int main() {

    ll N, C;
    cin >> N >> C;

    ll D[35][35];
    ll grid[505][505];
    //初期化
    ll mod012[3][35];
    //mod0 1 2のときどの色がどれだけ分布しているか
    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < 30; j++){
            mod012[i][j] = 0;
        }
    }

    for(ll i = 1; i <= C; i++){
        for(ll j = 1; j <= C; j ++){
            cin >> D[i][j];
        }
    }

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j ++){
            cin >> grid[i][j];
            mod012[(i+j)%3][grid[i][j]]++;
        }
    }

    ll ans = INF;
    for(ll i = 1; i <= C; i++){
        for(ll j = 1; j <= C; j++){
            if(i == j) continue;
            for(ll k = 1; k <= C; k++){
                ll t_ans = 0;
                if(j == k || i == k) continue;
                //cout << i << " " << j << " " << k << endl;

                //modで0のところをすべて色iに
                for(ll h = 1; h <= C; h++){
                    t_ans += mod012[0][h] * D[h][i];
                }

                //modで1のところをすべて色jに
                for(ll h = 1; h <= C; h++){
                    t_ans += mod012[1][h] * D[h][j];
                }

                //modで2のところをすべて色k
                for(ll h = 1; h <= C; h++){
                    t_ans += mod012[2][h] * D[h][k];
                }
                //cout << t_ans << endl;
                ans = min(t_ans, ans);
            }
        }        
    }

    cout << ans << endl;


}