#ifndef FUNTIONS_H_INCLUDED
#define FUNTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>//utilizacao das funcoes do API do Windows

//Estrutura de uma musica
typedef struct song{
    char *title;
    char *artist;
    int dur;
    int year;

    struct song *next;
    struct song *prev;

}*Music; //Ponteiro para a estrutura song

FILE *Playlist; //as playlists
FILE *PLS; // coleção de playlists

void MenuOptions(Music PL, int i, int j);
void hideCursor();
void showCursor();
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
void ShowPlaylist(Music PL);
void searchYear(Music PL, int year);
void searchArtist(Music PL, char *artist);
void replaceSpaces(char *str);


#endif // FUNTIONS_H_INCLUDED
