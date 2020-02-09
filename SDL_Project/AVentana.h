#ifndef AVENTANA_H_
#define AVENTANA_H_

#include "Inclusiones.h"
#include "AString.h"
#include "AColor.h"

//struct SDL_Window;
//struct SDL_Renderer;

class AVentana
{
private:
	SDL_Window* mainW;
	SDL_Renderer *render;
	
	AColor* color;
	AString msgError;
	AString nombreVentana;
	bool mostrarErrores;
	float ancho = 700;
	float alto = 600;
	int tipoRender = 0;

	//*******Eventos*********
	SDL_Event eventos;
	int tipoEvento;
	bool termino;
	//***********************

	// Funciones
	void guardaMuestraError(AString error);							//Guarda y muestra o no muestra los errores
	void guardaMuestraError(const char* error);						// Guarda y muestra o no muestra los errores
	void buclePrincipal();											//Bucle principal de la ventana o render
public:
	//*****Enumeraciones*******
	static enum TipoRender
	{
		RENDER_POR_SOFTWARE,
		RENDER_POR_HARDWARE
	};
	//*************************

	AVentana();
	AVentana(AString nombreVentana);
	void setMostrarErrores(bool valor);								// Los errores por defecto no se mostraran
	const char* getError();
	AString getErrorASTR(void);										// Retorna el error de tipo AString

	bool inicializar(float ancho, float alto);						// Inicializa una ventana con valores asignados
	bool inicializar(AString nombreVentana, float ancho, float alto);
	inline void setTipoRender(TipoRender tipo);						// Establece si el render es por hardware o software
	void destruirVentana();											// Destruye todos los objetos para cerrar la ventana
	inline SDL_Window* getVentana();
	inline SDL_Renderer* getRender();
	inline float getAnchoVentana();
	inline float getAltoVentna();
	inline void actualizar();
protected:
};

#endif // AVENTANA_H_
