## ABC110_Dについて

- とりあえず漠然と
    - 素因数分解して素因数の数について重複組み合わせを求めれば良いと思っていた
    
- そもそも
    - 素因数の数""ごと""に独立して重複組み合わせを計算して後で掛け合わせる必要がある
        - なぜなら，まとめて計算してしまうと(1,6)と(6,1)のような反転する組み合わせ（順番）が考慮されないから．

- 重複組み合わせ
    - n+k-1Ck
    - n個の要素をk個(グループ)にわける方法
    - k-1個の仕切りをイメージしするとk個(グループ)になる
        - つまり仕切りをどう並べるかを考える