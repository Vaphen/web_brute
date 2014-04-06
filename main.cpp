#include <iostream>	// cout
#include "param.h"	// getParams
#include "m_threads.h" // Start threads & brute

typedef unsigned int un_int;

int main(int argc, char **argv){
  Param myParams(argc, argv);
  myParams.setParams();
  m_threads myThreads;
  myThreads.start_threads();
  return 1;
}
