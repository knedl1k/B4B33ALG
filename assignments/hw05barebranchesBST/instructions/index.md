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

<h2><font color="blue">Správa holých větví v BVS</font></h2>
<p align="justify">

Tým profesora Fabinarise Suchbauma z institutu Maxe Plancka v Saarbrückenu dosáhl v posledních letech významných pokroků na poli binárních vyhledávacích stromů (BVS).
V současné době se tato veleúspěšná skupina zabývá binárními stromy, které vznikají při činnosti garbage collectoru a vyznačují se velkou hloubkou
a relativně malým počtem větví.
<br><br>
Říkáme, že neprázdná posloupnost uzlů <i>n</i><sub>1</sub>, <i>n</i><sub>2</sub>, ..., <i>n</i><sub><i>M</i></sub> v BVS je <b>holá větev</b> délky <i>M</i>, pokud jsou
splněné následující podmínky:
<ol>
<li>Každý uzel v posloupnosti má nejvíce jednoho potomka.</li>
<li>Pro každé <i>k</i> = 1, 2, ..., <i>M</i>&minus;1 je uzel <i>n</i><sub><i>k</i></sub> rodičem uzlu <i>n</i><sub><i>k</i>+1</sub>.
<li>Jestliže uzel <i>n</i><sub>1</sub> není kořenem celého BVS, potom jeho rodič má dva potomky.</li>
</ol>

Saarbrückenští odborníci navrhují mechanismus, který zabrání výskytu holých větví délky 2<sup><i>K</i></sup>&minus;1 pro danou konstantu <i>K</i>.

<br><br>
V případě, že holá větev <i>B</i> délky 2<sup><i>K</i></sup>&minus;1 vznikne v BVS důsledkem provedení operace Insert nebo Delete,
potom musí být z BVS okamžitě odstraněna a nahrazena perfektně vyváženým podstromem <i>T</i> obsahujícím všech 2<sup><i>K</i></sup>&minus;1 uzlů větve <i>B</i>.
Když existuje rodič <i>P</i> kořene větve <i>B</i>, potom se <i>P</i> stane rodičem kořene <i>T</i>, jinak se kořen <i>T</i> stane kořenem celého BVS.
Pokud existuje potomek <i>C</i> nejhlubšího uzlu <i>B</i>, potom se <i>C</i> stane potomkem nějakého listu <i>T</i>.
Pozice všech uzlů v <i>T</i> a pozice uzlu <i>C</i> relativně vůči <i>T</i> jsou určeny jenoznačně, protože celý strom je vyhledávacím stromem.

<br><br>
Po provedení jedné operace Insert vznikne nejvíce jedna holá větev délky 2<sup><i>K</i></sup>&minus;1.
Po provedení jedné operace Delete vzniknou maximálně dvě holé větve velikosti 2<sup><i>K</i></sup>&minus;1.
Případ vzniku dvou takovýchto větví je ilustrován na Obrázku 1 níže.

<br><br>

<b>Poznámka 1.</b> Pořadí uzlů (shora dolů) v holé větvi obecně neodpovídá vzestupnému/sestupnému pořadí klíčů (zleva doprava) této větve.
Neformálně řečeno, holá větev nemusí být rovná, v různých uzlech může měnit směr.
<p></p>

</p>

&nbsp; 
&nbsp; <table border="0" width="800" align="center"><tbody><tr><td align="center">
<!--img style="width: 60%; height: 60%;" src="img1.png"-->
<img style="width: 60%; height: 60%;" src="img1.png"><br><br>
<!--img style="width: 480px;" src="getdata.php?task=barebranchesBST&item=examples.png"--><br>


<b>Obrázek 1.</b> Vznik dvou holých větví délky 2<sup><i>K</i></sup>&minus;1 po smazání uzlu <i>d</i>.
Obě holé větve jsou postupně odstraněny a nahrazeny perfektně vyváženými podstromy <i>T</i><sub>1</sub> and <i>T</i><sub>2</sub>.
Uzel <i>v</i> je zároveň součástí <i>T</i><sub>1</sub> i <i>T</i><sub>2</sub>, uzel <i>z</i> je částí <i>T</i><sub>2</sub>.
Uzly <i>u</i> a <i>v</i> nemusí být totožné, stejně tak uzly <i>x</i> a <i>z</i>, viz Poznámka 1 výše.
Malé modré trojúhelníky reprezentují části BVS, které zůstávají po vykonání uvažované operace Delete beze změn.
     </td></tr>
</tbody></table>

<h3><font color="blue">Úloha</font></h3>
<p align="justify">
Je dána konstanta <i>K</i> a konečná posloupnost operací Insert a Delete, které mají být vykonány v daném pořadí nad iniciálně prázdným BVS.
Každá holá větev délky 2<sup><i>K</i></sup>&minus;1, jež během provádění operací dočasně vznikne, musí být okamžitě odstraněna pomocí výše popsané metody.
Spočítejte, kolik holých větví se během celého procesu odstraní.
<br><br>

