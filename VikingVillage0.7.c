//Note:The template file will be copied to a new file. When you change the code of the template file you can create new file with this base code. 
#include <iostream> 
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int version 1;		// Starting Version - 2 March 2020

enum e_item {
	e_food,
	e_wood,
	e_silver,
	e_population,
	e_cow,
	e_weapon,
	e_iron,
	e_silk,
	e_wool,
	e_gold,
	e_ivory,
	e_salt,
	e_wine,
	e_none,
	};

struct s_sack {
	enum e_item	loot;
	int	points;
};

struct trade {
	enum e_item	sell;
	enum e_item	buy;
	float	num;
	int	chance;
};

char smallA [][20] = { 
	"Food",
	"Wood",
	"Silver",
	"Population",
	"Cow",
	"Weapon Upgrade",
	"Iron" ,
	"Silk" ,
	"Wool" ,
	"Gold" ,
	"Ivory" ,
	"Salt" ,
	"Wine" ,
	"None" 
};

char *whatName (enum e_item what){
	return smallA [(int) what];
}//whatName

int prevSelected [20];

///////////////////////////////////////
void selectTrade (struct trade *it, float volitility){

	int num1, num2;

	int which = rand()%3;
	switch (which) {
		case 0: 
			it->num *= 1-volitility;
			break;
		case 1: 
			break;
		case 2: 
			it->num *= 1+volitility;
			break;

	}//

	num2 = 1;
	if (it->num < 1) {			// sell is worth more than buy
		num2 = 1;
		float hold;
		hold = 1.0 / it->num;
		num1 = (int) hold;
	}
	else {			// sell is worth less than buy
		num1 = 1;
		num2 = it->num;
	}

	printf ("%d %s => %d %s \n", num1, smallA [it->sell], num2, smallA [it->buy]);
    	//printf ("%d %s => %d %s \n", num1, "one", num2, "two");
	//printf ("%d %s => %d %s (%d)\n", num1, whatName (it->sell), num2, whatName (it->buy), it->chance);

}//

struct trade nearA [] = { 
{ e_silver, e_food,		5,	20}, 
{ e_silver, e_food,		5,	20}, 
{ e_silver, e_food,		5,	20}, 
{ e_silver, e_food,		5,	20}, 
{ e_food, e_silver,		0.2, 	10},
{ e_food, e_silver,		0.2, 	10},
{ e_silver, e_wood,		4,	20}, 
{ e_silver, e_wood,		4,	20}, 
{ e_wood, e_silver,		0.25, 	10},
{ e_wood, e_silver,		0.25, 	10},
{ e_wood, e_food,			1, 	10},
{ e_wood, e_food,			1, 	10},
{ e_silver, e_weapon,	0.333, 	5}, 
{ e_none, e_none,			0, 	1000} 
};

struct trade mediumA [] = { 
{ e_silver, e_food,		4,	20}, 
{ e_silver, e_food,		4,	20}, 
{ e_food, e_silver,		0.25, 	10},
{ e_food, e_silver,		0.25, 	10},
{ e_food, e_silver,		0.25, 	10},
{ e_silver, e_wood,		6,	20}, 
{ e_silver, e_wood,		6,	20}, 
{ e_silver, e_wood,		6,	20}, 
{ e_wood, e_silver,		0.16, 	10},
{ e_wood, e_food,			0.5, 	10},
{ e_silver, e_weapon,	0.5, 	5}, 
{ e_silver, e_cow,		0.5, 	5}, 
{ e_silver, e_iron,		3.0, 	5}, 
{ e_population, e_silver, 		12, 	5}, 
{ e_none, e_none,			0, 	1000} 
};

struct trade exoticA [] = { 
{ e_silk, e_silver,		3, 	10}, 
{ e_wool, e_silver,		2, 	10}, 
{ e_gold, e_silver,		8, 	10}, 
{ e_ivory, e_silver,		5, 	10}, 
{ e_salt, e_silver,		4, 	10}, 
{ e_wine, e_silver,		8, 	10}, 
{ e_none, e_none,		0, 	1000}, 
};

struct trade farA [] = { 
{ e_silver, e_food,		3,	20}, 
{ e_food, e_silver,		0.33, 	10},
{ e_silver, e_wood,		3,	20}, 
{ e_wood, e_silver,		0.33, 	10},
{ e_population, e_silver,		15, 	10},
{ e_silver, e_weapon,		0.5, 	10},
{ e_silver, e_iron,		0.5, 	10},
{ e_silver, e_silk, 		0.33, 	10}, 
{ e_silver, e_wool, 		0.5, 	10}, 
{ e_silver, e_gold, 		0.125, 	10}, 
{ e_silver, e_ivory, 	0.2, 	10}, 
{ e_silver, e_salt, 		0.25, 	10}, 
{ e_silver, e_wine, 		0.125, 	10}, 
{ e_none, e_none,		0, 	1000}, 
};

