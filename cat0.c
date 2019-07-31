//
// Created by camix on 31/7/19.
//
#define _POSIX_C_SOURCE 200809L
#define MAX_READ 1024
#define STDOUT 1
#define CAT0_READ_FAIL 4
#define CAT0_WRITE_FAIL 5
#define CAT0_OPEN_FAIL 6


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int cat0(const char *file_name) {
    int flags = O_RDONLY;
    int file = open(file_name, flags);
    if (file < 0) {
        return CAT0_OPEN_FAIL;
    }
    char buf[MAX_READ];
    int count;
    while((count = read(file, buf, MAX_READ)) != 0) {
        if (count < 0) {
            return CAT0_READ_FAIL;
        }
        int s = write(STDOUT, buf, count);
        if (s < 0) {
            return CAT0_WRITE_FAIL;
        }
    }
    close(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return cat0(argv[1]);
}
