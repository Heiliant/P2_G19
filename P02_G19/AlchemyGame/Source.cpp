﻿#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <windows.h>

enum class status
{
	_Clave1,
	_Clave2,
	_Value
};

struct pairHash {

	std::pair<std::string, std::string> a;

	size_t operator ()(const std::pair<std::string, std::string> &b) const {
		return ((std::hash<std::string>()(b.first)) ^ ((std::hash<std::string>()(b.second)) << 1)) >> 1;
	}
	bool operator==(const std::pair<std::string, std::string> &c) const {
		return ((a.first == c.first) && (a.second == c.second));
	}

};


void main()
{

	status componente = status::_Value;

	std::string linea;
	std::ifstream elements;
	elements.open("elements.dat");

	std::vector <std::string> formulas;
	std::unordered_map <std::pair<std::string, std::string>, std::string, pairHash> MapaFormulas;

	while (getline(elements, linea))
	{
		formulas.push_back(linea);
	}
	elements.close();


	std::string key;
	std::string key2;
	std::string content;
	for (std::string e : formulas) //recorrerá el vector formulas y en cada iteracion e será la string de esa posicion
	{
		for (char i : e) //recorrera la string e y en cada iteracion i sera una letra de esta
		{
			switch (i) { //mientras recorro la string, los chars pueden valer '=', '+', ' ' o una letra cualquiera.
			case ('='):
				componente = status::_Clave1; //si he leído un igual, se que estoy empezando a leer la key1, así que actualizo el 
											  //status a _Clave1. Como lo primero que hay en la línea siempre es el value, el 
											  //valor de status es _Value por defecto.
				break;
			case('+'):
				componente = status::_Clave2; //si he leído el '+', lo mismo que antes pero a _Clave2
				break;
			case(' '): //este caso me asegura que las claves no se encontrarán rodeadas por espacios en blanco.
					   //cosa importante para poder después acceder a los valores.
				break;
			default:
				switch (componente) {  //dependiendo del valor de status guardo los chars en un container distinto
				case(status::_Value):
					content.push_back(i);
					break;
				case(status::_Clave1):
					key.push_back(i);
					break;
				case(status::_Clave2):
					key2.push_back(i);
					break;
				}
				break;
			}
		} //una vez se acaba el foreach y he leído todos los chars de la línea, actualizo el status para que en la siguiente
		  //iteración vuelva a guardar los chars en el container "content" hasta que se encuentr el '='
		componente = status::_Value;
		//Meto el pair con el pair de strings (keys) y el string (value)
		MapaFormulas.insert(std::pair <std::pair <std::string, std::string>, std::string>(std::pair <std::string, std::string>(key, key2), content));
		//y reseteo los contenedores donde se guardan las keys y el value.
		content.erase();
		key.erase();
		key2.erase();
	}

	componente = status::_Value;

	for (std::string i : formulas) {
		std::string valueTemp = "";
		std::string keyOneTemp = "";
		std::string keyTwoTemp = "";
		for (int z = 0; z < i.size(); ++z) {
			switch (i.at(z)) {
			case ' ':
				break;
			case '+': componente = status::_Clave2;
				break;
			case '=': componente = status::_Clave1;
				break;
			default: switch (componente) {
			case status::_Clave1: keyOneTemp.push_back(i.at(z));
				break;
			case status::_Clave2: keyTwoTemp.push_back(i.at(z));
				break;
			case status::_Value: valueTemp.push_back(i.at(z));
				break;
			}
					 break;
			}
		}
		std::string valTemp_mymap = MapaFormulas.at(std::pair<std::string, std::string>(keyOneTemp, keyTwoTemp));
		if (valTemp_mymap != valueTemp) {
			system("pause");
		}
		componente = status::_Value;
		if (i == formulas.back()) {
			valueTemp.clear();
			keyOneTemp.clear();
			keyTwoTemp.clear();
		}
	}

	formulas.clear();
	formulas.shrink_to_fit();

	//Ahora todos los elementos están guardados en el mapa MapaFormulas y nos hemos asegurado de que se han guardado bien

	std::vector<std::string> elements_basics = { "Fire", "Water", "Earth", "Air" };

	std::vector <std::string> currentList(elements_basics);


	std::string prueba;


}


