#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;

int N = 0;

int main(){

    cin >> N;

    int loop = N;
    for(;;){
        if(loop % 2 == 0 && loop % N == 0){
            cout << loop << endl;
            return 0;
        }
        loop++;
    }

}