<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
  <meta HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8">
  <meta http-equiv="cache-control" content="no-cache">
  <link rel="stylesheet" type="text/css" href="default.css" />
  <title>Zadání úlohy z B4B33ALG</title>
</head>
<body>﻿<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<!-- saved from url=(0111)https://cw.felk.cvut.cz/brute/data/ae/release/2019z_b4b33alg/algzima2019/evaluation/input.php?task=occultations -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  
  <meta http-equiv="cache-control" content="no-cache">
  <link rel="stylesheet" type="text/css" href="./Zadání úlohy z A4B33ALG_files/default.css">
  <title>Zadání úlohy z B4B33ALG</title>
</head>

<body>
 <div class="main">

<h2><font color="blue">Líný AVL strom</font></h2>
<p align="justify">
Po velkém úspěchu se správou holých větví v BVS se tým profesora Fabinarise Suchbauma soustředí na studium speciálních variant AVL stromů.
Jmenovitě zkoumají přednosti tzv. líného AVL stromu. Tento strom implementuje operaci Insert stejně jako standardní AVL strom, liší se
ale v operaci Delete, která pouze označuje uzly jako smazané, aniž by měnila strukturu stromu. 
Pro zachování dobrých vlastností stromu je ale potřeba označené uzly čas od času fyzicky smazat, což se děje během tzv. konsolidační fáze, jež
je spuštena, pokud maximální počet označených uzlů na cestě z kořene do listu dosáhne mezní hranice.

<p align="justify">
<b>Notace</b><br>
Pro líný AVL strom <i>T</i>, nechť <i>depth</i>(<i>T</i>) označuje hloubku <i>T</i>, která je definovaná jako počet hran na nejdelší cestě
z kořene do některého z listů. Pokud je <i>T</i> prázdný, pak <i>depth</i>(<i>T</i>) = &minus;1.
Pro uzel <i>X</i> stromu <i>T</i>, nechť <i>key</i>(<i>X</i>) označuje jeho celočíselný klíč.
Předpokládáme, že každý uzel má booleovský příznak určující, zda klíč reprezentovaný v daném uzlu je smazaný, či ne.
Nechť <i>deleted</i>(<i>X</i>) označuje hodnotu tohoto příznaku pro uzel <i>X</i>. Říkáme, že <i>X</i> je <i>označený jako smazaný</i>
právě tehdy, když <i>deleted</i>(<i>X</i>)=<i>true</i>.
</p>

<!--  --------------------- INSERT ---------------------------- -->

<p align="justify">
<b>Insert(<i>k</i>)</b><br>
Pokud je klíč <i>k</i> uložený v <i>T</i> v uzlu <i>X</i>, potom operace Insert pouze nastaví <i>deleted</i>(<i>X</i>):=<i>false</i>.
Když klíč <i>k</i> není v <i>T</i>, je do <i>T</i> vložen podle stejných pravidel jako v případě standardního AVL stromu.
</p>

<!--  --------------------- DELETE ---------------------------- -->

<p align="justify">
<b>Delete(<i>k</i>)</b><br>
Pokud je klíč <i>k</i> uložený v <i>T</i> v uzlu <i>X</i>, potom operace Delete pouze nastaví <i>deleted</i>(<i>X</i>):=<i>true</i>.
Když klíč <i>k</i> není v <i>T</i>, potom operace neprovede žádnou změnu.
</p>

<!--  --------------------- CONSOLIDATION ---------------------------- -->

<p align="justify">
<b>Konsolidace</b><br>
Kosolidace proběhne automaticky po operaci Insert nebo Delete, pokud tato operace způsobí, že <i>T</i> obsahuje
cestu z kořene do listu, která má alespoň 1+&#8970;<i>depth</i>(<i>T</i>)/2&#8971; uzlů označených jako smazaných.
Konsolidace probíhá sekvečně v iteracích, dokud v <i>T</i> existuje uzel označený jako smazaný. V každé itaraci je vždy odstraněn
uzel <i>X</i> označený jako smazaný, který je mezi takovýmito uzly
aktuálně první v pořadí postorder. Odstranění uzlu se provede zavoláním operace <i>Remove</i>(<i>X</i>) definované níže.

<!--  --------------------- REMOVE ---------------------------- -->

<p align="justify">
<b>Remove(<i>X</i>)</b><br>
Pro fyzické smazání uzlu <i>X</i> z líného AVL stromu <i>T</i> se aplikují rekurzivní pravidla:
<ul>
  <li>Když je <i>X</i> list, proveď standardní Delete v AVL stromu s případným vyvážením pomocí rotací.
  Pokud lze aplikovat jednoduchou i dvojitou rotaci, jednoduchá rotace má vždy přednost.
  <li>Když má <i>X</i> levého potomka, pak v levém podstromu uzlu <i>X</i> najdi uzel <i>Y</i> s největším klíčem.
  Následně nastav <i>key</i>(<i>X</i>):=<i>key</i>(<i>Y</i>), <i>deleted</i>(<i>X</i>):=<i>false</i> a proveď <i>Remove</i>(<i>Y</i>).
  <li>Když nemá <i>X</i> levého potomka, ale má pravého, pak v pravém podstromu uzlu <i>X</i> najdi uzel <i>Y</i> s nejmenším klíčem.
  Následně nastav <i>key</i>(<i>X</i>):=<i>key</i>(<i>Y</i>), <i>deleted</i>(<i>X</i>):=<i>false</i> a proveď <i>Remove</i>(<i>Y</i>).
</ul>
</p>

</p>

<!--  --------------------- ILLUSTRATION ---------------------------- -->

