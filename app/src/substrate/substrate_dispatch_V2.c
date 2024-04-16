/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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

#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_utility_batch_V2(
    parser_context_t* c, pd_utility_batch_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V2(
    parser_context_t* c, pd_utility_batch_all_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V2(
    parser_context_t* c, pd_utility_force_batch_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V2(
    parser_context_t* c, pd_proxy_proxy_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V2(
    parser_context_t* c, pd_proxy_add_proxy_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V2(
    parser_context_t* c, pd_proxy_remove_proxy_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V2(
    parser_context_t* c, pd_balances_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V2(
    parser_context_t* c, pd_balances_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V2(
    parser_context_t* c, pd_balances_transfer_keep_alive_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V2(
    parser_context_t* c, pd_balances_transfer_all_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_currencies_transfer_V2(
    parser_context_t* c, pd_currencies_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->dest))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V2(
    parser_context_t* c, pd_session_set_keys_V2_t* m)
{
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V2(
    parser_context_t* c, pd_session_purge_keys_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
__Z_INLINE parser_error_t _readMethod_xtokens_transfer_V2(
    parser_context_t* c, pd_xtokens_transfer_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readBoxVersionedMultiLocation_V2(c, &m->dest))
    CHECK_ERROR(_readWeightLimit_V2(c, &m->dest_weight_limit))
    return parser_ok;
}
#endif
__Z_INLINE parser_error_t _readMethod_system_fill_block_V2(
    parser_context_t* c, pd_system_fill_block_V2_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V2(
    parser_context_t* c, pd_system_remark_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V2(
    parser_context_t* c, pd_system_set_heap_pages_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V2(
    parser_context_t* c, pd_system_set_code_V2_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V2(
    parser_context_t* c, pd_system_set_code_without_checks_V2_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V2(
    parser_context_t* c, pd_system_remark_with_event_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V2(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V2(
    parser_context_t* c, pd_multisig_as_multi_V2_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V2(
    parser_context_t* c, pd_multisig_approve_as_multi_V2_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V2(
    parser_context_t* c, pd_multisig_cancel_as_multi_V2_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V2(
    parser_context_t* c, pd_proxy_remove_proxies_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_create_pure_V2(
    parser_context_t* c, pd_proxy_create_pure_V2_t* m)
{
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_pure_V2(
    parser_context_t* c, pd_proxy_kill_pure_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->spawner))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V2(
    parser_context_t* c, pd_proxy_announce_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V2(
    parser_context_t* c, pd_proxy_remove_announcement_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V2(
    parser_context_t* c, pd_proxy_reject_announcement_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V2(
    parser_context_t* c, pd_proxy_proxy_announced_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V2(
    parser_context_t* c, pd_balances_set_balance_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V2(
    parser_context_t* c, pd_balances_force_unreserve_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_currencies_transfer_native_currency_V2(
    parser_context_t* c, pd_currencies_transfer_native_currency_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_currencies_update_balance_V2(
    parser_context_t* c, pd_currencies_update_balance_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->who))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readAmount(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_currencies_sweep_dust_V2(
    parser_context_t* c, pd_currencies_sweep_dust_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readVecAccountId(c, &m->accounts))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_claim_V2(
    parser_context_t* c, pd_vesting_claim_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_transactionpayment_set_alternative_fee_swap_path_V2(
    parser_context_t* c, pd_transactionpayment_set_alternative_fee_swap_path_V2_t* m)
{
    CHECK_ERROR(_readOptionVecCurrencyId(c, &m->fee_swap_path))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_transactionpayment_disable_charge_fee_pool_V2(
    parser_context_t* c, pd_transactionpayment_disable_charge_fee_pool_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_transactionpayment_with_fee_path_V2(
    parser_context_t* c, pd_transactionpayment_with_fee_path_V2_t* m)
{
    CHECK_ERROR(_readVecCurrencyId(c, &m->fee_swap_path))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_transactionpayment_with_fee_currency_V2(
    parser_context_t* c, pd_transactionpayment_with_fee_currency_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_transactionpayment_with_fee_paid_by_V2(
    parser_context_t* c, pd_transactionpayment_with_fee_paid_by_V2_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readAccountId(c, &m->payer_addr))
    CHECK_ERROR(_readMultiSignature(c, &m->payer_sig))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_transactionpayment_with_fee_aggregated_path_V2(
    parser_context_t* c, pd_transactionpayment_with_fee_aggregated_path_V2_t* m)
{
    CHECK_ERROR(_readVecSwapPath(c, &m->fee_aggregated_path))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_bounty_V2(
    parser_context_t* c, pd_bounties_propose_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V2(
    parser_context_t* c, pd_bounties_approve_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V2(
    parser_context_t* c, pd_bounties_propose_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->curator))
    CHECK_ERROR(_readCompactBalance(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V2(
    parser_context_t* c, pd_bounties_unassign_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V2(
    parser_context_t* c, pd_bounties_accept_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V2(
    parser_context_t* c, pd_bounties_award_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V2(
    parser_context_t* c, pd_bounties_claim_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V2(
    parser_context_t* c, pd_bounties_close_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V2(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_invulnerables_V2(
    parser_context_t* c, pd_collatorselection_set_invulnerables_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_desired_candidates_V2(
    parser_context_t* c, pd_collatorselection_set_desired_candidates_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_candidacy_bond_V2(
    parser_context_t* c, pd_collatorselection_set_candidacy_bond_V2_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->bond))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_register_as_candidate_V2(
    parser_context_t* c, pd_collatorselection_register_as_candidate_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_register_candidate_V2(
    parser_context_t* c, pd_collatorselection_register_candidate_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->new_candidate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_leave_intent_V2(
    parser_context_t* c, pd_collatorselection_leave_intent_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_withdraw_bond_V2(
    parser_context_t* c, pd_collatorselection_withdraw_bond_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_service_overweight_V2(
    parser_context_t* c, pd_xcmpqueue_service_overweight_V2_t* m)
{
    CHECK_ERROR(_readOverweightIndex(c, &m->index))
    CHECK_ERROR(_readXcmWeight(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_suspend_xcm_execution_V2(
    parser_context_t* c, pd_xcmpqueue_suspend_xcm_execution_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_resume_xcm_execution_V2(
    parser_context_t* c, pd_xcmpqueue_resume_xcm_execution_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_suspend_threshold_V2(
    parser_context_t* c, pd_xcmpqueue_update_suspend_threshold_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_drop_threshold_V2(
    parser_context_t* c, pd_xcmpqueue_update_drop_threshold_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_resume_threshold_V2(
    parser_context_t* c, pd_xcmpqueue_update_resume_threshold_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_threshold_weight_V2(
    parser_context_t* c, pd_xcmpqueue_update_threshold_weight_V2_t* m)
{
    CHECK_ERROR(_readXcmWeight(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_weight_restrict_decay_V2(
    parser_context_t* c, pd_xcmpqueue_update_weight_restrict_decay_V2_t* m)
{
    CHECK_ERROR(_readXcmWeight(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_xcmp_max_individual_weight_V2(
    parser_context_t* c, pd_xcmpqueue_update_xcmp_max_individual_weight_V2_t* m)
{
    CHECK_ERROR(_readXcmWeight(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V2(
    parser_context_t* c, pd_democracy_propose_V2_t* m)
{
    CHECK_ERROR(_readBoundedCallOfT(c, &m->proposal))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V2(
    parser_context_t* c, pd_democracy_second_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V2(
    parser_context_t* c, pd_democracy_emergency_cancel_V2_t* m)
{
    CHECK_ERROR(_readReferendumIndex(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V2(
    parser_context_t* c, pd_democracy_external_propose_V2_t* m)
{
    CHECK_ERROR(_readBoundedCallOfT(c, &m->proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V2(
    parser_context_t* c, pd_democracy_external_propose_majority_V2_t* m)
{
    CHECK_ERROR(_readBoundedCallOfT(c, &m->proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V2(
    parser_context_t* c, pd_democracy_external_propose_default_V2_t* m)
{
    CHECK_ERROR(_readBoundedCallOfT(c, &m->proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V2(
    parser_context_t* c, pd_democracy_fast_track_V2_t* m)
{
    CHECK_ERROR(_readH256(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V2(
    parser_context_t* c, pd_democracy_veto_external_V2_t* m)
{
    CHECK_ERROR(_readH256(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V2(
    parser_context_t* c, pd_democracy_cancel_referendum_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V2(
    parser_context_t* c, pd_democracy_undelegate_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V2(
    parser_context_t* c, pd_democracy_clear_public_proposals_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V2(
    parser_context_t* c, pd_democracy_unlock_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V2(
    parser_context_t* c, pd_democracy_cancel_proposal_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_swap_with_exact_supply_V2(
    parser_context_t* c, pd_dex_swap_with_exact_supply_V2_t* m)
{
    CHECK_ERROR(_readVecCurrencyId(c, &m->path))
    CHECK_ERROR(_readCompactu128(c, &m->supply_amount))
    CHECK_ERROR(_readCompactu128(c, &m->min_target_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_swap_with_exact_target_V2(
    parser_context_t* c, pd_dex_swap_with_exact_target_V2_t* m)
{
    CHECK_ERROR(_readVecCurrencyId(c, &m->path))
    CHECK_ERROR(_readCompactu128(c, &m->target_amount))
    CHECK_ERROR(_readCompactu128(c, &m->max_supply_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_add_liquidity_V2(
    parser_context_t* c, pd_dex_add_liquidity_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    CHECK_ERROR(_readCompactu128(c, &m->max_amount_a))
    CHECK_ERROR(_readCompactu128(c, &m->max_amount_b))
    CHECK_ERROR(_readCompactu128(c, &m->min_share_increment))
    CHECK_ERROR(_readbool(c, &m->stake_increment_share))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_add_provision_V2(
    parser_context_t* c, pd_dex_add_provision_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    CHECK_ERROR(_readCompactu128(c, &m->amount_a))
    CHECK_ERROR(_readCompactu128(c, &m->amount_b))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_claim_dex_share_V2(
    parser_context_t* c, pd_dex_claim_dex_share_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->owner))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_remove_liquidity_V2(
    parser_context_t* c, pd_dex_remove_liquidity_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    CHECK_ERROR(_readCompactu128(c, &m->remove_share))
    CHECK_ERROR(_readCompactu128(c, &m->min_withdrawn_a))
    CHECK_ERROR(_readCompactu128(c, &m->min_withdrawn_b))
    CHECK_ERROR(_readbool(c, &m->by_unstake))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_list_provisioning_V2(
    parser_context_t* c, pd_dex_list_provisioning_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    CHECK_ERROR(_readCompactu128(c, &m->min_contribution_a))
    CHECK_ERROR(_readCompactu128(c, &m->min_contribution_b))
    CHECK_ERROR(_readCompactu128(c, &m->target_provision_a))
    CHECK_ERROR(_readCompactu128(c, &m->target_provision_b))
    CHECK_ERROR(_readCompactu32(c, &m->not_before))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_update_provisioning_parameters_V2(
    parser_context_t* c, pd_dex_update_provisioning_parameters_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    CHECK_ERROR(_readCompactu128(c, &m->min_contribution_a))
    CHECK_ERROR(_readCompactu128(c, &m->min_contribution_b))
    CHECK_ERROR(_readCompactu128(c, &m->target_provision_a))
    CHECK_ERROR(_readCompactu128(c, &m->target_provision_b))
    CHECK_ERROR(_readCompactu32(c, &m->not_before))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_end_provisioning_V2(
    parser_context_t* c, pd_dex_end_provisioning_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_enable_trading_pair_V2(
    parser_context_t* c, pd_dex_enable_trading_pair_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_disable_trading_pair_V2(
    parser_context_t* c, pd_dex_disable_trading_pair_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_refund_provision_V2(
    parser_context_t* c, pd_dex_refund_provision_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->owner))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dex_abort_provisioning_V2(
    parser_context_t* c, pd_dex_abort_provisioning_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_a))
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id_b))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_aggregateddex_swap_with_exact_supply_V2(
    parser_context_t* c, pd_aggregateddex_swap_with_exact_supply_V2_t* m)
{
    CHECK_ERROR(_readVecSwapPath(c, &m->paths))
    CHECK_ERROR(_readCompactBalance(c, &m->supply_amount))
    CHECK_ERROR(_readCompactBalance(c, &m->min_target_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_aggregateddex_swap_with_exact_target_V2(
    parser_context_t* c, pd_aggregateddex_swap_with_exact_target_V2_t* m)
{
    CHECK_ERROR(_readVecSwapPath(c, &m->paths))
    CHECK_ERROR(_readCompactBalance(c, &m->target_amount))
    CHECK_ERROR(_readCompactBalance(c, &m->max_supply_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_aggregateddex_update_aggregated_swap_paths_V2(
    parser_context_t* c, pd_aggregateddex_update_aggregated_swap_paths_V2_t* m)
{
    CHECK_ERROR(_readVecTupleCurrencyIdCurrencyIdOptionVecSwapPath(c, &m->updates))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_honzon_adjust_loan_V2(
    parser_context_t* c, pd_honzon_adjust_loan_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readAmount(c, &m->collateral_adjustment))
    CHECK_ERROR(_readAmount(c, &m->debit_adjustment))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_honzon_close_loan_has_debit_by_dex_V2(
    parser_context_t* c, pd_honzon_close_loan_has_debit_by_dex_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readCompactu128(c, &m->max_collateral_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_honzon_transfer_loan_from_V2(
    parser_context_t* c, pd_honzon_transfer_loan_from_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->from))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_honzon_authorize_V2(
    parser_context_t* c, pd_honzon_authorize_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->to))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_honzon_unauthorize_V2(
    parser_context_t* c, pd_honzon_unauthorize_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->to))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_honzon_unauthorize_all_V2(
    parser_context_t* c, pd_honzon_unauthorize_all_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_honzon_expand_position_collateral_V2(
    parser_context_t* c, pd_honzon_expand_position_collateral_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readBalance(c, &m->increase_debit_value))
    CHECK_ERROR(_readBalance(c, &m->min_increase_collateral))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_honzon_shrink_position_debit_V2(
    parser_context_t* c, pd_honzon_shrink_position_debit_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readBalance(c, &m->decrease_collateral))
    CHECK_ERROR(_readBalance(c, &m->min_decrease_debit_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_honzon_adjust_loan_by_debit_value_V2(
    parser_context_t* c, pd_honzon_adjust_loan_by_debit_value_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->currency_id))
    CHECK_ERROR(_readAmount(c, &m->collateral_adjustment))
    CHECK_ERROR(_readAmount(c, &m->debit_value_adjustment))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_honzon_transfer_debit_V2(
    parser_context_t* c, pd_honzon_transfer_debit_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->from_currency))
    CHECK_ERROR(_readCurrencyId(c, &m->to_currency))
    CHECK_ERROR(_readBalance(c, &m->debit_transfer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_homa_mint_V2(
    parser_context_t* c, pd_homa_mint_V2_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_homa_request_redeem_V2(
    parser_context_t* c, pd_homa_request_redeem_V2_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readbool(c, &m->allow_fast_match))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_homa_fast_match_redeems_V2(
    parser_context_t* c, pd_homa_fast_match_redeems_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->redeemer_list))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_homa_claim_redemption_V2(
    parser_context_t* c, pd_homa_claim_redemption_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->redeemer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_homa_reset_current_era_V2(
    parser_context_t* c, pd_homa_reset_current_era_V2_t* m)
{
    CHECK_ERROR(_readEraIndex(c, &m->era_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_homa_force_bump_current_era_V2(
    parser_context_t* c, pd_homa_force_bump_current_era_V2_t* m)
{
    CHECK_ERROR(_readEraIndex(c, &m->bump_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_homa_fast_match_redeems_completely_V2(
    parser_context_t* c, pd_homa_fast_match_redeems_completely_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->redeemer_list))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_incentives_deposit_dex_share_V2(
    parser_context_t* c, pd_incentives_deposit_dex_share_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->lp_currency_id))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_incentives_withdraw_dex_share_V2(
    parser_context_t* c, pd_incentives_withdraw_dex_share_V2_t* m)
{
    CHECK_ERROR(_readCurrencyId(c, &m->lp_currency_id))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_incentives_claim_rewards_V2(
    parser_context_t* c, pd_incentives_claim_rewards_V2_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nft_transfer_V2(
    parser_context_t* c, pd_nft_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->to))
    CHECK_ERROR(_readClassIdOfTTokenIdOfT(c, &m->token))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_eth_call_V2(
    parser_context_t* c, pd_evm_eth_call_V2_t* m)
{
    CHECK_ERROR(_readTransactionAction(c, &m->action))
    CHECK_ERROR(_readVecu8(c, &m->input))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readCompactu32(c, &m->storage_limit))
    CHECK_ERROR(_readVecAccessListItem(c, &m->access_list))
    CHECK_ERROR(_readCompactu32(c, &m->valid_until))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_call_V2(
    parser_context_t* c, pd_evm_call_V2_t* m)
{
    CHECK_ERROR(_readEvmAddress(c, &m->target))
    CHECK_ERROR(_readVecu8(c, &m->input))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readCompactu32(c, &m->storage_limit))
    CHECK_ERROR(_readVecAccessListItem(c, &m->access_list))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_create_V2(
    parser_context_t* c, pd_evm_create_V2_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->input))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readCompactu32(c, &m->storage_limit))
    CHECK_ERROR(_readVecAccessListItem(c, &m->access_list))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_create2_V2(
    parser_context_t* c, pd_evm_create2_V2_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->input))
    CHECK_ERROR(_readH256(c, &m->salt))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readCompactu32(c, &m->storage_limit))
    CHECK_ERROR(_readVecAccessListItem(c, &m->access_list))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_transfer_maintainer_V2(
    parser_context_t* c, pd_evm_transfer_maintainer_V2_t* m)
{
    CHECK_ERROR(_readEvmAddress(c, &m->contract))
    CHECK_ERROR(_readEvmAddress(c, &m->new_maintainer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_publish_contract_V2(
    parser_context_t* c, pd_evm_publish_contract_V2_t* m)
{
    CHECK_ERROR(_readEvmAddress(c, &m->contract))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_publish_free_V2(
    parser_context_t* c, pd_evm_publish_free_V2_t* m)
{
    CHECK_ERROR(_readEvmAddress(c, &m->contract))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_enable_contract_development_V2(
    parser_context_t* c, pd_evm_enable_contract_development_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_disable_contract_development_V2(
    parser_context_t* c, pd_evm_disable_contract_development_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_set_code_V2(
    parser_context_t* c, pd_evm_set_code_V2_t* m)
{
    CHECK_ERROR(_readEvmAddress(c, &m->contract))
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_selfdestruct_V2(
    parser_context_t* c, pd_evm_selfdestruct_V2_t* m)
{
    CHECK_ERROR(_readEvmAddress(c, &m->contract))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evmaccounts_claim_account_V2(
    parser_context_t* c, pd_evmaccounts_claim_account_V2_t* m)
{
    CHECK_ERROR(_readEvmAddress(c, &m->eth_address))
    CHECK_ERROR(_readEip712Signature(c, &m->eth_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evmaccounts_claim_default_account_V2(
    parser_context_t* c, pd_evmaccounts_claim_default_account_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stableasset_mint_V2(
    parser_context_t* c, pd_stableasset_mint_V2_t* m)
{
    CHECK_ERROR(_readStableAssetPoolId(c, &m->pool_id))
    CHECK_ERROR(_readVecBalance(c, &m->amounts))
    CHECK_ERROR(_readBalance(c, &m->min_mint_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stableasset_swap_V2(
    parser_context_t* c, pd_stableasset_swap_V2_t* m)
{
    CHECK_ERROR(_readStableAssetPoolId(c, &m->pool_id))
    CHECK_ERROR(_readPoolTokenIndex(c, &m->i))
    CHECK_ERROR(_readPoolTokenIndex(c, &m->j))
    CHECK_ERROR(_readBalance(c, &m->dx))
    CHECK_ERROR(_readBalance(c, &m->min_dy))
    CHECK_ERROR(_readu32(c, &m->asset_length))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stableasset_redeem_proportion_V2(
    parser_context_t* c, pd_stableasset_redeem_proportion_V2_t* m)
{
    CHECK_ERROR(_readStableAssetPoolId(c, &m->pool_id))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readVecBalance(c, &m->min_redeem_amounts))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stableasset_redeem_single_V2(
    parser_context_t* c, pd_stableasset_redeem_single_V2_t* m)
{
    CHECK_ERROR(_readStableAssetPoolId(c, &m->pool_id))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readPoolTokenIndex(c, &m->i))
    CHECK_ERROR(_readBalance(c, &m->min_redeem_amount))
    CHECK_ERROR(_readu32(c, &m->asset_length))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stableasset_redeem_multi_V2(
    parser_context_t* c, pd_stableasset_redeem_multi_V2_t* m)
{
    CHECK_ERROR(_readStableAssetPoolId(c, &m->pool_id))
    CHECK_ERROR(_readVecBalance(c, &m->amounts))
    CHECK_ERROR(_readBalance(c, &m->max_redeem_amount))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V2(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V2_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V2(c, &method->basic.utility_batch_V2))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V2(c, &method->basic.utility_batch_all_V2))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V2(c, &method->basic.utility_force_batch_V2))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V2(c, &method->nested.proxy_proxy_V2))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V2(c, &method->nested.proxy_add_proxy_V2))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V2(c, &method->nested.proxy_remove_proxy_V2))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V2(c, &method->nested.balances_transfer_V2))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V2(c, &method->nested.balances_force_transfer_V2))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V2(c, &method->nested.balances_transfer_keep_alive_V2))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V2(c, &method->basic.balances_transfer_all_V2))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_currencies_transfer_V2(c, &method->nested.currencies_transfer_V2))
        break;
    case 10752: /* module 42 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V2(c, &method->basic.session_set_keys_V2))
        break;
    case 10753: /* module 42 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V2(c, &method->basic.session_purge_keys_V2))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 13824: /* module 54 call 0 */
        CHECK_ERROR(_readMethod_xtokens_transfer_V2(c, &method->basic.xtokens_transfer_V2))
        break;
#endif
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V2(c, &method->nested.system_fill_block_V2))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V2(c, &method->nested.system_remark_V2))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V2(c, &method->nested.system_set_heap_pages_V2))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V2(c, &method->nested.system_set_code_V2))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V2(c, &method->nested.system_set_code_without_checks_V2))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V2(c, &method->nested.system_remark_with_event_V2))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V2(c, &method->nested.multisig_as_multi_threshold_1_V2))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V2(c, &method->nested.multisig_as_multi_V2))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V2(c, &method->nested.multisig_approve_as_multi_V2))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V2(c, &method->nested.multisig_cancel_as_multi_V2))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V2(c, &method->basic.proxy_remove_proxies_V2))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_proxy_create_pure_V2(c, &method->basic.proxy_create_pure_V2))
        break;
    case 1285: /* module 5 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_pure_V2(c, &method->basic.proxy_kill_pure_V2))
        break;
    case 1286: /* module 5 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V2(c, &method->basic.proxy_announce_V2))
        break;
    case 1287: /* module 5 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V2(c, &method->basic.proxy_remove_announcement_V2))
        break;
    case 1288: /* module 5 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V2(c, &method->basic.proxy_reject_announcement_V2))
        break;
    case 1289: /* module 5 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V2(c, &method->basic.proxy_proxy_announced_V2))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V2(c, &method->nested.balances_set_balance_V2))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V2(c, &method->basic.balances_force_unreserve_V2))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_currencies_transfer_native_currency_V2(c, &method->nested.currencies_transfer_native_currency_V2))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_currencies_update_balance_V2(c, &method->basic.currencies_update_balance_V2))
        break;
    case 3075: /* module 12 call 3 */
        CHECK_ERROR(_readMethod_currencies_sweep_dust_V2(c, &method->basic.currencies_sweep_dust_V2))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_vesting_claim_V2(c, &method->basic.vesting_claim_V2))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_transactionpayment_set_alternative_fee_swap_path_V2(c, &method->basic.transactionpayment_set_alternative_fee_swap_path_V2))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_transactionpayment_disable_charge_fee_pool_V2(c, &method->basic.transactionpayment_disable_charge_fee_pool_V2))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_transactionpayment_with_fee_path_V2(c, &method->basic.transactionpayment_with_fee_path_V2))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_transactionpayment_with_fee_currency_V2(c, &method->basic.transactionpayment_with_fee_currency_V2))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_transactionpayment_with_fee_paid_by_V2(c, &method->basic.transactionpayment_with_fee_paid_by_V2))
        break;
    case 3590: /* module 14 call 6 */
        CHECK_ERROR(_readMethod_transactionpayment_with_fee_aggregated_path_V2(c, &method->basic.transactionpayment_with_fee_aggregated_path_V2))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V2(c, &method->basic.bounties_propose_bounty_V2))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V2(c, &method->basic.bounties_approve_bounty_V2))
        break;
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V2(c, &method->basic.bounties_propose_curator_V2))
        break;
    case 5379: /* module 21 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V2(c, &method->basic.bounties_unassign_curator_V2))
        break;
    case 5380: /* module 21 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V2(c, &method->basic.bounties_accept_curator_V2))
        break;
    case 5381: /* module 21 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V2(c, &method->basic.bounties_award_bounty_V2))
        break;
    case 5382: /* module 21 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V2(c, &method->basic.bounties_claim_bounty_V2))
        break;
    case 5383: /* module 21 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V2(c, &method->basic.bounties_close_bounty_V2))
        break;
    case 5384: /* module 21 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V2(c, &method->basic.bounties_extend_bounty_expiry_V2))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_collatorselection_set_invulnerables_V2(c, &method->basic.collatorselection_set_invulnerables_V2))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_collatorselection_set_desired_candidates_V2(c, &method->basic.collatorselection_set_desired_candidates_V2))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_collatorselection_set_candidacy_bond_V2(c, &method->basic.collatorselection_set_candidacy_bond_V2))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_collatorselection_register_as_candidate_V2(c, &method->basic.collatorselection_register_as_candidate_V2))
        break;
    case 10500: /* module 41 call 4 */
        CHECK_ERROR(_readMethod_collatorselection_register_candidate_V2(c, &method->basic.collatorselection_register_candidate_V2))
        break;
    case 10501: /* module 41 call 5 */
        CHECK_ERROR(_readMethod_collatorselection_leave_intent_V2(c, &method->basic.collatorselection_leave_intent_V2))
        break;
    case 10502: /* module 41 call 6 */
        CHECK_ERROR(_readMethod_collatorselection_withdraw_bond_V2(c, &method->basic.collatorselection_withdraw_bond_V2))
        break;
    case 12800: /* module 50 call 0 */
        CHECK_ERROR(_readMethod_xcmpqueue_service_overweight_V2(c, &method->basic.xcmpqueue_service_overweight_V2))
        break;
    case 12801: /* module 50 call 1 */
        CHECK_ERROR(_readMethod_xcmpqueue_suspend_xcm_execution_V2(c, &method->basic.xcmpqueue_suspend_xcm_execution_V2))
        break;
    case 12802: /* module 50 call 2 */
        CHECK_ERROR(_readMethod_xcmpqueue_resume_xcm_execution_V2(c, &method->basic.xcmpqueue_resume_xcm_execution_V2))
        break;
    case 12803: /* module 50 call 3 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_suspend_threshold_V2(c, &method->basic.xcmpqueue_update_suspend_threshold_V2))
        break;
    case 12804: /* module 50 call 4 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_drop_threshold_V2(c, &method->basic.xcmpqueue_update_drop_threshold_V2))
        break;
    case 12805: /* module 50 call 5 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_resume_threshold_V2(c, &method->basic.xcmpqueue_update_resume_threshold_V2))
        break;
    case 12806: /* module 50 call 6 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_threshold_weight_V2(c, &method->basic.xcmpqueue_update_threshold_weight_V2))
        break;
    case 12807: /* module 50 call 7 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_weight_restrict_decay_V2(c, &method->basic.xcmpqueue_update_weight_restrict_decay_V2))
        break;
    case 12808: /* module 50 call 8 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_xcmp_max_individual_weight_V2(c, &method->basic.xcmpqueue_update_xcmp_max_individual_weight_V2))
        break;
    case 17664: /* module 69 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V2(c, &method->basic.democracy_propose_V2))
        break;
    case 17665: /* module 69 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V2(c, &method->basic.democracy_second_V2))
        break;
    case 17667: /* module 69 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V2(c, &method->basic.democracy_emergency_cancel_V2))
        break;
    case 17668: /* module 69 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V2(c, &method->basic.democracy_external_propose_V2))
        break;
    case 17669: /* module 69 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V2(c, &method->basic.democracy_external_propose_majority_V2))
        break;
    case 17670: /* module 69 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V2(c, &method->basic.democracy_external_propose_default_V2))
        break;
    case 17671: /* module 69 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V2(c, &method->basic.democracy_fast_track_V2))
        break;
    case 17672: /* module 69 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V2(c, &method->basic.democracy_veto_external_V2))
        break;
    case 17673: /* module 69 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V2(c, &method->basic.democracy_cancel_referendum_V2))
        break;
    case 17675: /* module 69 call 11 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V2(c, &method->basic.democracy_undelegate_V2))
        break;
    case 17676: /* module 69 call 12 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V2(c, &method->basic.democracy_clear_public_proposals_V2))
        break;
    case 17677: /* module 69 call 13 */
        CHECK_ERROR(_readMethod_democracy_unlock_V2(c, &method->basic.democracy_unlock_V2))
        break;
    case 17681: /* module 69 call 17 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V2(c, &method->basic.democracy_cancel_proposal_V2))
        break;
    case 23296: /* module 91 call 0 */
        CHECK_ERROR(_readMethod_dex_swap_with_exact_supply_V2(c, &method->nested.dex_swap_with_exact_supply_V2))
        break;
    case 23297: /* module 91 call 1 */
        CHECK_ERROR(_readMethod_dex_swap_with_exact_target_V2(c, &method->basic.dex_swap_with_exact_target_V2))
        break;
    case 23298: /* module 91 call 2 */
        CHECK_ERROR(_readMethod_dex_add_liquidity_V2(c, &method->nested.dex_add_liquidity_V2))
        break;
    case 23299: /* module 91 call 3 */
        CHECK_ERROR(_readMethod_dex_add_provision_V2(c, &method->basic.dex_add_provision_V2))
        break;
    case 23300: /* module 91 call 4 */
        CHECK_ERROR(_readMethod_dex_claim_dex_share_V2(c, &method->basic.dex_claim_dex_share_V2))
        break;
    case 23301: /* module 91 call 5 */
        CHECK_ERROR(_readMethod_dex_remove_liquidity_V2(c, &method->nested.dex_remove_liquidity_V2))
        break;
    case 23302: /* module 91 call 6 */
        CHECK_ERROR(_readMethod_dex_list_provisioning_V2(c, &method->basic.dex_list_provisioning_V2))
        break;
    case 23303: /* module 91 call 7 */
        CHECK_ERROR(_readMethod_dex_update_provisioning_parameters_V2(c, &method->basic.dex_update_provisioning_parameters_V2))
        break;
    case 23304: /* module 91 call 8 */
        CHECK_ERROR(_readMethod_dex_end_provisioning_V2(c, &method->basic.dex_end_provisioning_V2))
        break;
    case 23305: /* module 91 call 9 */
        CHECK_ERROR(_readMethod_dex_enable_trading_pair_V2(c, &method->basic.dex_enable_trading_pair_V2))
        break;
    case 23306: /* module 91 call 10 */
        CHECK_ERROR(_readMethod_dex_disable_trading_pair_V2(c, &method->basic.dex_disable_trading_pair_V2))
        break;
    case 23307: /* module 91 call 11 */
        CHECK_ERROR(_readMethod_dex_refund_provision_V2(c, &method->basic.dex_refund_provision_V2))
        break;
    case 23308: /* module 91 call 12 */
        CHECK_ERROR(_readMethod_dex_abort_provisioning_V2(c, &method->basic.dex_abort_provisioning_V2))
        break;
    case 23808: /* module 93 call 0 */
        CHECK_ERROR(_readMethod_aggregateddex_swap_with_exact_supply_V2(c, &method->nested.aggregateddex_swap_with_exact_supply_V2))
        break;
    case 23809: /* module 93 call 1 */
        CHECK_ERROR(_readMethod_aggregateddex_swap_with_exact_target_V2(c, &method->nested.aggregateddex_swap_with_exact_target_V2))
        break;
    case 23810: /* module 93 call 2 */
        CHECK_ERROR(_readMethod_aggregateddex_update_aggregated_swap_paths_V2(c, &method->nested.aggregateddex_update_aggregated_swap_paths_V2))
        break;
    case 26112: /* module 102 call 0 */
        CHECK_ERROR(_readMethod_honzon_adjust_loan_V2(c, &method->nested.honzon_adjust_loan_V2))
        break;
    case 26113: /* module 102 call 1 */
        CHECK_ERROR(_readMethod_honzon_close_loan_has_debit_by_dex_V2(c, &method->basic.honzon_close_loan_has_debit_by_dex_V2))
        break;
    case 26114: /* module 102 call 2 */
        CHECK_ERROR(_readMethod_honzon_transfer_loan_from_V2(c, &method->basic.honzon_transfer_loan_from_V2))
        break;
    case 26115: /* module 102 call 3 */
        CHECK_ERROR(_readMethod_honzon_authorize_V2(c, &method->basic.honzon_authorize_V2))
        break;
    case 26116: /* module 102 call 4 */
        CHECK_ERROR(_readMethod_honzon_unauthorize_V2(c, &method->basic.honzon_unauthorize_V2))
        break;
    case 26117: /* module 102 call 5 */
        CHECK_ERROR(_readMethod_honzon_unauthorize_all_V2(c, &method->basic.honzon_unauthorize_all_V2))
        break;
    case 26118: /* module 102 call 6 */
        CHECK_ERROR(_readMethod_honzon_expand_position_collateral_V2(c, &method->basic.honzon_expand_position_collateral_V2))
        break;
    case 26119: /* module 102 call 7 */
        CHECK_ERROR(_readMethod_honzon_shrink_position_debit_V2(c, &method->basic.honzon_shrink_position_debit_V2))
        break;
    case 26120: /* module 102 call 8 */
        CHECK_ERROR(_readMethod_honzon_adjust_loan_by_debit_value_V2(c, &method->basic.honzon_adjust_loan_by_debit_value_V2))
        break;
    case 26121: /* module 102 call 9 */
        CHECK_ERROR(_readMethod_honzon_transfer_debit_V2(c, &method->basic.honzon_transfer_debit_V2))
        break;
    case 29696: /* module 116 call 0 */
        CHECK_ERROR(_readMethod_homa_mint_V2(c, &method->nested.homa_mint_V2))
        break;
    case 29697: /* module 116 call 1 */
        CHECK_ERROR(_readMethod_homa_request_redeem_V2(c, &method->nested.homa_request_redeem_V2))
        break;
    case 29698: /* module 116 call 2 */
        CHECK_ERROR(_readMethod_homa_fast_match_redeems_V2(c, &method->nested.homa_fast_match_redeems_V2))
        break;
    case 29699: /* module 116 call 3 */
        CHECK_ERROR(_readMethod_homa_claim_redemption_V2(c, &method->basic.homa_claim_redemption_V2))
        break;
    case 29703: /* module 116 call 7 */
        CHECK_ERROR(_readMethod_homa_reset_current_era_V2(c, &method->basic.homa_reset_current_era_V2))
        break;
    case 29704: /* module 116 call 8 */
        CHECK_ERROR(_readMethod_homa_force_bump_current_era_V2(c, &method->basic.homa_force_bump_current_era_V2))
        break;
    case 29705: /* module 116 call 9 */
        CHECK_ERROR(_readMethod_homa_fast_match_redeems_completely_V2(c, &method->nested.homa_fast_match_redeems_completely_V2))
        break;
    case 30720: /* module 120 call 0 */
        CHECK_ERROR(_readMethod_incentives_deposit_dex_share_V2(c, &method->basic.incentives_deposit_dex_share_V2))
        break;
    case 30721: /* module 120 call 1 */
        CHECK_ERROR(_readMethod_incentives_withdraw_dex_share_V2(c, &method->nested.incentives_withdraw_dex_share_V2))
        break;
    case 30722: /* module 120 call 2 */
        CHECK_ERROR(_readMethod_incentives_claim_rewards_V2(c, &method->basic.incentives_claim_rewards_V2))
        break;
    case 30978: /* module 121 call 2 */
        CHECK_ERROR(_readMethod_nft_transfer_V2(c, &method->basic.nft_transfer_V2))
        break;
    case 33280: /* module 130 call 0 */
        CHECK_ERROR(_readMethod_evm_eth_call_V2(c, &method->basic.evm_eth_call_V2))
        break;
    case 33281: /* module 130 call 1 */
        CHECK_ERROR(_readMethod_evm_call_V2(c, &method->basic.evm_call_V2))
        break;
    case 33283: /* module 130 call 3 */
        CHECK_ERROR(_readMethod_evm_create_V2(c, &method->basic.evm_create_V2))
        break;
    case 33284: /* module 130 call 4 */
        CHECK_ERROR(_readMethod_evm_create2_V2(c, &method->basic.evm_create2_V2))
        break;
    case 33287: /* module 130 call 7 */
        CHECK_ERROR(_readMethod_evm_transfer_maintainer_V2(c, &method->basic.evm_transfer_maintainer_V2))
        break;
    case 33288: /* module 130 call 8 */
        CHECK_ERROR(_readMethod_evm_publish_contract_V2(c, &method->basic.evm_publish_contract_V2))
        break;
    case 33289: /* module 130 call 9 */
        CHECK_ERROR(_readMethod_evm_publish_free_V2(c, &method->basic.evm_publish_free_V2))
        break;
    case 33290: /* module 130 call 10 */
        CHECK_ERROR(_readMethod_evm_enable_contract_development_V2(c, &method->basic.evm_enable_contract_development_V2))
        break;
    case 33291: /* module 130 call 11 */
        CHECK_ERROR(_readMethod_evm_disable_contract_development_V2(c, &method->basic.evm_disable_contract_development_V2))
        break;
    case 33292: /* module 130 call 12 */
        CHECK_ERROR(_readMethod_evm_set_code_V2(c, &method->basic.evm_set_code_V2))
        break;
    case 33293: /* module 130 call 13 */
        CHECK_ERROR(_readMethod_evm_selfdestruct_V2(c, &method->basic.evm_selfdestruct_V2))
        break;
    case 33792: /* module 132 call 0 */
        CHECK_ERROR(_readMethod_evmaccounts_claim_account_V2(c, &method->basic.evmaccounts_claim_account_V2))
        break;
    case 33793: /* module 132 call 1 */
        CHECK_ERROR(_readMethod_evmaccounts_claim_default_account_V2(c, &method->basic.evmaccounts_claim_default_account_V2))
        break;
    case 51201: /* module 200 call 1 */
        CHECK_ERROR(_readMethod_stableasset_mint_V2(c, &method->basic.stableasset_mint_V2))
        break;
    case 51202: /* module 200 call 2 */
        CHECK_ERROR(_readMethod_stableasset_swap_V2(c, &method->basic.stableasset_swap_V2))
        break;
    case 51203: /* module 200 call 3 */
        CHECK_ERROR(_readMethod_stableasset_redeem_proportion_V2(c, &method->basic.stableasset_redeem_proportion_V2))
        break;
    case 51204: /* module 200 call 4 */
        CHECK_ERROR(_readMethod_stableasset_redeem_single_V2(c, &method->basic.stableasset_redeem_single_V2))
        break;
    case 51205: /* module 200 call 5 */
        CHECK_ERROR(_readMethod_stableasset_redeem_multi_V2(c, &method->basic.stableasset_redeem_multi_V2))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V2(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 3:
        return STR_MO_UTILITY;
    case 5:
        return STR_MO_PROXY;
    case 10:
        return STR_MO_BALANCES;
    case 12:
        return STR_MO_CURRENCIES;
    case 42:
        return STR_MO_SESSION;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 54:
        return STR_MO_XTOKENS;
#endif
    case 0:
        return STR_MO_SYSTEM;
    case 4:
        return STR_MO_MULTISIG;
    case 13:
        return STR_MO_VESTING;
    case 14:
        return STR_MO_TRANSACTIONPAYMENT;
    case 21:
        return STR_MO_BOUNTIES;
    case 41:
        return STR_MO_COLLATORSELECTION;
    case 50:
        return STR_MO_XCMPQUEUE;
    case 69:
        return STR_MO_DEMOCRACY;
    case 91:
        return STR_MO_DEX;
    case 93:
        return STR_MO_AGGREGATEDDEX;
    case 102:
        return STR_MO_HONZON;
    case 116:
        return STR_MO_HOMA;
    case 120:
        return STR_MO_INCENTIVES;
    case 121:
        return STR_MO_NFT;
    case 130:
        return STR_MO_EVM;
    case 132:
        return STR_MO_EVMACCOUNTS;
    case 200:
        return STR_MO_STABLEASSET;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 768: /* module 3 call 0 */
        return STR_ME_BATCH;
    case 770: /* module 3 call 2 */
        return STR_ME_BATCH_ALL;
    case 772: /* module 3 call 4 */
        return STR_ME_FORCE_BATCH;
    case 1280: /* module 5 call 0 */
        return STR_ME_PROXY;
    case 1281: /* module 5 call 1 */
        return STR_ME_ADD_PROXY;
    case 1282: /* module 5 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 2560: /* module 10 call 0 */
        return STR_ME_TRANSFER;
    case 2562: /* module 10 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 2563: /* module 10 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 2564: /* module 10 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 3072: /* module 12 call 0 */
        return STR_ME_TRANSFER;
    case 10752: /* module 42 call 0 */
        return STR_ME_SET_KEYS;
    case 10753: /* module 42 call 1 */
        return STR_ME_PURGE_KEYS;
    default:
        return _getMethod_Name_V2_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V2_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 13824: /* module 54 call 0 */
        return STR_ME_TRANSFER;
#endif
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 8: /* module 0 call 8 */
        return STR_ME_REMARK_WITH_EVENT;
    case 1024: /* module 4 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 1025: /* module 4 call 1 */
        return STR_ME_AS_MULTI;
    case 1026: /* module 4 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 1027: /* module 4 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 1283: /* module 5 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 1284: /* module 5 call 4 */
        return STR_ME_CREATE_PURE;
    case 1285: /* module 5 call 5 */
        return STR_ME_KILL_PURE;
    case 1286: /* module 5 call 6 */
        return STR_ME_ANNOUNCE;
    case 1287: /* module 5 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 1288: /* module 5 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 1289: /* module 5 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 2561: /* module 10 call 1 */
        return STR_ME_SET_BALANCE;
    case 2565: /* module 10 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 3073: /* module 12 call 1 */
        return STR_ME_TRANSFER_NATIVE_CURRENCY;
    case 3074: /* module 12 call 2 */
        return STR_ME_UPDATE_BALANCE;
    case 3075: /* module 12 call 3 */
        return STR_ME_SWEEP_DUST;
    case 3328: /* module 13 call 0 */
        return STR_ME_CLAIM;
    case 3584: /* module 14 call 0 */
        return STR_ME_SET_ALTERNATIVE_FEE_SWAP_PATH;
    case 3586: /* module 14 call 2 */
        return STR_ME_DISABLE_CHARGE_FEE_POOL;
    case 3587: /* module 14 call 3 */
        return STR_ME_WITH_FEE_PATH;
    case 3588: /* module 14 call 4 */
        return STR_ME_WITH_FEE_CURRENCY;
    case 3589: /* module 14 call 5 */
        return STR_ME_WITH_FEE_PAID_BY;
    case 3590: /* module 14 call 6 */
        return STR_ME_WITH_FEE_AGGREGATED_PATH;
    case 5376: /* module 21 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 5377: /* module 21 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 5378: /* module 21 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 5379: /* module 21 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 5380: /* module 21 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 5381: /* module 21 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 5382: /* module 21 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 5383: /* module 21 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 5384: /* module 21 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 10496: /* module 41 call 0 */
        return STR_ME_SET_INVULNERABLES;
    case 10497: /* module 41 call 1 */
        return STR_ME_SET_DESIRED_CANDIDATES;
    case 10498: /* module 41 call 2 */
        return STR_ME_SET_CANDIDACY_BOND;
    case 10499: /* module 41 call 3 */
        return STR_ME_REGISTER_AS_CANDIDATE;
    case 10500: /* module 41 call 4 */
        return STR_ME_REGISTER_CANDIDATE;
    case 10501: /* module 41 call 5 */
        return STR_ME_LEAVE_INTENT;
    case 10502: /* module 41 call 6 */
        return STR_ME_WITHDRAW_BOND;
    case 12800: /* module 50 call 0 */
        return STR_ME_SERVICE_OVERWEIGHT;
    case 12801: /* module 50 call 1 */
        return STR_ME_SUSPEND_XCM_EXECUTION;
    case 12802: /* module 50 call 2 */
        return STR_ME_RESUME_XCM_EXECUTION;
    case 12803: /* module 50 call 3 */
        return STR_ME_UPDATE_SUSPEND_THRESHOLD;
    case 12804: /* module 50 call 4 */
        return STR_ME_UPDATE_DROP_THRESHOLD;
    case 12805: /* module 50 call 5 */
        return STR_ME_UPDATE_RESUME_THRESHOLD;
    case 12806: /* module 50 call 6 */
        return STR_ME_UPDATE_THRESHOLD_WEIGHT;
    case 12807: /* module 50 call 7 */
        return STR_ME_UPDATE_WEIGHT_RESTRICT_DECAY;
    case 12808: /* module 50 call 8 */
        return STR_ME_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT;
    case 17664: /* module 69 call 0 */
        return STR_ME_PROPOSE;
    case 17665: /* module 69 call 1 */
        return STR_ME_SECOND;
    case 17667: /* module 69 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 17668: /* module 69 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 17669: /* module 69 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 17670: /* module 69 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 17671: /* module 69 call 7 */
        return STR_ME_FAST_TRACK;
    case 17672: /* module 69 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 17673: /* module 69 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 17675: /* module 69 call 11 */
        return STR_ME_UNDELEGATE;
    case 17676: /* module 69 call 12 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 17677: /* module 69 call 13 */
        return STR_ME_UNLOCK;
    case 17681: /* module 69 call 17 */
        return STR_ME_CANCEL_PROPOSAL;
    case 23296: /* module 91 call 0 */
        return STR_ME_SWAP_WITH_EXACT_SUPPLY;
    case 23297: /* module 91 call 1 */
        return STR_ME_SWAP_WITH_EXACT_TARGET;
    case 23298: /* module 91 call 2 */
        return STR_ME_ADD_LIQUIDITY;
    case 23299: /* module 91 call 3 */
        return STR_ME_ADD_PROVISION;
    case 23300: /* module 91 call 4 */
        return STR_ME_CLAIM_DEX_SHARE;
    case 23301: /* module 91 call 5 */
        return STR_ME_REMOVE_LIQUIDITY;
    case 23302: /* module 91 call 6 */
        return STR_ME_LIST_PROVISIONING;
    case 23303: /* module 91 call 7 */
        return STR_ME_UPDATE_PROVISIONING_PARAMETERS;
    case 23304: /* module 91 call 8 */
        return STR_ME_END_PROVISIONING;
    case 23305: /* module 91 call 9 */
        return STR_ME_ENABLE_TRADING_PAIR;
    case 23306: /* module 91 call 10 */
        return STR_ME_DISABLE_TRADING_PAIR;
    case 23307: /* module 91 call 11 */
        return STR_ME_REFUND_PROVISION;
    case 23308: /* module 91 call 12 */
        return STR_ME_ABORT_PROVISIONING;
    case 23808: /* module 93 call 0 */
        return STR_ME_SWAP_WITH_EXACT_SUPPLY;
    case 23809: /* module 93 call 1 */
        return STR_ME_SWAP_WITH_EXACT_TARGET;
    case 23810: /* module 93 call 2 */
        return STR_ME_UPDATE_AGGREGATED_SWAP_PATHS;
    case 26112: /* module 102 call 0 */
        return STR_ME_ADJUST_LOAN;
    case 26113: /* module 102 call 1 */
        return STR_ME_CLOSE_LOAN_HAS_DEBIT_BY_DEX;
    case 26114: /* module 102 call 2 */
        return STR_ME_TRANSFER_LOAN_FROM;
    case 26115: /* module 102 call 3 */
        return STR_ME_AUTHORIZE;
    case 26116: /* module 102 call 4 */
        return STR_ME_UNAUTHORIZE;
    case 26117: /* module 102 call 5 */
        return STR_ME_UNAUTHORIZE_ALL;
    case 26118: /* module 102 call 6 */
        return STR_ME_EXPAND_POSITION_COLLATERAL;
    case 26119: /* module 102 call 7 */
        return STR_ME_SHRINK_POSITION_DEBIT;
    case 26120: /* module 102 call 8 */
        return STR_ME_ADJUST_LOAN_BY_DEBIT_VALUE;
    case 26121: /* module 102 call 9 */
        return STR_ME_TRANSFER_DEBIT;
    case 29696: /* module 116 call 0 */
        return STR_ME_MINT;
    case 29697: /* module 116 call 1 */
        return STR_ME_REQUEST_REDEEM;
    case 29698: /* module 116 call 2 */
        return STR_ME_FAST_MATCH_REDEEMS;
    case 29699: /* module 116 call 3 */
        return STR_ME_CLAIM_REDEMPTION;
    case 29703: /* module 116 call 7 */
        return STR_ME_RESET_CURRENT_ERA;
    case 29704: /* module 116 call 8 */
        return STR_ME_FORCE_BUMP_CURRENT_ERA;
    case 29705: /* module 116 call 9 */
        return STR_ME_FAST_MATCH_REDEEMS_COMPLETELY;
    case 30720: /* module 120 call 0 */
        return STR_ME_DEPOSIT_DEX_SHARE;
    case 30721: /* module 120 call 1 */
        return STR_ME_WITHDRAW_DEX_SHARE;
    case 30722: /* module 120 call 2 */
        return STR_ME_CLAIM_REWARDS;
    case 30978: /* module 121 call 2 */
        return STR_ME_TRANSFER;
    case 33280: /* module 130 call 0 */
        return STR_ME_ETH_CALL;
    case 33281: /* module 130 call 1 */
        return STR_ME_CALL;
    case 33283: /* module 130 call 3 */
        return STR_ME_CREATE;
    case 33284: /* module 130 call 4 */
        return STR_ME_CREATE2;
    case 33287: /* module 130 call 7 */
        return STR_ME_TRANSFER_MAINTAINER;
    case 33288: /* module 130 call 8 */
        return STR_ME_PUBLISH_CONTRACT;
    case 33289: /* module 130 call 9 */
        return STR_ME_PUBLISH_FREE;
    case 33290: /* module 130 call 10 */
        return STR_ME_ENABLE_CONTRACT_DEVELOPMENT;
    case 33291: /* module 130 call 11 */
        return STR_ME_DISABLE_CONTRACT_DEVELOPMENT;
    case 33292: /* module 130 call 12 */
        return STR_ME_SET_CODE;
    case 33293: /* module 130 call 13 */
        return STR_ME_SELFDESTRUCT;
    case 33792: /* module 132 call 0 */
        return STR_ME_CLAIM_ACCOUNT;
    case 33793: /* module 132 call 1 */
        return STR_ME_CLAIM_DEFAULT_ACCOUNT;
    case 51201: /* module 200 call 1 */
        return STR_ME_MINT;
    case 51202: /* module 200 call 2 */
        return STR_ME_SWAP;
    case 51203: /* module 200 call 3 */
        return STR_ME_REDEEM_PROPORTION;
    case 51204: /* module 200 call 4 */
        return STR_ME_REDEEM_SINGLE;
    case 51205: /* module 200 call 5 */
        return STR_ME_REDEEM_MULTI;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 768: /* module 3 call 0 */
        return 1;
    case 770: /* module 3 call 2 */
        return 1;
    case 772: /* module 3 call 4 */
        return 1;
    case 1280: /* module 5 call 0 */
        return 3;
    case 1281: /* module 5 call 1 */
        return 3;
    case 1282: /* module 5 call 2 */
        return 3;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2562: /* module 10 call 2 */
        return 3;
    case 2563: /* module 10 call 3 */
        return 2;
    case 2564: /* module 10 call 4 */
        return 2;
    case 3072: /* module 12 call 0 */
        return 3;
    case 10752: /* module 42 call 0 */
        return 2;
    case 10753: /* module 42 call 1 */
        return 0;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 13824: /* module 54 call 0 */
        return 4;
#endif
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 8: /* module 0 call 8 */
        return 1;
    case 1024: /* module 4 call 0 */
        return 2;
    case 1025: /* module 4 call 1 */
        return 5;
    case 1026: /* module 4 call 2 */
        return 5;
    case 1027: /* module 4 call 3 */
        return 4;
    case 1283: /* module 5 call 3 */
        return 0;
    case 1284: /* module 5 call 4 */
        return 3;
    case 1285: /* module 5 call 5 */
        return 5;
    case 1286: /* module 5 call 6 */
        return 2;
    case 1287: /* module 5 call 7 */
        return 2;
    case 1288: /* module 5 call 8 */
        return 2;
    case 1289: /* module 5 call 9 */
        return 4;
    case 2561: /* module 10 call 1 */
        return 3;
    case 2565: /* module 10 call 5 */
        return 2;
    case 3073: /* module 12 call 1 */
        return 2;
    case 3074: /* module 12 call 2 */
        return 3;
    case 3075: /* module 12 call 3 */
        return 2;
    case 3328: /* module 13 call 0 */
        return 0;
    case 3584: /* module 14 call 0 */
        return 1;
    case 3586: /* module 14 call 2 */
        return 1;
    case 3587: /* module 14 call 3 */
        return 2;
    case 3588: /* module 14 call 4 */
        return 2;
    case 3589: /* module 14 call 5 */
        return 3;
    case 3590: /* module 14 call 6 */
        return 2;
    case 5376: /* module 21 call 0 */
        return 2;
    case 5377: /* module 21 call 1 */
        return 1;
    case 5378: /* module 21 call 2 */
        return 3;
    case 5379: /* module 21 call 3 */
        return 1;
    case 5380: /* module 21 call 4 */
        return 1;
    case 5381: /* module 21 call 5 */
        return 2;
    case 5382: /* module 21 call 6 */
        return 1;
    case 5383: /* module 21 call 7 */
        return 1;
    case 5384: /* module 21 call 8 */
        return 2;
    case 10496: /* module 41 call 0 */
        return 1;
    case 10497: /* module 41 call 1 */
        return 1;
    case 10498: /* module 41 call 2 */
        return 1;
    case 10499: /* module 41 call 3 */
        return 0;
    case 10500: /* module 41 call 4 */
        return 1;
    case 10501: /* module 41 call 5 */
        return 0;
    case 10502: /* module 41 call 6 */
        return 0;
    case 12800: /* module 50 call 0 */
        return 2;
    case 12801: /* module 50 call 1 */
        return 0;
    case 12802: /* module 50 call 2 */
        return 0;
    case 12803: /* module 50 call 3 */
        return 1;
    case 12804: /* module 50 call 4 */
        return 1;
    case 12805: /* module 50 call 5 */
        return 1;
    case 12806: /* module 50 call 6 */
        return 1;
    case 12807: /* module 50 call 7 */
        return 1;
    case 12808: /* module 50 call 8 */
        return 1;
    case 17664: /* module 69 call 0 */
        return 2;
    case 17665: /* module 69 call 1 */
        return 1;
    case 17667: /* module 69 call 3 */
        return 1;
    case 17668: /* module 69 call 4 */
        return 1;
    case 17669: /* module 69 call 5 */
        return 1;
    case 17670: /* module 69 call 6 */
        return 1;
    case 17671: /* module 69 call 7 */
        return 3;
    case 17672: /* module 69 call 8 */
        return 1;
    case 17673: /* module 69 call 9 */
        return 1;
    case 17675: /* module 69 call 11 */
        return 0;
    case 17676: /* module 69 call 12 */
        return 0;
    case 17677: /* module 69 call 13 */
        return 1;
    case 17681: /* module 69 call 17 */
        return 1;
    case 23296: /* module 91 call 0 */
        return 3;
    case 23297: /* module 91 call 1 */
        return 3;
    case 23298: /* module 91 call 2 */
        return 6;
    case 23299: /* module 91 call 3 */
        return 4;
    case 23300: /* module 91 call 4 */
        return 3;
    case 23301: /* module 91 call 5 */
        return 6;
    case 23302: /* module 91 call 6 */
        return 7;
    case 23303: /* module 91 call 7 */
        return 7;
    case 23304: /* module 91 call 8 */
        return 2;
    case 23305: /* module 91 call 9 */
        return 2;
    case 23306: /* module 91 call 10 */
        return 2;
    case 23307: /* module 91 call 11 */
        return 3;
    case 23308: /* module 91 call 12 */
        return 2;
    case 23808: /* module 93 call 0 */
        return 3;
    case 23809: /* module 93 call 1 */
        return 3;
    case 23810: /* module 93 call 2 */
        return 1;
    case 26112: /* module 102 call 0 */
        return 3;
    case 26113: /* module 102 call 1 */
        return 2;
    case 26114: /* module 102 call 2 */
        return 2;
    case 26115: /* module 102 call 3 */
        return 2;
    case 26116: /* module 102 call 4 */
        return 2;
    case 26117: /* module 102 call 5 */
        return 0;
    case 26118: /* module 102 call 6 */
        return 3;
    case 26119: /* module 102 call 7 */
        return 3;
    case 26120: /* module 102 call 8 */
        return 3;
    case 26121: /* module 102 call 9 */
        return 3;
    case 29696: /* module 116 call 0 */
        return 1;
    case 29697: /* module 116 call 1 */
        return 2;
    case 29698: /* module 116 call 2 */
        return 1;
    case 29699: /* module 116 call 3 */
        return 1;
    case 29703: /* module 116 call 7 */
        return 1;
    case 29704: /* module 116 call 8 */
        return 1;
    case 29705: /* module 116 call 9 */
        return 1;
    case 30720: /* module 120 call 0 */
        return 2;
    case 30721: /* module 120 call 1 */
        return 2;
    case 30722: /* module 120 call 2 */
        return 1;
    case 30978: /* module 121 call 2 */
        return 2;
    case 33280: /* module 130 call 0 */
        return 7;
    case 33281: /* module 130 call 1 */
        return 6;
    case 33283: /* module 130 call 3 */
        return 5;
    case 33284: /* module 130 call 4 */
        return 6;
    case 33287: /* module 130 call 7 */
        return 2;
    case 33288: /* module 130 call 8 */
        return 1;
    case 33289: /* module 130 call 9 */
        return 1;
    case 33290: /* module 130 call 10 */
        return 0;
    case 33291: /* module 130 call 11 */
        return 0;
    case 33292: /* module 130 call 12 */
        return 2;
    case 33293: /* module 130 call 13 */
        return 1;
    case 33792: /* module 132 call 0 */
        return 2;
    case 33793: /* module 132 call 1 */
        return 0;
    case 51201: /* module 200 call 1 */
        return 3;
    case 51202: /* module 200 call 2 */
        return 6;
    case 51203: /* module 200 call 3 */
        return 3;
    case 51204: /* module 200 call 4 */
        return 5;
    case 51205: /* module 200 call 5 */
        return 3;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_currency_id;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 13824: /* module 54 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_dest;
        case 3:
            return STR_IT_dest_weight_limit;
        default:
            return NULL;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 1286: /* module 5 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 1287: /* module 5 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 1288: /* module 5 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 1289: /* module 5 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_currency_id;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_accounts;
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_fee_swap_path;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_fee_swap_path;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_payer_addr;
        case 2:
            return STR_IT_payer_sig;
        default:
            return NULL;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_fee_aggregated_path;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_curator;
        case 2:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 5383: /* module 21 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 5384: /* module 21 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bond;
        default:
            return NULL;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10500: /* module 41 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_candidate;
        default:
            return NULL;
        }
    case 10501: /* module 41 call 5 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10502: /* module 41 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 12805: /* module 50 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 12806: /* module 50 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 12807: /* module 50 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 12808: /* module 50 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 17664: /* module 69 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 17665: /* module 69 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        default:
            return NULL;
        }
    case 17667: /* module 69 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 17668: /* module 69 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        default:
            return NULL;
        }
    case 17669: /* module 69 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        default:
            return NULL;
        }
    case 17670: /* module 69 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        default:
            return NULL;
        }
    case 17671: /* module 69 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 17672: /* module 69 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 17673: /* module 69 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 17675: /* module 69 call 11 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 17676: /* module 69 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 17677: /* module 69 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 17681: /* module 69 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prop_index;
        default:
            return NULL;
        }
    case 23296: /* module 91 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_path;
        case 1:
            return STR_IT_supply_amount;
        case 2:
            return STR_IT_min_target_amount;
        default:
            return NULL;
        }
    case 23297: /* module 91 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_path;
        case 1:
            return STR_IT_target_amount;
        case 2:
            return STR_IT_max_supply_amount;
        default:
            return NULL;
        }
    case 23298: /* module 91 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id_a;
        case 1:
            return STR_IT_currency_id_b;
        case 2:
            return STR_IT_max_amount_a;
        case 3:
            return STR_IT_max_amount_b;
        case 4:
            return STR_IT_min_share_increment;
        case 5:
            return STR_IT_stake_increment_share;
        default:
            return NULL;
        }
    case 23299: /* module 91 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id_a;
        case 1:
            return STR_IT_currency_id_b;
        case 2:
            return STR_IT_amount_a;
        case 3:
            return STR_IT_amount_b;
        default:
            return NULL;
        }
    case 23300: /* module 91 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_owner;
        case 1:
            return STR_IT_currency_id_a;
        case 2:
            return STR_IT_currency_id_b;
        default:
            return NULL;
        }
    case 23301: /* module 91 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id_a;
        case 1:
            return STR_IT_currency_id_b;
        case 2:
            return STR_IT_remove_share;
        case 3:
            return STR_IT_min_withdrawn_a;
        case 4:
            return STR_IT_min_withdrawn_b;
        case 5:
            return STR_IT_by_unstake;
        default:
            return NULL;
        }
    case 23302: /* module 91 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id_a;
        case 1:
            return STR_IT_currency_id_b;
        case 2:
            return STR_IT_min_contribution_a;
        case 3:
            return STR_IT_min_contribution_b;
        case 4:
            return STR_IT_target_provision_a;
        case 5:
            return STR_IT_target_provision_b;
        case 6:
            return STR_IT_not_before;
        default:
            return NULL;
        }
    case 23303: /* module 91 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id_a;
        case 1:
            return STR_IT_currency_id_b;
        case 2:
            return STR_IT_min_contribution_a;
        case 3:
            return STR_IT_min_contribution_b;
        case 4:
            return STR_IT_target_provision_a;
        case 5:
            return STR_IT_target_provision_b;
        case 6:
            return STR_IT_not_before;
        default:
            return NULL;
        }
    case 23304: /* module 91 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id_a;
        case 1:
            return STR_IT_currency_id_b;
        default:
            return NULL;
        }
    case 23305: /* module 91 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id_a;
        case 1:
            return STR_IT_currency_id_b;
        default:
            return NULL;
        }
    case 23306: /* module 91 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id_a;
        case 1:
            return STR_IT_currency_id_b;
        default:
            return NULL;
        }
    case 23307: /* module 91 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_owner;
        case 1:
            return STR_IT_currency_id_a;
        case 2:
            return STR_IT_currency_id_b;
        default:
            return NULL;
        }
    case 23308: /* module 91 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id_a;
        case 1:
            return STR_IT_currency_id_b;
        default:
            return NULL;
        }
    case 23808: /* module 93 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_paths;
        case 1:
            return STR_IT_supply_amount;
        case 2:
            return STR_IT_min_target_amount;
        default:
            return NULL;
        }
    case 23809: /* module 93 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_paths;
        case 1:
            return STR_IT_target_amount;
        case 2:
            return STR_IT_max_supply_amount;
        default:
            return NULL;
        }
    case 23810: /* module 93 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_updates;
        default:
            return NULL;
        }
    case 26112: /* module 102 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_collateral_adjustment;
        case 2:
            return STR_IT_debit_adjustment;
        default:
            return NULL;
        }
    case 26113: /* module 102 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_max_collateral_amount;
        default:
            return NULL;
        }
    case 26114: /* module 102 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_from;
        default:
            return NULL;
        }
    case 26115: /* module 102 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_to;
        default:
            return NULL;
        }
    case 26116: /* module 102 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_to;
        default:
            return NULL;
        }
    case 26117: /* module 102 call 5 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 26118: /* module 102 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_increase_debit_value;
        case 2:
            return STR_IT_min_increase_collateral;
        default:
            return NULL;
        }
    case 26119: /* module 102 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_decrease_collateral;
        case 2:
            return STR_IT_min_decrease_debit_value;
        default:
            return NULL;
        }
    case 26120: /* module 102 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_currency_id;
        case 1:
            return STR_IT_collateral_adjustment;
        case 2:
            return STR_IT_debit_value_adjustment;
        default:
            return NULL;
        }
    case 26121: /* module 102 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_from_currency;
        case 1:
            return STR_IT_to_currency;
        case 2:
            return STR_IT_debit_transfer;
        default:
            return NULL;
        }
    case 29696: /* module 116 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 29697: /* module 116 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_allow_fast_match;
        default:
            return NULL;
        }
    case 29698: /* module 116 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_redeemer_list;
        default:
            return NULL;
        }
    case 29699: /* module 116 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_redeemer;
        default:
            return NULL;
        }
    case 29703: /* module 116 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era_index;
        default:
            return NULL;
        }
    case 29704: /* module 116 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bump_amount;
        default:
            return NULL;
        }
    case 29705: /* module 116 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_redeemer_list;
        default:
            return NULL;
        }
    case 30720: /* module 120 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lp_currency_id;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 30721: /* module 120 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lp_currency_id;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 30722: /* module 120 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 30978: /* module 121 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_token;
        default:
            return NULL;
        }
    case 33280: /* module 130 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_action;
        case 1:
            return STR_IT_input;
        case 2:
            return STR_IT_amount;
        case 3:
            return STR_IT_gas_limit;
        case 4:
            return STR_IT_storage_limit;
        case 5:
            return STR_IT_access_list;
        case 6:
            return STR_IT_valid_until;
        default:
            return NULL;
        }
    case 33281: /* module 130 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_input;
        case 2:
            return STR_IT_amount;
        case 3:
            return STR_IT_gas_limit;
        case 4:
            return STR_IT_storage_limit;
        case 5:
            return STR_IT_access_list;
        default:
            return NULL;
        }
    case 33283: /* module 130 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_input;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_gas_limit;
        case 3:
            return STR_IT_storage_limit;
        case 4:
            return STR_IT_access_list;
        default:
            return NULL;
        }
    case 33284: /* module 130 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_input;
        case 1:
            return STR_IT_salt;
        case 2:
            return STR_IT_amount;
        case 3:
            return STR_IT_gas_limit;
        case 4:
            return STR_IT_storage_limit;
        case 5:
            return STR_IT_access_list;
        default:
            return NULL;
        }
    case 33287: /* module 130 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_contract;
        case 1:
            return STR_IT_new_maintainer;
        default:
            return NULL;
        }
    case 33288: /* module 130 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_contract;
        default:
            return NULL;
        }
    case 33289: /* module 130 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_contract;
        default:
            return NULL;
        }
    case 33290: /* module 130 call 10 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 33291: /* module 130 call 11 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 33292: /* module 130 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_contract;
        case 1:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 33293: /* module 130 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_contract;
        default:
            return NULL;
        }
    case 33792: /* module 132 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_eth_address;
        case 1:
            return STR_IT_eth_signature;
        default:
            return NULL;
        }
    case 33793: /* module 132 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 51201: /* module 200 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_amounts;
        case 2:
            return STR_IT_min_mint_amount;
        default:
            return NULL;
        }
    case 51202: /* module 200 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_i;
        case 2:
            return STR_IT_j;
        case 3:
            return STR_IT_dx;
        case 4:
            return STR_IT_min_dy;
        case 5:
            return STR_IT_asset_length;
        default:
            return NULL;
        }
    case 51203: /* module 200 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_min_redeem_amounts;
        default:
            return NULL;
        }
    case 51204: /* module 200 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_i;
        case 3:
            return STR_IT_min_redeem_amount;
        case 4:
            return STR_IT_asset_length;
        default:
            return NULL;
        }
    case 51205: /* module 200 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_amounts;
        case 2:
            return STR_IT_max_redeem_amount;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V2(
    pd_Method_V2_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V2 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V2 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V2 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V2 - real */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_proxy_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V2 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->nested.proxy_proxy_V2.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V2 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_add_proxy_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V2 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_add_proxy_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V2 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_add_proxy_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_remove_proxy_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V2 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_remove_proxy_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V2 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_remove_proxy_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V2 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V2 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V2 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V2 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_keep_alive_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V2 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_transfer_all_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V2 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V2.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* currencies_transfer_V2 - dest */;
            return _toStringLookupasStaticLookupSource(
                &m->nested.currencies_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* currencies_transfer_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->nested.currencies_transfer_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* currencies_transfer_V2 - amount */;
            return _toStringCompactu128(
                &m->nested.currencies_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V2 - keys */;
            return _toStringKeys(
                &m->basic.session_set_keys_V2.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V2 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V2.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 13824: /* module 54 call 0 */
        switch (itemIdx) {
        case 0: /* xtokens_transfer_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.xtokens_transfer_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xtokens_transfer_V2 - amount */;
            return _toStringBalance(
                &m->basic.xtokens_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xtokens_transfer_V2 - dest */;
            return _toStringBoxVersionedMultiLocation_V2(
                &m->basic.xtokens_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* xtokens_transfer_V2 - dest_weight_limit */;
            return _toStringWeightLimit_V2(
                &m->basic.xtokens_transfer_V2.dest_weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V2 - ratio */;
            return _toStringPerbill(
                &m->nested.system_fill_block_V2.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V2 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V2 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V2.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V2 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V2 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V2 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V2 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_threshold_1_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V2 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V2 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V2 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V2 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_as_multi_V2.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V2 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V2 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_as_multi_V2.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V2 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V2 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_approve_as_multi_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V2 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_approve_as_multi_V2.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V2 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V2 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_approve_as_multi_V2.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V2 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V2 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_cancel_as_multi_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V2 - timepoint */;
            return _toStringTimepoint(
                &m->nested.multisig_cancel_as_multi_V2.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V2 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_create_pure_V2 - proxy_type */;
            return _toStringProxyType(
                &m->basic.proxy_create_pure_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_create_pure_V2 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_create_pure_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_create_pure_V2 - index */;
            return _toStringu16(
                &m->basic.proxy_create_pure_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_pure_V2 - spawner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_kill_pure_V2.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_pure_V2 - proxy_type */;
            return _toStringProxyType(
                &m->basic.proxy_kill_pure_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_pure_V2 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_pure_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_pure_V2 - height */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_pure_V2.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_pure_V2 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_pure_V2.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1286: /* module 5 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V2 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_announce_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V2 - call_hash */;
            return _toStringCallHashOf(
                &m->basic.proxy_announce_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1287: /* module 5 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V2 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_remove_announcement_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V2 - call_hash */;
            return _toStringCallHashOf(
                &m->basic.proxy_remove_announcement_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1288: /* module 5 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_reject_announcement_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V2 - call_hash */;
            return _toStringCallHashOf(
                &m->basic.proxy_reject_announcement_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1289: /* module 5 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V2 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V2 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->basic.proxy_proxy_announced_V2.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V2 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_set_balance_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V2 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V2.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V2 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V2.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_unreserve_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V2 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* currencies_transfer_native_currency_V2 - dest */;
            return _toStringLookupasStaticLookupSource(
                &m->nested.currencies_transfer_native_currency_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* currencies_transfer_native_currency_V2 - amount */;
            return _toStringCompactu128(
                &m->nested.currencies_transfer_native_currency_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* currencies_update_balance_V2 - who */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.currencies_update_balance_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* currencies_update_balance_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.currencies_update_balance_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* currencies_update_balance_V2 - amount */;
            return _toStringAmount(
                &m->basic.currencies_update_balance_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0: /* currencies_sweep_dust_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.currencies_sweep_dust_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* currencies_sweep_dust_V2 - accounts */;
            return _toStringVecAccountId(
                &m->basic.currencies_sweep_dust_V2.accounts,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* transactionpayment_set_alternative_fee_swap_path_V2 - fee_swap_path */;
            return _toStringOptionVecCurrencyId(
                &m->basic.transactionpayment_set_alternative_fee_swap_path_V2.fee_swap_path,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* transactionpayment_disable_charge_fee_pool_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.transactionpayment_disable_charge_fee_pool_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* transactionpayment_with_fee_path_V2 - fee_swap_path */;
            return _toStringVecCurrencyId(
                &m->basic.transactionpayment_with_fee_path_V2.fee_swap_path,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* transactionpayment_with_fee_path_V2 - call */;
            return _toStringCall(
                &m->basic.transactionpayment_with_fee_path_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* transactionpayment_with_fee_currency_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.transactionpayment_with_fee_currency_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* transactionpayment_with_fee_currency_V2 - call */;
            return _toStringCall(
                &m->basic.transactionpayment_with_fee_currency_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0: /* transactionpayment_with_fee_paid_by_V2 - call */;
            return _toStringCall(
                &m->basic.transactionpayment_with_fee_paid_by_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* transactionpayment_with_fee_paid_by_V2 - payer_addr */;
            return _toStringAccountId(
                &m->basic.transactionpayment_with_fee_paid_by_V2.payer_addr,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* transactionpayment_with_fee_paid_by_V2 - payer_sig */;
            return _toStringMultiSignature(
                &m->basic.transactionpayment_with_fee_paid_by_V2.payer_sig,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        case 0: /* transactionpayment_with_fee_aggregated_path_V2 - fee_aggregated_path */;
            return _toStringVecSwapPath(
                &m->basic.transactionpayment_with_fee_aggregated_path_V2.fee_aggregated_path,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* transactionpayment_with_fee_aggregated_path_V2 - call */;
            return _toStringCall(
                &m->basic.transactionpayment_with_fee_aggregated_path_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_bounty_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_bounty_V2 - description */;
            return _toStringBytes(
                &m->basic.bounties_propose_bounty_V2.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_approve_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_propose_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V2 - curator */;
            return _toStringAccountIdLookupOfT(
                &m->basic.bounties_propose_curator_V2.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V2 - fee */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_curator_V2.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_unassign_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_accept_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_award_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V2 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.bounties_award_bounty_V2.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_claim_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5383: /* module 21 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_close_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5384: /* module 21 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_extend_bounty_expiry_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V2 - remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_invulnerables_V2 - new_ */;
            return _toStringVecAccountId(
                &m->basic.collatorselection_set_invulnerables_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_desired_candidates_V2 - max */;
            return _toStringCompactu32(
                &m->basic.collatorselection_set_desired_candidates_V2.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_candidacy_bond_V2 - bond */;
            return _toStringCompactu128(
                &m->basic.collatorselection_set_candidacy_bond_V2.bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10500: /* module 41 call 4 */
        switch (itemIdx) {
        case 0: /* collatorselection_register_candidate_V2 - new_candidate */;
            return _toStringAccountId(
                &m->basic.collatorselection_register_candidate_V2.new_candidate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10501: /* module 41 call 5 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10502: /* module 41 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_service_overweight_V2 - index */;
            return _toStringOverweightIndex(
                &m->basic.xcmpqueue_service_overweight_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpqueue_service_overweight_V2 - weight_limit */;
            return _toStringXcmWeight(
                &m->basic.xcmpqueue_service_overweight_V2.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_suspend_threshold_V2 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_suspend_threshold_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_drop_threshold_V2 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_drop_threshold_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12805: /* module 50 call 5 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_resume_threshold_V2 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_resume_threshold_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12806: /* module 50 call 6 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_threshold_weight_V2 - new_ */;
            return _toStringXcmWeight(
                &m->basic.xcmpqueue_update_threshold_weight_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12807: /* module 50 call 7 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_weight_restrict_decay_V2 - new_ */;
            return _toStringXcmWeight(
                &m->basic.xcmpqueue_update_weight_restrict_decay_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12808: /* module 50 call 8 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_xcmp_max_individual_weight_V2 - new_ */;
            return _toStringXcmWeight(
                &m->basic.xcmpqueue_update_xcmp_max_individual_weight_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17664: /* module 69 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V2 - proposal */;
            return _toStringBoundedCallOfT(
                &m->basic.democracy_propose_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.democracy_propose_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17665: /* module 69 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V2 - proposal */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17667: /* module 69 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V2 - ref_index */;
            return _toStringReferendumIndex(
                &m->basic.democracy_emergency_cancel_V2.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17668: /* module 69 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V2 - proposal */;
            return _toStringBoundedCallOfT(
                &m->basic.democracy_external_propose_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17669: /* module 69 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V2 - proposal */;
            return _toStringBoundedCallOfT(
                &m->basic.democracy_external_propose_majority_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17670: /* module 69 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V2 - proposal */;
            return _toStringBoundedCallOfT(
                &m->basic.democracy_external_propose_default_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17671: /* module 69 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V2 - proposal_hash */;
            return _toStringH256(
                &m->basic.democracy_fast_track_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V2 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V2.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V2 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17672: /* module 69 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V2 - proposal_hash */;
            return _toStringH256(
                &m->basic.democracy_veto_external_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17673: /* module 69 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V2 - ref_index */;
            return _toStringCompactu32(
                &m->basic.democracy_cancel_referendum_V2.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17675: /* module 69 call 11 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 17676: /* module 69 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 17677: /* module 69 call 13 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V2 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.democracy_unlock_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 17681: /* module 69 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V2 - prop_index */;
            return _toStringCompactu32(
                &m->basic.democracy_cancel_proposal_V2.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23296: /* module 91 call 0 */
        switch (itemIdx) {
        case 0: /* dex_swap_with_exact_supply_V2 - path */;
            return _toStringVecCurrencyId(
                &m->nested.dex_swap_with_exact_supply_V2.path,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_swap_with_exact_supply_V2 - supply_amount */;
            return _toStringCompactu128(
                &m->nested.dex_swap_with_exact_supply_V2.supply_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* dex_swap_with_exact_supply_V2 - min_target_amount */;
            return _toStringCompactu128(
                &m->nested.dex_swap_with_exact_supply_V2.min_target_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23297: /* module 91 call 1 */
        switch (itemIdx) {
        case 0: /* dex_swap_with_exact_target_V2 - path */;
            return _toStringVecCurrencyId(
                &m->basic.dex_swap_with_exact_target_V2.path,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_swap_with_exact_target_V2 - target_amount */;
            return _toStringCompactu128(
                &m->basic.dex_swap_with_exact_target_V2.target_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* dex_swap_with_exact_target_V2 - max_supply_amount */;
            return _toStringCompactu128(
                &m->basic.dex_swap_with_exact_target_V2.max_supply_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23298: /* module 91 call 2 */
        switch (itemIdx) {
        case 0: /* dex_add_liquidity_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->nested.dex_add_liquidity_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_add_liquidity_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->nested.dex_add_liquidity_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* dex_add_liquidity_V2 - max_amount_a */;
            return _toStringCompactu128(
                &m->nested.dex_add_liquidity_V2.max_amount_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* dex_add_liquidity_V2 - max_amount_b */;
            return _toStringCompactu128(
                &m->nested.dex_add_liquidity_V2.max_amount_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* dex_add_liquidity_V2 - min_share_increment */;
            return _toStringCompactu128(
                &m->nested.dex_add_liquidity_V2.min_share_increment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* dex_add_liquidity_V2 - stake_increment_share */;
            return _toStringbool(
                &m->nested.dex_add_liquidity_V2.stake_increment_share,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23299: /* module 91 call 3 */
        switch (itemIdx) {
        case 0: /* dex_add_provision_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->basic.dex_add_provision_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_add_provision_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->basic.dex_add_provision_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* dex_add_provision_V2 - amount_a */;
            return _toStringCompactu128(
                &m->basic.dex_add_provision_V2.amount_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* dex_add_provision_V2 - amount_b */;
            return _toStringCompactu128(
                &m->basic.dex_add_provision_V2.amount_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23300: /* module 91 call 4 */
        switch (itemIdx) {
        case 0: /* dex_claim_dex_share_V2 - owner */;
            return _toStringAccountId(
                &m->basic.dex_claim_dex_share_V2.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_claim_dex_share_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->basic.dex_claim_dex_share_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* dex_claim_dex_share_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->basic.dex_claim_dex_share_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23301: /* module 91 call 5 */
        switch (itemIdx) {
        case 0: /* dex_remove_liquidity_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->nested.dex_remove_liquidity_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_remove_liquidity_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->nested.dex_remove_liquidity_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* dex_remove_liquidity_V2 - remove_share */;
            return _toStringCompactu128(
                &m->nested.dex_remove_liquidity_V2.remove_share,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* dex_remove_liquidity_V2 - min_withdrawn_a */;
            return _toStringCompactu128(
                &m->nested.dex_remove_liquidity_V2.min_withdrawn_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* dex_remove_liquidity_V2 - min_withdrawn_b */;
            return _toStringCompactu128(
                &m->nested.dex_remove_liquidity_V2.min_withdrawn_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* dex_remove_liquidity_V2 - by_unstake */;
            return _toStringbool(
                &m->nested.dex_remove_liquidity_V2.by_unstake,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23302: /* module 91 call 6 */
        switch (itemIdx) {
        case 0: /* dex_list_provisioning_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->basic.dex_list_provisioning_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_list_provisioning_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->basic.dex_list_provisioning_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* dex_list_provisioning_V2 - min_contribution_a */;
            return _toStringCompactu128(
                &m->basic.dex_list_provisioning_V2.min_contribution_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* dex_list_provisioning_V2 - min_contribution_b */;
            return _toStringCompactu128(
                &m->basic.dex_list_provisioning_V2.min_contribution_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* dex_list_provisioning_V2 - target_provision_a */;
            return _toStringCompactu128(
                &m->basic.dex_list_provisioning_V2.target_provision_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* dex_list_provisioning_V2 - target_provision_b */;
            return _toStringCompactu128(
                &m->basic.dex_list_provisioning_V2.target_provision_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* dex_list_provisioning_V2 - not_before */;
            return _toStringCompactu32(
                &m->basic.dex_list_provisioning_V2.not_before,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23303: /* module 91 call 7 */
        switch (itemIdx) {
        case 0: /* dex_update_provisioning_parameters_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->basic.dex_update_provisioning_parameters_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_update_provisioning_parameters_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->basic.dex_update_provisioning_parameters_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* dex_update_provisioning_parameters_V2 - min_contribution_a */;
            return _toStringCompactu128(
                &m->basic.dex_update_provisioning_parameters_V2.min_contribution_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* dex_update_provisioning_parameters_V2 - min_contribution_b */;
            return _toStringCompactu128(
                &m->basic.dex_update_provisioning_parameters_V2.min_contribution_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* dex_update_provisioning_parameters_V2 - target_provision_a */;
            return _toStringCompactu128(
                &m->basic.dex_update_provisioning_parameters_V2.target_provision_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* dex_update_provisioning_parameters_V2 - target_provision_b */;
            return _toStringCompactu128(
                &m->basic.dex_update_provisioning_parameters_V2.target_provision_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* dex_update_provisioning_parameters_V2 - not_before */;
            return _toStringCompactu32(
                &m->basic.dex_update_provisioning_parameters_V2.not_before,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23304: /* module 91 call 8 */
        switch (itemIdx) {
        case 0: /* dex_end_provisioning_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->basic.dex_end_provisioning_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_end_provisioning_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->basic.dex_end_provisioning_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23305: /* module 91 call 9 */
        switch (itemIdx) {
        case 0: /* dex_enable_trading_pair_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->basic.dex_enable_trading_pair_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_enable_trading_pair_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->basic.dex_enable_trading_pair_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23306: /* module 91 call 10 */
        switch (itemIdx) {
        case 0: /* dex_disable_trading_pair_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->basic.dex_disable_trading_pair_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_disable_trading_pair_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->basic.dex_disable_trading_pair_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23307: /* module 91 call 11 */
        switch (itemIdx) {
        case 0: /* dex_refund_provision_V2 - owner */;
            return _toStringAccountId(
                &m->basic.dex_refund_provision_V2.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_refund_provision_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->basic.dex_refund_provision_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* dex_refund_provision_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->basic.dex_refund_provision_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23308: /* module 91 call 12 */
        switch (itemIdx) {
        case 0: /* dex_abort_provisioning_V2 - currency_id_a */;
            return _toStringCurrencyId(
                &m->basic.dex_abort_provisioning_V2.currency_id_a,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dex_abort_provisioning_V2 - currency_id_b */;
            return _toStringCurrencyId(
                &m->basic.dex_abort_provisioning_V2.currency_id_b,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23808: /* module 93 call 0 */
        switch (itemIdx) {
        case 0: /* aggregateddex_swap_with_exact_supply_V2 - paths */;
            return _toStringVecSwapPath(
                &m->nested.aggregateddex_swap_with_exact_supply_V2.paths,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* aggregateddex_swap_with_exact_supply_V2 - supply_amount */;
            return _toStringCompactBalance(
                &m->nested.aggregateddex_swap_with_exact_supply_V2.supply_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* aggregateddex_swap_with_exact_supply_V2 - min_target_amount */;
            return _toStringCompactBalance(
                &m->nested.aggregateddex_swap_with_exact_supply_V2.min_target_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23809: /* module 93 call 1 */
        switch (itemIdx) {
        case 0: /* aggregateddex_swap_with_exact_target_V2 - paths */;
            return _toStringVecSwapPath(
                &m->nested.aggregateddex_swap_with_exact_target_V2.paths,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* aggregateddex_swap_with_exact_target_V2 - target_amount */;
            return _toStringCompactBalance(
                &m->nested.aggregateddex_swap_with_exact_target_V2.target_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* aggregateddex_swap_with_exact_target_V2 - max_supply_amount */;
            return _toStringCompactBalance(
                &m->nested.aggregateddex_swap_with_exact_target_V2.max_supply_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 23810: /* module 93 call 2 */
        switch (itemIdx) {
        case 0: /* aggregateddex_update_aggregated_swap_paths_V2 - updates */;
            return _toStringVecTupleCurrencyIdCurrencyIdOptionVecSwapPath(
                &m->nested.aggregateddex_update_aggregated_swap_paths_V2.updates,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26112: /* module 102 call 0 */
        switch (itemIdx) {
        case 0: /* honzon_adjust_loan_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->nested.honzon_adjust_loan_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* honzon_adjust_loan_V2 - collateral_adjustment */;
            return _toStringAmount(
                &m->nested.honzon_adjust_loan_V2.collateral_adjustment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* honzon_adjust_loan_V2 - debit_adjustment */;
            return _toStringAmount(
                &m->nested.honzon_adjust_loan_V2.debit_adjustment,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26113: /* module 102 call 1 */
        switch (itemIdx) {
        case 0: /* honzon_close_loan_has_debit_by_dex_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.honzon_close_loan_has_debit_by_dex_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* honzon_close_loan_has_debit_by_dex_V2 - max_collateral_amount */;
            return _toStringCompactu128(
                &m->basic.honzon_close_loan_has_debit_by_dex_V2.max_collateral_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26114: /* module 102 call 2 */
        switch (itemIdx) {
        case 0: /* honzon_transfer_loan_from_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.honzon_transfer_loan_from_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* honzon_transfer_loan_from_V2 - from */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.honzon_transfer_loan_from_V2.from,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26115: /* module 102 call 3 */
        switch (itemIdx) {
        case 0: /* honzon_authorize_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.honzon_authorize_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* honzon_authorize_V2 - to */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.honzon_authorize_V2.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26116: /* module 102 call 4 */
        switch (itemIdx) {
        case 0: /* honzon_unauthorize_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.honzon_unauthorize_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* honzon_unauthorize_V2 - to */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.honzon_unauthorize_V2.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26117: /* module 102 call 5 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 26118: /* module 102 call 6 */
        switch (itemIdx) {
        case 0: /* honzon_expand_position_collateral_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.honzon_expand_position_collateral_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* honzon_expand_position_collateral_V2 - increase_debit_value */;
            return _toStringBalance(
                &m->basic.honzon_expand_position_collateral_V2.increase_debit_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* honzon_expand_position_collateral_V2 - min_increase_collateral */;
            return _toStringBalance(
                &m->basic.honzon_expand_position_collateral_V2.min_increase_collateral,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26119: /* module 102 call 7 */
        switch (itemIdx) {
        case 0: /* honzon_shrink_position_debit_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.honzon_shrink_position_debit_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* honzon_shrink_position_debit_V2 - decrease_collateral */;
            return _toStringBalance(
                &m->basic.honzon_shrink_position_debit_V2.decrease_collateral,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* honzon_shrink_position_debit_V2 - min_decrease_debit_value */;
            return _toStringBalance(
                &m->basic.honzon_shrink_position_debit_V2.min_decrease_debit_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26120: /* module 102 call 8 */
        switch (itemIdx) {
        case 0: /* honzon_adjust_loan_by_debit_value_V2 - currency_id */;
            return _toStringCurrencyId(
                &m->basic.honzon_adjust_loan_by_debit_value_V2.currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* honzon_adjust_loan_by_debit_value_V2 - collateral_adjustment */;
            return _toStringAmount(
                &m->basic.honzon_adjust_loan_by_debit_value_V2.collateral_adjustment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* honzon_adjust_loan_by_debit_value_V2 - debit_value_adjustment */;
            return _toStringAmount(
                &m->basic.honzon_adjust_loan_by_debit_value_V2.debit_value_adjustment,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 26121: /* module 102 call 9 */
        switch (itemIdx) {
        case 0: /* honzon_transfer_debit_V2 - from_currency */;
            return _toStringCurrencyId(
                &m->basic.honzon_transfer_debit_V2.from_currency,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* honzon_transfer_debit_V2 - to_currency */;
            return _toStringCurrencyId(
                &m->basic.honzon_transfer_debit_V2.to_currency,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* honzon_transfer_debit_V2 - debit_transfer */;
            return _toStringBalance(
                &m->basic.honzon_transfer_debit_V2.debit_transfer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 29696: /* module 116 call 0 */
        switch (itemIdx) {
        case 0: /* homa_mint_V2 - amount */;
            return _toStringCompactu128(
                &m->nested.homa_mint_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 29697: /* module 116 call 1 */
        switch (itemIdx) {
        case 0: /* homa_request_redeem_V2 - amount */;
            return _toStringCompactu128(
                &m->nested.homa_request_redeem_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* homa_request_redeem_V2 - allow_fast_match */;
            return _toStringbool(
                &m->nested.homa_request_redeem_V2.allow_fast_match,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 29698: /* module 116 call 2 */
        switch (itemIdx) {
        case 0: /* homa_fast_match_redeems_V2 - redeemer_list */;
            return _toStringVecAccountId(
                &m->nested.homa_fast_match_redeems_V2.redeemer_list,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 29699: /* module 116 call 3 */
        switch (itemIdx) {
        case 0: /* homa_claim_redemption_V2 - redeemer */;
            return _toStringAccountId(
                &m->basic.homa_claim_redemption_V2.redeemer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 29703: /* module 116 call 7 */
        switch (itemIdx) {
        case 0: /* homa_reset_current_era_V2 - era_index */;
            return _toStringEraIndex(
                &m->basic.homa_reset_current_era_V2.era_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 29704: /* module 116 call 8 */
        switch (itemIdx) {
        case 0: /* homa_force_bump_current_era_V2 - bump_amount */;
            return _toStringEraIndex(
                &m->basic.homa_force_bump_current_era_V2.bump_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 29705: /* module 116 call 9 */
        switch (itemIdx) {
        case 0: /* homa_fast_match_redeems_completely_V2 - redeemer_list */;
            return _toStringVecAccountId(
                &m->nested.homa_fast_match_redeems_completely_V2.redeemer_list,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 30720: /* module 120 call 0 */
        switch (itemIdx) {
        case 0: /* incentives_deposit_dex_share_V2 - lp_currency_id */;
            return _toStringCurrencyId(
                &m->basic.incentives_deposit_dex_share_V2.lp_currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* incentives_deposit_dex_share_V2 - amount */;
            return _toStringCompactu128(
                &m->basic.incentives_deposit_dex_share_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 30721: /* module 120 call 1 */
        switch (itemIdx) {
        case 0: /* incentives_withdraw_dex_share_V2 - lp_currency_id */;
            return _toStringCurrencyId(
                &m->nested.incentives_withdraw_dex_share_V2.lp_currency_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* incentives_withdraw_dex_share_V2 - amount */;
            return _toStringCompactu128(
                &m->nested.incentives_withdraw_dex_share_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 30722: /* module 120 call 2 */
        switch (itemIdx) {
        case 0: /* incentives_claim_rewards_V2 - pool_id */;
            return _toStringPoolId(
                &m->basic.incentives_claim_rewards_V2.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 30978: /* module 121 call 2 */
        switch (itemIdx) {
        case 0: /* nft_transfer_V2 - to */;
            return _toStringLookupasStaticLookupSource(
                &m->basic.nft_transfer_V2.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nft_transfer_V2 - token */;
            return _toStringClassIdOfTTokenIdOfT(
                &m->basic.nft_transfer_V2.token,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33280: /* module 130 call 0 */
        switch (itemIdx) {
        case 0: /* evm_eth_call_V2 - action */;
            return _toStringTransactionAction(
                &m->basic.evm_eth_call_V2.action,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_eth_call_V2 - input */;
            return _toStringVecu8(
                &m->basic.evm_eth_call_V2.input,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* evm_eth_call_V2 - amount */;
            return _toStringCompactu128(
                &m->basic.evm_eth_call_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* evm_eth_call_V2 - gas_limit */;
            return _toStringCompactu64(
                &m->basic.evm_eth_call_V2.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* evm_eth_call_V2 - storage_limit */;
            return _toStringCompactu32(
                &m->basic.evm_eth_call_V2.storage_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* evm_eth_call_V2 - access_list */;
            return _toStringVecAccessListItem(
                &m->basic.evm_eth_call_V2.access_list,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* evm_eth_call_V2 - valid_until */;
            return _toStringCompactu32(
                &m->basic.evm_eth_call_V2.valid_until,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33281: /* module 130 call 1 */
        switch (itemIdx) {
        case 0: /* evm_call_V2 - target */;
            return _toStringEvmAddress(
                &m->basic.evm_call_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_call_V2 - input */;
            return _toStringVecu8(
                &m->basic.evm_call_V2.input,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* evm_call_V2 - amount */;
            return _toStringCompactu128(
                &m->basic.evm_call_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* evm_call_V2 - gas_limit */;
            return _toStringCompactu64(
                &m->basic.evm_call_V2.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* evm_call_V2 - storage_limit */;
            return _toStringCompactu32(
                &m->basic.evm_call_V2.storage_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* evm_call_V2 - access_list */;
            return _toStringVecAccessListItem(
                &m->basic.evm_call_V2.access_list,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33283: /* module 130 call 3 */
        switch (itemIdx) {
        case 0: /* evm_create_V2 - input */;
            return _toStringVecu8(
                &m->basic.evm_create_V2.input,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_create_V2 - amount */;
            return _toStringCompactu128(
                &m->basic.evm_create_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* evm_create_V2 - gas_limit */;
            return _toStringCompactu64(
                &m->basic.evm_create_V2.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* evm_create_V2 - storage_limit */;
            return _toStringCompactu32(
                &m->basic.evm_create_V2.storage_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* evm_create_V2 - access_list */;
            return _toStringVecAccessListItem(
                &m->basic.evm_create_V2.access_list,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33284: /* module 130 call 4 */
        switch (itemIdx) {
        case 0: /* evm_create2_V2 - input */;
            return _toStringVecu8(
                &m->basic.evm_create2_V2.input,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_create2_V2 - salt */;
            return _toStringH256(
                &m->basic.evm_create2_V2.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* evm_create2_V2 - amount */;
            return _toStringCompactu128(
                &m->basic.evm_create2_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* evm_create2_V2 - gas_limit */;
            return _toStringCompactu64(
                &m->basic.evm_create2_V2.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* evm_create2_V2 - storage_limit */;
            return _toStringCompactu32(
                &m->basic.evm_create2_V2.storage_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* evm_create2_V2 - access_list */;
            return _toStringVecAccessListItem(
                &m->basic.evm_create2_V2.access_list,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33287: /* module 130 call 7 */
        switch (itemIdx) {
        case 0: /* evm_transfer_maintainer_V2 - contract */;
            return _toStringEvmAddress(
                &m->basic.evm_transfer_maintainer_V2.contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_transfer_maintainer_V2 - new_maintainer */;
            return _toStringEvmAddress(
                &m->basic.evm_transfer_maintainer_V2.new_maintainer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33288: /* module 130 call 8 */
        switch (itemIdx) {
        case 0: /* evm_publish_contract_V2 - contract */;
            return _toStringEvmAddress(
                &m->basic.evm_publish_contract_V2.contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33289: /* module 130 call 9 */
        switch (itemIdx) {
        case 0: /* evm_publish_free_V2 - contract */;
            return _toStringEvmAddress(
                &m->basic.evm_publish_free_V2.contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33290: /* module 130 call 10 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 33291: /* module 130 call 11 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 33292: /* module 130 call 12 */
        switch (itemIdx) {
        case 0: /* evm_set_code_V2 - contract */;
            return _toStringEvmAddress(
                &m->basic.evm_set_code_V2.contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_set_code_V2 - code */;
            return _toStringVecu8(
                &m->basic.evm_set_code_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33293: /* module 130 call 13 */
        switch (itemIdx) {
        case 0: /* evm_selfdestruct_V2 - contract */;
            return _toStringEvmAddress(
                &m->basic.evm_selfdestruct_V2.contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33792: /* module 132 call 0 */
        switch (itemIdx) {
        case 0: /* evmaccounts_claim_account_V2 - eth_address */;
            return _toStringEvmAddress(
                &m->basic.evmaccounts_claim_account_V2.eth_address,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evmaccounts_claim_account_V2 - eth_signature */;
            return _toStringEip712Signature(
                &m->basic.evmaccounts_claim_account_V2.eth_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 33793: /* module 132 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 51201: /* module 200 call 1 */
        switch (itemIdx) {
        case 0: /* stableasset_mint_V2 - pool_id */;
            return _toStringStableAssetPoolId(
                &m->basic.stableasset_mint_V2.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* stableasset_mint_V2 - amounts */;
            return _toStringVecBalance(
                &m->basic.stableasset_mint_V2.amounts,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* stableasset_mint_V2 - min_mint_amount */;
            return _toStringBalance(
                &m->basic.stableasset_mint_V2.min_mint_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 51202: /* module 200 call 2 */
        switch (itemIdx) {
        case 0: /* stableasset_swap_V2 - pool_id */;
            return _toStringStableAssetPoolId(
                &m->basic.stableasset_swap_V2.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* stableasset_swap_V2 - i */;
            return _toStringPoolTokenIndex(
                &m->basic.stableasset_swap_V2.i,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* stableasset_swap_V2 - j */;
            return _toStringPoolTokenIndex(
                &m->basic.stableasset_swap_V2.j,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* stableasset_swap_V2 - dx */;
            return _toStringBalance(
                &m->basic.stableasset_swap_V2.dx,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* stableasset_swap_V2 - min_dy */;
            return _toStringBalance(
                &m->basic.stableasset_swap_V2.min_dy,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* stableasset_swap_V2 - asset_length */;
            return _toStringu32(
                &m->basic.stableasset_swap_V2.asset_length,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 51203: /* module 200 call 3 */
        switch (itemIdx) {
        case 0: /* stableasset_redeem_proportion_V2 - pool_id */;
            return _toStringStableAssetPoolId(
                &m->basic.stableasset_redeem_proportion_V2.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* stableasset_redeem_proportion_V2 - amount */;
            return _toStringBalance(
                &m->basic.stableasset_redeem_proportion_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* stableasset_redeem_proportion_V2 - min_redeem_amounts */;
            return _toStringVecBalance(
                &m->basic.stableasset_redeem_proportion_V2.min_redeem_amounts,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 51204: /* module 200 call 4 */
        switch (itemIdx) {
        case 0: /* stableasset_redeem_single_V2 - pool_id */;
            return _toStringStableAssetPoolId(
                &m->basic.stableasset_redeem_single_V2.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* stableasset_redeem_single_V2 - amount */;
            return _toStringBalance(
                &m->basic.stableasset_redeem_single_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* stableasset_redeem_single_V2 - i */;
            return _toStringPoolTokenIndex(
                &m->basic.stableasset_redeem_single_V2.i,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* stableasset_redeem_single_V2 - min_redeem_amount */;
            return _toStringBalance(
                &m->basic.stableasset_redeem_single_V2.min_redeem_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* stableasset_redeem_single_V2 - asset_length */;
            return _toStringu32(
                &m->basic.stableasset_redeem_single_V2.asset_length,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 51205: /* module 200 call 5 */
        switch (itemIdx) {
        case 0: /* stableasset_redeem_multi_V2 - pool_id */;
            return _toStringStableAssetPoolId(
                &m->basic.stableasset_redeem_multi_V2.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* stableasset_redeem_multi_V2 - amounts */;
            return _toStringVecBalance(
                &m->basic.stableasset_redeem_multi_V2.amounts,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* stableasset_redeem_multi_V2 - max_redeem_amount */;
            return _toStringBalance(
                &m->basic.stableasset_redeem_multi_V2.max_redeem_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V2(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 768: // Utility:Batch
    case 770: // Utility:Batch all
    case 772: // Utility:Force batch
    case 1283: // Proxy:Remove proxies
    case 1284: // Proxy:Create pure
    case 1285: // Proxy:Kill pure
    case 1286: // Proxy:Announce
    case 1287: // Proxy:Remove announcement
    case 1288: // Proxy:Reject announcement
    case 1289: // Proxy:Proxy announced
    case 2564: // Balances:Transfer all
    case 2565: // Balances:Force unreserve
    case 3074: // Currencies:Update balance
    case 3075: // Currencies:Sweep dust
    case 3328: // Vesting:Claim
    case 3584: // TransactionPayment:Set alternative fee swap path
    case 3586: // TransactionPayment:Disable charge fee pool
    case 3587: // TransactionPayment:With fee path
    case 3588: // TransactionPayment:With fee currency
    case 3589: // TransactionPayment:With fee paid by
    case 3590: // TransactionPayment:With fee aggregated path
    case 5376: // Bounties:Propose bounty
    case 5377: // Bounties:Approve bounty
    case 5378: // Bounties:Propose curator
    case 5379: // Bounties:Unassign curator
    case 5380: // Bounties:Accept curator
    case 5381: // Bounties:Award bounty
    case 5382: // Bounties:Claim bounty
    case 5383: // Bounties:Close bounty
    case 5384: // Bounties:Extend bounty expiry
    case 10496: // CollatorSelection:Set invulnerables
    case 10497: // CollatorSelection:Set desired candidates
    case 10498: // CollatorSelection:Set candidacy bond
    case 10499: // CollatorSelection:Register as candidate
    case 10500: // CollatorSelection:Register candidate
    case 10501: // CollatorSelection:Leave intent
    case 10502: // CollatorSelection:Withdraw bond
    case 10752: // Session:Set keys
    case 10753: // Session:Purge keys
    case 12800: // XcmpQueue:Service overweight
    case 12801: // XcmpQueue:Suspend xcm execution
    case 12802: // XcmpQueue:Resume xcm execution
    case 12803: // XcmpQueue:Update suspend threshold
    case 12804: // XcmpQueue:Update drop threshold
    case 12805: // XcmpQueue:Update resume threshold
    case 12806: // XcmpQueue:Update threshold weight
    case 12807: // XcmpQueue:Update weight restrict decay
    case 12808: // XcmpQueue:Update xcmp max individual weight
    case 13824: // XTokens:Transfer
    case 17664: // Democracy:Propose
    case 17665: // Democracy:Second
    case 17667: // Democracy:Emergency cancel
    case 17668: // Democracy:External propose
    case 17669: // Democracy:External propose majority
    case 17670: // Democracy:External propose default
    case 17671: // Democracy:Fast track
    case 17672: // Democracy:Veto external
    case 17673: // Democracy:Cancel referendum
    case 17675: // Democracy:Undelegate
    case 17676: // Democracy:Clear public proposals
    case 17677: // Democracy:Unlock
    case 17681: // Democracy:Cancel proposal
    case 23297: // Dex:Swap with exact target
    case 23299: // Dex:Add provision
    case 23300: // Dex:Claim dex share
    case 23302: // Dex:List provisioning
    case 23303: // Dex:Update provisioning parameters
    case 23304: // Dex:End provisioning
    case 23305: // Dex:Enable trading pair
    case 23306: // Dex:Disable trading pair
    case 23307: // Dex:Refund provision
    case 23308: // Dex:Abort provisioning
    case 26113: // Honzon:Close loan has debit by dex
    case 26114: // Honzon:Transfer loan from
    case 26115: // Honzon:Authorize
    case 26116: // Honzon:Unauthorize
    case 26117: // Honzon:Unauthorize all
    case 26118: // Honzon:Expand position collateral
    case 26119: // Honzon:Shrink position debit
    case 26120: // Honzon:Adjust loan by debit value
    case 26121: // Honzon:Transfer debit
    case 29699: // Homa:Claim redemption
    case 29703: // Homa:Reset current era
    case 29704: // Homa:Force bump current era
    case 30720: // Incentives:Deposit dex share
    case 30722: // Incentives:Claim rewards
    case 30978: // NFT:Transfer
    case 33280: // EVM:Eth call
    case 33281: // EVM:Call
    case 33283: // EVM:Create
    case 33284: // EVM:Create2
    case 33287: // EVM:Transfer maintainer
    case 33288: // EVM:Publish contract
    case 33289: // EVM:Publish free
    case 33290: // EVM:Enable contract development
    case 33291: // EVM:Disable contract development
    case 33292: // EVM:Set code
    case 33293: // EVM:Selfdestruct
    case 33792: // EvmAccounts:Claim account
    case 33793: // EvmAccounts:Claim default account
    case 51201: // StableAsset:Mint
    case 51202: // StableAsset:Swap
    case 51203: // StableAsset:Redeem proportion
    case 51204: // StableAsset:Redeem single
    case 51205: // StableAsset:Redeem multi
        return false;
    default:
        return true;
    }
}
