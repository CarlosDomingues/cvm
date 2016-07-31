#ifndef CVMERRORS_H
#define CVMERRORS_H

typedef enum {cvmOK, cvmStackOverflow, cvmStackEmpty, cvmStackNeeds2Operands} cvmErrorType;

char *
CvmGetCliErrorMessage (cvmErrorType);

#endif