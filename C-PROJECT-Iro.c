#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CARS_FILE "cars.txt"
#define MAX 100

struct Car {
	int plateNumber;
	char color[10];
	char brand[10];
	int year;
};


//H struct auth apothikeuei autokinhta mazi me megethos, gia na ta parei h synarthsh apothikeusis.
struct CarsWithSize {
	struct Car* cars;
	int size;
};

int menu();
void emfanisi();
int read(struct Car cars[], int n_p, FILE *myFile);
struct CarsWithSize eisagwgi();
void diagrafi();
void bubble(struct Car a[], int y);
struct CarsWithSize ananewsi();
void anazitisi();
void enimerwsi(struct Car *carsToSave, int size);
void eksodos();
void bubble();
void plateNumbers();
void get_char();



int main(void)
//H synarthsh main periexei th switch.
{
	
	struct CarsWithSize tempCarsWithSize;
	int choice, size, end=0;
	while(end!=1)
	{
		choice = menu();
		switch(choice)
		{
			case 1: {
				emfanisi();
				break;
			}
			case 2: {
				tempCarsWithSize = eisagwgi();
				break;
			}
			case 3: {
				diagrafi();
				break;
			}
			case 4: {
				tempCarsWithSize = ananewsi();
				break;
			}
			
			case 5: {
				anazitisi();
				break;
			}
			
			case 6: {
				enimerwsi(tempCarsWithSize.cars, tempCarsWithSize.size);
				break;
			}
			case 0: {
				eksodos();
			    break;
			}
			default: {
				printf("����� �������! ������ �� ��������� ������ ��� 0 - 6!\n\n");
				printf("\n\n������������� ��� ������ ��� ����������� ���� �������� ��� ��� �� ����������������:\t");
				scanf("%d", &choice);
			}
		}
		
	}
	
	system("PAUSE");
	return 0;
}

int menu()
//H synarthsh menu periexei to menou epilogwn kai thn epilogi tou xrhsth.
{
		int epilogi;
		system("CHCP 1253");
		system("CLS");
	
		printf("*********************************************************\n*\t����������� ��� ���� ��������� �����������\t*\n*********************************************************\n\n");
		printf("\n ������ �����\n");
		printf("--------------------------------------------------------\n\n");
		printf("1. �������� ����\n");
		printf("2. �������� ���� ��������\n");
		printf("3. �������� ��������\n");
		printf("4. �������� ��������\n");
		printf("5. ���������\n");
		printf("6. ��������� �����\n");
		printf("0. ������\n");
		printf("\n*********************************************************\n");
		printf("�������! � ��������� ��� ��������� ��� ��� ��������� �������� ������� ��������.\n��� ��� ��������� ��� ��������� ������ �� �������� �� 6.");
		printf("\n*********************************************************\n");
		
		printf("\n\n������������� ��� ������ ��� ����������� ���� �������� ��� ��� �� ����������������:\t");
		scanf("%d", &epilogi);
		return epilogi;
}


