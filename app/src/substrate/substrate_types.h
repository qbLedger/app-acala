/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "stdbool.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma clang diagnostic pop
#endif

// https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs
#define Data_e_NONE 0
#define Data_e_RAW_VECU8 33
#define Data_e_BLAKETWO256U8_32 34
#define Data_e_SHA256_U8_32 35
#define Data_e_KECCAK256_U8_32 36
#define Data_e_SHATHREE256_U8_32 37

typedef uint8_t pd_bool_t;
typedef uint8_t pd_u8_t;
typedef uint16_t pd_u16_t;
typedef uint32_t pd_u32_t;
typedef uint64_t pd_u64_t;
typedef uint32_t pd_BlockNumber_t;

#define CHECK_ERROR(FUNC_CALL)          \
    {                                   \
        parser_error_t err = FUNC_CALL; \
        if (err != parser_ok)           \
            return err;                 \
    }

typedef struct {
    uint8_t moduleIdx;
    uint8_t idx;
} pd_CallIndex_t;

typedef enum {
    eEraImmortal = 0,
    eEraMortal = 1
} pd_ExtrinsicEra_e;

// This type has a non-standard serialization
// core/sr-primitives/src/generic/era.rs
typedef struct {
    pd_ExtrinsicEra_e type;
    uint64_t period;
    uint64_t phase;
} pd_ExtrinsicEra_t;

typedef struct {
    const uint8_t* ptr;
    uint8_t len;
} compactInt_t;

typedef struct {
    uint32_t _lenBuffer;
    const uint8_t* _ptr; // Pointer to actual
    const uint8_t* _nextPtr; // Pointer to next Call
    uint8_t slotIdx; // Count of nested calls
    bool isTail;
} pd_NestCallIdx_t;

////////////////////////
// Common types
////////////////////////

typedef compactInt_t pd_Compactu32_t; // u32
typedef compactInt_t pd_Compactu64_t; // u64
typedef compactInt_t pd_CompactAssignments_t;
typedef compactInt_t pd_CompactBountyIndex_t;
typedef compactInt_t pd_CompactEraIndex_t;
typedef compactInt_t pd_CompactMemberCount_t;
typedef compactInt_t pd_CompactMoment_t;
typedef compactInt_t pd_CompactPropIndex_t;
typedef compactInt_t pd_CompactProposalIndex_t;
typedef compactInt_t pd_CompactReferendumIndex_t;
typedef compactInt_t pd_CompactRegistrarIndex_t;
typedef compactInt_t pd_CompactWeight_t;

typedef enum {
    eAddressIndex = 0,
    eAddressId = 1
} pd_Address_e;

typedef struct {
    pd_Address_e type;
    uint64_t idx;
    const uint8_t* idPtr;
} pd_Address_t;

typedef struct {
    compactInt_t index;
} pd_CompactIndex_t;

typedef struct {
    compactInt_t value;
} pd_CompactBalance_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EvmAddress_t;

typedef struct {
    uint8_t value;
} pd_TokenSymbol_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_t;

typedef struct {
    uint64_t blockNumber;
    pd_u8_array_32_t blockHash;
} pd_ByFork_t;

typedef struct {
    uint8_t value;
    union {
        pd_TokenSymbol_t token;
        pd_EvmAddress_t erc20;
        uint32_t liquidCrowdloan;
        uint16_t foreignAsset;
    };
} pd_DexShare_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Bytes_t;

typedef struct {
    pd_DexShare_t dexShare1;
    pd_DexShare_t dexShare2;
} pd_DexShareFixed_t;

typedef struct {
    pd_Compactu32_t nom;
    pd_Compactu32_t denom;
} pd_Fraction_t;

typedef struct {
    uint8_t value;
    union {
        pd_u8_array_32_t byGenesis;
        pd_ByFork_t byFork;
        pd_Compactu64_t chainId;
    };
} pd_NetworkIdV3_t;

typedef struct {
    uint8_t value;
    union {
        pd_Bytes_t named;
        pd_Compactu32_t index;
    };
} pd_BodyIdV2_t;

typedef struct {
    uint8_t value;
    union {
        const uint8_t* _ptr;
        pd_Compactu32_t index;
    };
} pd_BodyIdV3_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t count;
        pd_Fraction_t fraction;
    };
} pd_BodyPart_t;

