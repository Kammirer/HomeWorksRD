#pragma once
#include <string>

enum class Classification { Assault, Support, Sniper, Medic };

std::string getClassification(Classification classPlayer);