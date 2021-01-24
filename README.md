vDinar - virtualni Dinar <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="40px" height="40px">
======

[![vdinar](https://snapcraft.io/vdinar/badge.svg)](https://snapcraft.io/vdinar)

https://www.vdinar.info/en/

Copyright (c) 2009-2014 Bitcoin Developers

Copyright (c) 2011-2014 Litecoin Developers

Copyright (c) 2017-2021 vDinar Developers

What is vDinar? <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="32px" height="32px">
----------------

vDinar is a cryptocurrency using vCrypt as a proof-of-work algorithm, aimed to help money transactions between southern slavic countries. Of course, it is available to everyone else besides being from Balkans or not.

What's new in vDinar?
 - **vCrypt protocol/algorithm is similar to Scrypt-N, but changes the N factor at blockchain heights instead of hardcoded timestamps**
 - **allocates 2% of every mining reward to a special address for donations in the Yugoslav area**
 - **(optional) transaction fees split 75% to miners and 25% for donations**

**2.5 minute block target, subsidy halves in 840k blocks (~4 years)**

 - **49+1 coins per block (49 to miner, 1 to donations)**
 - **2016 blocks to retarget difficulty**

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

### Test network <img align="left" src="https://vdinar.jugoslaven.com/slike/Ikona-128.png" width="24px" height="24px">

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./vdinar-qt_test
