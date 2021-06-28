#include "jogo.h"

using namespace std;

int menu();
int menuAcoes();
void escolherPersonagem(Personagem &p, int jogador);
int usarMagia(char codMagia, Personagem &p2, Personagem &p1);
char menuMagias(Personagem &p);
int usarArma(char codArma, Personagem &p2, Personagem &p1);
char menuArmas(Personagem &p, int bK);
int bulKathos();
string getMagia(char magia);
string getArma(char arma);

bool salvar = false;
ofstream arq;
string nomeArquivo;

int main()
{
    system("cls");
    int op;
    Personagem p1;
    Personagem p2;

    cout << "\n RPG GAME ";

    op = menu();

    while (op != 2)
    {
        if (op == 1)
        {
            int opS;
            cout << "\nDeseja salvar ?\n\n1 - Sim\n2 - Nao";
            cout << "\n\nOpcao escolhida: ";
            cin >> opS;

            while (opS > 2 || opS < 1)
            {
                cout << "\n\nOpcao invalida, insira novamente: ";
                cin >> opS;
            }

            while (opS == 1)
            {
                salvar = true;

                string txt;

                cout << "\nInsira um nome para o arquivo de texto (sem espacos): ";
                cin >> txt;

                nomeArquivo = txt + ".txt";

                arq.open(nomeArquivo, ios::app);

                if (!(arq.is_open()))
                {
                    cout << "\nAlgo deu errado, tentar novamente?\n\n1 - Sim, quero ativar o modo salvar\n2 - Nao, nao quero salvar";
                    cout << "\nOpcao escolhida: ";
                    cin >> opS;

                    while (opS > 2 || opS < 1)
                    {
                        cout << "Opcao invalida, insira novamente: ";
                        cin >> opS;
                    }
                }
                else
                {
                    arq << "REGISTRO DE BATALHA\n\n";
                    arq.close();
                    opS = 0;
                }
            }

            if (opS == 2)
            {
                salvar = false;
            }

            escolherPersonagem(p1, 1);

            escolherPersonagem(p2, 2);

            if (salvar)
            {
                arq.open(nomeArquivo, ios::app);

                arq << "* * * * ATRIBUTOS JOGADOR 1 * * * *";
                arq << "\n\nClasse: " << p1.getClasse();
                arq << "\nNome: " << p1.getNome();
                arq << "\nVida Maxima: " << p1.getVidaMax();
                arq << "\nMana Maxima: " << p1.getManaMax();
                arq << "\nEnergia Maxima: " << p1.getEnergiaMax();
                arq << "\nForca fisica: " << p1.getFisica();
                arq << "\nForca magica: " << p1.getMagica();
                arq << "\nArmadura: " << p1.getResistFisica();
                arq << "\nResistencia magica: " << p1.getResistMagica();
                arq << "\nAgilidade: " << p1.getAgilidade();

                arq << "\n\n* * * * ATRIBUTOS JOGADOR 2 * * * *";
                arq << "\n\nClasse: " << p2.getClasse();
                arq << "\nNome: " << p2.getNome();
                arq << "\nVida Maxima: " << p2.getVidaMax();
                arq << "\nMana Maxima: " << p2.getManaMax();
                arq << "\nEnergia Maxima: " << p2.getEnergiaMax();
                arq << "\nForca fisica: " << p2.getFisica();
                arq << "\nForca magica: " << p2.getMagica();
                arq << "\nArmadura: " << p2.getResistFisica();
                arq << "\nResistencia magica: " << p2.getResistMagica();
                arq << "\nAgilidade: " << p2.getAgilidade();

                arq.close();
            }

            int turno = 1, jogador = 1, acao, op2, bK;

            int vida1 = 1, vida2 = 1, contAcoes;

            while (vida1 > 0 && vida2 > 0)
            {
                cout << "\n\n";
                system("pause");
                system("cls");

                cout << "\n\n* * * * TURNO " << turno << " * * * *";
                if (salvar)
                {
                    arq.open(nomeArquivo, ios::app);
                    arq << "\n\n* * * * TURNO " << turno << " * * * *";
                    arq.close();
                }
                turno++;
                contAcoes = 1;

                while (contAcoes <= 2 && vida1 > 0 && vida2 > 0)
                {

                    if (jogador == 1)
                    {
                        bK = bulKathos();
                        cout << "\n\n"
                             << p1.getNome() << ", escolha sua acao.";

                        if (salvar)
                        {
                            arq.open(nomeArquivo, ios::app);
                            arq << "\n\nVez de agir: "
                                << p1.getNome();

                            arq << "\nVida atual: " << p1.getVida() << "/" << p1.getVidaMax();
                            arq << "\nMana atual: " << p1.getMana() << "/" << p1.getManaMax();
                            arq << "\nEnergia atual: " << p1.getEnergia() << "/" << p1.getEnergiaMax();

                            arq.close();
                        }

                        if (bK)
                        {
                            cout << "\n\n* * * * Voce recebeu a bencao de Bul-Kathos! * * * *\nNesse turno voce tem acesso a Espada Lendaria Voto Solene de Bul-Kathos nas opcoes de Armas!";

                            if (salvar)
                            {
                                arq.open(nomeArquivo, ios::app);
                                arq << "\n\n* * * * " << p1.getNome() << " recebeu a bencao de Bul-Kathos! * * * *";

                                arq.close();
                            }
                        }
                        cout << "\n\nVida atual: " << p1.getVida() << "/" << p1.getVidaMax();
                        cout << "\nMana atual: " << p1.getMana() << "/" << p1.getManaMax();
                        cout << "\nEnergia atual: " << p1.getEnergia() << "/" << p1.getEnergiaMax();
                    }
                    else
                    {
                        bK = bulKathos();
                        cout << "\n\n"
                             << p2.getNome() << ", escolha sua acao.";

                        if (salvar)
                        {
                            arq.open(nomeArquivo, ios::app);
                            arq << "\n\nVez de agir: "
                                << p2.getNome();

                            arq << "\nVida atual: " << p2.getVida() << "/" << p2.getVidaMax();
                            arq << "\nMana atual: " << p2.getMana() << "/" << p2.getManaMax();
                            arq << "\nEnergia atual: " << p2.getEnergia() << "/" << p2.getEnergiaMax();

                            arq.close();
                        }
                        if (bK)
                        {
                            cout << "\n\n* * * * Voce recebeu a bencao de Bul-Kathos! * * * *\nNesse turno voce tem acesso a Espada Lendaria Voto Solene de Bul-Kathos nas opcoes de Armas!";
                            if (salvar)
                            {
                                arq.open(nomeArquivo, ios::app);
                                arq << "\n\n* * * * " << p2.getNome() << " recebeu a bencao de Bul-Kathos! * * * *";

                                arq.close();
                            }
                        }
                        cout << "\n\nVida atual: " << p2.getVida() << "/" << p2.getVidaMax();
                        cout << "\nMana atual: " << p2.getMana() << "/" << p2.getManaMax();
                        cout << "\nEnergia atual: " << p2.getEnergia() << "/" << p2.getEnergiaMax();
                    }

                    acao = menuAcoes();
                    contAcoes++;

                    while (acao == 4)
                    {
                        cout << "\nDeseja sair e perder todo o progresso do jogo?\n\n1 - Prosseguir\n2 - Cancelar\n";
                        cout << "\nOpcao escolhida: ";
                        cin >> op2;

                        while (op2 > 2 || op2 < 1)
                        {
                            cout << "\n\nOpcao invalida, insira novamente: ";
                            cin >> op2;
                        }

                        if (op2 == 1)
                        {
                            cout << "\n\n* * * * FIM DE JOGO * * * *\n\nVoce perdeu por W.O!\nVencedor: ";
                            cout << "\n\n* * * * * * * *";

                            if (jogador == 1)
                            {
                                cout << p2.getNome();
                            }
                            else
                            {
                                cout << p1.getNome();
                            }

                            if (salvar)
                            {
                                arq.open(nomeArquivo, ios::app);
                                if (jogador == 1)
                                {
                                    arq << "\n\n* * * * FIM DE JOGO * * * *\n\n" << p1.getNome();
                                }
                                else
                                {
                                    arq << p2.getNome();
                                }

                                arq << " abandonou o jogo e perdeu por W.O!\nVencedor: ";

                                if (jogador == 1)
                                {
                                    arq << p2.getNome();
                                }
                                else
                                {
                                    arq << p1.getNome();
                                }
                                arq.close();
                            }

                            return 0;
                        }
                        else
                        {
                            acao = menuAcoes();
                        }
                    }

                    int diferenca = 0, vidaAntes = 0, verifica = 0;

                    if (acao == 1)
                    {
                        char magia;

                        if (jogador == 1)
                        {

                            magia = menuMagias(p1);
                            if (magia == 's')
                            {
                                acao = 10;
                            }
                            else
                            {
                                if (magia != 'c' && magia != 'p')
                                {
                                    vidaAntes = p2.getVida();
                                    verifica = usarMagia(magia, p1, p2);

                                    if (verifica)
                                    {
                                        diferenca = vidaAntes - p2.getVida();
                                        cout << "\n\n"
                                             << p1.getNome() << " usou a magia " << getMagia(magia) << " e "
                                             << p2.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p1.getNome() << " usou a magia " << getMagia(magia) << " e "
                                                << p2.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                            arq.close();
                                        }
                                    }
                                    else
                                    {
                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p1.getNome() << "tentou usar a magia " << getMagia(magia) << " mas nao possui mana suficiente.";
                                            arq.close();
                                        }
                                        acao = 10;
                                    }
                                }
                                else
                                {
                                    vidaAntes = p1.getVida();
                                    verifica = usarMagia(magia, p1, p2);

                                    if (verifica)
                                    {
                                        diferenca = p1.getVida() - vidaAntes;
                                        cout << "\n\n"
                                             << p1.getNome() << " usou a magia " << getMagia(magia)
                                             << " e curou " << diferenca << " de vida!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p1.getNome() << " usou a magia " << getMagia(magia)
                                                << " e curou " << diferenca << " de vida!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                            arq.close();
                                        }
                                    }
                                    else
                                    {
                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p1.getNome() << "tentou usar a magia " << getMagia(magia) << " mas nao possui mana suficiente.";
                                            arq.close();
                                        }
                                        acao = 10;
                                    }
                                }
                            }
                        }
                        else
                        {
                            magia = menuMagias(p2);

                            if (magia == 's')
                            {
                                acao = 10;
                            }
                            else
                            {
                                if (magia != 'c' && magia != 'p')
                                {
                                    vidaAntes = p1.getVida();
                                    verifica = usarMagia(magia, p2, p1);

                                    if (verifica)
                                    {
                                        diferenca = vidaAntes - p1.getVida();

                                        cout << "\n\n"
                                             << p2.getNome() << " usou a magia " << getMagia(magia) << " e "
                                             << p1.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p2.getNome() << " usou a magia " << getMagia(magia) << " e "
                                                << p1.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                            arq.close();
                                        }
                                    }
                                    else
                                    {
                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p2.getNome() << " tentou usar a magia " << getMagia(magia) << " mas nao possui mana suficiente.";
                                            arq.close();
                                        }
                                        acao = 10;
                                    }
                                }
                                else
                                {
                                    vidaAntes = p2.getVida();
                                    verifica = usarMagia(magia, p2, p1);

                                    if (verifica)
                                    {
                                        diferenca = p2.getVida() - vidaAntes;
                                        cout << "\n\n"
                                             << p2.getNome() << " usou a magia " << getMagia(magia)
                                             << " e curou " << diferenca << " de vida!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p2.getNome() << " usou a magia " << getMagia(magia)
                                                << " e curou " << diferenca << " de vida!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                            arq.close();
                                        }
                                    }
                                    else
                                    {
                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p2.getNome() << " tentou usar a magia " << getMagia(magia) << " mas nao possui mana suficiente.";
                                            arq.close();
                                        }
                                        acao = 10;
                                    }
                                }
                            }
                        }
                    }
                    else if (acao == 2)
                    {
                        char arma;

                        if (jogador == 1)
                        {
                            arma = menuArmas(p1, bK);

                            if (arma == 's')
                            {
                                acao = 10;
                            }
                            else
                            {
                                vidaAntes = p2.getVida();
                                verifica = usarArma(arma, p1, p2);

                                if (verifica == 1)
                                {
                                    diferenca = vidaAntes - p2.getVida();
                                    cout << "\n\n"
                                         << p1.getNome() << " usou a arma " << getArma(arma) << " e "
                                         << p2.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p1.getNome() << " usou a arma " << getArma(arma) << " e "
                                            << p2.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                        arq.close();
                                    }
                                }
                                else if (verifica == 0)
                                {
                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p1.getNome() << " tentou usar a arma " << getArma(arma) << " mas nao possui energia suficiente.";
                                        arq.close();
                                    }
                                    acao = 10;
                                }
                                else if (verifica == -1)
                                {
                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p1.getNome() << " tentou usar a arma " << getArma(arma) << " mas " << p2.getNome() << " desviou e nao recebeu dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                        arq.close();
                                    }
                                }
                            }
                        }
                        else
                        {
                            arma = menuArmas(p2, bK);

                            if (arma == 's')
                            {
                                acao = 10;
                            }
                            else
                            {
                                vidaAntes = p1.getVida();
                                verifica = usarArma(arma, p2, p1);

                                if (verifica == 1)
                                {
                                    diferenca = vidaAntes - p1.getVida();
                                    cout << "\n\n"
                                         << p2.getNome() << " usou a arma " << getArma(arma) << " e "
                                         << p1.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p2.getNome() << " usou a arma " << getArma(arma) << " e "
                                            << p1.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                        arq.close();
                                    }
                                }
                                else if (verifica == 0)
                                {
                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p2.getNome() << " tentou usar a arma " << getArma(arma) << " mas nao possui energia suficiente.";
                                        arq.close();
                                    }
                                    acao = 10;
                                }
                                else if (verifica == -1)
                                {
                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p2.getNome() << " tentou usar a arma " << getArma(arma) << " mas " << p1.getNome() << " desviou e nao recebeu dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                        arq.close();
                                    }
                                }
                            }
                        }
                    }
                    else if (acao == 3)
                    {
                        acao = 10;
                        cout << "\n* ATRIBUTOS JOGADOR ";
                        if (jogador == 1)
                        {
                            cout << "1 * * * *";
                            p1.printAtributos();
                        }
                        else
                        {
                            cout << "2 * * * *";
                            p2.printAtributos();
                        }
                    }
                    if (acao != 10)
                    {
                        if (jogador == 1)
                        {
                            if (acao == 1)
                            {
                                p1.recuperarEnergia(10);
                            }
                            else if (acao == 2)
                            {
                                p1.recuperarMana(10);
                            }

                            jogador++;
                        }
                        else
                        {
                            if (acao == 1)
                            {
                                p2.recuperarEnergia(10);
                            }
                            else if (acao == 2)
                            {
                                p2.recuperarMana(10);
                            }
                            jogador--;
                        }
                    }
                    else
                    {
                        contAcoes--;
                    }

                    vida1 = p1.getVida();
                    vida2 = p2.getVida();

                    if (contAcoes == 3)
                    {
                        cout << "\nFIM DO TURNO " << turno - 1 << "\n\nVida de " << p1.getNome() << ": " << vida1 << "/" << p1.getVidaMax() << "\nVida de " << p2.getNome() << ": " << vida2 << "/" << p2.getVidaMax();
                        if (salvar)
                        {
                            arq.open(nomeArquivo, ios::app);

                            arq << "\nFIM DO TURNO " << turno - 1 << "\n\nVida de " << p1.getNome() << ": " << vida1 << "/" << p1.getVidaMax() << "\nVida de " << p2.getNome() << ": " << vida2 << "/" << p2.getVidaMax();

                            arq.close();
                        }
                    }
                }
            }
            if (vida1 == 0)
            {
                cout << "\n\n FIM DE JOGO \n"
                     << p1.getNome()
                     << " perdeu "
                     << "\n\nParabens Jogador 2, " << p2.getNome();

                if (salvar)
                {
                    arq.open(nomeArquivo, ios::app);

                    arq << "\n\nFIM DE JOGO \n"
                        << p1.getNome()
                        << " perdeu"
                        << "\n\nParabens Jogador 2, " << p2.getNome();

                    arq.close();
                }
            }
            else if (vida2 == 0)
            {
                cout << "\n\n FIM DE JOGO \n"
                     << p2.getNome()
                     << " perdeu"
                     << "\n\nParabens Jogador 1, " << p1.getNome();

                if (salvar)
                {
                    arq.open(nomeArquivo, ios::app);

                    cout << "\n\n* * * * FIM DE JOGO * * * *\n"
                         << p2.getNome()
                         << " perdeu"
                         << "\n\nParabens Jogador 1, " << p1.getNome();

                    arq.close();
                }
            }

            op = menu();
        }

    }

    return 0;
}
