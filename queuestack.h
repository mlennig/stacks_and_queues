//
//  queuestackdumb.h
//  COEN244Assign.4
//
//  Created by Miriam Lennig on 2016-03-18.
//  Copyright © 2016 Miriam Lennig. All rights reserved.
//

#ifndef queuestack_h
#define queuestack_h

using namespace std;

template <typename T>
class Container{    // Abstract base class
public:
    virtual void print() = 0;
    virtual void push(T) = 0;   // Add element into containter
    virtual T pop() = 0;    // Remove an element from container
    virtual T peek() = 0;   // View most recently added element in container
    virtual bool isEmpty() = 0; // Check if container is empty
    virtual bool isFull() = 0;  // Check if container is full
    virtual int numElements() = 0; // Returns number of elements held in container
    
};

template <typename S>
class Stack : public Container<S> { // Inherited stack class
public:
    Stack(int size);    // Constructor creates an array of specified size
    ~Stack();   // Destructor frees heap memory
    virtual void print();   // Prints elements in the stack
    virtual S peek();   // Returns the next element to be popped without popping it
    virtual void push(S);   // Pushes an element onto the stack
    virtual S pop();    // Pops an element off the stack
    virtual bool isEmpty(); // Checks to see if the stack is empty
    virtual bool isFull();  // Checks to see if the stack is full
    virtual int numElements(); // Returns number of elements held in stack
private:
    S *stackPtr;    // Pointer to array holding data in the stack
    int size;   // Number of elements held in the stack
    int top;    // The index of the most recently added element to the stack, index of the TOS
};

template <typename Q>
class Queue: public Container<Q> {
public:
    Queue(int length);      // Constructor, where length specifies max # elements the queue can hold
    ~Queue();
    virtual void print();   // Prints the queue in order from first to last
    virtual Q peek();       // Returns the next element to be popped without popping it
    virtual Q pop();        // Remove (and return) the first element of the queue
    virtual void push(Q);   // Add an element onto the end of the queue
    virtual bool isEmpty(); // Returns true if the queue is empty
    virtual int numElements(); // Returns number of elements held in queue
    virtual bool isFull();  // Returns true is the queue is full
private:
    int length;     // Maximum number of elements that the queue can hold
    int end;        // Index to the end of the queue
    int start;      // Index to the start of the queue
    Q *queuePtr;    // Pointer to the array holding the data in the queue
};

// Members of Stack

template <typename S>
int Stack <S> :: numElements(){
    // Returns number of elements on the stack
    return top + 1;
}

template <typename S>
S Stack <S> :: peek(){
    // Return TOS
    return stackPtr[top];
}

template <typename S>
void Stack <S> :: push(S s){
    if(isFull())
        // Check if stack is full
        cout << "Stack full. " << endl;
    else
        // Increment TOS index
        // Add element to stack
        stackPtr[++top] = s;
}

template <typename S>
S Stack <S> :: pop(){
    // Test if stack is empty
    S empty_return_value;
    if(isEmpty()) {
        cout << "Stack is empty." << endl;
        return empty_return_value;
    }
    else
        // Return value being popped
        // Decrement TOS index
        return stackPtr[top--];
}

template <typename S>
void Stack <S> :: print(){
    for (int i = top; i >= 0; i--)
        // Print elements in the order that they would be popped
        cout << stackPtr[i];
}

template <typename S>
Stack <S>::Stack(int capacity){
    // Constructor where capacity is specified
    // Allocates heap memory
    size = capacity;
    top = -1;
    stackPtr = new S[size]; // Create array of specified size
}

template<typename S>
Stack<S>::~Stack(){
    // Destructor
    delete [] stackPtr; // Free the heap memory allocated during construction
}

template<typename S>
bool Stack<S>::isEmpty(){
    // Check to see if stack is empty
    return top == -1;   // Return true if the stack is empty, i.e., if top == -1
}

template<typename S>
bool Stack<S>::isFull(){
    // Returns true of the stack is full
    return top == size -1;
}

// Members of Queue

template <typename Q>
int Queue <Q> :: numElements(){
    if (isEmpty())
        return 0;
    if (isFull())
        return length;
    if(start < end)
        return end - start; 
    if(end > start)
        return 1 + length + end - start;
    return -1;
    
}

template <typename Q>
Q Queue <Q> :: peek(){
    // Returns the next element to be popped from the queue
    Q empty_return_value;
    if(isEmpty()){
        cout << "Stack is empty. " << endl;
        return empty_return_value;
    }
    else
        return queuePtr[(start + 1)%(length + 1)];
}

template <typename Q>
bool Queue <Q> :: isFull(){
    // Return true if the queue is full
    // Is this correct?
    //
    return ((start < 1) && (end == length)) || (start == end + 1); // Bug to be fixed
}

template <typename Q>
bool Queue < Q> :: isEmpty(){
    // Return true if the queue is empty
    //
    return (start == end);
}

template <typename Q>
void Queue <Q> :: push(Q q) {
    // Push a new element onto the start of the queue
    //
    if(isFull())
        cout << "Queue is full." << endl;
    else{
        if (end == length){
            end = 0;
            queuePtr[end] = q;
        }
        else
            queuePtr[++end] = q;
    }
}

template <typename Q>
Q Queue <Q> :: pop(){
    Q empty_return_value;
    if(isEmpty()){
        cout << "Queue is empty. " << endl;
        return empty_return_value;
    }
    else
        if(start == length){
            start = 0;
            return queuePtr[start];
        }
    
    return queuePtr[++start];
}

template <typename Q>
Queue <Q>::Queue(int s){
    // Constructor in which length is specified
    // This constructor allocates heap memory
    //
    length = s;
    end = -1;
    start = -1;
    queuePtr = new Q[length + 1];
}

template<typename Q>
Queue<Q>::~Queue(){
    // Destructor
    delete [] queuePtr;
}

template<typename Q>
void Queue<Q> :: print(){
    if(isEmpty())
        cout << "Queue is empty. " << endl;
    else
        if(start < end)
            for(int i = start + 1; i <= end; i++)
                cout << queuePtr[i] << endl;
        else{
            for(int i = start + 1; i  <= length; i++)
                cout << queuePtr[i] << endl;
            for(int i = 0; i <= end; i++)
                cout << queuePtr[i] << endl;
        }
}


#endif /* queuestack_h */

