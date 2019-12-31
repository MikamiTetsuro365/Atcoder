#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > ruiseki;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll N, M;

bool check(ll mid){
    cout << "mid " << mid << endl; 
    ll shakeNum = 0;
    
    for(ll i = N - 1; i >= 0; i--){
        bool f = false;
        ll tmp = mid / vec[i];
        for(ll j = N - 1; j >= 0; j--){
            if(ruiseki[j] <= tmp){
                shakeNum += j + 1;
                mid -= vec[i] * ruiseki[j];
                f = true;
                break;
            }
        }
        if(f = false){
            shakeNum += N;
            mid -= vec[i] * ruiseki[N-1];
        }
        if(mid <= 0) break;
        //
        //ll index = lower_bound(ruiseki.begin(), ruiseki.end(), tmp) - ruiseki.begin();
        //cout << tmp << " " << ruiseki[index] << " " << mid << endl;
        //shakeNum += index;
        //mid -= vec[i] * ruiseki[index];
        //if(mid <= 0){
        //    break;
        //}
    }

    if(shakeNum <= M){
        return true;
    }else{
        return false;
    }
}

int main() {

    cin >> N >> M;
    //配列で言うP-1までは採用対象
    vec.assign(N, 0);
    ruiseki.assign(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    ruiseki[0] = vec[0];
    for(ll i = 1; i < N; i++){
        ruiseki[i] = ruiseki[i-1] + vec[i];
        cout << ruiseki[i] << endl;
    }

    //条件を満たすような最大値
    ll left = 0; ll right = INF;
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        if(check(mid)){
            left = mid;
        }else{
            right = mid;
        }
        
    }
    cout << left << endl;

}