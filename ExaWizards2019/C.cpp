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
//問題を読み間違って最初にできたプログラム
//ゴレーム同士が衝突すると消えて塵になる
int main(){
    multimap<string, ll> mp;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<ll > memo(N, 1);
    for(ll i = 0; i < N; i++){
        mp.insert(make_pair(s.substr(i,1), i));
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
        count = (int)mp.count(t);
        auto itr = mp.find(t);
        for (ll j = 0; j < count; j++) {
            ll posi = itr->second;
            //cout << itr->first << " " << itr->second << endl;
            if(d == "R"){
                if(posi == N-1){
                    memo[posi]=0;
                    if(s.substr(posi-1,1) == t){
                        memo[posi]=1;
                    }
                    itr++;
                    continue;
                }
                if(memo[posi+1]==1 && s.substr(posi+1,1) == t){
                    memo[posi]=0;
                    memo[posi+1]=1;
                    itr++;
                    continue;
                } 
                if(memo[posi+1]==1 && s.substr(posi+1,1) != t){
                    memo[posi]=0;
                    if(s.substr(posi-1,1) == t && posi != 0){
                        memo[posi]=1;
                    }
                    itr++;
                    continue;
                }
                if(memo[posi+1]==0){
                    memo[posi]=0;
                    memo[posi+1]=1;
                    itr++;
                    continue;
                } 
            }else{
                if(posi == 0){
                    memo[posi]=0;
                    itr++;
                    continue;
                }
                if(memo[posi+1]==1 && s.substr(posi-1,1) == t){
                    memo[posi]=0;
                    memo[posi-1]=1;
                    itr++;
                    continue;
                } 
                if(memo[posi+1]==1 && s.substr(posi-1,1) != t){
                    memo[posi]=0;
                    itr++;
                    continue;
                }
                if(memo[posi-1]==0){
                    memo[posi]=0;
                    memo[posi-1]=1;
                    itr++;
                    continue;
                }                 
            }
            
            
        }
    }
    //端のゴーレムは消えることに注意
    ll ans = 0;
    for(int k = 0; k < N; k++){
        if(memo[k] == 1){
            ans++;
        }
        cout << memo[k];
    }   
    cout << endl;

    cout << ans << endl;

    /*
    ll N = 0;
    vector<ll > B(N);
    for(ll i = 0; i < N; i++){
        cin >> B[i];
    }
    */

} 