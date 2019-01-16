#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define KEY "ALABALAPORTOCALA"

void Cripteaza(char * text, const char * cheie)
{
  const char * keyChar = cheie;

  for (; *text != '\0'; text++)
  {
    if (*text == '\n' || *text == ' ')
      continue;

    unsigned char isLowerCase = islower(*text);

    char toEncode = toupper(*text);

    char copyText = toEncode;


    *text = 'A' + (26  + *keyChar - toEncode)%26;



    if (isLowerCase)
      *text = tolower(*text);

    keyChar++;
    if (*keyChar == '\0')
      keyChar = cheie;


  }
}

void Decripteaza(char * text, const char * cheie)
{
  const char * keyChar = cheie;

  for (; *text != '\0'; text++)
  {
    if (*text == '\n' || *text == ' ')
      continue;

    unsigned char isLowerCase = islower(*text);

    char toDecode = toupper(*text);
    if (toDecode < *keyChar)
      toDecode += 26;




    *text = 'A' + ((*keyChar - toDecode) + 26) % 26;

    if (isLowerCase)
      *text = tolower(*text);

    keyChar++;
    if (*keyChar == '\0')
      keyChar = cheie;
  }
}

int main()
{
  char text[1000];

  printf("message=");
  fgets(text, sizeof(text), stdin);

  Cripteaza(text, KEY);
  printf("Cyphered text: %s\n", text);

  Decripteaza(text, KEY);
  printf("Decyphered text: %s", text);

  return 0;
}