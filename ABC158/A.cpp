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

    string S;
    cin >> S;

    map<char, ll> mp;
    mp[S[0]]++;
    mp[S[1]]++;
    mp[S[2]]++;

    if(mp.size() == 1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

}