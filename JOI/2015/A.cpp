#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = -1145141919;

vector<vector<ll > > G;
vector<vector<ll > > in;

ll N, M;

int main(){

    //頂点数と辺の数
    cin >> N >> M;
    //旅程
    vector<ll > ryo(M);
    for(ll i = 0; i < M; i++){
        cin >> ryo[i];
    }
    //前処理
    vector<ll > path(N + 2, 0);
    for(ll i = 0; i < M-1; i++){
        ll s = ryo[i];
        ll t = ryo[i+1];
        if(s > t){
            swap(s, t);
        }
        //cout << s << " " << t << endl;
        path[s] += 1;
        path[t] += -1;
    }   

    vector<vector<ll > > cost(N-1, vector<ll >(3, 0));
    for(ll i = 0; i < N - 1; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    //確認
    ll ans = 0;
    vector<ll > m(N + 1);
    for(ll i = 1; i < N; i++){
        m[i] = m[i-1] + path[i]; 
        //cout << m[i] << " ";
        ans += min(m[i] * cost[i-1][0], m[i] * cost[i-1][1] + cost[i-1][2]);
    }

    cout << ans << endl;

}