Pro ilustraci průběhu operací uvažujme následující příklad líného AVL stromu: 
<br>
<pre>
   2+
1+    3+
         4+
</pre>
Strom obsahuje klíče 1, 2, 3, 4 a jeho hloubka je 2. Symbol "+" za klíčem indikuje, že příslušný uzel není označený jako smazaný.
Když se provede <i>Delete</i>(3), struktura stromu se nezmění. Obdržíme výsledek
<pre>
   2+
1+    3-
         4+
</pre>
kde symbol "&minus;" za klíčem 3 indikuje, že daný uzel obsahuje klíč označený jako smazaný. Operace <i>Insert</i>(5)
vloží nový uzel a provede jednoduchou rotaci potřebnou k vyvážení uzlu s klíčem 3.
<pre>
   2+
1+       4+
      3-    5+
</pre>
Operace <i>Insert</i>(3) nalezne uzel s klíčem 3 a nastaví jeho příznak <i>deleted</i> na <i>false</i>.
<pre>
   2+
1+       4+
      3+    5+
</pre>
Provedení <i>Delete</i>(5) a <i>Delete</i>(2) vytvoří strom
<pre>
   2-
1+       4+
      3+    5-
</pre>
což vede k aktivaci konsolidační fáze, neboť nyní strom obsahuje cestu z kořene do listu, která má 2 &ge; 1+&#8970;2/2&#8971 uzlů označených jako smazaných.
Příslušná konsolidační procedura smaže nejprve uzel s klíčem 5. Výsledkem je strom
<pre>
   2-
1+       4+
      3+
</pre>
Poté je smazán kořen. Klíč v kořeni je nahrazen klíčem 1 z levého podstromu a uzel původně obsahující tento klíč je odstraněn.
<pre>
1+
       4+
    3+
</pre>
Následuje použití dvojité rotace v kořeni k získání výsledného vyváženého stromu.
<pre>
   3+
1+    4+
</pre>
</p>

<h3><font color="blue">Úloha</font></h3>
<p align="justify">
Implementujte líný AVL strom.
Nad iniciálně prázdným líným AVL stromem proveďte zadanou posloupnost operací Insert a Delete. Spočítejte, kolik bylo během celého procesu
provedeno rotací a konsolidací, zjistěte také hloubku výsledného stromu.
<br><br>

<hr>


<h3><font color="blue">Vstup</font></h3>
<p align="justify">
První vstupní řádek obsahuje kladné celé číslo <i>N</i>, které určuje celkový počet operací Insert a Delete, jež se mají vykonat.
Každý z následujících <i>N</i> řádků obsahuje právě jedno nenulové celé číslo.
Pokud je to kladné číslo <i>K</i>, potom daný řádek reprezentuje operaci <i>Insert</i>(<i>K</i>). V případě záporného čísla <i>K</i>
reprezentuje řádek operaci <i>Delete</i>(<i>|K|</i>). Operace se mají provést ve stejném pořadí, v jakém se na vstupu vyskytují.
<br>
Platí 1 &le; <i>N</i> &le; 2&times;10<sup>6</sup> a <i>1 &le; |K|</i> &le; 1.5&times;10<sup>6</sup>.

</p>


 <h3><font color="blue">Výstup</font></h3>
<p align="justify">
Výstup sestává z jednoho řádku obsahujícího tři celá čísla <i>D</i>, <i>R</i>, <i>C</i> oddělená mezerami. Číslo <i>D</i> je hloubka výsledného stromu.
Číslo <i>R</i> je odvozené od celkového počtu rotací vykonaných během celého procesu (včetně rotací provedených při konsolidacích).
Každá jednoduchá rotace přispívá do <i>R</i> hodnotou 1, každá dvojitá rotace přispívá hodnotou 2 (tzn., dvojitou rotaci započítáváme jako dvě jednoduché
rotace). A konečně, číslo <i>C</i> odpovídá počtu vyvolaných konsolidací.
</p>

<!-- EXAMPLE 1 -------------------------------------------------------------------------------------------------------------------- -->

<h3><font color="blue">Příklady</font></h3>

<table border="0" width="900" align="center">
<tr valign="top">

<td align="left" width="200">

<b>Vstup</b><br>
<pre>
9
2
1
3
4
-3
5
3
-5
-2
</pre>

<b>Výstup</b><br>
<pre>
1 3 1
</pre>


 </td>
 
 <td align="left" width="40">
 <td>

 <td align="left" width="200">
 
<b>Vstup</b><br>
<pre>
10
5
8
7
10
4
6
-8
-10
-5
-6
</pre>

<b>Výstup</b><br>
<pre>
1 3 2
</pre>


 </td>
 
 <td align="left" width="40">
 <td>

 <td align="left" width="200">
 
<b>Vstup</b><br>
<pre>
12
2
4
1
5
8
7
-4
-7
-2
-5
-1
-8
</pre>

<b>Výstup</b><br>
<pre>
-1 2 4
</pre>


 </td>
 
</td>
</tr>
</table>


<hr>
<h3><font color="blue">Veřejná data</font></h3>
<p align="justify">
Veřejná data k&nbsp;úloze jsou k&nbsp;dispozici. Veřejná data jsou uložena také v&nbsp;odevzdávacím systému a při
každém odevzdání/spuštění úlohy dostává řešitel kompletní výstup na stdout a stderr ze svého programu
pro každý soubor veřejných dat. 
<br>
<a href="getdata.php?task=lazyAVL&amp;item=datapub.zip"><b>Veřejná data</b></a>
</p>

</div></body></html></body>
</html>
