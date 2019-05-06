# include <string.h>
# include <stdlib.h>

int main()
{
	const char* h = "hoy es ajsdkljsdjasdkasdj;lasdkjdkasjd;ladj";
	const char* p = "viernes!!!!oidjfaoidjfdsf@#$@#AZXc";
	size_t lenh = strlen(h);
	size_t lenp = strlen(p);
	char* ss =(char*) malloc(lenh + lenp + 1); // hay que reservar memoria del '\0'
	//strcpy(ss, h);
	//strcpy(ss, p);
	//strcpy(ss + lenh, p); // mas eficiente
	memcpy(ss, h, lenh);
	memcpy(ss + lenh, p, lenp + 1);
	puts(ss);
	free(ss);
}