struct s_sack sackNear[] =  {
{ e_food, 1 },
{ e_food, 1 },
{ e_food, 1 },
{ e_food, 1 },
{ e_food, 1 },
{ e_food, 1 },
{ e_silver, 5 },
{ e_silver, 5 },
{ e_silver, 5 },
{ e_population, 10 },
{ e_none, 1000 }
};

struct s_sack sackMedium [] =  {
{ e_food, 1 },
{ e_food, 1 },
{ e_food, 1 },
{ e_food, 1 },
{ e_food, 1 },
{ e_iron, 2 },
{ e_ivory, 4 },
{ e_silver, 5 },
{ e_silver, 5 },
{ e_population, 10 },
{ e_none, 1000 }
};

struct s_sack sackFar[] =  {
{ e_food, 1 },
{ e_food, 1 },
{ e_food, 1 },
{ e_wool, 2 },
{ e_iron, 1 },
{ e_iron, 1 },
{ e_silver, 5 },
{ e_silver, 5 },
{ e_gold, 20 },
{ e_population, 7 },
{ e_none, 1000 }
};

int	sackItemsA [20];


///////////////////////////////////////
void displaySack () {
	int i;
	enum e_item item;

	for (i=0; i<10; i++) {
		if (sackItemsA [i])
			printf ("   %d %s \n", sackItemsA[i], smallA [i]);
	}//for


}//displaySack


///////////////////////////////////////
char *award (int age) {
	int var;

	var = rand ()%22;
	switch (var) {
		case 0: return "Get 3 silver";
		case 1: return "Gain 1 population";
		case 2: return "Get 2 weapon upgrade";
		case 3: return "Get 5 silver";
		case 4: return "Get 1 population and 5 food";
		case 5: return "Get 3 weapon upgrades";
		case 6: return "Get 15 food";
		case 7: return "Get 20 food";
		case 8: return "Get 15 wood";
		case 9: return "Get 30 wood";
            case 10: return "Skip one raid test";
            case 11: return "Reroll one die";
            case 12: return "Add one influence card after cards are revealed";
            case 13: return "Take control of the boat after the produce phase";
            case 14: return "Add an extra near trade card to any village";
            case 15: return "Add an extra exotic item to any village";
            case 16: return "Gain one extra die to any roll";
            case 17: return "Auto success for a sailing event (before roll)";
            case 18: return "Automatic success for raid activity (before roll)";
            case 19: return "During a raid, all weapon dice are increased by one";
            case 20: return "On lost raid, reduce loss by half";
            case 21: return "Sail activity requires no food";
	}//switch
	return "oops - no find";
	
}//award

///////////////////////////////////////
char *setGoal (int age) {
	int var;

	var = rand ()%9;
	if (age == 1)
		switch (var) {
			case 0: return "Trade food for 1 silver";
			case 1: return "Discover a new territory";
			case 2: return "Win a raid";
			case 3: return "Successful sack";
			case 4: return "Trade for 2 silver";
			case 5: return "Get 1 cow";
			case 6: return "Trade 8 food";
			case 7: return "Trade wood for 1 silver";
			case 8: return "Buy 6 food";
			case 9: return "Buy 12 food";
			default : return "oops 1";
		}//switch

	if (age == 2)
		switch (var) {
			case 0: return "Trade food for 2 silver";
			case 1: return "Discover a new medium territory";
			case 2: return "Win a raid";
			case 3: return "Successful sack";
			case 4: return "Trade for 4 silver";
			case 5: return "Get 1 population";
			case 6: return "Trade 20 food";
			case 7: return "Trade wood for 2 silver";
			case 8: return "Buy 12 food";
			case 9: return "Buy 12 food";
			default: return "oops 2";;
		}//switch

	if (age == 3)
		switch (var) {
			case 0: return "Trade food for 3 silver";
			case 1: return "Discover a new far territory";
			case 2: return "Win a raid";
			case 3: return "Successful sack medium territory";
			case 4: return "Trade for 6 silver";
			case 5: return "Get 2 population";
			case 6: return "Trade 30 food";
			case 7: return "Trade wood for 3 silver";
			case 8: return "Buy 25 food";
			case 9: return "Buy 12 food";
			default: return "oops 3";;
		}//switch

	return "oops - no find";
	
}//award

///////////////////////////////////////
void doSack (struct s_sack *list, int points) {
	int i;
	int var;
	int item;
	
    printf ("   ------- \n");        
	for (i=0; i<20; i++) 
		sackItemsA[i] = 0;
	
	for (i=0; i<50; i++) {
		var = rand()%10;

            if ((points - list[var].points) > -2) {
                points -= list[var].points;
            	    item = list[var].loot;
		    sackItemsA [(int) item]++;
            }//if points

		if (points < 0) {
			displaySack();
			return;
		}//if
	
	}//for
}//dosacknear


