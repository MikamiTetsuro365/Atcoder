#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
//一部doubleをllにしていて時間を犠牲にしたクソ
int main(){

    double A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    double noud_limit = 100 * E / (100 + E);
    double noud = 0;
    ll sugar = 0;
    ll water = 0;

    for(ll a = 0; a <= 31; a++){
        //cout << a << endl;
        for(ll b = 0; b <= 31; b++){
            //cout << b << endl;
            for(ll c = 0; c <= 101; c++){
                //cout << c << endl;
                for(ll d = 0; d <= 101; d++){
                    //cout << d << endl;
                    double t_water = 100 * A * a + 100 * B * b;
                    if(t_water <= 0) continue;
                    double t_sugar =  C * c + D * d;
                    double t_noud = 100 * t_sugar / (t_water + t_sugar) ;
                    if(t_water + t_sugar > F){
                        continue;
                    }
                    if(t_noud > noud_limit ){
                        continue;
                    }
                    if(noud <= t_noud){
                        noud = t_noud;
                        sugar = t_sugar;
                        water = t_water;
                    }
                }         
            }          
        }    
    }

    cout << water + sugar << " " << sugar << endl;

} 