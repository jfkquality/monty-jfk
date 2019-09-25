#include "monty.h"

/* does nothing? */
void nop(stack_t **s, unsigned int n)
{
        (void) s;
        (void) n;
}
void mod(stack_t **s, unsigned int n)
{
        int len = 0, total;

        stack_t *temp = *s, *a, *b;

        while (temp)
        {
                len++;
                temp = temp->next;
        }

        if (len < 2)
        {
                printf("L%d: can't mod, stack too short\n", n);
                exit(EXIT_FAILURE);
        }

        a = *s;
        b = (*s)->next;
        a->next = b->next;
        if (b->next)
                b->next->prev = a;
        total = b->n % a->n;
        a->n = total;
        free(b);
}
void mul(stack_t **s, unsigned int n)
{
        int len = 0, total;

        stack_t *temp = *s, *a, *b;

        while (temp)
        {
                len++;
                temp = temp->next;
        }

        if (len < 2)
        {
                printf("L%d: can't mul, stack too short\n", n);
                exit(EXIT_FAILURE);
        }

        a = *s;
        b = (*s)->next;
        a->next = b->next;
        if (b->next)
                b->next->prev = a;
        total = a->n * b->n;
        a->n = total;
        free(b);
}
void divi(stack_t **s, unsigned int n)
{
        int len = 0, total;

        stack_t *temp = *s, *a, *b;

        while (temp)
        {
                len++;
                temp = temp->next;
        }

        if (len < 2)
        {
                printf("L%d: can't div, stack too short\n", n);
                exit(EXIT_FAILURE);
        }

        a = *s;
        b = (*s)->next;
        a->next = b->next;
        if (b->next)
                b->next->prev = a;
        total = b->n / a->n;
        a->n = total;
        free(b);
}
void sub(stack_t **s, unsigned int n)
{
        int len = 0, total;

        stack_t *temp = *s, *a, *b;

        while (temp)
        {
                len++;
                temp = temp->next;
        }

        if (len < 2)
        {
                printf("L%d: can't sub, stack too short\n", n);
                exit(EXIT_FAILURE);
        }

        a = *s;
        b = (*s)->next;
        a->next = b->next;
        if (b->next)
                b->next->prev = a;
        total = b->n - a->n;
        a->n = total;
        free(b);
}
/* adds top 2 elements */
void add(stack_t **s, unsigned int n)
{
        int len = 0, total;

        stack_t *temp = *s, *a, *b;

        while (temp)
        {
                len++;
                temp = temp->next;
        }

        if (len < 2)
        {
                printf("L%d: can't add, stack too short\n", n);
                exit(EXIT_FAILURE);
        }
        a = *s;
        b = (*s)->next;
        a->next = b->next;
        if (b->next)
                b->next->prev = a;
        total = a->n + b->n;
        a->n = total;
        free(b);
}
/* swaps top 2 elements */
void swap(stack_t **s, unsigned int n)
{
        int len = 0;

        stack_t *temp = *s, *a, *b;

        while (temp)
        {
                len++;
                temp = temp->next;
        }

        if (len < 2)
        {
                printf("L%d: can't swap, stack too short\n", n);
                exit(EXIT_FAILURE);
        }

        a = *s;
        b = (*s)->next;
        a->next = b->next;
        if (b->next)
                b->next->prev = a;
        b->next = a;
        a->prev = b;
        b->prev = NULL;
        *s = b;
}
/* prints top of stack */
void pint(stack_t **s, unsigned int n)
{
        (void) s;
        (void) n;

	if (!*s)
	{
		printf("LLL: can't pint, stack empty\n"); /* , n); */
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*s)->n);
}
/* prints all values on stack from top */
void pall(stack_t **s, unsigned int n)
{
        stack_t *temp;
        (void) n;

        temp = *s;

        while (temp)
        {
                printf("%d\n", temp->n);
                temp = temp->next;
        }
}
/* removes top element */
void pop(stack_t **s, unsigned int n)
{
	stack_t *temp;
        (void) s;
        (void) n;

	temp = *s;

	if (!*s)
	{
		printf("L%d: can't pop an empty stack\n", n);
		free(s);
		exit(EXIT_FAILURE);
	}
	if (!temp->next)
	{
		free(temp);
		free(s);
		exit(EXIT_SUCCESS);
	}
	else
	{
		(*s)->next->prev = NULL;
		*s = (*s)->next;
	}
	free(temp);
}
/* pushes element onto stack */
void push(stack_t **s, unsigned int n, int value)
{
        stack_t *new;
	stack_t *current;

        (void) n;

	new = malloc(sizeof(stack_t));
        if (new == NULL)
        {
                dprintf(2, "Error: Can't malloc\n");
                exit(EXIT_FAILURE);
        }
	new->n = value;

        if (*s == NULL)
                *s = new;
	else
	{
		if (!stacktoq) /* stack: add to top */
		{
			new->next = *s;
			(*s)->prev = new;
			*s = new;
		}
		else /* queue: add to bottom */
		{
			current = *s;
			while (current->next)
				current = current->next;
			current->next = new;
			new->prev = current;
		}
	}
}
/* pchar - print char of ascii code pushed to stack */
void pchar(stack_t **s, unsigned int n)
{
	stack_t *head;

	head = *s;

	if (!head)
	{
		printf("L%d: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	if (head->n < 0 || head->n > 127)
	{
		printf("L%d: can't pchar, value out of range\n", n);
		exit(EXIT_FAILURE);
	}
	putchar((*s)->n);
	putchar('\n');
}
/* pstr - print chars of entire stack, i.e. a string */
void pstr(stack_t **s, unsigned int n)
{
	stack_t *head;

	(void) s;
	(void) n;

	head = *s;

	while (head->next && head->n > 0 && head->n <= 127)
	{
		putchar(head->n);
		head = head->next;
	}
	putchar('\n');
}
/* rotl - rotate stack to top */
void rotl(stack_t **s, unsigned int n)
{
	stack_t *head, *tail;

	(void) s;
	(void) n;

	head = *s;
	/**
	 * store head.
	 * - temp = head
	 * - tail = head
	 * iterate to bottom/tail of stack.
	 * - tail = tail.next
	 * make head the new tail
	 * - tail.next = head
	 * - head.prev = tail
	 * make head.next the new head
	 * - head.next.prev = null
	 * - *s = head.next
	 * - head.next = null
	 */

	head = *s;
	tail = head;

	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = head;
	head->prev = tail;
	head->next->prev = NULL;
	*s = head->next;
	head->next = NULL;
}
/* rotr - rotate stack to bottom */
void rotr(stack_t **s, unsigned int n)
{
	stack_t *head, *tail;

	(void) s;
	(void) n;

	head = *s;
	tail = head;

	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = head->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	head->prev = tail;
	*s = tail;

	/* head->next = NULL; */
}
/* stack - change data to a stack (LIFO, default) */
void stack(stack_t **s, unsigned int n)
{
	stacktoq = 0;

	(void) s;
	(void) n;
	/* (void) stacktoq; */

}
/* queue - change data to a queue (FIFO) */
void queue(stack_t **s, unsigned int n)
{
	stacktoq = 1;

	(void) s;
	(void) n;
	/* (void) stacktoq; */
}
/* comments */
void comments(stack_t **s, unsigned int n)
{
	/* if 1st non-space char is "#": is comment; do nothing" */
	(void) s;
	(void) n;
	/* (void) str; */
}
/* get function */
void (*get_function(char *s)) (stack_t **s, unsigned int n)
{
        instruction_t funcs[] = {
                {"pall", pall},
                {"pint", pint},
                {"pop", pop},
                {"swap", swap},
                {"add", add},
                {"nop", nop},
                {"sub", sub},
                {"div", divi},
                {"mul", mul},
                {"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{"comments", comments},
                {NULL, NULL}
        };

        int i = 0;

        while (funcs[i].opcode)
        {
                if (strcmp(s, funcs[i].opcode) == 0)
                        return (funcs[i].f);
                i++;
        }
        return (NULL);
}
char **parse_space(char *s, char *buffer[])
{
        char delim[] = " ";
        char *token;
        int i = 0;

        token = strtok(s, delim);

        while (token)
        {
                buffer[i] = token;
                token = strtok(NULL, delim);
                i++;
        }
        if (buffer[0] == NULL)
                return (NULL);
        return (buffer);
}
/* parse at newline and space */
char **parse(char *s, char *buffer[])
{
        char delim[] = "\n";
        char *token;
        int i = 0;

        token = strtok(s, delim);

        while (token)
        {
                buffer[i] = token;
                token = strtok(NULL, delim);
                i++;
        }
        if (buffer[0] == NULL)
                return (NULL);
        return (buffer);
}
void free_list(stack_t **s)
{
        stack_t *temp;

        while (*s)
        {
                temp = *s;
                *s = (*s)->next;
                free(temp);
        }
        free(s);
}
/* entry */
int main(int argc, char *argv[])
{
        int fd, i, line = 1, value, stacktoq = 0;
        char temp[1000], *split[1000], *split2[100], temp2[100];
        stack_t **stack;

	(void) stacktoq;

        memset(temp, 0, 1000);
        memset(split, 0, sizeof(split));
        if (argc != 2)
        {
                printf("USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }

        fd = open(argv[1], O_RDONLY);
        read(fd, temp, 1000);

        parse(temp, split);

        stack = malloc(sizeof(stack_t *));
        *stack = NULL;

        for (i = 0; split[i]; i++)
        {
                memcpy(temp2, split[i], 100);
                parse_space(temp2, split2);

                if (strcmp(split2[0], "push") == 0)
                {
                        value = atoi(split2[1]);
                        push(stack, line, value);
                }
                else if (get_function(split2[0]))
                        get_function(split[i])(stack, line);
                else
                {
                        printf("L%d: unknown instruction %s\n", line, split2[0]);
                        exit(EXIT_FAILURE);
                }
                line++;
        }
        free_list(stack);
        return (0);
}
