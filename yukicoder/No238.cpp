#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

void solv(string S){

    string r_S = S;
    reverse(r_S.begin(), r_S.end());

    ll cn = 0;
    ll r_cn = 0;

    //とりあえず回文を判定とともに回分も作る
    for(ll i = 0; i < S.length() / 2; i++){
        if(S[i] != S[S.length()-1-i]){
            string str(1, S[i]);
            S.insert(S.length()-1-i+1, str);
            i--;
            cn++;
            /*
            if(cn > 1){
                break;
            }
            */
        }
    }

    if(cn == 1){
        cout << S << endl;
        return;
    }

    //念の為反対方向から
    for(ll i = 0; i < r_S.length() / 2; i++){
        if(r_S[i] != r_S[r_S.length()-1-i]){
            string str(1, r_S[i]);
            r_S.insert(r_S.length()-1-i+1, str);
            i--;
            r_cn++;
            /*
            if(r_cn > 1){
                break;
            }
            */
        }
    }

    if(r_cn == 1){
        cout << r_S << endl;
        return;
    }

    //すでに回分になっているなら偶数長と奇数長で分けて考える
    if(cn == 0 && r_cn == 0){
        if(S.length() % 2 == 1){
            string str(1, S[S.length()/2]);
            S.insert(S.length()/2, str);
            cout << S << endl;
        }else{
            string str(1, 'a');
            S.insert(S.length()/2, str);
            cout << S << endl;            
        }
    }else{
        cout << "NA" << endl;
    }

    return;
}

int main(){


    //普通の回文判定をする
    //始点と終点の端っこ同士を確認していって不一致ならどちらかにアルファベットを追加する
    //追加し続けるとどんな文字列でも回分になる（はず）
    //もとから回分なら真ん中になにかアルファベットを追加する

    string S; cin >> S;

    solv(S);

}