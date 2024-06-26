#define PART_NAME_LENGTH 32
#include <stdlib.h>
#include <stdio.h>
typedef struct {
    int partNumber;
    char partName[PART_NAME_LENGTH];
    int quantity;
} PartRecord;

int initializeFile(FILE *fp);
int readRecord(FILE *fp, int position, PartRecord *partData);
int writeRecord(FILE *fp, PartRecord *partData);