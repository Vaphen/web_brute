#include "brute.h"

Brute::Brute() : Param(), min_astriction(33), max_astriction(127) {}

Brute::~Brute(){}

void Brute::brute_impl(char* str, int index, int max_depth)
{
  static un_int pw_state = 0;
  for(int i = 33; i < 127; i++){
    str[index] = static_cast<char>(i);
    if (index == max_depth - 1){
      if(str == password_test){
	std::cout << "Passwort: " << str << std::endl;
	exit(EXIT_SUCCESS);
      }
    }else{
      pw_state++;
      brute_impl(str, index + 1, max_depth);
    }
  }
}

void Brute::start_brute(){
  get_astriction();
  unsigned long long max_trys = 0;
  for(un_int s = pInfos.len_min; s <= pInfos.len_size; s++) max_trys += pow(94, s);
  std::cout << "Maximale Versuche: " << max_trys << std::endl;
  char *buf = new (std::nothrow) char[pInfos.len_size];
  if(buf == nullptr) { std::cerr << "FEHLER! Speicher konnte nicht alloziiert werden." << std::endl; exit(EXIT_FAILURE); }
 
  unsigned long long trys_pp = max_trys / pInfos.th_num;	// Trys Per Process
  std::string last_pw;
  do{
    last_pw.push_back(static_cast<char>(((trys_pp * thread_num) % 94) + 33));
    trys_pp = round(trys_pp / 94);
  }while(trys_pp > 94);
  std::cout << last_pw << std::endl;
  
  for(un_int j = pInfos.len_min; j <= pInfos.len_size; j++){
    for(un_int k = 0; k < sizeof(buf); k++) buf[k] = 0;
    brute_impl(buf, 0, j);
  }
  delete[] buf;
}

void Brute::get_astriction(){
  switch(pInfos.astr){
    case 'c': min_astriction = 65; max_astriction = 90; break;	// char astriction
    case 'n': min_astriction = 48; max_astriction = 57; break;	// number astriction
    case 'b': break;						// both astriction (ohne Sonderzeichen)
  }
}

void Brute::operator()() {
  start_brute();
}
