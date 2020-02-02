#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;


int main() {

    ll G, C, P;
    cin >> G >> C >> P;

    string S;
    cin >> S;

    map<char, ll> mp;

    for(ll i = 0; i < S.length(); i++){
        mp[S[i]]++;
    }

    ll ans = 0;
    ll tmp = 0;
    //勝てますか?
    //グー
    ans += 3 * min(mp['G'], P);
    tmp = P;
    P -= min(mp['G'], P);
    mp['G'] -= min(mp['G'], tmp);
    //チョキ
    ans += 3 * min(mp['C'], G);
    tmp = G;
    G -= min(mp['C'], G);
    mp['C'] -= min(mp['C'], tmp);
    //パー
    ans += 3 * min(mp['P'], C);
    tmp = C;
    C -= min(mp['P'], C);
    mp['P'] -= min(mp['P'], tmp);

    //アイコにできますか
    //グー
    ans += min(mp['G'], G);
    //チョキ
    ans += min(mp['C'], C);
    //パー
    ans += min(mp['P'], P);

    cout << ans << endl;

}