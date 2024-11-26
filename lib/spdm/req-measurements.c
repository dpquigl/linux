#include "spdm.h"

#include <linux/dev_printk.h>
#include <linux/slab.h>

/* Currently Only supports SPDM 1.2 */
int spdm_get_measurements(struct spdm_state *spdm_state,
				spdm_get_measurements_rsp **response,
				u8 slot, u8 index, bool sign, bool fresh)
{
	struct spdm_get_measurements_rsp *rsp;
	struct spdm_get_measurements_req req = {
		.code = SPDM_GET_MEASUREMENTS,
		.param1 = 0,
		.param2 = index,
		// slot_id_param will be filled in later
		.context = 0
	};
	size_t rsp_sz;
	int rc, length;

	
	// Ensure slot is in a valid range
	if (slot >= SPDM_SLOTS && slot != 0xF)
		return -EINVAL;
	req.slot_id_param = slot;

	// Build param1 based on arguments
	if (sign)
		req.param1 |= SPDM_MEAS_SIGNATURE;
	if (fresh)
		req.param1 |= SPDM_MEAS_NEW_MEASUREMENT;

	//TODO: Check if device supports measurements to begin with
	//TODO: Check if device only supports measurements with no sig but request wants a sig
		
	req_sz = sizeof(req);

	// TODO: Add Large Chunk support later
	rsp_sz = spdm_state->transport_sz;

	/* Calls to GET_MEASUREMENTS clear the M1 and M2 transcript */
	spdm_free_transcript(spdm_state);

	rsp = kvmalloc(rsp_sz, GFP_KERNEL);
	if (!rsp)
		return -ENOMEM;
	
	rc = spdm_exchange(spdm_state, &req, req_sz, rsp, rsp_sz);
	if (rc < 0) {
		kvfree(rsp)		
		return rc;
	}

	*response = rsp;
	return length;
}
