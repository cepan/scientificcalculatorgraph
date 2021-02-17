#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>


using namespace std;
class token
{
public:
    token();  
    token(int type);

    token operator =(const token& rhs){
        if(this!= &rhs){
           this->_type=rhs._type;

        }
        return *this;
    }

    virtual void print(ostream& outs=cout) const;
    friend ostream& operator <<(ostream& outs, const token* p ){
        p->print(outs);
        return outs;
    }
    int get_type(){return _type;}
    virtual double get_number(){}

private:
    int _type;

};

#endif // TOKEN_H
