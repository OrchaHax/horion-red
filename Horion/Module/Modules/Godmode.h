#pragma once

#include "Module.h"

class Godmode : public IModule {
private:

public:
	Godmode();
	~Godmode();

	// Inherited via IModule
	virtual void onSendPacket(C_Packet* packet) override;
	virtual void onDisable() override;
	virtual const char* getModuleName() override;
};

