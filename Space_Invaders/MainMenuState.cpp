#include "MainMenuState.h"

MainMenuState::MainMenuState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, int screenWidthIn, int screenHeightIn )
	:
	GameState( windowIn, handlerIn, screenWidthIn, screenHeightIn ),
	mainMenu( textureCodex, desiredItems, float( screenWidthIn ), float( screenHeightIn ) )
{}

void MainMenuState::InitializeState()
{
}

void MainMenuState::ResetState()
{
	mainMenu.ResetOptions();
}

void MainMenuState::Enter()
{
}

void MainMenuState::HandleInput()
{
	mainMenu.HandleInput( *handler );
}

void MainMenuState::UpdateLogic( float frameTime )
{
	mainMenu.Update( frameTime );
}

void MainMenuState::Render( float interpolation )
{
	mainMenu.Render( *window, interpolation );
}