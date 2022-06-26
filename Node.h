#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Node
{
public:
	int value;
	Texture texture;
	Texture estado;
	//Sprite sprite_fondo;
	Sprite* sprite_arturo;

	Node(string fondo, string ruta_arturo, string ruta_estado, int v) {
		value = v;

		if (!texture.loadFromFile(fondo)) {
			system("echo No se pudo cargar la textura del fondo.&pause");
		}
		if (!texture.loadFromFile(ruta_arturo)) {
			system("echo No se pudo cargar la textura de R2.&pause");
		}
		if (!texture.loadFromFile(ruta_estado)) {
			system("echo No se pudo cargar la textura de emocion.&pause");
		}

		sprite_arturo = new Sprite(texture);
		//sprite_arturo->setTexture(&texture);

		//sprite_fondo;
		sprite_arturo->setPosition(0, 0);
		//sprite_estado.setPosition(672, 490);
	}

};

