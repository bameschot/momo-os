#include "common.h"

void putchar(char ch);

void printf(const char *format, ...){

    //setup vararg
    va_list vararg;
    va_start(vararg,format);

    //loop over the format string
    while(*format){
        char ch = *format;

        switch (ch) {
            //format specifier
            case '%':
                //skip to the next char
                ch = *(++format);
                
                switch (ch){
                    // print %
                    case '%':
                        putchar(ch);
                        break;
                    case 's':
                        const char *argumentS = va_arg(vararg, const char*);
                        while(*argumentS) {
                            putchar(*(argumentS)++);
                        }
                        break;
                    // add decimal
                    case 'd':
                        int argumentI = va_arg(vararg, int);
                        if(argumentI<0)
                            putchar('-');
                        break;                    
                    default:
                        break;
                }
            default:
                putchar(ch);
        }
        format++;
    }

    va_end(vararg);
}