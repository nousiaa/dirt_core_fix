#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
	bool ALLOW_PATCH = false;
	ifstream in("drt.exe", ios::binary);
	cout << "ARE YOU SURE YOU WANT TO PATCH THIS FILE? (y/n) (ret)" << endl;
	char ANS;
	cin.get(ANS);
	if(ANS != 'Y' && ANS != 'y'){
		cout << "PATCH CANCELLED" << endl;
		cin.get(ANS);
		return 1;
	}
		
	if (in.is_open()){  
		char res[] = {0xC7,0x45,0xF0,0x00};
		char memblock[4];
		in.seekg(0x003C2D7F, ios::beg);
		in.read(memblock, 3);
		memblock[3]=0;
		if(string(memblock) ==string(res))
			ALLOW_PATCH = true;
		in.close();
	}
	if(ALLOW_PATCH){
		fstream out("drt.exe", ios::binary | ios::out | ios::in);
		if (out.is_open()){  
			char patch[] = {0xB8,0x01,0x00,0x00,0x00,0x90,0x90, 0x90, 0x90};
    		out.seekp(0x003C2D7F, ios::beg);
    		out.write(patch, 9);
    		out.close();
		}
	} else {
		cout << "PATCH FAILED" << endl;
		cin.get(ANS);
		return 1;
	}
	cout << "PATCH COMPLETED" << endl;
	cin.get(ANS);
	return 0;
}
