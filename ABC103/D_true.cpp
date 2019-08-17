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
//橋番号の末端が早いものを選び，それに対して先端が超えないような組を見つけてカウントする
//選んだ末端番号より大きい先端番号が出たら，別々の組としても支障はない
//中が悪い組が１つだけなら１個だけの橋を壊す

int main(){

    ll N, M;
    cin >> N >> M;
    vector<pair <ll, ll > > ab;

    for(ll i = 0; i < M; i++){
        ll A, B;
        cin >> A >> B;
        ab.push_back(make_pair(B, A));
    }

    sort(ab.begin(), ab.end());

    ll select = 0;
    ll ans = 1;
    for(ll i = 0; i < M; i++){
        if(!(ab[select].first > ab[i].second)){
            ans++;
            select = i;
        }
    }

    cout << ans << endl;
    

} 