#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

vector<ll > divisor(ll n) {
    vector< ll > div;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
        div.push_back(i);
        //重複許すマジ
        if(i * i != n) div.push_back(n / i);
        }
    }
    sort(div.begin(), div.end());
    
    return (div);
}

int main(){
    ll N;
    cin >> N;

    vector<ll > div = divisor(N);

    ll ans = div.size();

    map<string, ll> mp;
    for(ll i = 0; i < div.size() / 2; i++){
        string t1 = to_string(div[i]);
        string t2 = to_string(div[div.size() - 1 - i]);
        mp[t1+t2]++;
        mp[t2+t1]++;
    }

    if(div.size() % 2 != 0){
        string t = to_string(div[div.size() / 2 + 1]);
        mp[t + t]++;
    }

    cout << mp.size() << endl;

}