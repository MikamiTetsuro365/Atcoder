#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

//map<string, ll> card_comb;
set<string> card_comb;
ll solv(queue<ll > card_num, ll k, string s){

    if(k == 0){
        //k文字分並べたら終了
        //cout << s << endl;
        card_comb.insert(s);
        return true;
    }

    for(ll i = 0; i < card_num.size(); i++){
        //一度使った数字は二度と使わないように一旦popしておく
        ll tmp = card_num.front();
        string t_s = to_string(card_num.front());
        card_num.pop();
        //cout << card_num[i] << endl;
        solv(card_num, k - 1, s + t_s);
        //次の組み合わせでは使う可能性があるのでプッシュしておく
        card_num.push(tmp);
    }

    return true;

}

int main(){

    ll N, M;
    cin >> N >> M;

    //vector<ll > card_num;
    queue<ll > card_num;
    
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        card_num.push(t);
        //used[t][t] = 1;
    }

    string s = "";
    solv(card_num, M, s);
    //答え
    cout << card_comb.size() << endl;

    /* 
	set<string >::iterator pos = card_comb.begin();
	while(pos!=card_comb.end()){
        cout << *pos++ << endl;
	}
    */


}