#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){
    
    ll Aw, Ab, Bw, Bb, C, D;
    cin >> Aw >> Ab >> Bw >> Bb >> C >> D;

    ll white =  abs ( min((ll)0, Ab - C) );
    Aw -= white;
    Aw += min(Bw + white, D);


    cout << Aw << endl;

}