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
         //std::cout <<   "jsem zde " << i<<  " "<<tmp<<std::endl;
         if (roky[i]==',' || roky[i]==' '){
             continue;
         }
         else if (roky[i]=='-'){
             for (int j = 0; j < 4; ++j) {
                 ++i;

                 while(roky[i]==' ')++i;
                 tmp*=10;
                 tmp+=roky[i]-48;
                 //std::cout    <<   "\t\t\t inside shit" << i<<  " "<<    tmp<<std::endl;
             }
             vymez=tmp;
             if (vymez>2200){
                 return EASTER_INVALID_YEARS;
             }
             while (vymez!=pred){
                 ++pred;
                 pole.push_back(pred);
             }
             //pole.push_back(vymez);                                         //todo kontrolovat tady toto, jestli nezapisuju dvakrat posledni cislo
             continue;
         }
         else if (isalpha(roky[i])){
             std::cout <<   "pismeno " << i<<std::endl;

             return EASTER_INVALID_YEARS;
         }
         //std::cout <<   "jsem zde pred zapisem " << i<<  " "<<tmp<< " "<< pred<<std::endl;
         tmp*=10;
         tmp+=roky[i]-48;
         //std::cout <<   "jsem zde po zapisu " << i<<  " "<<tmp<< " "<< pred<<std::endl;
         if (tmp>1582 && tmp<=2200){
             pole.push_back(tmp);
             pred=tmp;
             tmp=0;
         }
         else if (tmp>2200 || (tmp>1000 && tmp<1582)){
             std::cout <<   "mrdam na to spatny rok " << i<<std::endl;
             //std::cout <<   "jsem zde " << tmp<<std::endl;
             return EASTER_INVALID_YEARS;
         }
     }

     for (auto k = 0; k < pole.size(); ++k) {
         std::cout  <<  pole[k] <<  " ";
     }
     std::cout <<   std::endl;
     int a, b, c, d, e, f, g, h, i, k, l, m, n, p, pom;
     /* 1)Y vydělíme 19 a získáme podíl (ten ignorujeme) a zbytek po dělení označíme A. To je pozice roku v 19-letém
            lunárním cyklu. (A+1 je tzv. Zlaté číslo)
        2)Y vydělíme 100 a získáme podíl B a zbytek C
        3)B vydělíme 4 a získáme podíl D a zbytek E
        4)B + 8 vydělíme 25 a získáme podíl F
        5)(B - F + 1) vydělíme 3 a získáme podíl G
        6)19A + B – D – G + 15 vydělíme 30 a získáme podíl (ignorujeme) a zbytek H
        7)C vydělíme 4 a získáme podíl I a zbytek K
        8)(32 + 2E + 2I - H - K) vydělíme 7 a získáme podíl (ignorujeme) a zbytek L
        9)(A + 11H + 22L) vydělíme 451 a získáme podíl M
        10)(H + L - 7M + 114) vydělíme 31 a získáme podíl N a zbytek P.
        11)Velikonoční neděle je (P+1)-tý den a N-tý měsíc (N=3 pro březen a N=4 pro duben) v roce Y.*/
     std::string vystup="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n"
             "<html>\n"
             "<head>\n"
             "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n"
             "<title>C++</title>\n"
             "</head>\n"
             "<body>\n"
             "<table width=\"300\">\n"
             "<tr><th width=\"99\">den</th><th width=\"99\">mesic</th><th width=\"99\">rok</th></tr>\n";

     for (int z = 0; z < pole.size(); ++z) {        //todo mam tam dve L-ka
         a=pole[z]%19;              //1

         b=pole[z]/100;             //2
         c=pole[z]%100;

         d=b/4;                     //3
         e=b%4;

         f=(b+8)/3;                 //4

         g=(b-f+1/3);               //5

         h=(19*a+b-d+g+15)%30;      //6

         i=c/4;                     //7
         k=c%4;

         l=(32+2*e +2*i-h-k)%7;     //8

         m=(a+11*h+22*l)/451;       //9

         n=(h+l-7*m+114)/31;        //10
         p=(h+l-7*m+114)%31;

         vystup+="<tr><td>";
         vystup += std::to_string(p+1);
        switch (n){
            case 1:
                vystup+="</td><td>leden</td><td>";
                break;
            case 2:
                vystup+="</td><td>unor</td><td>";
                break;
            case 3:
                vystup+="</td><td>brezen</td><td>";
                break;
            case 4:
                vystup+="</td><td>duben</td><td>";
                break;
            case 5:
                vystup+="</td><td>kveten</td><td>";
                break;
            case 6:
                vystup+="</td><td>cerven</td><td>";
                break;
            case 7:
                vystup+="</td><td>cervenec</td><td>";
                break;
            case 8:
                vystup+="</td><td>srpen</td><td>";
                break;
            case 9:
                vystup+="</td><td>zari</td><td>";
                break;
            case 10:
                vystup+="</td><td>rijen</td><td>";
                break;
            case 11:
                vystup+="</td><td>listopad</td><td>";
                break;
            case 12:
                vystup+="</td><td>prosinec</td><td>";
                break;
            }
         vystup+= std::to_string(pole[z]);
         vystup+="</td></tr>\n";
     }
     vystup+="</table>\n</body>\n</html>\n";
     std::cout  <<  vystup;
     return EASTER_OK;
 }

#ifndef __PROGTEST__
int main ( int argc, char * argv[] )
 {
     easterReport ( "2001 , 2002  ,  2003 ,2005,2006", "out2.html" );
     std::cout <<"-------------------------------------------------------------------------------"<<std::endl;
     easterReport ( "2000 - 2014", "out1.html" );
     std::cout <<"-------------------------------------------------------------------------------"<<std::endl;
     easterReport ( "2001 , 2002  ,  2003 ,2005,2006", "out2.html" );
     std::cout <<"-------------------------------------------------------------------------------"<<std::endl;
     easterReport ( "2000,2011,2010-2020", "out3.html" );
     std::cout <<"-------------------------------------------------------------------------------"<<std::endl;
     easterReport ( "2000-3000", "out4.html" );
 }
#endif /* __PROGTEST__ */