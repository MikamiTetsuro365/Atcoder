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
#include <queue>
#include <functional>

using namespace std;
typedef long long int ll;

int main(){

    string S;
    cin >> S;
    vector<pair<char, ll > > SS;
    char tmp = 'a';
    for(ll i = 0; i < 26; i++){
        SS.push_back(make_pair(tmp + i, 0));
    }

    for(ll i = 0; i < S.length(); i++){
        SS[S[i] - 97].second = -1;
    }

    //何が使えるか
    priority_queue<char, vector<char>, greater<char > > que;
    for(ll i = 0; i < SS.size(); i++){
        if(SS[i].second != -1) {
            que.push(SS[i].first);
        }
    }

    //26文字以下なら使っていないやつの中で最小を取り出す
    if(S.length() < 26){
        cout << S << que.top() << endl;
        return 0;
    }

    //後ろから２文字比較していって左(j-1)が右(j)より小さければj-1以上でまだ辞書順
    //で大きいものを採用できる.
    //j-1以上の文字でj-2の文字より辞書順で大きく，一番小さいのを選んでやる
    ll j = S.length()-1;
    bool flg = false;
    while(j > 0){
        //降順
        if(S[j-1] > S[j]){
            que.push(S[j]);
            //cout << S[j] << endl;
        }else{
            //辞書順でもうこれ以上無理なとき
            flg = true;
            que.push(S[j]);
            break;
        }
        j--;
    }

    if(flg == false){
        cout << "-1" << endl;
    }else{
        for(ll i = 0; i < j - 1; i++){
            //cout << i << endl;
            cout << S[i];
        }
        //cout << S[j];
        while(!que.empty()){
            if((S[j - 1] >  que.top())){
                //cout << que.top() << endl;
                que.pop();
            }else{
                break;
            }
        }
        cout << que.top() << endl;
    }

} 