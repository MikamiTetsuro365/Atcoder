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
    while(true){
        string tmp = to_string(N);
        if(tmp[0] == tmp[1] && tmp[1] == tmp[2]){
            cout << N << endl;
            return 0;
        }
        N++;
    }
}