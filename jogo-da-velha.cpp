#include <iostream>
using namespace std;

void init(int tabuleiro[][3]);
char montaJogada(int partida);
void show(int tabuleiro[][3]);
void jogada(int tabuleiro[][3], int);
int checaJogada(int *tabuleiro[3]);
int checaVencedor(int *tabuleiro[3]);
int jogo(int tabuleiro[][3]);

int main()
{
    int tabuleiro[3][3];

    int cont = 0;
    do
    {
        init(tabuleiro);
        jogo(tabuleiro);

        cout << "\n Outra partida?" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Jogar de novo" << endl;
        cin >> cont;
    } while (cont);

    return 0;
}

void init(int tabuleiro[][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = 0;
}

char montaJogada(int partida)
{
    if (partida == 0)
        return ' ';
    else if (partida == 1)
        return 'X';
    else
        return 'O';
}

void show(int tabuleiro[][3])
{
    cout << endl;
    for (int row = 0; row < 3; row++)
    {
        cout << " " << montaJogada(tabuleiro[row][0]) << " |";
        cout << " " << montaJogada(tabuleiro[row][1]) << " |";
        cout << " " << montaJogada(tabuleiro[row][2]) << endl;

        if (row != 2)
        {
            cout << "___ ___ ___\n"
                 << endl;
        }
    }
}

void jogada(int tabuleiro[][3], int jogador)
{
    int row, col, check;
    do
    {
        cout << "Linha: ";
        cin >> row;
        cout << "Coluna: ";
        cin >> col;
        row--;
        col--;

        check = tabuleiro[row][col] || row < 0 || row > 2 || col < 0 || col > 2;
        if (check)
            cout << "Essa casa não está vazia ou fora do intervalo 3x3" << endl;

    } while (check);

    if (jogador == 0)
        tabuleiro[row][col] = 1;
    else
        tabuleiro[row][col] = -1;
}

int checaJogada(int tabuleiro[][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tabuleiro[i][j] == 0)
                return 1;
    return 0;
}

int checaVencedor(int tabuleiro[][3])
{
    int row, col, sum;

    for (row = 0; row < 3; row++)
    {
        sum = 0;

        for (col = 0; col < 3; col++)
            sum += tabuleiro[row][col];

        if (sum == 3)
            return 1;
        if (sum == -3)
            return -1;
    }

    for (col = 0; col < 3; col++)
    {
        sum = 0;

        for (row = 0; row < 3; row++)
            sum += tabuleiro[row][col];

        if (sum == 3)
            return 1;
        if (sum == -3)
            return -1;
    }

    sum = 0;
    for (row = 0; row < 3; row++)
        sum += tabuleiro[row][row];
    if (sum == 3)
        return 1;
    if (sum == -3)
        return -1;

    sum = tabuleiro[0][2] + tabuleiro[1][1] + tabuleiro[2][0];
    if (sum == 3)
        return 1;
    if (sum == -3)
        return -1;

    return 0;
}

int jogo(int tabuleiro[][3])
{
    int turn = 0, cont, win;

    do
    {
        show(tabuleiro);
        cout << "Jogador " << 1 + turn % 2 << endl;
        jogada(tabuleiro, turn % 2);
        turn++;

        cont = checaJogada(tabuleiro);
        win = checaVencedor(tabuleiro);
    } while (cont && !win);

    show(tabuleiro);

    if (win == 1)
    {
        cout << "Jogador 1 ganhou!\n"
             << endl;
        return 1;
    }
    else if (win == -1)
    {
        cout << "Jogador 2 ganhou!\n"
             << endl;
        return 2;
    }
    else
        cout << "Empate\n"
             << endl;

    return 0;
}