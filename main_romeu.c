/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_romeu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:08:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/31 16:40:25 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

void	doprint(int out, char **str, int line)
{
	printf("(LINE %i) [OUT %i] |%s|\n", line, out, *str);
	free(*str);
	*str = NULL;
}

void	test(int fd)
{
	char	*st;
	int		out;
	int		i;

	st = NULL;
	i = 1;
	out = 1;
	while (out == 1)
	{
		out = get_next_line(fd, &st);
		doprint(out, &st, i++);
	}
	close(fd);
}

int		testfile(char *filename)
{
	int fd;
	
	fd = open(filename, O_RDONLY);
	test(fd);

	// int		fd;
	// int		i;
	// int		j;
	// char	*line;

	// line = 0;
	// j = 1;
	// printf("\n\n=== TESTE - %s - BUFF_SIZE:%d ===\n\n", filename, BUFFER_SIZE);
	// if (!(fd = open(filename, O_RDONLY)))
	// {
	// 	printf("\nError in open\n");
	// 	return (0);
	// }
	// while ((i = get_next_line(fd, &line)) > 0)
	// {
	// 	printf("[OUT %d] |%s|\n", i, line);
	// 	free(line);
	// 	j++;
	// }
	// printf("[OUT %d] |%s|\n", i, line);
	// free(line);
	// close(fd);
	return (0);
}

int		testfd(void)
{
	char	*line;

	line = 0;
	printf("\n==========================================\n");
	printf("========= TEST 8 : Wrong Input ===========\n");
	printf("==========================================\n\n");
	if (get_next_line(180, &line) == -1)
		printf("Well Done, you return -1 if no FD\n\n");
	else
		printf("Not Good, you don't return -1 if no FD\n\n");
	return (0);
}

void	testmultiple()
{
	char	*st;
	int		i;
	int		i2;
	
	int		fd;
	int		fd2;
	fd = open("../test2.mrjvs/tests/bonus/1.txt", O_RDONLY);
	fd2 = open("../test2.mrjvs/tests/bonus/2.txt", O_RDONLY);
	

	printf("\n==========================================\n");
	printf("========= TEST : BONUS ===================\n");
	printf("==========================================\n\n");
	st = NULL;
	i = 1;
	i2 = 1;
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd, &st), &st, i++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	doprint(get_next_line(fd2, &st), &st, i2++);
	close(fd);
	close(fd2);
}

int	testmarge()
{
	printf("\n==========================================\n");
	printf("============= TEST 7 : Marge =============\n");
	printf("==========================================\n\n");
	
	int		fd;
	int		i;
	int		j;
	char	*line = 0;
	int		fd2;

	j = 1;
	fd = open("../test1.Mazoise/files/mix_marge1", O_RDONLY);
	fd2 = open("../test1.Mazoise/files/mix_marge2", O_RDONLY);
	
	while (j < 8)
	{
		if ((i = get_next_line(fd, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	while (j < 13)
	{
		if ((i = get_next_line(fd2, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd2, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	if ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	free(line);
	j++;
	while (j < 23)
	{
		if ((i = get_next_line(fd2, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);
	j++;
	while (j < 25)
	{
		if ((i = get_next_line(fd, &line)) > 0)
			printf("%s\n", line);
		free(line);
		j++;
	}
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);
	return (0);
}


int		main(void)
{
	// testfd();
	//testfile("../test2.mrjvs/tests/normal/5.txt");
	//testfile("../test2.mrjvs/tests/normal/1.txt");
	//testfile("../test2.mrjvs/tests/normal/2.txt");
	//testfile("teste1.txt");
	//testfile("../test1.Mazoise/files/alphabet");
	//testfile("../test1.Mazoise/files/huge_alphabet");
	//testfile("../test1.Mazoise/files/mix_marge1");
	//testfile("../test1.Mazoise/files/mix_marge2");
	//test(0);

	//testmultiple();
	testmarge();
}
