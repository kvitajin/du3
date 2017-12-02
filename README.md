# Velikonoce, velikonoce přicházejí, ...

Realizujte funkci easterReport, která pro zadané roky zjisti data Velikonoc. Funkce uloží výsledný den, měsíc (v textové podobě) a rok jako řádek tabulky do výstupního HTML souboru. Nepovinné: funkci a veškeré pomocné funkce zdrojového souboru okomentujte pomocí nástroje Doxygen.

Úkolem je realizovat funkci s následujícím rozhraním:

int easterReport ( const char * years, const char * outFileName )
years
je vstupní parametr vaší funkce. Jedná se o řetězec, který určuje roky, pro které má funkce vypočítat data Velikonoc. Roky mohou být zadané buď jednotlivě nebo jako intervaly. řetězec může obsahovat více požadovaných roků/intervalů, takové jsou oddělené čárkou. Bílé znaky mimo letopočty ignorujte. Každý rok musí být vetší než 1582 (přechod na Gregoriánský kalendář) a menší než 2200. Pokud je zadaný interval, pak počáteční rok intervalu musí být menší nebo roven koncovému roku intervalu. Pokud je zadaný nesprávný vstup, funkce nic nedělá a vrací odpovídající chybový kód (viz níže).
outFileName
je řetězec se jménem výstupního souboru. Jméno souboru se může skládat z číslic, písmen, znaků tečka, dopředné a zpětné lomítko. Výstupní soubor navíc musí mít příponu ".html". Pokud jméno výstupního souboru nesouhlasí, funkce nic nedělá a vrací odpovídající chybový kód (viz níže). Pokud je jméno souboru správně, funkce do něj vygeneruje požadovaný HTML výstup. Pro každý z roků uvedených na vstupu funkce bude existovat jeden řádek tabulky v tomto vygenerovaném souboru.
návratová hodnota
návratovou hodnotou funkce je rozlišení úspěchu/neúspěchu volání. Jsou definované následující chybové kódy:
EASTER_OK pro úspěšné dokončení funkce.
EASTER_INVALID_FILENAME bude vráceno, pokud jméno výstupního souboru neodpovídá kritériím výše.
EASTER_INVALID_YEARS bude vráceno pokud vstupní řetězec nebyl správný (obsahoval špatně formátované roky/intervaly/nečíselné hodnoty ...).
EASTER_IO_ERROR bude vráceno, pokud při zpracování výstupního souboru došlo k I/O chybě.
Funkce nejprve kontroluje správnost jména výstupního souboru. Teprve pokud projde, kontroluje se řetězec s roky. Tedy pokud by funkce byla zavolaná s neplatným seznamem roků i s neplatným jménem souboru, vracela by hodnotu EASTER_INVALID_FILENAME.
Algoritmus pro výpočet (Meeus/Jones/Butcher algorithm): Zadaný rok z Gregoriánského kalendáře označme Y. Pro výpočet data Velikonoc je použit následující algoritmus:

Y vydělíme 19 a získáme podíl (ten ignorujeme) a zbytek po dělení označíme A. To je pozice roku v 19-letém lunárním cyklu. (A+1 je tzv. Zlaté číslo)
Y vydělíme 100 a získáme podíl B a zbytek C
B vydělíme 4 a získáme podíl D a zbytek E
B + 8 vydělíme 25 a získáme podíl F
(B - F + 1) vydělíme 3 a získáme podíl G
19A + B – D – G + 15 vydělíme 30 a získáme podíl (ignorujeme) a zbytek H
C vydělíme 4 a získáme podíl I a zbytek K
(32 + 2E + 2I - H - K) vydělíme 7 a získáme podíl (ignorujeme) a zbytek L
(A + 11H + 22L) vydělíme 451 a získáme podíl M
(H + L - 7M + 114) vydělíme 31 a získáme podíl N a zbytek P.
Velikonoční neděle je (P+1)-tý den a N-tý měsíc (N=3 pro březen a N=4 pro duben) v roce Y.
pozn.: Je použito celočíselné dělení.
Odevzdávejte zdrojový kód obsahující Vaší implementaci požadované funkce easterReport. V odevzdávaném zdrojovém souboru musí být implementace této funkce a implementace všech Vašich dalších pomocných funkcí. Vkládání hlavičkových souborů a funkci main ponechte v bloku podmíněného překladu, jak je ukázáno v následující ukázce. Doporučujeme zkopírovat si šablonu do Vašeho projektu a doplnit požadované implementace funkcí.

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

int easterReport ( const char * years, const char * outFileName )
 {
   /* todo */
 }

#ifndef __PROGTEST__
int main ( int argc, char * argv[] )
 {
   /* tests */
   return 0;
 }
