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
 - **vCrypt алгоритам/протокол, много сличан алгоритму Scrypt-N, гдје се Н мултипликатор мења по броју блокова**
 - **2% свих пореза (пореза, не трансакција!) је сачувано у централној адреси за хуманитарне сврхе на простору бивше Југославије**

**Нови блок сваких 2 и по минута, преполовљење сваких 840'000 блокова (~4 године)**

 - **49+1 новчића за блок (49 рудару, 1 адреси за донације)**
 - **2016 блокова за промену тежине**

Technical explanation <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
---------------------

Block structure differences (from Bitcoin)
 - **2 coinbase (no input) transactions instead of one**
 - **both coinbase transactions include the same extranonce**

Pooled mining differences (server side):
   **(On work request)**
 - **create two coinbase transactions instead of one**
 - **assign the 49 coins to first coinbase**
 - **assign 1/49 of the first coinbase transaction value to the second one**
 - **store merkle steps from the 2nd lvl., considering two unknown values (coinb. txs) in the 1st one**
 - **send splitted coinbase transactions (coinb1, coinb2, doncoinb1, doncoinb2), merkle steps and all the rest**
   **(On share received)**
 - **hash coinb. and don. coinb. txs**
 - **build hash merkle root with the latter result hashed with merkle steps one by one**

Pooled mining differences (client side):
 - **receive 2 new values (doncoinb1, doncoinb2)**
 - **build hash merkle root with first two txs as coinb. and don. coinb. (both with same extranonce)**

License <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
-------

vDinar is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

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
