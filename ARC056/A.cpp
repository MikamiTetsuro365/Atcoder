#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll A, B, K, L;
bool check(ll mid){
    ll sum = 0;
    if(B < A * L){
        sum += mid / B * L; 
        mid -= sum / L * B;
    }
    sum += mid / A;
    //cout << mid / A << endl;
    if(sum >= K){
        return true;
    }
    return false;

}

int main() {
    cin >> A >> B >> K >> L;

    ll left = -1; ll right = A * (1000000000 + 19);
 
    //最小値を求める
    //rightを寄せていく
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        //cout << mid << endl;
        if(check(mid)){
            right = mid;
        }else{
            left = mid;
        }
    }
    //最小値
    cout << right << endl;

}