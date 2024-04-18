#pragma once
#include "Monster.h"
#include <vector>
#include "structs.h"

class MonsterManager final
{
public:
	MonsterManager();
	~MonsterManager();

	MonsterManager(const MonsterManager&) = delete;
	MonsterManager& operator=(const MonsterManager&) = delete;
	MonsterManager(MonsterManager&&) = delete;
	MonsterManager& operator=(MonsterManager&&) = delete;

	Monster* AddItem(const Point2f& center, Monster::EnemyType type, int layer);
	void Update(float elapsedSec);
	void Draw(int layer) const;

	size_t Size() const;
	bool HitItem(const Rectf& rect, int layer);

	void TakeDmg(int enemyIdx, int dmgAmount);

	Rectf GetShape(int idx) const;

private:
	std::vector<Monster*> m_pItems;

};

