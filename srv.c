/*
#include <sys/types.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <stdio.h>
#include <stdlib.h>
#include <event.h>
#include <evhttp.h>

void generic_handler(struct evhttp_request *req, void *arg)
{
	struct evbuffer *buf;
	struct evkeyvalq *input_headers;
	struct evkeyvalq *output_headers;
	struct evkeyval *header;
	FILE* file=fopen("/new/tmp.txt","ra+");
	char body;
	buf = evbuffer_new();

	if (buf == NULL)
		{err(1, "failed to create response buffer");
	input_headers = req->input_headers;

	TAILQ_FOREACH(header,input_headers,next) {
		evbuffer_add_printf(buf,"%s :", header->key);
		evbuffer_add_printf(buf,"%s \n", header->value);
	}
	while((body = fgetc(file)) != EOF)
	{
		evbuffer_add_printf(buf,"%c",body);
	}
	evbuffer_add_printf(buf, "Requested: %sn", evhttp_request_uri(req));
	evhttp_add_header(req->output_headers,"Server","BOB");
	evhttp_send_reply(req, HTTP_OK, "OK", buf);
}
int main(int argc, char **argv)
{
	struct evhttp *httpd;
	event_init();
	httpd = evhttp_start("0.0.0.0", 8080);
	evhttp_set_gencb(httpd, generic_handler, NULL);
	event_dispatch();
	evhttp_free(httpd); 
	return 0;
}
*/