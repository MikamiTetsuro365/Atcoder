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

    ll A, B, C;
    cin >> A >> B >> C;

    map<ll, ll> mp;
    mp[A]++;
    mp[B]++;
    mp[C]++;

    if(mp[1] > mp[2]){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
    }

}