#include "pch.h"
#include "Monster.h"
#include "Texture.h"

Texture* Monster::m_pTexture{ nullptr };
int Monster::m_InstanceCounter{ 0 };
float Monster::m_SCALE{ 0.9f };

Monster::Monster(const Point2f& center, EnemyType type, int layer)
	: Sprite(center, layer)
	, m_Type{type}
	, m_Acceleration{0.0f, 0.0f}
	, m_IsAlive{true}
	, m_Hp{0}
{
	m_TimeTillTurn = 0.f;

	m_HorSpeed = -10.f;

	m_Velocity = Vector2f{};

	switch (m_Type)
	{
	case EnemyType::Enemy1:
		m_Hp = 150.f;
		m_SourceRect.width = 16.f;
		m_SourceRect.height = 16.f;
		break;

	case EnemyType::Enemy2:

		m_Hp = 100.f;
		m_SourceRect.width = 8.f;
		m_SourceRect.height = 8.f;
		break;

	case EnemyType::Enemy3:

		m_Hp = 200.f;
		m_SourceRect.width = 24.f;
		m_SourceRect.height = 24.f;
		m_Acceleration = Vector2f{ 0.f,0.f };
		break;
	}

	if (m_InstanceCounter == 0)
	{
		m_pTexture = new Texture("Images/Enemies.png");
	}

	Sprite::SetTexture(m_pTexture);

	++m_InstanceCounter;

	m_Shape.height = m_SourceRect.width * m_SCALE;
	m_Shape.width = m_SourceRect.height * m_SCALE;
	m_Shape.bottom = center.y - m_Shape.height / 2.f;
	m_Shape.left = center.x - m_Shape.width / 2.f;

}

Monster::~Monster()
{
	--m_InstanceCounter;

	if (m_InstanceCounter == 0)
	{
		delete m_pTexture;
	}
}




bool Monster::IsOverlapping(const Rectf& rect, int layer) const
{
	
	if (m_Layer != layer)
	{
		return false;
	}
	
	if (utils::IsOverlapping(rect, m_Shape))
	{
		
		return true;
	}
	return false;
	
}

bool Monster::IsAlive() const
{
	return m_IsAlive;
}

void Monster::TakeDmg(int dmgAmount)
{
	m_Hp -= dmgAmount;
}




void Monster::Update(float elapsedSec)
{
	if (m_Hp <= 0)
	{
		m_IsAlive = false;
	}
	m_TimeTillTurn += elapsedSec;

	m_Velocity.x = m_HorSpeed;

	if (m_TimeTillTurn >= 5)
	{
		m_TimeTillTurn = 0;

		m_IsFlipped = !m_IsFlipped;
		m_HorSpeed *= -1.f;
	}

	m_Shape.left += m_Velocity.x * elapsedSec;
	m_Shape.bottom += m_Velocity.y * elapsedSec;

	m_Velocity.x += m_Acceleration.x * elapsedSec;
	m_Velocity.y += m_Acceleration.y * elapsedSec;

	switch (m_Type)
	{
	case EnemyType::Enemy1:
		m_FrameMax = 2;
		m_SourceRect.left = 8.f + m_FrameCount * (m_SourceRect.width + 8.f);
		m_SourceRect.bottom = 24.f;
		
		break;

	case EnemyType::Enemy2:
		m_FrameMax = 2;
		m_SourceRect.left = 8.f + m_FrameCount * (m_SourceRect.width + 8.f);
		m_SourceRect.bottom = 96.f;
		break;

	case EnemyType::Enemy3:
		m_FrameMax = 2;
		m_SourceRect.left = 8.f + m_FrameCount * (m_SourceRect.width + 8.f);
		m_SourceRect.bottom = 240.f;

		break;
	}


	m_FrameCountDelay++;
	if (m_FrameCountDelay >= 10)
	{
		m_FrameCountDelay = 0;
		m_FrameCount++;
	}

	if (m_FrameCount >= m_FrameMax)
	{
		m_FrameCount = 0;
	}


	//utils::HitInfo hitInfo{};

	//if (level.IsCollidingHardHorizontal(m_Shape, m_Velocity, hitInfo, m_Layer) == Level::CollidingType::Left)
	//{

	//	m_Velocity.x = 0;
	//	m_Shape.left = hitInfo.intersectPoint.x;
	//}
	//if (level.IsCollidingHardHorizontal(m_Shape, m_Velocity, hitInfo, m_Layer) == Level::CollidingType::Right)
	//{
	//	m_Velocity.x = 0;
	//	m_Shape.left = hitInfo.intersectPoint.x - m_Shape.width;
	//}
	//if (level.IsCollidingHardVertical(m_Shape, m_Velocity, hitInfo, m_Layer) == Level::CollidingType::Bottom)
	//{

	//	m_Shape.bottom = hitInfo.intersectPoint.y;
	//	m_Velocity.y = 0;
	//}
	//if (level.IsCollidingHardVertical(m_Shape, m_Velocity, hitInfo, m_Layer) == Level::CollidingType::Top)
	//{
	//	m_Shape.bottom = hitInfo.intersectPoint.y - m_Shape.height;
	//	m_Velocity.y = 0;
	//}






	//if (level.IsCollidingSoftVertical(m_Shape, m_Velocity, hitInfo, m_Layer) == Level::CollidingType::Bottom)
	//{
	//	m_Shape.bottom = hitInfo.intersectPoint.y;
	//	m_Velocity.y = 0;
	//}

	//if (level.IsCollidingSpikesVertical(m_Shape, m_Velocity, hitInfo, m_Layer) == Level::CollidingType::Bottom or
	//	level.IsCollidingSpikesVertical(m_Shape, m_Velocity, hitInfo, m_Layer) == Level::CollidingType::Top)
	//{
	//	m_Velocity.y = 300;
	//}
	//if (level.IsCollidingSpikesHorizontal(m_Shape, m_Velocity, hitInfo, m_Layer) == Level::CollidingType::Left or
	//	level.IsCollidingSpikesHorizontal(m_Shape, m_Velocity, hitInfo, m_Layer) == Level::CollidingType::Right)
	//{
	//	m_Velocity.y = 300;
	//}

}


