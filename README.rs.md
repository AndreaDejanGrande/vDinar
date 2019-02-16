вДинар - виртуални Динар <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="40px" height="40px">
======

https://www.vdinar.info

Заштита ауторских права (c) 2009-2014 Развијачи Bitcoin-а

Заштита ауторских права (c) 2011-2014 Развијачи Litecoin-a

Заштита ауторских права (c) 2017-2019 Развијачи виртуалног Динара

Шта је вДинар? <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
----------------

вДинар је криптовалута која користи алгоритам/протокол vCrypt са сврхом побољшања новчаних трансакција на простору бивше Југославије. Она је наравно ипак доступна свим људима без обзира јесу ли из тог простора или не.

Шта је ново у виртуалном Динару?
 - **vCrypt алгоритам/протокол, много сличан алгоритму Scrypt-N, где се Н мултипликатор мења по броју блокова**
 - **2% свих пореза (пореза, не трансакција!) је сачувано у централној адреси за хуманитарне сврхе на простору бивше Југославије**

**Нови блок сваких 2 и по минута, преполовљење сваких 840'000 блокова (~4 године)**

 - **49+1 новчића за блок (49 рудару, 1 адреси за донације)**
 - **2016 блокова за промену тежине**

Техничко објашњење <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
---------------------

Разлике у структури блокова (од Bitcoin-а)
 - **2 "coinbase" (без извора) трансакције уместо једне**
 - **обе "coinbase" трансакције укључују исти "extranonce"**

Разлике у рудничком рударењу (са стране сервера):
   **(Након захтева рада)**
 - **направи две coinbase трансакције уместо једне**
 - **дели 49 новчића првој**
 - **дели 1/49 вредности прве другој**
 - **сачувај степене криптографске композивије ("merkle steps") из другог нивоа, узимајући у обзир две непознате вредности у првој**
 - **обавести клијента деловима обе трансакције ("coinb1", "coinb2", "doncoinb1", "doncoinb2"), степенима криптографске композиције и све остало**
   **(Након пријема делимичног решења)**
 - **састави обе трансакције без извора**
 - **изгради корен композиције ("hash merkle root") задњим резултатом састављен са свим осталим деловима композиције, један по један**

Разлике у рудничком рударењу (са стране клијента):
 - **2 додатне информације са стране сервера ("doncoinb1", "doncoinb2")**
 - **изгради корен композиције ("hash merkle root") са првим двама трансакцијама као "coinb" и "doncoinb" (обе са истим "extranonce")**

Дозвола <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
-------

вДинар је објављен условима дозволе MIT. Погледај датотеку `COPYING` за додатне
информације или погледај http://opensource.org/licenses/MIT.

Development process <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the Litecoin
development team members simply pulls it.

If it is a *more complicated or potentially controversial* change, then the patch
submitter will be asked to start a discussion with the devs and community.

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see `doc/coding.txt`) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/AndreaDejanGrande/vDinar/tags) are created
regularly to indicate new official, stable release versions of Litecoin.

Testing <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
-------

Testing and code review is the bottleneck for development. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="24px" height="24px">

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code.

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./vdinar-qt_test

### Donations <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="24px" height="24px">

Just use vDinar, that's the best donation!
