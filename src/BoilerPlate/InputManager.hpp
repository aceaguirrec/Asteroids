#pragma once

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

class InputManager {

private:
	bool keyW;
	bool keyA;
	bool keyS;
	bool keyD;
	bool keySpace;
	bool keyF;
	bool keyL;
	bool keyM;
	bool keyG;


public:
	InputManager();

	void SetW(bool wState);
	void SetA(bool aState);
	void SetS(bool sState);
	void SetD(bool dState);
	void SetSpace(bool spaceState);
	void SetF(bool fState);
	void SetL(bool lState);
	void SetM(bool mState);
	void SetG(bool gState);


	bool GetW();
	bool GetA();
	bool GetS();
	bool GetD();
	bool GetSpace();
	bool GetF();
	bool GetL();
	bool GetM();
	bool GetG();


}
#endif // !INPUT_MANAGER_H

