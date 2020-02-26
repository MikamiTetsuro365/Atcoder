#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//増やすことに意味はない
//もし自分が勝利できるなら相手は増やして妨害してくるが，自分は増やし多分
//必ず取り除けるので勝利は揺るがない
int main(){

    ll N; 
    cin >> N;

    for(ll i = 0; i < N; i++){
        ll M, K; cin >> M >> K;
        
        vector<ll > digits(30, 0);
        for(ll j = 0; j < M; j++){
            ll A; cin >> A;
            for(ll k = 0; k < 30; k++){
                if((A >> k) & 1 == 1){
                    //cout << k << endl;
                    digits[k]++;
                }
            }
        }

        bool flg2 = false;
        for(ll k = 0; k < 30; k++){
            if(digits[k] % 2 != 0){
                flg2 = true;
                break;
            }
        }    

        if(flg2 == true){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }

}