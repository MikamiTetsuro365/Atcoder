#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//距離iにある箱からコインを１つずつ距離i未満の箱に入れる
//距離0の箱に入ったコインは動かせない．全てのコインが動かせなければその手番の人は負け
//Nimへの帰着を考える
//距離iにある1枚のコイン＝i個コインが山として詰まれている
//距離i未満に動かす＝コインを1つ以上山から取り除く
//つまりコイン分だけ高さiの山がある！= 1山Nim
int main(){

    ll N; 
    cin >> N;

    for(ll i = 0; i < N; i++){
        ll M; cin >> M;

        vector<ll > digits(30, 0);
        vector<ll > check(M, 0);

        for(ll j = 0; j < M; j++){  
            //check 1 bit
            ll A; cin >> A;
            check[j] = A;
            
            if(j == 0) continue;

            for(ll k = 0; k < 30; k++){
                if((j >> k) & 1 == 1){
                    //cout << k << endl;
                    digits[k] += A;
                }
            }
        }

        // //all zero check
        // bool flg1 = false;
        // for(ll j = 0; j < M; j++){
        //     if(j == 0) continue;
        //     if(check[j] > 0) flg1 = true;
        // }

        // if(flg1 == false){
        //     cout << "Second" << endl;
        //     continue;
        // }

        //check mod choice yamanokazu + 1
        bool flg2 = false;
        for(ll k = 0; k < 30; k++){
            //cout << digits[k];
            if(digits[k] % 2 != 0){
                flg2 = true;
                break;
            }
        }    
        //cout << endl;

        if(flg2 == true){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }
}