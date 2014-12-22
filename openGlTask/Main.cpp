#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

int main(int argc, char* argv[])
{
	Controller* mController = new Controller(argc, argv);
	
	delete mController;
}