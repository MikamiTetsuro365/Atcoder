#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    string S;
    cin >> S;

    //多めに取る
    string comp = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
    vector<string> ans = {"Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si"};

    ll idx = 0;
    for(ll i = 0; i < 12; i++){
        string target = comp.substr(i, 20);
        if(target == S){
            break;
        }
        idx++;
    }
    //自分のいるところからなのでidxがそのまま答えに直結する
    cout << ans[idx] << endl;

}