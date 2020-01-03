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
    ll H, W;
    cin >> H >> W;
    vector<ll > cnH(W, 0);
    vector<string> input;

    for(ll i = 0; i < H; i++){
        string s = "";
        ll cnW = 0;
        for(ll j = 0; j < W; j++){
            char t; cin >> t;
            if(t == '.'){
                cnW++;
                cnH[j]++; 
            } 
            s+=t;
        }
        if(cnW != W){
            input.push_back(s);
        }
    }

    for(ll i = 0; i < input.size(); i++){
        for(ll j = 0; j < W; j++){
            if(cnH[j] != H){
                cout << input[i][j];
            } 
        }
        cout << endl;
    }

}