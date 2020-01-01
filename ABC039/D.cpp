#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

char img[105][105];
char rec_img[105][105];
char tmp_img[105][105];

ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
ll dy[8] = {0, 1, 1,  1,  0, -1,-1,-1};

//白いがその周りは白かった.そうじゃないと白い画素は変換後黒になる
//縮小前の画像を割り出して膨張させて一致するかどうか試す.
int main(){

    ll H, W; cin >> H >> W;

    for(ll i = 0; i < H; i++){
        string s; cin >> s;
        for(ll j = 0; j < W; j++){
            img[i][j] = s[j];
            rec_img[i][j] = '.';
            tmp_img[i][j] = s[j];
        }        
    }

    for(ll i = H - 1; i >= 0; i--){
        for(ll j = W - 1; j >= 0; j--){
            if(img[i][j] != '.') continue;

            for(ll k = 0; k < 8; k++){
                if(i + dy[k] < 0 || i + dy[k] >= H || j + dx[k] < 0 || j + dx[k] >= W){
                    continue;
                }
                
                if(img[i+dy[k]][j+dx[k]] == '#'){
                    img[i+dy[k]][j+dx[k]] = '*';
                }
            }
        }
    }

    //復元
    for(ll i = H - 1; i >= 0; i--){
        for(ll j = W - 1; j >= 0; j--){
            if(img[i][j] == '#'){
                rec_img[i][j] = '#';
                continue;
            }

            for(ll k = 0; k < 8; k++){
                if(i + dy[k] < 0 || i + dy[k] >= H || j + dx[k] < 0 || j + dx[k] >= W){
                    continue;
                }

                if(img[i+dy[k]][j+dx[k]] == '#'){
                    rec_img[i][j] = '#';
                    break;
                }
            }
        }
    }    

    /*
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            cout << img[i][j];
        }        
        cout << endl;
    }
    */

    bool f = true;

    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            if(rec_img[i][j] != tmp_img[i][j]){
                f = false;
            }
            //cout << rec_img[i][j];
        }        
        //cout << endl;
    }

    if(f == false){
        cout << "impossible" << endl;
    }else{
        cout << "possible" << endl;
        for(ll i = 0; i < H; i++){
            for(ll j = 0; j < W; j++){
                if(img[i][j] == '#'){
                    cout << '#';
                }else{
                    cout << '.';
                }
            }        
            cout << endl;
        }
    }
 
}