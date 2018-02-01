vDINAR
================================

https://www.jugoslaven.com - https://vdinar.jugoslaven.com

Copyright (c) 2009-2014 Bitcoin Developers

Copyright (c) 2011-2014 Litecoin Developers

Copyright (c) 2017 vDinar Developers

What is vDinar?
----------------

vDinar is a cryptocurrency using vCrypt as a proof-of-work algorithm, aimed to help money transactions between southern slavic countries. Of course, it is available to everyone else besides being from Balkans or not.

What's new in vDinar?
 - **vCrypt protocol/algorithm is similar to Scrypt-N, but changes the N factor at blockchain heights instead of hardcoded timestamps**
 - **allocates 2% of every mining reward (fees included) to a special address for donations in the Yugoslav area**

**2.5 minute block target, subsidy halves in 840k blocks (~4 years)**

The rest is the same as Bitcoin.
 - **50 coins per block**
 - **2016 blocks to retarget difficulty**

License
-------

vDinar is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

Development process
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

Testing
-------

Testing and code review is the bottleneck for development. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code.

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./vdinar-qt_test

### Donations

Just use vDinar, that's the best donation!
