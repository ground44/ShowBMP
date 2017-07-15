class bmp{
	private:
		char *path;
		int size;
		short reserved1;
		short reserved2;
		int offset;

		//bool openFile();
		//bool loadFileHeader();
		//bool loadDIB();
		//bool loadColorTable();

	public:
		bmp(char *path);
};