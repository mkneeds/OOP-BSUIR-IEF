#pragma once
#include <stdio.h>
#include <string.h>
#include <iostream>  
#include <string>  
#include <io.h> 
#include <windows.h>
#include <vector>
#include <stack>
#include "ShowTable.h"
#include <fstream>

using namespace std;

class SystemPO
{
public:
	HANDLE hFind = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA ffd;
	wstring spec;
	stack<wstring> directories;
	ShowTable table;
	int sys = 0;
	class OS {
	public:
		int on_os = 0;
		void start_os() {
			on_os = 1;
		}
		void checkOs() {
			if (on_os == 0) {
				cout << "Операционная система выключена..." << endl;
				cout << "Включаю Операционную систему..." << endl;
				cout << "////////////" << endl;
				start_os();
				cout << "Операционная система запущена" << endl;
			}
		}
	};
	class Service {
	public:
		int on_service = 0;
		void checkService() {
			if (on_service == 0) {
				cout << "Сервисы выключены..." << endl;
				cout << "Включаю Сервисы..." << endl;
				cout << "////////////" << endl;
				on_service = 1;
				cout << "Сервисы запущенЫ" << endl;
			}
		}
	};
	OS os;
	Service syss;
public:
	void check_system() {
		if (os.on_os == 0) {
			os.checkOs();
			sys = 1;
			cout << "-----------------------------------" << endl;
		}
		if (syss.on_service == 0) {
			syss.checkService();
			sys = 1;
		}
	}
	bool ListFiles(wstring path, wstring mask, vector<wstring>& files) {

		directories.push(path);
		files.clear();

		while (!directories.empty()) {
			path = directories.top();
			spec = path + L"\\" + mask;
			directories.pop();

			hFind = FindFirstFile(spec.c_str(), &ffd);
			if (hFind == INVALID_HANDLE_VALUE) {
				return false;
			}

			do {
				if (wcscmp(ffd.cFileName, L".") != 0 &&
					wcscmp(ffd.cFileName, L"..") != 0) {
					if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
						directories.push(path + L"\\" + ffd.cFileName);
					}
					else {
						files.push_back(path + L"\\" + ffd.cFileName);
					}
				}
			} while (FindNextFile(hFind, &ffd) != 0);

			if (GetLastError() != ERROR_NO_MORE_FILES) {
				FindClose(hFind);
				return false;
			}

			FindClose(hFind);
			hFind = INVALID_HANDLE_VALUE;
		}

		return true;
	}
	void print_i() {
		ShowTable t('-', '|', '+');
		t.add("Системное ПО");
		t.endOfRow();
		vector<wstring> files;
		if (ListFiles(L"C:\\Windows\\SystemApps", L"*", files)) {
			for (vector<wstring>::iterator it = files.begin();
				it != files.end();
				++it) {
				wstring a = it->c_str();
				string str = std::string(a.begin(), a.end());
				write_in_file(str);
				t.add(str);
				t.endOfRow();
				///*wcout << it->c_str() << endl;*/
			}
		}
		cout << t;
	}
	void write_in_file(string &str) {
		ofstream ofs("window.txt", ios_base::app);
		if (!ofs.bad()) {
			ofs << str;
			ofs << endl;
		}
		ofs.close();
	}
};


