vDinar - virtualni Dinar <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="40px" height="40px">
======

https://www.vdinar.info

Zaštita autorskih prava (c) 2009-2014 Razvijači Bitcoin-a

Zaštita autorskih prava (c) 2011-2014 Razvijači Litecoin-a

Zaštita autorskih prava (c) 2017-2019 Razvijači virtualnog Dinara

Šta je vDinar? <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
----------------

vDinar je kriptovaluta koja koristi algoritam/protokol vCrypt sa svrhom poboljšanja novčanih transakcija na prostoru bivše Jugoslavije. Ona je naravno ipak dostupna svim ljudima bez obzira jesu li iz tog prostora ili ne.

Šta je novo u virtualnom Dinaru?
 - **vCrypt algoritam/protokol, mnogo sličan algoritmu Scrypt-N, gdje se N multiplikator mijenja po broju blokova**
 - **2% svih poreza (poreza, ne transakcija!) je sačuvano u centralnoj adresi za humanitarne svrhe na prostoru bivše Jugoslavije**

**Novi blok svakih 2 i po minuta, prepolovljenje svakih 840'000 blokova (~4 godine)**

 - **49+1 novčića za blok (49 rudaru, 1 adresi za donacije)**
 - **2016 blokova za promjenu težine**

Tehničko objašnjenje <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
---------------------

Razlike u strukturi blokova (od Bitcoin-a)
 - **2 "coinbase" (bez izvora) transakcije umjesto jedne**
 - **obe "coinbase" transakcije uključuju isti "extranonce"**

Razlike u rudničkom rudarenju (sa strane servera):
   **(Nakon zahtjeva rada)**
 - **napravi dvije coinbase transakcije umjesto jedne**
 - **dijeli 49 novčića prvoj**
 - **dijeli 1/49 vrijednosti prve drugoj**
 - **sačuvaj stepene kriptografske kompozicije ("merkle steps") iz drugog nivoa, uzimajući u obzit dvije nepoznate vrijednosti u prvoj**
 - **obavijesti klijenta dijelovima obe transakcije ("coinb1", "coinb2", doncoinb1", "doncoinb2"), stepenima kriptografske kompozicije i sve ostalo**
   **(Nakon prijema djelomičnog rješenja)**
 - **sastavi obe transakcije bez izvora**
 - **izgradi korijen kompozicije ("hash merkle root") zadnjim rezultatom sastavljen sa svim ostalim dijelovima kompozicije, jedan po jedan**

Razlike u rudničkom rudarenju (sa strane klijenta):
 - **2 dodatne informacije sa strane servera ("doncoinb1", "doncoinb2")**
 - **izgradi korijen kompozicije ("hash merkle root") sa prvim dvama transakcijama kao "coinb" i "doncoinb" (obe sa istim "extranonce")**

Dozvola <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
-------

vDinar je objavljen uslovima dozvole MIT. Pogledaj datoteku `COPYING` za dodatne
informacije ili pogledaj http://opensource.org/licenses/MIT.

Proces razvijanja <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
-------------------

Razvijači rade u svojim vlastitim granama, te šalju zahtjeve prijema ("pull requests")
kada misle da je njihov kod spreman.

### Mreža za testiranje <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="24px" height="24px">

Za pokretanje alternativne mreže za testiranje napisati komandu:

    cd src; make -f makefile.unix test

Ili za pokretanje UI sučelja:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./vdinar-qt_test
