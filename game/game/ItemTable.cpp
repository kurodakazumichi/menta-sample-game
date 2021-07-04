//*****************************************************************************
// Item.cpp
//*****************************************************************************
#include <iostream>
#include <string>
#include "Consts.h"
#include "ItemTable.h"

using namespace std;

//=============================================================================
// ItemEntity
//=============================================================================
ItemEntity::ItemEntity(ItemID id, string name, int price)
	:_id(id)
	,_name(name)
	,_price(price) 
{}

// getter
ItemID ItemEntity::id() const {
	return this->_id;
}

const string& ItemEntity::name() const {
	return this->_name;
}

int ItemEntity::price() const {
	return this->_price;
}

void ItemEntity::show() const {
	cout << "ID   :" << static_cast<int>(this->_id) << endl;
	cout << "Name :" << this->_name << endl;
	cout << "Price:" << this->_price << endl;
}

//=============================================================================
// ItemTable
//=============================================================================
// アイテムデータを初期化
// mapの初期化はこのように書ける
map<ItemID, ItemEntity*> ItemTable::entities = 
{
	{ ItemID::PORTION  , new ItemEntity(ItemID::PORTION  , "ポーション"    , 100 ) },
	{ ItemID::PORTION_H, new ItemEntity(ItemID::PORTION_H, "ハイポーション", 500) }
};

// IDによってアイテムデータを探す
ItemEntity* ItemTable::findBy(ItemID id) {
	return ItemTable::entities[id];
}