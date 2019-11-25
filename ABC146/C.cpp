#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

ll digit(ll N){
    ll cn = 0;
    while(N != 0){
        N /= 10;
        cn++;
    }
    return cn;
}

bool check(ll A, ll B, ll X, ll N){

    if(A * N + B * digit(N) <= X){
        return true;
    }else{
        return false;
    }
}

int main(){

    ll A, B, X; 
    cin >> A >> B >> X;

    //cout << digit(100) << endl;

    ll left = 0; ll right = 1000000001;
 
    //最小値を求める
    //rightを寄せていく
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        if(check(A, B, X, mid) == true){
            left = mid;
        }else{
            right = mid;
        }
    }
    //最小値
    cout << left << endl;
    //cout << A * left + B * digit(left) << endl;

}