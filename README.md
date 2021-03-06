COEN244.Assignment(4)    Due date: Fri. Mar. 18th, 2016

Stacks & Queues 
===============

Design, implement and test a templated Stack class and a templated Queue class. Both
classes should be derived from a common base class, which is abstract (pure virtual).

Both classes should allow for the creation, use and destruction of stack and queue 
objects, where the type (class) of objects can be anything the user wants. The
user should be able to indicate both the type and size of the stack/queue he wants, then
use it (e.g., add and remove objects from it), and output its contents. Note that for user-
defined types (classes), certain operators and functions will require overloading.

Test your classes, by creating and using different types of stacks and queues (say 
int, float, char). Also, create 1 unrelated class (e.g., a trivial class that holds, sets, 
gets and prints a single string variable) and use it to show that you can create a 
stack and a queue of objects (or pointers to objects) of that class, a stack/queue
that operates correctly.


Stack Examples
--------------
		
Stack<int>    int_stk(50);
Stack<float>  int_stk(100);

int_stk.push(1);
int_stk.push(2);
int_stk.push(3);
int_stk.size();  // outputs 3
int_stk.pop();   // outputs 3
int_stk.pop();   // outputs 2
int_stk.pop();   // outputs 1
int_stk.pop();   // outputs "The stack is empty."
int_stk.size();  // outputs 0

// you should be able to create a stack of any predefined type and one user-defined
// type (a class you define).
// these methods are manadatory: push, pop, peek, is_empty, is_full, size.
// make sure the user cannot cause the program to: generate invalid outputs or (as
// much as possible) crash.


Queue Examples 
--------------

Queue<char> chr_que(50);
Queue<char> chr_que(100);

chr_que.push('H');
chr_que.push('e');
chr_que.push('l');
chr_que.push('l');
chr_que.push('o');
chr_que.size();  // outputs 5
chr_que.pop();   // outputs H
chr_que.pop();   // outputs e
chr_que.pop();   // outputs l
chr_que.pop();   // outputs l
chr_que.pop();   // outputs o
chr_que.pop();   // outputs "The queue is empty."
chr_que.size();  // outputs 0

// you should be able to create a queue of any predefined type and one user-defined
// type (a class you define).
// these methods are manadatory: push, pop, peek, is_empty, is_full, size.
// make sure the user cannot cause the program to: generate invalid outputs or (as
// much as possible) crash.


Testing
-------

It is important to test your program to provide strong empirical evidence that (a) the program gives 
correct outputs to valid inputs; (b) the program does not crash easily, as in response to expect-able
incorrect inputs (e.g., additional spaces or letters); (c) the program meets (or exceeds) the specifications, 
as explained here.


// end.

