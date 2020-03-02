#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){
    

    ll N, M;
    cin >> N >> M;
    vector<ll > v(N, INF);

    for(ll i = 0; i < M; i++){
        ll s, c; 
        cin >> s >> c;
        v[s-1] = min(v[s-1], c);
    }

    // for(ll i = 0; i < N; i++){
    //     cout << v[i];
    // }
    // cout << endl;

    for(ll i = 0; i < N; i++){
        if(i == 0){
            if(N >= 2 && (v[i] == 0 || v[i] == INF)){
                cout << -1 << endl;
                return 0;
            }else if(N == 1 && v[i] == INF){
                cout << 0;
            }else{
                cout << v[i];
            }
        }else{
            if(v[i] == INF){
                cout << 0;
            }else{
                cout << v[i];
            }            
        }
    
    }
    cout << endl;

}