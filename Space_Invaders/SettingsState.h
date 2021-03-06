#pragma once
#include "GameState.h"
#include "StateHandler.h"
#include "SettingsMenu.h"

class SettingsState : public GameState
{
public:
	SettingsState( sf::RenderWindow& windowIn, StateHandler& handlerIn, TextureCodex& textureCodex, AudioManager& audioManagerIn, int screenWidthIn, int screenHeightIn );

public:
	void InitializeState() override;
	void ResetState() override;
	void Enter() override;

	void HandleInput() override;
	void UpdateLogic( float frameTime ) override;
	void Render( float interpolation ) override;

private:
	const std::vector< std::string > desiredItems = { "Volume", "Exit" };
	SettingsMenu settingsMenu;
};