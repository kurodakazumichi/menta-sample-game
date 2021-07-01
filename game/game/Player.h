#pragma once
#include <string>
#include "LimitedNumber.h"

// 依存するクラス(前方宣言)
class Item;

//*****************************************************************************
// Player.h
//*****************************************************************************
class Player {

public:
  // デフォルトコンストラクタ
  Player();

  // 引数ありコンストラクタ
  Player(std::string name, float hp, float atk, float def);

  // setter
  void setMaxHp(float num);
  void setHp(float num);
  void setAtk(float num);
  void setDef(float num);

  // 全回復
  void fullRecovery();

  // レベルアップ
  void upLv();

  // ステータス加算
  void addMaxHp(float num);
  void addHp(float num);
  void addAtk(float num);
  void addDef(float num);

  // ステータスを表示
  void showStatus() const;

  // アイテムを使う
  void use(Item* item);

private:
  std::string name; // 名前
  LimitedNumber<int> lv;    // Lv
  LimitedNumber<float> hp;  // HP
  LimitedNumber<float> atk; // 攻撃力
  LimitedNumber<float> def; // 防御力
};