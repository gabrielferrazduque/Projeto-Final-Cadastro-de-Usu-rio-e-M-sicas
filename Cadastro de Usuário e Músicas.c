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
#define MAX_USUARIOS 100
#define MAX_MUSICAS 1000

typedef struct {
    int codigo; // autoincremento
    char titulo[TAM_TITULO]; // título da música
    char artista[TAM_NOME]; // nome do artista que canta esta música
} Musica;

typedef struct {
    int codigo; // autoincremento
    int codUsuario; // o código do usuário que criou a playlist
    char titulo[TAM_TITULO]; // título desta playlist
    int qtdMusicas; // qtd atual de músicas incluídas nesta playlist
    int musicas[TAM_MUSICAS]; // vetor contendo os códigos das músicas
} Playlist;

typedef struct {
    int codigo; // autoincremento
    char nome[TAM_NOME];
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int qtdPlaylists; // quantid. de playlists criadas pelo usuário
    Playlist playlists[TAM_PLAYLIST]; // todas playlists criadas
    int qtdPlaylistsFav; // quantid. de playlists favoritadas pelo usuário
    int playlistsFav[TAM_PLAYLIST]; // códigos das playlists favoritadas pelo usuário
} Usuario;

// Variáveis globais
Usuario usuarios[MAX_USUARIOS];
Musica musicas[MAX_MUSICAS];
int totalUsuarios = 0;
int totalMusicas = 0;

// Funções de protótipo
void menuPrincipal();
void menuAdministrador();
void menuUsuario(int usuarioIndex);
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
void listarPlaylistsUsuario(int usuarioIndex);
void listarTodasPlaylists(int usuarioIndex);
void consultarPlaylistsUsuario(int usuarioIndex);
void cadastrarPlaylist(int usuarioIndex);
void inserirMusicaNaPlaylist(int usuarioIndex);
void excluirMusicaDaPlaylist(int usuarioIndex);
void excluirPlaylist(int usuarioIndex);
void favoritarPlaylist(int usuarioIndex);

