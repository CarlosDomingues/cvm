#ifndef CVMERRORS_H
#define CVMERRORS_H

typedef enum {cvmOK, cvmStackOverflow, cvmStackEmpty} cvmErrorType;

char *
CvmGetCliErrorMessage (cvmErrorType);

#endif