/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "../csapp.h"

int main(){
    char *buf, *p;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
    int n1=0, n2=0;

    /* read environmental variable QUERY_STRING */
    if((buf = getenv("QUERY_STRING")) != NULL){
        p = strchr(buf, '&'); // p is the pointer for "&"
        *p = '\0';            // sperate into two array
        sscanf(buf, "arg1=%d", &n1);
        sscanf(p+1, "arg2=%d", &n2);
    }

    sprintf(content, "QUERY_STRING=%d&%d<p>", n1, n2);
    sprintf(content, "%sWelcome to add.com: ", content);
    sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
    sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", content, n1, n2, n1+n2);  
    sprintf(content, "%sThanks for visiting!\r\n", content);

    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);  
    fflush(stdout);
    exit(0);
}
