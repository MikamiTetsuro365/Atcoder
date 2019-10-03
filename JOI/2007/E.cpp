#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll A, B, C;
    cin >> A >> B >> C;
    ll N;
    cin >> N;

    vector<ll > kiki(A + B + C, 2); 
    
    vector<vector<ll > > kosyo;

    for(ll i = 0; i < N; i++){
        ll a, b, c, j;
        cin >> a >> b >> c >> j;
        if(j == 1){
            kiki[a-1] = 1;
            kiki[b-1] = 1;
            kiki[c-1] = 1;
        }else{
            vector<ll > t_kosyo;
            t_kosyo.push_back(a-1);
            t_kosyo.push_back(b-1);
            t_kosyo.push_back(c-1);
            kosyo.push_back(t_kosyo);     
        }
    }

    vector<vector<ll > > kosyo2;
    vector<vector<ll > > kosyo3;

    for(ll i = 0; i < kosyo.size(); i++){
        vector<ll > t_kosyo;
        if(kiki[kosyo[i][0]] != 1){
            t_kosyo.push_back(kosyo[i][0]);
        }
        if(kiki[kosyo[i][1]] != 1){
            t_kosyo.push_back(kosyo[i][1]);
        }
        if(kiki[kosyo[i][2]] != 1){
            t_kosyo.push_back(kosyo[i][2]);
        }

        if(t_kosyo.size() == 1){
            kiki[t_kosyo[0]] = 0;
        }
    }


    //出力
    for(ll i = 0; i < kiki.size(); i++){
        cout << kiki[i] << endl;
    }


}