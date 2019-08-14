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
typedef long long int ll;

int main(){
    
    ll N, K;
    cin >> N >> K;

    vector<ll > A(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    //Aの各桁を反転させたほうがお得か？そうではないかを上の桁から考える
    //Aの各桁をすべて見てみて1が多ければ反転させない，少なければ反転させる

    //すべてのAに対してd桁目で立っているbitの個数を数える
    //上から
    ll max_digit = 50;
    vector<vector<ll > > dp(max_digit * 2, vector< ll >(2, -1));
    //初期化
    dp[0][0] = 0;

    vector<ll > keta(max_digit, 0);
    for(ll i = 0; i < max_digit; i++){
        ll bit_mask = 1ll << (max_digit - i - 1);
        //cout << bit_mask << endl;
        for(ll j = 0; j < N; j++){
            if(A[j] & bit_mask){
                keta[i]++;
            }
        }
    }

    //桁DP
    //Kの桁を受けから見ていき初めて１が立っているところを見つけたらスタート
    for(ll i = 0; i < max_digit; i++){
        ll bit_mask = 1ll << (max_digit - i - 1);

        //反転させたときと反転させなかったときにどれだけ最大化できるか
        //0を採用するか1を採用するか
        //1が多数派：point0 > 多数派の1を勃たせておきたい気持ち：0を採用すれば1は勃ったままになる＞素直に得点計算
        //0が少数派：point1 > 少数はの1を萎えさせて多数派の0を勃たせたい：1を採用して得点計算
        ll point0 = bit_mask * keta[i];
        ll point1 = bit_mask * (N - keta[i]);
        

        if(dp[i][1] != -1){
            //ゆるゆるのまま行きたい気持ち・・・
            //0を勃たせても1を勃たせても良いのでとにかく大きな値になるように設定する
            //上位の桁で決定された(最大化された)値を引き継ぎ，
            //現在の桁で最大化できるのはpoint0かpoin1かを比較して決める
            if(dp[i + 1][1] < dp[i][1] + max(point0, point1)){
                dp[i + 1][1] = dp[i][1] + max(point0, point1);
            }
        }

    
        if(dp[i][0] != -1){
            //ガチガチからゆるゆるへ
            //つまり
            //ガチガチからゆるゆるへ移るにはXは0しか取らざるを得ない！
            //point0採用
            if(K & bit_mask){
                if( dp[i + 1][1] < dp[i][0] + point0){
                    dp[i + 1][1] = dp[i][0] + point0;
                }
                
            }
            //ガチガチのままガチガチへ
            if(K & bit_mask){
                //1のとき
                //0がある桁に寄与
                if(dp[i + 1][0] < dp[i][0] + point1){
                    dp[i + 1][0] = dp[i][0] + point1;
                }
                
            }else{
                //0のとき
                //1が勃っている桁に寄与
                if(dp[i + 1][0] < dp[i][0] + point0){
                    dp[i + 1][0] = dp[i][0] + point0;
                }
            }
        }

        //cout << i << endl;
    }

    //ガチガチのほうがよかったのかゆるゆるのほうが良かったのか，ガチゆるが良かったのか
    cout << max(dp[max_digit][0], dp[max_digit][1]) << endl;

    //確認
    /*
    for(ll i = 0; i < max_digit; i++){
        cout << keta[i] << " ";
    }
    cout << endl;
    */
 
} 