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
#include <map>

using namespace std;
typedef long long ll;
ll N;
ll Q;
//時間外にできたやつ
//TLEおこすのでゴミ
int main(){
    multimap<string, ll> mp;
    multimap<string, ll> mp2;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<ll > memo(N, 1);

    //左方向
    for(ll i = 0; i < N; i++){
        mp.insert(make_pair(s.substr(i,1), i));
    } 
    //右方向
    for(ll i = N - 1; i >= 0; i--){
        mp2.insert(make_pair(s.substr(i,1), i));
    }


    vector<string > T(Q);
    vector<string > D(Q);
    for(ll i = 0; i < Q; i++){
        cin >> T[i] >> D[i];
    } 
    //操作
    string t, d;
    for(ll i = 0; i < Q; i++){
        t = T[i];
        d = D[i];
        ll count = 0;
        ll count2 = 0;

        count = (int)mp.count(t);
        auto itr = mp.find(t);
        count2 = (int)mp2.count(t);
        auto itr2 = mp2.find(t);

        if(d == "L"){
            for (ll j = 0; j < count; j++) {
                ll posi = itr->second;
                if(posi == 0){
                    memo[posi] = 0;
                    itr++;
                    continue;
                }

                memo[posi-1] += memo[posi];
                memo[posi] = 0;
                itr++;
                        
            }
        }else{
        
            for (ll j = 0; j < count2; j++) {
                ll posi = itr2->second;
                //cout << itr2->first << " " << itr2->second << endl;
                if(posi == N-1){
                    memo[posi] = 0;
                    itr2++;
                    continue;
                }
                
                memo[posi+1] += memo[posi];
                memo[posi] = 0;
                itr2++;
                   
            }            
        }

    }
    //端のゴーレムは消えることに注意
    ll ans = 0;
    for(int k = 0; k < N; k++){
        ans += memo[k];
        //cout << memo[k];
    }   
    //cout << endl;

    cout << ans << endl;

    /*
    ll N = 0;
    vector<ll > B(N);
    for(ll i = 0; i < N; i++){
        cin >> B[i];
    }
    */

} 