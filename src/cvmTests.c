//printf, remove
#include <stdio.h>

//malloc
#include <stdlib.h>

#include "cvmConfig.h"
#include "cvmStack.h"
#include "cvmErrors.h"
#include "cvmTypes.h"
#include "cvmTests.h"

#define OK  0

//BUGS: 

//If I create an unitialized pointer and pass it to a function 
// then run it in test_run, it wont detect its unitialized unless
// I explicitly define it as type *pointer = NULL
//EDIT: This is not a bug, pointers in C are NOT guaranted to
// be initialied as NULL!

//------------------------------------------------
// CvmPush()                      
//------------------------------------------------
void CvmPop_01(){

  cvmStack s;
  cvmWord X = 3;
  cvmWord REGA = 0;

  CvmNewStack(&s);

  CvmPush(&s, X); 

  _it_should("Should return \"cvmOk\" if cvmWord is popped of the stack successfully.", 
  (CvmPop(&s, &REGA) == cvmOK));

  _it_should("The stack head should be decremented after a sucessfull pop.", 
  (s.head == 0));  

  _it_should("The register value after pop should be equal to the beforehand pushed value", 
  (REGA == 3));

  _it_should("Should return \"cvmStackEmpty\" if cvmWord is popped of an empty stack.", 
  (CvmPop(&s, &REGA) == cvmStackEmpty));

  CvmFreeStack(&s);
}

//------------------------------------------------
// CvmPush()                      
//------------------------------------------------

void CvmPush_01() 
{
    
  cvmStack s;
  cvmWord X = 3;

  CvmNewStack(&s);

  _it_should("Should return \"cvmOk\" if cvmWord is added to the stack successfully.", 
  (CvmPush(&s, X) == cvmOK));

  _it_should("The stack head should be incremented after sucessfull push.", 
  (s.head == 1));

  CvmFreeStack(&s);
}

void CvmPush_02() 
{
    
  int index = 0; 
  cvmStack s;
  cvmWord X = 3;
  cvmWord Y = 5;

  CvmNewStack(&s);

  for(index =0; index < MEMORY_SIZE; index++){
    CvmPush(&s, X); 
  }
  

  
  _it_should("Should return \"cvmStackOverflow\" if cvmWord is added to a full stack.", 
  (CvmPush(&s, Y) == cvmStackOverflow));
  

  
  _it_should("The stack head attribute should stay the same after an unsuccessfull push", 
  (s.head == MEMORY_SIZE));
  

  
  _it_should("The stack head value should stay the same after an unsuccessfull push", 
  (s.memory[MEMORY_SIZE-1] == X));

  CvmFreeStack(&s);
}


//------------------------------------------------
// Run all tests                      
//------------------------------------------------



void run_tests() 
{
  _test_start("CvmPush");
  CvmPush_01();
  CvmPush_02();

  _test_start("CvmPop");
  CvmPop_01();
}


int main(int argc, char **argv)
{        

  run_tests();

  _test_result();

  return OK;
}
