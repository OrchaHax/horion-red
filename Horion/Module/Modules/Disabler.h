#pragma once

#include "Module.h"

class Disabler : public IModule {
private:
	bool isMineplex = false;
	bool isCubeCraft = false;
	int oldGameMode = -1;
	float Bruhniggas;
	vec3_t Nofavec;
	double Nofapos = 0;
	double Nofapos2 = 0;
	double Nofapos3 = 0;
	float fNofapos = 0;
	float fNofapos2 = 0;
	float fNofapos3 = 0;

public:
	Disabler();
	~Disabler();

	// Inherited via IModule
	virtual void onDisable() override;
	virtual void onTick(C_GameMode* gm) override;
	virtual const char* getModuleName() override;
};
