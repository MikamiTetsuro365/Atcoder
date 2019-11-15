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

    ll N; cin >> N;
    
    vector<ll > A(N+1, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    //番兵
    A[N] = -1;

    ll r = 0;
    ll l = 0;
    ll ans = 0;
    while(r < N){
        //cout << r << endl;
        while(r < N && A[r] < A[r+1]){
            r++;
        }
        //cout << r << endl;
        ll cn = r - l + 1;
        ans = ans + (cn * (cn + 1)) / 2;
        
        r++;
        l = r;
    }

    cout << ans << endl;

}