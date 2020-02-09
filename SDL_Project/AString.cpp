#include "AString.h"
#include <cstring>
#include <memory>

AString::AString()
{
	
}

AString::AString(char* str)
{
	strcpy(this->cadena, str);
}

AString::AString(const AString &str)
{
	int n = strlen(str.cadena);
	cadena = new char[n + 1];
	strcpy(cadena, str.cadena);
}

/*AString::~AString()
{
	// Libero memoria de la cadena y luego borro el objeto
	free(&cadena);
	delete this;
}*/


const char* AString::concatenar(const char * str1, const char * str2)
{
	//Asigno el tamaño de la primera cadena + el tamaño de la segunda
	char *cadena_final = (char*)malloc(1 + strlen(str1) + strlen(str2));
	// Copio la primera
	strcpy(cadena_final, str1);
	// concateno la segunda con strcat
	strcat(cadena_final, str2);
	// Libero memoria de las dos cadenas y devuelvo la cadena concatenada
	free(&str1);
	free(&str2);
	return cadena_final;
}

const char * AString::setAString(const char * str)
{
	delete this->cadena;
	int n = strlen(str);
	cadena = new char[n + 1];
	strcpy(cadena, str);
	return cadena;
}

char * AString::obtenerChar()
{
	return this->cadena;
}

//Pendiente arreglar
/*AString& AString::operator=(AString &str)
{
	strcpy(cadena,str.cadena);
	return *this;
}*/

void AString::operator+(const char* str)
{
	strcpy(cadena, this->concatenar(cadena, str));
}


AString& AString::operator=(char* str) 
{
	setAString(str);
	return *this;
}