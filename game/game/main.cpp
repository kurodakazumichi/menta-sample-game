#include "Player.h"
#include "Item.h"

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

int main(void)
{
  sample02();
  return 0;
}