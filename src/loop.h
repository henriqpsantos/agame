#pragma once

enum DIRECTION {
		UP=0x0001,
		DOWN=0x0002,
		LEFT=0x0004,
		RIGHT=0x0008
};
bool handleLoop();
int handleEvents(void);

