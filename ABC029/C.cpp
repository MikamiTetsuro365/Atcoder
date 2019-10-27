#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;
set<string> s;

void solv(vector<char > A){
    do{
        string result;
        for(ll i = 0; i < A.size(); i++){
            result += A[i];
        }
        s.insert(result);
    }while(next_permutation(A.begin(), A.end()));
}

int main(){
    ll N; cin >> N;

    vector<char > a;

    for(ll i = 0; i < N; i++){
        vector<char > b;
        for(ll j = i ; j < N; j++){
            vector<char > c;
            vector<char > add1;
            for(ll k = j; k < N; k++){
                vector<char > add2;
                c.push_back('c');
                //確認
                add2.insert(add2.end(), a.begin(), a.end());
                add2.insert(add2.end(), b.begin(), b.end());
                add2.insert(add2.end(), c.begin(), c.end());
                solv(add2);
            }
            b.push_back('b');
            add1.insert(add1.end(), a.begin(), a.end());
            add1.insert(add1.end(), b.begin(), b.end());
            solv(add1);     
        }
        a.push_back('a');
        solv(a);    
    }

    for (auto x : s) {
        if(x.length() != N) continue;
        cout << x << endl;
    }

}