#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MACROS 50
#define MAX_LEN 100
struct Macro
{
        char name[MAX_LEN];
        char value[MAX_LEN];
};

struct Macro macros[MAX_MACROS];
int macro_count=0;

void store_macro(char *line)
{
        sscanf(line,"#define %s %s",
                        macros[macro_count].name,
                        macros[macro_count].value);
        macro_count++;
}

void replace_macros(char *line,FILE *fp)
{
        char word[MAX_LEN];
        int i=0,j=0,k;
                while(line[i])
        {
                if(isalnum(line[i]) || line[i]=='_')
                {
                        j=0;

                        while(isalnum(line[i]) || line[i]=='_')
                        {
                                word[j++]=line[i++];
                        }
                        word[j]='\0';
                        int found=0;
                        for(k=0;k<macro_count;k++)
                        {
                             if(strcmp(word,macros[k].name)==0)
                                {
                                fprintf(fp,"%s",macros[k].value);
                                found=1;
                                break;
                                }
                        }
                        if(found==0)
                        {
                        fprintf(fp,"%s",word);
                        }
                        }
                        else
                        {
                         fputc(line[i],fp);
                         i++;
                        }
        }
    }


void process_include(char *line,FILE *fp)

{

        char filename[MAX_LEN];
        FILE *fpin;
        int ch;
        sscanf(line,"#include <%[^>]>",filename);
        printf("including: %s\n",filename);
        fpin=fopen(filename,"r");
                if(fpin==NULL)
                {
                        printf("cannot open include file %s\n",filename);
                        return;
                }
        while((ch=fgetc(fpin))!=EOF)
        {
                fputc(ch,fp);
        }
        fclose(fpin);
}


int main(int argc,char *argv[])
{
        FILE *fpin,*fpout;
        char line[500];
        char outfile[1000];
        int in_multiline_comment=0;
        if(argc!=2)
        {
                printf("wrong input - usage: ./preprocessor inputfile.c\n");
                return 0;
        }

        fpin=fopen(argv[1],"r");
        if(fpin==NULL)
        {
                printf("input file not found");
                return 0;
        }
        strcpy(outfile,argv[1]);
        char *dot =strrchr(outfile,'.');
        if(dot)
        {
                strcpy(dot,".i");
                        }
        else
        {
                strcat(outfile,".i");
        }
        fpout=fopen(outfile,"w");
        while(fgets(line,sizeof(line),fpin))
        {
                char cleaned[500];
                int i=0,j=0;
                while(line[i])
                {
                        if(in_multiline_comment)
                        {
                                if(line[i]=='*' && line[i+1]=='/')
                                {
                                        in_multiline_comment=0;
                                        i+=2;
                                }
                                else
                                {
                                        i++;
                                }
                        }
                        else if(line[i]=='/' && line[i+1]=='/')
                        {
                                break;
                        }
                        else if(line[i]=='/' && line[i+1]=='*')
                        {
                                in_multiline_comment=1;
                                i+=2;
                        }
                        else
                        {
                                cleaned[j++]=line[i++];
                        }
                }
                cleaned[j]='\0';
                if(strchr(line,'\n') && !strchr(cleaned,'\n'))
				{
				    cleaned[j++] = '\n';
				    cleaned[j] = '\0';
				}
				if(j==0)
				{
				    fprintf(fpout,"\n");
				    continue;
				}
                if(strncmp(cleaned,"#define",7)==0)
                {
                        store_macro(cleaned);
                }
                else if(strncmp(cleaned,"#include",8)==0)
                {
                        process_include(cleaned,fpout);
                }
                else
                {
                        replace_macros(cleaned,fpout);
                }
        }
        fclose(fpin);
        fclose(fpout);
        printf("output generate: %s\n",outfile);
        return 0;
}