<b>Poznámka 2.</b> V implementaci předpokládáme, že operace Delete nahrazuje smazaný uzel <i>d</i> nejlevějším uzlem pravého podstromu <i>d</i>,
v případě, že <i>d</i> má dva potomky.
</p>

<hr>


<h3><font color="blue">Vstup</font></h3>
<p align="justify">
První vstupní řádek obsahuje dvě celá kladná čísla <i>K</i> and <i>N</i> oddělená mezerou. Následuje <i>N</i> vstupních řádků, kde každý z nich specifikuje jednu operaci.
Operace Insert je reprezentována vekým písmenem <code>'I'</code>, za kterým následuje mezera a celočíselný klíč.
Operace Delete je reprezentována velkým písmenem <code>'D'</code>, za kterým opět následuje mezera a celočíselný klíč.
Posloupnost vstupních operací nezpůsobí vkládání duplicitního klíče, stejně tak nezpůsobí mazání neexistující klíče.  <br>
Platí 2 &le; <i>K</i> &le; 12; 2 &le; <i>N</i> &le; 1.4&times;10<sup>6</sup>.

</p>


 <h3><font color="blue">Výstup</font></h3>
<p align="justify">
Výstup sestává z jednoho řádku obsahujícího nezáporné číslo, jež je rovno celkovému počtu holých větví délky 2<sup><i>K</i></sup>&minus;1
nahrazených perfektně vyváženým stromem během provádění na vstupu specifikovaných operací. 
</p>

<!-- EXAMPLE 1 -------------------------------------------------------------------------------------------------------------------- -->

<h3><font color="blue">Příklad 1</font></h3>

<table border="0" width="900" align="center">
<tbody><tr valign="top">
<td align="left" width="300">

    <b>Vstup</b><br>
<pre>2 11
I 90
I 95
I 40
I 80
I 60
I 75
I 70
D 95
D 70
D 40
D 60
</pre>


<b>Výstup</b><br>
<pre>4
</pre>
 <br><br>   <br><br> <br><br> <br><br>

  </td>
  <td align="left" width="30">
  </td><td>

</td><td align="center">
<img style="width: 70%; height: 70%;" src="getdata.php?task=barebranchesBST&item=img21.png">
<!--img style="width: 364px; height: 150px;" src="img2.png" /-->
<br><br>

<b>Obrázek 2.1.</b> 
Změny v BVS po provedení operace Insert(60), resp. Insert(70), resp. Delete(40), resp. Delete(60) v Příkladě 1 jsou zachycené jako transformace
a), resp. b), resp. c), resp. d). Uzly původních holých větví jsou ve všech případech zvýrazněny šedě.

</td>
</tr>
</tbody></table>



<!-- EXAMPLE 2 -------------------------------------------------------------------------------------------------------------------- -->




<h3><font color="blue">Příklad 2</font></h3>

<table border="0" width="900" align="center">
<tbody><tr valign="top">
<td align="left" width="300">

    <b>Vstup</b><br>
<pre>2 15
I 10
I 5
I 20
I 15
I 40
I 30
I 70
I 60
I 80
I 90
I 50
D 30
D 15
D 80
D 90
</pre>


<b>Výstup</b><br>
<pre>2
</pre>

  </td>
  <td align="left" width="30">
  </td><td>

</td><td align="center">
<br><br><br>
<img style="width: 70%; height: 70%;" src="getdata.php?task=barebranchesBST&item=img22.png">
<!--img style="width: 364px; height: 150px;" src="img2.png" /-->
<br><br>

<b>Obrázek 2.2.</b>
Změna v BVS po provedení operace Delete(90) v Příkladu 2. Uzly původních holých větví jsou zvýrazněny šedě.
Uvedená změna je instancí obecného případu zachyceného na Obrázku 1.

</td>
</tr>
</tbody></table>


<!-- EXAMPLE 3 -------------------------------------------------------------------------------------------------------------------- -->

<!--
<h3><font color="blue">Příklad 3</font></h3>
<b>Vstup</b><br>
<pre>3 13
I 11
I 99
I 22 
I 88
I 44
I 77
I 66
I 10
I 9
I 8
I 7
I 6
I 5
</pre>

<b>Výstup</b><br>
<pre>2
</pre>
-->

<hr>
<h3><font color="blue">Veřejná data</font></h3>
<p align="justify">
Veřejná data k&nbsp;úloze jsou k&nbsp;dispozici. Veřejná data jsou uložena také v&nbsp;odevzdávacím systému a při
každém odevzdání/spuštění úlohy dostává řešitel kompletní výstup na stdout a stderr ze svého programu
pro každý soubor veřejných dat. 
<br>
<a href="getdata.php?task=barebranchesBST&amp;item=datapub.zip"><b>Veřejná data</b></a>
</p>

</div></body></html></body>
</html>
