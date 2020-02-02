#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    reverse(s2.begin(), s2.end());
    
    if(s1 == s2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}