#pragma once
class Input
{

public:

	static void Update();
	static bool isKey(int key);
	static bool isKeyTrigger(int key);

private:
	
	static char keys[];
	static char oldkeys[];

	
};

