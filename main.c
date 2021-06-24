#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>






#define MAX_NAME 30


typedef struct node
{
	char* word;
	struct node* next;
}
node;



char** getdirectoryentries(); //get directory entries and return filename for each entry
int isCorrectFile(char* file, char* extension); //find string inside another




int main()
{
	FILE** files;
	
	//names array used to get the files with the .js extensions to infect
	char **names = getdirectoryentries();
	node* head = NULL;

	for (int i = 0; names[i] != NULL; i++)
	{

		if (isCorrectFile(names[i], ".js") >= 0)
		{
		    //copying the names of the javascript files into the linked list
			node* tmp = malloc(sizeof(tmp));

			if (tmp = NULL)	
			{
				fprintf(stderr, "Error allocating memory");
				return -1;
			}

			node* tmp2 = head;
			tmp->word = malloc(strlen(names[i]) * sizeof(tmp->word));

			if (tmp->word == NULL)
			{
				fprintf(stderr, "Error allocating memory");
				return -1;
			}
			
			strcpy(tmp->word, names[i]);

			if (head == NULL)
			{
				head = tmp;
			}
			else 
			{
				while (tmp2->next != NULL)
				{
					tmp2 = tmp2->next;		
				}
				
				tmp2->next = tmp;
			}
		}
	}
	
	//freeing the names array. It being no longer useful
	for (int i = 0; names[i] != NULL; i++)	free(names[i]);
	free(names);

	return 0;
}






char** getdirectoryentries()
{

	char** dirfiles = malloc(20 * sizeof(dirfiles));
	DIR* workingdir;
	
	for (int i = 0; i < 20; i++)
	{
		*(dirfiles + i) = malloc (MAX_NAME + sizeof(dirfiles));
	}

	if ((workingdir = opendir("./")) == NULL)
	{
		fprintf(stderr, "Error opening directory stream");
		return NULL;	
	}

	struct dirent* direntry; 
	int filenumber = 0;

	while ((direntry = readdir(workingdir)) != NULL)
	{
		char *filename = direntry->d_name;
		int j = 0;
		while(*(filename + j) != '\0')
		{
			*(*(dirfiles + filenumber) + j) = *(filename + j);
			j++;
		}
		*(*(dirfiles + filenumber) + j) = '\0';
		filenumber++;
	}	
	*(dirfiles + filenumber) = NULL;
	return dirfiles;	
}



int isCorrectFile(char* file, char* extension)
{
    int l, i, j;


    //finding length of second string
    for (l = 0; extension[l] != '\0'; l++);

    for (i = 0, j = 0; file[i] != '\0' && extension[j] != '\0'; i++)
    {
        if (file[i] == extension[j])
        {
            j++;
        }
        else
        {
            j = 0;
        }
    }

    if (j == l)
    {
       return i - j + 1;
    }
    else
    {
       return -1; 
    }

}
