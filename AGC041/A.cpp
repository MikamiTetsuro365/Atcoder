#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N, A, B;
    cin >> N >> A >> B;
    
    if(A % 2 == B % 2){
        //お互いの卓の真ん中で出会える
        //奇数卓真ん中にアレば
        cout << (B - A) / 2 << endl;
    }else{
        //偶数卓挟んでいるときはお互い寄り合ってもだめ
        //どちらかが一度端っこに行って調整したのちもう一方へ寄っていく
        //調整が済むとAとBの間には奇数卓(B - A - 1)挟んでいることになる
        cout << min(A - 1, N - B) + 1 + (B - A - 1) / 2 << endl;
    }

}