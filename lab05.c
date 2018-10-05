
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. park1064@purdue.edu
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
*  Day, Time, Location of Lab: 28 September 2018
*
*  Program Description: This program randomly generates the distance from
*  start to hole, club, loft angle, and initial velocity and calculates time,
*  travel ditance, distance from hole, and rank of each golfer.
*
***************************************************************************/
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
  
int enterSeed();
int calcDistToHole(int);
int calcClub(int);
int calcLoftAngle(int, int);
int calcInitialV (int);
double calcTime(int, int);
double calcTravelDist(int, int, double);
double calcDistFromHole(int, double);
void output1(int, int, int, int);
void output2(int,double, double, double, int);
void text1Output(int);
void text2Output();
int rank1(double distF1, double distF2, double distF3);
int rank2(double distF1, double distF2, double distF3);
int rank3(double distF1, double distF2, double distF3);

int main()
{
  int myDistStartToHole; //distance from start to hole
  double myDistFromHole1; //distance from start to hole of golfer 1
  double myDistFromHole2; //distance from start to hole of golfer 2
  double myDistFromHole3; //distance from start to hole of golfer 3

  int myClub1; //club of golfer 1
  int myClub2; //club of golfer 2
  int myClub3; //club of golfer 3

  int myLoftAngle1; //loft angle of golfer 1
  int myLoftAngle2; //loft angle of golfer 2
  int myLoftAngle3; //loft angle of golfer 3

  int myInitialV1; //initial velocity of golfer 1
  int myInitialV2; //initial velocity of golfer 2
  int myInitialV3; //initial velocity of golfer 3

  int myRank1; //rank of golfer 1
  int myRank2; //rank of golfer 2
  int myRank3; //rank of golfer 3

  int mySeed; //seed number
  
  double myTime1; //time of golfer 1
  double myTime2; //time of golfer 2
  double myTime3; //time of golfer 3

  double travelDist1; //travel distance of golfer 1
  double travelDist2; //travel distance of golfer 2
  double travelDist3; //travel distance of golfer 3
  
  mySeed = enterSeed();
  srand(mySeed);
  myDistStartToHole = calcDistToHole(mySeed);

  myClub1 = calcClub(mySeed);
  myLoftAngle1 = calcLoftAngle(mySeed, myClub1);
  myInitialV1 = calcInitialV(mySeed);

  myClub2 = calcClub(mySeed);
  myLoftAngle2 = calcLoftAngle(mySeed, myClub2);
  myInitialV2 = calcInitialV(mySeed);

  myClub3 = calcClub(mySeed);
  myLoftAngle3 = calcLoftAngle(mySeed, myClub3);
  myInitialV3 = calcInitialV(mySeed);
  
  myTime1 = calcTime(myInitialV1, myLoftAngle1);
  myTime2 = calcTime(myInitialV2, myLoftAngle2);
  myTime3 = calcTime(myInitialV3, myLoftAngle3);

  travelDist1 = calcTravelDist(myInitialV1, myLoftAngle1, myTime1);
  travelDist2 = calcTravelDist(myInitialV2, myLoftAngle2, myTime2);
  travelDist3 = calcTravelDist(myInitialV3, myLoftAngle3, myTime3);

  myDistFromHole1 = calcDistFromHole(myDistStartToHole, travelDist1);
  myDistFromHole2 = calcDistFromHole(myDistStartToHole, travelDist2);
  myDistFromHole3 = calcDistFromHole(myDistStartToHole, travelDist3);
  
  myRank1 = rank1(myDistFromHole1, myDistFromHole2, myDistFromHole3);
  myRank2 = rank2(myDistFromHole1, myDistFromHole2, myDistFromHole3);
  myRank3 = rank3(myDistFromHole1, myDistFromHole2, myDistFromHole3);

  text1Output(myDistStartToHole);

  output1(1, myClub1, myLoftAngle1, myInitialV1);
  output1(2, myClub2, myLoftAngle2, myInitialV2);
  output1(3, myClub3, myLoftAngle3, myInitialV3);
 
  text2Output();
 
  output2(1, myTime1, travelDist1, myDistFromHole1, myRank1);
  output2(2, myTime2, travelDist2, myDistFromHole2, myRank2);
  output2(3, myTime3, travelDist3, myDistFromHole3, myRank3);
  
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: enterSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line
*
*  Function Description: This function scans the seed number for random
*  number generation.
*
***************************************************************************/

int enterSeed()
{
  int seed; //seed number
  
  printf("Enter a seed -> ");
  scanf("%d", &seed); 
  return(seed);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcDistToHole
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, seed, seed number
*
*  Function Description: This function generates the distance to hole.
*
***************************************************************************/

int calcDistToHole (int seed)
{
  int range; //range of srand function
  int distStartToHole; //distance from start to hole
 
  range = (500 - 300) + 1;
  distStartToHole = (int) rand() % range + 300;
  
  return(distStartToHole);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcClub
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, seed, seed number
*
*  Function Description: This function generates the club number.
*
***************************************************************************/

int calcClub(int seed)
{
  int range; //range of srand function
  int club; //club number

  range = (3 - 1) + 1;
  club = rand() % range + 1;
  return(club);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcLoftAngle
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, seed, seed number
*    2. int, club, club number
*
*  Function Description: This function generates the loft angle.
*
***************************************************************************/

int calcLoftAngle(int seed, int club)
{
  int range; //range of srand function
  int loftAngle; //loft angle
  int minimum; //minimum loft angle
 
  minimum = 3 + club * 5;
    
  loftAngle = (int) rand() % 6 + minimum;

  return(loftAngle);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcInitialV
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, seed, seed number
*
*  Function Description: This function generates the initial velocity.
*
***************************************************************************/


int calcInitialV (int seed)
{
  int range; //range of srand function
  int initialV; //initial velocity

  range = (60 - 40) + 1;
  initialV = (int) rand() % 21 + 40;
 
  return(initialV);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcTime
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, initialV, initial velocity
*    2. int, loftAngle, loft angle
*
*  Function Description: This function calculates the time.
*
***************************************************************************/


double calcTime(int initialV, int loftAngle)
{
  double time; //time record of golfers
  time = (double)(2 * initialV * sin(loftAngle * M_PI / 180) /( 9.8 ));
  return(time);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcTravelDist
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, initialV, initial velocity
*    2. int, loftAngle, loft angle
*    3. double, time, time
*
*  Function Description: This function calculates the travel distance.
*
***************************************************************************/

double calcTravelDist(int initialV, int loftAngle, double time)
{
  double travelDist; //travel distance
 
  travelDist = (double)(initialV * cos(loftAngle * M_PI  / 180) * time);
  travelDist = ((int)(travelDist * 10 )) / 10.0;
  return(travelDist);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcDistFromHole
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, distStartToHole, distance from start to hole
*    2. double, travelDist, travel distance
*
*  Function Description: This function calculate the distance from hole.
*
***************************************************************************/

double calcDistFromHole(int distStartToHole, double travelDist)
{
  double distFromHole; //distance from hole

  distFromHole = fabs((double) distStartToHole - travelDist);
  distFromHole = ((int)(distFromHole * 10)) / 10.0;

return(distFromHole);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: rank1
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, distF1, distance from hole of golfer 1
*    2. double, distF2, distance from hole of golfer 2
*    3. double, distF3, distance from hole of golfer 3
*
*  Function Description: This function calculates the rank of golfer 1.
*
***************************************************************************/

int rank1(double distF1, double distF2, double distF3)
{
  int factor1; //factor needed to determine the rank of golfer 1
  int factor2; //another factor needed to determine the rank of golfer 1
  int theRank1; //rank of golfer 1
 
  factor1 = distF2 / distF1;
  factor2 = distF3 / distF1;  
  theRank1 = 3 - (factor1 + factor2);

  return (theRank1);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: rank2
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, distF1, distance from hole of golfer 1
*    2. double, distF2, distance from hole of golfer 2
*    3. double, distF3, distance from hole of golfer 3
*
*  Function Description: This function calculates the rank of golfer 2.
*
***************************************************************************/

int rank2(double distF1, double distF2, double distF3)
{
  int factor1; //factor needed to determine the rank of golfer 2
  int factor2;//another factor needed to determine the rank of golfer 2
  int theRank2; //rank of golfer 2

  factor1 = distF3 / distF2;
  factor2 = distF1 / distF2;
  theRank2 = 3 - (factor1 + factor2);

  return (theRank2);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: rank3
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, distF1, distance from hole of golfer 1
*    2. double, distF2, distance from hole of golfer 2
*    3. double, distF3, distance from hole of golfer 3
*
*  Function Description: This function calculates the rank of golfer 3.
*
***************************************************************************/

int rank3(double distF1, double distF2, double distF3)
{
  int factor1; //factor needed to determine the rank of golfer 3
  int factor2;//another factor needed to determine the rank of golfer 3
  int theRank3; //rank of golfer 3

  factor1 = distF1 / distF3;
  factor2 = distF2 / distF3;
  theRank3 = 3 - (factor1 + factor2);

  return(theRank3);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output1
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, golfer, golfer number
*    2. int, club, club number
*    3. int, loftAngle, loft angle
*    4. int, velocity, initial velocity
*
*  Function Description: This function prints out the randomly generated
*  variables.
*
***************************************************************************/


void output1(int golfer, int club, int loftAngle, int velocity)
{
  printf("  %d:%7d%9d%10d m/s\n", golfer, club, loftAngle, velocity);

  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output2
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, golfer, golfer number
*    2. double, time, time
*    3. double, travelDist, travel distance
*    4. double, distFromHole, distanace from hole
*    5. int, rank, rank
*
*  Function Description: This function prints out the calculated variables.
*
***************************************************************************/

void output2(int golfer, double time, double travelDist, double distFromHole, int rank)
{
  printf("  %d:%8.2lf s%13.1lf m%18.1lf m%10d\n", golfer, time, travelDist, distFromHole, rank);

  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: text1Output
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, myDistStartFromHole, distance from start to hole
*
*  Function Description: This function prints out the header of randomly
*  generated variables.
*
***************************************************************************/


void text1Output(int myDistStartToHole)
{
  printf("\nDistance to the hole: %d m\n", myDistStartToHole);
  printf("\nGolfer  Club  Loft Angle  Velocity\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: text2Output
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, myDistStartFromHole, distance from start to hole
*
*  Function Description: This function prints out the header of calculated
*  variables.
*
***************************************************************************/

void text2Output()
{
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nGolfer   Time     Travel Distance   Distance From Hole  Rank\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

  return;
}
