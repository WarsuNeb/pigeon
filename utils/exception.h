#pragma once

#include <errno.h>
#include <system_error>
#include <string>


namespace evm {

using std::string;

inline void throw_system_error_explicit(int err, const string& msg) {
    throw std::system_error(err, std::system_category(), msg);
}

inline void throw_system_error_explicit(int err, const char* msg) {
    throw_system_error_explicit(err, string(msg));
}

template <class T>
inline void throw_system_error(const T& msg) {
    throw_system_error_explicit(errno, msg);
}

// Check a Posix return code (0 on success, error number on error), throw
// on error.
template <class T>
inline void check_posix_error(ssize_t ret, const T& msg) {
    if (ret != 0)
        throw_system_error(msg);
}

// Check a traditional Unix return code (-1 and sets errno on error), throw
// on error.
template <class T>
inline void check_unix_error(ssize_t ret, const T& msg) {
    if (ret == -1)
        throw_system_error(msg);
}

// Check a Linux kernel-style return code (>= 0 on success, negative error
// number on error), throw on error.
template <class T>
inline void check_kernel_error(ssize_t ret, const T& msg) {
    if (ret < 0)
        throw_system_error(msg);
}

}
