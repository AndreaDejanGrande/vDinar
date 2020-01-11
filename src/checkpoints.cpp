// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    // How many times we expect transactions after the last checkpoint to
    // be slower. This number is a compromise, as it can't be accurate for
    // every system. When reindexing from a fast disk with a slow CPU, it
    // can be up to 20, while when downloading from a slow network with a
    // fast multicore CPU, it won't be much higher than 1.
    static const double fSigcheckVerificationFactor = 5.0;

    struct CCheckpointData {
        const MapCheckpoints *mapCheckpoints;
        int64 nTimeLastCheckpoint;
        int64 nTransactionsLastCheckpoint;
        double fTransactionsPerDay;
    };

    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (     0, uint256("0x5ef756bea8ef0fe2bede9461d8c195c622f783b132b06ea3941c9e956639a6f9")) //GENESIS
        (  2500, uint256("0x1ad7042da2ada926152060d8adf0454e78e1b735755b3777a3a6ef11a700c988")) //2500  chekpoints every 2.5k blocks for first 10k blocks
        (  5000, uint256("0x7f3d4b1f450f44054be97a911d06a4aab9cccda42736adaccb80e6512abc6106")) //5000
        (  7500, uint256("0x5600fdb061453b324bf279283c361ecca01ad5889caf76aba7ff943ae4872fa3")) //7500
        ( 10000, uint256("0x60863e4019b0531cd595b51f3da63bc156638f254c4a08da021fc6c3bd6dafe6")) //10000
        ( 10565, uint256("0x6527b36d18f451f4008ea9d830815315464b268bdfe8e231d4ad7e6bce473aae")) //PATCH solving 1.0's DisconnectBlock() error crashing wallets on restart and long term run:
                                                                                                //      blocks before shutdowns have to be put as checkpoints to avoid accepting forks made
                                                                                                //      during pauses
        ( 20000, uint256("0x92593ea944560f7c471f25eadfd91fd7a183a887d94880a62b891a425888c5bb"))
        ( 30000, uint256("0x01720c5da8ff114989b8561251362116010412008301d1ce8096406da70a6e67"))
        ( 40000, uint256("0xd9bb731363cd049f799087fea67644154cbb09ed58fa0ac59026628b0a180fc8"))
        ( 50000, uint256("0x32955944d2c6af23e85789a82b848fb23a6c33ec8d544c00e29ac891d68e37c6"))
        ( 75000, uint256("0xbd56babfc97678786a39328ff80d7e1a5659161223cc74f5b7a05e61bcb87f31"))
        (100000, uint256("0x7ce140c94d55401db67f0e8e54f947323020c471dfd76e5ada60d09dfb27f3be"))
        (125000, uint256("0x386be1ec56fa92e05ad19afa69062b94d831fb6354daf894fa667bfae3bc9726"))
        (150000, uint256("0xb6b13c702a883ad8a6e6895f80ce1c51e20292c36bfc1e32818969fe6f5ff9a6"))
        (175000, uint256("0xa19c4506bedc4c8be96930c75cfcb70c23533c47cb6b6f077a549c0e021dfe8a"))
        (200000, uint256("0xfd0c07d0c07d993463704de9cefeba6b2dd8edde95dbdb9f800b59ce2285c35a"))
        (225000, uint256("0x451ab8505973c38ab2a66cdf680d108f069594b6cbe3e2065b540d8084864c7b"))
        (250000, uint256("0xaf2dc7fb6bf3a078b341255db099aaf82281f92ff1ff23513844c2b1263ae51c"))
        ;
    static const CCheckpointData data = {
        &mapCheckpoints,
        1556950248, // * UNIX timestamp of last checkpoint block
        541886,     // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        1500.0      // * estimated number of transactions per day after checkpoint
    };

    // TODO: create testnet chain
    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        (   0, uint256("0x"))
        ;
    static const CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        0,
        0,
        0
    };

    const CCheckpointData &Checkpoints() {
        if (fTestNet)
            return dataTestnet;
        else
            return data;
    }

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (!GetBoolArg("-checkpoints", true))
            return true;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    // Guess how far we are in the verification process at the given block index
    double GuessVerificationProgress(CBlockIndex *pindex) {
        if (pindex==NULL)
            return 0.0;

        int64 nNow = time(NULL);

        double fWorkBefore = 0.0; // Amount of work done before pindex
        double fWorkAfter = 0.0;  // Amount of work left after pindex (estimated)
        // Work is defined as: 1.0 per transaction before the last checkoint, and
        // fSigcheckVerificationFactor per transaction after.

        const CCheckpointData &data = Checkpoints();

        if (pindex->nChainTx <= data.nTransactionsLastCheckpoint) {
            double nCheapBefore = pindex->nChainTx;
            double nCheapAfter = data.nTransactionsLastCheckpoint - pindex->nChainTx;
            double nExpensiveAfter = (nNow - data.nTimeLastCheckpoint)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore;
            fWorkAfter = nCheapAfter + nExpensiveAfter*fSigcheckVerificationFactor;
        } else {
            double nCheapBefore = data.nTransactionsLastCheckpoint;
            double nExpensiveBefore = pindex->nChainTx - data.nTransactionsLastCheckpoint;
            double nExpensiveAfter = (nNow - pindex->nTime)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore + nExpensiveBefore*fSigcheckVerificationFactor;
            fWorkAfter = nExpensiveAfter*fSigcheckVerificationFactor;
        }

        return fWorkBefore / (fWorkBefore + fWorkAfter);
    }

    int GetTotalBlocksEstimate()
    {
        if (!GetBoolArg("-checkpoints", true))
            return 0;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (!GetBoolArg("-checkpoints", true))
            return NULL;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
