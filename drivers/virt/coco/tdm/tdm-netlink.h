/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-3-Clause) */
/* Do not edit directly, auto-generated from: */
/*	Documentation/netlink/specs/tdm.yaml */
/* YNL-GEN kernel header */

#ifndef _LINUX_TDM_GEN_H
#define _LINUX_TDM_GEN_H

#include <net/netlink.h>
#include <net/genetlink.h>

#include <uapi/linux/tdm.h>

int tdm_nl_get_measurement_doit(struct sk_buff *skb, struct genl_info *info);
int tdm_nl_get_vca_doit(struct sk_buff *skb, struct genl_info *info);

extern struct genl_family tdm_nl_family;

#endif /* _LINUX_TDM_GEN_H */
