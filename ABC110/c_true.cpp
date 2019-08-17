#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <map>


using namespace std;
typedef long long ll;

//?????????????

int main(){

    string S, T;
    cin >> S >> T;
    map<char, char > check_s;
    map<char, char > check_t;
    //sort(S.begin(), S.end());
    //sort(T.begin(), T.end());

    for(ll i = 0; i < S.size(); i++){
        if(check_s.count(S[i])){
            if(check_s[S[i]] != T[i]){
                cout << "No" << endl;
                return 0;
            }
        }
        if(check_t.count(T[i])){
            if(check_t[T[i]] != S[i]){
                cout << "No" << endl;
                return 0;
            }
        }
        check_s[S[i]] = T[i];
        check_t[T[i]] = S[i];
    }

    cout << "Yes" << endl;
    
}