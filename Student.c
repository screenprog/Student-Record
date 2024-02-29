#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct student
{
	int marks, roll;
	char name[10];
};
struct student S;
void input()
{
	printf("\n Enter Student Name : ");
	fflush(stdin);
	gets(S.name);
	printf("\n Enter Student Roll Number : ");
	scanf("%d",&S.roll);
	printf("\n Enter Marks : ");
	scanf("%d",&S.marks);
}

void display()
{
	printf("\n Name : %s",S.name);
	printf("\n Roll Number : %d",S.roll);
	printf("\n Marks : %d",S.marks);
	printf("\n\n");
}

void file_writing(FILE *P)
{
	P=fopen("student.txt","a");
	input();
	fwrite(&S,sizeof(struct student),1,P);
	if(fwrite==0)
		printf("\n File Contents Writing Error");
	else
		printf("\n File Contents are Written \n\n");
	fclose(P);

}


void file_reading(FILE *P)
{
	P=fopen("student.txt","r");
	while(fread(&S,sizeof(struct student),1,P))
		display();
	fclose(P);
	getch();

}


void file_searching(FILE *P)
{
	int r;
	printf("\n Enter Roll Number to be Search :");
	scanf("%d",&r);
	P=fopen("student.txt","r");
	while(fread(&S,sizeof(struct student),1,P))
	{
		if(r==S.roll)
		{
			display();
			break;
		}
	}
	fclose(P);
}

//Delete a Record By Using Another File

void file_deletion(FILE *P)
{
	FILE *D;
	int d;
	printf("\n Enter Number to Delete : ");
	scanf("%d",&d);
	P=fopen("student.txt","r");
	D=fopen("delete.txt","w+");
	while(fread(&S,sizeof(struct student),1,P))
	{
		if(d==S.roll)
			printf("\n Data Deleted \n\n");
		else
			fwrite(&S,sizeof(struct student),1,D);
	}
	fclose(P);
	P=fopen("student.txt","w");
	fseek(D,0,SEEK_SET);
	while(fread(&S,sizeof(struct student),1,D))
		fwrite(&S,sizeof(struct student),1,P);
	fclose(D);
	remove("delete.txt");
	fclose(P);
}


main()
{
	FILE *P;
	int i;
	system("cls");
	while(1)
	{
		printf("\n For Reading Data Press 1");
		printf("\n For Writing Data Press 2");
		printf("\n For Searching Data Press 3");
		printf("\n For Deleting Data Press 4");
		printf("\n To Exit Press 0");
		printf("\n Enter Your Choise : ");
		scanf("%d",&i);
		switch(i)
		{
			case 1 :
				file_reading(P);
				break;
			case 2 :
				file_writing(P);
				break;
			case 3 :
				file_searching(P);
				break;
			case 4 :
				file_deletion(P);
				break;
			case 0 :
				exit(1);
			default :
				printf("\n Wrong Key Please Try Again");
		}
	}
	getch();
}
