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

    ll R; cin >> R;

    if(R < 1200){
        cout << "ABC" << endl;
    }else if(R < 2800){
        cout << "ARC" << endl;
    }else{
        cout << "AGC" << endl;
    }
}