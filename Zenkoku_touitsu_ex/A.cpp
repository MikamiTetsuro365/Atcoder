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

    string S;
    cin >> S;

    //接頭美を順番に並べたらそれはもう辞書順じゃん
    for(ll i = 0; i < S.length(); i++){
        cout << i + 1 << endl;
    }

}