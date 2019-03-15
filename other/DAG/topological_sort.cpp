#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;

ll N;
ll M;
vector<vector<ll> > G;
vector<ll > in_G;
//結果用
vector<ll > result;

//Kahnのアルゴリズムです

int main(){

    cin >> N;
    cin >> M;

    //入力を持たないノードの集合
    queue<ll> in;

    //本体
    G = vector<vector<ll> >(N);
    //流入量確認
    in_G = vector<ll > (N , 0);
    

    ll x = 0, y = 0;
    for(ll i = 0; i < M; i++){
        cin >> x >> y;
        G[x-1].push_back(y-1);
        in_G[y-1]++;
    }

    //グラフ確認
    /*
    for(ll i = 0; i < N; i++){
        cout << G[i].size() << " " << endl;;
    }
    */
    //流入数確認
    for(ll i = 0; i < N; i++){
        if(in_G[i] == 0){
            in.push(i);
        }
    }  


    ll n = 0;
    while(in.empty() == 0){
        n = in.front();
        result.push_back(n);
        in.pop();
        for(ll i = 0; i < G[n].size(); i++){
            in_G[G[n][i]]--;
            if(in_G[G[n][i]] == 0){
                in.push(G[n][i]);
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(in_G[i] > 0){
            cout << "No DAG" << endl;
            return 0;
        }
    }
    cout << "Yes DAG" << endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] + 1 << " ";
    }
    cout << endl;



}