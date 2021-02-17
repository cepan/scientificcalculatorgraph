#ifndef FUNCTION_H
#define FUNCTION_H
#include <token.h>
#include <iostream>
#include<cmath>
#include<math.h>
using namespace std;

class Function:public token
{
public:
    Function();
    Function(char f):token(3),_f(f){}//one kind of token(3)

    void print (ostream& outs=cout)const{
        outs<<_f;
    }
    double eval_function(double num){
        switch(_f){
        case (115):     //(s)
            return sin(num);
            break;
        case(116):      //(t)
            return tan(num);
            break;
        case(99):       //(c)
            return cos(num);
            break;            
        default:
            cout<<"Function Error"<<endl;
            break;
        }

    }
    double max(double a,double b){ //max function
        return (a<b)?b:a;
}
    double min(double a, double b){// min function
        return !(b<a)?a:b;
    }
    char get_function(){
        return _f;
    }
private:
    char _f;
};
#endif // FUNCTION_H
