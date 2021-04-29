#include "global.h"

#include <stdint.h>
#include <stdlib.h>

#include "core/sock.h"


namespace pg {

struct Global {
    Sock** socks;

    uint16_t* unused;

    size_t nsocks;

    int flags;
};

}
