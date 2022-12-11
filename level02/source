#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int iVar1;
	size_t ret;
	long i;
	char* buff_cpy;
	char* buff_1 [14];
	char* buff_2 [6];
	char* buff_3 [12];
	int local_14;
	FILE *pass_fd;

	/**
	 * buffers initializations
	 */
	buff_cpy = buff_3;
	for (i = 12; i != 0; i--) {
		*buff_cpy = 0;
		buff_cpy++;
	}
	*buff_cpy = 0;
	buff_cpy = buff_2;
	for (i = 5; i != 0; i--) {
		*buff_cpy = 0;
		buff_cpy++;
	}
	*buff_cpy = 0;
	buff_cpy = buff_1;
	for (i = 12; i != 0; i--) {
		*buff_cpy = 0;
		buff_cpy++;
	}
	*buff_cpy = 0;


	pass_fd = 0;
	local_14 = 0;
	pass_fd = fopen("/home/users/level03/.pass","r");
	if (pass_fd == 0) {
		fwrite("ERROR: failed to open password file\n", 1, 36, 2);
		// WARNING: Subroutine does not return
		exit(1);
	}


	/**
	 * Read password
	 */
	ret = fread(buff_2, 1, 41, pass_fd);
	local_14 = (int)ret;
	ret = strcspn(buff_2, "\n");
	buff_2[ret] = '\0';
	if (local_14 != 36) {
		fwrite("ERROR: failed to read password file\n", 1, 36, 2);
		fwrite("ERROR: failed to read password file\n", 1, 36, 2);
		// WARNING: Subroutine does not return
		exit(1);
	}


	fclose(pass_fd);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");

	/* Ask or username */
	printf("--[ Username: ");
	fgets(buff_3, 100, 0);
	ret = strcspn(buff_3, "\n");
	buff_3[ret] = '\0';

	/* Ask for password */
	printf("--[ Password: ");
	fgets(buff_1, 100, 0);
	ret = strcspn(buff_1, "\n");
	buff_1[ret] = '\0';


	puts("*****************************************");
	iVar1 = strncmp(buff_2, buff_1, 41);
	if (iVar1 == 0) {
		printf("Greetings, %s!\n", buff_3);
		system("/bin/sh");
		return 0;
	}
	printf(buff_3);
	puts(" does not have access!");
	// WARNING: Subroutine does not return
	exit(1);
}
