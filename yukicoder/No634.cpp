#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
//https://yukicoder.me/problems/no/634
//三角数なのでNはたかだか３つの三角数の組み合わせで表せるらしい（はぇー）
int main(){

    ll N;
    cin >> N;

    //vector<ll > ans(n, 0);
    ll t_value = 0;
    ll num = 1;

    vector<ll > value;
    //三角数列挙
    while(t_value <= N){
        t_value = num * (num + 1) / 2;
        num++;
        if(t_value <= N) {
            //cout << num << " " << t_value << endl;
            value.push_back(t_value);
        }
    }

    reverse(value.begin(), value.end());

    if(value[0] == N){
        cout << 1 << endl;
        return 0;
    }

    for(ll i = 0; i < value.size(); i++){
        for(ll j = i; j < value.size(); j++){
            if(value[i] + value[j] == N){
                cout << 2 << endl;
                return 0;
            }
        }
    }

    cout << 3 << endl;
    return 0;

}