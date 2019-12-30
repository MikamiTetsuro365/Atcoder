#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll N, M, V, P;
//番兵を入れていなかったので添字の操作と二分探査が噛み合わずドチャクソ悩んだ
//要復習

bool check(ll mid){
    //vec[0]は番兵
    //vec[mid]がP番目に選ばれれば目的を満たせる
    //満たすような操作を考える
    //vec[mid]がP番目に入るためにはvec[P]より大きいスコアになる必要がある
    //とりあえず全員がvec[mid]に投票してスコアをMだけ上げる
    vector<ll > tmp = vec;
    //トータルの投票数
    ll tmpVM = V * M;
    //vec[mid+1]~vec[N]に関しては投票者が全員投票してもvec[mid]にスコアより
    //小さくなる. なぜなら vec[mid] >= vec[mid+1] ...降順に並んでいるから
    for(ll i = mid; i <= N; i++){
        if(tmpVM <= 0){
            break;
        }
        tmp[i] += M;
        tmpVM -= M;
    }
    //vec[1]~vec[P-1]はvec[mid]より大きくて構わない
    //なぜなら，vec[mid]がP番目であるとき,この範囲のスコアが高くなってもvec[P]
    //はP番目に選ばれるのは確実だから
    for(ll i = 1; i < P; i++){
        if(tmpVM <= 0){
            break;
        }
        tmp[i] += M;
        tmpVM -= M;        
    }

    //vec[P]~vec[mid-1]に関してはvec[mid]+Mを超えないように投票する必要がある
    //なぜなら，超えてしまうとvec[mid]はP番目に選ばれなくなるから
    for(ll i = P; i < mid; i++){
        if(tmpVM <= 0){
            break;
        }
        ll sabun = tmp[mid] - tmp[i];
        if(sabun < 0){
            //vec[mid]+Mがvec[P]のスコアを超えられないと絶対にP番目に選ばれない
            return false;
        } 
        tmp[i] += sabun;
        tmpVM -= sabun;        
    }    

    if(tmpVM > 0){
        //全員の投票権を使い切れていない
        //つまりvec[P]~vec[mid-1]でまだまで投票できるのでvec[mid]はP番目に選ばれない
        return false;
    }

    if(tmp[P] > tmp[mid]){
        return false;
    }

    return true;
}

int main() {

    cin >> N >> M >> V >> P;
    //配列で言うP-1までは採用対象

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }
    //番兵
    vec.push_back(INF);
    sort(vec.rbegin(), vec.rend());

    //条件を満たすような最大値
    //絶対に1問は選べる
    ll left = 1; ll right = N + 1;
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        //cout << "mid" << mid << endl;
        if(check(mid)){
            left = mid;
        }else{
            right = mid;
        }
        
    }
    cout << left << endl;

}