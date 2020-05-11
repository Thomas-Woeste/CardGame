/* Author: Thomas Woeste
 * Program: node.cpp
 * Date: 1/27/2020
 * Purpose: The purpose this header is to impliment the node class which represents one element of a
 *          linked list.
 */

#include "node.h"
#include <iostream> 


Node::Node(){
    data = 0;
    next = NULL;
    previous = NULL;
}

