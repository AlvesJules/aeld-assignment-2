#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    openlog("writer", 0, LOG_USER);
	if (argc != 3) {
		syslog(LOG_ERR, "Expected 2 arguments: <writefile> <writestr>, got %d", argc - 1);
        	fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        return 1;
	}

	const char *writefile = argv[1];
	const char *writestr  = argv[2];
	
	FILE *file = fopen(writefile, "w");
	if (file == NULL) {
		syslog(LOG_ERR, "Cannot open file %s", writefile);
		return 1;
	}
	
	if (fprintf(file, "%s\n", writestr) < 0) {
		syslog(LOG_ERR, "Cannot write to file %s", writefile);
		fclose(file);
		return 1;
	}
	
	if (fclose(file) != 0) {
	    syslog(LOG_ERR, "Error closing file %s", writefile);
	    return 1;
	}

	syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
	return 0;
}
