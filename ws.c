#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#include <unistd.h>

#define WORDLEN 20
#define MAXWORDS 100
#define ROW 40
#define COL 40





void trimws(char* s);

int readWords(char* wl[MAXWORDS], char* filename); 

void generate_grid(void);
void print_grid(void);

void place_word(void);

int main(int argc, char* argv[]){
	char* wordlist[MAXWORDS];
	int wordCount;
	
	wordCount = readWords(wordlist, argv[1]);
	
	char grid[ROW][COL];
	
	//Generate grid
	//char c = 'A' + (rand() % 26);
	int i = 0; 
	int j = 0; 
	for(i=0; i<ROW;++i){
		for(j=0; j<COL;++j){
			grid[i][j] = '.';
		}
	}
	
	//Set up the random seed
	int seed = 69;
	srand(seed);
	
	int word;
	for(word=0; word<wordCount;++word){
		//get a random direction for each word
		int xdir = 0; 
		int ydir = 0; 
		while(xdir==0&&ydir==0){
				xdir = rand()%3-1;
				ydir = rand()%3-1;
			}
		printf("%d, %d\n", xdir, ydir);
		
		int startx = rand() % COL; 
		int starty = rand() % ROW;
		
		int startxx = startx; 
		int startyy = starty; 
		
		int q; 
		for(q=0; q<strlen(wordlist[word]); ++q){
			grid[starty][startx] = wordlist[word][q];
			startx += xdir;
			starty += ydir;
		}
		
	}
	
	
	
	//print grid
	for(i=0; i<ROW;++i){
		for(j=0; j<COL;++j){
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<wordCount; ++i){
		//printf("%s, ", wordlist[i]);
	}

}


		
void place_word(void){
	int i = 0;
	int j = 0;
	int randRow = (rand() % 27);
	int randCol = (rand() % 39);
	for(i = randRow; i<28; ++i){
		for(j = randCol; j<40; ++j){
			
			
		}
	}
}
			
			
			
			
			
			
//http://www.101computing.net/python-wordsearch-generator/
			
			
//https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=2&cad=rja&uact=8&ved=0ahUKEwiqouer783YAhWh3oMKHZ6SAR0QtwIINDAB&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DGjiwgnpv-5s&usg=AOvVaw2r8VBqEiNJ70W1ScdVE_vn
			
			
void trimws(char* s) {
	int end = strlen(s) - 1;
	while (isspace(s[end])){
		s[end] = 0;
		end -=1;
	}
}

int readWords(char* wl[MAXWORDS], char* filename) {
	FILE* inFile = NULL;
	inFile = fopen(filename, "r");
	int i = 0;
	while(!feof(inFile)){
		wl[i] = (char*)malloc(WORDLEN*sizeof(char));
		fgets(wl[i], WORDLEN, inFile);
		trimws(wl[i]);
		++i;
	}
	
	fclose(inFile);
	return i-1;

}
