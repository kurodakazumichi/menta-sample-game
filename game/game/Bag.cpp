//*****************************************************************************
// Bag.cpp
//*****************************************************************************
#include <string>
#include <iostream>
#include "Consts.h"
#include "Bag.h"
#include "ItemTable.h"
#include "Item.h"

using namespace std;

// デフォルトコンストラクタ
Bag::Bag() 
	:items(map<ItemID, int>())
{}

// アイテムを追加する
void Bag::push(ItemID id) 
{
	// 初回はキーがないので、数量を1個に設定
	if (this->items.count(id) == 0) {
		this->items[id] = 1;
		return;
	}

	// アイテムの数を増やす
	this->items[id]++;
}

// アイテムを取り出す
Item* Bag::pop(ItemID id) 
{
	// アイテムを持ってなければNULL
	if (this->has(id) == false) return NULL;

	// アイテムを減らす(ほんとは個数がマイナスにならないようにチェックする方がいいけど横着)
	this->items[id]--;

	// アイテムを返す
	return ItemTable::getItem(id);
}

// 指定したアイテムがあるかどうか
bool Bag::has(ItemID id) 
{
	// キーがない = アイテムを持ってない
	if (this->items.count(id) == 0) return false;

	// アイテムの個数が0以下(実質0個)
	if (this->items[id] <= 0) return false;

	// キーがあり、アイテムが1個以上ならある
	return true;
}

// アイテムの中身を表示
void Bag::show() const {
	for (auto it = this->items.begin(); it != this->items.end(); ++it) 
	{
		ItemID itemId = it->first;
		int    count  = it->second;

		// アイテムが0個なら表示しない
		if (count == 0) continue;

		// アイテム名:n個 と表示
		const string& name = ItemTable::findBy(itemId)->name();
		cout << name << ":" << it->second << "個" << endl;
	}
}