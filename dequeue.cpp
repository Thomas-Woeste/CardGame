/* Author: Thomas Woeste
 * Program: dequeue.cpp
 * Date: 1/27/2020
 * Purpose: The purpose of dequeue.cpp is to declare the Dequeue class. This class represents a double linked list.
 *          The linked list is made using a dummy node at the beginning to make the programming easier and more 
 *          efficient. 
 */

#include <iostream>
#include "dequeue.h"

using namespace std;

Dequeue::Dequeue() {
    //make dummy node
    Node *dummyN = new Node;

    front = dummyN;
    rear = dummyN;

    dummyN->next = dummyN;
    dummyN->previous = dummyN;
} //Dequeue

bool Dequeue::isEmptyDequeue() {
    if(front == rear){
        return true;
    }
    else {
        return false;
    }
} //isEmptyDequeue

void Dequeue::insertFrontDequeue(int data) {
    Node *card = new Node;
    Node *dummyN = front;

    card->next = dummyN->next;
    card->next->previous = card;
    dummyN->next = card;
    card->data = data;
    card->previous = dummyN;
        
    //If isEmptyDequeue is true set rear to the new node
    if(isEmptyDequeue()){
        rear = card;
    }
} //inseartFrontDequeue

void Dequeue::insertRearDequeue(int data) {
    Node *card = new Node;
    Node *dummyN = front;

    card->data = data;
    card->next = dummyN;
    card->previous = dummyN->previous;
    dummyN->previous = card;

    //If isEmptyDequeue is true set front to the new node
    if(isEmptyDequeue()){
        dummyN->next = card;
    }

} //insertRearDequeue

int Dequeue::deleteFrontDequeue() {
    //make sure there is something in the deck
    if(isEmptyDequeue()){
        cout << "Error: deleteFrontDequeue(), Tried to delete a node/card from an empty deck " << endl;
        return 0;
    }
    
    Node* dummyN = front;
    Node* currentCard = dummyN -> next;

    int cardValue = currentCard->data;
    dummyN->next = currentCard->next;
    currentCard->next->previous = dummyN;

    if(rear == currentCard){
        rear = currentCard -> previous;
    }
    
    delete currentCard;
    return cardValue;
} //deleteFrontDequeue

int Dequeue::deleteRearDequeue() {
    //make sure there is something in the deck
    if(isEmptyDequeue()){
        cout << "Error: deleteRearDequeue(), Tried to delete a node/card from an empty deck " << endl;
        return 0;
    }
    
    Node* dummyN = front;
    Node* currentCard = dummyN->previous;
    
    int cardValue = currentCard->data;
    dummyN->previous = currentCard->previous;
    currentCard->previous->next = dummyN;
    rear = currentCard->previous;

    delete currentCard;
    return cardValue;
} //deleteRearDequeue

int Dequeue::calcWeight() {
    Node* dummyN = front;
    Node* current = dummyN->next;
    int depthCounter = 1;
    int weight = 0;
    
    //Tranverse the linked list and calculate the weight of the deck
    while(current != dummyN) {
        weight = weight + (depthCounter * current->data);
        
        current = current->next;
        depthCounter += 1;
    }
    
    return weight;
} //calcWeight
