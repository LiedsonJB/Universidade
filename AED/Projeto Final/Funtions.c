#include "Funtions.h"

void MenuOptions(Music PL, int i, int j){
    system("cls");

    printf("\tMY PLAYLIST\n------------------------------------\n\n");
    for(int a=1; a<=8; a++){
        if(a==i)
            printf(">>> ");

        switch(a){
        case 1: printf("%s\n", i==1?"ADD MUSIC":"Add Music"); break;
        case 2: printf("%s\n", i==2?"REMOVE MUSIC":"Remove Music"); break;
        case 3: printf("%s\n", i==3?"PLAY MUSIC":"Play Music"); break;
        case 4: printf("%s\n", i==4?"SEARCH MUSIC":"Search Music"); break;
        case 5: printf("%s\n", i==5?"PLAYLIST DURATION":"Playlist Duration"); break;
        case 6: printf("%s\n", i==6?"SAVE PLAYLIST":"Save Playlist"); break;
        case 7: printf("%s\n", i==7?"LOAD PLAYLIST":"Load playlist"); break;
        case 8: printf("%s\n", i==8?"EXIT":"Exit"); break;
        }
    }

    if(PL == NULL){
        printf("\n------------------------------------\n");
        printf("--- NO SONGS TO PLAY, LOAD FIRST --- ");
        printf("\n------------------------------------\n");
    }else{
        printf("\n\tMusic is Playing\n------------------------------------\n");
        printf("    <--| %s |-->", Next(PL, j));
        printf("\n------------------------------------\n");
    }
}

