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

    string S, T;
    cin >> S >> T;

    ll A, B;
    cin >> A >> B;

    string U;
    cin >> U;

    map<string, ll> mp;

    mp[S] = A;
    mp[T] = B;

    mp[U]--;

    cout << mp[S] << " " <<  mp[T] << endl;

    // if(ans){
    //     cout << "Yes" << endl;
    // }else{
    //     cout << "No" << endl;
    // }

}

