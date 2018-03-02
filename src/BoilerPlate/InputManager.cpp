#include "InputManager.hpp"

InputManager::InputManager() {

	keyW = false;
	keyA = false;
	keyS = false;
	keyD = false;
	keySpace = false;
	keyF = false;
	keyL = false;
	keyM = false;
	keyG = false;
}

void InputManager::SetW(bool wState) {

	keyW = wState;
}

void InputManager::SetA(bool aState) {

	keyA = aState;
}

void InputManager::SetS(bool sState) {

	keyS = sState;
}

void InputManager::SetD(bool dState) {

	keyD = dState;
}

void InputManager::SetSpace(bool spaceState) {

	keySpace = spaceState;
}

void InputManager::SetF(bool fState) {

	keyF = fState;
}

void InputManager::SetL(bool lState) {

	keyL = lState;
}

void InputManager::SetM(bool mState) {

	keyM = mState;
}

void InputManager::SetG(bool gState) {

	keyG = gState;
}


bool InputManager::GetW() {

	return keyW;
}

bool InputManager::GetA() {

	return keyA;
}

bool InputManager::GetS() {

	return keyS;
}

bool InputManager::GetD() {

	return keyD;
}

bool InputManager::GetSpace() {

	return keySpace;
}

bool InputManager::GetF() {

	return keyF;
}

bool InputManager::GetL() {

	return keyL;
}

bool InputManager::GetM() {

	return keyM;
}

bool InputManager::GetG() {

	return keyG;
}
