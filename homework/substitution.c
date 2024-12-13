#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check key
    if (argc != 2)
    {
        printf("Usage: ./subsitution key\n");
        return 1;
    }

    string k = argv[1];

    if (strlen(k) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Usage: ./subsitution key\n");
            return 1;
        }
    }

    for (int i = 0; i < strlen(k); i++)
    {
        for (int j = (i + 1); j < strlen(k); j++)
        {
            if (toupper(k[i]) == toupper(k[j]))
            {
                printf("Usage: ./subsitution key\n");
                return 1;
            }
        }
    }

    // plaintext
    string text = get_string("plaintext: ");

    // upper
    for (int i = 0; i < strlen(k); i++)
    {
        if (islower(k[i]))
        {
            k[i] = toupper(k[i]);
        }
    }

    // convert
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            int index = text[i] - 65;
            text[i] = k[index];
        }
        if (islower(text[i]))
        {
            int m = text[i] - 97;
            text[i] = tolower(k[m]);
        }
    }

    // ciphertext
    printf("ciphertext: %s\n", text);
    return 0;
}
