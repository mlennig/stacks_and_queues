//
//  main.cpp
//  COEN244Assign.4
//  21297899
//  Created by Miriam Lennig on 2016-03-12.
//  Copyright © 2016 Miriam Lennig. All rights reserved.
//
//  This module tests the templates Queue and Stack
//

#include <iostream>
#include "queuestack.h"
using namespace std;

class Dummy{
public:
    Dummy();
    float getX();
    void setX(float);
    float getY();
    void setY(float);
    float getZ();
    void setZ(float);
    friend ostream& operator<<(ostream&, const Dummy&);
private:
    float X;
    float Y;
    float Z;
};

Dummy::Dummy(){
    // No heap memory allocated, so can rely on the default destructor
    X = 0;
    Y = 0;
    Z = 0;
}


ostream& operator<<(ostream& os, const Dummy& d){
    os << "(" << d.X << ", " << d.Y << ", " << d.Z << ")" << endl;
    return os;
}


float Dummy::getX(){
    return X;
}

void Dummy::setX(float x){
    X = x;
}

float Dummy::getY(){
    return Y;
}

void Dummy::setY(float y){
    Y = y;
}

float Dummy::getZ(){
    return Z;
}

void Dummy::setZ(float z){
    Z = z;
}

int main() {
    Stack<int>    int_stk(50);

    Stack<float>  float_stk(100);
   
    
    int_stk.push(1);
    int_stk.push(2);
    int_stk.push(3);
    cout << "Should print 3: " << int_stk.numElements() << endl;  // outputs 3
    
    if (!int_stk.isEmpty())
        cout << "Should print 3: " << int_stk.pop() << endl;   // outputs 3
    else
        int_stk.pop();
    
    if (!int_stk.isEmpty())
        cout << "Should print 2: " << int_stk.pop() << endl;   // outputs 2
    else
        int_stk.pop();
        
    if (!int_stk.isEmpty())
        cout << "Should print 1: " << int_stk.pop() << endl;   // outputs 1
    else
        int_stk.pop();
    
    cout << "Should say stack is empty: ";
    if (!int_stk.isEmpty())
        cout << "Last stack pop: " << int_stk.pop() << endl;   // outputs "The stack is empty."
    else
        int_stk.pop();
    
    cout << "Should print 0: " << int_stk.numElements()  << endl;  // outputs 0
    
    Queue<char> chr_que(50);
    Queue<int> int_que(100);
    Queue<Dummy> dummy_que(20);

    chr_que.push('H');
    chr_que.push('e');
    chr_que.push('l');
    chr_que.push('l');
    chr_que.push('o');
    
    cout << "Should print 5: " << chr_que.numElements() << endl;  // outputs 5
    cout << "Should print h: " << chr_que.pop() << endl;   // outputs H
    cout << "Should print e: " << chr_que.pop() << endl;   // outputs e
    cout << "Should print l: " << chr_que.pop() << endl;   // outputs l
    cout << "Should print l: " << chr_que.pop() << endl;   // outputs l
    cout << "Should print o: " << chr_que.pop() << endl;   // outputs o
    cout << "Should say queue is empty: ";
    if (!chr_que.isEmpty())
        cout << chr_que.pop() << endl;
    else
        chr_que.pop();  //Should print the queue is empty
    cout << "Should print 0: " << chr_que.numElements() << endl;  // outputs 0
    
    Queue<char> myqueue(5);
    myqueue.push('a');
    myqueue.push('b');
    myqueue.push('c');
    myqueue.push('d');
    myqueue.push('e');
    cout << "\nCurrent state of the queue:\n";
    myqueue.print();
    
    cout << "\nPopping first four elements:\n";
    for (int i=0; i < 4; i++)
        cout << "popped: " << myqueue.pop() << endl;
    myqueue.push('f');
    cout << "\nCurrent state of the queue:\n";
    myqueue.print();
    cout << "Pushing g onto the queue\n";
    myqueue.push('g');
    cout << "\nCurrent state of the queue:\n";
    myqueue.print();
    cout << "\nPushing h onto the queue\n";
    myqueue.push('h');
    cout << "\nCurrent state of the queue:\n";
    myqueue.print();
    cout << "\nPushing j onto the queue\n";
    myqueue.push('j');
    cout << "\nCurrent state of the queue:\n";
    myqueue.print();

    Stack<Dummy> dummy_stack(20);
    
    Dummy dummy;
    
    dummy.setX(5);
    dummy.setY(4);
    dummy.setZ(3);
    dummy_stack.push(dummy);
    
    dummy.setX(1);
    dummy.setY(2);
    dummy.setZ(10);
    dummy_stack.push(dummy);
    
    dummy_stack.print();
    
    dummy.setX(11);
    dummy.setY(12);
    dummy.setZ(13);
    dummy_stack.push(dummy);
    
    dummy_stack.print();
    
    dummy_stack.pop();
    
    dummy_stack.print();
 
}
