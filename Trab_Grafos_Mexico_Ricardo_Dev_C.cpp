#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

using namespace std;

const int n = 32; /*Número de vértices */
/*Exemplo de Algoritmo em C para BFS*/
/*Matriz de Adjacência do Grafo*/
int G[n][n] = { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0
};

bool V[n]; /*Vetor de visitados */

/*Procedimento DFS */
void DFS(int raiz)
{
	int i;
	V[raiz] = true;
	printf("%1d ", raiz);
	for (i = 0; i < n; i++)
	{
		if (G[raiz][i] == 1)
		{
			if (V[i] == false)
			{
				DFS(i);
			}
		}
	}
}

int DFS_Origem_Destino(int raiz, int destino)
{
	if (raiz == destino)
	{
		printf("%d ", destino);
		return destino;
	}
	else
	{
		int i;
		V[raiz] = true;

		printf("%1d ", raiz);
		for (i = 0; i < n; i++)
		{
			if (G[raiz][i] == 1)
			{
				if (V[i] == false)
				{
                    if (DFS_Origem_Destino(i, destino) == destino) 
                    {
                        return destino;
                    }
				}
			}
		}
	}
}

void BFS(int raiz)
{
	int i;
	int no;
	V[raiz] = true;;
	queue<int> fila;
	fila.push(raiz);
	while (!fila.empty())
	{
		no = fila.front();
		fila.pop();
		
		printf("%d ", no);
		for (i = 0; i < n; i++)
		{
			if (G[no][i] == 1)
			{
				if (V[i] == false)
				{
					fila.push(i);
					V[i] = true;
				}
			}
		}
	}
}

void BFS_Origem_Destino(int raiz, int destino)
{
	int i;
	int no;
	V[raiz] = true;

	if (raiz == destino)
	{
		
		printf("\n%d", destino);
	}
	else
	{
		queue<int> fila;
		fila.push(raiz);
		while (!fila.empty())
		{
			no = fila.front();

			if (no == destino)
			{
				
				printf("%d", no);
				break;
			}

			fila.pop();
			
			printf("%d ", no);
			for (i = 0; i < n; i++)
			{
				if (G[no][i] == 1)
				{
					if (V[i] == false)
					{
						fila.push(i);
						V[i] = true;
					}
				}
			}
		}
	}
}

void zera_visitados()
{
	int i;
	/*É necessário zerar o vetor de visitados novamente */
	for (i = 0; i < n; i++)
	{
		V[i] = false;
	}
}

void mostrarLegenda()
{
	system("cls");
	printf("Estados do Mexico\n");
	printf("0 = Baja California\t\n");
	printf("1 = Baja California Sur\t\n");
	printf("2 = Sonora\t\n");
	printf("3 = Chihuaha\t\n");
	printf("4 = Coahuila\t\n");
	printf("5 = Nuevo Leon\t\n");
	printf("6 = Tamaulipas\t\n");
	printf("7 = Sinaloa\t\n");
	printf("8 = Durango\t\n");
	printf("9 = Zacatecas\t\n");
	printf("10 = San Luis Potosi\t\n");
	printf("11 = Nayarity\t\n");
	printf("12 = Jalisco\t\n");
	printf("13 = Aguascalientes\t\n");
	printf("14 = Guanajuato\t\n");
	printf("15 = Queretaro\t\n");
	printf("16 = Hidalgo\t\n");
	printf("17 = Veracruz\t\n");
	printf("18 = Colima\t\n");
	printf("19 = Michoacan\t\n");
	printf("20 = Estado de Mexico\t\n");
	printf("21 = Distrito Federal\t\n");
	printf("22 = Tlaxcala\t\n");
	printf("23 = Guerrero\t\n");
	printf("24 = Morelos\t\n");
	printf("25 = Puebla\t\n");
	printf("26 = Oaxaca\t\n");
	printf("27 = Chiapos\t\n");
	printf("28 = Tabasco\t\n");
	printf("29 = Campeche\t\n");
	printf("30 = Yucatan\t\n");
	printf("31 = Quintana Roo\t\n");

	printf("\nPressione Enter para continuar");
	getch();
}

void menuBusca()
{
	zera_visitados();
	fflush(stdin);
	system("cls");
	printf("1. Busca em Profundidade\n");
	printf("2. Busca em Largura\n");
	printf("\nPara voltar ao menu inicial digite 0");
}

void menuTipoBusca()
{
	fflush(stdin);

	printf("\nDeseja realizar uma busca geral ou com origem e destino?: \n");
	printf("1. Busca Geral\n");
	printf("2. Busca informando Origem e Destino\n");
}

