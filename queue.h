#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include<node.h>
using namespace std;

template <class T>
class queue{

public:

    class Iterator{
    //the nested class
    public:
        friend class queue;                  //this will allow List
                                            //  to access the private
                                            //  members of Iterator
        Iterator(node<T>* p = NULL):_ptr(p){}     //ctor




        const T& operator *()const{                    //dereference oprator
            assert (_ptr != NULL);
            return _ptr->_item;
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

        friend bool operator !=(const Iterator& left,   //it != it
                                const Iterator& right){
            return left._ptr != right._ptr;
        }

        node<T>* operator ->(){
            return _ptr;
        }
    private:
        node<T>* _ptr;                    //pointer being
                                    //  encapsulated
    };
    template <class U>
    friend ostream& operator <<(ostream &outs, const queue<U>& print_me){
        print_list(print_me._front);
        return outs;
    }

    queue(){
    _front= nullptr;
    _rear= nullptr;
    _size=0;
}
    ~queue(){
        ClearList(_front);
    }

    queue(const queue<T> &copyThis){
        _front= CopyList(copyThis._front);
        _rear= LastNode(_front);
        _size = copyThis._size;
    }

    queue& operator =(const queue & RHS){
        if(this!= &RHS){
            ClearList(_front);
            _front= CopyList(RHS._front);
            _rear= LastNode(_front);
            _size = RHS._size;
        }
        return *this;
    }
    void push( T item){
        if(empty()){
            insert_head(_front,item);
            _rear=_front;
        }else{
            Insert_After(_rear,item);
            _rear=_rear->_next;


        }
        _size++;
    }
    T pop(){
        assert(!empty());
        _size--;
        return erase_head(_front);
    }
    T front(){
        return _front->_item;
    }
    bool empty(){
        return (_size==0)?true :false;

    }

    Iterator Begin()const{
        return Iterator(_front);
    }
    Iterator End()const{
        return Iterator(_rear);
    }
private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};





#endif // QUEUE_H
