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

using namespace std;
typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    vector<ll > vec;
    //基本的に1010101...の順番に揃えたい(バグを減らす気持ち)
    //左端が0なら空の0を加えておく1の数は0，右端も同様
    //一番左端が0なら調整を加える
    if(s[0] == '0') vec.push_back(0);
    //00..または11…が続いているところをまとめ上げる

    for(ll i = 0; i < s.size();){
        ll j = i;
        //一緒の間ループを回し続けて，切れ目を探す
        while(j < s.size() && s[j] == s[i]){
            ++j;
        }
        vec.push_back(j - i);
        //次の始点へすっ飛ばす
        i = j;
    }
    //最高尾が0だったら調整を加える
    if(s[s.length()-1] == '0'){
        vec.push_back(0);
    }

    //累積和を取る
    //始点は0から
    vector<ll > sum(vec.size() + 1, 0);
    for(ll i = 0; i < vec.size(); i++){
        sum[i + 1] = sum[i] + vec[i];
    }

    //累積和メイン
    ll ans = 0;
    for(ll left = 0; left < sum.size(); left += 2){
        //10...01分の合計を求めたい気持ち
        ll right = left + K * 2 + 1;
        //バグらせ防止, rightが伸びきったらもう動かさない終端でleftが上がってくるのを待つ
        if(right >= sum.size()){
            right = sum.size() - 1;
        }
        ans = max(ans, sum[right] - sum[left]);
    }

    cout << ans << endl;

} 