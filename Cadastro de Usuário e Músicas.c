include <stdio.h>
#include <string.h>

#define TAM_MAX_PLYLST 200
#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15
#define TAM_PLAYLIST 100
#define TAM_TITULO 50
#define TAM_MUSICAS 100

struct Musica {
    int codigo; // autoincremento
    char titulo[TAM_TITULO]; // título da música
    char artista[TAM_NOME]; // nome do artista que canta esta música
};

struct Playlist { 

#define MAX_USUARIOS 100
#define MAX_MUSICAS 1000

void listarMusicas(struct Musica musicas[], int qtdMusicas) {
    for (int i = 0; i < qtdMusicas; i++) {
        printf("Codigo: %d, Titulo: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
    }
}

void consultarMusica(struct Musica musicas[], int qtdMusicas, char *query) {
    for (int i = 0; i < qtdMusicas; i++) {
        if (strstr(musicas[i].titulo, query) != NULL || strstr(musicas[i].artista, query) != NULL || musicas[i].codigo == atoi(query)) {
            printf("Codigo: %d, Titulo: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
        }
    }
}
Funções de Gerenciamento de Playlists

c
Copiar código
void listarPlaylists(struct Playlist playlists[], int qtdPlaylists, struct Usuario usuarios[], int qtdUsuarios) {
    for (int i = 0; i < qtdPlaylists; i++) {
        for (int j = 0; j < qtdUsuarios; j++) {
            if (playlists[i].codUsuario == usuarios[j].codigo) {
                printf("Codigo: %d, Titulo: %s, Criador: %s\n", playlists[i].codigo, playlists[i].titulo, usuarios[j].nome);
                for (int k = 0; k < playlists[i].qtdMusicas; k++) {
                    printf("   Musica %d\n", playlists[i].musicas[k]);
                }
            }
        }
    }
}

Usuario usuarios[MAX_USUARIOS];
Musica musicas[MAX_MUSICAS];
int totalUsuarios = 0;
int totalMusicas = 0;

void menuPrincipal();
void menuAdministrador();
void menuUsuario();
void loginAdministrador();
void loginUsuario();
void cadastrarUsuario();
void listarUsuarios();
void consultarUsuario();
void alterarSenhaUsuario();
void cadastrarMusica();
void listarMusicas();
void consultarMusica();
void alterarMusica();
void excluirMusica();
void listarPlaylists();
void consultarPlaylist();

int main() {
    menuPrincipal();
    return 0;
}


    int codigo; // autoincremento
    int codUsuario; // o código do usuário que criou a playlist
    char titulo[TAM_TITULO]; // título desta playlist
    int qtdMusicas; // qtd atual de músicas incluídas nesta playlist
    int musicas[TAM_MUSICAS]; // vetor contendo os códigos das músicas
};

struct Usuario {
    int codigo; // autoincremento
    char nome[TAM_NOME];
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int qtdPlaylists; // quantid. de playlists criadas pelo usuário
    struct Playlist playlists[TAM_PLAYLIST]; // todas playlists criadas
    int qtdPlaylistsFav; // quantid. de playlists favoritadas pelo usuário
    int playlistsFav[TAM_PLAYLIST]; // códigos das playlists favoritadas pelo usuário
};
#define MAX_USUARIOS 100
#define MAX_MUSICAS 1000

Usuario usuarios[MAX_USUARIOS];
Musica musicas[MAX_MUSICAS];
int totalUsuarios = 0;
int totalMusicas = 0;

void menuPrincipal();
void menuAdministrador();
void menuUsuario();
void loginAdministrador();
void loginUsuario();
void cadastrarUsuario();
void listarUsuarios();
void consultarUsuario();
void alterarSenhaUsuario();
void cadastrarMusica();
void listarMusicas();
void consultarMusica();
void alterarMusica();
void excluirMusica();
void listarPlaylists();
void consultarPlaylist();

int main() {
    menuPrincipal();
    return 0;
}

