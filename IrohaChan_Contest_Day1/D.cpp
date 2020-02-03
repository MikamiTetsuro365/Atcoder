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

    ll N, X, Y;
    cin >> N >> X >> Y;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }
    sort(vec.rbegin(), vec.rend());

    for(ll i = 0; i < N; i++){
        if(i % 2 == 0) X += vec[i];
        else Y += vec[i];
    }

    if(X > Y){
        cout << "Takahashi" << endl;
    }else if(X < Y){
        cout << "Aoki" << endl;
    }else{
        cout << "Draw" << endl;
    }


}