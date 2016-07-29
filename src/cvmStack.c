#include <stdlib.h>

//for debbug
#include <stdio.h>

#include "cvmStack.h"
#include "cvmConfig.h"
#include "cvmErrors.h"

cvmErrorType CvmNewStack(cvmStackp s) {

	s->head = 0;
	s->memory = malloc((MEMORY_SIZE) * sizeof(cvmWord));	      
	s->current_size = 1;
	
	return cvmOK;
}

cvmErrorType CvmFreeStack(cvmStackp s) {

	free(s->memory);
	s->head = 0;
	return cvmOK;
}

cvmErrorType CvmPush(cvmStackp s, cvmWord w) {

	/*
	if (s->head == s->current_size) {
		s->current_size += MEMORY_SIZE;
		s->memory = realloc(s->memory, s->current_size * sizeof(cvmWord));
	}
	*/

	if (s->head >= MEMORY_SIZE){
		return cvmStackOverflow;
	}
	s->memory[s->head] = w;
	s->head++;
	return cvmOK;
}

cvmErrorType CvmPop(cvmStackp s, cvmWord* w) {
	  
	if (s->head == 0) { 
		return cvmStackEmpty;
	}
	
	s->head--;
	*w = s->memory[s->head];
	  
	return cvmOK;
}

//pek - read without pop

