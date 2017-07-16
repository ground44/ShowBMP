#include <iostream>

#include "bmp.hpp"

bmp::bmp(){
	
}

bool bmp::openFile(char *path){
	bool result=false;
	FILE *fp;

	//open the file
	this->path=path;
	fp=fopen(path,"rb");
	if(fp==NULL)goto Exit;

	//get the file size;
	fseek(fp,0,SEEK_END);
	fileSize=ftell(fp);
	rewind(fp);

	//create a buffer to load the file in
	buffer=(unsigned char*)malloc(fileSize);

	//read te file into the buffer
	if(fread(buffer,1,fileSize,fp)!=fileSize) goto Exit;

	//mark the result succesfull
	result=true;

	Exit:
	fclose(fp);
	return result;
}

bool bmp::readFileHeader(){
	bool result=false;
	char *pfileHeader = (char*)&fileHeader.headerField[0];
	for(int i=0;i<14;i++){
		pfileHeader[i]=buffer[i];
	}

	if(fileHeader.headerField[0]=='B'&&fileHeader.headerField[1]=='M'){
		result=true;
	}
	else if(fileHeader.headerField[0]=='B'&&fileHeader.headerField[1]=='A'){
		result=true;
	}
	else if(fileHeader.headerField[0]=='C'&&fileHeader.headerField[1]=='I'){
		result=true;
	}
	else if(fileHeader.headerField[0]=='C'&&fileHeader.headerField[1]=='P'){
		result=true;
	}
	else if(fileHeader.headerField[0]=='I'&&fileHeader.headerField[1]=='C'){
		result=true;
	}
	else if(fileHeader.headerField[0]=='P'&&fileHeader.headerField[1]=='T'){
		result=true;
	}

	return result;
}

bool bmp::readDIBHeader(){
	bool result=false;
	char *pDIBHeader = (char*)&dibHeader.headerSize;
	for(int i=0;i<40;i++){
		pDIBHeader[i]=buffer[i+14];
	}
	
	result=true;
	return result;
}


int bmp::getWidth(){
	return dibHeader.width;
}

int bmp::getHeight(){
	return dibHeader.height;
}

