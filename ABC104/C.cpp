#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi; 
typedef pair<pair<ll ,ll >,ll > pii; 

int main(){
    
    ll D, G;
    cin >> D >> G;

    //vector<vector<ll > > D * (D + 1) / 2, vector<ll >(n_c, value));
    vector<pair<ll, ll > > input;
    
    for(ll i = 0; i < D; i++){
        ll p, c; cin >> p >> c;
        input.push_back(make_pair(p, c));
    }
    //cout << input.size() << endl;
    ll ans = INFINITY;
    
    for(ll i = 0; i <= (1<<D); i++){
        ll sum = 0;
        ll t_ans = 0;
        //ボーナスポイント込でもらえる組み合わせ
        for(ll j = 0; j < D; j++){
            if((i >> j) & 1 == 1){
                //ll a = i >> j;
                //cout <<  a;
                sum += input[j].first * 100 * (j + 1) + input[j].second;
                t_ans += input[j].first;
            }
        }
        cout << endl;
        //ボーナスポイント込でもらえた組み合わせでGを超えると幸せ
        //cout << i << " " << t_ans << endl; 
        if(sum >= G){
            ans = min(ans, t_ans);
            continue;
        }
        //微調整 単体のポイントを大きい順から割り振っていく
        //大きい順のほうが最小の手数になる
        for(ll j = D-1; j >= 0; j--){
            //ボーナスポイント込のところ以外のところから
            if(i >> j & 1 == 1) continue;
            for(ll k = 0; k < input[j].first; k++){
                if(sum >= G){
                    break;
                }
                sum += 100 * (j + 1);
                t_ans++;
            }
        }

        ans = min(ans, t_ans);

    }

    
    cout << ans << endl;

}