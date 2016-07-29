#ifndef CVMTYPES_H
#define CVMTYPES_H

#include <stdint.h>


typedef int64_t cvmWord;

typedef struct { 
	int head; 
	cvmWord* memory; 
	int current_size; 
} cvmStack;

typedef cvmStack* cvmStackp;

#endif