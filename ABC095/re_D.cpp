// #include "bits/stdc++.h"

// using namespace std;
// typedef long long int ll;
// typedef pair<ll, ll > pi;  
// typedef pair<pair<ll, ll >, ll > pii;  
// vector<ll > vec;
// vector<vector<ll > > vec2;
// ll MOD = 1000000007;
// ll INF = 1145141919454519;

// ll N, C;
// ll x[191919];
// ll v[191919];
// ll l_r[191919];
// ll l_max[191919];
// ll r_r[191919];
// ll r_max[191919];

// //累積ワ
// //問題の切り分け(どんな行動が最適解になるか？)
// //折り返して反対周りするなら，反対周りで最大値になる箇所で出ていかないとお得じゃなさそう
// int main() {

//     cin >> N >> C;

//     for(ll i = 0; i < N; i++){
//         cin >> x[i] >> v[i];
//     }

//     //左周りの累積和と最大値
//     ll tmp = -INF;
//     for(ll i = 1; i <= N; i++){
//         if(i == 1){
//             l_r[i] += v[i-1] - x[i-1];
//         }else{
//             l_r[i] += v[i-1] + l_r[i-1] - (x[i-1] - x[i-2]);
//         }
//         tmp = max(tmp, l_r[i]);
//         l_max[i] = tmp;
//     }  

//     //右周りの累積和と最大値
//     ll idx = 1;
//     tmp = -INF;
//     for(ll i = N - 1; i >= 0; i--){
//         if(i == N - 1){
//             r_r[idx] += v[i] - (C - x[i]);
//         }else{
//             //cout << x[i] << endl;
//             r_r[idx] += v[i] + r_r[idx-1] - ((C - x[i-1]) - (C - x[i]));
//         }
//         tmp = max(tmp, r_r[idx]);
//         r_max[idx] = tmp;
//         //cout << idx << " " << r_r[idx] << endl;
//         idx++; 
//     }   

//     ll ans = -INF;
//     //左に回って行ってそのまま出た時と折り返して右周りで最大になる箇所で出た時
//     for(ll i = 0; i <= N; i++){
//         //折り返してみるパターン
//         ll turn = l_r[i] - x[i] + r_max[N-i];
//         ans = max(turn, ans);
//         //そのまま出ていくパターン
//         ans = max(l_r[i], ans);
//     }
//     //cout << ans << endl;
//     //右
//     idx = N;
//     for(ll i = 0; i <= N; i++){
//         //折り返してみるパターン
//         ll turn = r_r[i] - (C - x[idx]) + l_max[N-i];
//         ans = max(turn, ans);
//         //そのまま出ていくパターン
//         ans = max(r_r[i], ans);
//         idx--;
//     }


//     cout << ans << endl;

// }