//E
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;

string ans[6][100];

ll N;

ll mp[20][20];
set<ll>S;
void show(ll f = 0){
    stringstream ss;
    rep1(y, N)rep1(x, N)ss << mp[y][x];
    ll sum = 0;
    rep1(y, N){
        if(f)rep1(x, N)cout << mp[y][x];
        if(f)cout << endl;
        sum += mp[y][y];
    }
    ans[N][sum] = ss.str();
    S.insert(sum);
    if(f)cout << sum << endl << endl;
}

void dfs(ll x = 1, ll y = 1){
    if(y > N){
        show();
        return;
    }
    ll nxt_x = x + 1;
    ll nxt_y = y;
    if(nxt_x > N){
        nxt_x = 1;
        nxt_y++;
    }
    rep1(i, N){
        mp[y][x] = i;
        ll cnt = 0;
        rep1(j, N){
            if(mp[y][j] == i)cnt++;
            if(mp[j][x] == i)cnt++;
        }
        if(cnt == 2)dfs(nxt_x, nxt_y);
    }
    mp[y][x] = 0;
}

int main(){
    ll M;
    cin >> M;
    
    //初期化
    rep1(i, 5)rep(j, i * i)ans[i][j] = "IMPOSSIBLE";
    rep1(i, 5){
        N = i;
        dfs();
    }
    // cout << "string ans[6][50];" << endl;
    // rep1(i, 5)for(ll j = i; j <= i * i; j++){
    //     cout << "ans[" << i << "][" << j << "] = \"" << ans[i][j] << "\";" << endl;
    // }

    for(ll i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        if(ans[a][b] == "IMPOSSIBLE"){
            cout << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
        }else{
            cout << "Case #" << i+1 << ": " << "POSSIBLE" << endl;
            //cout << ans[a][b] << endl;
            for(ll j = 0; j < a; j++){
                for(ll k = 0; k < a; k++){
                    cout << ( k ? " " : "" ) << ans[a][b][j * a + k];
                } 
                cout << endl;
            }
        }
    }


    return 0;
}