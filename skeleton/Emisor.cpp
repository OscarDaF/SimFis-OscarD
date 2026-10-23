#include "Emisor.h"

void Emisor::distUniforme()
{
	std::mt19937 gen (rd());
	std::uniform_int_distribution<> dist(1,6); //LIMITES
}

void Emisor::distGaussiana()
{
	std::mt19937 gen(rd());
	std::normal_distribution<> dist(); //MEDIANA , DESVIACIÓN TÍPICA
}
