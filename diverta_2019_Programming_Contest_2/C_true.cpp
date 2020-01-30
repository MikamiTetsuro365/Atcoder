#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//大胆な気持ちで考える
//プラスはプラスのまま答えに足したいし
//マイナスはプラスにして答えに足したい
//でもx-yという操作をする必要があるので
//すべてをプラスにしたりマイナスにすることは絶対にできない
//必ず+と-の要素が必要
//つまり最大値と最小値を+と-に固定すれば，あとの数字はどのような
//符号の付け方でも良い
int main() {
    //ifstream in("23.txt");
    //cin.rdbuf(in.rdbuf());

    ll N;
    cin >> N;

    vector<ll > minus;
    vector<ll > plus;


    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());

    ll sum = 0;
    //-から+に数字が分布しているならすべての符号を+にできる
    //A_N(最大でプラス) - (A_1(最小でマイナス) - プラスの奴ら ) - マイナスの奴ら
    //ですべての符号をプラスに揃えることができる！！！！
    for(ll i = 0; i < N; i++){
        sum += abs(vec[i]);
    }
    //-または+しか存在しない数列だとはみ出た分考慮する
    if(vec[0] > 0) sum -= vec[0] * 2;
    if(vec[vec.size()-1] < 0) sum += vec[vec.size()-1] * 2;

    cout << sum << endl;

    //操作を復元する
    //最小の値から操作していく
    ll tmp = vec[0];

    //まずはプラスのやつらを引いていく
    //ここ(A_1(最小でマイナス) - プラスの奴ら ) の操作
    for(ll i = 1; i < N - 1; i++){
        if(vec[i] >= 0){
            cout << tmp << " " << vec[i] << endl;
            //更新
            tmp -= vec[i];
        }
    }
    //次にマイナスの奴らを引いていく
    //A_N(最大でプラス) - (tmp) - マイナスの奴ら
    cout << vec[vec.size()-1] << " " << tmp << endl;
    tmp = vec[vec.size()-1] - tmp;
    for(ll i = 1; i < N - 1; i++){
        if(vec[i] < 0){
            cout << tmp << " " << vec[i] << endl;
            tmp -= vec[i];
        }
    }

}