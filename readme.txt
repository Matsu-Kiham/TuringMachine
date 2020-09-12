Turing Machine

製作者：Matsu-Kiham
バージョン：1.00

チューリングマシンのシミュレーターです．
Windows10で動作確認済みです．

導入方法：
TuringMachine.exeをダウンロードして起動してください．
また，以下のファイルはソースコードに関わるファイルです．
なお，開発はVisual Studio 2019を用いて行いました．
・Resource.h
・TuringMachine.cpp
・TuringMachine.h
・TuringMachine.ico
・TuringMachine.rc
・TuringMachine.sln
・TuringMachine.vcxproj
・TuringMachine.vcxproj.filters
・framework.h
・small.ico
・targetver.h

アプリの操作法：
まず，シミュレートしたいマシンの番号を下のボタンから一つ選んで
クリックしてください．#06を選んだ場合，右上の#06用と書かれた
ところにあるコンボボックスの▼をクリックして1から7までの数から
どれかを一つ選んでください．
その後，マシンを自動で動かしたい場合は実行ボタンを，手動で
1ステップずつ動かしたい場合はステップをクリックしてください．
実行ボタンをクリックした場合，マシンが停止して出力が表示される
までアプリの操作はできません．また，ステップの場合，マシンが
停止しても出力は表示されません．
他のマシンをシミュレートしたい場合，もう一度マシンの番号を
選んでクリックしてから，同様の操作を行ってください．

マシンの内容
#01
A. M. Turing, ON COMPUTABLE NUMBERS, WITH AN APPLICATION TO
THE ENTSCHEIDUNGSPROBLEM, 1936
の3. Examples of computing machines.のI
一つ飛ばしで0と1を交互に書き込む．

#02
A. M. Turing, ON COMPUTABLE NUMBERS, WITH AN APPLICATION TO
THE ENTSCHEIDUNGSPROBLEM, 1936
の3. Examples of computing machines.のII
001011011101111011111...という列を書き込む．

#03
テープ上の記号xをyに書き換える．

#04
足し算をする．

#05
引き算をする．

#06
テープ上の0の個数を2進法で表す．


作者本人への連絡
matsukiham★gmail.com（★を@に変えてください）

更新履歴
2020/09/12　バージョン1.00公開