///////////////////////////////////////
void doTrade (int cnt, struct trade *list) {
	int i;
	int val;
      printf ("---------\n");
	for (i=0; i<20; i++) 
		prevSelected [i] = 0;

	for (i=0; i<cnt; i++) {
		val = rand ()%13 ;
		if (prevSelected [val]) {
			i--;		/// repeat this item if collision
			continue;
		}//if prevselected

		selectTrade (&list [val], .2);
		prevSelected [val] = 1;
		}//for 
}//dolarge


void beAttacked (int age){
    int num;
    printf ("------- Be Attacked by a neighboring clan -------\n");
    printf ("Defend with how many dice:  ");
    scanf ("%d\n", &num);
    
    int i;
    int score = 0;
    
    int youDice = num;
    int themDice;
    switch (age) {
        case 1: themDice = 4; 
            break;
        case 2: themDice = 6;
             break;
         case 3: themDice = 8;
             break;
    }//switch
    
    themDice += rand()%3-1;        // vary dice by one randomly

    printf ("Your dice: ");
    for (i=0; i<youDice; i++)
        printf ("%d    ", rand()%6+1);
        
    
    printf ("\nTheir dice: ");
    for (i=0; i<themDice; i++)
        printf ("%d    ", rand()%6+1);
    printf ("\n");
    
    
    printf ("-- Lose the following --\n");
    doSack (sackNear, 10);
}//beattacked

void runRaid (int age){
    int num;
    printf ("------- Raid a neighboring clan -------\n");
    printf ("Number of dice:  ");
    scanf ("%d\n", &num);
    
    int i;
    int score = 0;
    
    int youDice = num;
    int themDice;
    switch (age) {
        case 1: themDice = 4; 
            break;
        case 2: themDice = 6;
             break;
         case 3: themDice = 8;
             break;
    }//switch

    printf ("Your dice: ");
    for (i=0; i<youDice; i++)
        printf ("%d    ", rand()%6+1);
        
    
    printf ("\nTheir dice: ");
    for (i=0; i<themDice; i++)
        printf ("%d    ", rand()%6+1);
    printf ("\n");
    
    printf ("-- Leader --\n");
    doSack (sackNear, 10);
    printf ("-- Crew --\n");            
    doSack (sackNear, 5);
}//runraid
        
        

void runSack (int location, int age){
    int num;
    printf ("------- Sack a village -------\n");
    printf ("Number of dice:  ");
    scanf ("%d\n", &num);
    
    int i;
    int score = 0;
    
    int youDice = num;
    int themDice;
    switch (age) {
        case 1: themDice = 4; 
            break;
        case 2: themDice = 6;
             break;
         case 3: themDice = 8;
             break;
    }//switch

    printf ("Your dice: ");
    for (i=0; i<youDice; i++)
        printf ("%d    ", rand()%6+1);
        
    
    printf ("\nTheir dice: ");
    for (i=0; i<themDice; i++)
        printf ("%d    ", rand()%6+1);
    printf ("\n");
        

        switch (location){
            case 1: 
                    printf ("-- Leader --\n");
                    doSack (sackNear, 20);
                    printf ("-- Crew --\n");            
                    doSack (sackNear, 10);
                    break;
            case 2: 
                    printf ("-- Leader --\n");
                    doSack (sackMedium, 25);
                    printf ("-- Crew --\n");            
                    doSack (sackMedium, 12);
                    break;     
                    
             case 3: 
                    printf ("-- Leader --\n");
                    doSack (sackFar, 30);
                    printf ("-- Crew --\n");            
                    doSack (sackFar, 15);
                    break;                  
        }//switch
}//runattack

void newTerritory (int location) {
    int num;
    printf ("------- New Territory -------\n");
    printf ("Number of dice:  ");
    scanf ("%d\n", &num);
    
    int i, max;
    
    for (i=0; i<num; i++) {
        int val = rand ()%6+1;
        printf ("%d ", val);
        if (val > max) max = val;
    }//fori
    
    printf ("\nMax: %d\n", max);
    
    switch (location) {
        case 1: 
                if (max <= 2) {
                    printf ("Fail\n");
                    return;
                    }//if
                else
                    doTrade (2, nearA);
            break;
        case 2: 
                if (max <= 3) {
                    printf ("Fail\n");
                    return;
                    }//if
                else
                    doTrade (3, mediumA);
            break;
        case 3: 
                if (max <= 4) {
                    printf ("Fail\n");
                    return;
                    }//if
                else
                    doTrade (5, farA);
            break;
    }//switch
    
    
}//newterritory

