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
  cvmWord Y = 5;

  CvmNewStack(&s);

  for(index =0; index < MEMORY_SIZE; index++){
    CvmPush(&s, index); 
  }
  

  
  _it_should("Should return \"cvmStackOverflow\" if cvmWord is added to a full stack.", 
  (CvmPush(&s, Y) == cvmStackOverflow));
  

  
  _it_should("The stack head attribute should stay the same after an unsuccessfull push", 
  (s.head == MEMORY_SIZE));
  

  
  _it_should("The stack head value should stay the same after an unsuccessfull push", 
  (s.memory[MEMORY_SIZE-1] == MEMORY_SIZE-1));

  CvmFreeStack(&s);
}


//------------------------------------------------
// CvmAdd()                      
//------------------------------------------------

void CvmAdd_01() 
{
  cvmWord REGA; 
  cvmStack s;

  CvmNewStack(&s);
  CvmPush(&s, 5);
  CvmPush(&s, 4);
  
  _it_should("Should return \"cvmOK\" after sucessfull add operation.", 
  (CvmAdd(&s) == cvmOK));
  
  _it_should("The stack head attribute be decreased by one", 
  (s.head == 1));
  
  _it_should("The stack head value should be the sum of the head and head -1", 
  (s.memory[(s.head)-1] == 9));

  _it_should("Should return \"cvmStackNeeds2Operands\" if there's only one element in stack.", 
  (CvmAdd(&s) == cvmStackNeeds2Operands));

  CvmPop(&s, &REGA);

  _it_should("Should return \"cvmStackNeeds2Operands\" if there are no elements in stack.", 
  (CvmAdd(&s) == cvmStackNeeds2Operands));

  CvmFreeStack(&s);
}

//------------------------------------------------
// CvmMultiply()                      
//------------------------------------------------

void CvmMultiply_01() 
{
  cvmWord REGA; 
  cvmStack s;

  CvmNewStack(&s);
  CvmPush(&s, 5);
  CvmPush(&s, 4);
  
  _it_should("Should return \"cvmOK\" after sucessfull add operation.", 
  (CvmMultiply(&s) == cvmOK));
  
  _it_should("The stack head attribute be decreased by one", 
  (s.head == 1));
  
  _it_should("The stack head value should be the miltiplication of the head and head -1", 
  (s.memory[(s.head)-1] == 20));

  _it_should("Should return \"cvmStackNeeds2Operands\" if there's only one element in stack.", 
  (CvmMultiply(&s) == cvmStackNeeds2Operands));

  CvmPop(&s, &REGA);

  _it_should("Should return \"cvmStackNeeds2Operands\" if there are no elements in stack.", 
  (CvmMultiply(&s) == cvmStackNeeds2Operands));

  CvmFreeStack(&s);
}


//------------------------------------------------
// CvmSwap()                      
//------------------------------------------------

/** \example CvmSwap
 * This is an example of how to use CvmSwap function.
 * More details about this example.
 */
void CvmSwap_01() 
{
  cvmWord REGA; 
  cvmStack s;

  CvmNewStack(&s);
  CvmPush(&s, 5);
  CvmPush(&s, 4);
  
  _it_should("Should return \"cvmOK\" after sucessfull swap operation.", 
  (CvmSwap(&s) == cvmOK));
  
  _it_should("The stack head attribute should remain the same.", 
  (s.head == 2));
  
  _it_should("The stack head -1 value should be the value of head - 2 before swapping", 
  (s.memory[(s.head)-1] == 5));

  CvmPop(&s, &REGA);

  _it_should("Should return \"cvmStackNeeds2Operands\" if there's only one element in stack.", 
  (CvmSwap(&s) == cvmStackNeeds2Operands));

  CvmPop(&s, &REGA);

  _it_should("Should return \"cvmStackNeeds2Operands\" if there are no elements in stack.", 
  (CvmSwap(&s) == cvmStackNeeds2Operands));

  CvmFreeStack(&s);
}

//------------------------------------------------
// CvmDuplicate()                      
//------------------------------------------------

void CvmDuplicate_01() 
{
  cvmWord REGA; 
  cvmStack s;
  int index =0;

  CvmNewStack(&s);
  CvmPush(&s, 5);
  
  _it_should("Should return \"cvmOK\" after sucessfull Duplicate operation.", 
  (CvmDuplicate(&s) == cvmOK));
  
  _it_should("The stack head attribute should be increased by one.", 
  (s.head == 2));
  
  _it_should("The stack head -1 value should be the value of head - 2 before duplication.", 
  (s.memory[(s.head)-1] == 5));

  _it_should("The stack head -2 value should remain the same.", 
  (s.memory[(s.head)-1] == 5));

  CvmPop(&s, &REGA);

  CvmPop(&s, &REGA);

  _it_should("Should return \"cvmStackEmpty\" if the stack is empty.", 
  (CvmDuplicate(&s) == cvmStackEmpty));

  for(index =0; index < MEMORY_SIZE; index++){
    CvmPush(&s, index); 
  }

  _it_should("Should return \"cvmStackOverflow\" if head equals memory sizes.", 
  (CvmDuplicate(&s) == cvmStackOverflow));

  CvmFreeStack(&s);
}



//------------------------------------------------
// Run all tests                      
//------------------------------------------------



void run_tests() 
{

  _test_start("CvmAdd");
  CvmAdd_01();

  _test_start("CvmDuplicate");
  CvmDuplicate_01();

  _test_start("CvmMultiply");
  CvmMultiply_01();

  _test_start("CvmPush");
  CvmPush_01();
  CvmPush_02();

  _test_start("CvmPop");
  CvmPop_01();

  _test_start("CvmSwap");
  CvmSwap_01();


}



int main(int argc, char **argv)
{        

  run_tests();

  _test_result();

  return OK;
}
