#include "TP.h"



TP::TP() : IModule(0x0, Category:: MOVEMENT, "TP movement") {
{
	this->registerFloatSetting("value", &this->glideMod, this->glideMod, -2, 1);
}


TP::~TP()
{
}

const char* TP::getModuleName()
{
	if (isEnabled()) {
		static char yeet[30]; // This is kinda ghetto rn, there should be a better way to make this...
		sprintf_s(yeet, 30, "TP [%.2f]", glideModEffective);
		return yeet;
	}
	else
		return ("TP");
	
}

void TP::onTick(C_GameMode* gm) {
	float calcYaw = (gm->player->yaw + 90) * (PI / 180);
	float calcPitch = (gm->player->pitch) * -(PI / 180);
	if (gm->player != nullptr) {
		glideModEffective = glideMod;
		if (GameData::isKeyDown(VK_SPACE))
			glideModEffective += 0.2f;
		if (GameData::isKeyDown(VK_SHIFT))
			glideModEffective -= 0.2f;
		gm->player->velocity.y = glideModEffective;
		burh++;
		C_LocalPlayer* localPlayer = g_Data.getLocalPlayer();
		if (burh >= 4)
		{
			localPlayer->velocity.x *= 1.39f;
			localPlayer->velocity.z *= 1.39f;
			vec3_t pos = *g_Data.getLocalPlayer()->getPos();
			float teleportX = cos(calcYaw) * cos(calcPitch) * 3.000000005f;
			float teleportZ = sin(calcYaw) * cos(calcPitch) * 3.000000005f;
			pos = *gm->player->getPos();
			//g_Data.getLocalPlayer()->setPos(vec3_t(pos.x, pos.y - 0.15f, pos.z ));
			g_Data.getLocalPlayer()->setPos(vec3_t(pos.x + teleportX, pos.y + 0.15f, pos.z + teleportZ));
			burh = 0;
		}

	}
		
}

const char * TP::getRawModuleName()
{
	return "TP";
}
