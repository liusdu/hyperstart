#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include "../config.h"

struct hyper_pod;
struct env;

#ifdef WITH_DEBUG
#define dprintf(fmt, ...) \
	fprintf(stdout, fmt, ##_VA_ARGS__)
#else
#define dprintf(fmr, ...)
#endif

char *read_cmdline(void);
int hyper_setup_env(struct env *envs, int num);
int hyper_find_sd(char *prefix, char *addr, char **dev);
int hyper_list_dir(char *path);
void online_cpu(void);
void online_memory(void);
int hyper_mkdir(char *path);
int hyper_open_channel(char *channel, int mode);
int hyper_open_serial_dev(char *tty);
int hyper_setfd_cloexec(int fd);
int hyper_setfd_block(int fd);
int hyper_setfd_nonblock(int fd);
int hyper_socketpair(int domain, int type, int protocol, int sv[2]);
void hyper_shutdown(void);
int hyper_insmod(char *module);
#endif
