#pragma once
#include "Module.h"
class TP : public IModule {
private:
	float glideMod = -0.01f;
	float glideModEffective = 0;
	int burh = 0;
	int bureah = 0;
	int burhnigga = 0;
	int breauhhhuhuhuhniga = 0;

public:
	TP();
	~TP();

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
	virtual const char* getRawModuleName() override;
};
