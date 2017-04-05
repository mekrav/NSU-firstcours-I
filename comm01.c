#include <stdio.h>

int main() {
    char s;
    int f=0,k=0;
    FILE *in, *out;
    in=fopen("in.txt","r");
    out=fopen("out.txt","w");
    if(!feof(in))  fscanf(in,"%c",&s);
    while(!feof(in)){
        if((s=='/') && (f==0) && (k==0)
            {f=1; fscanf(in,"%c",&s);}
            else{   if(!feof(in))  fprintf(out,"/%c",s);
            }
        
        if((s=='*') && (f==1) && (k==0)){
            fscanf(in,"%c",&s);
            if(s=='/') {f=0; if(!feof(in)) fscanf(in,"%c",&s);}
        }

        if(s=='"'){
            if(k==0) k=1;
            if(k==1) k=0;
            f=0;
        }
        if(!feof(in)&&(f==0))fprintf(out,"%c",s);
        if(!feof(in)) fscanf(in,"%c",&s);

    }
    if(f==0)fprintf(out,"%c",s);
    fclose(in);
    fclose(out);
    return 0;
}
