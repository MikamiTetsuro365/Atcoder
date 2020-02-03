#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    //判定用
    ll hantei[7] = {0, 0, 0, 5, 4, 3, 1};

    vector<ll > E(10, 0);
    vector<ll > L(10, 0);
    ll B;

    for(ll i = 0; i < 6; i++){
        ll t; cin >> t;
        E[t]=1;
    }

    cin >> B;

    for(ll i = 0; i < 6; i++){
        ll t; cin >> t;
        L[t]=1;
    }

    //確認
    ll cn = 0;
    bool f = false;
    for(ll i = 0; i <= 9; i++){
         if(E[i] * L[i]) cn++;
         else if(L[i] == 1 && i == B) f = true;
    }
    
    if(cn == 5 && f == true){
        cout << 2 << endl;
    }else{
        cout << hantei[cn] << endl;
    }
}