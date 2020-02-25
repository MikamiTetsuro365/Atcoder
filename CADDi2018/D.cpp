#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//るんるんは場に奇数個のりんごがあるときに勝てる
//つまり場に残るりんごが偶数個になるとダックスフンドが何かしらりんごをとったとき奇数個だけが残る
//複数の木があった時，奇数個りんごがなっている木を狙い撃ちにして取ると良さそう
//つねにルンルンが場のりんごを偶数個に揃えることができれば，
//相手はパスできないので必ず奇数個のりんごが次の手番で回ってくる
int main(){

    ll N; cin >> N;

    ll sum = 0;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        if(t % 2 == 1){
            sum++;
        }
    }

    if(sum > 0){
        cout << "first" << endl;
    }else{
        cout << "second" << endl;
    }
    //if(s)

}