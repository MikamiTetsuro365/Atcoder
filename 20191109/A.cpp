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

    if(N % 2 == 0){
        cout << N / 2 - 1 << endl;
    }else{
        cout << N / 2<< endl;
    }
}