#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <list.h>
using namespace std;


template <class T>
class Stack
{
    public:
    class Iterator{
    //the nested class
    public:
        friend class list<T>;                  //this will allow List
                                            //  to access the private
                                            //  members of Iterator
        Iterator(node<T>* p = NULL):_ptr(p){}     //ctor

        Iterator(typename list<T>::Iterator p){
            _ptr=p;
        }


        const T& operator *()const{                    //dereference oprator
            assert (_ptr != NULL);
            return *_ptr;
        }

        friend Iterator operator ++(Iterator& it,       //it++
                                    int unused){
            Iterator hold;
            hold = it;
            it._ptr = it._ptr->_next;
            return hold;
        }
        Iterator& operator ++(){                        //++it
            _ptr = _ptr->_next;
            return *this;
        }
        friend bool operator ==(const Iterator& left,   //it == it
                                const Iterator& right){
            return left._ptr == right._ptr;
        }

        friend bool operator !=(const Iterator& left,   //it != it
                                const Iterator& right){
            return left._ptr != right._ptr;
        }

        typename list<T>::Iterator operator ->(){
            return _ptr;
        }
    private:
        typename list<T>::Iterator _ptr;                    //pointer being
                                    //  encapsulated
    };

    template <class U>
    friend ostream& operator <<(ostream& outs, const Stack<U>& print_me){
        print_me._stack.Print();
        outs<<endl;
        return outs;
    }

        Stack();
        void push(const T &item);
        T pop();
        T top();
        bool empty();
        Iterator begin()const{
            return Iterator(_stack.Begin());
        }
        Iterator End()const{
            return Iterator(_stack.End());
        }
    private:
        int size;
        list<T> _stack;
};
template <class T>
Stack<T>::Stack(){
    size=0;
}
template <class T>
void Stack<T>::push(const T &item){
    _stack.InsertHead(item);
    size++;
}
template <class T>
T Stack<T>::pop(){
    assert(!this->empty());
    T i =_stack.Begin()->_item;
    _stack.Delete_Head();
    size--;
    return i;
}
template <class T>
T Stack<T>::top(){

    assert(_stack.Begin()!=NULL);
    return _stack.Begin()->_item;
}
template <class T>
bool Stack<T>::empty(){
    return (size==0)?true :false;
}

#endif // STACK_H
