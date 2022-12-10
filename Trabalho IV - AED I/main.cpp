// Trabalho feito por Thales Willian e Henrique Sales
// ATENÇÃO: todas as estruturas de comando que dizem respeito à Lista Duplamente Encadeada possuem um "2" após seu nome.

#include <iostream>
#include <windows.h>

// #include "Lista_2Encad.cpp"
#include "Lista_Encad.cpp"

using namespace std;

void Menu()
{
    cout << "1. Menu da rodoviária\n";
    cout << "2. Menu de manutenção\n";
    cout << "3. Sair\n\n";
}

void PreencheAuto(Lista *linhas, int *id)
{
    Item item;
    item.id = *id;
    *id += 1;
    item.nome = "SJE-BH";
    item.companhia = "Saritur";

    CriaListaVazia2(&item.paradas);

    Item2 parada;

    parada.id = item.idParada;
    item.idParada++;
    parada.horario = "00:10";
    parada.horario2 = "00:25";
    parada.cidade = "SJE";
    parada.passagem = 0;

    InsereListaUltimo2(&item.paradas, parada);

    parada.id = item.idParada;
    item.idParada++;
    parada.horario = "00:45";
    parada.horario2 = "01:00";
    parada.cidade = "GHS";
    parada.passagem = 16.60;

    InsereListaUltimo2(&item.paradas, parada);

    parada.id = item.idParada;
    item.idParada++;
    parada.horario = "04:00";
    parada.horario2 = "04:15";
    parada.cidade = "ITA";
    parada.passagem = 61.80;

    InsereListaUltimo2(&item.paradas, parada);

    parada.id = item.idParada;
    item.idParada++;
    parada.horario = "05:15";
    parada.horario2 = "05:30";
    parada.cidade = "BH";
    parada.passagem = 49.05;

    InsereListaUltimo2(&item.paradas, parada);

    InsereListaUltimo(linhas, &item);
}

void ProcuraLinha(Lista *linhas)
{
    int op;
    while (op != 1 && op != 2 && op != 3)
    {
        cout << "1. Procurar cidade\n";
        cout << "2. Procurar por código\n";
        cout << "3. Voltar\n";
        cout << "\nOpção: ";
        cin >> op;
        system("cls");
    }

    if (op == 1)
    {
        float preco = 0;
        int rotas = 0; // Caso, dentro do "if", a variável não encontre nenhuma rota, será utilizada como orientação.

        bool OrigemExist = false;
        bool DestinoExist = false;

        cout << "Digite a cidade de origem: ";
        string origem;
        cin >> origem;
        cout << "Digite a cidade de destino: ";
        string destino;
        cin >> destino;

        Apontador linha = linhas->primeiro->prox;
        Apontador2 aOrigem;
        Apontador2 aDestino;

        while (linha != NULL) // Percorre as linhas.
        {
            aDestino = linha->item.paradas.primeiro->prox;

            while (aDestino != linha->item.paradas.primeiro) // Percorre as paradas.
            {
                if (aDestino->item.cidade == destino)
                {
                    DestinoExist = true;
                    aOrigem = aDestino;
                    preco = 0;
                    while (aOrigem != linha->item.paradas.primeiro) // A partir da cidade de destino, encontra a origem.
                    {
                        if (aOrigem->item.cidade == origem)
                        {
                            OrigemExist = true;
                            system("cls");
                            ImprimeItemRecebido(linha->item);
                            cout << endl;
                            cout << "Preço da passagem: " << preco << endl;
                            cout << "Horário de saída: " << aOrigem->item.horario2 << endl;
                            cout << "Horário de chegada: " << aDestino->item.horario << endl;
                            cout << endl << endl;
                            rotas++;
                        }
                        preco += aOrigem->item.passagem;
                        aOrigem = aOrigem->ante;
                    }
                }
                aDestino = aDestino->prox;
            }
            linha = linha->prox;
        }
        if (!OrigemExist)
        {
            cout << "\nOrigem inexistente.\n\n";
        }
        if (!DestinoExist)
        {
            cout << "\nDestino inexistente.\n\n";
        }
        if (rotas == 0 && !OrigemExist && !DestinoExist)
        {
            cout << "\nLinha inexistente.\n\n";
        }
        system("pause");
        system("cls");
        return;
    }
    if (op == 2)
    {
        cout << "Insira o ID da linha: ";
        Apontador aux;
        int id;
        cin >> id;

        aux = PesquisaItem(linhas, id);

        if (aux == NULL)
        {
            cout << "Linha não encontrada";
        }
        ImprimeItemRecebido(aux->item);
        cout << endl;

        cout << "Cidades pertencentes à linha\n\n";
        ImprimeLista2(&aux->item.paradas);
        system("pause");
        system("cls");
    }
    if (op == 3)
    {
        return;
    }
}

void IncluiLinha(Lista *linhas, int *id)
{
    Item linha;
    linha.id = *id;

    cout << "Insira o nome da companhia: ";
    cin >> linha.companhia;

    cout << "Insira o nome (código) da linha: ";
    cin >> linha.linha;

    cout << "\n\nLinha criada.\n\n";

    CriaListaVazia2(&linha.paradas);
    InsereListaUltimo(linhas, &linha);

    *id += 1;
}

