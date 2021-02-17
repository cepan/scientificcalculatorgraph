#ifndef COORDINATE_H
#define COORDINATE_H
#include <iostream>
using namespace std;
struct Coordinate{
    float _x;
    float _y;
    Coordinate(int i, int j):_x(i),_y(j){
    }
    Coordinate():_x(0),_y(0){
    }
    void print_Coordinate(){
        cout<<"("<<_x<<","<<_y<<")"<<endl;
    }

};












#endif // COORDINATE_H
