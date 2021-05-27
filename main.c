#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileOps.h"

int main(int argc, char * argv[]) {
    char ch[1000];
    const char * commands[] = {"add", "list", "init", "delete", "test1", "test2"};
    const char FILE_NAME[] = ".todo";
    //TODO: implement required input safety
    if(strcmp(argv[1],commands[0])==0) {
        writeToFile(argv[2]);
    }
    else if(strcmp(argv[1], commands[1])==0) {
        readFile();
    }
    else if(strcmp(argv[1], commands[2])==0) {
        initFolder();
    } 
    else if(strcmp(argv[1], commands[3])==0) {
        deleteFile(atoi(argv[2]));
    } 
    else if(strcmp(argv[1], commands[4])==0) {
        test();
    } 
    else if(strcmp(argv[1], commands[5])==0) {
        test2();
    }
    else {
        printf("Invalid option\n");
    }
    return 0;
}


