#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//最長増加列を求める原理を思い出そう
//なるべく，小さいやつを残しておくと後々伸ばせる数字の数が多くなるので
//伸ばせる候補が複数あったら大きい末尾に足していくと良い
int main() {

    ll N;
    cin >> N;

    multiset<ll > st;
    //番兵を入れると楽
    st.insert(-INF);

    for(ll i = 0; i < N; i++){
        ll A; cin >> A;
        auto it = st.lower_bound(A);
        it--;
        //番兵以外なら更新できる候補が有るので消して更新
        if(*it != -INF) st.erase(it);
        st.insert(A);
        //cout << "size:" << st.size() << endl;
    }

    cout << st.size()-1 << endl;

}