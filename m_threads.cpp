#include <vector>       // std::vector
#include <thread>       // std::thread
#include <cmath>
#include "m_threads.h"  // Header
#include "brute.h"      // bruteforcing

m_threads::m_threads() : Param() {}

m_threads::~m_threads(){}

void m_threads::start_threads(){
  std::vector<std::thread> brute_threads;		// Thread-Vektor
  for(un_int i = 0; i < pInfos.th_num; i++){		// pInfos.max_threads einfuegen
    Brute myBrute;
    brute_threads.push_back(std::thread(myBrute));
  }
  for(auto& th : brute_threads){
    th.join();						// Threads ausfuehren
  }
  std::cout << "Bruteforce beendet. Es wurde kein Passwort gefunden." << std::endl;
}
