#pragma once
#include <algorithm>

#if _DEBUG
#include <iostream>
#endif

//*****************************************************************************
// LimitedNumber 範囲付き数値クラス
// 0以上最大値以下の範囲に収まるようにチェック機能がついた数値クラス
// テンプレートに関する処理はヘッダに定義する。
//*****************************************************************************
template <class Number> 
class LimitedNumber 
{
public:
	// デフォルトコンストラクタ
	LimitedNumber()
		:now(0)
		,max(0)
	{}

	// 引数ありコンストラクタ
	explicit LimitedNumber(Number now, Number max)
	{
		this->setMax(max);
		this->setNow(now);
	}

	// setter, getter
	void setMax(Number num) 
	{
		num = std::max(static_cast<Number>(0), num);
		this->max = num;

		// 最大値が更新されたので、現在値を再セット
		this->setNow(this->now);
	}

	Number getMax() const {
		return this->max;
	}

	void setNow(Number num) 
	{
		num = std::max(static_cast<Number>(0), num);
		num = std::min(this->max, num);
		this->now = num;
	}

	Number getNow() const {
		return this->now;
	}

	// 最大値を増やす
	void addMax(Number num) {
		this->setMax(this->max + num);
	}

	// 現在値を増やす
	void addNow(Number num) {
		this->setNow(this->now + num);
	}

	// 満タンにする
	void full() {
		this->now = this->max;
	}

	// 空っぽにする
	void empty() {
		this->now = 0;
	}

	// 満タンです
	bool isFull() {
		return (this->now == this->max);
	}

	// 空っぽです
	bool isEmpty() {
		return (this->now == 0);
	}

	// 割合(現在値/最大値)
	float rate() {
		if (this->max == 0) return 0.0f;
		return (static_cast<float>(this->now) / static_cast<float>(this->max));
	}

#if _DEBUG
	// デバッグ用
	void show() {
		std::cout << this->now << "/" << this->max << std::endl;
		std::cout << "rate   :" << this->rate() << std::endl;
		std::cout << "isFull :" << this->isFull() << std::endl;
		std::cout << "isEmpty:" << this->isEmpty() << std::endl;
	}
#endif

private:
	Number now; // 現在の値
	Number max; // 最大の値
};