# MIDI2JAMMA

## 必要なハード

- [Arduino Uno R3](https://www.switch-science.com/catalog/789/)
- [MIDI シールド](https://www.switch-science.com/catalog/2492/)
  - 2022/04/24 時点で在庫切れ。

## 必要なライブラリ

- [Arduino MIDI Library](https://github.com/FortySevenEffects/arduino_midi_library/)

## 説明・補足

- (シールドは在庫切れですが・・)MIDI 受信回路が必要です。自作する場合はピン数足りていれば Uno R3 でなくてもよいと思います。

- HiHatNum,SnareNum 等の配列の数字は MIDI のノートナンバーです。電子ドラムの機種によってノートナンバーが異なる可能性があるため、合わせる必要があるかもしれません。

- Threshold は、MIDI 信号の velocity(どのくらい強く叩いたか)と比較させています。低い値にすると感度が上がります。(パッド毎の設定まではないです。)

- npn トランジスタのスイッチング回路で、叩いた時に反応するようにします。6個のトランジスタが必要です。

  - ベースには 8~13 ピンのいずれか1つを接続
  - コレクタには JAMMA の 5V 出力に接続
  - エミッタには JAMMA の GND に接続

- hitPad()で High の時間を 15ms にしているのは、それ以下では抜けが気になるようになったからです。

