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
ll N;

//改善　改善

int main(){

    string S;
    cin >> S;
    
    vector<ll > posi(S.length(), 0); 

    vector<ll > table(S.length(), 0);

    ll count = 0;

    //流し込める量を数え上げ
    for(ll i = S.length() - 1 ; i >= 0; i--){

        if(S[i] == 'R'){
            count++;
            table[i] = count;
        }else{
            count = 0;
        }     
    }
    for(ll i = 0 ; i < S.length(); i++){
    
        if(S[i] == 'L'){
            count--;
            table[i] = count;
        }else{
            count = 0;
            continue;
        }    
    }

    /*
    for(ll i = 0; i < S.length() - 1; i++){
        cout << table[i] << " ";
    }
    cout << table[S.length() - 1] << endl;
    */

    //集計
    for(ll i = 0; i < S.length(); i++){
        if( table[i] % 2 == 0){
            posi[i + table[i]]++;
        }else{
            if(table[i] < 0){
                posi[i + table[i] + 1]++;
            }else{
                posi[i + table[i] - 1]++;
            }
            
        }      
    }


    for(ll i = 0; i < S.length() - 1; i++){
        cout << posi[i] << " ";
    }
    cout << posi[S.length() - 1] << endl;;



} 
