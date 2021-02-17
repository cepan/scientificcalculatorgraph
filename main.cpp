#include <cmath>
#include "math.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <queue.h>
#include<operator.h>
#include<operand.h>
#include<rpn.h>
#include <animate.h>
using namespace std;

    int main(){
        bool done= false;
        /*users inputs a function and execute the animate game
         * inside the animate will convert the string into queue.
         * Taking the queue and generate graphing points
         * convert graphing point to pixel point
         * using sfml to create a window with x- axis and y- axis
         * graph the pixel point on to the window
         * users are allow to enter basic single variable function including
         * sin x cos x tan x max and min
         * users are allowed to press space bar to pause to enter a new function.
         * */

 while(!done){
        string s;

        cout<<endl<<endl<<"key in funciton  (s)in, (c)os, (t)an, (m)ax(,), mi(n)(,)"<<endl;
        cin>>s;
        RPN a(s);
        try{
        Animate game;//execute sfml
        game.run(a);
        cout<<"press space bar to pause and enter a new function"<<endl;
        }
        catch(int e){   //thrown in shunnting yard
            cout<<"!missing parentesses, double check your life!"<<endl;

        }catch (char w){
            return 0;
        }catch (string s){
            cout<<"huh?"<<endl;;
        }
 }
 return 0;

}//        cout<<endl<<endl<<"------ MAIN EXITING --------------------------"<<endl;









