#include "Godmode.h"

Godmode::Godmode() : IModule(0x0, Category::EXPLOITS, "Godmode") {

}

Godmode::~Godmode() {
}

const char* Godmode::getModuleName() {
	return ("Godmode");
}

void Godmode::onSendPacket(C_Packet* packet) {
	if (packet->isInstanceOf<C_MovePlayerPacket>()) {
		C_MovePlayerPacket* movePacket = reinterpret_cast<C_MovePlayerPacket*>(packet);
		vec3_t pos = *g_Data.getLocalPlayer()->getPos();
		pos.y += 10.f;
		movePacket->Position = pos;
	}
}

void Godmode::onDisable() {

}