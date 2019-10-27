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

    for(ll i = 1; i <= 9; i++){
        if(N / i <= 9){
            if(N / i * i == N){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    

}