#include "Classification.h"

std::string getClassification(Classification classPlayer) {
	switch (classPlayer) {
	case Classification::Assault:
		return "Assault";
	case Classification::Support:
		return "Support";
	case Classification::Sniper:
		return "Sniper";
	case Classification::Medic:
		return "Medic";
	}
}