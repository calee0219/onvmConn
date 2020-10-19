#include <stdio.h>
#include "_cgo_export.h"

#define NF_TAG "goConn"
#define SERVICE_ID_DIGIT 10

//typedef int GoInt;
//extern int Handler(struct rte_mbuf*, struct onvm_pkt_meta*, struct onvm_nf_local_ctx*);

struct onvm_nf_local_ctx * nf_local_ctx_all;

static void __attribute__ ((constructor)) init(void) {
    int arg_offset;
    struct onvm_nf_function_table *nf_function_table;

    nf_local_ctx_all = onvm_nflib_init_nf_local_ctx();
    onvm_nflib_start_signal_handler(nf_local_ctx_all, NULL);

    nf_function_table = onvm_nflib_init_nf_function_table();
    nf_function_table->pkt_handler = &Handler;

    char * cmd[] = {"/home/ubuntu/openNetVM/examples/goConn/build/app/goConn", "-F", "/home/ubuntu/openNetVM/examples/goConn/onvmNet/onvmConfig.json", NULL};
    if ((arg_offset = onvm_nflib_init(3, cmd, NF_TAG, nf_local_ctx_all, nf_function_table)) < 0) {
            onvm_nflib_stop(nf_local_ctx_all);
            if (arg_offset == ONVM_SIGNAL_TERMINATION) {
                    printf("Exiting due to user termination\n");
                    return;
            } else {
                    rte_exit(EXIT_FAILURE, "Failed ONVM init\n");
            }
    }
}

int onvm_init(struct onvm_nf_local_ctx * nf_local_ctx, char * onvm_config_path) {
  /*
    int arg_offset;
    struct onvm_nf_function_table *nf_function_table;

    nf_local_ctx = onvm_nflib_init_nf_local_ctx();
    onvm_nflib_start_signal_handler(nf_local_ctx, NULL);

    nf_function_table = onvm_nflib_init_nf_function_table();
    nf_function_table->pkt_handler = &Handler;

    char * cmd[3] = {"./goConn", "-F", onvm_config_path};
    if ((arg_offset = onvm_nflib_init(3, cmd, NF_TAG, nf_local_ctx, nf_function_table)) < 0) {
            onvm_nflib_stop(nf_local_ctx);
            if (arg_offset == ONVM_SIGNAL_TERMINATION) {
                    printf("Exiting due to user termination\n");
                    return 0;
            } else {
                    rte_exit(EXIT_FAILURE, "Failed ONVM init\n");
            }
    }

    */
    return 0;
}

int onvm_terminate() {
    onvm_nflib_stop(nf_local_ctx_all);

    return 0;
}

void onvm_send_pkt(char * buff, int service_id, struct onvm_nf_local_ctx * ctx) {
}

