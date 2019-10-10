#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<double, double > pi; 
typedef pair<pair<ll ,ll >,ll > pii; 
//全探査するだけ
ll ctoi(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

int main(){
    
    string input; cin >> input;
    
    for(ll i = 0; i < (1<<3); i++){
        vector<ll > fugou(3, 1);
        for(ll j = 0; j < 3; j++){
            if(i >> j & 1){
                fugou[j] = -1;
            }
        }
        ll sum = ctoi(input[0]);
        for(ll j = 0; j < 3; j++){
            if(fugou[j] == 1){
                sum += ctoi(input[j + 1]);
            }else{
                sum -= ctoi(input[j + 1]);
            }
        }

        if(sum == 7){
            cout << input[0];
            for(ll j = 0; j < 3; j++){
                if(fugou[j] == 1){
                    cout << "+" << input[j + 1];
                }else{
                    cout << "-" << input[j + 1];
                }
            }
            cout << "=7" << endl;
            return 0;
        }
    }

}