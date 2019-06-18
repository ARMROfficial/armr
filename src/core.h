// Copyright (c) 2014-2016 The ShadowCoin developers
// Copyright (c) 2018-2019 ARMR developers
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.


#ifndef CORE_H
#define CORE_H




class CAnonOutputCount
{ // CountAllAnonOutputs
public:

    CAnonOutputCount()
    {
        nValue = 0;
        nExists = 0;
        nSpends = 0;
        nOwned = 0;
        nLastHeight = 0;
        nCompromised = 0;
        nStakes = 0;
        nMature = 0;
        nMixins = 0;
        nMixinsStaking = 0;
        nCompromisedHeight = 0;
    }

    CAnonOutputCount(int64_t nValue_, int nExists_, int nUnconfirmed_, int nSpends_, int nOwned_, int nLastHeight_, int nCompromised_, int nMature_, int nMixins_, int nMixinsStaking_, int nStakes_, int nCompromisedHeight_)
    {
        nValue = nValue_;
        nExists = nExists_;
        nSpends = nSpends_;
        nUnconfirmed = nUnconfirmed_;
        nOwned = nOwned_;
        nLastHeight = nLastHeight_;
        nCompromised = nCompromised_;
        nMature = nMature_;
        nMixins = nMixins_;
        nMixinsStaking = nMixinsStaking_;
        nStakes = nStakes_;
        nCompromisedHeight = nCompromisedHeight_;
    }

    void set(int64_t nValue_, int nExists_, int nUnconfirmed_, int nSpends_, int nOwned_, int nLastHeight_, int nCompromised_, int nMature_, int nMixins_, int nMixinsStaking_, int nStakes_, int nCompromisedHeight_)
    {
        nValue = nValue_;
        nExists = nExists_;
        nSpends = nSpends_;
        nUnconfirmed = nUnconfirmed_;
        nOwned = nOwned_;
        nLastHeight = nLastHeight_;
        nCompromised = nCompromised_;
        nMature = nMature_;
        nMixins = nMixins_;
        nMixinsStaking = nMixinsStaking_;
        nStakes = nStakes_;
        nCompromisedHeight = nCompromisedHeight_;
    }

    void addCoin(int nBlockHeight, int64_t nCoinValue, bool fStake)
    {
        nExists++;
        nValue = nCoinValue;
        nStakes += fStake;
        if (nBlockHeight > nLastHeight)
            nLastHeight = nBlockHeight;
    }

    void updateDepth(int nBlockHeight, int64_t nCoinValue)
    {
        nValue = nCoinValue;
        if (nBlockHeight > nLastHeight)
            nLastHeight = nBlockHeight;
    }

    void incSpends(int64_t nCoinValue)
    {
        nSpends++;
        nValue = nCoinValue;
    }

    void decSpends(int64_t nCoinValue)
    {
        nSpends--;
        nValue = nCoinValue;
    }

    void incExists(int64_t nCoinValue)
    {
        nExists++;
        nValue = nCoinValue;
    }

    void decExists(int64_t nCoinValue)
    {
        nExists--;
        nValue = nCoinValue;
    }

    int numOfUnspends()
    {
        return nExists - nSpends;
    }

    int numOfMatureUnspends()
    {
        return nMature - nSpends;
    }


    int64_t nValue;
    int nExists;
    int nUnconfirmed;
    int nSpends;
    int nOwned; // todo
    int nLastHeight;
    int nCompromised;
    int nCompromisedHeight;
    int nMature;
    int nMixins;
    int nMixinsStaking;
    int nStakes;
};




#endif  // SPEC_CORE_H

