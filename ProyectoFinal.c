
#include <stdio.h>
#include <time.h>

void loop (char c[3][3]);
void Intro_Primera (char c[3][3]);
void tablero (char c[3][3]);
void Intro_Usuario (char c[3][3]);
void Intro_IA (char c[3][3]);
int ganador(char[3][3]);

int main() //Funcion principal
{
	char c[3][3]; //Defifnimos una matriz
	
	loop (c); //Es la funcion que se repetira hasta que haya un ganador
	
	system ("pause");
	return 0;
}

void loop (char c[3][3])//Hace llamado a las Funciones fundamentales, refresca la pantalla
						// y se repite hasta que haya un resultado
{
	int i, j; //Declaramos un contador de tiradas y la funcion que muestra al ganador
	
	i=0;
	
	Intro_Primera(c); //Muestra el tablero por primera vez
	
	do
	{
		system("cls");
		tablero(c);
		if(i%2==0)  //Decide quien tira
		{
			Intro_Usuario(c); //Tira el usuario
		}
		else
		{
			Intro_IA(c);   //Tira el Usuario
		}
		j=ganador(c);
		i++;
		
	}while (i<=9 && j==2);
	
	system("cls");
		tablero(c); //Muestra el tablero final
	
	if (j==0) //En caso de que haya ganado el usuario
	{
		printf("Has ganado, Felicidades xD\n\n");
	}
	else if (j==1) //En caso de que haya ganado la IA
	{
		printf("Chale dude, has perdido :(");
	}
	else   //en caso de un empate
	{
		printf("Empataste con la maquina xD, intentalo de nuevo\n\n");
	}
}
	

 void Intro_Primera (char c[3][3])//Poniendo valores al tablero
 {
	int i,j;
	char aux;
	aux='1';
	
	for (i=0; i<3; i++)				//  1 | 2 | 3
	{								//  ---------
		for(j=0; j<3; j++)			//  7 | 8 | 9
		{							//  ---------	
			c[i][j]=aux++;			//  4 | 5 | 6
		}
	}
 }
 
 void Intro_Usuario(char c[3][3]) //Funcion del usuario
 {
 	int i, j, k;
 	char aux;
 	do
 	{
 		do //Introduccion de la casilla elegida por el usuario 
 		{
 			printf("Introduzca la casilla seleccionada: ");
 			fflush (stdin);
 			scanf("%c", &aux);		
		 } while( aux<'1'||aux>'9');
		
		k=0;
		
		switch (aux) //Aqui se detecta si la casilla esta ocupada, Un caso por casilla
		{
			case '1':  
			{
				i=0;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O')
				{
					k=1;
					printf("La casilla ya esta ocupada, trata con otra casilla\n\n");
				}
			break;
			}
			case '2':
			{
				i=0;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O')
				{
					k=1;
					printf("La casilla ya esta ocupada, trata con otra casilla\n\n");
				}	
			break;
			}
			case '3':
			{
				i=0;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O')
				{
					k=1;
					printf("La casilla ya esta ocupada, trata con otra casilla\n\n");
				}	
			break;
			}
			case '4':
			{
				i=1;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O')
				{
					k=1;
					printf("La casilla ya esta ocupada, trata con otra casilla\n\n");
				}	
			break;
			}
			case '5':
			{
				i=1;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O')
				{
					k=1;
					printf("La casilla ya esta ocupada, trata con otra casilla\n\n");
				}	
			break;
			}
			case '6':
			{
				i=1;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O')
				{
					k=1;
					printf("La casilla ya esta ocupada, trata con otra casilla\n\n");
				}	
			break;
			}
			case '7':
			{
				i=2;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O')
				{
					k=1;
					printf("La casilla ya esta ocupada, trata con otra casilla\n\n");
				}	
			break;
			}
			case '8':
			{
				i=2;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O')
				{
					k=1;
					printf("La casilla ya esta ocupada, trata con otra casilla\n\n");
				}	
			break;
			}
			case '9':
			{
				i=2;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O')
				{
					k=1;
					printf("La casilla ya esta ocupada, trata con otra casilla\n\n");
				}	
			break;
			}
		}
	 }while (k==1);  
	 
	 c[i][j]='X'; //El tablero muestra la jugada
 }
 
 void Intro_IA (char c[3][3])  //Funcion de la IA oponente
 {
 	int i, j, k;
 	
 	srand (time(NULL));
 	do // Aqui la IA escoje una casilla al azar
 	{
 		
 		i=rand() % 3;
 		j=rand() % 3;
 		k=0;
 		
 		if (c[i][j]== 'X' || c[i][j]=='O') // La IA detecta si la casilla esta ocupada
 		{
 			k=1;
		 }
	 }while (k==1);
	 c[i][j]='O';  //El tablero muestra la jugada de la IA
 }
 
 void tablero (char c[3][3])  //Esta funcion se encarga de mostrar el tablero en toda la partida
 {
	 int i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j<2)
			{
			printf(" %c |", c[i][j]); //Estas son las divsiones verticales
			}
		else 
		{
			printf(" %c ", c[i][j]);
		}
		}
		if (i<2)
		{
			printf("\n-----------\n"); //Son las divisiones en horizontales
		}
	}
	printf("\n\n");
 }
 
int ganador(char c[3][3])
{
	if(c[0][0]=='X'||c[0][0]=='O')
	{
		if (c[0][0]==c[0][1] && c[0][0]==c[0][2])
		{
			if (c[0][0]=='X')
			{
				return 0; //El usuario ha ganado
			}
		else 
			{
			return 1; //Ha perdido el usuario
			}
		}
		if (c[0][0]==c[1][0] && c[0][0]==c[2][0])
		{
			if (c[0][0]=='X')
			{
				return 0; //El usuario ha ganado
			}
		else 
			{
			return 1; //Ha perdido el usuario
			}	
		}
	}
	
	if(c[1][1]=='X'||c[1][1]=='O')
	{
		if (c[1][1]==c[0][0] && c[1][1]==c[2][2])
		{
			if (c[1][1]=='X')
			{
				return 0; //El usuario ha ganado
			}
		else 
			{
			return 1; //Ha perdido el usuario
			}
		}
		if (c[1][1]==c[1][0] && c[1][1]==c[1][2])
		{
			if (c[1][1]=='X')
			{
				return 0; //El usuario ha ganado
			}
		else 
			{
			return 1; //Ha perdido el usuario
			}
		}
			if (c[1][1]==c[2][0] && c[1][1]==c[0][2])
		{
			if (c[1][1]=='X')
			{
				return 0; //El usuario ha ganado
			}
		else 
			{
			return 1; //Ha perdido el usuario
			}
		}
			if (c[1][1]==c[0][1] && c[1][1]==c[2][1])
		{
			if (c[1][1]=='X')
			{
				return 0; //El usuario ha ganado
			}
		else 
			{
			return 1; //Ha perdido el usuario
			}
		}	
	}
	if (c[2][2]=='X' || c[2][2]=='O')
	{
		if (c[2][2]==c[2][0] && c[2][2]==c[2][1])
		{
			if (c[2][2]=='X')
			{
				return 0; //El usuario ha ganado
			}
		else 
			{
			return 1; //Ha perdido el usuario
			}
		}	
		if (c[2][2]==c[0][2] && c[2][2]==c[1][2])
		{
			if (c[2][2]=='X')
			{
				return 0; //El usuario ha ganado
			}
		else 
			{
			return 1; //Ha perdido el usuario
			}
		}
	}
	return 2; //Empate entre el usuario y la maquina	
}

