#include<stdio.h>
#include<stdlib.h>

int menu_func();
struct lin_queue *create_node();
struct lin_queue *deque_node(struct lin_queue *);

struct lin_queue
{
	int data;
	struct lin_queue *next;
};

int main()
{

	int choice, num_nod, lv;
	struct lin_queue *start, *rear;
	start = rear = NULL;
	while(1)
	{
		choice = menu_func();
		if(choice == 0)
			return 0;
		else if(start == NULL)
		{
			start = rear = create_node();
		}
		else if(choice == 1)
		{
			printf("Node is already created\n");
		}
		else if(choice == 2 && start != NULL)
		{
			printf("How many time you want to create node\n");
			scanf("%d", &num_nod);
			for(lv = 0; lv < num_nod; lv++)
			{
				rear->next = create_node();
				rear = rear->next;
			}
		}
		else if(choice == 3)
		{
			start = deque_node(start);
		}
		else if(choice == 5)
		{
			count_nod(start);
		}
		else if(choice == 6)
		{
			display_que(start);
		}
	}
}

int menu_func()
{
	int choice;
	printf("\n");
	printf("Press 0 for exit\n");
	printf("Press 1 to  create starting node\n");
	printf("Press 2 for the Enque of n node\n");
	printf("Press 3 for the Deque\n");
	printf("Press 4 for the Enque node at the rearer\n");
	printf("Press 5 to  now the size of the queue\n");
	printf("Press 6 to  display queue\n");

	scanf("%d", &choice);
	printf("\n");

	return choice;
}

struct lin_queue *create_node()
{
	struct lin_queue *start;
	start = (struct lin_queue *)malloc(sizeof(struct lin_queue));	
	printf("Enter the data\n");
	scanf("%d", &start->data);
	start->next = NULL;
	return start;

}

struct lin_queue * deque_node(struct lin_queue *start)
{
	struct lin_queue *first;
	first = start;
	first = start->next;
	free(start);
	start = NULL;
	start = first;
	return start;
	 
}

int count_nod(struct lin_queue *start)
{
	int no_node;
	no_node = 0;
	while(start)
	{
		no_node++;
		start = start->next;
	}
	printf("Number of node are %d\n", no_node);
	return 0;
}

int display_que(struct lin_queue *start)
{
	int num;
	num = 1;
	while(start->next != NULL)
	{
		printf("The data in the %d node is %d\n", num, start->data);
		start = start->next;
		num++;
	}
	printf("The data in the %d node is %d\n", num, start->data);
}
