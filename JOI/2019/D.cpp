#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll conti_sum = 0;
    for(ll i = 0; i < S.length()-1;){
        if(S[i] != S[i + 1]){
            conti_sum++;
            i += 2;
        }else{
            i++;
        }
    }

    cout << conti_sum << endl;

}