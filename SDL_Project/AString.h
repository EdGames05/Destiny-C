#ifndef ASTRING_H_
#define ASTRING_H_


class AString
{
private:
	char* cadena;

	// Funciones
	const char* concatenar(const char* str1, const char* str2);
public:
	AString();
	AString(char* str);
	AString(const AString &str);
	//~AString();

	// Funciones

	char* obtenerChar();
	const char* setAString(const char* str);
	//Operadores

	//AString& operator=(AString &str);
	AString& operator=(char* str);
	void operator+(const char* str);
protected:
};

#endif // ASTRING_H_