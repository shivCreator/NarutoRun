#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<vector>

using namespace sf;

int main()
{
    RenderWindow ninjaWar(VideoMode(800,600),"Test");
    Texture rocks;
    rocks.loadFromFile("Obstacles.png");

//    RectangleShape Obs1;
//    Obs1.setSize(Vector2f(150, 150));
//    Obs1.setTexture(&rocks);
//    Obs1.setTextureRect(IntRect(0,0,150,150));
//    Obs1.setPosition(Vector2f(100, 100));



    Texture ninja;
    if(!ninja.loadFromFile("naru2.png"))
        return EXIT_FAILURE;
    Sprite Naruto;
    int highNaruto = 0;
    int wideNaruto = 0;
    bool lRun = false;
    bool rRun = false;
    bool dRun = false;
    bool uRun = false;
    bool relaxed = true;
    Naruto.setTexture(ninja);

    while(ninjaWar.isOpen())
    {
        Event e;
        while(ninjaWar.pollEvent(e))
        {
            if((e.type == Event::Closed)||(Keyboard::isKeyPressed(Keyboard::Enter)))
                ninjaWar.close();
            if(Keyboard::isKeyPressed(Keyboard::A)){lRun = true; relaxed = false;}
            if(Keyboard::isKeyPressed(Keyboard::D)){rRun = true; relaxed = false;}
            if((e.type==Event::KeyReleased)&&((e.key.code == Keyboard::A)||(e.key.code == Keyboard::D)))
            {
                lRun = false;
                rRun = false;
                wideNaruto = 1;
            }
            if(Keyboard::isKeyPressed(Keyboard::S))
            {
                dRun = true;
            }
            if(e.type==Event::KeyReleased && e.key.code==Keyboard::S)
            {
                lRun = false;
                rRun = false;
                dRun = false;
                uRun = false;
                relaxed = true;
            }
            if(Keyboard::isKeyPressed(Keyboard::W))
            {
                uRun = true;
            }
            if(e.type==Event::KeyReleased && e.key.code==Keyboard::W)
            {
                lRun = false;
                rRun = false;
                dRun = false;
                uRun = false;
                relaxed = true;
            }
            if(Naruto.getPosition().x<-34.f){Naruto.setPosition(Vector2f(-34.f,Naruto.getPosition().y));}
            if(Naruto.getPosition().x>738.f){Naruto.setPosition(Vector2f(738.f,Naruto.getPosition().y));}
            if(Naruto.getPosition().y<0.f){Naruto.setPosition(Vector2f(Naruto.getPosition().x, 0.f));}
            if(Naruto.getPosition().y>500.f){Naruto.setPosition(Vector2f(Naruto.getPosition().x, 500.f));}

        }
     //warWdates
     //NarutoMotion
     if(lRun){highNaruto = 2; wideNaruto++; Naruto.move(-2.f,0.f);}
     if(rRun){highNaruto = 0; wideNaruto++; Naruto.move(2.0f,0.f);}
     if(dRun){highNaruto = 1; wideNaruto=0; Naruto.move(0.0f,2.f);}
     if(uRun){highNaruto = 1; wideNaruto=0; Naruto.move(0.f,-2.f);}
     if(relaxed){highNaruto=1;wideNaruto=0;}
     if(wideNaruto>8){wideNaruto=1;}
     //Naruto
    Naruto.setTextureRect(IntRect(80*wideNaruto,96*highNaruto, 80,96));

    //collision
        //clear
        ninjaWar.clear(Color::White);
        ninjaWar.draw(Naruto);
//        ninjaWar.draw(Obs1);
        ninjaWar.display();
    }
    return 0;
}
