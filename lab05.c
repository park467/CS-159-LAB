
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. park1064purdue.edu
*  2. lchittin@purdue.edu
*  3. lrisany@purdue.edu (delete line if no third partner)
*
*  
*  Lab #:05
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The project we are submitting is our own original work.
*
*  Day, Time, Location of Lab:
*
*  Program Description:
*
***************************************************************************/
# include <stdio.h>
# include <math.h>
#include <stdlib.h>

int main()
{
  int myDistStartToHole;
  int myDistFromHole;
  int myClub;
  int myLoftAngle;
  int myInitialV;
  int golfer;
  int mySeed; 
  
  mySeed = enterSeed();
  myDistStartToHole = calcDistToHole(mySeed);
  myClub = calcClub(mySeed);
  myLoftAngle = calcLoftAngle(mySeed, myClub);
  myInitialV = calcInitialV(mySeed);

  return(0);
}

int enterSeed()
{
  int seed;
  printf("Enter a seed -> ");
  scanf("%d", &seed); 
  return(seed);
}

int calcDistToHole(int seed)
{
 int range;
 int distStartToHole;

 srand(seed);
 range = (500 - 300) + 1;
 distStartToHole = (int) rand() % range + 300;
  
 return(distStartToHole);
}

int calcClub(int seed)
{
  int range;
  int club;

  srand(seed);
  range = (3 - 1) + 1;
  club = (int) rand() % range + 1;
  return(club);
}

int calcLoftAngle(int seed, int club)
{
  int range;
  int loftAngle;
  int maximum;
  srand(seed);

  maximum = 5 * (club + 2) + 3;
  range = (maximum - (maximum - 5)) + 1;

  loftAngle = (int) rand() % range + 1;

  return(loftAngle);
}

int calcInitialV (int seed)
{
  int range;
  int initialV;

  srand(seed);
  range = (60 - 40) + 1;
  initialV = (int) rand() % range + 1;

  return(initialV);
}

double calcTime(int initialV, int loftAngle)
{
  double time;
  
  time = (double)(initialV * sin(loftAngle) / 4.9);
  return(time);
}

double calcTravelDist(int initialV, int loftAngle, double time)
{
  double travelDist;
  travelDist = (double)(initialV * cos(loftAngle) * time);
  return(travelDist);
}

double calcDistFromHole(int distStartToHole, double travelDist)
{
  double distFromHole;
  distFromHole = (double) abs(distStartToHole - travelDist);
  return(distFromHole);
}

void rank(double distF1, distF2, distF3)
{
  int maximum;
  int *rank1;
  int *rank2;
  int *rank3;
  *rank1 = 1 + (distF1 % distF2) + (distF1 % distF3);
  *rank2 = 1 + (distF2 % distF1) + (distF2 % distF3);
  *rank3 = 1 + (distF3 & distF1) + (distF3 % distF2);

return();
}
