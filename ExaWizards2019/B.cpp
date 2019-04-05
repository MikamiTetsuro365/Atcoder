#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
//greaterで必要
#include <functional>
//重複チェック
#include <set>


using namespace std;
typedef long long ll;
ll N;
ll M;
ll r;
ll INF = 1<<28;


int main() {
    //頂点数
    cin >> N;
    string S;
    cin >> S;

    int r = 0;
    int b = 0;
    for(int i= 0; i < N; i++){
        if(S.substr(i,1) == "R"){
            r++;
        }else{
            b++;
        }
    }

    if(r > b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}