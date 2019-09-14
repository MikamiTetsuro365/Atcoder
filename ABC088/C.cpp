#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <map>


using namespace std;
typedef long long ll;
ll N;
//b[0]を固定して全探査
int main(){

    ll n_rows = 3;
    ll n_cols = 3;
    ll value = 0;
    vector<vector<ll > > vec(n_rows, vector<ll >(n_cols, value));

    for(ll i = 0; i < n_rows; i++){
        for(ll j = 0; j < n_cols; j++){
            cin >> vec[i][j];
        }        
    }

    ll ans = 0;
    bool flg = true;
    for(ll i = 0; i <= vec[0][0]; i++){
        flg = true;
        //b[0]を固定してaを確定
        vector<ll > a(3, 0);
        for(ll j = 0; j < 3; j++){
            a[j] = vec[j][0] - i;
            //cout << a[j] << endl;
            if(a[j]  < 0){
                flg = false;
                break;
            }
        }
        //矛盾が出たら深追いしない
        if(flg == false) continue;
        //aでbを確定
        vector<ll > b(3, 0);
        for(ll j = 0; j < 3; j++){
            b[j] = vec[0][j] - a[0];
            //cout << b[j] << endl;
            if(b[j] < 0){
                flg = false;
                break;
            }
        }

        //矛盾が出たら深追いしない
        if(flg == false) continue;
        //その他を求める
        for(ll j = 1; j < 3; j++){
            for(ll k = 1; k < 3; k++){
                if(a[j] + b[k] != vec[j][k] ){
                    flg = false;
                    break;
                }
            }
        }
        //矛盾が出たら深追いしない
        if(flg == false) continue;

        ans++;
    }
    //１つ以上成り立つ答えがあればYES
    if(ans > 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}