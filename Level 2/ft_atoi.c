/**
 * 
 * the line 'result = result * 10 + *str - '0' is used to convert 
 * a string of digits to an integer value 
 * by multiplying the current value of the integer 
 * by 10
 * and adding the value of the current digit. */

int ft_atoi(char *str)
{
    int result = 0;
    int sign = 1;

    while(*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + *str - '0';
        str++;
    }
    return (sign * result);
}


int ft_atoi(char *str)
{
    int res = 0;
    int sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + *str - '0';
        str++;
    }
    return (sign * res);
}
