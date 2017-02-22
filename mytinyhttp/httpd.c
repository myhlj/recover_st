#include <stdion.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

#define ISspace(x) isspace((int)(x))
#define SERVER_STRING "Server: jdbhttpd/0.1.0\r\n"

void accept_request(int);
void bad_request(int);
void cat(int,FILE*);
void cannot_execute(int);
void error_die(const char*);
void excute_cgi(int,const char*,const char*,const char*);
int get_line(int,char*,int);
void headers(int,const char*);
void not_found(int);
void serve_file(int,const char*);
int startup(u_short*);
void unimplemented(int);

void accept_request(int client)
{
	char buf[1024];
	int numchars;
	char method[255];
	char url[255];
	char path[512];
	size_t i,j;
	struct stat st;
	int cgi = 0;


	char* query_string = NULL;
	numchars = get_line(client,buf,sizeof(buf));
	i = 0; j = 0;
	
	while(!ISspace(buf[j]) && (i < sizeof(method) - 1))
	{
		method[i] = buf[j];
		i++; j++;
	}
	method[i]="\0";

	if(strcasecmp(method,"Get") && strcasecmp(method,"Post"))
	{
		unimplemented(client);
		return;
	}
	
	if(strcasecmp(method,"Post") == 0)
	{
		cgi = 0;
	}

	i = 0;
	while(ISspace(buf[j]) && (j < sizeof(buf)))
		j++;
	while(ISspace(buf[j]) && (i < sizeof(url - 1)) && (j < sizeof(buf)))
	{
		url[i] = buf[j];
		i++; j++;
	}
	url[i] = '\0';

	if(strcasecmp(method,"Get") == 0)
	{
		query_string = url;
		while((*query_string != '?') && (*query_string != '\0'))
			query_string++;
		if(query_string == '?')
		{
			cgi = 1;
			*query_string = '\0';
			query_string++;
		}
	}

}
