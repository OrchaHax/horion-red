#include "Disabler.h"

Disabler::Disabler() : IModule(0x0, Category::EXPLOITS, "Disable AntiCheat") {
	this->registerBoolSetting("CubeCraft", &this->isCubeCraft, this->isCubeCraft);
	this->registerBoolSetting("Mineplex", &this->isMineplex, this->isMineplex);
}

Disabler::~Disabler() {
}

const char* Disabler::getModuleName() {
	return ("Disabler");
}

void Disabler::onTick(C_GameMode* gm) {
	if (!g_Data.isInGame())
		return;
	{
		if (isCubeCraft) {
			if (strcmp(g_Data.getRakNetInstance()->serverIp.getText(), "mco.cubecraft.net") == 0) {
				vec3_t posa = *g_Data.getLocalPlayer()->getPos();
				vec3_ti* bedPos = new vec3_ti(posa.x, posa.y - 1.6, posa.z);
				vec3_t pos = *g_Data.getLocalPlayer()->getPos();
				Nofavec = pos;
				Nofavec.y += 1.6;
				C_MovePlayerPacket* a = new C_MovePlayerPacket(g_Data.getLocalPlayer(), Nofavec);
				g_Data.getClientInstance()->loopbackPacketSender->sendToServer(a);
				delete a;
				Nofavec.y -= 1.6;
				C_MovePlayerPacket* a2 = new C_MovePlayerPacket(g_Data.getLocalPlayer(), Nofavec);
				g_Data.getClientInstance()->loopbackPacketSender->sendToServer(a2);
				delete a2;
				if (isMineplex) {
					if (strcmp(g_Data.getRakNetInstance()->serverIp.getText(), "mco.mineplex.com") == 0) {
						vec3_t pos = *g_Data.getLocalPlayer()->getPos();
						C_MovePlayerPacket* movePlayerPacket = new C_MovePlayerPacket(g_Data.getLocalPlayer(), pos);
						g_Data.getClientInstance()->loopbackPacketSender->sendToServer(movePlayerPacket);
						delete movePlayerPacket;
						pos.y = -4477558.0f;
						movePlayerPacket = new C_MovePlayerPacket(g_Data.getLocalPlayer(), pos);
						g_Data.getClientInstance()->loopbackPacketSender->sendToServer(movePlayerPacket);
						delete movePlayerPacket;
					}
				}
			}
		}
	}
}
void Disabler::onDisable() {
	if (g_Data.getLocalPlayer() != nullptr)
		g_Data.getLocalPlayer()->setGameModeType(oldGameMode);
}