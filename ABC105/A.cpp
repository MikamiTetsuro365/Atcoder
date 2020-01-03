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
    ll N, K;
    cin >> N >> K;
    
    if(N % K == 0){
        cout << 0 << endl;
    }else{
        cout << 1 << endl; 
    }
}