typedef struct {
    uint8_t value;
    union {
        pd_TokenSymbol_t token;
        pd_DexShareFixed_t dexShare;
        pd_EvmAddress_t erc20;
        uint32_t stableAssetPoolToken;
        uint32_t liquidCrowdloan;
        uint16_t foreignAsset;
    };
} pd_CurrencyId_t;

typedef struct {
    uint8_t value;
    pd_Bytes_t named;
} pd_NetworkIdV2_t;

typedef struct {
    uint8_t some;
    pd_NetworkIdV3_t contained;
} pd_OptionNetworkIdV3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_20_t;

typedef struct {
    pd_NetworkIdV2_t networkId;
    pd_u8_array_32_t key;
} pd_AccountId32V2_t;

typedef struct {
    pd_OptionNetworkIdV3_t networkId;
    pd_u8_array_32_t key;
} pd_AccountId32V3_t;

typedef struct {
    pd_NetworkIdV2_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64V2_t;

typedef struct {
    pd_OptionNetworkIdV3_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64V3_t;

typedef struct {
    pd_NetworkIdV2_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20V2_t;

typedef struct {
    pd_OptionNetworkIdV3_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20V3_t;

typedef compactInt_t pd_Compactu128_t;

typedef struct {
    uint8_t length;
    pd_u8_array_32_t data;
} pd_GeneralKeyV3_t;

typedef struct {
    pd_BodyIdV2_t id;
    pd_BodyPart_t part;
} pd_PluralityV2_t;

typedef struct {
    pd_BodyIdV3_t id;
    pd_BodyPart_t part;
} pd_PluralityV3_t;

typedef struct {
    uint32_t value1;
    uint32_t value2;
    uint32_t value3;
} pd_Taiga_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecCurrencyId_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32V2_t accountId32;
        pd_AccountIndex64V2_t accountIndex64;
        pd_AccountKey20V2_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_PluralityV2_t plurality;
    };
} pd_JunctionV2_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32V3_t accountId32;
        pd_AccountIndex64V3_t accountIndex64;
        pd_AccountKey20V3_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_GeneralKeyV3_t generalKey;
        pd_PluralityV3_t plurality;
        pd_NetworkIdV3_t globalConsensus;
    };
} pd_JunctionV3_t;

typedef struct {
    uint8_t value;
    union {
        pd_VecCurrencyId_t currencies;
        pd_Taiga_t taiga;
    };
} pd_SwapPath_t;

typedef struct {
    const uint8_t* _ptr;
} pd_H256_t;

typedef struct {
    pd_JunctionV2_t junction;
} pd_JunctionV2X1_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
} pd_JunctionV2X2_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
} pd_JunctionV2X3_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
    pd_JunctionV2_t junction3;
} pd_JunctionV2X4_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
    pd_JunctionV2_t junction3;
    pd_JunctionV2_t junction4;
} pd_JunctionV2X5_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
    pd_JunctionV2_t junction3;
    pd_JunctionV2_t junction4;
    pd_JunctionV2_t junction5;
} pd_JunctionV2X6_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
    pd_JunctionV2_t junction3;
    pd_JunctionV2_t junction4;
    pd_JunctionV2_t junction5;
    pd_JunctionV2_t junction6;
} pd_JunctionV2X7_t;

typedef struct {
    pd_JunctionV2_t junction0;
    pd_JunctionV2_t junction1;
    pd_JunctionV2_t junction2;
    pd_JunctionV2_t junction3;
    pd_JunctionV2_t junction4;
    pd_JunctionV2_t junction5;
    pd_JunctionV2_t junction6;
    pd_JunctionV2_t junction7;
} pd_JunctionV2X8_t;

typedef struct {
    pd_JunctionV3_t junction;
} pd_JunctionV3X1_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
} pd_JunctionV3X2_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
} pd_JunctionV3X3_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
    pd_JunctionV3_t junction3;
} pd_JunctionV3X4_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
    pd_JunctionV3_t junction3;
    pd_JunctionV3_t junction4;
} pd_JunctionV3X5_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
    pd_JunctionV3_t junction3;
    pd_JunctionV3_t junction4;
    pd_JunctionV3_t junction5;
} pd_JunctionV3X6_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
    pd_JunctionV3_t junction3;
    pd_JunctionV3_t junction4;
    pd_JunctionV3_t junction5;
    pd_JunctionV3_t junction6;
} pd_JunctionV3X7_t;

