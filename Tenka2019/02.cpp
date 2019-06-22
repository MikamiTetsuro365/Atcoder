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
    int N;
    cin >> N;
    string S;
    cin >> S;
    int K;
    cin >> K;

    string ss = S.substr(K-1, 1);

    for(int i = 0; i < N; i++){
        if(S.substr(i, 1) != ss){
            cout << "*" ;
        }else{
            cout << S.substr(i, 1);
        }
    }
    cout << endl;
} 