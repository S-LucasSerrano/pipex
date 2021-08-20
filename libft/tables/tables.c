#include <stdlib.h>

/* Frees a double pointer or table that has the columns end in a NULL.
Table:
	-> void*
	-> void*
	-> NULL */
void	ft_free_table(void ***table)
{
	void	*ptr;

	ptr = *table;
	while (**table != NULL)
	{
		free(**table);
		*table += 1;
	}	
	free(ptr);
	ptr = NULL;
}
