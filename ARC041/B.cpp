#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll G[1919][1919];
ll ans[1919][1919];

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {-1, 0, 1, 0};

int main() {

    ll N, M;
    cin >> N >> M;

    for(ll i = 0; i < N; i++){
        string S;
        cin >> S;
        for(ll j = 0; j < M; j++){
            G[i][j] = S[j]-'0';
        }
    }

    for(ll i = 1; i < N - 1; i++){
        for(ll j = 1; j < M - 1; j++){
            ll mn = INF;
            ll check = 0;
            for(ll k = 0; k < 4; k++){
                if(G[i+dy[k]][j+dx[k]] > 0){
                    mn = min(mn, G[i+dy[k]][j+dx[k]]);
                    check++;
                }
            }
            if(check == 4){
                ans[i][j] = mn;
                for(ll k = 0; k < 4; k++){
                    G[i+dy[k]][j+dx[k]] -= mn;
                }
            }
        }
    }

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }


}