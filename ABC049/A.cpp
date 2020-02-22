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

    char c;
    cin >> c;

    map<char, ll> mp;
    mp['a']++;
    mp['e']++;
    mp['i']++;
    mp['o']++;
    mp['u']++;

    if(mp[c] != 1){
        cout << "consonant" << endl;
    }else{
        cout << "vowel" << endl;
    }

}