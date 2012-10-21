/* mjpeg HTTP stream decoder */

#ifndef _MJPEGRX_H
#define _MJPEGRX_H

#include <pthread.h>
//#define DEBUG

struct keyvalue_t {
	char *key;
	char *value;
	struct keyvalue_t *next;
};

struct mjpeg_threadargs_t {
	char *host;
	int port;

	pthread_t thread;

	struct mjpeg_callbacks_t *callbacks;
	struct mjpeg_inst_t *inst;
};

struct mjpeg_callbacks_t {
	void (*donecallback)(void *optarg);
	void (*readcallback)(char *buf, int bufsize, void *optarg);
	void *optarg;
};

struct mjpeg_inst_t {
	int threadrunning;
	pthread_t *thread;
};

struct mjpeg_inst_t *
mjpeg_launchthread(
		char *host,
		int port,
		struct mjpeg_callbacks_t *callbacks
		);

void mjpeg_stopthread(struct mjpeg_inst_t *inst);
void * mjpeg_threadmain(void *optarg);

#endif