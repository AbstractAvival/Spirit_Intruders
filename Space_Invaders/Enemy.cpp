#include "Enemy.h"

Enemy::Enemy()
	:
	GameObject( sf::Vector2f( 0, 0 ) ),
	enemyType( EnemyTypes::TestEnemy )
{
	currentSprite = Sprites::Contract;
}

Enemy::Enemy( TextureCodex& codex, EnemyTypes enemyTypeIn, sf::Vector2f positionIn )
	:
	GameObject( positionIn ),
	enemyType( enemyTypeIn )
{
	currentSprite = Sprites::Contract;
	InitializeSprites( codex );
	SetPosition( positionIn );
}

Enemy::Enemy( Enemy& enemy )
	:
	GameObject( enemy.position ),
	enemyType( enemy.enemyType )
{
	currentSprite = enemy.currentSprite;
	for( int spriteIndex = 0; spriteIndex < int( enemy.sprites.size() ); spriteIndex++ )
	{
		sprites.emplace_back( sf::Sprite() );
		sprites[ spriteIndex ].setTexture( *enemy.sprites[ spriteIndex ].getTexture() );
	}
	SetPosition( enemy.position );
}

Enemy::~Enemy()
{
}

void Enemy::Update( float frameTime )
{
}

void Enemy::Render( sf::RenderWindow& window, float interpolation )
{
	if( !IsDead() )
	{
		window.draw( sprites[ int( currentSprite ) ] );
	}
}

void Enemy::Move( sf::Vector2f offset )
{
	SwapMovementSprite();
	GameObject::Move( offset );
}

void Enemy::InitializeSprites( TextureCodex& textureCodex )
{
	switch( enemyType )
	{
	case EnemyTypes::Boss:
		LoadBossSprite( textureCodex );
		break;

	case EnemyTypes::TierOne:
		LoadTierOneSprites( textureCodex );
		break;

	case EnemyTypes::TierTwo:
		LoadTierTwoSprites( textureCodex );
		break;

	case EnemyTypes::TierThree:
		LoadTierThreeSprites( textureCodex );
		break;

	case EnemyTypes::TestEnemy:
		LoadTestSprite( textureCodex );
		break;
	}
}

void Enemy::LoadBossSprite( TextureCodex& textureCodex )
{
	sprites.emplace_back( sf::Sprite() );
	sprites[ int( currentSprite ) ].setTexture( textureCodex.GetGameTexture( GameTextureTypes::WhiteBox ) );
}

void Enemy::LoadTierOneSprites( TextureCodex& textureCodex )
{
	GameTextureTypes spriteTypes[ 3 ] = { GameTextureTypes::EnemyOneFirst, GameTextureTypes::EnemyOneSecond, GameTextureTypes::Explosion };
	LoadSprites( textureCodex, spriteTypes );
}

void Enemy::LoadTierTwoSprites( TextureCodex& textureCodex )
{
	GameTextureTypes spriteTypes[ 3 ] = { GameTextureTypes::EnemyTwoFirst, GameTextureTypes::EnemyTwoSecond, GameTextureTypes::Explosion };
	LoadSprites( textureCodex, spriteTypes );
}

void Enemy::LoadTierThreeSprites( TextureCodex& textureCodex )
{
	GameTextureTypes spriteTypes[ 3 ] = { GameTextureTypes::EnemyThirdFirst, GameTextureTypes::EnemyThirdSecond, GameTextureTypes::Explosion };
	LoadSprites( textureCodex, spriteTypes );
}

void Enemy::SwapMovementSprite()
{
	if( currentSprite == Sprites::Contract )
	{
		currentSprite = Sprites::Expand;
	}
	else if( currentSprite == Sprites::Expand )
	{
		currentSprite = Sprites::Contract;
	}
}