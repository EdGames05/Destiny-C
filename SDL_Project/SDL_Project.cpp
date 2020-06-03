// SDL_Project.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//*********************************************************************************************
/************ Si se va a cambiar de 64 a 32 bits también cambiar la .dll  *********************/

#include <iostream>
#include "AVentana.h"

int main(int argc, char* args[])
{
	AString nombreVentana;
	nombreVentana.setAString("Prueba SDL");
	printf(nombreVentana.obtenerChar());
	AVentana ventana(nombreVentana);
	ventana.setMostrarErrores(true);
	ventana.inicializar(700,600);
	return 0;
}