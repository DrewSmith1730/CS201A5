#include "fileops.asmith16.h"


int initializeFile(FILE *fp){
    if(fp == NULL){
        return 1;
    }
    int zero = 0;
    fseek(fp, 0, SEEK_SET);
    fwrite(&zero, sizeof(int), 1, fp);

    return 0;
}

int readRecord(FILE *fp, int position, PartRecord *partData){
    if(fp == NULL){
        return 1;
    }
    if(position <= 0){
        return 1;
    }
    
    fseek(fp, 0, SEEK_SET);
    int recordNumber = 0;
    fread(&recordNumber, sizeof(int), 1, fp);
    if(recordNumber < position){
        return 1;
    }

    fseek(fp, (4 + (position-1) * sizeof(PartRecord)), SEEK_SET);
    fread(&(partData->partNumber), sizeof(partData->partNumber), 1, fp);
    fread(&(partData->partName), sizeof(partData->partName), 1, fp);
    fread(&(partData->quantity), sizeof(partData->quantity), 1, fp);

    return 0;
}

int writeRecord(FILE *fp, PartRecord *partData){
    if(fp == NULL){
        return -1;
    }

    fseek(fp, 0, SEEK_SET);
    int recordNumber;
    fread(&recordNumber, sizeof(int), 1, fp);
    int position;
    fseek(fp, 0, SEEK_SET);
    recordNumber = recordNumber + 1;
    fwrite(&recordNumber, sizeof(int), 1, fp);
    if(recordNumber == 0){
        position = 4;
    }
    else{
        position = (4 + (recordNumber-1) * sizeof(PartRecord));
    }


    fseek(fp, position, SEEK_SET);
    fwrite(&(partData->partNumber), sizeof(partData->partNumber), 1, fp);
    fwrite(&(partData->partName), sizeof(partData->partName), 1, fp);
    fwrite(&(partData->quantity), sizeof(partData->quantity), 1, fp);




    return position;
}