#include <stdio.h>
#include <stdlib.h>

#include "write.c"

/* enum { */
/* 	RIGHT, LEFT, */
/* 	INCR, DECR, */
/* 	OUTP, INP, */
/* 	LOOPBEGIN, LOOPEND */
/* }; */

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Error: No file given\n");
		goto FAIL;
	}

	FILE *fin = fopen(argv[1], "r");

	if (fin == NULL) {
		printf("Error: Unable to open input file\n");
		goto FAIL;
	}

	FILE *fout = fopen("OUT.c", "w");

	if (fout == NULL) {
		printf("Error: Unable to open output file\n");
		goto FAIL;
	}

	write_start(fout);

	int curchar;
	curchar = fgetc(fin);
	while (curchar != EOF) {
		if (curchar == 62) {        // >
			write_right(fout);
		} else if (curchar == 60) { // <
			write_left(fout);
		} else if (curchar == 43) { // +
			write_incr(fout);
		} else if (curchar == 45) { // -
			write_decr(fout);
		} else if (curchar == 46) { // .
			write_outp(fout);
		} else if (curchar == 44) { // ,
			write_inp(fout);
		} else if (curchar == 91) { // [
			write_loopbegin(fout);
		} else if (curchar == 93) { // ]
			write_loopend(fout);
		}

		curchar = fgetc(fin);
	}

	write_end(fout);
	goto EXIT;

EXIT:
	fclose(fin);
	fclose(fout);
	system("gcc OUT.c;");
	system("rm OUT.c;");
	return 0;
FAIL:
	return -1;
}
