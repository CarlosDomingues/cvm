#include "cvmErrors.h"
#include "cvmTypes.h"

//[message number]
static char *cvmCliErrorMessages[3] = {
                                          
	"Function successfully executed.",
	"Error: stack overload. Push operation failed.",
	"Error: stack is empty. Pop operation failed."
};


char *
CvmGetCliErrorMessage (cvmErrorType error)
{
  return cvmCliErrorMessages[error];
}