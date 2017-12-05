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

int zapis(std::string &vystup, std::string &file){
    int flag=0;
    int i;
    if (file.size()<6){
        return EASTER_INVALID_FILENAME;
    }
    for (i = 0; i <(int)file.size()-5; ++i) {
        if (!std::cin.fail()              &&
            ((file[i]>='A'&& file[i]<='Z') ||
             (file[i]>='a'&& file[i]<='z') ||
             (file[i]>='0'&& file[i]<='9') ||
              file[i]=='\\'|| file[i]=='/' || file[i]=='.')){
        }else ++flag;
    }

    /*for (int j = i; j < file.size(); ++j) {
        std::cout   <<      file[j];
    }*/

    if(file[i]!='.' || file[++i]!='h' || file[++i]!='t' || file[++i]!='m' || file[++i]!='l'){
        return EASTER_INVALID_FILENAME;
    }
    if (flag){
        //std::cout <<    "flag"  << flag;
        return EASTER_INVALID_FILENAME;
    }

    ofstream ofs;
    ofs.open(file.c_str());
    if(ofs){
        ofs <<  vystup;
        ofs.close();
        return EASTER_OK;
    } else{
        return EASTER_IO_ERROR;
    }

}

int easterReport ( const char * years, const char * outFileName )
 {

     std::string roky=years;
     std::vector<int> pole;
     int tmp=0, pred=0, vymez=0;
     for (int i = 0; i < (int)roky.length(); ++i) {
         //std::cout <<   "jsem zde " << i<<  " "<<tmp<<std::endl;
         if (roky[i]==' '){
             continue;
         }
         else if ((roky[i]==',' && tmp!=0)||(i==(int)roky.length() && tmp!=0)){
             if (tmp<1582 || tmp>2200){
                 //std::cout  <<"merde " << pred<<" "<<tmp<<std::endl;
                 return EASTER_INVALID_YEARS;
             }
         }
         else if (roky[i]==','){
             continue;
         }
         else if (roky[i]=='-' && i<5){
             return EASTER_INVALID_YEARS;
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
             if (vymez<pred){
                 return EASTER_INVALID_YEARS;
             }
             while (vymez!=pred){
                 ++pred;
                 pole.push_back(pred);
             }
             //pole.push_back(vymez);
             continue;
         }
         else if (isalpha(roky[i])){
             //std::cout <<   "pismeno " << i<<std::endl;

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
             //std::cout <<   "mrdam na to spatny rok " << i<<std::endl;
             //std::cout <<   "jsem zde " << tmp<<std::endl;
             return EASTER_INVALID_YEARS;
         }
     }

     /*for (auto k = 0; k < pole.size(); ++k) {
         std::cout  <<  pole[k] <<  " ";
     }
     std::cout <<   std::endl;*/
     int a, b, c, d, e, f, g, h, i, k, l, m, n, p;

     std::string vystup="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n"
             "<html>\n"
             "<head>\n"
             "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n"
             "<title>C++</title>\n"
             "</head>\n"
             "<body>\n"
             "<table width=\"300\">\n"
             "<tr><th width=\"99\">den</th><th width=\"99\">mesic</th><th width=\"99\">rok</th></tr>\n";
     /* 1)Y vydělíme 19 a získáme podíl (ten ignorujeme) a zbytek po dělení označíme A. To je pozice roku v 19-letém
            lunárním cyklu. (A+1 je tzv. Zlaté číslo)
        2) Y vydělíme 100 a získáme podíl B a zbytek C
        3) B vydělíme 4 a získáme podíl D a zbytek E
        4) B + 8 vydělíme 25 a získáme podíl F
        5) (B - F + 1) vydělíme 3 a získáme podíl G
        6) 19A + B – D – G + 15 vydělíme 30 a získáme podíl (ignorujeme) a zbytek H
        7) C vydělíme 4 a získáme podíl I a zbytek K
        8) (32 + 2E + 2I - H - K) vydělíme 7 a získáme podíl (ignorujeme) a zbytek L
        9) (A + 11H + 22L) vydělíme 451 a získáme podíl M
        10)(H + L - 7M + 114) vydělíme 31 a získáme podíl N a zbytek P.
        11)Velikonoční neděle je (P+1)-tý den a N-tý měsíc (N=3 pro březen a N=4 pro duben) v roce Y.*/

     for (int z = 0; z < (int)pole.size(); ++z) {
         a=pole[z]%19;              //1

         b=pole[z]/100;             //2
         c=pole[z]%100;

         d=b/4;                     //3
         e=b%4;

         f=(b+8)/25;                 //4

         g=(b-f+1)/3;               //5

         h=(19*a+b-d-g+15)%30;      //6

         i=c/4;                     //7
         k=c%4;

         l=(32+2*e +2*i-h-k)%7;     //8

         m=(a+11*h+22*l)/451;       //9

         n=(h+l-7*m+114)/31;        //10
         p=(h+l-7*m+114)%31;

         vystup+="<tr><td>";
         vystup += std::to_string((p+1));
        switch (n){
            case 3:
                vystup+="</td><td>brezen</td><td>";
                break;
            case 4:
                vystup+="</td><td>duben</td><td>";
                break;
            default:
                break;
            }
         vystup+= std::to_string(pole[z]);
         vystup+="</td></tr>\n";
     }
     vystup+="</table>\n</body>\n</html>\n";
    // std::cout  <<  vystup;                             //todo smazat
     std::string file=outFileName;

     tmp=zapis(vystup, file);
     return tmp;
     return EASTER_OK;
 }

#ifndef __PROGTEST__
int main ( int argc, char * argv[] ) {
    int tmp;

    tmp = easterReport ( "2012,2013,2015-2020", "out0.html" );
    std::cout << tmp << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    tmp = easterReport ( "2000 - 2014-", "out1.html" );
    std::cout << tmp << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    tmp = easterReport ( "2001 , 2002 ,951 ,  2003 ,2005,2006", "out2.html" );
    std::cout << tmp << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    tmp = easterReport("2000,2011,2010-2020", "out3.html");
    std::cout << tmp << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    tmp = easterReport("", "out4.html");
    std::cout << tmp << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    return 0;
}

#endif /* __PROGTEST__ */