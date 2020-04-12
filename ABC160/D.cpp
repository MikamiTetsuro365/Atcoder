#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;
typedef pair<pair<double, double >, double > pdd;
typedef pair<double, double > pd;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){
    
    ll N, X, Y;
    cin >> N >> X >> Y;

    vector<ll > ans(N, 0);
    for(ll i = 1; i <= N; i++){
        for(ll j = i + 1; j <= N; j++){
            //if(i == j) continue;
            ll t_ans = min(abs(i-j), min(abs(i-X)+abs(j-X), abs(i-X)+abs(j-Y)+1));
            //cout << i << " " << j << " " << t_ans << endl;
            ans[t_ans]++;
        }        
    }

    for(ll i = 1; i <= N-1; i++){
        cout << ans[i] << endl;
    }
}