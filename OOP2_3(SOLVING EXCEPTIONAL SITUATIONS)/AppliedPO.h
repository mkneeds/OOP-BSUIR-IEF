#pragma once
#include <iostream>
#include "ShowTable.h"
#include <windows.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class AppliedPO
{
public:
	HANDLE hFind = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA ffd;
	wstring spec;
	stack<wstring> directories;
	int AppliedOn = 0; // 0 - off 1 - on
	int getAppliedOn() { return AppliedOn; }

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
	void print_ifform() {
		ShowTable t('-', '|', '+');
		t.add("Пользовательское ПО");
		t.endOfRow();
		vector<wstring> files;
		if (ListFiles(L"D:\\SYAP", L"*", files)) {
			for (vector<wstring>::iterator it = files.begin();
				it != files.end();
				++it) {
				wstring a = it->c_str();
				string str = std::string(a.begin(), a.end());
				t.add(str);
				t.endOfRow();
				///*wcout << it->c_str() << endl;*/
			}
		}
		cout << t;
	}
};

