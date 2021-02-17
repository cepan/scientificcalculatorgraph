#ifndef OPERAND_H
#define OPERAND_H
#include "token.h"

class operand :public token
{
public:
    operand();//one kind of token(0)
    operand(double number);
    void print (ostream& outs=cout)const;
    double get_number(){return _num;}
private:
    double _num;
};

#endif // OPERAND_H
