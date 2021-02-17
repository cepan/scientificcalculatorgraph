#include "operand.h"

operand::operand(){

}
operand::operand(double number):token(0),_num(number){

}
void operand::print(ostream &outs)const {
    outs<<_num;
}
