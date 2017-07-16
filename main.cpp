#include <stdio.h>
#include <iostream>

#include "bmp.hpp"//bmp parser
#include "gfx.hpp"//the graphix functions file

using namespace std;

bmp image;

int main(int argc,char *argv[]){
	if(argc<2){
		cout<<"No file given"<<endl;
		return 0;
	}

	//opening and parsing the file
	if(!image.openFile(argv[1])){
		cout<<"Error opening the image"<<endl;
		return 0;
	}else{
		cout<<"Image opened succesfully"<<endl;
	}

	if(!image.readFileHeader()){
		cout<<"Error reading the fileheader"<<endl;
	}else{
		cout<<"fileHeader was read succesfully"<<endl;
	}

	if(!image.readDIBHeader()){
		cout<<"Error reading the DIBheader"<<endl;
	}else{
		cout<<"DIBHeader was read succesfully"<<endl;
	}

	//Graphics stuff
	if(!glInit()){
		cout<<"Error initing OpenGL"<<endl;
	}else{
		cout<<"OpenGl started succesfully"<<endl;
	}

	if(!createWindow(argv[1],image.getWidth(),image.getHeight())){
		cout<<"Error creating a window"<<endl;
	}else{
		cout<<"a window was created."<<endl;
	}

	imageShow();


}