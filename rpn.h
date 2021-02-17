#ifndef RPN_H
#define RPN_H
#include<iostream>
#include<token.h>
#include<queue.h>
#include<stack.h>
#include<constant.h>
#include<operand.h>
#include<operator.h>
#include<variable.h>
#include<coordinate.h>
#include<vector>
#include<function.h>
using namespace std;

struct RPN
{

    RPN();
    RPN(string s){_s=s;}
    double eval(queue<token*> q,double var){

        bool debug = true;
        if(debug){
            if(q.empty()){
                cout<<"queue is null"<<endl;
            }else{
                cout<<"eval Queue: "<<q<<endl;
                cout<<"=====eval without var starts====="<<endl;

        }
    }
        token* p;
        Stack<token*>s;
        while(!q.empty()){//run loop until it's empty
            p= q.pop();//check which token it is

            switch(p->get_type()){
            case VARIABLE:
            {
                if(debug){
                    cout<<"pushing variable"<<endl;
                }
                s.push(new operand(var));
                if(debug){
                    cout<<"Stack: "<<s<<endl;
                }
                break;
            }
            case OPERAND://operand
            {
                if(debug){
                    cout<<"pushing operand"<<endl;
                }

                s.push(p);
                if(debug){
                    cout<<"Stack: "<<s<<endl;
                }
            }
                break;
            case OPERATOR://operator
            {
                if(debug){
                    cout<<"pushing operator"<<endl;
                }
                auto* operand_1=s.pop();
                auto* operand_2=s.pop();
                if(debug){
                    cout<<"poping operand_1     "<<operand_1->get_number()<<endl;
                    cout<<"poping operand_2     "<<operand_2->get_number()<<endl;
                }

                auto* optr=static_cast<Operator* >(p);//take the operator that has poped and evaluate two operand
                double result=  optr->evaluate(operand_1->get_number(),
                                               operand_2->get_number());
                if(debug){
                    cout<<"result"<<result<<endl;
                }
                s.push(new operand(result));//push in the result
                if(debug){
                    cout<<"Stack: "<<s<<endl;

                }
                break;
            }
            case FUNCTION:
            {
                if(static_cast<Function*>(p)->get_function()=='m'){
                    auto* a=s.pop();
                    auto* b=s.pop();
                    if(debug){
                        cout<<"poping a     "<<a->get_number()<<endl;
                        cout<<"poping b     "<<b->get_number()<<endl;
                    }

                    auto* multi=static_cast<Function* >(p);//determine the two number which is bigger
                    double result1=  multi->max(a->get_number(),
                                                   b->get_number());
                    if(debug){
                        cout<<"multi"<<result1<<endl;
                    }
                    s.push(new operand(result1));
                    if(debug){
                        cout<<"Stack: "<<s<<endl;

                    }

                }else if(static_cast<Function*>(p)->get_function()=='n'){

                    auto* c=s.pop();
                    auto* d=s.pop();
                    if(debug){
                        cout<<"poping c     "<<c->get_number()<<endl;
                        cout<<"poping d     "<<d->get_number()<<endl;
                    }

                    auto* multi1=static_cast<Function* >(p);//determine the two number which are smaller
                    double result2=  multi1->min(c->get_number(),
                                                   d->get_number());
                    if(debug){
                        cout<<"multi1"<<result2<<endl;
                    }
                    s.push(new operand(result2));
                    if(debug){
                        cout<<"Stack: "<<s<<endl;

                    }



                }else{
                if(debug){
                    cout<<"pushing function"<<endl;
                }
                auto* operand_top=s.pop();
                auto* func= static_cast<Function*>(p);
                double func_result= func->eval_function(operand_top->get_number());
                if(debug){
                    cout<<"func_result"<<func_result<<endl;
                }
                s.push(new operand(func_result));
                if(debug){
                    cout<<"Stack: "<<s<<endl;

                }

                break;
                }
            }
            }
        }

        if(debug){
            cout<<"=====eval ends====="<<endl;

            cout<<"postfix  result: "<<s.top()->get_number()<<endl<<endl;
        }
        return s.top()->get_number();
    }

