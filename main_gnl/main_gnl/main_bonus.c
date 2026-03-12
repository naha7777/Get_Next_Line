#include "get_next_line_bonus.h"
#include <stdio.h>

// affiche 2 lignes
int	main(void)
{
	int		j;
	j = 3;

	int		fds[j];
	int		i;
	char	*line;

	i = 0;
	fds[0] = open("short.txt", O_RDONLY);
	fds[1] = open("long.txt", O_RDONLY);
	fds[2] = open("test.txt", O_RDONLY);
	// Ligne 1 de chaque fichier
	while (i < j)
	{
		line = get_next_line(fds[i]);
		printf("\nLigne 1 du fichier %d : \n%s\n\n", i, line);
		free(line);
		i++;
	}
	// Ligne 2 de chaque fichier
	i = 0;
	while (i < j)
	{
		line = get_next_line(fds[i]);
		printf("\nLigne 2 du fichier %d : \n%s\n\n", i, line);
		free(line);
		i++;
	}
	// VIDER TOUS LES BUFFERS RESTANTS
	i = 0;
	while (i < j)
	{
		while ((line = get_next_line(fds[i])) != NULL)
			free(line);
		i++;
	}
	close(fds[0]);
	close(fds[1]);
	close(fds[2]);
	return (0);
}

// int main(void)
// {
//     int     j = 3;
//     int     fds[j];
//     int     i = 0;
//     char    *line;
//     int     ligne_num = 1;
//     int     encore_des_lignes;

//     fds[0] = open("short.txt", O_RDONLY);
//     fds[1] = open("long.txt", O_RDONLY);
//     fds[2] = open("test.txt", O_RDONLY);

//     encore_des_lignes = 1;
//     while (encore_des_lignes)
//     {
//         encore_des_lignes = 0;
//         i = 0;
//         while (i < j)
//         {
//             line = get_next_line(fds[i]);
//             if (line != NULL)
//             {
//                 printf("\nLigne %d du fichier %d : \n%s\n", ligne_num, i, line);
//                 free(line);
//                 encore_des_lignes = 1;  // Au moins un fichier a encore des lignes
//             }
//             i++;
//         }
//         ligne_num++;
// 	}
//     close(fds[0]);
//     close(fds[1]);
//     close(fds[2]);
//     return (0);
// }


// int main(void)
// {
//     int     j = 3;
//     int     fds[j];
//     int     i = 0;
//     char    *line;
//     int     ligne_num = 1;
//     int     encore_des_lignes;

//     fds[0] = open("short.txt", O_RDONLY);
//     fds[1] = open("long.txt", O_RDONLY);
//     fds[2] = open("test.txt", O_RDONLY);

//     encore_des_lignes = 1;
//     while (encore_des_lignes)
//     {
//         encore_des_lignes = 0;
//         i = 0;
//         while (i < j)
//         {
//             line = get_next_line(fds[i]);
//             if (line != NULL)
//             {
//                 printf("\nLigne %d du fichier %d : %s", ligne_num, i, line);
//                 free(line);
//                 encore_des_lignes = 1;
//             }
//             else
//             {
//                 printf("\nLigne %d du fichier %d : null\n", ligne_num, i);
//             }
//             i++;
//         }
//         ligne_num++;
//     }

//     close(fds[0]);
//     close(fds[1]);
//     close(fds[2]);
//     return (0);
// }