void emfanisi()
//emfanisi twn periexomenwn tou arxeiou cars.txt me stoixisi
{
	system("CHCP 1253");
	system("CLS");
	FILE *myFile = fopen(CARS_FILE, "r+");
	int i=0;
	struct Car cars[MAX];
	int size;

	while(!feof(myFile)) 
	{
		read(cars, i, myFile);
		i++;
	}

	size = i;
	printf("-----------------------------------------------------------------");
	printf("\n|\t%-10s%-10s%-20s%-10s%\t|\n", "\�������", "�����", "�������������", "����");
	printf("-----------------------------------------------------------------\n");
	for(i=0; i<size; i++)
		printf("|\t%-10d%-10s%-20s%-10d%\t|\n", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
		printf("_________________________________________________________________\n");

	fclose(myFile);
	system("PAUSE");
}

int read(struct Car cars[], int n_p, FILE *myFile)
//anagnwsi twn periexomenwn tou arxeiou cars.txt
{
	
	if(myFile==NULL)
	{
		printf("Error\n");
		return -1;
	}
	fscanf(myFile, "%d %s %s %d\n", &cars[n_p].plateNumber, cars[n_p].color, cars[n_p].brand, &cars[n_p].year);
	
}

 struct CarsWithSize eisagwgi()
//eisagwgi stoixeiwn apo ton xristi. Epistrefetai mia struct autokinhtwn mazi me to megethos tous.
{
	struct CarsWithSize carsWithSize;
	int plithos, choice;
	int i, f, j;
	FILE *myFile;
	printf("���� ������ ����������� ��� ��� �� ������������:\t");
			scanf("%d", &plithos);
			carsWithSize.cars = malloc(plithos*sizeof(struct Car));
			carsWithSize.size = plithos;
	for(i=0; i<plithos; i++)
	{
		system("CLS");
		do
		{
			f=0;
			printf("--------------------------------\n");
			printf("|\t��� ������� %d\t\t|\n", i+1);
			printf("--------------------------------\n");
			printf("\n������� �����������:\t");
			scanf("%d", &carsWithSize.cars[i].plateNumber);
			for(j=0;j<i;j++)	if(carsWithSize.cars[i].plateNumber==carsWithSize.cars[j].plateNumber)	f=1;
			if(f==1)	printf("\n�������! � ������� ����� ��� �������!\n\n");
			else if(carsWithSize.cars[i].plateNumber<1001 || carsWithSize.cars[i].plateNumber>9999)	
				printf("\n�������! � ������� ����������� ������ �� ����������� ��� 4 �����!\n");
			else if(carsWithSize.cars[i].plateNumber == (float)carsWithSize.cars[i].plateNumber)
			carsWithSize.cars[i].plateNumber == (int)carsWithSize.cars[i].plateNumber;
		}while(f == 1 || carsWithSize.cars[i].plateNumber<1001 || carsWithSize.cars[i].plateNumber>9999);
		printf("����� �����������:\t");
		getchar();
		scanf("%s", carsWithSize.cars[i].color);
		printf("�������������:\t");
		scanf("%s", carsWithSize.cars[i].brand);
		do{
			printf("���� ����������:\t");
			scanf("%d", &carsWithSize.cars[i].year);
			if(carsWithSize.cars[i].year<1960 || carsWithSize.cars[i].year>2006)
				printf("�� ���������� �������. ��������� ��� ����������� 1960 - 2006!\n");
		}while(carsWithSize.cars[i].year<1960 || carsWithSize.cars[i].year>2006);
		printf("\n�������� ��� �������!\n\n\n");
	}
	system("PAUSE");
	return carsWithSize;
	free(carsWithSize.cars);
	
}

int numberofLines()
//aparithmisi twn grammwn tou arxeiou cars.txt
{

	FILE *myFile = fopen(CARS_FILE, "r");
	int ch, number_of_lines = 0;
	do
	{
	    ch = fgetc(myFile);
	    if(ch == '\n')
	        number_of_lines++;
	}
	while (ch != EOF);
	if(ch != '\n' && number_of_lines != 0)
	    number_of_lines++;
	fclose(myFile);
	return number_of_lines;
}

void diagrafi()
//H synarthsh ths diagrafis
{
	system("CLS");
	printf("--------------------------------\n");
	printf("|\t�������� ��������\t|\n");
	printf("--------------------------------\n");
	printf("\n���������� �������:\n\n"); 
	FILE *myFile;
	myFile = fopen(CARS_FILE, "r+");
	int x=numberofLines(), platenumber, position, size, i=0;
	char answer;
	struct Car cars[MAX];
	while(!feof(myFile)) 
	{
	read(cars, i, myFile);
	i++;
	}

	size = i;
	for(i=0; i<size; i++)
	{
		
		bubble(cars, x);
		printf("%d%, ", cars[i].plateNumber);
	}
	
	printf("\n\n������������� ��� ������ ��� ��� �� ����������:\n");
	scanf("%d", &platenumber);
	i=0;
	while(i<size)
	{
		if(platenumber == cars[i].plateNumber) 
		{
			printf("\n\n�������: %d\n�����: %s\n�������������: %s\n���� ����������: %d\n\n", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
			position = i;
			printf("����� �������� ��� ��� �� ���������� ��� ������� ��� ����������� ���� ������ %d? (Y / N)\n\n", cars[position].plateNumber);
			getchar();
			gets(&answer);
			if(answer=='y' || answer=='Y')
			{
				printf("�������� ��������! �� �������� ��� ����� �� ����:\n\n");
				for(i=0; i<position; i++)
				//Apothikeuw to position tou autokinhtou pou epilegei o xrhsths.
				//Sth synexeia prospathw na ftiaksw loupes anagnwshs kai ektypwshs poy den periexoun auto to position
				{
					fscanf(myFile, "%d %s %s %d\n", &cars[i].plateNumber, cars[i].color, cars[i].brand, &cars[i].year);
					printf("�������: %d\n�����:%s\n�������������:%s\n����:%d\n\n", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
						fclose(myFile);
						myFile = fopen(CARS_FILE, "w");
						fprintf(myFile, "\n%d %s %s %d", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
				}
				for(i=position+1; i<x-1; i++)
				{
					fscanf(myFile, "%d %s %s %d\n", &cars[i].plateNumber, cars[i].color, cars[i].brand, &cars[i].year);	
					printf("�������: %d\n�����:%s\n�������������:%s\n����:%d\n\n", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
					fclose(myFile);
					myFile = fopen(CARS_FILE, "a");
					fprintf(myFile, "\n%d %s %s %d", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
				}
					break;
			}
			else
			{
				menu();
			}			
		}
	
		i++;
	
	}
	fclose(myFile);
	system("PAUSE");
	
	
}

void bubble(struct Car a[], int y)
//taksinomisi tou arithmou twn autokinhtwn me auksousa seira
{
	int i,j;
    struct Car temp;
    for(i=0; i<y-1; i++)
        for(j=0; j<y-i-1; j++)
            if(a[j].plateNumber > a[j+1].plateNumber)
            {
            	temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
            }
}

void anazitisi()
//menou epilogwn anazitisis
{
	int choice;
	system("CLS");
	printf("--------------------------------\n");
	printf("|\t����� ����������\t|\n");
	printf("--------------------------------\n\n");
	printf("1. �� ���� ��� ������\n");
	printf("2. �� ���� �� �����\n");
	printf("3. �� ���� ��� ������������\n");
	printf("4. �� ���� �� ���� ����������\n");
	printf("0. ��������� ��� ������ �����\n");
	
	printf("\n\n������������� ��� ������ ��� ����������� ��� �������� ����������:\t");
	scanf("%d", &choice);
	
	switch(choice)
	{
	case 1: {
		system("CLS");
		FILE *myFile;
		int i=0, size, number;
		char telestis;
		struct Car cars[MAX];
		myFile=fopen(CARS_FILE,"r");
		printf("--------------------------------\n");
		printf("|��������� �� ���� ��� ������  |\n");
		printf("--------------------------------\n");
		printf("\n���������� �������:\n");
		while(!feof(myFile)) 
		{
			read(cars, i, myFile);
			i++;
		}

		size = i;
		for(i=0; i<size; i++)
			printf("%d, ", cars[i].plateNumber);
		printf("\n\n�������� ��� ������� ��������� (<, >) ��� ��� ������ ��� ������ �� ���������:\n");
		getchar();
		gets(&telestis);
		if(telestis == '>')
		{
			printf("\n�������� �������� ����:\n");
			scanf("%d", &number);
			printf("\n�������� ��� ��������\n");
			printf("----------------------------------------------\n");
			i=0;
			for(i=0; i<size; i++)
			{
				if(cars[i].plateNumber>number)
				{
					printf("�������: %d\n�����:%s\n�������������:%s\n����:%d\n\n", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
				}
				
			}
		}
		else
        {
			printf("\n�������� ������� ����:\n");
			scanf("%d", &number);
			printf("\n�������� ��� ��������\n");
			printf("----------------------------------------------\n");
			i=0;
			for(i=0; i<size; i++)
			{
				if(cars[i].plateNumber<number)
				{
					printf("�������: %d\n�����:%s\n�������������:%s\n����:%d\n\n", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
				}
				
			}
		}
	
		fclose(myFile);
		system("PAUSE");
		break;
	
 }
	case 2: {
		system("CLS");
		FILE *myFile;
		int i=0, size;
		char color[10];
		struct Car cars[MAX];
		myFile=fopen(CARS_FILE,"r");
		printf("--------------------------------\n");
		printf("|��������� �� ���� �� �����    |\n");
		printf("--------------------------------\n");
		printf("��������� �������:\n\n");
		while(!feof(myFile)) 
		{
			read(cars, i, myFile);
			i++;
		}

		size = i;
		for(i=0; i<size; i++)
		printf("%s, ", cars[i].color);
		printf("\n\n������������� �� ����� ��� �� ����������:\n");
		scanf("%s", &color);
		i=0;
		for(i=0; i<size; i++)
		{
                 if(strncmp(color, cars[i].color,3)==0)
                 printf("�������: %d\n�����:%s\n�������������:%s\n����:%d\n\n", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
        }
        fclose(myFile);
		system("PAUSE");
		break;
  }

	case 3: {
		system("CLS");
		FILE *myFile;
		int i=0, size;
		char brand[20];
		struct Car cars[MAX];
		myFile=fopen(CARS_FILE,"r");
		printf("------------------------------------\n");
		printf("|��������� �� ���� ��� ������������|\n");
		printf("------------------------------------\n");
		printf("���������� �������������:\n\n");
		while(!feof(myFile)) 
		{
		read(cars, i, myFile);
		i++;
		}

		size = i;
		for(i=0; i<size; i++)
		printf("%s, ", cars[i].brand);
		printf("\n\n�������� �� ����� ��� ������������:\n");
		scanf("%s", &brand);
		i=0;
		for(i=0; i<size; i++)
		{
                 if(strncmp(brand, cars[i].brand, 3)==0)
                 printf("\n�������: %d\n�����:%s\n�������������:%s\n����:%d\n\n", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
        }
		fclose(myFile);
		system("PAUSE");
		break;
  
	}
	case 4: {
		system("CLS");
		FILE *myFile;
		int i=0, size, etos;
		char telestis;
		struct Car cars[MAX];
		myFile=fopen(CARS_FILE,"r");
		printf("--------------------------------------\n");
		printf("|��������� �� ���� �� ���� ����������|\n");
		printf("--------------------------------------\n");
		printf("\n��������� ���:\n\n");
		while(!feof(myFile)) 
		{
		read(cars, i, myFile);
		i++;
		}
        size = i;
		for(i=0; i<size; i++)
			printf("%d, ", cars[i].year);
		printf("\n\n�������� ��� ������� ��������� (<, >) ��� �� ���� ��� ������ �� ���������:\n");
		getchar();
		gets(&telestis);
		if(telestis == '>')
		{
			printf("\n�������� �������� ����:\n");
			scanf("%d", &etos);
			printf("\n�������� ��� ��������\n");
			printf("----------------------------------------------\n");
			i=0;
			for(i=0; i<size; i++)
			{
				if(cars[i].year>etos)
				{
					printf("�������: %d\n�����:%s\n�������������:%s\n����:%d\n\n", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
				}
				
			}
		}
		else
        {
			printf("\n�������� ������� ����:\n");
			scanf("%d", &etos);
			printf("\n�������� ��� ��������\n");
			printf("----------------------------------------------\n");
			i=0;
			for(i=0; i<size; i++)
			{
				if(cars[i].year<etos)
				{
					printf("�������: %d\n�����:%s\n�������������:%s\n����:%d\n\n", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
				}
				
			}
		}
	
		fclose(myFile);
		system("PAUSE");
		break;
	
 }
	case 0: {
		menu();
		break;
	}

	}
}

struct CarsWithSize ananewsi()
//tropopoihsh twn stoixeiwn
//Prosoxi. Logw kapoiou lathous sth dilwsi tou size, trexei mono gia tis 2 prwtes fores pou tha ginei ananewsi.
{
	int platenumber;
	system("CLS");
	printf("--------------------------------\n");
	printf("|\t4. �������� ��������\t|\n");
	printf("--------------------------------\n");
	printf("���������� ��������:\n\n");
	FILE *myFile = fopen(CARS_FILE, "r+");
	int x;
	int position;
	x=numberofLines();
	int i=0;
	struct Car cars[MAX];
	int size;
	struct CarsWithSize carsWithSize;
	while(!feof(myFile)) 
	{
		read(cars, i, myFile);
		i++;
	}

	size = i;
	for(i=0; i<size; i++)
	{
		
		bubble(cars, x);
		printf("%d%, ", cars[i].plateNumber);
	}
	printf("\n\n������������� ��� ������ ��� �������� ��� ��� �� �������������:\n");
	scanf("%d", &platenumber);
	i=0;
	while(i<size)
	{
		if(platenumber == cars[i].plateNumber) {
			printf("\n\n�������: %d\n�����: %s\n�������������: %s\n���� ����������: %d", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
			position = i;
			break;
		}
		i++;
	}
	printf("\n\n���� ��� ������:\n");
	scanf("%d", &cars[position].plateNumber);
	printf("\n���� ��� �����:\n");
	scanf("%s", &cars[position].color);
	printf("\n���� ��� ������������:\n");
	scanf("%s", &cars[position].brand);
	printf("\n���� ��� ����:\n");
	scanf("%d", &cars[position].year);
	printf("������������� �������: %d %s %s %d\n\n", cars[position].plateNumber, cars[position].color, cars[position].brand, cars[position].year);
	system("PAUSE");
	fclose(myFile);
	myFile = fopen(CARS_FILE, "w");
	for(i=0; i<size; i++)
		fprintf(myFile, "\n%d %s %s %d", cars[i].plateNumber, cars[i].color, cars[i].brand, cars[i].year);
	fclose(myFile);
	
	
}
void enimerwsi(struct Car *carsToUpdate, int size)
/*apothikeusi tis eisagwgis
H fopen leitourgei me APPEND kai oxi me Write, wste na prosthetei katw apo ta idi
yparxonta aytokinhta*/
{
	system("CLS");
	FILE *myFile;
	int i;
	myFile = fopen(CARS_FILE, "a");
	for(i=0; i<size; i++)
		fprintf(myFile, "\n%d %s %s %d", carsToUpdate[i].plateNumber, carsToUpdate[i].color, carsToUpdate[i].brand, carsToUpdate[i].year);
	fclose(myFile);
	printf("\n�������� ���������\n");
	system("PAUSE");
	
	
}

void eksodos()
{
     system("CLS");
     printf("---------------------------\n");
     printf("|\tGoodbye\t\t|");
     printf("\n------------------------\n");
     system("PAUSE");
     exit(0);
     
}
     











