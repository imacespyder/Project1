#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
int student[3][4]={0};
void *teacher();
void *stud1();
void *stud2();
void *stud3();
pthread_mutex_t l;
int ab1,ab2;
int r1,r2;

int main()
{	
    printf("\nWELCOME TO THE PROJECT \n\t");
	printf("\t\t\t---IM the Students-Teacher process sync.---\n");
	pthread_mutex_init(&l,NULL);
	
	student[1][1]=1;
	student[2][2]=2;student[3][3]=1;
	pthread_t t_thread;
	pthread_t s_thread;
	printf("Resources Details: \n\t\tPress '1' for pen\n\t\tPress '2' for paper \n\t\tPress '3' for question paper \n"); 
	
	while(1)
	{
		if(student[1][4]==1 && student[2][4]==1 && student[3][4]==1){break;}
		pthread_create(&t_thread, NULL, teacher, NULL);
	    pthread_join(t_thread,NULL);
	    
		if((ab1==1 && ab2==2 || ab2==1 && ab1==2 ) && student[3][4]==0)
		{
			pthread_create(&s_thread, NULL, stud3, NULL);
			pthread_join(s_thread,NULL);
		}
		else if((ab1==1 && ab2==3 || ab2==1 && ab1==3 ) && student[2][4]==0)
		{
			pthread_create(&s_thread, NULL, stud2, NULL);
			pthread_join(s_thread,NULL);
		}
		else if((ab1==2 && ab2==3 || ab2==2 && ab1==3 ) && student[1][4]==0)
		{
			pthread_create(&s_thread, NULL, stud1, NULL);
			pthread_join(s_thread,NULL);
		}
		else
		{
			printf("\n\tError occured!: please try again with different choices.\n");
		}
	}
	printf("completed");
	
	
}

void *teacher()
{
	pthread_mutex_lock(&l);
	printf("\nFirst Resource on shared tabel:-\t");
	scanf("%d",&ab1);
	printf("Second Resource on shared tabel:-\t");
	scanf("%d",&ab2);
	pthread_mutex_unlock(&l);
}

void *stud2()
{	
	pthread_mutex_lock(&l);
	printf("\nChoices have = 'pen', 'question paper'\n");
	student[2][4]=1;
	printf("\n\t Student 2 has completed its assignment. \n");
	pthread_mutex_unlock(&l);
}
void *stud3()
{	
	pthread_mutex_lock(&l);
	printf("\nChoices Made = 'pen', 'paper'\n");
	student[3][4]=1;
	printf("\n\t Student 3 has completed its assignment.\n");
	pthread_mutex_unlock(&l);
}
void *stud1()
{	
	pthread_mutex_lock(&l);
	printf("\nChoices Made = 'paper', 'question_paper'\n");
	student[1][4]=1;
	printf("\n\tStudent 1 has completed its assignment.\n");	
	pthread_mutex_unlock(&l);
}
