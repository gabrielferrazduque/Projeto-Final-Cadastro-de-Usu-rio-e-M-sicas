# Projeto-Final-Cadastro-de-Usu-rio-e-M-sicas
Projeto Final  Cadastro de Usuário e Músicas
#include <stdio.h>
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
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

    
};

struct Playlist {
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
