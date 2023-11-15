<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
  <meta HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8">
  <meta http-equiv="cache-control" content="no-cache">
  <link rel="stylesheet" type="text/css" href="default.css" />
  <title>Zadání úlohy z B4B33ALG</title>
</head>
<body><!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<!-- saved from url=(0111)https://cw.felk.cvut.cz/brute/data/ae/release/2019z_b4b33alg/algzima2019/evaluation/input.php?task=occultations -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  
  <meta http-equiv="cache-control" content="no-cache">
  <link rel="stylesheet" type="text/css" href="./Zadání úlohy z A4B33ALG_files/default.css">
  <title>Zadání úlohy z B4B33ALG</title>
</head>
<body>
 <div class="main">


<h2><font color="blue">Výstavba sítě železničních tratí</font></h2>
<p align="justify">

Hlavní (krajské) město horského kraje je propojeno s ostatními městy sítí silnic. Každá silnice vede údolím a spojuje dvě města, mimo města se silnice nekříží.
Zároveň platí, že topologie měst a silnic odpovídá binárnímu stromu, ve kterém je hlavní město kořenem. Znamená to, mimo jiné, že z libovolného města
se lze do hlavního města dostat právě po jedné trase, pokud po každé použité silnici projedeme pouze jednou.

<br>
<br>

K zajištění plynulejšího spojení s hlavním městem se kraj rozhodne vybudovat síť železničních tratí.
Horský terén umožňuje stavět tratě jen poblíž existujících silnic, jeden železniční úsek tak propojí vždy dvě města spojená silnicí.
S přihlédnutím k dostupným finančním prostředkům je pro maximální efektivitu železniční dopravy požadováno následující řešení.

Bude vybudovaná právě jedna rychlotrať, která bude začínat v hlavním městě a povede přes několik na sebe navazujících železničních úseků
(z hlavního města tak vede právě jeden úsek rychlotrati; z každého další města rychlotrati, s výjimkou koncového, vedou dva rychlotraťové úseky).
Dále, z každého města ležícího na rychlotrati může být vybudovaná obyčejná trať z dalších po sobě navazujících železničních úseků, které ovšem již nespojují
města ležící na rychlotrati (stejně jako rychlotrať představuje i obyčejná trať ve stromové topologii cestu).

<br>
<br>

Cílem návrhu sítě železničních tratí je maximalizovat počet měst, pro která bude existovat spojení s hlavním městem po železnici (za použití rychlotrati a/nebo jedné
obyčejné trati).

</p>

<h3><font color="blue">Úloha</font></h3>
<p align="justify">
Pro danou topologii měst a silnic nalezněte plán na vybudování sítě železničních tratí dle daných požadavků, která propojí maximální počet měst s hlavním městem.

&nbsp; 
&nbsp; 
&nbsp; <table border="0" width="800" align="center"><tbody><tr><td align="center">
<img style="width: 500px;" src="example.png">
<!--img style="width: 500px;" src="example.png"-->
<br>


<b>Obrázek 1.</b> Příklad optimální sítě železničních tratí, která propojuje 10 měst z celkového počtu 13.
Města odpovídají uzlům daného stromu, silnice jsou jeho hrany. Hlavní město je kořen s identifikátorem 8. Rychlotrať je
znázorněna oranžovým pozadím, celkem 3 obyčejné tratě pak přerušovaným světle oranžovým pozadím.
     </td></tr>
</tbody></table>

<hr>


<h3><font color="blue">Vstup</font></h3>
<p align="justify">
První řádek vstupu obsahuje celé číslo <i>N</i> reprezentující počet měst.
Druhý řádek vstupu obsahuje <i>N</i> různých celých čísel od 1 do <i>N</i> oddělených mezerami.
Každé z těchto čísel je identifikátorem jednoho města, přičemž čísla jsou na vstupu zapsaná v pořadí preorder
(s ohledem na stromovou topologii měst a silnic) a zároveň platí, že každý identifikátor odpovídá pořadovému číslu daného města v uspořádání inorder.
Reprezentovaný binární strom nemusí být úplný, vnitřní uzly mohou mít pouze jednoho potomka (levého, nebo pravého).

<br>
Platí 2 &le; <i>N</i> &le; 4 &times; 10<sup>6</sup>.

</p>


 <h3><font color="blue">Výstup</font></h3>
<p align="justify">
Výstup obsahuje jeden textový řádek s celým číslem <i>M</i>, jež odpovídá maximálnímu počtu měst, která mohou být součástí zamýšlené sítě železničních tratí.
</p>


<h3><font color="blue">Příklad 1</font></h3>

<b>Vstup</b><br>
<pre>
7
3 1 2 6 4 5 7
</pre>

<b>Výstup</b><br>
<pre>
7
</pre>

<h3><font color="blue">Příklad 2</font></h3>
<b>Vstup</b><br>
<pre>
13
8 4 2 1 3 6 5 7 11 9 10 13 12
</pre>

<b>Výstup</b><br>
<pre>
10
</pre>

Data a řešení Příkladu 2 můžeme vidět na <b>Obrázku 1</b>.

<hr>
<h3><font color="blue">Veřejná data</font></h3>
<p align="justify">
Veřejná data k&nbsp;úloze jsou k&nbsp;dispozici. Veřejná data jsou uložena také v&nbsp;odevzdávacím systému a při
každém odevzdání/spuštění úlohy dostává řešitel kompletní výstup na stdout a stderr ze svého programu
pro každý soubor veřejných dat.
<br>
<a href="getdata.php?task=railways&amp;item=datapub.zip"><b>Veřejná data</b></a>
</p>

</div></body></html></body>
</html>
