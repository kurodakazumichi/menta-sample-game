#pragma once
#include <string>

// 依存するクラス(前方宣言)
class Player;

//*****************************************************************************
// Item.h
//*****************************************************************************
class Item
{
public:
	// デフォルトコンストラクタ
	Item();

	// 引数ありコンストラクタ
	Item(std::string name);

	// アイテムがプレイヤーに使われる
	virtual void usedBy(Player* player);

	// アイテム名を返す
	const std::string& getName() const;

private:
	std::string name; // アイテム名
};

// アイテム:ポーション
class ItemPortion : public Item {
public:
	ItemPortion();
	void usedBy (Player* player);
};

// アイテム：最大HPアップ
class ItemMaxHpUp : public Item {
public:
	ItemMaxHpUp();
	void usedBy(Player* player);
};

// アイテム：力の種
class ItemAtkSeed : public Item {
public:
	ItemAtkSeed();
	void usedBy(Player* player);
};

// アイテム：守りの種
class ItemDefSeed : public Item {
public:
	ItemDefSeed();
	void usedBy(Player* player);
};

// アイテム：レベルアップの実
class ItemLvUp : public Item {
public:
	ItemLvUp();
	void usedBy(Player* player);
};

// アイテム：レベルアップの果実
class ItemLvUpPlus : public Item {
public:
	ItemLvUpPlus();
	void usedBy(Player* player);
};