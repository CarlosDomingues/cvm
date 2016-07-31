/*! 

@file cvmStack.h
  
 @brief Functions to manipulate stacks.
 
This file contains the functions used to manipulate a stack
data structure. It allows users to execute taks such as 
getting and addind data, and includes functions to initialize
and free stack variables.
 
@author Carlos Felipe Domingues e Oliveira
@email cfelipe.domingues@gmail.com
@bug No known bugs.
 */

#ifndef CVMSTACK_H
#define CVMSTACK_H

//for files
#include <stdio.h>

#include "cvmTypes.h"
#include "cvmErrors.h"

/*!
@function
@brief Initializes a new stack.

CvmNewStack initializes the internal structure of a new stack by doing the following:

- Sets head to zero.
- Dynamically allocates MEMORY_SIZE words to the memory atribute.
- Sets current_size to one.

\param s an unitialized cvmStack object.
\returns a cvmOK for success.  
*/
cvmErrorType CvmNewStack(cvmStackp s);

/*!
@function
@brief Frees memory occupied by a stack.

CvmFreeStack frees the memory used in a stack by doing the following:

- Sets head to zero.
- Frees all memory used in the memory pointer
- Sets current_size to one.

\param s a cvmStack object.
\returns cvmOK for success.  
*/
cvmErrorType CvmFreeStack(cvmStackp s);

/*!
@function
@brief Pushes a word into the stack.

CvmPush takes a cvmWord parameter and adds it to the top of the stack, which is
memory[head]. Head is increased by one afterwards.

\param s a cvmStack object.
\param w a cvmWord 
integer.
\returns a cvmOK if there's no problem or cvmStackOverflow if the stack is full.
*/
cvmErrorType CvmPush(cvmStackp s, cvmWord w);

/*!
@function
@brief Pops a word from the stack.

CvmPop copies the memory[head-1] element from the stack to w.
The head atribute will be decreased by one.

\param s a cvmStack object.
\param w a cvmWord integer.
\returns a cvmOK if there's no problem or cvmStackEmpty if the stack is empty.
*/
cvmErrorType CvmPop(cvmStackp p, cvmWord* w);

/*!
@function
@brief Returns the object localized on the head, but without poping it.

CvmPeek copies the memory[head-1] element from the stack to w.
The head atribute is NOT decreased by one after the operation.

\param s a cvmStack object.
\param w a cvmWord variable.
\returns a cvmOK if there's no problem or cvmStackEmpty if the stack is empty.
*/
cvmErrorType CvmPeek(cvmStackp p, cvmWord* w);

/*!
@brief Pops the topmost elements of the stack, adds them and push the result.

CvmAdd assigns memory [head-1] + memory[head -2] to memory[head -1].

The head atribute is subsequently decreased.

\param s a cvmStack object.
\returns a cvmOK for success or cvmStackNeeds2Operands if the stack has only on or zero elements.  
*/
cvmErrorType CvmAdd(cvmStackp s);

/*!
@brief Pops the topmost elements of the stack, multiplies them and push the result.

CvmAdd assigns memory [head-1] * memory[head -2] to memory[head -1].

The head atribute is subsequently decreased.

\param s a cvmStack object.
\returns a cvmOK for success or cvmStackNeeds2Operands if the stack has only on or zero elements.  
*/
cvmErrorType CvmMultiply(cvmStackp s);

/*!
@brief Prints all elements on the stack

\param s a cvmStack object.
\returns a cvmOK for success or cvmStackEmpty if there are no elements on the stack.  
*/
cvmErrorType CvmPrint(cvmStackp s);

/*!
@brief Swaps the two topmost elements of the stack.

\param s a cvmStack object.
\returns a cvmOK for success or cvmStackNeeds2Operands if the stack has only on or zero elements.  
*/
cvmErrorType CvmSwap(cvmStackp s);

cvmErrorType CvmNop(cvmStackp s);

/*!
@brief Pushes a new element to the stack, which is equal to the curreny topmost object.

\param s a cvmStack object.
\returns a cvmOK for success, cvmStackEmpty if the stack has only one element or 
cvmStackOverflow if the stack is full.  
*/
cvmErrorType CvmDuplicate(cvmStackp s);


#endif
