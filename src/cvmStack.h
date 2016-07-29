#ifndef CVMSTACK_H
#define CVMSTACK_H

//for files
#include <stdio.h>

#include "cvmTypes.h"
#include "cvmErrors.h"


cvmErrorType CvmNewStack(cvmStackp s);
cvmErrorType CvmFreeStack(cvmStackp s);

cvmErrorType CvmPush(cvmStackp s, cvmWord w);
cvmErrorType CvmPop(cvmStackp p, cvmWord* w);

/* extension */
cvmStackp read(FILE*);
void write(cvmStackp, FILE*);

#endif
