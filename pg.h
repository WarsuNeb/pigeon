#pragma once

#include <stdlib.h>


namespace pg {

/*  A number random enough not to collide with different errno ranges on      */
/*  different OSes. The assumption is that error_t is at least 32-bit type.   */
#define HAUSNUMERO 156384712

/* Native pigeon error codes. */
#ifndef ETERM
#define ETERM (HAUSNUMERO + 1)
#endif
#ifndef EFSM
#define EFSM (HAUSNUMERO + 2)
#endif

struct Socket {
    Socket(int domain, int protocol);

    ~Socket() { close(); }

    void close();

    void set_opt(int level, int option, const void* value, size_t value_len);
    void get_opt(int level, int option, void* value, size_t* value_len);

    void bind(const char* addr);
    void connect(const char* addr);

    void shutdown(int how);

    void send(const void* buf, size_t len, int flags);
    void recv(void* buf, size_t len, int flags);

    void sendmsg();
    void recvmsg();
};

#define POLLIN 1
#define POLLOUT 2

struct PollFd {
    int fd;
    short events;
    short revents;
};

}
