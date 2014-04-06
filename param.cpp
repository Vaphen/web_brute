#include "param.h"

Param::p_info Param::pInfos;

Param::Param(int &argc, char** argv){
  this->argc = argc;
  this->argv = argv;
}

Param::Param(){}

Param::~Param(){}

void Param::setParams(){
  bool valid = true;				// Wenn false, Programm wird nicht ausgeführt
  char param = 0;				// Parameter fuer getopt
  while((param = getopt(argc, argv, ":t:l:a:m:u:h")) != -1){
      switch(param){
	case 't': 
	  if(atoi(optarg) >= 1){		// Nur ausfuehren wenn optarg eine Zahl und groessergleich eins ist
	    pInfos.th_num = atoi(optarg);
	  }else{
	    std::cerr << "FEHLER! Operation -" << param << " wurde ein falscher Parameter mitgegeben." << std::endl;
	    valid = false;
	  }break;
	case 'm': 
	  if(atoi(optarg) >= 1){
	    pInfos.len_min = atoi(optarg);
	  }else{
	    std::cerr << "FEHLER! Operation -" << param << " wurde ein falscher Parameter mitgegeben." << std::endl;
	    valid = false;
	  }break;
	case 'l':
	  if(atoi(optarg) >= 1){
 	    pInfos.len_size = atoi(optarg);
	  }else{
	    std::cerr << "FEHLER! Operation -" << param << " wurde ein falscher Parameter mitgegeben." << std::endl;
	    valid = false;
	  }break;
	case 'a':
	  if(*optarg == 'c')      pInfos.astr = 'c';
	  else if(*optarg == 'n') pInfos.astr = 'n';
	  else if(*optarg == 'b') pInfos.astr = 'b';
	  else {
	    std::cerr << "FEHLER! Operation -" << param <<  " wurde ein falscheer Parameter mitgegeben." << std::endl;
	    valid = false;
	  } break;
	case 'u': 
	  pInfos.uri = optarg; break;
	case 'h':
	  showHelp(); exit(EXIT_SUCCESS);
	case '?': 
	  std::cerr << "FEHLER! Operation -" << static_cast<char>(optopt) << " wurde Parameterlos mitgegeben oder ist nicht bekannt."  << std::endl;
	  valid = false;
	  break;
	default:  
	  std::cerr   << "FEHLER! Es ist ein unbekannter Fehler in den Paramtern aufgetreten." << std::endl;
	  valid = false;
	  break;
      }
  }
  if(!valid) exit(EXIT_FAILURE);
}

void Param::showHelp() const{			// Hilfeanzeige
  std::cout << "              ##################################             \n";
  std::cout << "              # BruteForce Programm von V4PH3N #             \n";
  std::cout << "              ##################################             \n";
  std::cout << "|-----------------------------------------------------------|\n";
  std::cout << "| Parameter:                                 |   Default    |\n";
  std::cout << "|-----------------------------------------------------------|\n";
  std::cout << "|   -t(hreads)   : Anzahl der Threads        |   1          |\n";
  std::cout << "|   -m(inimum)   : Minimale Passwortlaenge   |   4          |\n";
  std::cout << "|   -l(imit)     : Maximale Passwortlaenge   |   6          |\n";
  std::cout << "|   -u(rl)       : Ziel-URL                  |   google.de  |\n";
  std::cout << "|   -a(striction): Begrenzung                |   Alle       |\n";
  std::cout << "|      c(hars)        nur Buchstaben         |              |\n";
  std::cout << "|      n(umbers)      nur Zahlen             |              |\n";
  std::cout << "|      b(oth)         Zahlen und Buchstaben  |              |\n";
  std::cout << "|   -h(elp)   :    Diese Anzeige             |              |\n";
  std::cout << "|-----------------------------------------------------------|\n";
  std::cout << "Beispiel:                                                  \n";
  std::cout << "   " << argv[0] << " -t 2 -m 3 -l 5 -u vaphen.funpic.de -a c" << std::endl;
}
