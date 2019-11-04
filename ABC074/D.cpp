#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 114514191919;
ll N, M; 


int main(){

    //頂点数と辺の数
    cin >> N;

    vector<vector<ll > > G(N, vector<ll >(N, 0));
    vector<vector<ll > > t_G(N, vector<ll >(N, 0));
    //初期化
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            ll t = 0; cin >> t;
            G[i][j] = t;
            ans += t;
        }       
    }

    //ワーシャルフロイド
    for(ll reley = 0; reley < N; reley++){
        for(ll from = 0; from < N; from++){
            for(ll to = 0; to < N; to++){
                if(reley == from || reley == to || from == to){
                    continue;
                }
                //INF(削除)した不要な経路はもう辿らない
                if( G[from][reley] == INF || G[reley][to] == INF || G[from][to] == INF){
                    continue;
                }
                //直接fromからtoへ行くより他を経由していく経路のほうが長いと辻褄が合わないので終了
                if(G[from][to] > G[from][reley] + G[reley][to]){
                    cout << -1 << endl;
                    return 0;
                }
                //直接fromからtoへ行くより他を経由していく経路の距離が同じなら直接行く距離を消す
                if(G[from][to] == G[from][reley] + G[reley][to])
                {   
                    //cout << G[from][to] << endl;
                    ans -= G[from][to];
                    G[from][to] = INF;
                }
            }
        }
    }

    cout << ans / 2 << endl;

}