#include "Funtions.h"

int main(){

    char op;
    int i = 1, j = 1;
    char title[50], artist[50], playlist[50];
    int duration, year, position;
    int op2, control_load = 0;
    int total;

    Music PL = NULL;//Playlist

    hideCursor();
    MenuOptions(PL, i, j);

    while(1){
        system("color B");
        op = getch();
        switch(op){
            case 80: //down
                i++;
                if(i==9)
                  i=1;
                break;
            case 72: //up
                i--;
                if(i==0)
                  i=8;
                break;
            case 77: //right
                total = musics(PL);
                j++;
                if(j>total)
                    j = 1;

                break;
            case 75: //left
                total = musics(PL);
                j--;
                if(j<1)
                    j = total;

                break;
            case 13://Enter
                if(i==1){ //Add Music
                    showCursor();//
                    system("cls");
                    printf("\tAdd Music\n-------------------------------\n\n");
                    printf("What position: ");
                    scanf("%d", &position);
                    fflush(stdin);
                    printf("\nMusic Information\n-------------------------------\n");
                    printf("\n\tTitle: ");
                    fgets(title, sizeof(title), stdin);
                    title[strcspn(title, "\n")] = '\0';
                    printf("\tArtist: ");
                    fgets(artist, sizeof(artist), stdin);
                    artist[strcspn(artist, "\n")] = '\0';
                    printf("\tDuration: ");
                    scanf("%d",&duration);
                    printf("\tPublication: ");
                    scanf("%d",&year);
                    fflush(stdin);
                    PL = InAnyPlace(PL, title, artist, duration, year, position);
                    printf("\n\nMusic added successfully");
                    printf("\n------------------------------------\n");
                    system("pause");
                    hideCursor();//
                }

                else if(i==2){//Remove Music
                    if(PL == NULL){
                        system("cls");
                        printf("Sorry! No music available right now\n\n-----------------------------------\n");
                        system("pause");
                        system("cls");
                    }else{
                        showCursor();//
                        system("cls");
                        ShowPlaylist(PL);
                        printf("\nRemove the song\n-------------------------------\n");
                        printf("\tTitle: ");
                        fgets(title, sizeof(title), stdin);
                        title[strcspn(title, "\n")] = '\0';
                        printf("\tArtist: ");
                        fgets(artist, sizeof(artist), stdin);
                        artist[strcspn(artist, "\n")] = '\0';
                        PL = Remove(PL, title, artist);
                        system("pause");
                        fflush(stdin);
                        hideCursor();//
                    }
                }

                else if(i==3){ //Play music
                    if(PL == NULL){
                        system("cls");
                        printf("Sorry! No music available right now\n\n-----------------------------------\n");
                        system("pause");
                        system("cls");
                    }else{
                        showCursor();//
                        system("cls");
                        printf("Play the music in what way\n----------------------------\n\n");
                        printf("\t1. Play ascending\n\t2. Play descending\n\nOption: ");
                        scanf("%d", &op2);
                        system("cls");
                        hideCursor();//
                        if(op2 == 1)
                            AscendingOrder(PL);
                        else
                            DescendingOrder(PL);

                      printf("\nEnd of Playlist\n\n-----------------------------\n");
                      system("pause");
                    }
                }

                else if(i==4){ //Search Music
                    if(PL == NULL){
                        system("cls");
                        printf("Sorry! No music available right now\n\n-----------------------------------\n");
                        system("pause");
                        system("cls");
                    }else{
                        showCursor();//
                        system("cls");
                        printf("Search Music\n------------------------------\n\n");
                        printf("1. Search Artist\n\t2. Search Year\n\nOption: ");
                        scanf("%d", &op);

                        if(op == 1){
                            system("cls");
                            printf("Search Artist: ");
                            fgets(artist, sizeof(artist), stdin);
                            artist[strcspn(artist, "\n")] = '\0';
                            searchArtist(PL, artist);
                        }else{
                            system("cls");
                            printf("Year of Publication: ");
                            scanf("%d", &year);
                            system("cls");
                            searchYear(PL, year);
                        }
                        hideCursor();//
                    }
                }
                else if(i==5){ // Playlist Duration
                    if(PL == NULL){
                        system("cls");
                        printf("Sorry! No music available right now\n\n-----------------------------------\n");
                        system("pause");
                        system("cls");
                    }else{
                        system("cls");
                        duration = Duration(PL);
                        printf("\nDuration of the playlist: %02d:%02d:%02d\n", duration/3600, (duration%3600)/60, duration%60);
                        printf("\n------------------------------------\n");
                        system("pause");
                        system("cls");
                    }
                }

                else if(i==6){ // Save Playlist
                    if(PL == NULL){
                        system("cls");
                        printf("Sorry! No music available right now\n\n-----------------------------------\n");
                        system("pause");
                        system("cls");
                    }else{
                        showCursor();//
                        if(control_load == 0){
                            system("cls");
                            printf("Playlist name: ");
                            fgets(playlist, sizeof(playlist), stdin);
                            playlist[strcspn(playlist, "\n")] = '\0';
                            PutInFile(PL, control_load, playlist);
                            playlist[strcspn(playlist, ".")] = '\0';
                            AddPlaylist(playlist);
                        }else{
                            playlist[strcspn(playlist, ".")] = '\0';
                            PutInFile(PL, control_load, playlist);
                            system("cls");
                            printf("Saved!\n\n---------------------------\n");
                            system("pause");
                        }

                        fclose(Playlist);
                        hideCursor();//
                    }
                }

                else if(i==7){ // Load playlist
                    system("cls");
                    ShowPlaylists();
                    showCursor();//
                    printf("\n------------------------------------\n");
                    printf("Playlist name: ");
                    fgets(playlist, sizeof(playlist), stdin);
                    playlist[strcspn(playlist, "\n")] = '\0';
                    strcat(playlist, ".txt");
                    hideCursor();//
                    if(PL != NULL)
                        PL = FreePlaylist(PL);
                    PL = LoadFile(playlist);
                    if(PL != NULL)
                        control_load = 1;
                    else
                        control_load = 0;
                    system("pause");
                }

                else {//Exit
                    system("cls");
                    printf("Thank you for using our program & Come back\n\n");
                    return 0;
                }
                break;


        }

        MenuOptions(PL, i, j);


    }
}
