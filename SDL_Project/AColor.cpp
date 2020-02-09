#include "AColor.h"

AColor::AColor()
{
	setColor(DEFECTO);
}

AColor* AColor::getAColor()
{
	return this;
}

inline void AColor::setColor(uint r, uint g, uint b, uint a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

inline void AColor::setColor(Colores color)
{
	switch (color)
	{
		case DEFECTO:
		{
			this->r = 255;
			this->g = 255;
			this->b = 255;
			this->a = 0;
			break;
		}
		case BLANCO:
		{
			this->r = 255;
			this->g = 255;
			this->b = 255;
			this->a = 0;
			break;
		}
		case NEGRO:
		{
			this->r = 0;
			this->g = 0;
			this->b = 0;
			this->a = 0;
			break;
		}
		case AZUL:
		{
			this->r = 0;
			this->g = 0;
			this->b = 255;
			this->a = 0;
			break;
		}
		case ROJO:
		{
			this->r = 255;
			this->g = 0;
			this->b = 0;
			this->a = 0;
			break;
		}
		case VERDE:
		{
			this->r = 0;
			this->g = 255;
			this->b = 0;
			this->a = 0;
			break;
		}
		case CELESTE:
		{
			this->r = 135;
			this->g = 206;
			this->b = 235;
			this->a = 0;
			break;
		}
	}
}

inline void AColor::renderizarColor(SDL_Renderer* render)
{

}

inline void AColor::renderizarColor(Colores color, SDL_Renderer* render)
{

}

inline void AColor::renderizarColor(SDL_Renderer* render,uint r, uint g, uint b, uint a)
{

}