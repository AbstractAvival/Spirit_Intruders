#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "TextureCodex.h"
#include "MovementDirections.h"
#include "Enemy.h"
#include "RandomNumberGenerator.h"
#include "HeadsUpDisplay.h"
#include "AudioManager.h"

class EnemyManager
{
public:
	EnemyManager();
	EnemyManager( TextureCodex& textureCodex, AudioManager& audioManagerIn, HeadsUpDisplay& hudDisplayIn );
	~EnemyManager();

	void ResetEnemies();
	void UpdateEnemies( float frameTime, bool playerExploded );
	void RenderEnemies( sf::RenderWindow& window, float interpolation );
	bool CheckCollisionAndKill( sf::FloatRect playerShotBoundary );
	bool IsExecutingOpeningFormation();
	bool AreAllEnemiesDead();
	Enemy GetRandomFrontlineEnemy();

private:
	void CreateTierOneEnemies( TextureCodex& textureCodex );
	void CreateTierTwoEnemies( TextureCodex& textureCodex );
	void CreateTierThreeEnemies( TextureCodex& textureCodex );
	void CreateBoss( TextureCodex& textureCodex);
	void CreateEnemies( TextureCodex& textureCodex, EnemyTypes desiredEnemyType, int startingColumn, int endingColumn );
	void HandleEnemyMovement();
	void HandleBossMovement();
	void HandleAllEnemiesKilled();
	void ResetEnemyPositionsAndKill();
	void ResetBossPosition();
	void DoOpeningFormation();
	void MoveEnemies( sf::Vector2f direction );
	void SetMovementDirection();
	void ClearExplodedEnemies();
	sf::Vector2f GetMovementVector();

private:
	static constexpr int enemyRowLength = 11;
	static constexpr int enemyColumnHeight = 5;
	static constexpr int explodedValue = 2;
	static constexpr float horizontalSeparationDistance = 40.0f;
	static constexpr float verticalSeparationDistance = 35.0f;
	static constexpr float startingXPosition = 50.0f;
	static constexpr float startingYPosition = 130.0f;
	Enemy* enemies[ enemyRowLength * enemyColumnHeight ];
	Enemy* boss = nullptr;
	AudioManager* audioManager = nullptr;
	HeadsUpDisplay* hudDisplay = nullptr;
	MovementDirections currentMovementDirection;
	RandomNumberGenerator numberGenerator;
	bool isExecutingOpeningFormation = true;
	bool isGoingLeft = false;
	float maxMovementFrameTime = 0.13f;
	float accumulatedEnemyRespawnFrameTime = 0.0f;
	float maxEnemyRespawnFrameTime = 1.0f;
	float accumulatedMoveFrameTime = 0.0f;
	float accumulatedBossFrameTime = 0.0f;
	float horizontalBossMovement = -10.0f;
	float bossSpawnCooldown;
	int horizontalMovementCount = 14;
	int verticalMovementCount = 1;
	int openingFormationX;
	int openingFormationY;
	int movementColumnIndex;
	int movementXIndex;
	int movementYIndex;
};