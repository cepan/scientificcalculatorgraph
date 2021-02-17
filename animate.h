#ifndef ANIMATE_H
#define ANIMATE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
#include <queue.h>
#include <rpn.h>
class Animate
{
public:
    Animate();
    void run(RPN r);
    void processEvents();
    void update();
    void render(RPN r);
    void Draw(RPN r);
private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;
    vector<sf::CircleShape> c;
    //The little red dot
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen

    queue <token*> q;
    string s;
    float lo= -3;                       //interval
    float hi= 3;
};
string mouse_pos_string(sf::RenderWindow& window);

#endif // ANIMATE_H
