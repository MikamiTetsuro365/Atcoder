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

    string a, b;
    cin >> a >> b;

    string aa;
    string bb;
    for(ll i = 0; i < stoi(b); i++){
        aa += a;
    }

    for(ll i = 0; i < stoi(a); i++){
        bb += b;
    }

    if(aa < bb){
        cout << aa << endl;
    }else{
        cout << bb << endl;
    }

}