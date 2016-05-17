//This small program is meant to add a header (comment) to every file in the directory it runs on
//if the file has a name x.cpp where x is a number without leading zeroes, up to 20000, which is
//enough to cover all the UVa problem numbers. The header must have name header.txt and must be 
//already formatted as comment or it will break your code, so beware. Use at own risk, this program
//hasn't been extensively tested, it was just something to fix my problem this one time
//If the code file starts with a /* or // (already has a comment at the beggining), the program won't
//change the contents of the file. This program is potentially dangerous since it doesn't create
//backups when replacing a file, so create your own backups first or try this in a branch other than
//the master branch if you're using git

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int main(){

	FILE* header = fopen("Header.txt", "r");
	if(header == NULL){
		printf("Header.txt not found\n");
		return -1;
	}
	FILE* code;
	char filename[1000];
	char tempName[1000];
	char* newFileContent;
	int codeFileSize;
	int headerFileSize;
	char st[2];
	
	int i = 1;
	for(i = 0; i < 20000; i++){
		sprintf(filename, "%d.cpp", i);
		sprintf(tempName, "%dv2.cpp", i);
		code = fopen(filename, "r");
		if(code != NULL){
			fscanf(code, "%c%c", &st[0], &st[1]);
			if(strcmp(st, "/*") == 0 || strcmp(st, "//") == 0){//File already starts with a comment
				printf("File %s already starts with a comment. The file was not modified.\n", filename);
				continue;
			}
			rewind(code);
			
			fseek(code, 0, SEEK_END);
			codeFileSize = ftell(code);//Get size of code file
			rewind(code);
			fseek(header, 0, SEEK_END);
			headerFileSize = ftell(header);//Get size of header file
			rewind(header);
			newFileContent = (char*) malloc((headerFileSize + codeFileSize + 1) * sizeof(char));//Alloc memory for new file content
			if(newFileContent == NULL){//If could not alloc
				printf("Could not alloc enough memory (%s).\n", filename);
				return -1;
			}
			fread(newFileContent, sizeof(char), headerFileSize, header);//Read contents of header and put on newFileContent
			fread(newFileContent + headerFileSize, sizeof(char), codeFileSize, code);//Read contents of code file and put on right position
																					 //of newFileContent string
			newFileContent[headerFileSize + codeFileSize] = 0;//Adds terminating character to string
			fclose(code);
			code = fopen(filename, "w"); // Attention, if you don't want to overwrite your source code files
										 // use a name other than filename (you can use tempName for xv2.cpp
										 // instead of filename, the new file will be name xv2.cpp, where x is
										 // the same number of the file name
			fprintf(code, "%s", newFileContent);//Prints new content on file, overwriting old code file
			free(newFileContent);
			printf("File %s successfully updated.\n", filename);
		}
	}
}
