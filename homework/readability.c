#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int check_letter(string text);
int check_words(string text);
string upper(string text);
int check_sentence(string text);

int main(void)
{
    //user input
    string text = get_string("Text:\n");
    text = upper(text);

    //check
    int letter = check_letter(text);
    int words = check_words(text);
    int sentences = check_sentence(text);

    //formula
    float l = ((float) letter / (float) words * 100.0);
    float s = ((float) sentences / (float) words * 100.0);
    float index = round(0.0588 * l - 0.296 * s - 15.8);
    if (index >= 16.0)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        index = round(index);
        printf("Grade %i\n", (int) index);
    }
}













int check_letter(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i<n; i++)
    {
        //if (text[i] >= 65 && text[i]<= 90)
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int check_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i<n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    count += 1;
    return count;
}

int check_sentence(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i<n; i++)
    {
        if ((text[i] == 46) || (text[i] == 33) || (text[i] == 63))
            count++;
    }
    return count;
}

string upper(string text){
    for (int i = 0, n = strlen(text); i<n; i++)
    {
        text[i] = toupper(text[i]);
    }
    return text;
}