void hideCursor() {

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void showCursor() {

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

char* BuildString(char *txt){
    char *str = malloc(sizeof(char) * (strlen(txt) + 1));
    if(!str){
        system("cls");
        system("Color 4");
        printf("\nAlocation Failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(str, txt);
    return str;
}

Music InAnyPlace(Music PL, char *tit, char *art, int du, int ye, int position){
    Music music = malloc(sizeof(struct song));
    if(!music){
        system("cls");
        system("Color 4");
        printf("\nAlocation Failed!\n");
        exit(EXIT_FAILURE);
    }

    music->title = BuildString(tit);
    music->artist = BuildString(art);
    music->dur = du;
    music->year = ye;
    music->next = NULL;
    music->prev = NULL;

    if(PL == NULL)
        return music;

    if (position <= 1) {  // Inserir na primeira posição
        music->next = PL;
        if (PL != NULL) {
            PL->prev = music;
        }
        return music;
    }

    Music cur;
    int i;
    for (cur = PL, i = 1; cur != NULL && i < position - 1; cur = cur->next, i++); //got to the position

    if(cur == NULL) //the position is greater than the list
        for (cur = PL; cur->next != NULL; cur = cur->next);//go to the end of list

    music->next = cur->next;
    music->prev = cur;
    cur->next = music;
    if (music->next != NULL){
        music->next->prev = music;
    }
    return PL;

}

void ShowMusic(char *title, char *artist){
    printf("\n.Title: %s\n.Artist: %s\n", title, artist);
}

void ShowPlaylist(Music PL){
    Music cur;
    for(cur=PL; cur!=NULL; cur=cur->next)
        ShowMusic(cur->title, cur->artist);
}

void PutInFile(Music PL, int c, char *playlist){
    strcat(playlist, ".txt");
    char dir[] = "playlist/";
    strcat(dir, playlist);
    Playlist = fopen(dir, "w+");

    if(!Playlist){
        system("cls");
        system("calor 4");
        printf("\nError to create!\n");
        exit(EXIT_FAILURE);
    }
    Music cur;
    for(cur=PL; cur->next != NULL; cur=cur->next);
    for(; cur != NULL; cur=cur->prev)
        fprintf(Playlist, "%s%c%s%c%d%c%d\n", cur->title, '_', cur->artist, '_', cur->dur, '_', cur->year);

}

Music LoadFile(char *playlist){
    char dir[] = "playlist/";
    strcat(dir, playlist);
    FILE *Playlist = fopen(dir, "r");
    if (!Playlist) {
        system("cls");
        system("Color 4");
        printf("\nError to open or playlist do not exist!\n");
        return;
    }
    Music PL = NULL;
    char tit[30], art[30];
    int dur, yea, a=1;

    while (fscanf(Playlist, "%[^_]_%[^_]_%d_%d\n", tit, art, &dur, &yea)==4) {
        PL = InAnyPlace(PL, tit, art, dur, yea, a);
    }

    fclose(Playlist);
    printf("\nSuccessfuly loaded!\n");
    return PL;
}

Music Remove(Music PL, char *title, char *artist){
    Music cur;
    for(cur=PL;cur != NULL; cur=cur->next)
        if(strcmp(cur->title, title) == 0 && strcmp(cur->artist, artist) == 0){
            if(cur->prev ==  NULL){//first position
                PL= cur->next;
                if (PL != NULL)
                    PL->prev = NULL;
            }
            else{//any position
                cur->prev->next = cur->next;
                if (cur->next != NULL)
                    cur->next->prev = cur->prev;
            }
        printf("\nMusic Removed!\n\n------------------------------\n");
        return PL;
    }

    printf("\nMusic not found!\n\n------------------------------\n");
    return PL;

}

void AscendingOrder(Music PL){
    Music cur;
    printf("Playing by Ascending\n---------------------------------\n\n");
    for(cur=PL; cur!=NULL; cur=cur->next){
        ShowMusic(cur->title, cur->artist);
        for(int i=0; i<10; i+=2){
            printf("--");
            sleep(0,25);
        }
    }
}

void DescendingOrder(Music PL){
    Music cur;
    printf("Playing by Descending\n---------------------------------\n\n");
    for(cur=PL; cur->next!=NULL; cur=cur->next);
    while(cur!=NULL){
        ShowMusic(cur->title, cur->artist);
       for(int i=0; i<10; i+=2){
            printf("--");
            sleep(0.25);
        }
        cur=cur->prev;
    }
}

Music FreePlaylist(Music PL){
    Music cur = PL;
    Music nextsong;

    while (cur != NULL) {
        nextsong = cur->next;
        free(cur->title);
        free(cur->artist);
        free(cur);
        cur = nextsong;
    }

    PL = NULL;
    return PL;
}

int musics(Music PL){
    Music cur = PL;
    int cont = 0;
    while(cur != NULL){
        cont++;
        cur = cur->next;
    }
    return cont;
}

char *Next(Music PL, int j){
    Music cur = PL;
    for(int i = 1; i!=j ; i++, cur=cur->next);
        return cur->title;
}

void replaceSpaces(char *str){
    while (*str) {
        if (*str == ' ') {
            *str = '_';
        }
        str++;
    }
}

void AddPlaylist(char *play){
    replaceSpaces(play);
    PLS = fopen("archive.txt", "a+");
    if(!PLS){
        system("Color 4");
        printf("\nError!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(PLS,"%s\n", play);
    fclose(PLS);
}

void ShowPlaylists(){
    PLS = fopen("archive.txt", "r");
    if(!PLS){
        system("Color 4");
        printf("\nError!\n");
        return;
    }
    char PLname[30];
    printf("My PlayLists\n------------------------------------\n\n");
    while(fscanf(PLS, "%29s", PLname)!= EOF){
        for (int i = 0; PLname[i] != '\0'; i++)
            if (PLname[i] == '_')
                PLname[i] = ' ';
        printf("%s\n", PLname);
    }

    fclose(PLS);
}

void searchArtist(Music PL, char *artist){
    Music cur;
    printf("Songs from this artist%d\n----------------------------------------\n", artist);
    for(cur = PL; cur != NULL; cur = cur->next){
        if(strcmp(cur->artist, artist)==0){
            printf("%s\n", cur->title);
        }
    }
}

void searchYear(Music PL, int year){
    Music cur;
    printf("Music published this year %d\n----------------------------------------\n", year);
    for(cur = PL; cur != NULL; cur = cur->next){
        if(year == cur->year){
            ShowMusic(cur->title, cur->artist);
        }
    }
}

int Duration(Music PL){
    float soma = 0;
    Music cur = PL;

    while(cur != NULL){
        soma = soma + cur->dur;
        cur = cur->next;
    }
    return soma;
}
