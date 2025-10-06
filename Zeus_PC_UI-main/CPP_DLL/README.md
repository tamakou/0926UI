# CPP_DLL
C#アプリからCPPで開発されたDLLの呼び出し  
# 主な機能
- UI画面からの処理要求を実行、結果を返す。
- DLL内に更に各処理モジュール（DLL）を呼び出し（モジュール分離）
- 処理要求は「同期実行」と「非同時実行」で実行。

# DLLのインタフェースの定義
- THProcLib/include/ 以下のファイルを参照。  
- [DLLコマンド定義全般](Commands.md)  
   [DLLレンダリング関連コマンド](RenderCommands.md)  
# ビルド方法
- VisualStudio2022で　THProcLib/src/ThProcLib.vcxproj　を開き、ビルドを行う。
- 先にプロジェクトAppUIをビルドした後にCPP_DLLの成果物のコピー

| 成果物  | コピー先 |
| ------------- | ------------- |
|CPP_DLL\bin\debug  | AppUI\AppUI\bin\Debug\net8.0-windows  |
|CPP_DLL\bin\debug\Release  | AppUI\AppUI\bin\Release\net8.0-windows  |
- ライブラリDLLのコピー（一回コピーのみ）

| ライブライDLL  | コピー先 |
| ------------- | ------------- |
|CPP_DLL\ThPCCoreLib\bin\Debug  | AppUI\AppUI\bin\Debug\net8.0-windows  |
|CPP_DLL\ThPCCoreLib\bin\Release  | AppUI\AppUI\bin\Release\net8.0-windows  |
  
# 参考資料
- [C#とC++DLL間の構造体、配列、コールバックなどの受け渡し方法](https://sksp-tech.net/archives/504#toc2)
- [C/C++で作られたDLLをC#から利用する際の引数の渡し方色々,ポインターなど...](https://ymegane88.hatenablog.com/entry/2019/08/12/013017)
- [C#からC++のDLLを呼び出す (構造体編) [C#]](https://nprogram.hatenablog.com/entry/2018/05/17/055306)
- [★　C#とC++間の配列と構造体の授受まとめ](https://qiita.com/Miyukiumoo/items/c3fcaf5fcf806ee250a0)  

# CSから呼び出しのテスト
- testDLLCS 参考程度
- CPP_DLL/bin/ 以下のThProcLib.dll　を　CSプロジェクトのビルドしたフォルダ以下にコピーしてください。
- CS内には　 [DllImport("ThProcLib.dll", EntryPoint =xxxx] のように使ってください。
