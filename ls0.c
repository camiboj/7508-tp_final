//
// Created by camix on 31/7/19.
//
#define _POSIX_C_SOURCE 200809L
#define LS0_OPENDIR_FAIL 3
#define LS0_CLOSEDIR_FAIL 4
#define MAX_DIR_NAME 1024


#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int ls0(const char *dir_name) {
    DIR* dirp = opendir(dir_name);
    if (dirp == NULL) {
        return LS0_OPENDIR_FAIL;
    }
    struct dirent *res;
    while((res = readdir(dirp)) != NULL) {
        if (res->d_name[0] != '.')
            fprintf(stdout, "%s\t", res->d_name);
    }
    fprintf(stdout, "\n");
    int s = closedir(dirp);
    if (s == -1) {
        return LS0_CLOSEDIR_FAIL;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [<pathname>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc == 2) {
        return ls0(argv[1]);
    }
    char dir_name[MAX_DIR_NAME];
    return ls0(getcwd(dir_name, MAX_DIR_NAME));
}