void IncluiParada(Lista *linhas)
{
    int id;

    cout << "Insira o ID da linha à qual a parada será adicionada: ";
    cin >> id;

    Apontador aux = PesquisaItem(linhas, id);
    while (aux == NULL)
    {
        cout << "Nenhuma linha encontrada.\n\n";
    }

    Item2 parada;

    parada.id = aux->item.idParada;
    aux->item.idParada++;

    cout << "Insira o código da cidade: ";
    cin >> parada.cidade;
    cout << "Insira o horário em que o ônibus chega na cidade: ";
    cin >> parada.horario;
    cout << "Insira o horário em que o ônibus sairá da cidade: ";
    cin >> parada.horario2;
    cout << "Insira o valor da passagem: ";
    cin >> parada.passagem;

    if (VerificaListaVazia2(&aux->item.paradas))
    {
        cout << "Linha sem paradas.\n\n";
        cout << "A parada foi inserida.\n\n";

        InsereListaUltimo2(&aux->item.paradas, parada);

        return;
    }
    ImprimeLista2(&aux->item.paradas);

    cout << "Onde deseja incluir a parada? (Digite ''0'' para inserí-la no início).\n";
    cout << "ID: ";
    cin >> id;

    if (id == 0)
    {
        InsereListaPrimeiro2(&aux->item.paradas, parada);
        cout << "\nParada inserida.\n\n";
        return;
    }
    InsereAposElemento2(&aux->item.paradas, parada, id);
}

void AlteraParada(Lista *linhas)
{
    int id;

    cout << "Insira o ID da linha à qual deseja alterar uma parada: ";
    cin >> id;

    Apontador aux = PesquisaItem(linhas, id);

    if (aux == NULL)
    {
        cout << "\nLinha inexistente.\n\n";
        return;
    }

    if (VerificaListaVazia2(&aux->item.paradas))
    {
        cout << "\nLinha sem paradas.\n\n";
        return;
    }

    ImprimeLista2(&aux->item.paradas);

    cout << "ID da parada que deseja alterar: ";
    cin >> id;

    Apontador2 aux2 = LocalizaID2(&aux->item.paradas, id);

    if (aux2 == NULL)
    {
        cout << "\nParada inexistente.\n\n";
        return;
    }

    cout << "Dados pré-alteração:\n\n";

    ImprimeItem2(aux2->item);

    cout << "Insira o código da cidade: ";
    cin >> aux2->item.cidade;
    cout << "Insira o horário em que o ônibus chega na cidade: ";
    cin >> aux2->item.horario;
    cout << "Insira o horário em que o ônibus sairá da cidade: ";
    cin >> aux2->item.horario2;
    cout << "Insira o valor da passagem: ";
    cin >> aux2->item.passagem;
}

void EliminaParada(Lista *linhas)
{
    int id;

    cout << "Insira o ID da linha à qual deseja remover uma parada: ";
    cin >> id;

    Apontador aux = PesquisaItem(linhas, id);

    if (aux == NULL)
    {
        cout << "\nLinha inexistente.\n\n";
        return;
    }

    if (VerificaListaVazia2(&aux->item.paradas))
    {
        cout << "\nLinha sem paradas.\n\n";
        return;
    }

    ImprimeLista2(&aux->item.paradas);

    cout << "ID da parada que deseja remover: ";
    cin >> id;

    Apontador2 aux2 = LocalizaID2(&aux->item.paradas, id);

    if (aux2 == NULL)
    {
        cout << "\nParada inexistente.\n\n";
        return;
    }

    RetiraID2(&aux->item.paradas, id);
    cout << "\nParada removida da linha.\n\n";
}

void EliminaLinha(Lista *linhas)
{
    int id;

    cout << "Insira o ID da linha a ser removida: ";
    cin >> id;

    Apontador aux = PesquisaItem(linhas, id);

    if (aux == NULL)
    {
        cout << "\nLinha inexistente.\n\n";
        return;
    }

    RemoveItemPorId(linhas, id);
    cout << "\nLinha removida.\n\n";
}

void Manutencao(Lista *linhas, int *id)
{
    int op;

    while (op != 6)
    {
        cout << "1. Incluir nova linha\n";
        cout << "2. Incluir nova parada na linha\n";
        cout << "3. Alterar uma parada\n";
        cout << "4. Eliminar uma parada\n";
        cout << "5. Eliminar uma linha\n";
        cout << "6. Voltar\n\n";
        cout << "Escolha: ";

        cin >> op;

        cout << "\n\n";

        switch (op)
        {
        case 1:
            system("cls");
            IncluiLinha(linhas, id);
            break;

        case 2:
            system("cls");
            IncluiParada(linhas);
            break;

        case 3:
            system("cls");
            AlteraParada(linhas);
            break;

        case 4:
            system("cls");
            EliminaParada(linhas);
            break;

        case 5:
            system("cls");
            EliminaLinha(linhas);
            break;

        default:
            break;
        }
        system("pause");
        system("cls");
    }
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    // UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int idLinhas = 1;
    string senha;
    string senhaCorreta = "tijolo";

    Lista linhas;
    CriaListaVazia(&linhas);
    PreencheAuto(&linhas, &idLinhas);

    ImprimeLista2(&linhas.ultimo->item.paradas);
    cout << "--------------------------------------\n\n";
    int esc;

    while (esc != 3)
    {
        Menu();

        cin >> esc;

        if (esc == 1)
        {
            system("cls");
            ProcuraLinha(&linhas);
        }
        else if (esc == 2)
        {
            system("cls");

            cout << "Insira a senha do administrador: ";

            cin >> senha;

            if (senha == senhaCorreta)
            {
                system("cls");
                Manutencao(&linhas, &idLinhas);
            }
            else
            {
                cout << "\nSenha inválida.\nConsulte o administrativo caso tenha esquecido.\n";
            }
        }
    }
    return 0;
}