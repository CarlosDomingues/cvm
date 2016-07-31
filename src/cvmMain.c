#include "cvmStack.h"
#include "cvmErrors.h"
#include "cvmTypes.h"
#include "cvmCPU.h"

int main() {

	unsigned code_size = 5;
	unsigned short code[5] = {1, 2, 1, 0, 5};

	cvmCpuRun(code, code_size);

	return 0;
}

