/* Author: Thomas Woeste
 * Program: node.h
 * Date: 1/27/2020
 * Purpose: This header file defines the Node class which represents one element of a
 *          linked list.
 */

class Node{
    public:
        friend class Dequeue;
        Node();

    private:
        Node* next;
        int data;
        Node* previous;
};
