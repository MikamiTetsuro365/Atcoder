#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    string s; cin >> s;
    ll t_s = stoll(s);
    vector<ll > S(s.size(), 0);

    for(ll i = 0; i < s.size(); i++){
        S[i] = t_s % 10;
        t_s /= 10;
        //cout << S[i] << endl;
    }

    ll sum = 0;
    for(ll i = 0; i < (1<<s.length() - 1); i++){
        ll t_sum = S[0];
        ll cn = 1;
        bool f = true;
        for(ll j = 0; j < s.length() - 1; j++){
            if(i >> j & 1){
                sum += t_sum;
                t_sum = 0;
                cn = 0;
            }

            ll tt = ceil(S[j + 1]) * ceil(pow(10, cn));
            t_sum += tt; 
            cn++;
           
        }
        //cout << bitset<3>(i) << endl;
        //cout << t_sum << endl;
        sum += t_sum;
    }

    cout << sum << endl;

}