void menuBuscaOrigem()
{
	zera_visitados();
	fflush(stdin);
	printf("Qual origem? \n");
}

void menuBuscaDestino()
{
	zera_visitados();
	fflush(stdin);
	printf("Qual destino? \n");
}

void iniciarTerminarObras(int obras)
{
	int origem = 999;
	int destino = 999;

	printf("\n");
	menuBuscaOrigem();
	scanf("%d", &origem);

	printf("\n");
	menuBuscaDestino();
	scanf("%d", &destino);

	printf("\nEstado inicial da rodovia: %d\n", G[origem][destino]);

	if (obras == 0) {
		if (G[origem][destino] == 1)
		{
			G[origem][destino] = 0;
			G[destino][origem] = 0;
			printf("\nObras iniciadas nessa rodovia");
		}
		else
		{
			printf("\nRodovia nao existe ou ja se encontra em obras");
		}
	}
	else {
		if (G[origem][destino] == 0)
		{
			G[origem][destino] = 1;
			G[destino][origem] = 1;
			printf("\nObras terminadas nessa rodovia");
		}
		else
		{
			printf("\nRodovia nao existe ou ja terminou as obras");
		}
	}
	

	printf("\n\nEstado final da rodovia: %d\n", G[origem][destino]);
	printf("\nPressione Enter para continuar");
	getch();
}

void menuPrincipal()
{
	zera_visitados();
	fflush(stdin);
	system("cls");
	printf("\n\tMENU GRAFO MEXICO");
	printf("\n\t------------------------------");
	printf("\n\n\t 1. Mostrar legenda");
	printf("\n\t 2. Fazer busca");
	printf("\n\t 3. Bloquear rodovia");
	printf("\n\t 4. Desbloquear rodovia");
	printf("\n\t Para sair digite 0");
	printf("\n\n Digite a opcao desejada: ");
}

/*Programa Principal */
int main()
{
	const int raiz = 0;
	zera_visitados();

	int escolha = 999;
	int buscaEscolhida = 999;
	int tipoBusca = 999;
	int origem = 999;
	int destino = 999;

	while (escolha != 0)
	{
		menuPrincipal();

		scanf("%d", &escolha);

		switch (escolha)
		{
			case 0:
				printf("Programa Encerrado\n");
				break;
			case 1:
				mostrarLegenda();
				break;
			case 2:
				while (buscaEscolhida != 0)
				{
					menuBusca();
					printf("\n");
					scanf("%d", &buscaEscolhida);

					switch (buscaEscolhida)
					{
						case 1:
							zera_visitados();
							menuTipoBusca();
							scanf("%d", &tipoBusca);

							if (tipoBusca == 1)
							{
								printf("\nBusca em Profundidade: \n");
								DFS(raiz);
							}
							else
							{
								printf("\n");
								menuBuscaOrigem();
								scanf("%d", &origem);

								printf("\n");
								menuBuscaDestino();
								scanf("%d", &destino);

								printf("\nBusca em Profundidade com Origem %d e Destino %d:\n", origem, destino);
								DFS_Origem_Destino(origem, destino);
							}

							if (tipoBusca == 0)
							{
								tipoBusca = 999;
							}

							origem = 999;
							destino = 999;

							printf("\nPressione Enter para continuar");
							getch();
							break;
						case 2:
							zera_visitados();
							menuTipoBusca();
							scanf("%d", &tipoBusca);

							if (tipoBusca == 1)
							{
								printf("\nBusca em Largura: \n");
								BFS(raiz);
							}
							else
							{
								printf("\n");
								menuBuscaOrigem();
								scanf("%d", &origem);

								printf("\n");
								menuBuscaDestino();
								scanf("%d", &destino);

								printf("\nBusca em Largura com Origem %d e Destino %d:\n", origem, destino);
								BFS_Origem_Destino(origem, destino);
							}

							if (tipoBusca == 0)
							{
								tipoBusca = 999;
							}

							origem = 999;
							destino = 999;

							printf("\nPressione Enter para continuar");
							getch();
							break;
						case 0:
							break;
						default:
							printf("\n Opcao invalida. Tente novamente \n");
							getch();
							break;
					}
				}

				if (buscaEscolhida == 0) buscaEscolhida = 999;
				break;
			case 3:
				iniciarTerminarObras(0);
				break;
			case 4:
				iniciarTerminarObras(1);
				break;
			default:
				printf("\n Opcao invalida. Tente novamente \n");
				getch();
				break;
		}
	}
}
