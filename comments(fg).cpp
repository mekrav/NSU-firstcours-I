#include <stdio.h>
bool kov(char w) {
    bool ff=false;
    if ((w == '\'') || (w == '\"')) {
        if (!ff) ff = true; else ff = false;
    }
    return ff;
}
int main(){
    FILE *in, *out;
    char w,n;
    bool flag = false, flag1 = false;

    in=fopen("in.txt","r");
    out=fopen("out.txt", "w");
    fscanf(in, "%c", &w);
    while (!feof(in)) {
        if (!flag) {
            if (w != '/') {
                /*if (w == '\n') fprintf(out, "%c", '\n'); else*/ fprintf(out, "%c", w);
            }
            else {
                fscanf(in, "%c", &n);
                if (n != '*') { fprintf(out, "%c", w); flag1 = 1; w = n; }
                else { if (!kov(n)) flag = true; else { fprintf(out, "%c%c", w, n); } }
            }
        }
        else {
            if (w == '*') {
                fscanf(in, "%c", &n);
                kov(n);
                if (n == '/') if(!kov(n)) flag = false; else {
                        w = n;
                        flag1 = true;
                    }
            }
        }
        if (!flag1) {
            fscanf(in, "%c", &w);
        }
        flag1 = false;
    }
    fclose(in);
    fclose(out);
    return 0;
}