#endif /* __PROGTEST__ */
Dodržte přesně formát výstupního souboru i chybových hlášení Výstupní soubor musí přesně odpovídat ukázkám. Testování provádí stroj, který kontroluje obsah na přesnou shodu. Pokud se obsah Vašeho výstupního souboru liší od referenčního výstupu,je Vaše odpověď považovaná za nesprávnou. Záleží i na mezerách, i na odřádkování. Nezapomeňte na odřádkování za posledním řádkem výstupu. Využijte přiložený archiv obsahující požadovaný výstup pro ukázkové vstupy.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti (ale tato úloha by ani s jedním omezením neměla mít problém). Testovací prostředí dále zakazuje používat některé "nebezpečné funkce" -- funkce pro spouštění programu, pro práci se sítí, ... Pokud jsou tyto funkce použité, program se nespustí.

Ukázka práce programu:
easterReport ( "2012,2013,2015-2020", "out0.html" ); /* return: 0 */
/* file out0.html:
------8<-----
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>C++</title>
</head>
<body>
<table width="300">
<tr><th width="99">den</th><th width="99">mesic</th><th width="99">rok</th></tr>
<tr><td>8</td><td>duben</td><td>2012</td></tr>
<tr><td>31</td><td>brezen</td><td>2013</td></tr>
<tr><td>5</td><td>duben</td><td>2015</td></tr>
<tr><td>27</td><td>brezen</td><td>2016</td></tr>
<tr><td>16</td><td>duben</td><td>2017</td></tr>
<tr><td>1</td><td>duben</td><td>2018</td></tr>
<tr><td>21</td><td>duben</td><td>2019</td></tr>
<tr><td>12</td><td>duben</td><td>2020</td></tr>
</table>
</body>
</html>
------8<-----
*/

easterReport ( "2000 - 2014", "out1.html" ); /* return: 0 */
/* file out1.html:
------8<-----
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>C++</title>
</head>
<body>
<table width="300">
<tr><th width="99">den</th><th width="99">mesic</th><th width="99">rok</th></tr>
<tr><td>23</td><td>duben</td><td>2000</td></tr>
<tr><td>15</td><td>duben</td><td>2001</td></tr>
<tr><td>31</td><td>brezen</td><td>2002</td></tr>
<tr><td>20</td><td>duben</td><td>2003</td></tr>
<tr><td>11</td><td>duben</td><td>2004</td></tr>
<tr><td>27</td><td>brezen</td><td>2005</td></tr>
<tr><td>16</td><td>duben</td><td>2006</td></tr>
<tr><td>8</td><td>duben</td><td>2007</td></tr>
<tr><td>23</td><td>brezen</td><td>2008</td></tr>
<tr><td>12</td><td>duben</td><td>2009</td></tr>
<tr><td>4</td><td>duben</td><td>2010</td></tr>
<tr><td>24</td><td>duben</td><td>2011</td></tr>
<tr><td>8</td><td>duben</td><td>2012</td></tr>
<tr><td>31</td><td>brezen</td><td>2013</td></tr>
<tr><td>20</td><td>duben</td><td>2014</td></tr>
</table>
</body>
</html>
------8<-----
*/

easterReport ( "2001 , 2002  ,  2003 ,2005,2006", "out2.html" ); /* return: 0 */
/* file out2.html:
------8<-----
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>C++</title>
</head>
<body>
<table width="300">
<tr><th width="99">den</th><th width="99">mesic</th><th width="99">rok</th></tr>
<tr><td>15</td><td>duben</td><td>2001</td></tr>
<tr><td>31</td><td>brezen</td><td>2002</td></tr>
<tr><td>20</td><td>duben</td><td>2003</td></tr>
<tr><td>27</td><td>brezen</td><td>2005</td></tr>
<tr><td>16</td><td>duben</td><td>2006</td></tr>
</table>
</body>
</html>
------8<-----
*/

easterReport ( "2000,2011,2010-2020", "out3.html" ); /* return: 0 */
/* file out3.html:
------8<-----
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>C++</title>
</head>
<body>
<table width="300">
<tr><th width="99">den</th><th width="99">mesic</th><th width="99">rok</th></tr>
<tr><td>23</td><td>duben</td><td>2000</td></tr>
<tr><td>24</td><td>duben</td><td>2011</td></tr>
<tr><td>4</td><td>duben</td><td>2010</td></tr>
<tr><td>24</td><td>duben</td><td>2011</td></tr>
<tr><td>8</td><td>duben</td><td>2012</td></tr>
<tr><td>31</td><td>brezen</td><td>2013</td></tr>
<tr><td>20</td><td>duben</td><td>2014</td></tr>
<tr><td>5</td><td>duben</td><td>2015</td></tr>
<tr><td>27</td><td>brezen</td><td>2016</td></tr>
<tr><td>16</td><td>duben</td><td>2017</td></tr>
<tr><td>1</td><td>duben</td><td>2018</td></tr>
<tr><td>21</td><td>duben</td><td>2019</td></tr>
<tr><td>12</td><td>duben</td><td>2020</td></tr>
</table>
</body>
</html>
------8<-----
*/

easterReport ( "2000-3000", "out4.html" ); /* return: 2 */
