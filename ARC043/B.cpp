#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//愚直なDPでやるとN以下の数の通りの数を探さないといけないのでしんどい

//Binary Indexed Treeの本体
class bit1d{
    public:
    vector<ll > bit;
    ll N;

    bit1d(ll n = 0){
        N = n + 19;
        bit = vector<ll >(N + 19, 0); 
    }

    //要素の追加
    void add(ll a, ll w){
        //区間の長さと現在追加しようとしている値の添字を足すと求めることができる
        //区間の長さは区間番号を２進数にした時,最も下位にある立ったビットで分かる
        //x & -xで最も下位の立ったbitが分かる
        for(ll i = a; i <= N; i += i & -i){
            bit[i] += w;
        }
    }

    //区間1~aの和の計算
    ll intervalSum_1_a(ll a){
        //次にどこを足せばよいかは区間番号からその区間番号の長さを引くと求まる
        ll ret = 0;
        for(ll i = a; i > 0; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }

};

//ll dp[101010][101010][]
//ある問題を1
int main() {

    ll N; 
    cin >> N;
    //BIT準備
    bit1d selectOne(100000);
    bit1d selectTwo(100000);
    bit1d selectThree(100000);

    vector<ll > D(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> D[i];
    }
    sort(D.begin(), D.end());

    ll ans = 0;

    for(ll i = 0; i < N; i++){
        //BITに要素の個数を追加
        //1問目への選び方．全てについて自分自身の1つだけ
        selectOne.add(D[i], 1);
        //2問目への選び方．1問目について自分より1/2以下の難易度が選べる
        selectTwo.add(D[i], selectOne.intervalSum_1_a(D[i]/2));
        //3問目への選び方．2問目について自分より1/2以下の難易度が選べる
        //つまり2問目における自分より1/2以下の難易度の通りの数の合計が3問目における通りの数になる
        selectThree.add(D[i], selectTwo.intervalSum_1_a(D[i]/2));
        //4問目も同様
        ans += selectThree.intervalSum_1_a(D[i]/2);
        ans %= MOD;

    }

    cout << ans << endl;
}