#include "cvmStack.h"
#include "cvmErrors.h"
#include "cvmTypes.h"

int main() {

	cvmStack s;
	cvmWord X = 3;
	cvmWord Y = 5;
	cvmErrorType result = 2;
	cvmWord REGA = 0;
	cvmWord REGB = 0;
	cvmWord Z = 0;

	result = CvmNewStack(&s);

	CvmPush(&s, X);
	
	CvmPush(&s, Y);
	
	CvmPop(&s, &REGA);

	CvmPop(&s, &REGB);

	Z = REGA + REGB;

	printf("Z=%ld\n", Z);

	result = CvmFreeStack(&s);

	printf("Result: %s\n",
		   CvmGetCliErrorMessage(result));

	return 0;
}

