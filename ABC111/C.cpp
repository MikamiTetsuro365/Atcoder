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
#include <map> 

using namespace std;
typedef long long ll;
ll N;

ll search_v(vector<ll > v, ll in){

    for(ll i = 0; i < v.size(); i++){
        if(v[i] == in){
            return i;
        }
    }

    return -1;
}

int main(){
    //奇数と偶数番号で別に考える
    cin >> N;
    map<ll, ll> k_mp;
    map<ll, ll> g_mp;

    ll g_num = 0;
    ll g_max = 0;

    ll k_num = 0;
    ll k_max = 0;

    for(ll i = 0; i < N; i++){
        ll in;
        cin >> in;
        if(i % 2 == 0){
            g_mp[in]++;

            if(g_max < g_mp[in]){
                g_num = in;
                g_max = g_mp[in];
            }

        }else{
            k_mp[in]++;
            if(k_max < k_mp[in]){
                k_num = in;
                k_max = k_mp[in];
            }
        }
    }

    //ll ans = N / 2;

    cout << ans << endl;
}