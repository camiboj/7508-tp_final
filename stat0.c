//
// Created by camix on 31/7/19.
//

#define _POSIX_C_SOURCE 200809L

#define MAX_TYPE 64


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/******************************************************************************
 * $ ./stat0 README.md
 * Size: 1318
 * File: README.md
 * Type: regular file
 *
 * S_ISREG(m)  is it a regular file?
 * S_ISDIR(m)  directory?
 *
 * Pre-condición: el archivo existe, y es un directorio o un archivo regular.
 */


void stat0(const char *file_name) {
    struct stat sb;
    stat(file_name, &sb);
    fprintf(stdout, "Size: %lld\n", (long long) sb.st_size);
    fprintf(stdout, "File: %s\n", file_name);
    char* type = "regular file";
    if (S_ISDIR(sb.st_mode)) {
        type = "directory";
    }
    fprintf(stdout, "Type: %s\n", type);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    stat0(argv[1]);
    return 0;
}