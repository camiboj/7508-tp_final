//
// Created by camix on 31/7/19.
//
#define _POSIX_C_SOURCE 200809L

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int rm0(const char *file) {
    return unlink(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return rm0(argv[1]);
}
