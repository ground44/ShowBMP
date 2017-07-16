#include <stdio.h>
#include <iostream>

#include "bmp.hpp"

using namespace std;

bmp image;

int main(int argc,char *argv[]){
	if(argc<2){
		cout<<"No file given"<<endl;
		return 0;
	}

	if(!image.openFile(argv[1])){
		cout<<"Error opening the image"<<endl;
		return 0;
	}else{
		cout<<"Image opened succesfully"<<endl;
	}

	if(!image.readFileHeader()){
		cout<<"Error reading the fileheader"<<endl;
	}else{
		cout<<"fileHeader was read succefully"<<endl;
	}

	if(!image.readDIBHeader()){
		cout<<"Error reading the DIBheader"<<endl;
	}else{
		cout<<"DIBHeader was read succefully"<<endl;
	}

	int brea1k=44;




}