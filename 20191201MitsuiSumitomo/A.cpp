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

    int lmdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    ll M1, D1, M2, D2;
    cin >> M1 >> D1 >> M2 >> D2;
    
    if(lmdays[M1-1] == D1){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }

}