///////////////////////////////////////
void doMedium (int cnt) {
	int i;
	int val;
	for (i=0; i<20; i++) 
		prevSelected [i] = 0;

	printf ("      --- Medium ---\n");
	for (i=0; i<cnt; i++) {
		val = rand ()%9 ;
		selectTrade (&mediumA [val], .2);
			i--;		/// repeat this item if collision
		prevSelected [val] = 1;
		}//for 
}//domedium

///////////////////////////////////////
void doCards () {
    int i;
    
    printf ("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf ("-- Near --\n");
    for (i=0; i<4; i++) doTrade (2, nearA);
    printf ("   ---- Sack ----\n");
    for (i=0; i<4; i++) doSack (sackNear, 20);

    printf ("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf ("-- Medium --\n");
    for (i=0; i<4; i++) doTrade (3, mediumA);
    printf ("   ---- Sack ----\n");
    for (i=0; i<4; i++) doSack (sackMedium, 30);

    printf ("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf ("-- Far --\n");
    for (i=0; i<4; i++) doTrade (5, farA);
    printf ("   ---- Sack ----\n");
    for (i=0; i<4; i++) doSack (sackFar, 40);
    
    printf ("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf ("-- Age 1 Goals --\n");
    for (i=0; i<10; i++) 			printf ("Goal: %s\n", setGoal (1) );

    printf ("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf ("-- Age 1 Rewards --\n");

    for (i=0; i<10; i++) 			printf ("Goal: %s\n", award (1) );
    
}//cards
    
    
///////////////////////////////////////
void doNear (int cnt) {
	int i;
	int val;

	for (i=0; i<20; i++) 
		prevSelected [i] = 0;

	printf ("      --- Near ---\n");
	for (i=0; i<cnt; i++) {
		val = rand ()%6 ;
		selectTrade (&nearA [val], .2);
			i--;		/// repeat this item if collision
		}//for 
	
	val = rand ()%2;
	if (val == 1) {
		val = rand ()%6 ;
		selectTrade (&exoticA [val], .5);
	}//if val
}//doNear


///////////////////////////////////////
int main (int argc, char *argv[]){

	int i;
	int val;
	time_t t;

	srand ((unsigned) time (&t));
	char ans;
	char ch;

	int age = 1;
	int location = 1;

	char *locStrA []= { "no", "Near", "Medium", "Far" };
	char *ageStrA []= { "Never", "Early", "Mid", "Old" };

	while (1) {

		printf ("##### Age      %s #####\n", ageStrA [age]);
		printf ("##### Location %s #####\n", locStrA [location] );
		printf ("	e - Explore a %s Territory \n", locStrA [location] );
		printf ("	s - Sack a %s Territory\n", locStrA [ location] );
		printf ("	r - Raid a neighboring clan\n");		printf ("	b - Be attacked by a neighboring clan\n");
		printf ("	g - Goal (%s)\n", ageStrA [age] );
		printf ("	a - Award  (%s)\n", ageStrA [age] );
		printf ("	c - Change Age from %s\n", ageStrA [age] );
		printf ("	n - Set location 'near' \n");
		printf ("	m - Set location 'medium' \n");
		printf ("	f - Set location 'far' \n");
             printf ("    1 - Print Cards\n");
		printf ("	q - Quit\n");
		scanf ("%c%c", &ans, &ch) ;

		printf ("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        
		switch (ans) {
		case 'E':
		case 'e':
                    newTerritory (location);
                    break;
		case 't':
		case 'T':
			if (location == 1) doTrade (2, nearA);
			if (location == 2) doTrade (3, mediumA);
			if (location == 3) doTrade (5, farA);
			break;

		case 'S':
		case 's':
                    runSack (location, age);

			break;

		case 'N':		
		case 'n':		
			location = 1;
			break;
		case 'M':		
		case 'm':		
			location = 2;
			break;
		case 'F':		
		case 'f':		
			location = 3;
			break;
            case 'r':
            case 'R':
                    runRaid(age);
                    break;
            case 'b':
            case 'B':
                    beAttacked(age);
                    break;
		case 'c':					// Increase the current age
		case 'C':
			age++;
			if (age > 3)
				age = 1;
                printf ("age: %d\n", age);
			break;
		case 'g':
		case 'G':
			printf ("Goal: %s\n", setGoal (age) );
			break;
		case 'a':
		case 'A':
			printf ("Award: %s\n", award (age) );
			break;
		case 'q':
		case 'Q':
			return 0;
            case '1':
                    doCards ();
                    break;
		default:
			continue;
		}//switch

		printf ("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf ("\n\n");
	
	}//while


}//main


 *My favorite app::C++ For iOS - Free  https://itunes.apple.com/app/id1016322367?mt=8
Other's Tutorals:http://iii9i.com