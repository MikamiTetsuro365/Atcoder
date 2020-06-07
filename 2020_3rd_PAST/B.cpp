#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    ll N, M, Q;
    cin >> N >> M >> Q;

    vector<ll > P(M, N);
    vector<ll > PP(N, 0);

    vector<ll > ans;

    //解いたかどうか
    vector<vector<ll > > v(N, vector<ll >(M, 0));

    for(ll i = 0; i < Q; i++){
        ll s;
        cin >> s;
        
        if(s == 1){
            ll ss;
            cin >>  ss;
            ll sum = 0;
            for(ll j = 0; j < v[ss-1].size(); j++){
                if(v[ss-1][j] == 1){
                    sum += P[j];
                }
            }
            ans.push_back(sum);
        }else{
            ll n, m;
            cin >> n >> m;
            P[m-1]--;
            v[n-1][m-1] = 1;
        }
    }

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

}