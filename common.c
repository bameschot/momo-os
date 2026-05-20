#include "common.h"

void putchar(char ch);

/*
    returns the absolute value of an integer
*/
int abs(int val)
{
    if (val < 0)
        return val * -1;
    return val;
}

/*
    counts the number of characters (including sign, excluding string terminator) for the given integer
*/
int intCharCount(int value)
{
    int digits = 0;
    if (value < 0)
    {
        digits++;
    }
    int val = abs(value);
    while (val > 9)
    {
        digits++;
        val /= 10;
    }
    return digits;
}

/*
    creates a string for the given integer including string terminator
*/
void intToString(int value, char *str)
{
    int val = value;

    // abs the value
    int digits = intCharCount(value) + 1;
    str[digits--] = '\0';
    if (val < 0)
    {
        val = -val;
    }

    while (val > 0)
    {
        str[digits--] = (val % 10) + '0';
        val /= 10;
    }

    if (value < 0)
    {
        str[digits--] = '-';
    }
}

void printf(const char *format, ...)
{

    // setup vararg
    va_list vararg;
    va_start(vararg, format);

    // loop over the format string
    while (*format)
    {
        char ch = *format;

        switch (ch)
        {
        // format specifier
        case '%':
            // skip to the next char
            ch = *(++format);

            switch (ch)
            {
            // print %
            case '%':
            {
                putchar(ch);
                break;
            }
            case 's':
            {
                const char *argumentS = va_arg(vararg, const char *);
                while (*argumentS)
                {
                    putchar(*(argumentS)++);
                }
                break;
            }
            // add decimal
            case 'd':
            {
                int argumentI = va_arg(vararg, int);
                char intStr[intCharCount(argumentI) + 1];
                intToString(argumentI, intStr);
                for (int i = 0; intStr[i] != '\0'; i++)
                {
                    putchar(intStr[i]);
                }

                break;
            }
            default:
            {
                break;
            }
            }
            break;
        default:
            putchar(ch);
        }
        format++;
    }

    va_end(vararg);
}