    double eval(queue<token*>& q){
        bool debug = false;
        token* p;
        Stack<token*>s;
        if(debug){
            cout<<"=====eval without var starts====="<<endl;
        }
        while(!q.empty()){//loop run through whole queue
            p= q.pop();//pop to check if is operand, operator function
            switch(p->get_type()){
            case OPERAND://operand
            {
                s.push(p);//push
                break;
            }
            case OPERATOR://operator
            {
                auto* operand_1=s.pop();
                auto* operand_2=s.pop();

                auto* optr=static_cast<Operator* >(p);//evaluate the 2 operand
                double result=  optr->evaluate(operand_1->get_number(),operand_2->get_number());
                if(debug){
                    cout<<"result"<<result<<endl;
                }
                s.push(new operand(result));// push in the new result
                if(debug){
                    cout<<"S: "<<s<<endl;

                }
                break;
            }
            case FUNCTION:
            {   //checking if the function is max
                if(static_cast<Function*>(p)->get_function()=='m'){
                    auto* a=s.pop();
                    auto* b=s.pop();
                    if(debug){
                        cout<<"poping a     "<<a->get_number()<<endl;
                        cout<<"poping b     "<<b->get_number()<<endl;
                    }

                    auto* multi=static_cast<Function* >(p);
                    double result1=  multi->max(a->get_number(),
                                                   b->get_number());
                    if(debug){
                        cout<<"multi"<<result1<<endl;
                    }
                    s.push(new operand(result1));
                    if(debug){
                        cout<<"Stack: "<<s<<endl;

                    }

                }else if(static_cast<Function*>(p)->get_function()=='n'){
                    //checking is the functino is min
                    auto* c=s.pop();
                    auto* d=s.pop();
                    if(debug){
                        cout<<"poping c     "<<c->get_number()<<endl;
                        cout<<"poping d     "<<d->get_number()<<endl;
                    }

                    auto* multi1=static_cast<Function* >(p);
                    double result2=  multi1->min(c->get_number(),
                                                   d->get_number());
                    if(debug){
                        cout<<"multi1"<<result2<<endl;
                    }
                    s.push(new operand(result2));
                    if(debug){
                        cout<<"result Stack: "<<s<<endl;

                    }



                }else{
                    //checking if the function is trig function

                if(debug){
                    cout<<"pushing function"<<endl;
                }
                auto* operand_top=s.pop();
                auto* func= static_cast<Function*>(p);
                double func_result= func->eval_function(operand_top->get_number());
                if(debug){
                    cout<<"func_result"<<func_result<<endl;
                }
                s.push(new operand(func_result));
                if(debug){
                    cout<<"Stack: "<<s<<endl;

                }
                }

                break;
            }

            }
        }
        if(debug){
            cout<<"=====eval ends====="<<endl;
        }

        return s.top()->get_number();


    }
    queue <token*> infix_to_postfix(queue <token*> s){
        bool debug = true;
        queue <token*> output;
        Stack <token*> stck;
        int i=0;
        int j =0;
        int k=1;
        token* p;
        if(debug){
            cout<<"==infix to postfix starts=="<<endl;
        }
        /* This implementation does not implement composite functions,functions with variable number of arguments, and unary operators.

        while there are tokens to be read:
            read a token.
            if the token is a number, then:
                push it to the output queue.
            if the token is a function then:
                push it onto the operator stack
            if the token is an operator, then:
                while ((there is a function at the top of the operator stack)
                       or (there is an operator at the top of the operator stack with greater precedence)
                       or (the operator at the top of the operator stack has equal precedence and is left associative))
                      and (the operator at the top of the operator stack is not a left bracket):
                    pop operators from the operator stack onto the output queue.
                push it onto the operator stack.
            if the token is a left bracket (i.e. "("), then:
                push it onto the operator stack.
            if the token is a right bracket (i.e. ")"), then:
                while the operator at the top of the operator stack is not a left bracket:
                    pop the operator from the operator stack onto the output queue.
                pop the left bracket from the stack.
        if there are no more tokens to read:
            while there are still operator tokens on the stack:
                pop the operator from the operator stack onto the output queue.
        exit.
                  */
        while(!s.empty()){
            p=s.pop();//pop to check whether the tiken is operand or variable or operator or function
            switch(p->get_type()){
            case VARIABLE:
            case OPERAND:       //0
                output.push(p);
                if(debug){
                    cout<<"output queue: "<<output<<endl;
                }
                break;
            case FUNCTION:
                stck.push(p);
                if(debug){
                    cout<<"operator stack: "<<stck<<endl;
                }
                break;
            case OPERATOR:      //1
                auto* optr1= static_cast<Operator*>(p);
                char punc= optr1->get_o();
                switch(punc){
                case '(':
                    stck.push(p);
                    i++;
                    if(debug){
                        cout<<"operator stack: "<<stck<<endl;
                    }
                    break;
                case ')':
                    j++;
                    if(debug){
                        cout<<"stck after )starting  "<<stck<<endl;
                    }

                    while(static_cast<Operator* >(stck.top())->get_o()!= '('){
                        output.push(stck.pop());
                    }
                    stck.pop();
                    if(debug){
                        cout<<"stck after )ending  "<<stck<<endl;
                        cout<<"output queue after ) ending  "<<output<<endl;
                    }

                    break;
                default:
                    if(!stck.empty())
                    {
                        auto* optr=static_cast<Operator* >(stck.top());
                        if(debug){
                            cout<<"predence of optr    "<<optr->precedence()<<endl;
                            cout<<"predence of optr1    "<<static_cast<Operator*>(p)->precedence()<<endl;
                        }

                        while(!stck.empty() &&
                              stck.top()->get_type()==FUNCTION||
                              ((optr->precedence()>optr1->precedence())||
                              (optr->precedence()==optr1->precedence()&&optr1->get_order()==Left ))
                              &&(optr->get_o()!='(')){
                            output.push(stck.pop());
                            optr=static_cast<Operator* >(stck.top());
                        }
                        stck.push(p);
                    }else{
                        stck.push(p);
                    }
                        if(debug){
                            cout<<"operator stack: "<<stck<<endl;
                        }
                    break;
                }
                break;

            }

        }
        while(!stck.empty()){
            output.push(stck.pop());
        }
        if(debug){
            cout<<"==infix to postfix ends=="<<endl;
        }
        if(i!=j){
            throw k;
        }
        return output;
    }
    queue<token*> read(){
        string s;
        bool debug= true;
        if(debug){
            cout<<"==converting string to queue starts=="<<endl;
        }

        char temp;
        queue<token*> result;
        int size= static_cast<int>(_s.size());
        for( int i=0; i<size;i++){
            temp= _s[i];
            switch(temp){
            //1,2,3,4,5,6,7,8,9,0
            case (48):case(49):case(50):case(51):case(52):
            case(53):case(54):case(55):case(56):case(57):
                if(debug){
                    cout<<"pushing operand"<<endl;

                }

                result.push(new operand(temp-'0'));
                break;
            case(40):case(41):
                //(  )
            case(43):case(45):case(42):case(47):case(94):
                //+-*/^
                if(debug){
                    cout<<"pushing operator"<<endl;

                }
                result.push(new Operator(temp));
                break;
            case(120):
                // x
                if(debug){
                    cout<<"pushing variable"<<endl;

                }
                result.push(new Variable(temp));
                break;
            case(115):case(116):case(99):case (109):case (110):// sin(s) cos(c) tan(t)Max(m) Min(n)
                if(debug){
                    cout<<"pushing function"<<endl;

                }
                result.push(new Function(temp));
                break;
            case (32):
                // ,
                break;
//            default:
//                throw s;
            }
        }
        if(debug){
            cout<<"reading string:  "<<result<<endl;
            cout<<"==converting string to queue ends=="<<endl;
        }
        return result;
    }
    string _s;
    Coordinate point;
};



#endif // RPN_H
