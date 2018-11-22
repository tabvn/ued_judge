//
// Created by Toan on 11/22/18.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <libwebsockets.h>
#include <string.h>
#include <signal.h>
#include <functional>


static int interrupted;

namespace Ued {


    struct Server {

        struct lws_http_mount config = {
                /* .mount_next */        NULL,        /* linked-list "next" */
                /* .mountpoint */        "/",        /* mountpoint URL */
                /* .origin */            ".public", /* serve from dir */
                /* .def */            "index.html",    /* default filename */
                /* .protocol */            NULL,
                /* .cgienv */            NULL,
                /* .extra_mimetypes */        NULL,
                /* .interpret */        NULL,
                /* .cgi_timeout */        0,
                /* .cache_max_age */        0,
                /* .auth_mask */        0,
                /* .cache_reusable */        0,
                /* .cache_revalidate */        0,
                /* .cache_intermediaries */    0,
                /* .origin_protocol */        LWSMPRO_FILE,    /* files in a dir */
                /* .mountpoint_len */        1,        /* char count */
                /* .basic_auth_login_file */    NULL,
        };

        int logs = LLL_USER | LLL_ERR | LLL_WARN | LLL_NOTICE;

        void start(int port) {

            struct lws_context_creation_info info;
            struct lws_context *context;
            const char *p;
            int n = 0;
            signal(SIGINT, [](int signal) {
                interrupted = 1;
            });

            lws_set_log_level(this->logs, NULL);
            lwsl_user("Server started http://localhost:%d\n", port);

            memset(&info, 0, sizeof info);
            info.port = port;
            info.mounts = &config;
            info.error_document_404 = "/404.html";
            info.options =
                    LWS_SERVER_OPTION_HTTP_HEADERS_SECURITY_BEST_PRACTICES_ENFORCE;

            context = lws_create_context(&info);


            if (!context) {
                lwsl_err("lws init failed\n");
                return;
            }
            while (n >= 0 && !interrupted)
                n = lws_service(context, 1000);

            lws_context_destroy(context);
        }


    };
}


#endif //SERVER_SERVER_H
