#ifndef CONSTANT_H
#define CONSTANT_H




enum function{OPERAND,OPERATOR,VARIABLE,FUNCTION};

enum associativity{Right, Left};


const int SCREEN_WIDTH = 1400;
const int  SCREEN_HEIGHT = 800;
const int SMOOTH_POINT = 5000;
const int SB_MOUSE_POSITION = 0;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED + 1;




#endif // CONSTANT_H
