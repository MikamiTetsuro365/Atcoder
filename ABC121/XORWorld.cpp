#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;
typedef long long ll;

ll A, B = 0;

//4の倍数周期で出てくる値が決まってるポイので0~nが簡単に求まる
//0~n と 0~mのそれぞれのXORを求めて，その値同士のXORを取ると差分が出てくる
//n xor n = 0なので(つまり共通部分)

int main(){
    clock_t start = clock();
    cin >> A >> B;

    ll total = 0;

    switch ((A - 1) % 4)
    {
        case 0:
            total = A - 1;
            break;
        case 1:
            total = 1;
            break;
        case 2:
            total = A ;
            break;
        case 3:
            total = 0;
            break;
    }

    switch (B % 4)
    {
        case 0:
            total = total ^ B;
            break;
        case 1:
            total = total ^ 1;
            break;
        case 2:
            total = total ^ (B + 1);
            break;
        case 3:
            total = total ^ 0;
            break;
    }

    cout << total << endl;

}