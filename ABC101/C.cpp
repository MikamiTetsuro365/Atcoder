#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi; 
typedef pair<pair<ll ,ll >,ll > pii; 

int main(){
    
    ll N, K;
    cin >> N >> K;

    vector<ll > vec(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    ll ans = 0;
    for(ll i = 0; i < N - 1;){
        if(vec[i] != vec[i+1]){
            ans++;
            i += K - 1;
        }else{
            i++;
        }
    }

    cout << ans << endl;

}