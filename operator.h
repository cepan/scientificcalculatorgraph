#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"
#include <constant.h>

class Operator : public token
{
public:
    Operator();
    Operator(char o);
    void print(ostream &outs=cout)const;
    double evaluate(double operand_1,double operand_2);
    char get_o(){return _o;}
    int precedence();
    associativity get_order(){return _order;}
private:
    char _o;
    associativity _order;
};

#endif // OPERATOR_H
