#include "PlayState.h"

PlayState::PlayState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn ),
	enemyManager( EnemyManager( textureCodex ) ),
	playerManager( PlayerManager( textureCodex ) ),
	headsUpDisplay( HeadsUpDisplay( textureCodex, "HighScoreLog.txt" ) )
{}

void PlayState::InitializeState()
{
}

void PlayState::ResetState()
{
}

void PlayState::Enter()
{
}

void PlayState::HandleInput()
{
	playerManager.HandlePlayerInput();
}

void PlayState::UpdateLogic( float frameTime )
{
	enemyManager.UpdateEnemies( frameTime );
	playerManager.UpdatePlayer( maxScreenWidth );
}

void PlayState::Render( float interpolation )
{
	headsUpDisplay.RenderHUD( *window );
	enemyManager.RenderEnemies( *window, interpolation );
	playerManager.RenderPlayer( *window, interpolation );
}
