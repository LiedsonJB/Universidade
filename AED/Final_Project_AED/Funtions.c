#include "Funtions.h"

// Função para exibir as opções do menu
void MenuOptions(Music PL, int i, int j){
    system("cls"); // Limpa a tela do console

    // Exibe o título do menu
    printf("\tMY PLAYLIST\n------------------------------------\n\n");

    // Loop para exibir as opções do menu
    for(int a = 1; a <= 8; a++){
        if(a == i)
            printf(">>> "); // Indica a opção atualmente selecionada

        // Switch case para exibir cada opção do menu com destaque na opção selecionada
        switch(a){
        case 1: printf("\t%s\n", i == 1 ? "\tADD MUSIC" : "Add Music"); break;//operador ternário
        case 2: printf("\t%s\n", i == 2 ? "\tREMOVE MUSIC" : "Remove Music"); break;
        case 3: printf("\t%s\n", i == 3 ? "\tPLAY MUSIC" : "Play Music"); break;
        case 4: printf("\t%s\n", i == 4 ? "\tSEARCH MUSIC" : "Search Music"); break;
        case 5: printf("\t%s\n", i == 5 ? "\tPLAYLIST DURATION" : "Playlist Duration"); break;
        case 6: printf("\t%s\n", i == 6 ? "\tSAVE PLAYLIST" : "Save Playlist"); break;
        case 7: printf("\t%s\n", i == 7 ? "\tLOAD PLAYLIST" : "Load playlist"); break;
        case 8: printf("\t%s\n", i == 8 ? "\tEXIT" : "Exit"); break;
        }
    }

    // Verifica se a playlist está vazia
    if(PL == NULL){
        printf("\n------------------------------------\n");
        printf("--- NO SONGS TO PLAY, LOAD FIRST --- ");
        printf("\n------------------------------------\n");
    } else {
        // Exibe a música que está tocando
        printf("\n\tMusic is Playing\n------------------------------------\n");
        printf("    <--| %s |-->", Next(PL, j));
        printf("\n------------------------------------\n");
    }
}

// Função para esconder o cursor no console
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

// Função para mostrar o cursor no console
void showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

