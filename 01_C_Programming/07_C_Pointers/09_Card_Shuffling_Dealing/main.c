/*
 *           File: main.c
 *     Created on: Thursday 17/03/2022 18:19
 *         Author: Makram Maher Makram
 *        Subject:
 *
 *
 */

/* Includes files */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int * const deck, const unsigned int suits, const unsigned int faces);
void deal_Four_Players(unsigned int deck[][FACES], const char * suit[], const char * face[], const unsigned int suits, const unsigned int faces);


/* main function */
int main(void)
{
   const char * suit[SUITS] = {"Spades", "Hearts", "Diamonds", "Clubs"};
   const char * face[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

   unsigned int deck[SUITS][FACES] = {0};

   srand(time(NULL));

   shuffle((unsigned int * const)deck, SUITS, FACES);
   puts("");
   deal_Four_Players(deck,suit,face,SUITS,FACES);

   return 0;
}/* end main */


void shuffle(unsigned int * const deck, const unsigned int suits, const unsigned int faces)
{
   unsigned int i;
   for (i = 0; i < suits * faces; i++)
   {
      unsigned int row;
      unsigned int column;

      do
      {
         row = rand() % suits;
         column = rand() % faces;
      } while (*(deck + (faces * row) + column) != 0);

      *(deck + (faces * row) + column) = i;
   }
}

void deal_Four_Players(unsigned int deck[][FACES], const char * suit[], const char * face[], const unsigned int suits, const unsigned int faces)
{
   unsigned int card, i , j;

   printf("%12s%24s\t%20s\t%20s\n","Player 1","Player 2","Player 3","Player 4");
   
   for (card = 0; card < suits * faces; card++)
   {
      for (i = 0; i < suits; i++)
      {
         for (j = 0; j < faces; j++)
         {
            if (deck[i][j] == card)
            {
               printf("%5s of %-8s%c", face[j], suit[i], (card+1) % 4 == 0 ? '\n' : '\t');
            }
         }
      }
   }
}