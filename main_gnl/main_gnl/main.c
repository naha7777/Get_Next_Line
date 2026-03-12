#include "get_next_line.h"
#include <stdio.h>

// TESTE BASIC, LONG, SHORT
// CHANGER BUFFER_SIZE
int	main()
{
	int		fd;
	char	*line;

	printf("\n------test basic-----\n");
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("erreur ouverture fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n-----teste un caractere-----\n");
	fd = open("short.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("erreur ouverture fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n-----teste BEAUCOUP de caracteres-----\n");
	fd = open("long.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("erreur ouverture fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n-----teste fichier vide-----\n");
	fd = open("empty.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("erreur ouverture fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n-----teste fichier.c-----\n");
	fd = open("main.c", O_RDONLY);
	if (fd == -1)
	{
		printf("erreur ouverture fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}


// TESTE STDIN
// int main()
// {
// 	printf("\nteste stdin\n");
// 	char	*line;
// 	while ((line = get_next_line(0)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// }


// Invalid FD
// int main(void)
// {
// 	char	*next_line;
// 	int		count;

// 	count = 0;
// 	printf("--- Test: Invalid FD (-1) ---\n");
// 	next_line = get_next_line(-1);
// 	printf("[%d]: %s\n", count, next_line);
// 	free(next_line);
// 	next_line = get_next_line(-1);
// 	printf("[%d]: %s\n", count, next_line);
// 	free(next_line);
// 	return (0);
// }


// Empty.txt 2 fois
// int main(void)
// {
// 	char	*next_line;
// 	int		count;
// 	int		fd;

// 	count = 0;
// 	fd = 0;
// 	printf("--- Test Empty.txt ---\n");
// 	fd = open("empty.txt", O_RDONLY);
// 	next_line = get_next_line(fd);
// 	printf("[%d]: %s\n", count, next_line);
// 	if (next_line == NULL)
// 		printf("[NULL]\n");
// 	free(next_line);
// 	next_line = get_next_line(fd);
// 	printf("[%d]: %s\n", count, next_line);
// 	if (next_line == NULL)
// 		printf("[NULL]\n");
// 	free(next_line);
// 	close(fd);
// 	return (0);
// }
