#include <iostream>
#include <vector>
#include "Player.h"
#include "Item.h"
#include "LimitedNumber.h"
#include "ItemTable.h"
#include "Bag.h"

using namespace std;

// プレイヤーを生成してステータスを操作するサンプル
void sample01() {
  // 名前、HP、攻撃力、防御力を指定してプレイヤーを生成
  Player* p1 = new Player("とんらん", 15, 10, 10);

  p1->addMaxHp(10); // 最大HPを10加算
  p1->addAtk(10);   // 攻撃力を10加算
  p1->addDef(10);   // 防御力を10加算
  p1->addHp(10);    // HPを10加算

  p1->showStatus();

  delete(p1);
}

// 体力を10回復する薬草というアイテムを作って、プレイヤーがそのアイテムを使う
void sample02() 
{
  // 名前、HP、攻撃力、防御力を指定してプレイヤーを生成
  Player* p1 = new Player("とんらん", 15, 10, 10);
  Item* item = new Item("薬草");

  // ステータス表示
  p1->showStatus();

  // プレイヤーにダメージを与える
  p1->addHp(-13);
  p1->showStatus();

  // プレイヤーがアイテムを使う
  p1->use(item);
  p1->showStatus();

  delete(p1);
  delete(item);
}

// 範囲制限付き数値クラスの動作確認
void sample03() {
  LimitedNumber<float> num;

#if _DEBUG
  num.show();

  // 最大値:0以下にならない
  num.setMax(-100);
  num.show();

  // 最大値を設定
  num.setMax(100);
  num.show();

  // 現在値:最小値(0)を下回らない
  num.setNow(-1000);
  num.show();

  // 現在値:最大値を超えない
  num.setNow(1000); // 最大値を超えない
  num.show();

  // 最大値を変更する(現在値が最大値より大きいなら、最大値に合わせられる)
  num.setMax(50);
  num.show();

  // 最大値を元に戻す
  num.setMax(100);
  num.show();

  // 空にする
  num.empty();
  num.show();

  // 満タンにする
  num.full();
  num.show();

  // 現在値を減らす
  num.addNow(-20);
  num.show();

  // 最大値を増やす
  num.addMax(100);
  num.show();

#endif
}

// 色んなアイテムを作って使ってみる
void sample04() {
  // 名前、HP、攻撃力、防御力を指定してプレイヤーを生成
  Player* p1 = new Player("とんらん", 15, 10, 10);

  // 適当にアイテムを作る
  vector<Item*> items = vector<Item*>();
  items.push_back(new ItemMaxHpUp());  // 最大HPアップ
  items.push_back(new ItemPortion());  // ポーション
  items.push_back(new ItemAtkSeed());  // 力の種
  items.push_back(new ItemDefSeed());  // 守りの種
  items.push_back(new ItemLvUp());     // レベルアップの実
  items.push_back(new ItemLvUpPlus()); // レベルアップの果実
  
  for (int i = 0; i < items.size(); ++i) {
    cout << items[i]->getName() << "を使った。" << endl;
    p1->use(items[i]);
    p1->showStatus();
  }
}

// Itemテーブルからアイテムの情報を取得し内容を表示
void sample05() {
  ItemTable::findBy(ItemID::PORTION)->show();
  ItemTable::findBy(ItemID::PORTION_H)->show();
}

// バッグの動作チェック
void sample06() {
  // アイテム用変数(後で使う)
  Item* item = NULL;

  //プレイヤーを生成
  Player* p1 = new Player("とんらん", 15, 10, 10);

  // バッグを作る(ポーション2個とハイポーション1個)
  Bag* bag = new Bag();
  bag->push(ItemID::PORTION);
  bag->push(ItemID::PORTION);
  bag->push(ItemID::PORTION_H);
  bag->show();

  // ポーションを取得する
  item = bag->pop(ItemID::PORTION);

  // アイテムが取れない事もあるのでチェックしとく
  if (item != NULL) {
    p1->addHp(-20);   // ダメージ与えて
    p1->use(item);    // アイテム使って
    p1->showStatus(); // 結果を確認
    bag->show();
  }

}

int main(void)
{
  sample06();
  return 0;
}