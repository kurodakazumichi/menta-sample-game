#pragma once
#include <string>
#include <map>
#include "Consts.h"

// 前方宣言
class Item;

//*****************************************************************************
// ItemTable.h
// Entityも一緒に定義
//*****************************************************************************

//=============================================================================
// ItemEntity
//=============================================================================
class ItemEntity {
public:
	// コンストラクタ
	ItemEntity(ItemID id, std::string name, int price);

	// getterのみ(setter作らない方針にして、getXXだと長いからgetは省略したメソッド名)
	ItemID id() const;
	const std::string& name() const;
	int price() const;

	// 内容を表示
	void show() const;

private:
	// getterと名前被らないようにｱﾝｽｺをつける
	ItemID _id;
	std::string _name;
	int _price;
};

//=============================================================================
// ItemTable
// アイテムテーブルクラスはnewできても意味がないというか、インスタンスが複数あっても困る
// なので、そもそもnewもさせないし、newしなくても使えるクラスとして実装します。
// ここではメンバを全てstaticにする作り方を採用してみる。
// 
// ちなみにメンバを全てstaticにするような作り方を
// Monostateパターンと言ったりする。
// デザインパターンの１つである。
//=============================================================================
class ItemTable 
{
public:
	// IDを元にEntityを探す
	static ItemEntity* findBy(ItemID);

	// IDを元にアイテムインスタンスを取得
	static Item* getItem(ItemID);

private:
	// デフォルトコンストラクタをprivateにするとnew出来なくなる
	ItemTable() {}

	// コピーコンストラクタもprivateにしておく。
	// newさせないというのは→インスタンス増やしたくない→コピーされたくないでもある。
	// コピーコンストラクタを宣言だけして、実装をしないと
	// 何かの間違いでコピーがおこるようなコードを書いた時点でコンパイルエラーにできる。
	ItemTable(const ItemTable&);

	// アイテムエンティティ(同じデータが何個もあっても意味ないのでstaticでいい)
	static std::map<ItemID, ItemEntity*> entities;

	// アイテムのインスタンス
	static std::map<ItemID, Item*> items;
};