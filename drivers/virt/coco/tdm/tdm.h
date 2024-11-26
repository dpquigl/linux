#ifndef __TDM_H
#define __TDM_H

enum {
	TDM_GENL_ATTR_UNSPEC,
	TDM_GENL_ATTR_DEVICE, /* Device that we want to attest */
	TDM_GENL_ATTR_ATTEST_RESULT,
	TDM_GENL_ATTR_ATTEST_SEQNUM,
	__TDM_GENL_ATTR_MAX,
};
#define TDM_GENL_ATTR_MAX (__TDM_GENL_ATTR_MAX - 1)
#define TDM_GENL_ATTR_LEN (__TDM_GENL_ATTR_MAX)
enum {
	TDM_GENL_CMD_UNSPEC,
	TDM_GENL_CMD_ATTEST, /* kernel -> TDM notification for attestation request */
	TDM_GENL_CMD_ATTEST_RESULT, /* TDM -> kernel response message for attestation request */
	TDM_GENL_CMD_TEST_ATTEST, /* Userpace -> kernel trigger to test attestastion request */
	__TDM_GENL_CMD_MAX,
};
#define TDM_GENL_CMD_MAX (__TDM_GENL_CMD_MAX - 1)

#define TDM_GENL_FAMILY_NAME "tdm"
#define TDM_GENL_VERSION 0x01
#define TDM_GENL_MCAST_GROUP_NAME "tdm_mc_group"

#define DEVID_LEN_W_NULL 15
#define DEVID_LEN (DEVID_LEN_W_NULL - 1)

struct tdm_genl_measurement_result {
	char *measurement_record; /* Attestation token */
	uint32_t *measurement_record_length;
	char *opaque_data;
	uint16_t *opaque_data_length;
	char *requester_context;
	char *signature;
	
};

int tdm_genetlink_init(void);
void tdm_genetlink_exit(void);
int tdm_send_attest(const char*);
#endif /* __TDM_H */
