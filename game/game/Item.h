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
	void usedBy(Player* player);

private:
	std::string name; // アイテム名
};