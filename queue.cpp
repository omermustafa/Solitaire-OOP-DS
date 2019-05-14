#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <conio.h>
#include<iostream>
#include <card.h>
using namespace std;
class Node {
    public:
        Node(){
//            data = 0;
            next = NULL;
        }
        Card getData(){
            return data;
        }
        Node* getNext(){
            return next;
        }
        void setNext(Node * n){
            next = n;
        }
        void setData(Card data) {
            Node::data = data;
        }

    Node(Card data) : data(data) {
        next = NULL;
    }


    void display(){
        cout<<data<<" ";
//        cout << &data << endl;
    }
private:
        Card data;
        Node * next;

};
class Queue {
    public:
        Queue() {
            size = 0;
            front = rear = NULL;
        }
        void push_back(Card d){
            Node * n = new Node(d);

            if(front  == NULL && rear == NULL){
                front = rear = n;
            }
            else{
                rear->setNext(n);
                rear = n;
            }
            size++;

        }
        void push_front(Card d){
            Node * n = new Node(d);

            if(front == NULL && rear == NULL){
                front = rear = n;
            }
            else {
              Node * temp = front;
              while(temp->getNext() != NULL){
                temp = temp->getNext();
              }
              temp->setNext(n);
            }
        }
        void pop_front(){
            if(front != NULL){
                Node * temp = front;
                front = front->getNext();
                temp->setNext(NULL);
                delete temp;
                temp = NULL;
                size--;
            }
            else{
                cout<<"Queue is already empty !!!"<<endl;
            }
        }
        void pop_back(){
            Node * temp = front;
            while(temp->getNext() != NULL){
                temp = temp->getNext();
            }
            temp->setNext(NULL);
            delete temp;
            temp = NULL;
            size--;
        }


        bool isEmpty(){
        return (front == NULL) && (rear == NULL);
        }
        Card getFrontElement(){
            return front->getData();
        }
        Card getRearElement(){
            return rear->getData();
        }
        Node * getFront(){
            return front;
        }
        Node * getRear(){
            return rear;
        }
        void display(){
            Node * temp = front;
            while(temp != NULL){
                temp->display();
                temp = temp->getNext();
            }
        }
        int getSize(){
            return size;
        }


private:
        Node * front, *rear;
        int size;
};

#endif
