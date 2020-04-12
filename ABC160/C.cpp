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
    
    ll K, N;
    cin >> K >> N;
    
    //vec.push_back(0);
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);    
    }

    ll ans = INF;

    for(ll i = 0; i < N; i++){
        ll r, l;
        if(i == 0){
            r = vec.back()-vec[i];
            l = vec[i] + K - vec[i+1]; 
        }else if(i == N-1){
            r = K - vec[i] + vec[i-1];
            l = vec[i] - vec.front();
        }else{
            r = K - vec[i] + vec[i-1];
            l = vec[i] + K - vec[i+1];
        }
        ans = min(ans, min(r, l));
        //cout << r << " " << l << endl;
    }

    cout << ans << endl;

}