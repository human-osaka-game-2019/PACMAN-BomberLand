#include "Bomb.h"
#include "../Utility/Vec.h"
#include "../Utility/Size.h"

BOMB::BOMB()
{
	is_Dead = false;
	pos.X = 693;
	pos.Y = 824;
	size.Width = 80;
	size.Height = 80;
}

BOMB::~BOMB()
{

}


