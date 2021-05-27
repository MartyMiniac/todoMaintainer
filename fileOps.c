#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fileOps.h"

void _getFileName(char * name);
void _updateIndex(long * val, long int * data[]);

void _getFileName(char * name) {
    const char * FILE_NAME = ".todo/index";
    time_t rawTime;
    time(&rawTime);
    sprintf(name, ".todo/%ld", rawTime);

    long int count;

    FILE * f = fopen(FILE_NAME, "rb");
    fread(&count, sizeof(long), 1, f);

    long int * data[count+1];
    
    fread(data, sizeof(long), count, f);
    fclose(f);

    data[count]=(long int *)rawTime;
    count++;

    _updateIndex(&count, data);
}
void writeToFile(char * str) {
    char * filename=malloc(sizeof(char)*10);
    _getFileName(filename);
    printf("Adding %s\n", str);
    FILE * f = fopen(filename, "w");       
    fprintf(f, "%s\n", str);
    fclose(f);
}
void readFile() {
    const char * FILE_NAME=".todo/index";
    long int count;

    FILE * f = fopen(FILE_NAME, "rb");
    fread(&count, sizeof(long int), 1, f);

    long int data[count];
    
    fread(&data, sizeof(long int), count, f);
    fclose(f);
    printf("TODO:\n");

    for(long int i=0; i<count; i++) {
        char * temp=malloc(sizeof(char)*20);
        sprintf(temp, ".todo/%ld", data[i]);
        printf("%ld) ", (i+1));

        FILE * f = fopen(temp, "r");
        int ch=getc(f);
        while(ch!=EOF) {
            putchar(ch);
            ch=getc(f);
        }
        fclose(f);
    }
}
void initFolder() {
    mkdir(".todo");
    const char * FILE_NAME=".todo/index";
    
    long int count=0l;
    FILE * f = fopen(FILE_NAME, "wb");
    fwrite((long int *)&count, sizeof(long), 1, f);
    fclose(f);
}

void deleteFile(int pos) {
    const char * FILE_NAME=".todo/index";
    long int count;

    FILE * f = fopen(FILE_NAME, "rb");
    fread(&count, sizeof(long int), 1, f);

    long int data[count];
    
    fread(&data, sizeof(long int), count, f);
    fclose(f);
    if(pos<1 || pos>count) {
        printf("%d doesn't exists\n", pos);
    }
    else {
        char * name=malloc(sizeof(char)*20);
        sprintf(name, ".todo/%ld", data[pos-1]);
        remove(name);
        printf("%s\n", name);
        count--;
        data[pos-1]=data[count];
        _updateIndex(&count, data);
    }
}

void _updateIndex(long * val, long int * data[]) {
    const char * FILE_NAME=".todo/index";
    FILE * f = fopen(FILE_NAME, "wb");
    fwrite((long int *)val, sizeof(long), 1, f);
    fwrite(data, sizeof(long), *val, f);
    fclose(f);
}


void test() {
}
void test2() {
}