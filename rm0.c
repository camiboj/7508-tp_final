//
// Created by camix on 31/7/19.
//
#define _POSIX_C_SOURCE 200809L

#include <unistd.h>

int rm0(const char *file) {
    return unlink(file);
}

int main(int argc, char *argv[]) {
    // do something with argc to avoid warnings
    return rm0(argv[1]);
}
