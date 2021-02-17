#include <iostream>
#include <cassert>
#ifndef NODE_H
#define NODE_H

using namespace std;

template<typename T>
struct node
{
    T _item;
    node<T>* _next;
    node();
    node(T item);
    node<T>* insert_head(node<T>* &head_ptr, const T& item);
    node<T>* Insert_After(node<T> *afterThis,T insertThis);
    node<T>* SearchList(node<T>* head,T key);
    node<T>* PreviousNode(node<T>* head, node<T>* prevToThis);
    node<T>* Insert_Before(node<T>*& head,node<T>* beforeThis,T insertThis);
    node<T>* LastNode(node<T>* head);
    node<T>* CopyList(node<T>* head);
    node<T>* WhereThisGoes(node<T>* head,T item,bool ascending=true);
    node<T>* Insert_Sorted(node<T>* &head,T item,bool ascending=true);

    void ClearList(node<T>*& head);
    T erase_head(node<T>* head);
    void print_list(node<T>* head_ptr);
    T Deletenode(node<T>* iMarker);
    T& At(node<T>* head, int pos);

};
template<typename T>
node<T>::node(){
    _item= NULL;
    _next= nullptr;

}
template<typename T>
node<T>::node(T item){
    _item= item;
    _next= nullptr;
}

template <typename T>
void print_list(node<T>* head_ptr){//check
    /*
         * print list pointed to by head_ptr
         */

        node<T>* walker;
        walker = head_ptr;
        while (walker != NULL){
            cout<<walker->_item;
            walker = walker->_next;
        }
        cout<<endl;
}
template <typename T>
node<T>* SearchList(node<T>* head,T key){
    node<T>* walker= head;
    if(head==nullptr){
        return nullptr;
    }
    while(walker != NULL){
        if(walker->_item== key){
            return walker;
        }
        walker= walker->_next;
    }
    return nullptr;
}
template<typename T>
node<T>* insert_head(node<T>* &head_ptr, const T& item){//check
    /*
     * create a new node with item as payload.
     * insert at the head of the list
     * return pointer to this inserted node
     */

    //1. create a new node.
    node<T>* temp = new node<T>(item);

    //2. temp's next points to where head_ptr points to
    temp->_next = head_ptr;

    //3. point head_ptr to where temp is pointing to
    head_ptr = temp;

    //return head_ptr;
    return head_ptr;
}
template <typename T>//check
node<T>* Insert_After(node<T> *afterThis,T insertThis){//check
    //create a new node
    assert(afterThis!=NULL);
    node<T>* insert = new node<T>(insertThis);
    insert->_next=afterThis->_next;
    afterThis->_next= insert;
     return insert;
}
template <typename T>//check
node<T>* Insert_Before(node<T>*& head,node<T>* beforeThis,T insertThis){
    node<T>*walker=PreviousNode(head,beforeThis);
    //create a new node
    node<T>* insert = new node<T>(insertThis);
    insert->_next=walker->_next;
    walker->_next=insert;
    return insert;
}
template <typename T>//check
node<T>* PreviousNode(node<T>* head, node<T>* prevToThis){
    assert(head!= NULL);
    node<T>* walker = head;
    if(head !=prevToThis){
        while(walker!=prevToThis){
            if(walker->_next== prevToThis){
                return walker;
            }
            walker= walker->_next;
        }
    }else{
        return NULL;
    }
}
template <typename T>
T Deletenode(node<T>* head_ptr,node<T>* iMarker){//check
    //create a walker points to the same place as headptr points

    //go through the whole chain and find the place where pointer inside the node is
    //pointing to the node i want to delete.
    //once the walker's address match the node i want to delete.
    //have walker point to the one after the node I want to delete.
    //and delete the node i intend to delete......
    assert(head_ptr!=NULL);
    node<T>* walker= PreviousNode(head_ptr,iMarker);
    walker->_next=iMarker->_next;
    T value= iMarker->_item;
    delete iMarker;

    return value;

}
template <typename T>
T& At(node<T>* head, int pos){//check
    assert(head!=NULL);
    node<T>*  walker= head;
    int i= 0;
    while(i!= pos){
        walker=walker->_next;
        i++;
    }
    return walker->_item;

}


template <typename T>
void ClearList(node<T>*& head){
    const bool debug= false;
    if(debug){
        cout<<"enter loop"<<endl;
    }
    while(head!= NULL){
        erase_head(head);
    }
    head= NULL;
//    delete head;
}
template <typename T>
node<T>* CopyList(node<T>* head){
    node<T>* newhead=NULL;
    node<T>* walker2;
    node<T>* walker= head;
    if(head!= NULL){
        insert_head(newhead,walker->_item);
        walker2 = newhead;
        walker= walker->_next;
        while(walker!= NULL){
            Insert_After(walker2,walker->_item);
            walker2= walker2->_next;
            walker= walker->_next;

        }
        return newhead;
    }else{
        return NULL;
    }


}


template <typename T>
node<T>* LastNode(node<T>* head){
    node<T>* walker= head;
    while(walker!=NULL){
        walker=walker->_next;
    }
    return walker;
}
template<typename T>
T erase_head(node<T>* &head){
    assert(head!=NULL);
    node<T>* walker= head;
    T value= head->_item;
    head= head->_next;
    delete walker;
    return value;
}
template <typename T>
node<T>* WhereThisGoes(node<T>* head,T item,bool ascending){
    if(head==nullptr){
        return nullptr;
    }
    node<T>* walker1= head;
    node<T>* walker2= head->_next;

    if(ascending){
        if(item<head->_item){
            return nullptr;
        }
        while(walker2!= NULL){
            if(item >walker1->_item&& item <walker2->_item){
                return walker1;
            }
            walker1=walker1->_next;
            walker2= walker2->_next;
        }
        return walker1;
    }else if(ascending== false){
        if(item>head->_item){
            return nullptr;
        }
        while(walker2!= NULL){
            if(item <walker1->_item&& item >walker2->_item){
                return walker1;
            }
            walker1=walker1->_next;
            walker2= walker2->_next;
        }
        return walker1;

    }
}
template <typename T>
node<T>* Insert_Sorted(node<T>* &head,T item,bool ascending){
    node<T>* result= head;
    node<T>* wtg = WhereThisGoes(result, item, ascending);
        if(wtg==nullptr){
            insert_head(head, item);
        }else{
            Insert_After(wtg,item);
        }
        return result;
}
//template <typename T>
//node<T>* InsertSorted_unique(node<T>* &head,T item,bool ascending){
//   node<T>* result= head;
//   node<T>*wtg= WhereThisGoes(result, item,ascending);
//   const bool debug= true;
//   if(debug){
//       cout<<search_item->_item<<endl;
//   }
//   if(search_item->_next->_item!= item){
//       if(debug){
//           cout<<"added"<<endl;
//       }
//       Insert_After(search_item,item);
//       return result;
//   }else{
//       return result;
//   }
//}






#endif // NODE_H
