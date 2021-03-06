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

using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    string s;
    cin >> s;
    vector<ll > vec;
    //一番左端が0なら調整を加える
    bool start = 0;
    bool swi;
    if(s.substr(0, 1) == "#"){
        swi = 0;
    }else{
        swi = 1;
        start = 1;
    }
    if(swi == 0){
        vec.push_back(0);
    }
    //０または１が連続するところをまとめる処理
    ll f = 0;
    ll cont = 1;
    ll white = 0;
    for(ll i = 0; i < s.length()-1; i++){
        if(swi == 0){
            if(s.substr(i, 1) == "#" && s.substr(i+1, 1) == "."){
                vec.push_back(cont);
                swi = 1;
                cont = 1;
            }else{
                cont++;
            }
        }else{
            if(s.substr(i, 1) == "." && s.substr(i+1, 1) == "#"){
                vec.push_back(cont);
                white += cont;
                swi = 0;
                cont = 1;
            }else{
                cont++;
            }
        }

    }
    vec.push_back(cont);
    if(s.substr(s.length()-1,1) == "."){
        white += cont;
    } 
    //cout << white << endl;
    //０になるとき
    if(cont == s.length()){
        cout << "0" << endl;
        return 0;
    }else if(vec.size() == 2){
        if(start == 1){
            cout << "0" << endl;
        }
        return 0;
    }
    
    ll black = 0;
    ll ans = 1145141919;
    for(int i = 0; i < vec.size(); i++){
        //黒の個数確認
        if(i % 2 == 0){
            white -= vec[i];
        }else{
            black += vec[i];
        }
        //cout << black << " " << white << endl;
        ans = min(ans, black + white);

    }
    
    cout << ans << endl;  
}