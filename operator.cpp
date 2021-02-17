#include "operator.h"
#include "cmath"
Operator::Operator(){

}
Operator::Operator(char o):token(1),_o(o){//one kind of token(1)

}
void Operator::print(ostream &outs) const{
    outs<<_o;
}
double Operator::evaluate(double operand_1, double operand_2){
    double result=0;
    bool debug= false;
    if(debug){
        cout<<"=======evaluate (operator) starts========"<<endl;
        cout<<"=======evaluate (operator) starts========"<<endl;
        cout<<"=======evaluate (operator) starts========"<<endl;
        cout<<"=======evaluate (operator) starts========"<<endl;
        cout<<"=======evaluate (operator) starts========"<<endl;
        cout<<"=======evaluate (operator) starts========"<<endl;

    }

    switch(_o){

    case('+'):      //var + var
        result= operand_2 +operand_1;
        if(debug){
            cout<<"right: "<<operand_2<<" + "<<"left: "<<operand_1<<endl<<endl;
        }
        break;
    case('-'):      //var - var
        result= operand_2-operand_1;
        if(debug){
            cout<<"right: "<<operand_2<<" - "<<"left: "<<operand_1<<endl<<endl;
        }
        break;
    case('*'):      //var * var
        result=operand_2*operand_1;
        if(debug){
            cout<<"right: "<<operand_2<<" * "<<"left: "<<operand_1<<endl<<endl;
        }
        break;
    case('/'):      //var / var
        result=operand_2/operand_1;
        if(debug){
            cout<<"right:"<<operand_2<<" / "<<"left: "<<operand_1<<endl<<endl;
        }
        break;
    case('^'):      //var ^ var
        result=pow(operand_2,operand_1);
        if(debug){
            cout<<"right:"<<operand_2<<" ^ "<<"left: "<<operand_1<<endl<<endl;
        }

        break;
    default:
        cout<<"false operator"<<endl;
    }
    if(debug){
        cout<<"=======evaluate (operator) ends========"<<endl;
        cout<<"=======evaluate (operator) ends========"<<endl;
        cout<<"=======evaluate (operator) ends========"<<endl;
        cout<<"=======evaluate (operator) ends========"<<endl;
        cout<<"=======evaluate (operator) ends========"<<endl;
        cout<<"=======evaluate (operator) ends========"<<endl;

    }
    return result;
}
int Operator::precedence(){//level of precedence
    switch (_o) {
    case ('^'):
        _order= Right;
        return 4;
        break;
    case ('*'):
        _order= Left;
        return 3;
        break;
    case ('/'):
        _order= Left;
        return 3;
        break;
    case ('+'):
        _order= Left;
        return 2;
        break;;
    case ('-'):
        _order=Left;
        return 2;
        break;
    default:
        break;
    }
}
