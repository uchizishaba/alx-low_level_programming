#include "main.h"

/**
 * create_file - this function creates a file
 * @filename: file name to be created
 * @text_content: content writed in the file
 * Return: 1 if it works. -1 if it fails
 */
int create_file(const char *filename, char *text_content)
{
	int rwr;
	int fid;
	int nlet;

	if (!filename)
		return (-1);

	fid = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fid == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nlet = 0; text_content[nlet]; nlet++)
		;

	rwr = write(fid, text_content, nlet);

	if (rwr == -1)
		return (-1);

	close(fid);

	return (1);
}
