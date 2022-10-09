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
		cout << "Constructor of the PcSoftware class" << endl;
		if (a) throw 1;
	}
	~PcSoftware() {
		throw std::runtime_error("Distructor of the PcSoftware class");
		cout << "Distructor PcSoftware" << endl;
	}

	PcSoftware(int OnPc, int i) : OnPc(OnPc), a(i) {}
	void SwitchPC();


};


