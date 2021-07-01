#include <iostream>
#include "Player.h"
#include "Item.h"
#include "LimitedNumber.h"

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

int main(void)
{
  sample03();
  return 0;
}