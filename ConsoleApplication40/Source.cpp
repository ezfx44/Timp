#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "rus");
	char nFile1[20];
	char nFile2[20]; 
	char buff1[256];
	char buff2[256];
	int line = 1;
	std::cout << "Âגוהטעו טלÿ ןונגמדמ פאיכא : ";
	std::cin >> nFile1;
	std::cout << "\nÂגוהטעו טלÿ געמנמדמ פאיכא : ";
	std::cin >> nFile2;
	std::ifstream f1, f2;
	f1.open(nFile1);
	f2.open(nFile2);
	std::ofstream fout;
	fout.open("file.txt");
	while (!f1.eof() || !f2.eof())
	{
		f1.getline(buff1, 256);
		f2.getline(buff2, 256);
		if (strcmp(buff1, buff2))
		{
			fout << nFile1 << " " << line << " " << buff1 << std::endl;
			fout << nFile2 << " " << line << " " << buff2 << std::endl;
		}
		line++;
	}
	f1.close();
	f2.close();
	system("pause");
	return 0;
}