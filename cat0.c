//
// Created by camix on 31/7/19.
//
#define _POSIX_C_SOURCE 200809L
#define MAX_READ 1024
#define STDOUT 1
#define STAT0_READ_FAIL 4
#define STAT0_WRITE_FAIL 5
#define STAT0_OPEN_FAIL 6


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <libexplain>

void cat0(const char *file_name) {
    int flags = O_RDONLY;
    int file = open(file_name, flags);
    /*if (file < 0) {
        fprintf(stderr, "%s\n", explain_open(file_name, flags));
        exit(EXIT_FAILURE);
    }*/
    char buf[MAX_READ];
    int count;
    while((count = read(file, buf, MAX_READ)) > 0) {
        write(STDOUT, buf, count);
        /*if (count < 0) {
            fprintf(stderr, "%s\n", explain_read(file, buf, MAX_READ));
            exit(EXIT_FAILURE);
        }
        int s = write(STDOUT, buf, count);
        if (s < 0) {
            fprintf(stderr, "%s\n", explain_write(file, buf, count));
            exit(EXIT_FAILURE);
        }*/
    }
    close(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    cat0(argv[1]);
    return 0;
}
