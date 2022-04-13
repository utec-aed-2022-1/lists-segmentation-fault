#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"

template <typename T>
class DoubleList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

    public:
        DoubleList() : List<T>() {}

        ~DoubleList(){
          clear();
          delete head;
          delete tail;
        }

       T front(){
            return head;
        }

        T back(){
            return tail;
        }

        void push_front(T data){
          Node<T>* nuevo = new Node<T>(data);
          nuevo -> next = head;
          head -> prev = nuevo;
          head = nuevo;
        }

        void push_back(T data){
          Node<T>* nuevo = new Node<T>(data);
          nuevo -> next = nullptr;
          nuevo -> prev = tail;
          tail -> next = nuevo;
          tail = nuevo;
        }

        T pop_front(){
          head = head -> next;
          delete head -> prev;
          head -> prev = nullptr;
        }

        T pop_back(){
          tail = tail -> prev;
          delete tail -> next;
          tail -> next = nullptr;
        }

        T insert(T data, int pos){
          Node<T>* nuevo = new Node<T>(data);
          Node<T>* temp = head;
          int i = 0; while(i++ < pos - 1) temp = temp->next;
          nuevo -> next = temp -> next;
          nuevo -> prev = temp;
          temp -> next -> prev = nuevo;
          temp -> next = nuevo;
        }

        bool remove(int pos){
          Node<T>* temp = head;
          int i = 0; while(i++ < pos - 1) temp = temp->next;
          temp -> prev -> next = temp -> next;
          temp -> next -> prev = temp -> prev;
        }

        T& operator[](int pos){
          if(pos >= size()) throw "index out of range";
          Node<T> temp = head;
          int i = 0; while(i++ < pos - 1) temp = temp->next;
          return temp->data;
        }

        bool is_empty(){
            return head==nullptr;
        }

        int size(){
          int size = 0;
          Node<T>* temp = head;
          while(temp != nullptr){
            temp = temp -> next;
            size ++;
          }
          return size;
        }

        void clear(){
          Node<T>* temp = head;
          while(temp != nullptr){
            head = temp;
            temp = temp -> next;
            delete head;
          }
          head = tail = nullptr;
        }
        
        void sort(){
          
          int swapp, i;
          Node<T>* temp = head;
          Node<T>* ptr1;
          Node<T>* lptr = NULL;
          if (temp == NULL)
            return;
          do{
            
            swapp = 0;
            ptr1 = temp;
            while (ptr1->next != lptr){
              if (ptr1->data > ptr1->next->data){
                swap(ptr1->data, ptr1->next->data);
                swapp = 1;
              }
            ptr1 = ptr1->next;
            }
          lptr = ptr1;
          }
          while (swapp);
        }

        bool is_sorted(){
          if(head == nullptr){
            return true;
          }
          Node<T>* temp = head;
          while(temp != nullptr){
            if(temp -> data > temp -> next -> data){
              return false;
            } else{
              return true;
            }
          }
        }

        void reverse(){
          Node<T>* ptr;
          Node<T>* ptr2;
          int val;
          ptr = head;
          ptr2 = head;
          while(ptr2 -> next != nullptr){
            ptr2 = ptr2 -> next;
            val = ptr -> data;
            ptr -> data = ptr2 -> data;
            ptr2 -> data = val;
          }
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif
