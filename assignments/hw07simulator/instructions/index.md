<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
  <head>
    <meta HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=utf8">
    <meta http-equiv="cache-control" content="no-cache">
    <link rel="stylesheet" type="text/css" href="default.css" />
    <title>Zadání úlohy z B4B33ALG</title>
  </head>
  <body>
    <!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
    <!-- saved from url=(0111)https://cw.felk.cvut.cz/brute/data/ae/release/2019z_b4b33alg/algzima2019/evaluation/input.php?task=occultations -->
    <html>
      <head>
        <meta http-equiv="Content-Type" content="text/html; charset= charset=UTF-8">
        <meta http-equiv="cache-control" content="no-cache">
        <link rel="stylesheet" type="text/css" href="./Zadání úlohy z A4B33ALG_files/default.css">
        <title>Zadání úlohy z B4B33ALG</title>
      </head>
      <body>
        <div class="main">
          <h2><font color="blue">Simulátor snímkovací družice</font></h2>
          <p align="justify">
            Družice provádí snímkování v tzv. cyklech.  Každý cykl trvá 1 minutu.
            Během snímkování se přístroje družice vždy nacházejí v jednom ze čtyř různých režimů, společných pro všechny přístroje a označených <i>A</i>, <i>B</i>, <i>C</i>, <i>D</i>.
            Režim přístrojů se může měnit na konci každého cyklu, nikdy však během cyklu.
            Snímkování trvá <i>M</i> minut. Plán snímkování je posloupnost délky <i>M</i>, která pro každou minutu 1, 2, ... <i>M</i> specifikuje, ve kterém režimu se v dané minutě (v daném cyklu) přístroje družice nacházejí.
            <br>
            <br>
            Řídíci středisko je si prakticky jisto, že může  pro družici dopředu připravit prakticky libovolný plán snímkování dané délky <i>M</i>.
            <br>
            <br>
            Zároveň se snímkováním družice poběží na Zemi v reálném čase simulátor, který obsahuje kopie přístrojů na družici. Simulátor má stejné režimy přístrojů <i>A</i>, <i>B</i>, <i>C</i>, <i>D</i> a rovněž pracuje v minutových cyklech. Cykly družice a simulátoru budou synchronizovány, v každém okamžiku  činnosti simulátoru musí být přístroje družice i simulátoru ve stejném režimu. 
            <br>
            <br>
            Simulátor je založen na předchozím modelu družice, a má proto některá omezení. První omezení je to, že doba běhu simulátoru, která je <i>K</i> minut, je typicky kratší než doba snímkování <i>M</i>.
            Simulátor nemůže začít pracovat před zahájením snímkování, musí být v činnosti po celou svou dobu běhu a nemůže skončit svou činnost po konci snímkování.
            <br>
            <br>
            Druhé omezení je komplexnější a spočívá v tom, že simulátor většinou nemůže na konci cyklu měnit libovolně režim přístrojů. Simulátor má proto daný fixní procesní seznam, což je několik posloupností, každá má délku <i>K</i> a specifikuje <i>K</i> režimů, kterými simulator projde v jednotlivých cyklech během simulace. Před zahájením činnosti je simulátoru určena jedna z posloupností v procesním seznamu a ta pak určuje simulátoru režim pro každý cykl během simulace. Tato posloupnost musí být vždy volena tak, aby přístroje v simulátoru i na družici byly současně ve stejném režimu.   
            <br>
            <br>
            Řídíci středisko dosud neví, ve kterém okamžiku bude simulator spuštěn během snímkování družice.  Přeje si proto navrhnout plán snímkování pokud možno tak, aby bylo možno spustit simulátor na začátku kteréhokoli cyklu družice během snímkování.
            <br>
            Ukazuje se, že to bude možné, dokonce počet různých plánů snímkování může být dost velký i za uvedených omezujících podmínek.
          </p>
          <h3><font color="blue">Úloha</font></h3>
          <p align="justify">
            Je dán procesní seznam simulátoru a doba snímkování. Určete počet možných plánů snímkování.
          </p>
          <hr>
          <h3><font color="blue">Vstup</font></h3>
          <p align="justify">
            První řádek vstupu obsahuje tři čísla  <i>S</i>, <i>K</i>, <i>M</i> oddělená mezerou, představující počet posloupností v procesním seznamu simulátoru, délku každého z těchto seznamů, to jest počet cyklů v práci 
            simulátoru, a počet cyklů ve snímkování družice.
            Na dalších <i>S</i> řádcích je uveden procesní seznam simulátoru.
            Každý z řádků obsahuje jednu posloupnost seznamu, jako řetězec déky <i>K</i> skládající se výhradně ze symbolů  <i>A</i>, <i>B</i>, <i>C</i>, <i>D</i>.
            <br>
            Platí: 3 &le; <i>S</i> &le; 50, 2 &le; <i>K</i> &le; 10, <i>K</i> &le; <i>M</i> &le; 100.
          </p>
          <h3><font color="blue">Výstup</font></h3>
          <p align="justify">
            Výstup obsahuje jeden textový řádek s jediným celým číslem <i>P</i>   představujícím počet možných plánů snímkování. Platí <i>P</i> &le;  2<sup>63</sup>&minus;1.
          </p>
          <center>
            <table width="90%">
              <col width="15%"/>
              <col width="5%"/>
              <col width="35%"/>
              <col width="5%"/>
              <col width="30%"/>
              <tr>
                <td valign="top">
                  <h3><font color="blue">Příklad 1</font></h3>
                  <b>Vstup</b><br>
                  <pre>
4 3 5
ABB
BBB
BBA
BAB
</pre>
                  <b>Výstup</b><br>
                  <pre>
9
</pre>
                <td/>
                <td valign="top">
                  <h3><font color="blue">Příklad 2</font></h3>
                  <b>Vstup</b><br>
                  <pre>
4 3 10
ABB
BBB
BBA
BAB
</pre>
                  <b>Výstup</b><br>
                  <pre>
60
</pre>
                  V Příkladu 1 a Příkladu 2 jsou identické procesní seznamy simulátoru, data se liší pouze délkou snímkování družice. Pro kontrolu uvádíme, že počet plánů snímkování pro jednotlivé délky snímkování 3, 5, ..., 15 je, v odpovídajícím pořadí, 4, 6, 9, 13, 19, 28, 41, 60, 88, 129, 189, 277, 406.
                <td/>
                <td valign="top">
                  <h3><font color="blue">Příklad 3</font></h3>
                  <b>Vstup</b><br>
                  <pre>
3 2 10
AB
BB
BA
</pre>
                  <b>Výstup</b><br>
                  <pre>
144
</pre>
                  Pro zajímavost si všimněme, že 144 je dvanáctým prvkem Fibonacciho posloupnosti (1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ... ).
                </td>
              </tr>
            </table>
          </center>
          <hr>
          <h3><font color="blue">Veřejná data</font></h3>
          <p align="justify">
            Veřejná data k&nbsp;úloze jsou k&nbsp;dispozici. Veřejná data jsou uložena také v&nbsp;odevzdávacím systému a při
            každém odevzdání/spuštění úlohy dostává řešitel kompletní výstup na stdout a stderr ze svého programu
            pro každý soubor veřejných dat.
            <br>
            <a href="getdata.php?task=simulator&item=datapub.zip"><b>Veřejná data</b></a>
          </p>
        </div>
      </body>
    </html>
  </body>
</html>
