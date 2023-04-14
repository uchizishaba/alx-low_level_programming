#include "main.h"

/**
 * append_text_to_file - apthis function pends text at the end of a file
 * @filename: fil ename that will be written
 * @text_content: the added content
 * Return: 1 if the file exists. -1 if the fails doesn't exist or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int rwr;
	int fid;
	int nlet;

	if (!filename)
		return (-1);

	fid = open(filename, O_WRONLY | O_APPEND);

	if (fid == -1)
		return (-1);

	if (text_content)
	{
		for (nlet = 0; text_content[nlet]; nlet++)
			;

		rwr = write(fid, text_content, nlet);

		if (rwr == -1)
			return (-1);
	}

	close(fid);

	return (1);
}
