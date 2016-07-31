#include <stdio.h>

#include "cvmErrors.h"
#include "cvmTypes.h"
#include "cvmStack.h"

static char *cvmByteCode[4] = {

	"HALT",
	"PUSH",
	"POP",
	"ADD"
};


//change to return struct traceback later = stack error code, +current ip, + current instruction, etc
//can use goto to return traceback?
cvmErrorType cvmCpuRun(unsigned short code[], unsigned code_size){

	unsigned ip = 0;
	unsigned bytecode = 0;

	cvmStack s;

	CvmNewStack(&s);

	while(ip != code_size){
		
		bytecode = code[ip];

	    switch(bytecode) {
	        case 0 :
	            printf("HALT\n" );
	            ip++;
	            break;
	        case 1 :
	            printf("PUSH\n" );
	        	ip++;
	        	break;
			case 2 :
	            printf("POP\n" );
	        	ip++;
	        	break;
			default :
	      	    printf("Invalid bytecode\n" );
	   			ip++;
	   			break;
	    }
	}

	CvmFreeStack(&s);

	return cvmOK;
}