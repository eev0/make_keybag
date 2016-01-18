// make-keybag.c - Create new system keybag
//
// by evo

#include <stdio.h>
#include <sys/stat.h>

extern int MKBKeyBagCreateSystem();

int main(int argc, char* argv[]) {
	printf("Checking for keybag...\n");
	struct stat st = {0};
	if(stat("/mnt2/keybags/systembag.kb",&st) != 0) {
		printf("No keybag found. Attempting to create...\n");
		int test = MKBKeyBagCreateSystem(0, "/mnt2");
		if (test != 0) {
			printf("MKBKeyBagCreateSystem failed :(\n");
		} else {
			printf("MKBKeyBagCreateSystem worked! ^_^\n");
		}
	} else {
		printf("Keybag already exists. Skipping keybag creation.\n");
	}
	return 0;
}
