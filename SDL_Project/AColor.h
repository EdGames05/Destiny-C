#ifndef ACOLOR_H_
#define ACOLOR_H_

#include "Inclusiones.h"

// Esto de AColor tendra que funcionar con mis propios rgb
class AColor
{
private:
	typedef unsigned int uint;

	uint r = 0;
	uint g = 0;
	uint b = 0;
	uint a = 0;
public:
	AColor();
	AColor* getAColor();

	// Enumeracion de colores
	static enum Colores
	{
		//El por defecto es blanco
		DEFECTO,
		BLANCO,
		NEGRO,
		AZUL,
		ROJO,
		VERDE,
		CELESTE
	};

	//Está función modifica el color pero no lo establece para pintar en SDL
	inline void setColor(uint r, uint g, uint b, uint a);
	//Está función modifica el color pero no lo establece para pintar en SDL
	inline void setColor(Colores color);
	// Prepara el color para ser pintado con SDL
	inline void renderizarColor(SDL_Renderer* render);
	// Establece y Prepara el color para ser pintado con SDL
	inline void renderizarColor(Colores color, SDL_Renderer* render);
	// Establece y Prepara el color para ser pintado con SDL
	inline void renderizarColor(SDL_Renderer* render,uint r, uint g, uint b, uint a);
};

#endif // ACOLOR_H_