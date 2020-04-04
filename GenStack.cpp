/* 
 * Logan Welsh
 * 2325215
 * lwelsh@chapman.edu
 * CPSC-350-01
 * Assignment 3: Syntax Checker
 * GenStack.cpp
 * Definition of generic stack class.
 */

#include "GenStack.h"
#include <iostream>

// CONSTRUCTORS

template <class T>
const int GenStack<T>::DEF_MAX = 128;

template <class T>
GenStack<T>::GenStack(int maxSize) {	// Overloaded constructor
	
	init(maxSize);
}


template <class T>
GenStack<T>::GenStack() {	// Default constructor

	init(DEF_MAX);
	
}

template <class T>
void GenStack<T>::init(int maxSize) {	// Internal method called by constructors
	
	myArray = new T[maxSize];	// Allocate on heap
	mSize = maxSize;
	top = -1;
}


template <class T>
GenStack<T>::~GenStack() {	// Destructor
	
	delete myArray;
}





// CORE FUNCTIONS

template <class T>
void GenStack<T>::push(T data) {
	
	if(isFull()) {
		resize(1);
	}
	
	myArray[++top] = data;	// "Pre-increment"
}


template <class T>
T GenStack<T>::pop() {
	
	if( !(isEmpty()) ) {	// Only removes if stack is not empty
		return myArray[top--];	// "Post-decrement"
	}
	else {	// If stack is empty, throw an exception
		cout << "\t\t\t!!!zoinks scoob" << endl;
		throw -1;
	}
}






// AUXILIARY FUNCTIONS

template <class T>
bool GenStack<T>::isFull() {
	return (top == mSize - 1);
}


template <class T>
bool GenStack<T>::isEmpty() {
	return (top == -1);
}


template <class T>
T GenStack<T>::peek() {
	return myArray[top];	// Returns current top item without removing it
}


template <class T>
void GenStack<T>::printStack() {
	for(int i = 0; i <= top; ++i) {
		cout << myArray[i];
	}
	cout << endl;
}




// INTERNAL FUNCTIONS

template <class T>
void GenStack<T>::resize(int sizeChange) {
	
	int oldSize = mSize;
	mSize += sizeChange;
	T *newArray = new T[mSize];
	
	for(int i = 0; i < mSize; ++i) {
		if(i < oldSize) {
			newArray[i] = myArray[i];
		}
	}
	
	if(top > mSize) {
		top = mSize;
	}
	
	delete myArray;
	myArray = newArray;
	
}
