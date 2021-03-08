#include <stdio.h>
#include <string.h>


int main(int argc, char** argv){

	if (argc != 2){
		printf("\nUsage : warm <password>\n");
		return -1;
	}

	char* p4s5 = "me_up!%#";

	if (strncmp(argv[1], p4s5, strlen(p4s5))){
		printf("\n[%s] incorrect!\n", argv[1]);
		return 1;
	}else{
		printf("\nWarm up done, good job\n");
		return 0;
	}
}


