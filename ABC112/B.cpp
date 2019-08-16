#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>

using namespace std;
typedef long long ll;
ll N;

int main(){

    ll N, T;
    cin >> N >> T;

    vector<pair<ll, ll > > ct;

    for(ll i = 0; i < N; i++){
        ll c, t;
        cin >> c >> t;
        ct.push_back(make_pair(t, c));
    }

    sort(ct.begin(), ct.end());

    ll ans = 1145141919;

    for(ll i = 0; i < N; i++){
        if(ct[i].first > T){
            break;
        }
        if(ans > ct[i].second){
            ans = ct[i].second;
        }
    }

    if(ans == 1145141919){
        cout << "TLE" << endl;
    }else{
        cout << ans << endl;
    }



} 