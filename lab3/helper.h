typedef struct{
	char *word;
}oneWord;

typedef struct{
	int count;
	char startLetter;
	oneWord *ptr;
}wordLine;
