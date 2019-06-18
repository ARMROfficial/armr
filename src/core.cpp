// Copyright (c) 2014-2016 The ShadowCoin developers
// Copyright (c) 2018-2019 ARMR developers
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.



void addAnonOutput(CPubKey& pkAo, CAnonOutput& anonOutput, txMixins_container& txMixinsContainer)
{
    // create pair with vout index of tx and pubKey
    const auto & pairOutPubkey = std::make_pair(anonOutput.outpoint.n, pkAo);
    // check if CTxMixins does already exist in container for tx hash
    const auto & txHashIndex = txMixinsContainer.get<TXHASH>();
    const auto it = txHashIndex.find(anonOutput.outpoint.hash);
    if (it != txHashIndex.end())
        // add anon pubKey to existing CTxMixins in container
        it->vOutPubKeys.push_back(pairOutPubkey);
    else
    {
        CTxMixins txMixins(anonOutput.outpoint.hash);
        txMixins.vOutPubKeys.push_back(pairOutPubkey);
        txMixinsContainer.push_back(txMixins);
    }
}

