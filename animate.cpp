#include "animate.h"
#include<constant.h>
#include<iostream>
using namespace std;
Animate::Animate(){


//    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snoop the Double G!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    window.setFramerateLimit(60);

    mouseIn = true;


    //mouse tracking point red dot
    mousePoint = sf::CircleShape();
    mousePoint.setRadius(3.0);
    mousePoint.setFillColor(sf::Color::Red);






//    cout<<"animate instantiated successfully."<<endl;
    cout<<endl<<"========================================="<<endl;



}

void Animate::Draw(RPN r){
    /*draw will take care of draw the x-axis, y-axis, and the graph
     *
    */
    bool debug = false;
    //Look at the data and based on the data, draw shapes on window object.
    //x- axis set on the window and set the color, the form of the axis (linestrip)
    sf::VertexArray x_axis(sf::LinesStrip,2);
    x_axis[0].position = sf::Vector2f(0, SCREEN_HEIGHT/2);
    x_axis[0].color = sf::Color::White;
    x_axis[1].position = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT/ 2);
    x_axis[1].color = sf::Color::White;

    //drawing y_axis
    //y- axis set on the window and set the color(white), the form of the axis (linestrip)

    sf::VertexArray y_axis(sf::LinesStrip, 2);
    y_axis[0].position = sf::Vector2f(SCREEN_WIDTH/2, 0);
    y_axis[0].color = sf::Color::White;
    y_axis[1].position = sf::Vector2f(SCREEN_WIDTH/ 2, SCREEN_HEIGHT);
    y_axis[1].color = sf::Color::White;
    window.clear();


    q= r.infix_to_postfix(r.read());// shunting yard

    for(int i= 0;i<SMOOTH_POINT;i++){   //generate the graphing points on the
                                        //graph based on the smount of points
        int ratio=SCREEN_WIDTH/(hi-lo);
        float x=lo+ (hi-lo)*i/SMOOTH_POINT;
        float y= r.eval(q,x);

        x= x*ratio+SCREEN_WIDTH/2;          //convert the graphing points to pixel
        y= -(y*ratio) +SCREEN_HEIGHT/2;


        sf::CircleShape temp(2);             //store the pixel points into a vector
        temp.setPosition(x,y);
        temp.setFillColor(sf::Color::White);
        c.push_back(temp);
    }

//draw each circle at each coordinate
    for(int i = 0; i<c.size();i++){
        window.draw(c.at(i));
    }
    c.clear();
    //x,y- axis drawn
window.draw(y_axis);
window.draw(x_axis);

//    system.Draw(window);

// draw the red mouse point
    if (mouseIn){
        window.draw(mousePoint);
    }


//    - - - - - - - - - - - - - - - - - - -
//    getPosition() gives you screen coords, getPosition(window) gives you window coords
//    cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
//    - - - - - - - - - - - - - - - - - - -

//    drawing Test: . . . . . . . . . . . .
//    This is how you draw text:)
//    window.draw(myTextLabel);
//    . . . . . . . . . . . . . . . . . . .

}
void Animate::update(){
    //cause changes to the data for the next frame
//    system.Step(command);
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

    }

}
void Animate::render(RPN r){
    window.clear();//clearing the window
    Draw(r);       //draw the window
    window.display();//display the window

}
void Animate::processEvents(){
    sf::Event event;
    float mouseX, mouseY;
    char r ='c';
    bool debug = false;
    string s;
    while (window.pollEvent(event))//or waitEvent
        {
        // check the type of the event...
            switch (event.type)
            {
            // window closed
            case sf::Event::Closed://
                window.close();
                throw  r;
                break;

            // key pressed
            case sf::Event::KeyPressed:
                switch(event.key.code){
                 case sf::Keyboard::Left:
                    command = 4;
                    break;
                case sf::Keyboard::Right:
                    command = 6;
                    break;
                case sf::Keyboard::Escape://esc close the window
                    window.close();               
                 break;
                case sf::Keyboard::Hyphen:// zoom out
                    hi= hi*1/0.8;
                    lo=lo*1/0.8;
                    if(debug)
                    {
                        cout<<"zoom in"<<endl;
                        cout<<"hi:  "<<hi<<"    lo: "<<lo<<endl;
                    }
                    break;
                case sf::Keyboard::Equal://zoom in
                    hi=hi*0.8;
                    lo=lo*0.8;
                    if(debug)
                    {
                        cout<<"zoom out"<<endl;
                        cout<<"hi:  "<<hi<<"    lo: "<<lo<<endl;
                    }
                    break;
                case sf::Keyboard::Space://pause to enter
                    throw s;
                }

                break;
            case sf::Event::MouseEntered:
                mouseIn = true;
                break;

            case sf::Event::MouseLeft:
                mouseIn = false;
                break;

            case sf::Event::MouseMoved:
                 mouseX = event.mouseMove.x;
                 mouseY = event.mouseMove.y;
                 //Do something with it if you need to...
                break;
            case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
//                                mouse_pos_string(window);

                    }
                    else{
//                                cout<<mouse_pos_string(window);
                    }
                    break;

                default:
                    break;
            }
        }

}
void Animate::run(RPN r){
    while (window.isOpen())
    {
        processEvents();
        update();
        render(r); //clear/draw/display
    }
    cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;

}
string mouse_pos_string(sf::RenderWindow &window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";

}
