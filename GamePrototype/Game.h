#pragma once
#include "BaseGame.h"
#include "MonsterManager.h"
#include <SoundStream.h>


class Game : public BaseGame
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

private:

	MonsterManager m_MonsterManager;

	//Hud m_JetpackLogo{ Rectf{5, 10, 32, 30}, Hud::HudType::JetpackIcon };;
	//Hud m_JetpackBar{ Rectf{37, 10, 87, 17}, Hud::HudType::JetpackBar };;
	//Hud m_Heart3{ Rectf{280, 216, 35, 32}, Hud::HudType::Heart };
	//Hud m_Heart2{ Rectf{320, 216, 35, 32}, Hud::HudType::Heart };;
	//Hud m_Heart1{ Rectf{360, 216, 35, 32}, Hud::HudType::Heart };;
	//Hud m_GemIcon{ Rectf{5, 216, 32, 32}, Hud::HudType::Gem };;


	bool m_GameOver{ false };

	//TTF_Font* m_pFont;
	//std::vector<Texture*> m_pNumbers;

	//Level m_Level;

	//GemManager m_GemManager;
	//EnemyManager m_EnemyManager;
	//BulletManager m_BulletManager;
	//ParticleManager m_ParticleManager;
	//JumpersManager m_JumpersManager;

	//End* m_pEnd;

	std::vector<std::vector<Point2f>> m_VerticesMiddleLevelGems;
	std::vector<std::vector<Point2f>> m_VerticesMiddleLevelEnemies;

	std::vector<std::vector<Point2f>> m_VerticesFarLevelGems;
	std::vector<std::vector<Point2f>> m_VerticesFarLevelEnemies;

	std::vector<std::vector<Point2f>> m_VerticesCloseLevelGems;
	std::vector<std::vector<Point2f>> m_VerticesCloseLevelEnemies;

	std::vector<std::vector<Point2f>> m_VerticesJumpers1;



	//Avatar m_Avatar;

	//Camera m_Camera{ 200.f, 125.f };

	SoundStream m_BGMtest;

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;
};