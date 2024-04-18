#pragma once
class Texture;
class Level;

class Sprite
{
	
	public:
		explicit Sprite(const Point2f& center, int layer);
		virtual ~Sprite() = default;

		Sprite(const Sprite& other) = delete;
		Sprite(Sprite& other) noexcept = delete;
		Sprite& operator=(const Sprite& other) = delete;
		Sprite& operator=(Sprite& other) noexcept = delete;

		virtual void Draw(int layer) const; 
		virtual void Update(float elapsedSec) = 0;

		void SetTexture(Texture* TexturePointer);
		Rectf GetShape() const;
protected:
		Texture* m_pDrawTexture;

		bool m_IsFlipped;


		int m_Layer;

		int m_FrameCountDelay;
		int m_FrameCount;
		int m_FrameMax;

		Point2f m_Center;
		Rectf m_Shape;

		Rectf m_SourceRect;
};

