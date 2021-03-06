*

You are given a text. Write a program which outputs its lines according to the following rules:

If line length is ≤ 55 symbols, print it without any changes.
If the line length is > 55 symbols, change it as follows:
Trim the line to 40 symbols.
If there are spaces ‘ ’ in the resulting string, trim it once again to the last space (the space should be trimmed too).
Add a string ‘... <Read More>’ to the end of the resulting string and print it.
INPUT SAMPLE:

The first argument is a file. The file contains a text.

For example:

Tom exhibited.
Amy Lawrence was proud and glad, and she tried to make Tom see it in her face - but 
he wouldn't look.
Tom was tugging at a button-hole and looking sheepish.
Two thousand verses is a great many - very, very great many.
Tom's mouth watered for the apple, but he stuck to his work.

OUTPUT SAMPLE:

Print to stdout the text lines with their length limited according to the rules described above.
For example:

Tom exhibited.
Amy Lawrence was proud and glad, and she... <Read More>
Tom was tugging at a button-hole and looking sheepish.
Two thousand verses is a great many -... <Read More>
Tom's mouth watered for the apple, but... <Read More>
CONSTRAINTS:

The maximum length of a line in the input file is 300 symbols.
There cannot be more than one consequent space symbol in the input data.

*/

#include <stdio.h>
#include <string.h>

#define MAXLINELEN  300

int main(int argc, char **argv)
{
    FILE  *fp;
    char line[MAXLINELEN];
	int lineLen;


    fp = fopen(argv[1],"r");
	if (!fp)
	{
		//printf("Can't open file %s\n", argv[1]);
		return 1;
	} // if
	while (!feof(fp))
	{
		fgets((char *) &line[0], MAXLINELEN, fp);
		if (line[0] == '\n')
			continue;
        lineLen = strlen(line);
		
		if (lineLen>55)
		{
			lineLen = 40;
			while (lineLen && line[lineLen]!= ' ')
				lineLen--;
			while (lineLen && line[lineLen]== ' ')
				lineLen--;
			if (!lineLen)
				line[40] = 0;
			else
			    line[lineLen+1] = 0;
			printf("%s... <Read More>\n", line);
		}
		else
		{
			if (line[0] != ' ')
			   printf("%s", line);
		}
		  
	}

   return 0;
}


