#include "pch.h"
#include "Sprite.h"
#include "Texture.h"




Sprite::Sprite(const Point2f& center, int layer)
	:m_FrameMax{0}
	,m_FrameCountDelay{0}
	,m_FrameCount{0}
	,m_IsFlipped{}
	,m_Layer{layer}
{
    m_pDrawTexture = nullptr;

	m_Center.x = center.x;
	m_Center.y = center.y;
}

void Sprite::Draw(int layer) const
{
	if (m_Layer != layer)
	{

	}
	else
	{


		const float cy = m_Shape.bottom + m_Shape.height / 2;
		const float cx = m_Shape.left + m_Shape.width / 2;

		glPushMatrix();

		if (m_IsFlipped)
		{
			glTranslatef((m_Shape.left + m_Shape.width / 2.f), 0.f, 0.f);
			glScalef(-1.f, 1.f, 1.f);
			glTranslatef(-(m_Shape.left + m_Shape.width / 2.f), 0.f, 0.f);
		}

		m_pDrawTexture->Draw(m_Shape, m_SourceRect);

		glPopMatrix();
	}
}

void Sprite::SetTexture(Texture* TexturePointer)
{
	m_pDrawTexture = TexturePointer;
}

Rectf Sprite::GetShape() const
{
	return m_Shape;
}


