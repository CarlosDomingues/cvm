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

cvmErrorType CvmPeek(cvmStackp s, cvmWord* w) {
	  
	if (s->head == 0) { 
		return cvmStackEmpty;
	}

	*w = s->memory[(s->head) - 1];
	  
	return cvmOK;
}


cvmErrorType CvmAdd(cvmStackp s) {

	if ((s->head == 0) || (s->head ==1)) { 
		return cvmStackNeeds2Operands;
	}

	s->memory[(s->head) - 2] = s->memory[(s->head) - 1] + s->memory[(s->head) - 2];

	s->head --;

	return cvmOK;
}


cvmErrorType CvmMultiply(cvmStackp s) {

	if ((s->head == 0) || (s->head ==1)) { 
		return cvmStackNeeds2Operands;
	}

	s->memory[(s->head) - 2] = s->memory[(s->head) - 1] * s->memory[(s->head) - 2];

	s->head --;

	return cvmOK;
}


cvmErrorType CvmSwap(cvmStackp s) {

	cvmWord REGA;
	  
	if ((s->head == 0) || (s->head ==1)) { 
		return cvmStackNeeds2Operands;
	}

	REGA = s->memory[(s->head) - 1];

	s->memory[(s->head) - 1] = s->memory[(s->head) - 2];

	s->memory[(s->head) - 2] = REGA;

	return cvmOK;
}


cvmErrorType CvmPrint(cvmStackp s){ 
	  
	int aux_counter = s->head;
	
	while(aux_counter > 0){
		printf("%d\n", s->memory[aux_counter - 1]);
		aux_counter--;
	}

	return cvmOK;
}


cvmErrorType CvmNop(cvmStackp s) {

	//maybe should check for null pointer?

	return cvmOK;
}

cvmErrorType CvmDuplicate(cvmStackp s){


	if (s->head >= MEMORY_SIZE){
		return cvmStackOverflow;
	}

	if (s->head == 0){
		return cvmStackEmpty;
	}


	s->memory[(s->head)] = s->memory[(s->head) - 1];

	s->head++;
	
	return cvmOK;
}


//multi N
//ADD N