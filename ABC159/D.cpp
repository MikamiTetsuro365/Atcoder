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

    //map<ll, ll> mp; 
    vector<ll > K(200019, 0);
    vector<ll > C(200019, 0);
    vector<ll > C_1(200019, 0);

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
        K[t]++;
    }

    ll sum = 0;
    for(ll i = 1; i <= N; i++){
        C[i] = K[i] * (K[i]-1) / 2;
        C_1[i] = (K[i]-1) * (K[i]-2) / 2;
        sum += C[i];
    }    

    for(ll i = 0; i < vec.size(); i++){
        //cout << ";" << vec[i-1] << endl;
        cout << sum - C[vec[i]] + C_1[vec[i]] << endl;;
    }    
    //set<ll > 
    
}