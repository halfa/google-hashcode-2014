/*************************** 
* Google HashCode 2014 trial
* **************************
* Avaible instructions
* - PAINTSQ   R C S 
*     paint the square (2S+1)x(2S+1)
* - ERASECELL R C
*/

#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1

void analyse (FILE* out, char* t, R, C){
  /* We cut the map into small 3*3 squares */
	int r, c, r_right = R%3, c_bot = C%3;
	int i, j;

	// analyse
	for (r=0; r<R; r+=3){
		for (c = 0; c < C; c+=3)
		{
			//look for paterns
			switch ( isSquare(t, R, r, c, 3) )
			{
				case 0:
					fprintf(out, "PAINTSQ %d %d 1\n", r, c);
				break;
				
				case 1: // look for the blank pixel

				break;

				default:
				
			}
		}
	}

	// edges
}

int countBlankSquare (char* t, R, x, y, d){
	int blank = 0;
	int r, c;
	for(r=0; r<d; r++)
		for(c=0; c<d; c++)
			if (*(t+R*(r+x)+(c+y) == 0){
				paint = false;
				break;
			}
	return paint;
}

int main (char* argv){
  
  FILE* source = fopen("doodle.txt", "r");
  FILE* out = fopen("out", "w");
  int R, C, r, c, lines_out;
  char* t;

  // Read file content
  fscanf(source, "%d %d", &R, &C);
  if(DEBUG) printf("R:%d, C:%d \n", R, C);
  
  t = calloc(R*C,sizeof(char));
    if(t == NULL) exit(1);

  // Fill the map
  lines_out = 0;
  for(r = 0; r < R; r++)
    for(c = 0; c < C; c++)
      if(fgetc(source) == '#'){
        *(t+R*r+c) = 1;
        // naive case
        // fprintf(out, "PAINTSQ %d %d 0\n", r, c);
      }
  
  analyse(out, t, R, C);

  fclose(source);
  fclose(out);

  return 0;
}
