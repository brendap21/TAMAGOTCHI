#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Node.h"

using namespace std;
using namespace sf;


void instructions() {
    cout << ("\n\nBienvenido a Star Wars Tamagotchi.\n\n") << endl;
    cout << ("\n\nPresione la tecla Q para ejercitar a R2D2.\n") << endl;
    cout << ("Presione la tecla W para darle una limpieza a R2D2.\n") << endl;
    cout << ("Presione la tecla E para alimentar a R2D2.\n") << endl;
    cout << ("Presione la tecla R para golpear a R2D2.\n") << endl;
    cout << ("Presione la tecla X para salir del juego.\n") << endl;
}

    //BASE


int main()
{
    RenderWindow window(VideoMode(800, 600), "STAR WARS TAMAGOTCHI");
    
    /*RectangleShape fondo(Vector2f(800, 600));
    RectangleShape ruta_arturo(Vector2f(800, 600));
    CircleShape ruta_estado(115, 112);*/

    /*Texture texture1;
    if (texture1.loadFromFile("img/ILUSTRACIONES_FONDO.png")) {
        fondo.setTexture(&texture1);
        Sprite sprite1(texture1);
    }*/

    //MUSIC
    Music music;
    if (!music.openFromFile("audio/StarWarsAudio.wav")) {
        system("echo No se pudo cargar el audio.&pause");
        return EXIT_FAILURE;
    }
    else music.openFromFile("audio/StarWarsAudio.wav");
    music.play();

    Node* estadoFeliz = new Node("img/ILUSTRACIONES_FONDO.png", "img/ILUSTRACIONES_TAMAGOCHI.png", "img/ILUSTRACIONES_FELIZ.png",0);
    Node* estadoActual = estadoFeliz;
    Node* estadoEnojado = new Node("img/ILUSTRACIONES_FONDO.png", "img/ILUSTRACIONES_PEGAR.png", "img / ILUSTRACIONES_ENOJADO.png",2);
    Node* estadoTriste = new Node("img/ILUSTRACIONES_FONDO.png", "img/ILUSTRACIONES_TRISTE-13.png", "img/ILUSTRACIONES_TRISTE-11.png",1);
    Node* estadoFinal = new Node("img/ILUSTRACIONES_FONDO.png", "img/ILUSTRACIONES_MUERTE.png", "img/ILUSTRACIONES_MUERTO.png",3);
    
    Node* estados[4][4] = {
        {estadoFeliz,estadoTriste,estadoFeliz,estadoFeliz},
        {estadoFeliz,estadoEnojado,estadoTriste,estadoFeliz},
        {estadoFeliz,estadoFinal,estadoTriste,estadoEnojado},
        {estadoFinal,estadoFinal,estadoFinal,estadoFinal}
    };

    Thread thread(&instructions);
    thread.launch();

    window.setFramerateLimit(30);

    int opcion;
    while (window.isOpen())
    {
        Event event;
        opcion = -1;
        while (window.pollEvent(event))
        {     
            if (event.type == Event::KeyPressed) {
                
                if (event.key.code == Keyboard::Q) {
                    cout << ("\n\nPresiono la tecla Q\n\n") << endl;
                    opcion = 3;
                }
                if (event.key.code == Keyboard::W) {
                    cout << ("\n\nPresiono la tecla W\n\n") << endl;
                    opcion = 2;
                }
                if (event.key.code == Keyboard::R) {
                    cout << ("\n\nPresiono la tecla R\n\n") << endl;
                    opcion = 1;
                }
                if (event.key.code == Keyboard::E) {
                    cout << ("\n\nPresiono la tecla E\n\n") << endl;
                    opcion = 0;
                }
                if (event.key.code == Keyboard::X) {
                    window.close();
                    cout << ("\n\nPresiono la tecla X\n\n") << endl;
                }
                if (event.type == Event::Closed)
                window.close();
            }
        }
        estadoActual = estados[estadoActual->value][opcion];
        
        window.clear();
        window.draw(*estadoActual->sprite_arturo);
        window.display();
    }

    return EXIT_SUCCESS;
}