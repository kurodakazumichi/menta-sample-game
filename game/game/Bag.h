#pragma once

#include <map>
#include "Consts.h"

// 前方宣言
class Item;

//*****************************************************************************
// Bag.h
//*****************************************************************************
class Bag 
{
public:
	// コンストラクタ
	Bag();

	// アイテムを追加する
	void push(ItemID id);

	// アイテムを取り出す
	Item* pop(ItemID id);

	// アイテムがあるか確認する
	bool has(ItemID id);

	// バッグの中身を見る
	void show() const;
private:
	std::map<ItemID, int> items;
};