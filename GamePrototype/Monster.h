#pragma once
#include "Sprite.h"
#include "utils.h"
class Level;

class Monster : public Sprite
{
public:
	enum class EnemyType
	{
		Enemy1,
		Enemy2,
		Enemy3,
	};


	Monster(const Point2f& center, EnemyType type, int layer);
	~Monster();


	Monster(const Monster&) = delete;
	Monster& operator=(const Monster&) = delete;
	Monster(Monster&&) = delete;
	Monster& operator=(Monster&&) = delete;

	void Update(float elapsedSec);
	bool IsOverlapping(const Rectf& rect, int layer) const;
	bool IsAlive() const;
	void TakeDmg(int dmgAmount);


private:

	EnemyType m_Type;

	float m_TimeTillTurn;

	float m_Hp;
	bool m_IsAlive;

	float m_HorSpeed;

	Vector2f m_Velocity;
	Vector2f m_Acceleration;

	static Texture* m_pTexture;
	static int m_InstanceCounter;
	static float m_SCALE;
};


