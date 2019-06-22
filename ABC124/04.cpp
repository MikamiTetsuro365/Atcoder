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
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    vector<int > vec;
    //一番左端が0なら調整を加える
    bool swi;
    if(s.substr(0, 1) == "0"){
        swi = 0;
    }else{
        swi = 1;
    }
    if(swi == 0){
        vec.push_back(0);
    }
    //０または１が連続するところをまとめる処理
    int f = 0;
    int cont = 1;
    for(int i = 0; i < s.length()-1; i++){
        if(swi == 0){
            if(s.substr(i, 1) == "0" && s.substr(i+1, 1) == "1"){
                vec.push_back(cont);
                swi = 1;
                cont = 1;
            }else{
                cont++;
            }
        }else{
            if(s.substr(i, 1) == "1" && s.substr(i+1, 1) == "0"){
                vec.push_back(cont);
                swi = 0;
                cont = 1;
            }else{
                cont++;
            }
        }

    }
    vec.push_back(cont);

    //数合わせ
    /*
    if(ans.size() % 2 != 0){
        ans.push_back(0);
    }
    */

    //確認
    /*
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
    }
    cout << endl;
    */

    int range = 2 * K + 1;
    int left = 0;
    int right = 0;
    int temp = 0;
    int ans = 0;
    //しゃくとり方
    for(int i = 0; i < vec.size(); i += 2){
        int Nextleft = i;
        //右端を貫通しないように制限を加える
        int Nextright = min(i + range, (int)vec.size());
        //前の左端から今回の左端まで（差分）引く
        while(Nextleft > left){
            temp -= vec[left];
            left++;
        }
        //前の右端から今回の右端まで（差分）足す
        while(Nextright > right){
            temp += vec[right];
            right++;
        }

        ans = max(ans, temp);

    }

    cout << ans << endl;


} 