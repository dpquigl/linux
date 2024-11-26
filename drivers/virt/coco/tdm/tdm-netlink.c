// SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-3-Clause)
/* Do not edit directly, auto-generated from: */
/*	Documentation/netlink/specs/tdm.yaml */
/* YNL-GEN kernel source */

#include <net/netlink.h>
#include <net/genetlink.h>

#include "tdm-netlink.h"

#include <uapi/linux/tdm.h>

/* TDM_CMD_GET_MEASUREMENT - do */
static const struct nla_policy tdm_get_measurement_nl_policy[TDM_A_MEASUREMENT_DEVICE + 1] = {
	[TDM_A_MEASUREMENT_OPERATION] = { .type = NLA_U8, },
	[TDM_A_MEASUREMENT_ATTRIBUTES] = NLA_POLICY_MASK(NLA_U8, 0x7),
	[TDM_A_MEASUREMENT_DEVICE] = { .type = NLA_NUL_STRING, },
};

/* Ops table for tdm */
static const struct genl_split_ops tdm_nl_ops[] = {
	{
		.cmd		= TDM_CMD_GET_MEASUREMENT,
		.doit		= tdm_nl_get_measurement_doit,
		.policy		= tdm_get_measurement_nl_policy,
		.maxattr	= TDM_A_MEASUREMENT_DEVICE,
		.flags		= GENL_CMD_CAP_DO,
	},
	{
		.cmd	= TDM_CMD_GET_VCA,
		.doit	= tdm_nl_get_vca_doit,
		.flags	= GENL_CMD_CAP_DO,
	},
};

struct genl_family tdm_nl_family __ro_after_init = {
	.name		= TDM_FAMILY_NAME,
	.version	= TDM_FAMILY_VERSION,
	.netnsok	= true,
	.parallel_ops	= true,
	.module		= THIS_MODULE,
	.split_ops	= tdm_nl_ops,
	.n_split_ops	= ARRAY_SIZE(tdm_nl_ops),
};
