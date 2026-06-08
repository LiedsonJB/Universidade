#ifndef FUNTIONS_H_INCLUDED
#define FUNTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <windows.h>

typedef struct song{
    char *title;
    char *artist;
    int dur;
    int year;

    struct song *next;
    struct song *prev;

}*Music;

FILE *Playlist;
FILE *PLS;

void MenuOptions(Music PL, int i, int j);
void hideCursor();
char* BuildString(char *txt);
int Duration(Music PL);
Music InAnyPlace(Music PL, char *tit, char *art, int du, int ye, int position);
void PutInFile(Music PL, int c, char *playlist);
Music LoadFile(char *playlist);
Music Remove(Music PL, char *title, char *artist);
void AscendingOrder(Music PL);
void DescendingOrder(Music PL);
Music FreePlaylist(Music PL);
int musics(Music PL);
char *Next(Music PL, int j);
void AddPlaylist(char *play);
void ShowPlaylists();
void ShowMusic(char *title, char *artist);
void searchYear(Music PL, int year);
void searchArtist(Music PL, char *artist);


#endif // FUNTIONS_H_INCLUDED
