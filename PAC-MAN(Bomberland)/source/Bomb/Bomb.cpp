#include "Bomb.h"
#include "../Utility/Vec.h"
#include "../Utility/Size.h"

BOMB::BOMB()
{
	is_Dead = false;
	pos.X = 643;
	pos.Y = 674;
	size.Width = 80;
	size.Height = 80;
}

BOMB::~BOMB()
{

}