int main() {
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    int escolha;
    while (1) {
        printf("Bem-vindo ao Sistema de Música\n");
        printf("1. Administrador\n");
        printf("2. Usuário\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                loginAdministrador();
                break;
            case 2:
                loginUsuario();
                break;
            case 3:
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void loginAdministrador() {
    char senha[TAM_SENHA];
    printf("Digite a senha de administrador: ");
    scanf("%s", senha);

    if (strcmp(senha, "m@st3r2024") == 0) {
        menuAdministrador();
    } else {
        printf("Senha incorreta.\n");
    }
}

void loginUsuario() {
    int opcao;
    printf("1. Login\n");
    printf("2. Cadastro\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        char login[TAM_LOGIN], senha[TAM_SENHA];
        printf("Digite o login: ");
        scanf("%s", login);
        printf("Digite a senha: ");
        scanf("%s", senha);

        for (int i = 0; i < totalUsuarios; i++) {
            if (strcmp(usuarios[i].login, login) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
                printf("Login bem-sucedido.\n");
                menuUsuario(i);
                return;
            }
        }
        printf("Login ou senha incorretos.\n");
    } else if (opcao == 2) {
        cadastrarUsuario();
    } else {
        printf("Opção inválida.\n");
    }
}

void cadastrarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuários atingido.\n");
        return;
    }

    Usuario novoUsuario;
    novoUsuario.codigo = totalUsuarios + 1;
    printf("Digite o nome: ");
    scanf("%s", novoUsuario.nome);
    printf("Digite o login: ");
    scanf("%s", novoUsuario.login);
    printf("Digite a senha: ");
    scanf("%s", novoUsuario.senha);
    novoUsuario.qtdPlaylists = 0;
    novoUsuario.qtdPlaylistsFav = 0;

    usuarios[totalUsuarios++] = novoUsuario;
    printf("Usuário cadastrado com sucesso.\n");
}

void menuAdministrador() {
    int escolha;
    while (1) {
        printf("Menu Administrador\n");
        printf("1. Listar Usuários\n");
        printf("2. Consultar Usuário\n");
        printf("3. Alterar Senha de Usuário\n");
        printf("4. Cadastrar Música\n");
        printf("5. Listar Músicas\n");
        printf("6. Consultar Música\n");
        printf("7. Alterar Dados de Música\n");
        printf("8. Excluir Música\n");
        printf("9. Listar Playlists\n");
        printf("10. Consultar Playlist\n");
        printf("11. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                listarUsuarios();
                break;
            case 2:
                consultarUsuario();
                break;
            case 3:
                alterarSenhaUsuario();
                break;
            case 4:
                cadastrarMusica();
                break;
            case 5:
                listarMusicas();
                break;
            case 6:
                consultarMusica();
                break;
            case 7:
                alterarMusica();
                break;
            case 8:
                excluirMusica();
                break;
            case 9:
                listarPlaylists();
                break;
            case 10:
                consultarPlaylist();
                break;
            case 11:
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void listarUsuarios() {
    printf("Lista de Usuários:\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
    }
}

void consultarUsuario() {
    int codigo;
    char login[TAM_LOGIN];
    char nome[TAM_NOME];

    printf("Consultar usuário por:\n");
    printf("1. Código\n");
    printf("2. Login\n");
    printf("3. Parte do Nome\n");
    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o código: ");
            scanf("%d", &codigo);
            for (int i = 0; i < totalUsuarios; i++) {
                if (usuarios[i].codigo == codigo) {
                    printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
                    return;
                }
            }
            printf("Usuário não encontrado.\n");
            break;
        case 2:
            printf("Digite o login: ");
            scanf("%s", login);
            for (int i = 0; i < totalUsuarios; i++) {
                if (strcmp(usuarios[i].login, login) == 0) {
                    printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
                    return;
                }
            }
            printf("Usuário não encontrado.\n");
            break;
        case 3:
            printf("Digite parte do nome: ");
            scanf("%s", nome);
            for (int i = 0; i < totalUsuarios; i++) {
                if (strstr(usuarios[i].nome, nome)) {
                    printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
                }
            }
            break;
        default:
            printf("Opção inválida.\n");
    }
}

void alterarSenhaUsuario() {
    int codigo;
    char novaSenha[TAM_SENHA];
    char confirmacaoSenha[TAM_SENHA];

    printf("Digite o código do usuário: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite a nova senha: ");
            scanf("%s", novaSenha);
            printf("Confirme a nova senha: ");
            scanf("%s", confirmacao
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
void menuAdministrador(struct Usuario usuarios[], int qtdUsuarios, struct Musica musicas[], int qtdMusicas, struct Playlist playlists[], int qtdPlaylists) {
    // Funções específicas do administrador
}

void menuUsuario(struct Usuario *usuario, struct Musica musicas[], int qtdMusicas, struct Playlist playlists[], int qtdPlaylists) {
    // Funções específicas do usuário
}

int main() {
    struct Usuario usuarios[TAM_MAX_PLYLST];
    struct Musica musicas[TAM_MAX_PLYLST];
    struct Playlist playlists[TAM_MAX_PLYLST];

    int qtdUsuarios = 0, qtdMusicas = 0, qtdPlaylists = 0;
    int opcao;
    char senha[TAM_SENHA];

    while (1) {
        printf("Escolha o tipo de usuário:\n1. Administrador\n2. Usuário\n3. Sair\n");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Digite a senha de administrador: ");
            scanf("%s", senha);
            if (strcmp(senha, "m@st3r2024") == 0) {
                menuAdministrador(usuarios, qtdUsuarios, musicas, qtdMusicas, playlists, qtdPlaylists);
            } else {
                printf("Senha incorreta!\n");
            }
        } else if (opcao == 2) {
            int logado = 0;
            while (!logado) {
                printf("1. Login\n2. Cadastro\n3. Voltar\n");
                scanf("%d", &opcao);
                if (opcao == 1) {
                    char login[TAM_LOGIN], senha[TAM_SENHA];
                    printf("Login: ");
                    scanf("%s", login);
                    printf("Senha: ");
                    scanf("%s", senha);
                    for (int i = 0; i < qtdUsuarios; i++) {
                        if (strcmp(usuarios[i].login, login) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
                            menuUsuario(&usuarios[i], musicas, qtdMusicas, playlists, qtdPlaylists);
                            logado = 1;
                            break;
                        }
                    }
                    if (!logado) {
                        printf("Login ou senha incorretos!\n");
                    }
                } else if (opcao == 2) {
                    struct Usuario novoUsuario;
                    novoUsuario.codigo = qtdUsuarios + 1;
                    printf("Nome: ");
                    scanf("%s", novoUsuario.nome);
                    printf("Login: ");
                    scanf("%s", novoUsuario.login);
                    printf("Senha: ");
                    scanf("%s", novoUsuario.senha);
                    usuarios[qtdUsuarios++] = novoUsuario;
                } else {
                    break;
                }
            }
        } else {
            break;
        }
    }

    return 0;
}
