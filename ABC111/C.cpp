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
    //map<ll, ll> k_mp;
    //map<ll, ll> g_mp;
    vector<ll > k_v;
    vector<ll > k_v_sum;
    vector<ll > g_v;
    vector<ll > g_v_sum;

    for(ll i = 0; i < N; i++){
        ll in;
        ll st;
        cin >> in;
        if(i % 2 == 0){
            st = search_v(g_v, in);
            //cout << st << endl;
            if(st == -1){
                g_v.push_back(in);
                g_v_sum.push_back(1);
            }else{
                g_v_sum[st]++;
            }

        }else{
            st = search_v(k_v, in);
            //cout << st << endl;
            if(st == -1){
                k_v.push_back(in);
                k_v_sum.push_back(1);
            }else{
                k_v_sum[st]++;
            }
        }
    }

    sort(g_v_sum.begin(), g_v_sum.end());
    sort(k_v_sum.begin(), k_v_sum.end());

    //答えだす
    ll ans = 0;

    for(ll i = 0; i < g_v_sum.size()-1; i++){
        if(g_v_sum.size() == 1){
            break;
        }
        ans += g_v_sum[i];
    }
    for(ll i = 0; i < k_v_sum.size()-1; i++){
        if(k_v_sum.size() == 1){
            break;
        }
        ans += k_v_sum[i];
    }

    cout << ans << endl;
}