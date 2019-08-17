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
//ゴリ押し
//たぶんできないこともないけど，前処理と後処理がめんどくさすぎて計算時間が間に合わない可能性
int main(){

    ll N, M;
    cin >> N >> M;
    vector<ll > a(N,0);
    vector<ll > b(N,0);
    //aとbの関係を記憶
    map<ll, vector<ll > > memo;
    for(ll i = 0; i < M; i++){
        ll A, B;
        cin >> A >> B;
        memo[A].push_back(B);
        a[A-1] = 1;
        b[B-1] = 1;
    }

    //vector<vector<ll > > ab(N + 1, vector<ll>(2, 0));
    //bの位置を記憶
    map<ll, vector<ll > > memo2;
    vector<ll > t_a(N + 1,0);
    vector<ll > t_b(N + 1,0);
    //うりゃ
    ll it = 0;
    for(ll i = 0; i < N; i++){
        if(a[i] == 1){
            t_a[it] = i + 1;
        }
        if(b[i] == 1){
            t_b[it] = i + 1;
            memo2[i + 1].push_back(it);
        }
        if(a[i] == 1 || b[i] == 1){
            it++;
        }
    }

    vector<ll > eraseList;
    ll ans = 0;
    for(ll i = 0; i < N; i++){

        if(t_a[i] != 0){
            for(ll j = 0; j < memo[t_a[i]].size(); j++){
                eraseList.push_back(memo[t_a[i]][j]);
            }            
        }

        //削除跡があれば
        if(t_b[i + 1] == -1){
            continue;
        }
        
        if(t_a[i] > 0 && t_b[i + 1] > 0 || t_a[i] == 0 && t_b[i + 1] > 0 ){
            ans++;
            //削除
            for(ll j = 0; j < eraseList.size(); j++){
                t_b[memo2[eraseList[j]][0]] = -1;
            }
            eraseList.clear();
        }
    }   

    cout << ans << endl;

    //確認
    for(ll i = 0; i < N; i++){
        cout << t_a[i] << " ";
    }
    cout << endl;

    for(ll i = 0; i < N; i++){
        cout << t_b[i] << " ";
    }
    cout << endl;
    
    

} 