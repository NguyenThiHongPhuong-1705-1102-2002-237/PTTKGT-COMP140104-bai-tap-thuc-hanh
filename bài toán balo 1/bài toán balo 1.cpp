#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int maketqua[100], gtkhoiluong[100], MAX = 0, khoiluongmax, somonhang, n;
string codekq = "", codetam = "";

void sauKhiDeQui() {
	int khoiluong = 0;
	codetam = "";
	for (int i = 0; i < somonhang; ++i) {
		khoiluong += maketqua[i] * gtkhoiluong[i];
	}
	for (int i = 0; i < somonhang; ++i) {
		if (maketqua[i] != 0) {
			string s;
			s = '0' + i;
			codetam += s + " ";

		}
	}
	if (khoiluong <= khoiluongmax && khoiluong > MAX) {
		MAX = khoiluong;
		codekq = codetam;
	}
}

void deQui(int i) {
	if (i == somonhang)
		sauKhiDeQui();
	else {
		for (int j = 0; j <= 1; ++j) {
			maketqua[i] = j;
			deQui(i + 1);
		}
	}
}

int main() {
	ifstream infile;
	infile.open("balo.inp");
	infile >> somonhang >> khoiluongmax;
	for (int i = 0; i < somonhang; ++i)
		infile >> gtkhoiluong[i];
	infile.close();
	ofstream outfile;
	outfile.open("balo.out");
	deQui(0);
	outfile << MAX << endl << codekq;
	outfile.close();
	return 0;
}
