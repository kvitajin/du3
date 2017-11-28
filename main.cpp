#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#define EASTER_OK                0
#define EASTER_INVALID_FILENAME  1
#define EASTER_INVALID_YEARS     2
#define EASTER_IO_ERROR          3


#endif /* __PROGTEST__ */

#include <vector>

int easterReport ( const char * years, const char * outFileName )
 {
     ofstream ofs;
     std::string roky=years;
     std::vector<int> pole;
     int tmp=0, pred=0, vymez=0;
     for (int i = 0; i < (int)roky.length(); ++i) {
         std::cout <<   "jsem zde " << i<<  " "<<tmp<<std::endl;
         if (roky[i]==','){
             continue;
         }
         else if (roky[i]=='-'){
             for (int j = 0; j < 4; ++j,++i) {
                 if (isspace(roky[i]))++i;
                 tmp*=10;
                 tmp+=roky[i]-48;
             }
             vymez=tmp;
             while (vymez!=pred){
                 ++pred;
                 pole.push_back(pred);
             }
             pole.push_back(vymez);
         }
         else if (isalpha(roky[i])){
             std::cout <<   "mrdam na to pismeno " << i<<std::endl;

             return EASTER_INVALID_YEARS;
         }
         std::cout <<   "jsem zde pred zapisem " << i<<  " "<<tmp<<std::endl;
         tmp*=10;
         tmp+=roky[i]-48;
         std::cout <<   "jsem zde po zapiseu " << i<<  " "<<tmp<<std::endl;
         if (tmp>1582 && tmp<=2200){
             pole.push_back(tmp);
             pred=tmp;
             tmp=0;
         }
         else if (tmp>2200 || tmp>1000 && tmp<1582){
             std::cout <<   "mrdam na to spatny rok " << i<<std::endl;
             std::cout <<   "jsem zde " << tmp<<std::endl;


             return EASTER_INVALID_YEARS;
         }
     }

     for (auto k = 0; k < pole.size(); ++k) {
         std::cout  <<  pole[k] <<  std::endl;
     }
 }

#ifndef __PROGTEST__
int main ( int argc, char * argv[] )
 {
     easterReport ( "2001 , 2002  ,  2003 ,2005,2006", "out2.html" );
 }
#endif /* __PROGTEST__ */