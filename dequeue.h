/* 
 * Author: Thomas Woeste
 * Project: Assign 1
 * File: dequeue.h
 * Purpose: The purpose of this file is define the dequeue class to be implimented in 
 *          dequeue.cpp
 */

#include "node.h"

using namespace std;

class Dequeue{
	public:
	 
	 //default constructor
	 Dequeue();

	 //Check to see if the dequeue is empty
	 bool isEmptyDequeue();

	 //insert a new node to the front of the Dequeue with the value given to the method
	 void insertFrontDequeue(int data);

	 //inseart a new node to the end of the Dequeue with the value given to the method
	 void insertRearDequeue(int data); 
         
	 //deletes the first node of the dequeue and return its value
	 int deleteFrontDequeue(); 

	 //deletes the last node of the dequeue then returns its value
	 int deleteRearDequeue(); 

     //Calculates the weight of a dequeue
     int calcWeight();

	private:
      	 
     Node* front;
     Node* rear;

};
