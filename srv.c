#include <sys/types.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <stdlib.h>
#include <err.h>
#include <event.h>
#include <evhttp.h>
void generic_handler(struct evhttp_request *req, void *arg)
{
 struct evbuffer *buf;
	struct evkeyvalq *input_headers;
        struct evkeyval *header;
	buf = evbuffer_new();
	if (buf == NULL)
		err(1, "failed to create response buffer");
	input_headers = req->input_headers;

        TAILQ_FOREACH(header, input_headers, next) {
			FILE* fp=fopen("/txt/txt.txt","a+");
			printf("%s :", header->key );
			printf("%s \n", header->value );
			fprintf(fp,header->key);
			//fprintf(fp,"\n");
			fprintf(fp,header->value);
			fprintf(fp,"\n");

			fclose(fp);
        }
	evbuffer_add_printf(buf, "Requested: %s\n", evhttp_request_uri(req));
	evhttp_send_reply(req, HTTP_OK, "OK", buf);
}
int main(int argc, char **argv)
{
	struct evhttp *httpd;
	event_init();
	httpd = evhttp_start("0.0.0.0", 8080);
	/* Set a callback for requests to "/specific". */
	/* evhttp_set_cb(httpd, "/specific", another_handler, NULL); */
	/* Set a callback for all other requests. */
	evhttp_set_gencb(httpd, generic_handler, NULL);
	event_dispatch();    /* Not reached in this code as it is now. */
	evhttp_free(httpd);    return 0;
}
