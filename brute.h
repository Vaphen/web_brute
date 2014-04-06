#ifndef _BRUTE_H_INCLUDED_
#define _BRUTE_H_INCLUDED_

#include <iostream>
#include <cmath>	// pow(x,y) -> Potenzen
#include <cstdlib>	// exit()
#include "param.h"

const std::string password_test = "0}3l";

class Brute : public Param{
public:
    Brute();
    ~Brute();
   void start_brute();
   void operator()();
private:
    int min_astriction, max_astriction;
    void brute_impl(char* str, int index, int max_depth); 
    void get_astriction();
};
#endif
