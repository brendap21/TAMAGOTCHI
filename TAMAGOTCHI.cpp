#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

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

int main()
{
    RenderWindow window(VideoMode(800, 600), "STAR WARS TAMAGOTCHI");

    //BASE
    RectangleShape fondo(Vector2f(800, 600));
    RectangleShape r2Base(Vector2f(800, 600));
    //EMOTIONS
    CircleShape emocionFeliz(115, 112);
    CircleShape emocionTriste(115, 112);
    CircleShape emocionEnojado(115, 112);
    CircleShape emocionMuerto(115, 112);
    //TASKS
    RectangleShape r2Alimento(Vector2f(800, 600));
    RectangleShape r2Ejercicio(Vector2f(800, 600));
    RectangleShape r2Limpieza(Vector2f(800, 600));
    RectangleShape r2Pegar(Vector2f(800, 600));
    RectangleShape r2Muerte(Vector2f(800, 600));


    //FONDO GENERAL
    Texture texture1;
    if (!texture1.loadFromFile("img/ILUSTRACIONES_FONDO.png")) {
        system("echo No se pudo cargar el fondo.&pause");
        return EXIT_FAILURE;
    }
    else
        texture1.loadFromFile("img/ILUSTRACIONES_FONDO.png");
        fondo.setTexture(&texture1);
    Sprite sprite1(texture1);

    //R2 BASE
    Texture texture2;
    if (!texture2.loadFromFile("img/ILUSTRACIONES_TAMAGOCHI.png")) {
        system("echo No se pudo cargar la textura de r2 base.&pause");
        return EXIT_FAILURE;
    }
    else
        texture2.loadFromFile("img/ILUSTRACIONES_TAMAGOCHI.png");
    r2Base.setTexture(&texture2);
    Sprite sprite2(texture2);
    sprite2.setPosition(25,-25);

    //FELICIDAD
    Texture texture3;
    if (!texture3.loadFromFile("img/ILUSTRACIONES_FELIZ.png")) {
        system("echo No se pudo cargar la textura de felicidad.&pause");
        return EXIT_FAILURE;
    }
    else
        texture3.loadFromFile("img/ILUSTRACIONES_FELIZ.png");
    emocionFeliz.setTexture(&texture3);
    Sprite sprite3(texture3);
    sprite3.setPosition(672, 490);

    //TRISTEZA
    Texture texture4;
    if (!texture4.loadFromFile("img/ILUSTRACIONES_TRISTE.png")) {
        system("echo No se pudo cargar la textura de Tristeza.&pause");
        return EXIT_FAILURE;
    }
    else
        texture4.loadFromFile("img/ILUSTRACIONES_TRISTE.png");
    emocionTriste.setTexture(&texture4);
    Sprite sprite4(texture4);
    sprite4.setPosition(672, 490);

    //ENOJO
    Texture texture5;
    if (!texture5.loadFromFile("img/ILUSTRACIONES_ENOJADO.png")) {
        system("echo No se pudo cargar la textura de Enojo.&pause");
        return EXIT_FAILURE;
    }
    else
        texture5.loadFromFile("img/ILUSTRACIONES_ENOJADO.png");
    emocionEnojado.setTexture(&texture5);
    Sprite sprite5(texture5);
    sprite5.setPosition(672, 490);

    //MUERTO
    Texture texture6;
    if (!texture6.loadFromFile("img/ILUSTRACIONES_MUERTO.png")) {
        system("echo No se pudo cargar la textura de Muerte.&pause");
        return EXIT_FAILURE;
    }
    else
        texture6.loadFromFile("img/ILUSTRACIONES_MUERTO.png");
    emocionMuerto.setTexture(&texture6);
    Sprite sprite6(texture6);
    sprite6.setPosition(672, 490);

    //ALIMENTO
    Texture texture7;
    if (!texture7.loadFromFile("img/ILUSTRACIONES_ALIMENTO.png")) {
        system("echo No se pudo cargar la textura de Alimento.&pause");
        return EXIT_FAILURE;
    }
    else
        texture7.loadFromFile("img/ILUSTRACIONES_ALIMENTO.png");
    r2Alimento.setTexture(&texture7);
    Sprite sprite7(texture7);
    sprite7.setPosition(25, -25);

    //EJERCICIO
    Texture texture8;
    if (!texture8.loadFromFile("img/ILUSTRACIONES_EJERCICIO.png")) {
        system("echo No se pudo cargar la textura de Ejercicio.&pause");
        return EXIT_FAILURE;
    }
    else
        texture8.loadFromFile("img/ILUSTRACIONES_EJERCICIO.png");
    r2Ejercicio.setTexture(&texture8);
    Sprite sprite8(texture8);
    sprite8.setPosition(25, -25);

    //LIMPIEZA
    Texture texture9;
    if (!texture9.loadFromFile("img/ILUSTRACIONES_LIMPIEZA.png")) {
        system("echo No se pudo cargar la textura de Limpieza.&pause");
        return EXIT_FAILURE;
    }
    else
        texture9.loadFromFile("img/ILUSTRACIONES_LIMPIEZA.png");
    r2Limpieza.setTexture(&texture9);
    Sprite sprite9(texture9);
    sprite9.setPosition(25, -25);

    //PEGAR
    Texture texture10;
    if (!texture10.loadFromFile("img/ILUSTRACIONES_PEGAR.png")) {
        system("echo No se pudo cargar la textura de Golpe.&pause");
        return EXIT_FAILURE;
    }
    else
        texture10.loadFromFile("img/ILUSTRACIONES_PEGAR.png");
    r2Pegar.setTexture(&texture10);
    Sprite sprite10(texture10);
    sprite10.setPosition(25, -25);

    //MUERTE
    Texture texture11;
    if (!texture11.loadFromFile("img/ILUSTRACIONES_MUERTE.png")) {
        system("echo No se pudo cargar la textura de Muerte.&pause");
        return EXIT_FAILURE;
    }
    else
        texture11.loadFromFile("img/ILUSTRACIONES_MUERTE.png");
    r2Muerte.setTexture(&texture11);
    Sprite sprite11(texture11);
    sprite11.setPosition(25, -25);

    //MUSIC
    Music music;
    if (!music.openFromFile("audio/StarWarsAudio.wav")) {
        system("echo No se pudo cargar el audio.&pause");
        return EXIT_FAILURE;
    }
    else music.openFromFile("audio/StarWarsAudio.wav");
    music.play();

    Thread thread(&instructions);
    thread.launch();

    window.setFramerateLimit(30);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {     
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::X) {
                    window.close();
                    cout << ("\n\nPresiono la tecla X\n\n") << endl;
                }
            }
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite1);
        window.draw(sprite2);
       // window.draw(sprite9);
       // window.draw(sprite6);
        window.display();
    }
    return EXIT_SUCCESS;
}