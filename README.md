# Atcoder
Atcoder関連はここにまとめます(精進)
includeは適当に書いてね

# たまに忘れる奴ら
**多次元ベクター(下は二次元)**
```cpp
ll n_rows = 5;
ll n_cols = 5;
ll value = 0;
vector<vector<ll > > vec(n_rows, vector<ll >(n_cols, value));
```

# map全列挙
```cpp

map<ll, ll> mp;
//ここになにか入力
auto begin = mp.begin(), end = mp.end();
for (auto iter = begin; iter != end; iter++) {
    cout << iter -> first << " " <<  iter -> second << endl;
}

```
# 最小公倍数
**N個の最小公倍数=最小公倍数の最小公倍数の最小公倍数(ry**
```cpp
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
```

```cpp
ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}
```

# 最小公倍数


# コピペで使いたい奴ら


# テンプレ
```cpp

```

# 約数
**約数を返します**
```cpp
vector<ll > divisor(ll n) {
  vector< ll > div;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      div.push_back(i);
      //重複許すマジ
      if(i * i != n) div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end());
  return (ret);
}
```


# 木やグラフ
**辺に重みも設定できます**
```cpp
//to (行き先), weight の順で設定
vector<vector<pair<ll, ll > > > G;
vector<ll > ans;
int main(){
    ll N;
    cin >> N;
    
    //初期化
    G.assign(N, vector<pair<ll, ll > >());
    ans.assign(N, 0);
 
    //グラフ入力
    for(ll i = 0; i < N-1; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
}
```

# dfs
**グラフや木を作って実行してくれい.**
```cpp
void dfs(ll idx, ll from = -1){
 
    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //同じだったらもう処理しない
        //頂点に戻ってきたら
        //後戻りを許さない
        if(to == from){
            continue;
        }

        //下は例です．この跡に色々処理を使いして幸せになりましょう
        /*    
        if(G[idx][i].second % 2 == 0){
            ans[to] = ans[idx];
        }else{
            ans[to] = 1 - ans[idx];
        }
        */
 
        dfs(to, idx);
 
    }
}

int main(){

    //グラフを作る

    //dfs 実行
    dfs(0);

}

```
# 累積和
**基本的なイメージはここよぉ[paiza](https://paiza.hatenablog.com/entry/2015/01/21/%E3%80%90%E7%B4%AF%E7%A9%8D%E5%92%8C%E3%80%81%E3%81%97%E3%82%83%E3%81%8F%E3%81%A8%E3%82%8A%E6%B3%95%E3%80%91%E5%88%9D%E7%B4%9A%E8%80%85%E3%81%A7%E3%82%82%E8%A7%A3%E3%82%8B%E3%82%A2%E3%83%AB%E3%82%B4)**

## まとめる処理
**たまに数列とかを同じ者同士でまとめる必要があるので**

```cpp
for(ll i = 0; i < s.size();){
    ll j = i;
    //一緒の間ループを回し続けて，切れ目を探す
    while(j < s.size() && s[j] == s[i]){
        ++j;
    }
    vec.push_back(j - i);
    //次の始点へすっ飛ばす
    i = j;
}
```

## 累積和のメイン処理
**合計を順番にとっていく,leftとrightを操作しながらある区間の合計を取っていく**
```cpp
//先頭は必ず0からスタート
vector<ll > sum(vec.size() + 1, 0);
for(ll i = 0; i < vec.size(); i++){
    //1つ前との合計を取っていく
    sum[i + 1] = sum[i] + vec[i];
}

//累積和メイン
ll ans = 0;
for(ll left = 0; left < sum.size(); left += 2){
    //K * 2 + 1の部分を合計を取りたい任意の区間の要素数に合わせる
    ll right = left + K * 2 + 1;
    //バグらせ防止, rightが伸びきったらもう動かさない終端でleftが上がってくるのを待つ
    if(right >= sum.size()){
        right = sum.size() - 1;
    }
    //sum[right] - sum[left]である区間の合計がわかります.
    ans = max(ans, sum[right] - sum[left]);
}
```


# 橋
**とてもわかり易い説明.特に6段目がよさみあふれる[ここ1](http://kagamiz.hatenablog.com/entry/2013/10/05/005213)[ここ２](https://ei1333.github.io/luzhiled/snippets/graph/lowlink.html)[ここ3](https://www.slideshare.net/chokudai/arc045)**




#　あばばば
**概要**
```cpp

```


