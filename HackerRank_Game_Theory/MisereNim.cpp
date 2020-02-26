#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//全て1のときは当然偶数奇数で勝ち負けが決まる
//相手の取った数に合わせて残りの山の数を合わせることができれば後攻が勝てる
//NimKっぽい
int main(){

    ll N;
    cin >> N;

    for(ll i = 0; i < N; i++){
        ll M; cin >> M;

        bool flg = false;
        vector<ll > digits(15, 0);
        map<ll, ll> mp;

        for(ll j = 0; j < M; j++){  
            //check 1 bit
            ll A; cin >> A;
            mp[A]++;
            for(ll k = 0; k < 15; k++){
                if((A >> k) & 1 == 1){
                    //cout << k << endl;
                    digits[k]++;
                }
            }
        }

        //check mod choice yamanokazu + 1
        for(ll k = 0; k < 15; k++){
            //cout << digits[k] << endl;
            if(digits[k] % 2 != 0){
                flg = true;
                break;
            }
        }    

        if(mp[1] == M){
            if(mp[1] % 2 == 0){
                cout << "First" << endl;
            }else{
                cout << "Second" << endl;
            }
            continue;
        }

        if(flg == true){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }

}