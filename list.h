#include<node.h>

#ifndef LIST_H
#define LIST_H

template <typename T>
class list
{
public:
    class Iterator{
    //the nested class
    public:
        friend class list;                  //this will allow List
                                            //  to access the private
                                            //  members of Iterator
        Iterator(node<T>* p = NULL):_ptr(p){}     //ctor




        const T& operator *()const{
            //dereference oprator
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
        friend bool operator ==(const Iterator& left,   //it == it
                                const Iterator& right){
            return left._ptr == right._ptr;
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


    Iterator InsertHead(const T& item){
        return Iterator(insert_head(_head,item));
    }
    Iterator InsertAfter( T item, Iterator iMarker){
        return Iterator(Insert_After(iMarker,item));
    }
    Iterator InsertBefore(T item,Iterator iMarker){
        return Iterator(Insert_Before(_head,iMarker, item));
    }
    Iterator InsertSorted(T item){
        return Iterator(Insert_Sorted(_head,item, true));
    }
    T Delete(Iterator iMarker){
        return Deletenode(_head, iMarker);
    }
    T Delete_Head(){
        return erase_head(_head);
    }
    Iterator Search (const T item){
        return SearchList(_head, item);
    }
    Iterator Prev(Iterator IMarker){
        return PreviousNode(_head, IMarker);
    }
    Iterator Begin() const{
        return _head;
    }
    Iterator End()const{
        return LastNode(_head);
    }
    list();
    ~list();
    list(const list <T>&copyThis);
    list& operator =(const list& RHS);

//    node<T>* InsertHead(T i);

//    node<T>* InsertAfter(T i,node<T>* iMarker);

//    node<T>* InsertBefore(T i,node<T>* iMarker);

//    node<T>* InsertSorted(T i);         //insert i. Assume sorted list


//    T Delete(node<T>* iMarker);         //delete node pointed to by iMarker
//    T Delete_Head(node<T>* iMarker);

    void Print() const;                                 //print the list

//    node<T>* Search(const T &key);      //return pointer to node containing

//    node<T>* Prev(node<T>* iMarker);    //get the previous node to iMarker

    T& operator[](int index);                   //return the item at index


//    node<T>* Begin() const;                     //return the head of the list

//    node<T>* End() const;                       //return the tail of the list
                                                            //  if you ever have to use this
                                                            //  function, you need to redesign
                                                            //  your program.
        template <class U>
        friend ostream& operator <<(ostream& outs,          //insertion operator for list
                                    const list<U>& l){
            outs<<l;
            return outs;
        }
    private:
        node<T>* _head;
};
template <typename T>
list<T>::list()
{
    _head = nullptr;
}
template <typename T>
list<T>::~list(){
    ClearList(_head);
}
template <typename T>
list<T>::list(const list<T> &copyThis){
    _head = CopyList(copyThis._head);
}
template <typename T>
list<T>& list<T>::operator =(const list& RHS){
    if(this!=&RHS){
        ClearList(_head);
        _head = CopyList(RHS._head);
    }
    return *this;
}
template <typename T>
void list<T>::Print() const{
    print_list(_head);
}

//template <typename T>
//node<T>* list<T>::InsertHead(T i){
//    if(SearchList(_head,i) == nullptr){
//        return insert_head(_head,i);
//    }
//}
//template <typename T>
//node<T>* list<T>::InsertAfter(T i, node<T>* iMarker){
//    if(SearchList(_head,i)==nullptr){
//        return Insert_After(iMarker,i);
//    }
//}
//template <typename T>
//node<T>* list<T>::InsertBefore(T i, node<T>* iMarker){
//    if(SearchList(_head,i)==nullptr){
//        return Insert_Before(_head,iMarker,i);
//    }
//}
//template <typename T>
//node<T>* list<T>::InsertSorted(T i){
//    if(Search(i)==nullptr){
//        return  Insert_Sorted(_head,i,false);
//    }
//}
//template <typename T>
//T list<T>::Delete(node<T>* iMarker){

//    return Deletenode(_head,iMarker);

//}
//template <typename T>
//node<T>* list<T>::Search(const T &key){
//    return SearchList(_head,key);
//}
//template <typename T>
//T list<T>::Delete_Head(node<T>* iMarker){
//    return erase_head(_head);
//}
//template <typename T>
//node<T>* list<T>::Prev(node<T>* iMarker){
//    return PreviousNode(_head,iMarker);
//}
//template <typename T>
//T& list<T>::operator[](int index){
//    return At(_head, index);
//}
//template <typename T>
//node<T>* list<T>::Begin() const{
//    return _head;
//}
//template <typename T>
//node<T>* list<T>::End() const{
//    return LastNode(_head);

//}
#endif // LIST_H
