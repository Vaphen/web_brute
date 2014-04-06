#ifndef _PARAM_H_INCLUDED_
#define _PARAM_H_INCLUDED_

#include <iostream>
#include <unistd.h>	// getopt()

typedef unsigned int un_int;

class Param{
public:
    Param(int &argc, char **argv);
    Param();
    ~Param();
    void setParams();
private:  
  int argc;
  char **argv;
  void showHelp() const;
  typedef struct process_infos{
    un_int	th_num;
    std::string uri;
    un_int	len_min;
    un_int	len_size;
    char	astr;
    process_infos() : th_num(1), uri("google.de"), len_min(4), len_size(6), astr('a'){} 
  } p_info;
protected:
  static p_info pInfos;
};

#endif
