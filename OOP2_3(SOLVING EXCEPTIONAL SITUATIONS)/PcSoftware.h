#pragma once
#include "AppliedPO.h"
#include "SystemPO.h"
#include <exception>


class PcSoftware : virtual public SystemPO, virtual public AppliedPO //Програмное обеспечение компьютера
{
public:

	int OnPc = 0;
	int a;
	PcSoftware() { OnPc = 0; }
	PcSoftware(int a) {
		cout << "Конструктор класса сработал" << endl;
		if (a) throw 1;
	}
	~PcSoftware() {
		throw std::runtime_error("Сработал диструктор");
		cout << "Диструктор PCSoftware" << endl;
	}

	PcSoftware(int OnPc, int i) : OnPc(OnPc), a(i) {}
	void SwitchPC();
};


