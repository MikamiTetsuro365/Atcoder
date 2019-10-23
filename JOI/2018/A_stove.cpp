#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;


int main(){

    ll N, M; cin >> N >> M;
    map<ll, ll > mp;
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        if(mp[t] != 0) continue;

        mp[t]++;
        vec.push_back(t);

    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << endl;
    //圧縮
    vector<ll > t_vec;
    ll cn = 0;
    for(ll i = 0; i < vec.size();){
        if(cn > 10) break;

        ll j = i;

        while(j < vec.size() && vec[j] == vec[j+1]-1){
            cout << j << endl;
            j++;
        }
        //cout << j-i << " " << vec[j]-vec[j-1] << endl;
        cout << j << endl;
        t_vec.push_back(j-i);
        t_vec.push_back(vec[j]-vec[j-1]);
        i=j + 1;
        cn++;
    }





}