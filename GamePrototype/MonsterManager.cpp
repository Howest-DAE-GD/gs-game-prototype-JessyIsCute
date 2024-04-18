#include "pch.h"
#include "MonsterManager.h"

MonsterManager::MonsterManager()
{
	m_pItems = std::vector<Monster*>{};
}

MonsterManager::~MonsterManager()
{
	for (Monster* pUp : m_pItems)
	{
		delete pUp;
	}
}

Monster* MonsterManager::AddItem(const Point2f& center, Monster::EnemyType type, int layer)
{
	Monster* pEnemy = new Monster(center, type, layer);
	m_pItems.push_back(pEnemy);
	return pEnemy;
}

void MonsterManager::Update(float elapsedSec)
{
	int idx{};
	for (Monster* pUp : m_pItems)
	{
		pUp->Update(elapsedSec);


		if (!pUp->IsAlive())
		{
			delete m_pItems[idx];
			m_pItems[idx] = m_pItems[Size() - 1];
			m_pItems.pop_back();
		}
		else
		{

		idx++;
		}

	}
}

size_t MonsterManager::Size() const
{
	return m_pItems.size();
}

void MonsterManager::Draw(int layer) const
{
	for (Monster* pUp : m_pItems)
	{
		pUp->Draw(layer);
	}
}

Rectf MonsterManager::GetShape(int idx) const
{
	return m_pItems[idx]->GetShape();
}

bool MonsterManager::HitItem(const Rectf& rect, int layer)
{
	int foundIdx = -1;
	for (int idx = 0; idx < Size(); ++idx)
	{
		if (m_pItems[idx]->IsOverlapping(rect, layer))
		{
			foundIdx = idx;
			break;
		}
	}
	if (foundIdx >= 0)
	{
		delete m_pItems[foundIdx];
		m_pItems[foundIdx] = m_pItems[Size() - 1];
		m_pItems.pop_back();
		return true;
	}
	return false;
}

void MonsterManager::TakeDmg(int enemyIdx, int dmgAmount)
{
	m_pItems[enemyIdx]->TakeDmg(dmgAmount);
}
