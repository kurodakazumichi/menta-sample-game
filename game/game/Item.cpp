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

const string& Item::getName() const {
	return this->name;
}

//-----------------------------------------------------------------------------
// ポーション(体力を10回復する)
ItemPortion::ItemPortion():Item("ポーション") 
{}

void ItemPortion::usedBy(Player* player) {
	player->addHp(10);
}

//-----------------------------------------------------------------------------
// 最大HPアップ(最大HPを10上げる)
ItemMaxHpUp::ItemMaxHpUp():Item("最大HPアップ")
{}

void ItemMaxHpUp::usedBy(Player* player) {
	player->addMaxHp(10);
}

//-----------------------------------------------------------------------------
// 力の種(攻撃力が5上がる)
ItemAtkSeed::ItemAtkSeed() :Item("力の種")
{}

void ItemAtkSeed::usedBy(Player* player) {
	player->addMaxAtk(5);
	player->addAtk(5);
}

//-----------------------------------------------------------------------------
// 守りの種(防御力が5上がる)
ItemDefSeed::ItemDefSeed() :Item("守りの種")
{}

void ItemDefSeed::usedBy(Player* player) {
	player->addMaxDef(5);
	player->addDef(5);
}

//-----------------------------------------------------------------------------
// レベルアップの実(レベルが上がる)
ItemLvUp::ItemLvUp() : Item("レベルアップの実")
{}

void ItemLvUp::usedBy(Player* player) {
	player->upLv();
}

//-----------------------------------------------------------------------------
// レベルアップの果実(レベルが5上がる)
ItemLvUpPlus::ItemLvUpPlus() : Item("レベルアップの果実")
{}

void ItemLvUpPlus::usedBy(Player* player) {
	for(int i = 0; i < 5; ++i) player->upLv();
}