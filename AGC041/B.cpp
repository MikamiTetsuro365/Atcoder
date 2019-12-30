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

bool check(ll mid){

    //midは配列の中のどこ?
    ll idx = mid;
    //Pは配列の中でどこ？
    ll p = P;
    //すでにP番目以内ですか？
    cout << idx << " " << p << endl;
    if(idx <= p){
        return true;
    }

    //vec[idx]がP番目以内に入ることができるか?
    //全員の投票をvec[idx]に集める
    ll base = vec[idx] + M;
    cout << vec[idx] << " " << base << endl;

    //投票数は1減る
    ll v = V - 1;
    //全員が全力で投票してもP番目以内に入れない時
    //vec[idx]は絶対に採用されることはない
    if(vec[p] > base){
        return false;
    }
    //P番目に入れるなら1~P-1までとmid+1~Nまでには全員投票しても順番は変わらない
    cout << p << "+" << N << "-" << idx << "=" << p + N - idx <<endl;
    if(v <= p + N - idx){
        return true;
    }
    cout << "dame" << endl;
    v -= p + N - idx;
    
    //P~mid-2に関してはみmidに対して全力投票した結果より下回ってくれないと困る
    //つまりmidがP番目になるのを邪魔しないように投票できなければならない
    //残りを投票
    ll nokori = v * M;
    cout << "nokori" << nokori << endl;

    for(ll i = p; i < idx; i++){
        //最大なんぼ投票できるかな？
        ll sa = base - vec[i];
        cout << sa << endl;
        if(nokori <= 0) break;
        nokori -= sa;
    }

    if(nokori > 0) return false;

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
        cout << "mid" << mid << endl;
        if(check(mid)){
            left = mid;
        }else{
            right = mid;
        }
        
    }
    cout << left << endl;

}