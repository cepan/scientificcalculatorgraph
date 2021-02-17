#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include<token.h>
#include <constant.h>


using namespace std;




class Variable : public token
{
public:
    Variable();
    Variable(char chr):token(2),_chr(chr){}//one kind of token(2)
    void print(ostream &outs=cout)const{outs<<_chr;}
    char get_char(){return _chr;}
private:
    char _chr;
};

#endif // VARIABLE_H