// Função para construir uma string (aloca espaço)
char* BuildString(char *txt){
    char *str = malloc(sizeof(char) * (strlen(txt) + 1));
    if(!str){
        system("cls");
        system("Color 4");
        printf("\nAllocation Failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(str, txt); // Copia o texto para a nova string alocada dinamicamente
    return str;
}

// Função para inserir uma música em qualquer posição da lista
Music InAnyPlace(Music PL, char *tit, char *art, int du, int ye, int position){
    Music music = malloc(sizeof(struct song));
    if(!music){
        system("cls");
        system("Color 4");
        printf("\nAllocation Failed!\n");
        exit(EXIT_FAILURE);
    }

    // Atribui valores à nova música
    music->title = BuildString(tit);
    music->artist = BuildString(art);
    music->dur = du;
    music->year = ye;
    music->next = NULL;
    music->prev = NULL;

    // Se a playlist estiver vazia, retorna a nova música como a primeira da lista
    if(PL == NULL)
        return music;

    // Inserir na primeira posição
    if (position <= 1) {
        music->next = PL;
        if (PL != NULL) {
            PL->prev = music;
        }
        return music;
    }

    // Encontra a posição correta para inserir a música
    Music cur;
    int i;
    for (cur = PL, i = 1; cur != NULL && i < position - 1; cur = cur->next, i++);

    // Se a posição for maior que a lista, insere no final
    if(cur == NULL)
        for (cur = PL; cur->next != NULL; cur = cur->next);

    music->next = cur->next;
    music->prev = cur;
    cur->next = music;
    if (music->next != NULL){
        music->next->prev = music;
    }
    return PL;
}

// Função para exibir informações de uma música
void ShowMusic(char *title, char *artist){
    printf("\n.Title: %s\n.Artist: %s\n", title, artist);
}

// Função para exibir todas as músicas da playlist
void ShowPlaylist(Music PL){
    Music cur;
    for(cur = PL; cur != NULL; cur = cur->next)
        ShowMusic(cur->title, cur->artist);
}

// Função para salvar a playlist em um arquivo
void PutInFile(Music PL, int c, char *playlist){
    strcat(playlist, ".txt");
    char dir[] = "playlist/";
    strcat(dir, playlist);
    Playlist = fopen(dir, "w+");

    if(!Playlist){
        system("cls");
        system("Color 4");
        printf("\nError to create!\n");
        exit(EXIT_FAILURE);
    }

    // Navega até o final da lista
    Music cur;
    for(cur = PL; cur->next != NULL; cur = cur->next);
    // Escreve a playlist no arquivo, de trás para frente
    for(; cur != NULL; cur = cur->prev)
        fprintf(Playlist, "%s_%s_%d_%d\n", cur->title, cur->artist, cur->dur, cur->year);

    fclose(Playlist);
}

// Função para carregar uma playlist de um arquivo
Music LoadFile(char *playlist){
    //criar diretório
    char dir[] = "playlist/";
    strcat(dir, playlist);
    Playlist = fopen(dir, "r");
    if (!Playlist) {
        system("cls");
        system("Color 4");
        printf("\nError to open or playlist does not exist!\n");
        return NULL;
    }
    Music PL = NULL;
    char tit[30], art[30];
    int dur, yea, a = 1;

    // Lê os dados do arquivo e insere na playlist
    while (fscanf(Playlist, "%[^_]_%[^_]_%d_%d\n", tit, art, &dur, &yea) == 4) {
        PL = InAnyPlace(PL, tit, art, dur, yea, a);
    }

    fclose(Playlist);
    printf("\nSuccessfully loaded!\n");
    return PL;
}

// Função para remover uma música da playlist com base no título e artista
Music Remove(Music PL, char *title, char *artist){
    Music cur;
    // Percorre a playlist
    for(cur = PL; cur != NULL; cur = cur->next) {
        if(strcmp(cur->title, title) == 0 && strcmp(cur->artist, artist) == 0){
            // Se a música a ser removida está na primeira posição
            if(cur->prev == NULL){
                PL = cur->next;
                if (PL != NULL)
                    PL->prev = NULL;
            }
            // Se a música está em qualquer outra posição
            else {
                cur->prev->next = cur->next;
                if (cur->next != NULL)
                    cur->next->prev = cur->prev;
            }
            printf("\nMusic Removed!\n\n------------------------------\n");
            return PL; // Retorna a playlist atualizada
        }
    }
    printf("\nMusic not found!\n\n------------------------------\n");
    return PL; // Retorna a playlist sem alterações se a música não for encontrada
}

// Função para exibir a playlist em ordem crescente (do início ao fim)
void AscendingOrder(Music PL){
    Music cur;
    printf("Playing by Ascending\n---------------------------------\n\n");
    for(cur = PL; cur != NULL; cur = cur->next){
        ShowMusic(cur->title, cur->artist); // Exibe a música
        for(int i = 0; i < 3; i++){
            printf("---");
            Sleep(200); // Pausa para simular a reprodução da música
        }
    }
}

// Função para exibir a playlist em ordem decrescente (do fim ao início)
void DescendingOrder(Music PL){
    Music cur;
    printf("Playing by Descending\n---------------------------------\n\n");
    for(cur = PL; cur->next != NULL; cur = cur->next);
    while(cur != NULL){
        ShowMusic(cur->title, cur->artist); // Exibe a música
        for(int i = 0; i < 3; i++){
            printf("---");
            Sleep(200); // Pausa para simular a reprodução da música
        }
        cur = cur->prev;
    }
}

// Função para liberar a memória alocada para a playlist
Music FreePlaylist(Music PL){
    Music cur = PL;
    Music nextsong;

    while (cur != NULL) {
        nextsong = cur->next;
        free(cur->title); // Libera a memória do título
        free(cur->artist); // Libera a memória do artista
        free(cur); // Libera a memória da estrutura da música
        cur = nextsong;
    }

    PL = NULL; // Define a playlist como vazia
    return PL;
}

// Função para contar o número de músicas na playlist
int musics(Music PL){
    Music cur = PL;
    int cont = 0;
    while(cur != NULL){
        cont++;
        cur = cur->next;
    }
    return cont; // Retorna a contagem de músicas
}

// Função para avançar ou retroceder na playlist
char *Next(Music PL, int j){
    Music cur = PL;
    for(int i = 1; i != j ; i++, cur = cur->next);
    return cur->title; // Retorna o título da música
}

// Função para substituir espaços por underscore em uma string
void replaceSpaces(char *str){
    while (*str) {
        if (*str == ' ') {
            *str = '_'; // Substitui o espaço por string
        }
        str++;
    }
}

// Função para adicionar o nome de uma playlist na coleção de playlists
void AddPlaylist(char *play){
    replaceSpaces(play); // Substitui espaços por underscores
    PLS = fopen("archive.txt", "a+");
    if(!PLS){
        system("Color 4");
        printf("\nError!\n");
        exit(EXIT_FAILURE); //abortar o programa
    }
    fprintf(PLS,"%s\n", play); // Escreve o nome da playlist no arquivo (na coleção)
    fclose(PLS);
}

// Função para exibir todas as playlists salvas da coleção
void ShowPlaylists(){
    PLS = fopen("archive.txt", "r");
    if(!PLS){
        system("Color 4");
        printf("\nError!\n");
        return;
    }
    char PLname[30];
    printf("My PlayLists\n------------------------------------\n\n");
    while(fscanf(PLS, "%29s", PLname) != EOF){
        for (int i = 0; PLname[i] != '\0'; i++)
            if (PLname[i] == '_')
                PLname[i] = ' '; // Substitui undersocres por espaços
        printf("%s\n", PLname); // Exibe o nome da playlist
    }

    fclose(PLS);
}

// Função para procurar músicas de um determinado artista na playlist
void searchArtist(Music PL, char *artist){
    Music cur;
    int control = 0;
    printf("Songs from this artist: %s\n----------------------------------------\n", artist);
    for(cur = PL; cur != NULL; cur = cur->next){
        if(strcmp(cur->artist, artist) == 0){
            printf("%s\n", cur->title); // Exibe o título da música
            control++;
        }
    }
    if(control == 0)
        printf("\nNo Music\n"); // Informa se não encontrou músicas do artista
}

// Função para procurar músicas lançadas em um determinado ano na playlist
void searchYear(Music PL, int year){
    Music cur;
    int control = 0;
    printf("Music published this year %d\n----------------------------------------\n", year);
    for(cur = PL; cur != NULL; cur = cur->next){
        if(year == cur->year){
            ShowMusic(cur->title, cur->artist); // Exibe a música
            control++;
        }
    }
    if(control == 0)
        printf("\nNo Music\n"); // Informa se não encontrou músicas do ano especificado
}

// Função para calcular a duração total da playlist
int Duration(Music PL){
    float soma = 0;
    Music cur = PL;

    while(cur != NULL){
        soma += cur->dur; // Soma a duração das músicas
        cur = cur->next;
    }
    return soma; // Retorna a duração total
}

