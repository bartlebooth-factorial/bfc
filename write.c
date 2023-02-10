/* void write_start(FILE *fout); */
/* void write_right(FILE *fout); */
/* void write_left(FILE *fout) */
/* void write_incr(FILE *fout); */
/* void write_decr(FILE *fout); */
/* void write_outp(FILE *fout); */
/* void write_inp(FILE *fout); */
/* void write_loopbegin(FILE *fout); */
/* void write_loopend(FILE *fout); */
/* void write_end(FILE *fout); */

void write_start(FILE *fout) {
	fputs("#include <stdio.h>\n", fout);
	fputs("int main(int argc, char *argv[]) { ", fout);
	fputs("char array[30000] = {0}; char *ptr = array; ", fout);
}

void write_right(FILE *fout) {
	fputs("++ptr; ", fout);
}

void write_left(FILE *fout) {
	fputs("--ptr; ", fout);
}

void write_incr(FILE *fout) {
	fputs("++*ptr; ", fout);
}

void write_decr(FILE *fout) {
	fputs("--*ptr; ", fout);
}

void write_outp(FILE *fout) {
	fputs("putchar(*ptr); ", fout);
}

void write_inp(FILE *fout) {
	fputs("*ptr = getchar(); ", fout);
}

void write_loopbegin(FILE *fout) {
	fputs("while (*ptr) { ", fout);
}

void write_loopend(FILE *fout) {
	fputs("} ", fout);
}

void write_end(FILE *fout) {
	fputs("return 0; }\n", fout);
}

