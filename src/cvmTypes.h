/*! 

@file cvmTypes.h
  
 @brief Custom types used in CVM.
 
This file contains helper custom types used in the CVM library.
Custom types related to external interfaces are likely to be in other files.
Types related to error handling will be at cvmErrors.h
 
@author Carlos Felipe Domingues e Oliveira
@email cfelipe.domingues@gmail.com
@bug No known bugs.
 */


#ifndef CVMTYPES_H
#define CVMTYPES_H

#include <stdint.h>

/*!

cvmWord represents a word in the Virtual Machine. 
This particular implementation uses 64-bit wide integers.
The word size can be easily changed without any side effects
on the rest of the program.

*/
typedef uint32_t cvmWord;

/*!
cvmStack is a minimal implementation of a stack structure.
A stack, also know as first in last out, is a vector-like
data structure that only allows data to be stored or collected
from the first address (known as head). 
*/
typedef struct { 

	/*!
 	The stack's head indicates the first free position on the stack. 
 	Hence if head = N, the head element will be at memory[head-1]
	*/
	int head; 			

	/*!
	Memory is an array of words that contain the data itself.
	Memory size is controlled by the constant MEMORY_SIZE, 
	which can be found at cvmConfig.h
	*/
	cvmWord* memory; 

	/*!
	current_size tells us how many blocks of MEMORY_SIZE
	a stack has. When initialized, its default value is 1.
	*/	
	int current_size; 
} cvmStack;

/*!
Helper type to hold pointers to cvmStack.
*/
typedef cvmStack* cvmStackp;

#endif