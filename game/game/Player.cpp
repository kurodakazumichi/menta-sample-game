//*****************************************************************************
// Player.cpp
//*****************************************************************************
#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include "Player.h"
#include "Item.h"
#include "LimitedNumber.h"

using namespace std;

// デフォルトコンストラクタ
Player::Player()
  : lv(1, 99)
  , name("名無しの勇者")
  , hp(0, 0)
  , atk(0, 0)
  , def(0, 0)
{}

// 引数ありコンストラクタ
Player::Player(string name, float hp, float atk, float def)
  : lv(1, 99)
  , name(name)
  , hp(hp, hp)
  , atk(atk, atk)
  , def(def, atk)
{}

// setter
void Player::setMaxHp(float num) {
  this->hp.setMax(num);
}

void Player::setHp(float num) {
  this->hp.setNow(num);
}

void Player::setAtk(float num) {
  this->atk.setNow(num);
}

void Player::setDef(float num) {
  this->atk.setNow(num);
}

// 全回復
void Player::fullRecovery() {
  this->hp.full();
  this->atk.full();
  this->def.full();
}

// レベルアップ
void Player::upLv() 
{
  this->lv.addNow(1);
  this->hp.addMax(1 + rand() % 3);
  this->atk.addMax(1 + rand() % 3);
  this->def.addMax(1 + rand() % 3);

  this->fullRecovery();
}

// ステータス加算
void Player::addMaxHp(float num) {
  this->hp.addMax(num);
}
void Player::addHp(float num) {
  this->hp.addNow(num);
}
void Player::addAtk(float num) {
  this->atk.addNow(num);
}
void Player::addDef(float num) {
  this->def.addNow(num);
}

// アイテムを使う
void Player::use(Item* item) 
{
  // アイテムがプレイヤーに使われる
  item->usedBy(this);
}

// ステータスを表示
void Player::showStatus() const {
  cout << this->name << endl;
  cout << "Lv :" << this->lv.getNow() << endl;
  cout << "HP :" << this->hp.getNow() << "/" << this->hp.getMax() << endl;
  cout << "ATK:" << this->atk.getNow() << endl;
  cout << "DEF:" << this->def.getNow() << endl;
}