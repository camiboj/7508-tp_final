#define _POSIX_C_SOURCE 200809L

#include <unistd.h>

int rm0(const char *file) {
    return unlink(file);
}

int main(int argc, char *argv[]) {
    // do something with argc to discard warnings
    return rm0(argv[1]);
}
