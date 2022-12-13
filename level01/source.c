

char*	a_user_name;

int verify_user_name(void)
{
	int iVar1;
	byte *pbVar2;
	byte *pbVar3;
	undefined uVar4;
	undefined uVar5;
	byte bVar6;

	bVar6 = 0;
	uVar4 = &stack0xfffffff4 < (undefined *)0x10;
	uVar5 = &stack0x00000000 == (undefined *)0x1c;
	puts("verifying username....\n");
	iVar1 = 7;
	pbVar2 = a_user_name;
	pbVar3 = (byte *)"dat_wil";
	do {
		if (iVar1 == 0) break;
		iVar1 = iVar1 + -1;
		uVar4 = *pbVar2 < *pbVar3;
		uVar5 = *pbVar2 == *pbVar3;
		pbVar2 = pbVar2 + (uint)bVar6 * -2 + 1;
		pbVar3 = pbVar3 + (uint)bVar6 * -2 + 1;
	} while ((bool)uVar5);
	return (int)(char)((!(bool)uVar4 && !(bool)uVar5) - uVar4);
}



int verify_user_pass(byte *param_1)
{
	int iVar1;
	byte *pbVar2;
	undefined in_CF;
	undefined in_ZF;

	iVar1 = 5;
	pbVar2 = (byte *)"admin";
	do {
		if (iVar1 == 0) break;
		iVar1 = iVar1 + -1;
		in_CF = *param_1 < *pbVar2;
		in_ZF = *param_1 == *pbVar2;
		param_1 = param_1 + 1;
		pbVar2 = pbVar2 + 1;
	} while ((bool)in_ZF);
	return (int)(char)((!(bool)in_CF && !(bool)in_ZF) - in_CF);
}



int main(void)
{
	int i;
	char* buffer_cpy;
	char* buffer [16];
	int verif;

	buffer_cpy = buffer;
	for (i = 16; i != 0; i--)
	{
		*buffer_cpy = 0;
		buffer_cpy++;
	}
	verif = 0;
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);
	verif = verify_user_name();
	if (verif == 0) {
		puts("Enter Password: ");
		fgets(buffer, 100, stdin);
		verif = verify_user_pass(buffer);
		puts("nope, incorrect password...\n");
		return (1);
	}
	else {
		puts("nope, incorrect username...\n");
		return (1);
	}
	return (0);;
}
