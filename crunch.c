//CS 320 Christian Caeg Monday and Wendesday

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int size = 4;
int NUM_SENT = 1;
int spacies = 0;
int wordMin = 6;

int main(int argc, char *argv[]) {
    static char words[540000][25];
    FILE *file;
    int i, j;
    int values[100];
    int booly = 0;
    int counter = 0;

    size_t cnt, n;
    char word[25];

    int last = argc - 1;
    char* filename = argv[last];

    srand(time(NULL));
    file = fopen(filename, "r");
    if (file == NULL){
        printf("The file cannot be opened.\n");
        return 1;
    }
    cnt = 0;
    while(1==fscanf(file, "%24s", word)){
        if(cnt == 540000)
            break;
        strcpy(words[cnt++], word);
    }
    fclose(file);
    n = cnt;


    for (int i = 1; i< argc; i++){
        if (strcmp(argv[i], "-d") == 0)
        {
            int newMaxWords = atoi(argv[i+1]);

            size = newMaxWords;
        }

        if (strcmp(argv[i], "-m") == 0)
        {
            int newMinChar = atoi(argv[i+1]);

            wordMin = newMinChar;
        }

        if (strcmp(argv[i], "-n") == 0)
        {
            int newMaxSent = atoi(argv[i+1]);
            NUM_SENT = newMaxSent;
        }

        if (strcmp(argv[i], "-s") == 0)
        {
            spacies = spacies + 1;
        }
    }

    for ( int r = 0; r < NUM_SENT; r++){
        for(int q = 0; q < size;) {

            int random;

            // generates a random number
            random = rand() % n;

            // picks a random number and stores it in an array
            values[counter] = random;
            counter++;

            int temp = 0;
            int wordSize = 0;

            char *pointedWord = words[random];

            while (*(pointedWord + temp))
            {
                temp++;
                wordSize++;
            }


            if (wordSize < wordMin){
                random = rand() % n;
                do{
                    random = rand() % n;

                    char *pointedWord = words[random];

                    while (*(pointedWord + temp))
                    {
                        temp++;
                        wordSize++;
                    }
                }
                while (wordSize < wordMin);
            }


            // prints the first number
            if (q == 0){
                printf("%s", words[random]);
                q++;

                if(spacies == 1){
                    printf(" ");
                }
            }

            if (q != 0){
                for(int w = 0; w < size; w++){
                    if (values[w] == random){
                        booly = 1;
                    }
                }



                if (booly == 0) {
                    printf("%s", words[random]);
                    q++;

                    if(spacies == 1){
                        printf(" ");
                    }
                }
                booly = 0;
            }

        }

        printf("\n");
    }
    return 0;

}