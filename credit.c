#include<stdio.h>
#include<cs50.h>

int calc(long long);
int fnum(long long);
int typer(int);
int digver(long long);

int main(void)
{
    long long num;

    num = get_long_long("Number: ");

    //printf("fnum %i\ntyper %i\ndigver %i\ncalc %i\n", fnum(num), typer(fnum(num)), digver(num), calc(num));

    if (calc(num) == 0)
    {
        if (typer(fnum(num)) == 1 && digver(num) == 15)
        {
            printf("AMEX\n");
        }
        else if (typer(fnum(num)) == 2 && digver(num) == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (typer(fnum(num)) == 3 && (digver(num) == 13 || digver(num) == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

// Classifies card by provider
int typer(int n)
{
    switch (n)
    {
        case (37):      //AMEX
        case (34):
            //printf("typer1");
            return(1);
            break;
        case (51):      //MASTERCARD
        case (52):
        case (53):
        case (54):
        case (55):
            //printf("typer2");
            return(2);
            break;
        case (4):       //VISA
            //printf("typer 3");
            return(3);
            break;
        default:
            //printf("Typer 4");
            return(0);  //INVALID
            break;
    }
}

// Validates card number
int calc(long long i)
{
    int s1total, endprod;
    long long digadd, digdoub, dubprod;

    for(digadd = i, s1total = 0; digadd > 0; digadd/=100)
    {
        s1total += digadd % 10;
        //printf("digadd %lld\ns1total %i\n",digadd,s1total);
    }

    for(digdoub = i/10, dubprod = 0; digdoub > 0; digdoub /= 100)
    {
        if (((digdoub % 10) * 2) > 9)
        {
            dubprod += ((digdoub / 10) * 2);
            dubprod += ((digdoub % 10) * 2);
        }
        else
        {
            dubprod += ((digdoub % 10) * 2);
        }

        // add the digits, not the pr0ducts
        printf("dub %lld\ndp %lld\n",digdoub,dubprod);
    }
        //printf("dubprod %i\\n", dubprod);

    endprod = (digadd + dubprod) % 10;

    printf("calc %i \n", endprod);
    return(endprod);
}

//Finds the first 2 digits, 1 digit for Visa
int fnum(long long n)
{
    int beginnum;
    long long i;

    for(i = n; i > 99; i /= 10)
    {
        //printf("%lld \n", i);
    }

    if ((i < 50) && (i > 39))
    {
        i /= 10;
        beginnum = i;
        //printf("visa %i", beginnum);
    }
    else
    {
        beginnum = i;
        //printf("%i ",beginnum);
    }

    //printf("%i \n", beginnum);
    return(beginnum);
}

// Counts the number of digits
int digver(long long n)
{
    int i = 0;

    while (n > 9)
    {
        i++;
        n /=10;
    }

    i++;
    //printf("\ndigver %i\n", i);
    return(i);


}