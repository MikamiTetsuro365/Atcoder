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
typedef long long int ll;

int main(){

    ll N, K;
    string S;
    cin >> N >> K >> S;
    vector <ll > packing;

    //バグらせないように後ろに一つつけておく
    if(S[S.length()-1] == 'R'){
        S.push_back('L');
    }else{
        S.push_back('R');
    }

    //幸福度
     ll ans = 0;

    //前処理
    ll tmp = 0;
    //最大何箇所変更できるか
    ll changeable = 0;
    for(ll i = 0; i < S.length() - 1; i++){
        //Lのときはプラスで揃える
        if(S[i] == 'L'){
            tmp++;
            if(S[i+1] == 'R'){
                packing.push_back(tmp);
                ans += tmp - 1;
                tmp = 0;
                changeable++;
            }
        }
        //Rのときはマイナスに揃える 
        if(S[i] == 'R'){
            tmp++;
            if(S[i+1] == 'L'){
                packing.push_back(-1 * tmp);
                ans += tmp - 1;
                tmp = 0;
                changeable++;
            }
        }
    }
    //一つ分余計
    changeable--;
    //cout << changeable << endl;

    if(changeable == 0){
        //変更可能な箇所がない　幸福度は人数に応じる
        cout << ans << endl;
    }else{
        //cout << changeable << endl;
        //向きを変えても２人分の幸福度しか最大で増えない
        ans += 2 * min(changeable / 2, K);
        K -= changeable / 2;
        //幸福度が１しか増えないところがあるか？
        if(K > 0 && changeable % 2 == 1){
            ans += 1;
        }
        cout << ans << endl;
    }

   
    //cout << ans << endl;

} 