#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
void escreverCriar();
void lerDados();
void lerDadosDois();

int main() {
    // escreverCriar();
    // lerDados();
    lerDadosDois();

    return 0;
}

void escreverCriar() {
    // rtx é meu ponteiro, nome genérico
    FILE *escrever;

    // Faz o ponteiro apontar para um arquivo
    escrever = fopen("D:\\pastinha\\numero.txt", "w"); // "r" = ler | "w" = escrever | "a" = adicionar

    // Como a barra invertida tem outras funções em C, para isso funcionar você tem que colocar duas barras invertidas: "D:\\pasta\\..."
    // Se você não especificar onde vai estar o arquivo e deixar apenas o nome, ele vai criar o arquivo de texto no diretório onde o programa está salvo

    fprintf(escrever, "10 20 30"); // Se eu mudar esse conteúdo e rodar o código, o novo texto sobrescreve o antigo

    // Note que sempre que vamos fazer algum comando com arquivos .txt, as funções são parecidas, mas começam com "f" — por exemplo: fopen(), fprintf()
    // O printf que já usávamos, agora com 'f' no começo, pode ser entendido como "File Printf"

    fclose(escrever);
}

void lerDados() {
    FILE *ler;

    // Pode mudar o nome do arquivo para ver o resultado
    ler = fopen("D:\\pastinha\\numero.txt", "r");

    // Vamos supor agora que você tente ler um arquivo que não existe, por exemplo "numeros.txt"
    // O programa não vai encontrar esse arquivo, e a resposta pode ser o último resultado lido (se o conteúdo anterior estiver em memória, ou erro mesmo)

    // Para resolver isso, usamos uma verificação com "NULL"
    // Se o ponteiro não estiver apontando para lugar nenhum, o arquivo não existe ou não pode ser aberto
    if (ler == NULL) {
        printf("Arquivo não pode ser aberto\n");
        system("pause");
        return;
    }

    int x, y, z; // Criei três variáveis

    // Continua igual ao "scanf", mas com uma pequena alteração: temos que informar o ponteiro (no caso, "ler")
    fscanf(ler, "%i %i %i", &x, &y, &z);

    printf("%i %i %i\n", x, y, z);

    fclose(ler);
    system("pause");
}

void lerDadosDois() {
    // Aqui vamos ver como lidar com a limitação do "scanf", que precisa dos dados bem formatados para funcionar

    FILE *ler;
    ler = fopen("D:\\pastinha\\string.txt", "r");

    if (ler == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        getchar();
        exit(0);
    }

    // Aqui nós criamos um vetor de caracteres
    char frase[100];

    // "fgets" pode ser entendido como FILE-get-String
    // "fgets" recebe três parâmetros: o vetor (frase), o tamanho e o ponteiro
    // "!= NULL" quer dizer que queremos que o while funcione enquanto conseguir ler uma linha
    while (fgets(frase, 100, ler) != NULL) {
        printf("%s", frase);
    }

    fclose(ler);
    printf("\n");
    system("pause");

    // Recomendo você até fazer testes — um muito divertido é usar ASCII Art.
    // Cole ela no arquivo de texto e rode o código para ver no terminal.
    // Link: https://ascii-art.botecodigital.dev.br/#ascii-convertido
}