typedef struct {
    pd_JunctionV3_t junction0;
    pd_JunctionV3_t junction1;
    pd_JunctionV3_t junction2;
    pd_JunctionV3_t junction3;
    pd_JunctionV3_t junction4;
    pd_JunctionV3_t junction5;
    pd_JunctionV3_t junction6;
    pd_JunctionV3_t junction7;
} pd_JunctionV3X8_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSwapPath_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV2X1_t x1;
        pd_JunctionV2X2_t x2;
        pd_JunctionV2X3_t x3;
        pd_JunctionV2X4_t x4;
        pd_JunctionV2X5_t x5;
        pd_JunctionV2X6_t x6;
        pd_JunctionV2X7_t x7;
        pd_JunctionV2X8_t x8;
    };
} pd_JunctionsV2_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV3X1_t x1;
        pd_JunctionV3X2_t x2;
        pd_JunctionV3X3_t x3;
        pd_JunctionV3X4_t x4;
        pd_JunctionV3X5_t x5;
        pd_JunctionV3X6_t x6;
        pd_JunctionV3X7_t x7;
        pd_JunctionV3X8_t x8;
    };
} pd_JunctionsV3_t;

typedef struct {
    uint8_t some;
    pd_VecSwapPath_t contained;
} pd_OptionVecSwapPath_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecH256_t;

typedef struct {
    pd_EvmAddress_t address;
    pd_VecH256_t storageKeys;
} pd_AccessListItem_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Balance_t;

typedef struct {
    pd_CallIndex_t callIndex;
    const uint32_t* _txVerPtr;
    pd_NestCallIdx_t nestCallIdx;
} pd_Call_t;

typedef struct {
    uint32_t value;
} pd_ClassIdOfT_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_t;

typedef struct {
    uint8_t parents;
    pd_JunctionsV2_t interior;
} pd_MultiLocationV2_t;

typedef struct {
    uint8_t parents;
    pd_JunctionsV3_t interior;
} pd_MultiLocationV3_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_t;

typedef struct {
    uint64_t value;
} pd_TokenIdOfT_t;

typedef struct {
    pd_CurrencyId_t currencyid1;
    pd_CurrencyId_t currencyid2;
    pd_OptionVecSwapPath_t paths;
} pd_TupleCurrencyIdCurrencyIdOptionVecSwapPath_t;

typedef struct {
    pd_H256_t h256;
    uint32_t u32;
} pd_TupleH256u32_t;

typedef struct {
    pd_Compactu64_t refTime;
    pd_Compactu64_t proofSize;
} pd_Weight_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u128_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_t id;
        pd_CompactAccountIndex_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_AccountIdLookupOfT_t;

typedef struct {
    pd_u128_t value;
} pd_Amount_t;

typedef struct {
    uint8_t value;
    union {
        pd_H256_t legacy;
        pd_Bytes_t bytes_inline;
        pd_TupleH256u32_t lookup;
    };
} pd_BoundedCallOfT_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV2_t multilocationV2;
        pd_MultiLocationV3_t multilocationV3;
    };
} pd_BoxVersionedMultiLocation_t;

typedef struct {
    pd_ClassIdOfT_t value1;
    pd_TokenIdOfT_t value2;
} pd_ClassIdOfTTokenIdOfT_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_t id;
        pd_CompactAccountIndex_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_t contained;
} pd_OptionTimepoint_t;

typedef struct {
    uint8_t value;
    pd_CurrencyId_t currencyid;
} pd_PoolId_t;

typedef struct {
    uint8_t value;
    pd_EvmAddress_t h160;
} pd_TransactionAction_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccessListItem_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
    uint32_t callTxVersion;
} pd_VecCall_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleCurrencyIdCurrencyIdOptionVecSwapPath_t;

typedef struct {
    uint8_t value;
    pd_Weight_t limited;
} pd_WeightLimit_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Eip712Signature_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Hash_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_t contained;
} pd_OptionProxyType_t;

typedef struct {
    uint8_t some;
    pd_VecCurrencyId_t contained;
} pd_OptionVecCurrencyId_t;

typedef struct {
    uint64_t value;
} pd_OverweightIndex_t;

typedef struct {
    uint32_t value;
} pd_PoolTokenIndex_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_t;

typedef struct {
    uint32_t value;
} pd_StableAssetPoolId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBalance_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_Vecu8_t;

#ifdef __cplusplus
}
#endif
