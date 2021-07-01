//*****************************************************************************
// Player.cpp
//*****************************************************************************
#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include "Player.h"

using namespace std;

// デフォルトコンストラクタ
Player::Player()
  :lv(1)
  , name("名無しの勇者")
  , hp(0)
  , maxHp(0)
  , atk(0)
  , def(0)
{}

// 引数ありコンストラクタ
Player::Player(string name, float hp, float atk, float def)
  :lv(1)
  , name(name)
  , hp(hp)
  , maxHp(hp)
  , atk(atk)
  , def(def)
{}

// setter
void Player::setMaxHp(float num) {
  num = max(0.f, num);
  num = min(999.f, num);
  this->maxHp = num;
}

void Player::setHp(float num) {
  num = max(0.f, num);
  num = min(this->maxHp, num);
  this->hp = num;
}
void Player::setAtk(float num) {
  num = max(0.f, num);
  num = min(99.f, num);
  this->atk = num;
}
void Player::setDef(float num) {
  num = max(0.f, num);
  num = min(99.f, num);
  this->def = num;
}

// 全回復
void Player::fullRecovery() {
  this->hp = this->maxHp;
}

// レベルアップ
void Player::upLv() {
  this->lv++;

  this->maxHp += 1 + rand() % 3;
  this->atk += 1 + rand() % 3;
  this->def += 1 + rand() % 3;

  this->fullRecovery();
}

// ステータス加算
void Player::addMaxHp(float num) {
  this->setMaxHp(this->maxHp + num);
}
void Player::addHp(float num) {
  this->setHp(this->hp + num);
}
void Player::addAtk(float num) {
  this->setAtk(this->atk + num);
}
void Player::addDef(float num) {
  this->setDef(this->def + num);
}

// ステータスを表示
void Player::showStatus() const {
  cout << this->name << endl;
  cout << "Lv :" << this->lv << endl;
  cout << "HP :" << this->hp << "/" << this->maxHp << endl;
  cout << "ATK:" << this->atk << endl;
  cout << "DEF:" << this->def << endl;
}