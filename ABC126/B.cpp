#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

int main(){

    string S;

    cin >> S;

    ll A = stoi(S.substr(0, 2));
    ll B = stoi(S.substr(2, 2));

    if(1 <= A && A <= 12){
        if(1 <= B &&B <= 12){
            cout << "AMBIGUOUS" << endl;
        }else{
            cout << "MMYY" << endl;
        }
    }else{
        if(1 <= B && B <= 12){
            cout << "YYMM" << endl;
        }else{
            cout << "NA" << endl;
        }
    }
} 