#include "pg.h"


namespace pg {

void poll(PollFd* fds, int nfds, int timeout) {
    PollFd* pfd = new PollFd[nfds * 2];

    for (int i = 0; i != nfds; ++i) {
        if (fds[i].events & POLLIN) {

        }
    }
}

}
