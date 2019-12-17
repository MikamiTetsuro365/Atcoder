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

    string s; cin >> s;
    
    ll g = 0;
    ll p = 0;

    ll ans = 0;
    for(ll i = 0; i < s.length(); i++){
        if(s[i] == 'g'){
            //パーを出したいが
            if(p + 1 <= g){
                p++;
                ans++;
            }else{
                g++;
            }
        }else{
            //パーを出してアイコにしたいが
            if(p + 1 <= g){
                p++;
            }else{
                g++;
                ans--;
            }
        }
    }

    cout << ans << endl;

}