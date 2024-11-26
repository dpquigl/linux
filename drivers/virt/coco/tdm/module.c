#include <linux/module.h>
#include <linux/printk.h>

#include "tdm-netlink.h"

static int __init tdm_init(void)
{
	int ret = 0;

	ret = genl_register_family(&tdm_nl_family);
	if (ret) {
		pr_err("Failed to register " TDM_GENL_FAMILY_NAME "\n");
	} else {
		pr_info("Successfully registered " TDM_GENL_FAMILY_NAME "\n");
	}

	return 0;
}

static void __exit tdm_exit(void)
{
	int ret = 0;

	ret = genl_unregister_family(&tdm_nl_family);
	if (ret) {
		pr_warn("Failed to unregister " TDM_GENL_FAMILY_NAME " netlink family\n");
	} else {
		pr_info("Unregistered " TDM_GENL_FAMILY_NAME " netlink family\n");
	}
}

module_init(tdm_init);
module_exit(tdm_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("David Quigley <david.quigley@intel.com>");
MODULE_DESCRIPTION("TDM Netlink Family Driver");
