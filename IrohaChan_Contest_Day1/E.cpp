#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
vector<vector<pi > > G;
vector<bool > seen;
ll MOD = 1000000007;

int main(){

    ll N, A, B;
    cin >> N >> A >> B;

    vector<ll > day(B, 0);
    //番兵
    day.push_back(0);
    day.push_back(N+1);

    //愛が足りない
    if(A == 1){
        cout << 0 << endl;
        return 0;
    }

    for(ll i = 0; i < B; i++){
        ll t; cin >> t;
        if(t == 1) continue;
        day[i] = t;
    }
    sort(day.begin(), day.end());

    ll cn = 0;
    for(ll i = 1; i < day.size(); i++){
        //cout << day[i]-day[i-1] << endl;
        //隙間を計算
        cn += (day[i]-day[i-1]-1)/A;
    }
    
    cout << N - B - cn << endl;

}