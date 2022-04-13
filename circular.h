#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {  
    private:
        Node<T>* head;//sentinel
        Node<T>* tail;//sentinel

        int nodes; 
    public:
        CircularList() : List<T>() {
          head = nullptr;
          tail = nullptr;
        }

        ~CircularList(){
           // TODO
        }


        void push_front(T data){
          Node<T>* nuevo = new Node<T>(data);
          nuevo -> next = head;
          head -> prev = nuevo;
          head = nuevo;
          head->prev = tail;
          tail->next = head;
        }

        void push_back(T data){
            Node<T>* nuevo = new Node<T>(data);
        
            if(head == nullptr){ //CASO VACIO
                nuevo->next = nuevo;
                nuevo->prev = nuevo;
                head = nuevo;
                tail = nuevo;
            }
        
            tail = head->prev;
            tail->next = nuevo;
            nuevo->prev = tail;
            nuevo->next = head;
            head->prev = nuevo;
            tail = nuevo;
        }

};

#endif
