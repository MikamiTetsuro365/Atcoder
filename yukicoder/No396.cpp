#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

ll findClass(ll M, ll X){
    ll ans = 0;
    //境界
    if(X % M == 0){
        if(X / M % 2 == 1){
            return M;
        }else{
            return 1;
        }
    }
    //その他
    if(X / M % 2 == 0){
        return X % M;
    }else{
        return M - X % M + 1;
    }

}

int main(){

    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;

    ll classA = findClass(M, X);
    ll classB = findClass(M, Y);

    //cout  << classA << ", " << classB << endl;

    if(classA == classB){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

} 