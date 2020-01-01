#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    ll A, B;
    cin >> A >> B;

    if(A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    } 

}