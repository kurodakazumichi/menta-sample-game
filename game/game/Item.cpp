//*****************************************************************************
// Item.cpp
//*****************************************************************************
#include <string>
#include "Item.h"
#include "Player.h"

using namespace std;

// デフォルトコンストラクタ
Item::Item()
	:name("Unknown")
{}

// 引数ありコンストラクタ
Item::Item(string name)
	:name(name)
{}

// アイテムがプレイヤーに使われる
// 暫定:とりあえずこのアイテムはプレイヤーの体力を10回復することにする
void Item::usedBy(Player* player) 
{
	player->addHp(10);
}