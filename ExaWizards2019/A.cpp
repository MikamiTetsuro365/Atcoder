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
    int A;
    int B;
    int C;
    cin >> A >> B >> C;

    if(A == B && B == C && C == A){
        cout << "Yes"<< endl;
    }else{
        cout << "No" << endl;
    }


    
}