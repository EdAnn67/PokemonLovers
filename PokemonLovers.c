#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	char *Info;
	struct Node *Left;
	struct Node *Right;
}Nodes;
int Menu;
char YesNo;

Nodes* CreateNode(char *Info){
    char *NewInfo = (char*) calloc(20, sizeof(char));
    memcpy(NewInfo, Info, 20);
	Nodes* NewNode = malloc(sizeof(Nodes));
	NewNode->Info = NewInfo;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	
	return NewNode;
}

void InsertLeft(Nodes* root, char *Info){
    root->Left = CreateNode(Info);
}

void InsertRight(Nodes* root, char *Info){
    root->Right = CreateNode(Info);
}

void InOrder(Nodes* root){
    if(root == NULL) return;
    InOrder(root->Left);
    printf("\n->%s", root->Info);
    InOrder(root->Right);
}

int main(){
	Nodes* Base = CreateNode("Electrico");
    InsertLeft(Base, "Pikachu");
    
	do{
    	Nodes* ActualBase = Base;
    	Nodes* TemporaryNode = Base;
		system("cls");
		printf("\nBienvenido al menu de Pokemon Lovers: ");
		printf("\nIngrese la opcion que desea ejecutar: ");
		printf("\n1 - Adivinar el Pokemon");
		printf("\n2 - Reglas del juego");
		printf("\n3 - Imprimir el arbol");
		printf("\n4 - Salir");
		printf("\n\nOpcion: ");
		scanf("%d", &Menu);
		
		while(Menu < 1 || Menu > 4){
			system("cls");
			printf("\nBienvenido al menú de Pokemon Lovers: ");
			printf("\nIngrese la opcion que desea ejecutar: ");
			printf("\n1 - Adivinar el Pokemon");
			printf("\n2 - Reglas del juego");
			printf("\n3 - Imprimir el arbol");
			printf("\n4 - Salir");
			printf("\n\nOpcion: ");
			scanf("%d", &Menu);
		}
		
		
		if(Menu == 1){
			do{
				printf("\nEstas pensando en un Pokemon de tipo %s", ActualBase->Info);
				printf("\nIngrese S o N: ");
				scanf("%c", &YesNo);
			
				while(YesNo != 'S' && YesNo != 'N' && YesNo != 's' && YesNo != 'n'){
					printf("\nIngrese un valor valido (S o N)");
					scanf("%c", &YesNo);
				}
			
				if(YesNo == 's' || YesNo == 'S'){
					printf("Entonces estás pensando en %s", ActualBase->Left->Info);
					printf("\nIngrese S o N: ");
					scanf("%c", &YesNo);
				
					while(YesNo != 'S' && YesNo != 'N' && YesNo != 's' && YesNo != 'n'){
						printf("\nIngrese un valor valido (S o N)");
						scanf("%c", &YesNo);
					}
				
					if(YesNo == 's' || YesNo == 'S'){
						printf("\nHemos Adivinado tu Pokemon.");
						sleep(3);
						break;
					}
				
					else{
						if(ActualBase->Right != NULL){
							ActualBase = ActualBase->Right;
						}
					}
				}
			
				else{
					if(ActualBase->Right != NULL){
						ActualBase = ActualBase->Right;
					}
				}
				
				TemporaryNode = TemporaryNode->Right;
			}while(TemporaryNode != NULL);
			if(YesNo == 'n' || YesNo == 'N'){
				char Answer[20];
				printf("\nIngrese el tipo de Pokemon en el cual esta pensando: ");
				scanf("%20s", Answer);
				InsertRight(ActualBase, Answer);
				printf("\nIngrese el nombre del pokemon en el cual esta pensando: ");
				scanf("%20s", Answer);
				InsertLeft(ActualBase->Right, Answer);
				sleep(3);
			}
		}
		
	    else if(Menu == 2){
	        system("cls");
	        printf("Detalles de Pokemon Lovers:\n");
	        printf("\nLos Pokémon son una clase de criaturas inspiradas en animales reales,");
	        printf("\n insectos, objetos, plantas o criaturas mitológicas,");
	        printf("\n cada una de estas criaturas se pueden clasificar en diferentes tipos");
	        printf("\n y tienen características diferentes.\n\n");
	        printf("Se requiere crear una base de datos por medio de interrogantes que se hacen al usuario,");
	        printf("\n se van quitando alternativas hasta que queda una. El objetivo es “instruir” a la base de datos,");
	        printf("\n en un inicio la base de datos solo sabe un pokemon ");
	        printf("\n y cuestionará si ese pokemon es el que el usuario está pensando,");
	        printf("\n de lo contrario preguntará en que pokemon pensaba el usuario ");
	        printf("\n y en qué lo diferencia del que nos “predice”,");
	        printf("\n se debe hacer uno de arbol binario que despues de introducir cualquier dato");
	        printf("\ npodrá predecir cualquier pokemon.\n\n");
	        sleep(10);
	        
	    }
    
		else if(Menu == 3){
			printf("\nSe va a imprimir el Arbol en Inorder Traversal: ");
			printf("\n");
			InOrder(Base);
			sleep(3);
		}
		
		else if(Menu == 4){
			break;
		}
		
		
	}while(Menu > 0 || Menu < 4);
}
