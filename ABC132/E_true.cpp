#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;
typedef pair<pair<double, double >, double > pdd;
typedef pair<double, double > pd;  
vector<ll > vec;
vector<vector<ll > > vec2;
vector<vector<ll > > G;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll N, M, S, T;
 
int main(){
    
    cin >> N >> M;
    //初期化
    G.assign(N, vector<ll >());
    vector<vector<ll > > conf(N, vector<ll >(3, INF));
 
    //グラフ入力
    for(ll i = 0; i < M; i++){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        //有向グラフです
        G[u].push_back(v);
    }
    
    //スタートとゴールの入力
    cin >> S >> T;
    S--; T--;
 
    //BFS
    conf[S][0] = 0;
    queue<pi > que;
    que.push(make_pair(S, 0));
 
    while(!que.empty()){
        //現在地
        ll from = que.front().first;
        //歩数
        ll step = que.front().second;
        que.pop();

        //けん, けん, ぱの「ぱ」のタイミングでゴールにたどりつきたい
        if(from == T && step % 3 == 0){
            cout << step / 3 << endl;
            return 0;
        }
 
        for(ll i = 0; i < G[from].size(); i++){
            //すでに探査済み
            //次の地点に向かうとけん, けん, ぱのどのフェーズになるか
            ll to = G[from][i];
            ll phase = (step + 1) % 3;
            //
            if(conf[to][phase] != INF) continue;
 
            conf[to][phase] = conf[from][step % 3] + 1;
            que.push(make_pair(to, conf[to][phase]));
        }
    }

    cout << -1 << endl;
 
}
