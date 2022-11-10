/* Show the CGI (Common Gateway Interface) environment variables */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "PJ_RPI.h"

/* Print a basic HTTP header. */

static void print_http_header (const char * content_type)
{
    printf ("Content-Type: %s\n\n", content_type);
}

/* Handle errors by printing a plain text message. */

static void cgi_fail (const char * message)
{
    print_http_header ("text/plain");
    printf ("%s\n", message);
    exit (0);
}

int main (){
     print_http_header ("text/html");

    FILE *ptr;
    ptr = fopen("/var/www/html/students.json", "w+");
    char* data;

    data = getenv("QUERY_STRING");
    if(data == NULL)
        printf("NO DATA GIVEN");
    else{
        fseek(ptr, -2, SEEK_END);
        fputc(',',ptr);
        fputc('"',ptr);

        for(int a = 5; a < strlen(data); a++){
            if (data[a]== "^")
            {
                break;
            }
            else
            {
                fputc(data[a],ptr);
            }
        }
        fputc('"',ptr);
        fputc('}',ptr);
    }
    return 0;
}