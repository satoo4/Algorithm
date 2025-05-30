//シフト演算
//左に書いてある数字を2進数に直し、右に書いてある数字分だけ左にシフトする
//5<<2 だと5=101で10100になる
//右にシフトする場合は>>を使う

//アンド演算
//2進数の各桁を比較して、両方とも1の時だけ1になる
//5&3 だと5=101,3=011で001になる

//シフト演算とアンド演算を使うと各桁が1になっているか確認できる
//nシフトして、1とアンド演算をすることで、n桁目が1かどうかを確認できる

//bit全探索は各桁に0と1を割り当てて、全ての組み合わせを試す方法

