#pragma once
#pragma pack(2)


struct FILEHEADER{
	unsigned char headerField[2];
	unsigned int bitmapSize;
	unsigned short reserved1;
	unsigned short reserved2;
	unsigned int offset;
};

struct DIBHEADER{
	unsigned int headerSize;
	signed int width;
	signed int height;
	unsigned short noColorPlanes;
	unsigned short noBytesPerPixel;
	unsigned int compression;
	unsigned int imageSize;
	signed int horResolution;
	signed int verResolution;
	unsigned int noColorsInPalette;
	unsigned int noImportantColors;
};

class bmp{
	private:
		char *path;
		unsigned char *buffer;
		int fileSize;
		
		
		//header info
		FILEHEADER fileHeader;
		DIBHEADER dibHeader;

	
	public:
		bmp();
		bool openFile(char *path);
		bool readFileHeader();
		bool readDIBHeader();
		int getWidth();
		int getHeight();
};

