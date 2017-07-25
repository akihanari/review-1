= 本を発行する


== 入稿のための最終出力を作る

印刷所へ最終的な印刷用データを渡すことを入稿と呼びます。
本節では入稿について実際の事例をベースに解説します。

@<chapref>{writing-book}で述べたとおり、同人誌向けのRe:VIEW構成を使用する前提です。本書のリポジトリをCloneしている場合、ノンブル（通し番号）のような同人誌特有の問題を回避できます。

 * @<href>{https://github.com/TechBooster/C89-FirstStepReVIEW-v2}

ここから先はTechBoosterが日光企画さんへ入稿した場合の手順として解説していきます。実のところ、印刷所ごとに印刷工程が違い、すべてで通用するスタンダードな方法というものはありません。

たとえば表紙データは印刷所ごとテンプレートが異なったり、入稿用本文にトンボ（断裁位置の目印）がないと受け付けてもらえなかったり、利用ソフトウェアのバージョン指定があったり、さまざまです。

かといって、すべてを説明すると流れを理解するまえに頭がパンクしてしまいます。ですので日光企画さんの事例に限って入稿に必要な知識をみていきましょう。実際には入稿予定の印刷所が指定するフォーマット、注意点を熟読して入稿に挑みましょう。

入稿に先立って知っておく知識として、部数に応じて適した印刷手法が異なります。

: オンデマンド印刷
  ～100部の小ロット印刷に適しています。印刷に使う版を作らないので手軽な一方、単価は高めです

: オフセット印刷
  100部〜の印刷に適しています。版を作る手法で、ロット数に応じて単価が安くなります

一般的にオフセット印刷のほうが品質がよいですが、近年の印刷技術向上によりオンデマンド印刷でも十分な品質を得られるケースがあります。
とくに品質については印刷所の腕の見せ所といえます。紙の種類も多数あるため詳細を知りたい場合は印刷所に相談するとよいでしょう。
だれもが最初から熟練者ではありません。初めての人の相談にも快く応じてくれるでしょう。

TechBoosterが過去に遭遇した事例では次のとおりです（印刷所選びに不安があれば本書のリポジトリ＋日光企画さんを使うとトラブルなく入稿できる可能性が高くなります）。

 * 表紙データ：表紙は本文と別の形式で入稿する
 * ページ数：紙の消費単位の関係で4の公倍数とするなど制約がある
 * ノンブル：全ページ通し番号が必要
 * レイアウト：余裕を持った小口（余白）を設定する

技術書であれば表紙がカラー、本文がモノクロであるケースがほとんどです。表紙と本文については後述の節でフォローしていきます。

一番の悩みどころである印刷部数については売れて欲しい部数の８掛けぐらいちょうどいいでしょう。
鉄則は頒布する必要最低限だけ印刷して在庫を持たないことです。８掛けであれば予測を外しても大量には残らない数です。

同人誌においては新刊がもっとも売れます。残った在庫は既刊と呼ばれ、
新刊ほどの勢いはありません。おおよそ１０～２０％程度の販売速度になります。

サークルごとに部数の指標は違いますが、TechBoosterは１５００～２０００部を用意してます。
日光企画さんの場合はオンデマンド印刷、オフセット印刷どちらでもPDF入稿が可能です。
つまり本書で紹介している手法で出力したらそのまま入稿形式となり、完璧！というわけです。便利ですね。

== 表紙データの作成方法

印刷所ごとのフォーマットに合わせて表紙を作成します。フォーマットはPSD形式です。
イラストと表紙用の装丁をおこない、入稿用データを作成します（@<img>{hyoushi}）。

//image[hyoushi][入稿データの一例]{
//}

表紙 1（表）と表紙 4（裏）に本の厚みも考慮した背を足したサイズが必要です。
断ち切りのための遊びがどれぐらい必要か、なども印刷所に確認しておきます。

日光企画さんの標準的なセットでは背は0.063mm/ページで計算します。背幅は表紙も含めたページ数なので本文128ページであれば表紙をいれると132ページ（8.316mm）です。

ちなみに表紙は表紙１〜表紙４と呼び、ページ数に含めます。本の内側に来る表紙２、表紙３には通常印刷しません。

TechBoosterではデザイナーさんとイラストレーターさんが協力して表紙を作成しています。
編集者が双方に書籍のイメージを伝えて構図を固めていきます。書籍の魅力を最大限引き出す表紙にしましょう。手に取ってもらえなければ読んでもらえないのですから。

印刷所によってはAI形式でも大丈夫だったり、利用できるソフトウェアのバージョン指定があったりします。表紙のフォーマット（テンプレート）もかならず違うのでよく確認してからとりかかりましょう。

== 本文データの作成方法

本文データはPDF形式で入稿します。またAdobe Acrobat Proが必要@<fn>{adobe}です。

//footnote[adobe][表紙データの作成にもPhotoshopを使うので潔くCreative Cloudのコンプリート月々プランでの契約がオススメです]

ページ数は基本的に４の倍数になるように揃えて入稿します。ならない場合は無理やり白いページを挟むこともあります。またページごとにノンブル（ページの通し番号）が必要です。たとえ白であっても、番号をいれます。同人誌以外では見ない制約ですが、乱丁を防ぐためにつけています。レイアウトは指がかかるのと本のノド（綴じている側の余白）があるので余裕を持った設定をしています。読みやすさに直結するので注意して設定してください。最初のうちは@<b>{本書リポジトリのレイアウト設定}での利用を推奨します。

ここでも印刷所によっては、PDF形式での入稿が行えない（画像として出力する必要がある）、トンボが必要である、隠しノンブルに対応できる、など条件が異なります。

TechBoosterが日光企画さんに入稿する事例では次のように進めています。

次のコマンドでPDFを出力します（B5 JISサイズを指定しています）。

//cmd{
review-pdfmaker config.yml
//}

しかし、これだけでは入稿に使えません。
フォントの埋め込みとPDFのフォーマットをPDF/Xに変換、原稿のモノクロ化をして初めて印刷所で扱うことができます。

=== フォントの確認
MacTexを利用している場合、現在のフォントを次のコマンドで調べることができます。

//cmd{
$ kanji-config-updmap status

CURRENT family for ja: ipaex
Standby family : ipa
//}

MacTex 2017ではデフォルトでIPAフォントを利用しています。埋め込まれていない場合は@<tt>{noEmbed}と表示しているはずです。
後述の手法をつかうとヒラギノフォントなどデフォルト以外に変更できます。

=== フォントの埋め込み

フォントの埋め込みをおこない、フォントがない環境で文字化けが起きないようにします。
埋め込み方は「Tex Wiki」サイト@<fn>{mactex-font}が参考になります。次のコマンドはサイトからの引用です。

//cmd{
cd /usr/local/texlive/2017/texmf-dist/scripts/cjk-gs-integrate
sudo perl cjk-gs-integrate.pl --link-texmf --force
sudo mktexlsr
//}

//cmd{
sudo kanji-config-updmap-sys hiragino-elcapitan
//}

//footnote[mactex-font][@<href>{https://texwiki.texjp.org/?TeX%20Live%2FMac#elcapitan}]

このコマンドを実行したあとに@<tt>{review-pdfmaker}コマンドでPDFを作成するとフォントが埋め込まれています。文書のプロパティで埋め込みフォントと表示があれば成功です（@<img>{font}）。

//image[font][埋め込みフォント]{
//}

=== PDFフォーマットをPDF/Xに変換

PDFと一口にいっても単純じゃありません。そこは長い歴史をもつPDFさんのことです。
多数のバージョンが存在しています。TeXに続く深淵です。

しかし、印刷所への入稿を考えるとPDF/Xフォーマットがもっともポピュラーです。残念ながらLaTeX単体では対応できないため、ここから先はAcrobat Pro DCでの操作です。

ツールから印刷工程を選ぶと次のサイドメニューが表示されます（@<img>{pdfx}）。

//image[pdfx][PDF/Xとして保存する（画面右サイドメニュー中）]{
//}

メニューの中のPDF/Xとして保存するを選んで、別名で保存してください。このとき目次のハイパーリンクなど付加情報は保存されませんが、これは仕様@<fn>{engineer}です。

//footnote[engineer][エンジニアは仕様と言われると弱い]

=== 原稿のモノクロ化

入稿の最終段階です。作成したPDFデータをモノクロ化します。モノクロ化にあたってはPDF/Xフォーマットであることが前提ですので、前述のフォーマット変換作業を忘れずにおこなってください。

ツールから印刷工程を選ぶと色を置換というサイドメニューが表示されています（前述の@<img>{pdfx}のPDF/Xとしての保存の２つ上です）。

ここではオブジェクトのうち、DeviceCMYKカラータイプのプロファイルを変換します（@<img>{replace-color}、@<img>{replace-color-dot-gain}）。

//image[replace-color][色を置換では、DeviceCMYKを選択する]{
//}

//image[replace-color-dot-gain][カラーを出力インテントに変換をチェック]{
//}

@<b>{カラーを出力インテントに変換}にチェックをいれて、@<b>{Dot Gain 15%}を選択します。
また変換のオプションで@<b>{黒を維持}もチェックします。

この設定で色を置換すると無事、モノクロ化できます。ここまでで本文の入稿データ作成は完了です。

== 電子書籍（PDF）を発行する

#@# TODO mhidaka

== EPUB（リフロー）を発行する

#@# TODO mhidaka