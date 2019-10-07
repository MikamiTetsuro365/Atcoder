#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;

    //priority_queue<ll, vector<ll >, greater<ll > > taro;
    //priority_queue<ll, vector<ll >, greater<ll > > hanako;

    vector<bool > taro(2*N + 1, false);
    vector<bool > hanako(2*N + 1, false);
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        taro[t] = true;
    }
    for(ll i = 0; i < taro.size(); i++){
        if(taro[i] == false) hanako[i] = true;
    }

    //cout << taro.size() << " " << hanako.size() << endl;
    ll max = 0;
    ll taro_num = N;
    ll hanako_num = N;
    while(taro_num != 0 && hanako_num != 0){
        ll f = false;
        //太郎ターン
        for(ll i = max; i < taro.size(); i++){
            if(taro[i] == true && i > max){
                max = i;
                taro[i] = false;
                //cout << i << " " << taro[i] << endl;
                taro_num--;
                f = true;
                break;
            }
        }

        //何もできなかったらMaxを戻して花子ターンへ
        if(f == false){
            max = 0;
        }else{
            f = false;
        }

        //花子ターン
        for(ll i = max; i < hanako.size(); i++){
            if(hanako[i] == true && i > max){
                max = i;
                hanako[i] = false;
                hanako_num--;
                f = true;
                break;
            }
        }
        //何もできなかったらMaxを戻して太郎ターンへ
        if(f == false){
            max = 0;
        }else{
            f = false;
        }

    }

    cout << hanako_num << endl;

    cout << taro_num  << endl;

}
