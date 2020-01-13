#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

using namespace std;

int main(){

    ll N, M;
    cin >> N >> M;

    ll wgb = 0;

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            char c; cin >> c;
            if(c == 'W' || c == 'G' || c == 'B'){
                wgb++;
            }
        }
    }

    if(N * M == wgb){
        cout << "#Black&White" << endl;
    }else{
        cout << "#Color" << endl;
    }

}