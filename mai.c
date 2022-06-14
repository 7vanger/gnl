#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd1 = open("../textao.txt", O_RDONLY);
	int n = 0;
	while (n < 3)
	{
		printf("%s", get_next_line(fd1));
		n++;
	}
		close(fd1);
	return (0);
}
