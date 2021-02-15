/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_romeu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:08:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/15 11:50:20 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include "ft_ansi.h"

void	doprint(int out, char **str, size_t line)
{
	printf(ANSI_F_CYAN "%zu (%d)" ANSI_RESET "\t|%s" ANSI_F_CYAN "$\n" ANSI_RESET, line, out, *str);
	free(*str);
	*str = NULL;
}

void	test(int fd)
{
	char	*st;
	int		out;
	size_t	i;

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
	fd = open("../test1.Mazoise.42TESTERS-GNL/files/mix_marge1", O_RDONLY);
	fd2 = open("../test1.Mazoise.42TESTERS-GNL/files/mix_marge2", O_RDONLY);
	
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

void	test_basic(void)
{
	size_t	line_count;
	char	*line;
	int		fd;
	int		out = 1;

	line_count = 0;
	line = NULL;
	printf("Opening file... ");
	fd = open("../test3.TinfoilPancakes.get-next-line-testing-tools/test_basic_dino.txt", O_RDONLY);
	if (fd < 0)
	{
		printf(ANSI_F_RED "Error opening %s.\n" ANSI_RESET, "test_basic_dino.txt");
		return ;
	}
	printf("Done.\n");
	printf(ANSI_F_YELLOW "Reading Lines...\n" ANSI_RESET);
	while (out == 1)
	{
		out = get_next_line(fd, &line);
		doprint(out, &line, ++line_count);
	}
	if (line_count != 13)
		printf(ANSI_F_RED "ERROR: test_basic(...) failed.\n" ANSI_RESET);
	else
		printf(ANSI_F_GREEN "Done.\n" ANSI_RESET);
	printf(ANSI_F_YELLOW "[ Lines Expected: 13, Lines Read: %zu ]\n" ANSI_RESET, line_count);
	fd = close(fd);
	if (fd < 0)
	{
		printf(ANSI_F_BRED "Fatal Error: Could not close open file.\n" ANSI_RESET);
		exit(EXIT_FAILURE);
	}
}

void	test_poems(void)
{
	size_t	line_count;
	char	*line;
	int		fd_i;
	int		fd_a;
	int		fd_b;
	int		out;

	line = NULL;
	line_count = 0;
	fd_i = open("../test3.TinfoilPancakes.get-next-line-testing-tools/timmy_test_interleave.txt", O_RDONLY);
	fd_a = open("../test3.TinfoilPancakes.get-next-line-testing-tools/timmy_test_a.txt", O_RDONLY);
	fd_b = open("../test3.TinfoilPancakes.get-next-line-testing-tools/timmy_test_b.txt", O_RDONLY);
	if (fd_i < 0 || fd_a < 0 || fd_b < 0)
	{
		printf(ANSI_F_RED "Error opening files.\n" ANSI_RESET);
		return ;
	}
	printf(ANSI_F_YELLOW "Starting interleaved file read test...\n\n" ANSI_RESET);
	line_count = 0;
	while (line_count < 4)
	{
		out = get_next_line(fd_i, &line);
		doprint(out, &line, ++line_count);
	}
	out = 1;
	while (out == 1)
	{
		out = get_next_line(fd_a, &line);
		doprint(out, &line, ++line_count);
	}
	get_next_line(fd_i, &line);
	doprint(out, &line, ++line_count);
	
	out = 1;
	while (out == 1)
	{
		out = get_next_line(fd_b, &line);
		doprint(out, &line, ++line_count);
	}

	out = 1;
	while (out == 1)
	{
		out = get_next_line(fd_i, &line);
		doprint(out, &line, ++line_count);
	}
	
	if (line_count != 45)
		printf(ANSI_F_RED "\nERROR: Interleaved files test failed! [ test_poems(...); ]\n" ANSI_RESET);
	else
		printf(ANSI_F_GREEN "\nDone.\n" ANSI_RESET);
	printf(ANSI_F_YELLOW "[ Lines Expected: 45, Lines Read: %zu ]\n" ANSI_RESET, line_count);
	fd_i = close(fd_i);
	fd_a = close(fd_a);
	fd_b = close(fd_b);
	if (fd_i < 0 || fd_a < 0 || fd_b < 0)
	{
		printf(ANSI_F_BRED "Fatal Error: Could not close open files!\n" ANSI_RESET);
		exit(EXIT_FAILURE);
	}
}

void	test_null_cases(void)
{
	char	*line;
	int		temp_fd;
	size_t	line_count;
	int		out;

	line = NULL;
	line_count = 0;
	temp_fd = open("../test3.TinfoilPancakes.get-next-line-testing-tools/test_null_cases.txt", O_RDONLY);
	printf("Testing failure cases...\n");
	printf("Passing NULL pointer to line parameter of get_next_line(...)\n");
	get_next_line(temp_fd, NULL);
	printf("Passing invalid file descriptor (fd = -1)...\n");
	get_next_line(-1, &line);
	printf("Passing invalid file descriptor and line pointer...\n");
	printf(ANSI_F_GREEN "Done.\n" ANSI_RESET "As a prize here is some text:\n\n");
	if (temp_fd < 0)
	{
		printf(ANSI_F_RED "Nevermind. The file couln't be opened so you get nothing :C\n" ANSI_RESET);
		return ;
	}

	out = 1;
	while (out == 1)
	{
		out = get_next_line(temp_fd, &line);
		doprint(out, &line, ++line_count);
	}
	
	if (line_count == 16)
		printf("\nDid you enjoy your prize? Yes? Okay let's move on.\n");
	else
		printf(ANSI_F_RED "Hey! Your prize isn't working properly! What's going on?\n" ANSI_RESET);
	printf(ANSI_F_YELLOW "[ Prize lines read: %zu, Prize lines expected: 16 ]\n" ANSI_RESET, line_count);
	temp_fd = close(temp_fd);
	if (temp_fd < 0)
	{
		printf("Fatal Error: Could not close open file!\n");
		exit(EXIT_FAILURE);
	}
}

int		main(void)
{
	//testfd();
	test(0);
	testfile("../test2.mrjvs.42cursus_gnl_tests/tests/normal/5.txt");
	testfile("../test2.mrjvs.42cursus_gnl_tests/tests/normal/1.txt");
	testfile("../test2.mrjvs.42cursus_gnl_tests/tests/normal/2.txt");
	testfile("teste1.txt");
	testfile("../test1.Mazoise.42TESTERS-GNL/files/alphabet");
	testfile("../test1.Mazoise.42TESTERS-GNL/files/huge_alphabet");
	testfile("../test1.Mazoise.42TESTERS-GNL/files/mix_marge1");
	testfile("../test1.Mazoise.42TESTERS-GNL/files/mix_marge2");
	//testfile("../test3.TinfoilPancakes/timmy_test_a.txt");


	testmultiple();
	testmarge();
	test_basic();
	test_poems();
	test_null_cases();
}
