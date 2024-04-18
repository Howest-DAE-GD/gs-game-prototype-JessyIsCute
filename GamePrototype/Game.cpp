#include "pch.h"
#include "Game.h"
#include <SVGParser.h>
#include <iostream>

Game::Game( const Window& window ) 
	:BaseGame{ window }
	, m_BGMtest{ "Sounds/BGM.mp3" }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{

	
	m_BGMtest.Play(1);

	//m_Camera.SetLevelFarBoundaries(m_Level.GetFarBoundaries());
	//m_Camera.SetLevelMiddleBoundaries(m_Level.GetMiddleBoundaries());
	//m_Camera.SetLevelCloseBoundaries(m_Level.GetCloseBoundaries());



	////////////////////////////////////////////////////////////////////////
	///////////////////////// Enemies //////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	SVGParser::GetVerticesFromSvgFile("Images/BackgroundMiddleMonsters.svg", m_VerticesMiddleLevelEnemies);


	m_MonsterManager.AddItem(m_VerticesMiddleLevelEnemies[0][0], Monster::EnemyType::Enemy1, 1);
	m_MonsterManager.AddItem(m_VerticesMiddleLevelEnemies[0][1], Monster::EnemyType::Enemy2, 1);
	m_MonsterManager.AddItem(m_VerticesMiddleLevelEnemies[0][2], Monster::EnemyType::Enemy3, 1);


	SVGParser::GetVerticesFromSvgFile("Images/BackgroundFarOther.svg", m_VerticesFarLevelEnemies);
	m_MonsterManager.AddItem(m_VerticesFarLevelEnemies[0][0], Monster::EnemyType::Enemy1, 2);

	SVGParser::GetVerticesFromSvgFile("Images/BackgroundCloseOther.svg", m_VerticesCloseLevelEnemies);
	m_MonsterManager.AddItem(m_VerticesCloseLevelEnemies[0][0], Monster::EnemyType::Enemy1, 0);

	SVGParser::GetVerticesFromSvgFile("Images/BackgroundMiddleJumpers.svg", m_VerticesJumpers1);


	//////////////////////////////////////////////////////////////////////////
	/////////////////////////// Jumpers //////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	////m_JumpersManager.AddItem(m_VerticesJumpers1[0][0], m_VerticesFarLevelEnemies[0][1], 1, 2);
	////m_JumpersManager.AddItem(m_VerticesFarLevelEnemies[0][2], m_VerticesJumpers1[0][1], 2, 1);
	////m_JumpersManager.AddItem(m_VerticesJumpers1[0][2], m_VerticesCloseLevelEnemies[0][1], 1, 0);
	////m_JumpersManager.AddItem(m_VerticesCloseLevelEnemies[0][2], m_VerticesJumpers1[0][3], 0, 1);


	//////////////////////////////////////////////////////////////////////////
	/////////////////////////// Gems /////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////


	//SVGParser::GetVerticesFromSvgFile("Images/BackgroundMiddleGems.svg", m_VerticesMiddleLevelGems);

	//for (std::vector<Point2f> GemsVectors : m_VerticesMiddleLevelGems)
	//{
	//	for (Point2f Gems : GemsVectors)
	//	{
	//		m_GemManager.AddItem(Gems, 1);
	//	}
	//}


	//SVGParser::GetVerticesFromSvgFile("Images/BackgroundFarGems.svg", m_VerticesFarLevelGems);

	//for (std::vector<Point2f> GemsVectors : m_VerticesFarLevelGems)
	//{
	//	for (Point2f Gems : GemsVectors)
	//	{
	//		m_GemManager.AddItem(Gems, 2);
	//	}
	//}

	//SVGParser::GetVerticesFromSvgFile("Images/BackgroundCloseGems.svg", m_VerticesCloseLevelGems);

	//for (std::vector<Point2f> GemsVectors : m_VerticesCloseLevelGems)
	//{
	//	for (Point2f Gems : GemsVectors)
	//	{
	//		m_GemManager.AddItem(Gems, 0);
	//	}
	//}

	//////////////////////////////////////////////////////////////////////////
	/////////////////////////// Ends /////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////


	//SVGParser::GetVerticesFromSvgFile("Images/BackgroundMiddleOther.svg", m_VerticesCloseLevelGems);

	//m_pEnd = new End{ m_VerticesMiddleLevelEnemies[0][3], 1 };



	
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	m_MonsterManager.Update(elapsedSec);

	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void Game::Draw( ) const
{

	m_MonsterManager.Draw(2);
	ClearBackground( );
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	std::cout << "MOUSEBUTTONDOWN event: ";
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		std::cout << " left button x: " << e.x << " y: " << e.y << std::endl;
		break;
	case SDL_BUTTON_RIGHT:
		std::cout << " right button " << std::endl;
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << " middle button " << std::endl;
		break;
	}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