void leerComando(std::string &comandoJugador) //esta a medias, la ire haciendo a medida que tengamos las funciones
{
	std::cin >> comandoJugador;
	std::getline(std::cin, comandoJugador);
	std::cin.clear(); // clears all error state flags
					  // extracts characters from the input buffer and discards them
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::size_t encontrado = comandoJugador.find("add");

	if (encontrado != std::string::npos)
	{
		std::string ordenAdd;
		ordenAdd = comandoJugador.substr(encontrado);

		ordenAdd.substr(encontrado);
	}

	encontrado = comandoJugador.find("delete");

	if (encontrado != std::string::npos) {

	}

	encontrado = comandoJugador.find("info");

	if (encontrado != std::string::npos) {

	}

	encontrado = comandoJugador.find("clean");
	if (encontrado != std::string::npos) {

	}

	encontrado = comandoJugador.find("sort");
	if (encontrado != std::string::npos) {

	}


	if (comandoJugador == "add basics " || comandoJugador == "addbasics" || comandoJugador == "Add basics")
	{
		addBasics();
	}

	if (comandoJugador == "delete" || comandoJugador == "Delete")
	{
		std::cin >> a;
		std::cin.clear();

		BorrarElement(a);
	}

	if (comandoJugador == "info")
	{
		std::cin >> a;

		if (a >= 0 && a <= currentList.size())
		{
			informasao(a);
		}
	}

	if (comandoJugador == "clean" || comandoJugador == "Clean")
	{
		clean(currentList);
	}

	if (comandoJugador == "help" || comandoJugador == "Help")
	{
		Tutorial();
	}
}

void add(int numero) //duplica un elemento de la lista
{
	currentList.push_back(currentList[numero]);
}

void addBasics()
{
	for (int i = 0; i < elements_basics.size(); i++)
	{
		std::cout << elements_basics[i];
	}

}

void BorrarElement(int numero)
{
	currentList.erase(currentList[numero]);
}

void informasao(int indice)
{
	std::string concatenacion = currentList[indice];

	ShellExecute(NULL, "open", "https://en.wikipedia.org/wiki/" + concatenacion, NULL, NULL, SW_SHOWNORMAL);
}

void clean(std::vector<std::string>hola)
{
	std::string repetidor = hola[0];

	for (int i = 0; i<hola.size(); i++)
	{
		if (hola[i] == repetidor)
		{
			hola.erase(hola[i]);
		}
	}
}

void Tutorial()
{
	std::cout << "El jugador empieza con los 4 elementos básicos: aire​, fuego​, tierra ​y agua​" << std::endl;
	std::cout << "Cuando se combinan 2 elementos y estos producen un resultado, se suma 1 a la	puntuación " << std::endl;
	std::cout << "si el nuevo elemento no se encuentra en la lista de elementos del jugador." << std::endl;
	std::cout << "No se pueden combinar 2 elementos que ocupen la misma posición en la lista.​" << std::endl;
	std::cout << std::endl;
	std::cout << "Si el jugador escribe “add​” y el número de un elemento disponible en la lista, se añade una copia del elemento al que hace referencia dentro de la lista.​" << std::endl;
	std::cout << std::endl;
	std::cout << "Si el jugador escribe “add basics​” se añaden nuevas instancias de los 4 elementos básicos dentro de la lista de elementos.​" << std::endl;
	std::cout << std::endl;
	std::cout << "Si el jugador escribe “delete​” y el número de un elemento disponible en la lista, se elimina el elemento al que hace referencia.​" << std::endl;
	std::cout << std::endl;
	std::cout << "Si el jugador escribe “info​” y el número de un elemento disponible en la lista, se abre en el navegador la página de Wikipedia(u otra enciclopedia)" << std::endl;
	std::cout << "con la información acerca del elemento.​" << std::endl;
	std::cout << std::endl;
	std::cout << "Si el jugador escribe “sort​” se ordenan todos los elementos por orden alfabético." << std::endl;
	std::cout << std::endl;
	std::cout << "Si el jugador escribe “clean​” se eliminan todos los elementos que estén repetidos en la lista." << std::endl;
	std::cout << std::endl;
	std::cout << "Si el jugador escribe “help​” se muestra un tutorial con todas las acciones previamente mencionadas que puede realizar el jugador durante la partida." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

