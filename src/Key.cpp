#include "Key.h"


void Key::handleCollision(Thief& gameObject)
{
	m_dispatched = CollisionStatus::Good;
	
	gameObject.handleCollision(*this);

	Thief* thiefptr = dynamic_cast<Thief*> (&gameObject);
	if (!thiefptr->getKey())
	{
		thiefptr->setKey(true);
			m_dispatched = CollisionStatus::Destroy;
	}
}

void Key::handleCollision(King& gameObject) { m_dispatched = CollisionStatus::Good; }
void Key::handleCollision(Mage& gameObject) { m_dispatched = CollisionStatus::Good; }
void Key::handleCollision(Warrior& gameObject) { m_dispatched = CollisionStatus::Good; }
void Key::handleCollision(Gnome& gameObject) { m_dispatched = CollisionStatus::Good; }


//sf::Texture img;
			//img.loadFromFile("thiefKey.png");
			//thiefptr->setSpriteTexture(img);