#ifndef LOADER_H
#define LOADER_H

#include "definitions.h"


UserType temporalUser;

int routerMenu = 0;


//informacion del player
string playeName = "Steve";
int playeMaxDamagePerAttack = 300;
int playerMaxLife = 1200;
int plusLife = 500;
int plusAttack= 850;
string description = "";

bool haveShieldPlayer = false;
bool haveSwordPlayer = false;

bool passedWithBlacksmith = false;
bool passedWithWizard = false;

string bossName = "";
int bossMaxDamagePerAttack = 0;
int bossMaxLife = 3000;

bool isBossDied = false;
bool isPlayerDied = false;

#endif // !LOADER_H

