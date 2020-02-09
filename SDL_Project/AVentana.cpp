#include "AVentana.h"

AVentana::AVentana()
{
	this->tipoRender = 0;
	this->nombreVentana.setAString("AVentana SDL");
	this->ancho = 700;
	this->alto = 600;
	this->mostrarErrores = false;
}

AVentana::AVentana(AString nombreAVentana)
{
	this->nombreVentana = nombreAVentana;
	this->ancho = 700;
	this->alto = 600;
	this->tipoRender = 0;
	this->mostrarErrores = false;
}

void AVentana::setMostrarErrores(bool valor)
{
	this->mostrarErrores = valor;
}

void AVentana::guardaMuestraError(AString error)
{
	if (this->mostrarErrores)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", error.obtenerChar(), NULL);
	}
	msgError = error;
}

void AVentana::guardaMuestraError(const char* error)
{
	if (this->mostrarErrores)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", error, NULL);
	}
	msgError.setAString(error);
}

const char* AVentana::getError()
{
	return this->msgError.obtenerChar();
}

AString AVentana::getErrorASTR(void)
{
	return this->msgError;
}

bool AVentana::inicializar(float ancho, float alto)
{
	if (termino)
	{
		guardaMuestraError("Error: La AVentana ya está inicializada.");
		return true;
	}
	termino = false;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		guardaMuestraError(SDL_GetError());
		SDL_Quit();
		termino = true;
		return false;
	}
	else
	{
		this->ancho = ancho;
		this->alto = alto;
		this->mainW = SDL_CreateWindow(this->nombreVentana.obtenerChar(),
										SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED,
										ancho, alto,
										SDL_WINDOW_SHOWN);
		
		// En está parte define como se va a renderizar toda la ventana
		// Si el tipo de render no es establecido por defecto es por hardware
		switch (this->tipoRender)
		{
		case RENDER_POR_HARDWARE:
		{
			this->render = SDL_CreateRenderer(mainW, -1, SDL_RENDERER_ACCELERATED);
			break;
		}
		case RENDER_POR_SOFTWARE:
		{
			this->render = SDL_CreateRenderer(mainW, -1, SDL_RENDERER_SOFTWARE);
			break;
		}
		}

		// Aquí se crea el bucle infinito para actualizaar
		this->buclePrincipal();

		return true;
	}
}

bool AVentana::inicializar(AString nombreAVentana, float ancho, float alto)
{
	if (termino)
	{
		guardaMuestraError("Error: La AVentana ya está inicializada.");
		return true;
	}
	termino = false;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		guardaMuestraError(SDL_GetError());
		SDL_Quit();
		termino = true;
		return false;
	}
	else
	{
		this->ancho = ancho;
		this->alto = alto;
		this->mainW = SDL_CreateWindow(nombreAVentana.obtenerChar(),
										SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED,
										ancho, alto,
										SDL_WINDOW_SHOWN);

		// En está parte define como se va a renderizar toda la ventana
		// Si el tipo de render no es establecido por defecto es por hardware
		switch (this->tipoRender)
		{
			case RENDER_POR_HARDWARE:
			{
				this->render = SDL_CreateRenderer(mainW, -1, SDL_RENDERER_ACCELERATED);
				break;
			}
			case RENDER_POR_SOFTWARE:
			{
				this->render = SDL_CreateRenderer(mainW, -1, SDL_RENDERER_SOFTWARE);
				break;
			}
		}

		// Aquí se crea el bucle infinito para actualizaar
		this->buclePrincipal();

		return true;
	}
}

inline void AVentana::setTipoRender(TipoRender tipo)
{
	this->tipoRender = tipo;
}

void AVentana::destruirVentana()
{
	// Destruye todo el render
	SDL_DestroyRenderer(this->render);
	// Y Destruye la ventana
	SDL_DestroyWindow(this->mainW);
	// Libera memoria
	SDL_Quit();
}

void AVentana::buclePrincipal()
{
	while (!termino)
	{
		if (SDL_PollEvent(&eventos))
		{
			this->tipoEvento = eventos.type;

			// Si el evento es igual a cerrar AVentana entonces termina el proceso
			if (tipoEvento == SDL_QUIT)
			{
				termino = true;
			}

		}

		this->actualizar();
	}
}

inline SDL_Window* AVentana::getVentana()
{
	return this->mainW;
}

inline SDL_Renderer* AVentana::getRender()
{
	return this->render;
}

inline float AVentana::getAnchoVentana()
{
	return this->ancho;
}

inline float AVentana::getAltoVentna()
{
	return this->alto;
}

inline void AVentana::actualizar()
{
	// Limpia el render
	SDL_RenderClear(this->render);
	// Reconstruye el render
	SDL_RenderPresent(this->render);
}