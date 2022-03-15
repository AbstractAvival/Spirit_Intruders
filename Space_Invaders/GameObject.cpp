#include "GameObject.h"

GameObject::GameObject( sf::Vector2< int > positionIn )
	:
	position( positionIn ),
	isDead( false )
{}

sf::Vector2< int > GameObject::GetPosition()
{
	return position;
}

void GameObject::SetPosition( sf::Vector2< int > newPosition )
{
	position = newPosition;
}

void GameObject::Kill()
{
	isDead = true;
}

bool GameObject::IsDead()
{
	return isDead;
}

void GameObject::LoadTestSprite( TextureCodex& textureCodex )
{
	sprites.emplace_back( sf::Sprite() );
	sprites[ ( int )currentSprite ].setTexture( textureCodex.GetGameTexture( GameTextureTypes::WhiteBox ) );
}