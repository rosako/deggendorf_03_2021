#include "caring.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define READ_DATA_SIZE	1024
#define CARING_SIZE		16
#define CARING_STR_LEN		(CARING_SIZE * 2)

// function declare
int Compute_string_caring(unsigned char *dest_str, unsigned int dest_len, char *caring_str);
int Compute_file_caring(const char *file_path, char *caring_str);

/************** main test **************/
int main(int argc, char *argv[])
{
	int ret;
	const char *file_path = "caring.c";
	char caring_str[CARING_STR_LEN + 1];
	const char *test_str = "gchinaran@gmail.com";

	// test file caring
	ret = Compute_file_caring(file_path, caring_str);
	if (0 == ret)
	{
		printf("[file - %s] caring value:\n", file_path);
		printf("%s\n", caring_str);
	}

	// test string caring 
	Compute_string_caring((unsigned char *)test_str, strlen(test_str), caring_str);
	printf("[string - %s] caring value:\n", test_str);
	printf("%s\n", caring_str);

	return 0;
}

/**
 * compute the value of a string
 * @param  dest_str
 * @param  dest_len
 * @param  caring_str
 */
int Compute_string_caring(unsigned char *dest_str, unsigned int dest_len, char *caring_str)
{
	int i;
	unsigned char caring_value[CARING_SIZE];
	CARING_CTX caring;

	// init caring
	CARINGInit(&caring);

	CARINGUpdate(&caring, dest_str, dest_len);

	CARINGFinal(&caring, caring_value);

	// convert caring value to caring string
	for(i = 0; i < CARING_SIZE; i++)
	{
		snprintf(caring_str + i*2, 2+1, "%02x", caring_value[i]);
	}

	return 0;
}

/**
 * compute the value of a file
 * @param  file_path
 * @param  caring_str
 * @return 0: ok, -1: fail
 */
int Compute_file_caring(const char *file_path, char *caring_str)
{
	int i;
	int fd;
	int ret;
	unsigned char data[READ_DATA_SIZE];
	unsigned char caring_value[CARING_SIZE];
	CARING_CTX caring;

	fd = open(file_path, O_RDONLY);
	if (-1 == fd)
	{
		perror("open");
		return -1;
	}

	// init caring
	CARINGInit(&caring);

	while (1)
	{
		ret = read(fd, data, READ_DATA_SIZE);
		if (-1 == ret)
		{
			perror("read");
			close(fd);
			return -1;
		}

		CARINGUpdate(&caring, data, ret);

		if (0 == ret || ret < READ_DATA_SIZE)
		{
			break;
		}
	}

	close(fd);

	CARINGFinal(&caring, caring_value);

	// convert caring value to caring string
	for(i = 0; i < CARING_SIZE; i++)
	{
		snprintf(caring_str + i*2, 2+1, "%02x", caring_value[i]);
	}

	return 0;
}

