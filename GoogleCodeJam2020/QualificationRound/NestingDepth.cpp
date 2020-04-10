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

    ll N;
    cin >> N;
    
    for(ll i = 0; i < N; i++){
        ll M; cin >> M;
        ll sumk = 0;
        
        vector<vector<ll > > G(M, vector<ll >(M, 0));
        for(ll j = 0; j < M; j++){
            for(ll k = 0; k < M; k++){
                cin >> G[j][k];
                if(j == k) sumk += G[j][k];
            }
        }
        
        //check row
        ll cn_r = 0;
        for(ll j = 0; j < M; j++){
            map<ll, ll> mp;
            for(ll k = 0; k < M; k++){
                mp[G[j][k]]++;
            }
            if(mp.size() < M) cn_r++;
        }
        
        
        //check col
        ll cn_c = 0;
        for(ll j = 0; j < M; j++){
            map<ll, ll> mp;
            for(ll k = 0; k < M; k++){
                mp[G[k][j]]++;
            }
            if(mp.size() < M) cn_c++;
        }
        
        cout <<"Case #" << i+1 << ": " << sumk << " " << cn_r << " " << cn_c << endl;

    }
}