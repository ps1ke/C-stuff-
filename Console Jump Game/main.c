#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int main()
{
    char lineGround[] = "                              ";
    char lineAir[] = "                              ";
    time_t start = time(NULL);
    int score = 1;
    int numberObs = 1;
    int gameRunning = 1;
    int pressedFor = -1;
    int moreScore = 0;
    while (1){
		Sleep(30);
        if(gameRunning){
            time_t now = time(NULL);
            score = difftime(now, start) + 1 + moreScore;
            lineAir[0] = 32;
            lineGround[0] = 32;
            if(numberObs){
                int z;
                for(z = 0; z < 28; z++){
                    if(lineGround[z + 1] == 124){
                        lineGround[z] = 124;
                        lineGround[z + 1] = lineGround[z + 2];
                    } else{
                        lineGround[z] = 32;
            }}}
            if(kbhit()){
                switch(getche()){
                case 32:
                    if(pressedFor < 0){
                        pressedFor = 10;
            }}}
            if(pressedFor > 1){
                lineAir[0] = 64;
            } else{
                lineGround[0] = 64;
            }
            int obsProb;
            if(lineGround[28] != 124){
                lineGround[28] = 0;
                obsProb = rand() % 30;
                if (obsProb < 2 && numberObs < 4){
                    srand(time(NULL));
                    lineGround[28] = 124;
                    numberObs++;
                }
            }
            if(lineGround[3] == 124){
                numberObs += -1;
            }
            system("cls");
            printf("Score: %d \n\n\n\n", score);
            printf("\n%s\n", lineAir);
            printf(lineGround);
            printf("\n______________________________");
            pressedFor += -1;
            if((lineGround[1] == 124) && (lineAir[0] == 64)){
                moreScore += 100;
            }
            if((lineGround[1] == 124) && (lineGround[0] == 64)){
                gameRunning = 0;
        }} else{
            system("cls");
            printf("GAME OVER!! SCORE: %d \nTYPE ENTER TO RESTART!", score);
            score = 0;
            moreScore = 0;
            if(getchar()){
                start = time(NULL);
                gameRunning = 1;
    }}}
    return 0;
}
