#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd1 = open("../textao.txt", O_RDONLY);
		printf("%s", get_next_line(fd1));
		close(fd1);
	return (0);
}
