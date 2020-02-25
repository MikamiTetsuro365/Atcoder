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

    string T;
    cin >> T;

    T = '0' + T + '0';

    string T2 = T;

    ll len = 0;
    ll mx = 0;
    //前処理
    for(ll i = 0; i < T.length(); i++){
        if(T[i] == '?'){
            if(i % 2 == 0){
                T[i] = '2';
            }else{
                T[i] = '5';
            }
        }
    }
    for(ll i = 0; i < T2.length(); i++){
        if(T2[i] == '?'){
            if(i % 2 == 1){
                T2[i] = '2';
            }else{
                T2[i] = '5';
            }
        }
    }
    // cout << T << endl;
    // cout << T2 << endl;
    //数え上げ
    bool f = false;
    for(ll i = 1; i < T.length(); i++){
        if(T[i] == '2' && f == false){
            f = true;
        }else if(T[i] == '5' && f == true){
            len += 2;
            f = false;
            //cout << i << " " << len << endl;
        }else{
            mx = max(mx, len);
            len = 0;
            if(T[i] == '2') f = true;
            else f = false;
        }
    }

    len = 0;
    for(ll i = 1; i < T2.length(); i++){
        if(T2[i] == '2' && f == false){
            f = true;
        }else if(T2[i] == '5' && f == true){
            len += 2;
            f = false;
        }else{
            mx = max(mx, len);
            len = 0;
            if(T2[i] == '2') f = true;
            else f = false;
        }
    }


    cout << mx << endl;

    // for(ll i = 0; i < tmp.size(); i++){
    //     cout << tmp[i] << " " ;
    // }
    // cout << endl;
    

}