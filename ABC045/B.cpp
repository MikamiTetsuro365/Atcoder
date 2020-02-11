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

    string a, b, c;
    cin >> a >> b >> c;

    map<char, queue<char > >mp;

    //準備
    for(ll i = 0; i < a.length(); i++){
        mp['a'].push(a[i]);
    }
    for(ll i = 0; i < b.length(); i++){
        mp['b'].push(b[i]);
    }
    for(ll i = 0; i < c.length(); i++){
        mp['c'].push(c[i]);
    }

    //シミュレーション
    char teban = 'a';
    while(!mp[teban].empty()){
        char tmp = mp[teban].front();
        mp[teban].pop();
        teban = tmp;
        
    }

    teban -= 32;
    cout << (char)teban << endl;

}