#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	//Need ASCII 40-125 (from testme)
	//Generate a random character
	//Trying to get: [({ax})]
	char random_character = (rand()%(126-32))+32;
	
	//Return random character
    return random_character;
}

char *inputString()
{
    // TODO: rewrite this function
	//Generate random string
	//Trying to get: reset\0
	
	//Initialize Variables
	char string[6];
	int i;
	
	//Generate string
	for(i = 0; i < 5; i++)
	{
		string[i] = (rand()%(116-101))+101;
		i++;
	}
    return string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;	// [ : ASCII value 91
    if (c == '(' && state == 1) state = 2;	// ( : ASCII value 40
    if (c == '{' && state == 2) state = 3;	// { : ASCII value 123
    if (c == ' '&& state == 3) state = 4;	// [space] : ASCII value 32
    if (c == 'a' && state == 4) state = 5;	// a : ASCII value 97
    if (c == 'x' && state == 5) state = 6;	// x : ASCII value 120
    if (c == '}' && state == 6) state = 7;	// } : ASCII value 125
    if (c == ')' && state == 7) state = 8;	// ) : ASCII value 41
  if (c == ']' && state == 8) state = 9;	// ] : ASCII value 93
    if (s[0] == 'r' && s[1] == 'e'			// r: ASCII 114, e : ASCII 101
       && s[2] == 's' && s[3] == 'e'		// s: ASCII 115, e : ASCII 101
       && s[4] == 't' && s[5] == '\0'		// t: ASCII 116, \0: ASCII 0
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
