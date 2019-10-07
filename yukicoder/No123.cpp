#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){
    ll N, M;
    cin >> N >> M;

    vector<ll > card;

    for(ll i = 0; i < N; i++){
        card.push_back(i + 1);
    } 
    
    for(ll i = 0; i < M; i++){
        ll t = 0; cin >> t; t--;
        ll tmp = card[t];
        //cout << tmp << endl;
        for(ll j = t - 1; j >= 0 ; j--){
            //cout << i << " " <<  j << endl;
            card[j + 1] = card[j]; 
        }
        card[0] = tmp;
    }

    cout << card[0] << endl;

}