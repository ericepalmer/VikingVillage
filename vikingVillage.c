//Note:The template file will be copied to a new file. When you change the code of the template file you can create new file with this base code. 
//#include <iostream> 
//using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int version = 2;		// Starting Version - 2 March 2020, 20 Apr 2023

///////////////////////////////////////
enum e_item {
	e_food,
	e_wood,
	e_wool,
	e_honey,
	e_fur,
	e_antlers,
	e_millStones,
	// not used
		e_leather,
		e_clothes,

	e_silver,
	e_cow,
	e_sheep,
	e_weapon,
	e_iron,
	e_s_jewelry,
	// not used
		e_l_armor,
		e_shield,
		e_gem,
		e_copper,
		e_tin,
		e_plough,
		e_wine,

	e_silk,
	e_gold,
	e_ivory,
	e_salt,
	// not used
		e_g_jewelry,
		e_compass,
		e_map
	};

///////////////////////////////////////
struct s_sack {
	enum e_item	loot;
	int	points;
};

///////////////////////////////////////
struct t_item {
	enum e_item item;			// index to "name" for lookup
	float	value;				// is silver
	int	can_make;			// Can this item be used to make something
	int 	consumed;			// Will this item be consumed
};

///////////////////////////////////////
// This holds a single trade option
struct t_trade {
	enum e_item sell;
	int nSell;
	enum e_item buy;
	int nBuy;
};
///////////////////////////////////////
struct trade {
	enum e_item	sell;
	enum e_item	buy;
	float	num;
	int	chance;
};

char *getName (enum e_item item){
	switch (item) {
		case e_food: return "Food";
		case e_wood: return "Lumber";
		case e_wool: return "Wool";
		case e_honey: return "Honey";
		case e_fur: return "Fur";
		case e_antlers: return "Antlers";
		case e_millStones: return "Mill Stones";
		case e_leather: return "Leather";
		case e_clothes: return "Clothes";
		case e_silver: return "Silver";
		case e_cow: return "Cow";
		case e_sheep: return "Sheep";
		case e_weapon: return "Weapon Upgrade";
		case e_iron: return "Iron ore";
		case e_s_jewelry: return "Silver Jewelry";
		case e_l_armor: return "Leather Armor";
		case e_shield: return "Shield";
		case e_gem: return "Gem Stone";
		case e_copper: return "Copper ore";
		case e_tin: return "Tin ore";
		case e_plough: return "Plough";
		case e_wine: return "Wine";
		case e_silk: return "Silk";
		case e_gold: return "Gold";
		case e_ivory: return "Ivory";
		case e_salt: return "Salt";
		case e_g_jewelry: return "Gold Jewelry";
		case e_compass: return "Compass";
		case e_map: return "Map";
		default: return "Unknown";
	}//switch

}

///////////////////////////////////////
// t_item item, value, can_make, consumed
struct t_item itemA [] = {
	// Basic
	{e_food, 		 .125, 0, 1},
	{e_wood, 		.100, 1, 1},
	{e_wool, 		.071, 0, 0},
	{e_honey, 		 .25, 0, 0},
	{e_fur, 			 .20, 0, 0},
	{e_antlers, 	.05, 0, 0},
	{e_millStones, .0333, 0, 0},
	// not used
		{e_leather, .02, 0, 0},
		{e_clothes, .02, 0, 0},

	// Special
	{e_silver, 	1.00, 1, 1},
	{e_cow, 		4.00, 1, 0},
	{e_sheep, 	2.00, 1, 0},
	{e_weapon, 	1.00, 0, 0},
	{e_iron, 	0.50, 0, 0},
	{e_s_jewelry, 3.00, 0, 0},
	// not used
		{e_l_armor, 1, 1, 1},
		{e_shield, 1, 1, 1},
		{e_gem, 1, 1, 1},
		{e_copper, 1, 1, 1},
		{e_tin, 1, 1, 1},
		{e_plough, 1, 1, 1},

	// Exotic
	{e_silk, 		4, 0, 0},
	{e_gold, 		10, 0, 0},
	{e_ivory, 		6, 0, 0},
	{e_g_jewelry, 	20, 0, 0},
	{e_salt, 		2, 0, 0},
	// not used
		{e_compass, 	4, 0, 0},
		{e_map, 		4, 0, 0}
};

///////////////////////////////////////

int prevSelected [20];


///////////////////////////////////////
void sort (int array [], int max) {
	int i, j;
	int hold;
	for (i=0; i<max; i++)
		for (j=0; j<max; j++) {
			if (array [i] > array [j]) {
				hold = array [i];
				array [i] = array [j];
				array [j] = hold;
			}//if 
		}//forj

}//sort

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

	printf ("%d %s => %d %s \n", num1, getName (it->sell), num2, getName (it->buy));
    	//printf ("%d %s => %d %s \n", num1, "one", num2, "two");

}//

///////////////////////////////////////
///////////////////////////////////////
struct trade nearA [] = { 
};

struct trade mediumA [] = { 
};


struct trade farA [] = { 
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
{ e_ivory, 10 },
{ e_food, 1000 }
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
{ e_ivory, 10 },
{ e_food, 1000 }
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
{ e_ivory, 7 },
{ e_food, 1000 }
};

int	sackItemsA [20];


///////////////////////////////////////
void displaySack () {
	int i;
	enum e_item item;

	for (i=0; i<10; i++) {
		if (sackItemsA [i])
			printf ("   %d %s \n", sackItemsA[i], getName(i));
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
		case 4: return "Get 1 population and 5 wheat";
		case 5: return "Get 3 weapon upgrades";
		case 6: return "Get 15 wheat";
		case 7: return "Get 20 wheat";
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
            case 21: return "Sail activity requires no wheat";
	}//switch
	return "oops - no find";
	
}//award

///////////////////////////////////////
char *setGoal (int age) {
	int var;

	var = rand ()%9;
	if (age == 1)
		switch (var) {
			case 0: return "Trade wheat for 1 silver";
			case 1: return "Discover a new territory";
			case 2: return "Win a raid";
			case 3: return "Successful sack";
			case 4: return "Trade for 2 silver";
			case 5: return "Get 1 cow";
			case 6: return "Trade 8 wheat";
			case 7: return "Trade wood for 1 silver";
			case 8: return "Buy 6 wheat";
			case 9: return "Buy 12 wheat";
			default : return "oops 1";
		}//switch

	if (age == 2)
		switch (var) {
			case 0: return "Trade wheat for 2 silver";
			case 1: return "Discover a new medium territory";
			case 2: return "Win a raid";
			case 3: return "Successful sack";
			case 4: return "Trade for 4 silver";
			case 5: return "Get 1 population";
			case 6: return "Trade 20 wheat";
			case 7: return "Trade wood for 2 silver";
			case 8: return "Buy 12 wheat";
			case 9: return "Buy 12 wheat";
			default: return "oops 2";;
		}//switch

	if (age == 3)
		switch (var) {
			case 0: return "Trade wheat for 3 silver";
			case 1: return "Discover a new far territory";
			case 2: return "Win a raid";
			case 3: return "Successful sack medium territory";
			case 4: return "Trade for 6 silver";
			case 5: return "Get 2 population";
			case 6: return "Trade 30 wheat";
			case 7: return "Trade wood for 3 silver";
			case 8: return "Buy 25 wheat";
			case 9: return "Buy 12 wheat";
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



int attack (int youDice, int themDice)
{
	int	themA [50];
	int	youA [50];
	int	i;
	int	score = 0;

	// reset arrays to 0
   for (i=0; i<youDice; i++) {
		youA [i] = 0;
		themA [i] = 0;
	}//for

	// Figure out dice
	printf ("Your dice : ");
   for (i=0; i<youDice; i++)
		youA [i] = rand()%6+1;
	sort (youA, youDice);
   for (i=0; i<youDice; i++)
        printf ("%d    ", youA [i]);
        
   printf ("\nTheir dice: ");
   for (i=0; i<themDice; i++)
		themA [i] = rand()%6+1;
	sort (themA, themDice);
   for (i=0; i<themDice; i++)
       printf ("%d    ", themA[i]);
	printf ("\n");
	
	// Evaluate
	int min;
	printf ("            ");
	if (youDice > themDice)
		min = themDice;
	else
		min = youDice;
   for (i=0; i<min; i++) {
		char ch;
		ch = ' ';
		if (youA [i] > themA[i]) {
			ch = '+';
			score ++;
		}//if
		if (youA [i] < themA[i]) {
			ch = '-';
			score --;
		}//if
      printf ("%c    ", ch);
	}//for
	printf ("\n");
	return score;
}//attack

///////////////////////////////////////
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

	score = attack (youDice, themDice);;
	printf ("Score:  %d\n", score);
	if (score > 0) {
		printf ("You win\n");
		return;
	}//if

	printf ("-- Lose the following --\n");
	doSack (sackNear, 10);
}//beattacked

///////////////////////////////////////
void runRaid (int age){
   int num;
   int i;
   int score = 0;
   int youDice;
   int themDice;

   printf ("------- Raid a neighboring clan -------\n");
   printf ("Number of dice:  ");
   scanf ("%d", &num);
   //scanf ("%d\n", &num);

	youDice = num;
   switch (age) {
        case 1: themDice = 4; 
            break;
        case 2: themDice = 6;
             break;
         case 3: themDice = 8;
             break;
   }//switch

	score = attack (youDice, themDice);;

	printf ("Score: %d\n", score);
	if (score <= 0) {
		printf ("Fail\n");
		return;
	}//ifscore
   
   printf ("-- Leader --\n");
   doSack (sackNear, 10);
   printf ("-- Crew --\n");            
   doSack (sackNear, 5);
}//runraid
        
        

///////////////////////////////////////
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

/*
    printf ("Your dice: ");
    for (i=0; i<youDice; i++)
        printf ("%d    ", rand()%6+1);
        
    
    printf ("\nTheir dice: ");
    for (i=0; i<themDice; i++)
        printf ("%d    ", rand()%6+1);
    printf ("\n");
*/
        
	score = attack (youDice, themDice);;
	printf ("Score: %d\n", score);
	if (score <= 0) {
		printf ("You fail\n");
		return;
	}//if

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

///////////////////////////////////////
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
/*
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
*/



///////////////////////////////////////
void printTrade (struct t_trade *trade) {
	float sellSil = itemA[trade->sell].value * trade->nSell;
	float buySil = itemA[trade->buy].value * trade->nBuy;
	printf ("%3d %-16s %3d %-17s (%3.2f) \n", trade->nSell, getName (trade->sell), 
					trade->nBuy, getName (trade->buy), buySil/sellSil * 100);
}//printrade
    
    
///////////////////////////////////////
void doNear (int cnt) {
	int i;
	int basicSelA [10];
	struct t_trade trade;

	printf ("------------------\n");
	printf ("------------------\n");
	printf ("      --- Near ---\n");
	printf ("Selling  this for that\n");

	int range = e_s_jewelry - e_silver;
	enum e_item special = rand()%range + e_silver + 1;

	// Loop for the number of times 
	//		First one allows access to "special"
	for (i=0; i<cnt; i++) {

		float bonus = 1.0;
		int which = rand()%3;
		if (which)
				bonus = 1 + (rand()%30/100.0);
		else
				bonus = 1 - (rand()%20/100.0);

		enum e_item buy = rand ()%e_millStones ;
		enum e_item sell = rand ()%e_millStones ;


		// Check for collisions
		if (buy == sell){
			//printf ("Match %d %d\n", buy, sell);
			i--;
			continue;
		}//skip if perfect match

		// If we are on the first one, set it to special
		if (i == 0) buy = special;

		// Calculate for a sale of one (1)
		int factor = 1;		// Start assuming selling 1
		float silver = itemA[sell].value * bonus;	// what does 1 sell for
		silver *= 2;	// double selling value
		float numBuy = silver / itemA[buy].value ;


		// Recalculate if you need more than one item
		if (numBuy < 1) 
			factor = (int) (1.0 / (numBuy));
		numBuy = silver * factor / itemA[buy].value ;

		//printf ("Selling %d %s for %3.1f %s\n", factor, nameA[sell], numBuy, nameA[buy]);


		// Bump if losing too much on rounding
		float remainder = numBuy - (int) numBuy;
		if ((remainder < .7) && (remainder > .1)){
			factor ++;	
			numBuy = silver * factor / itemA[buy].value ;
			//printf ("Bump:   Selling %d %s for %3.1f %s\n", factor, nameA[sell], numBuy, nameA[buy]);
		}//if low round

		numBuy = (int) (numBuy + .6);


		// Set the system and print
		trade.buy = buy;
		trade.sell = sell;
		trade.nBuy = (int) numBuy;
		trade.nSell = (int) factor;;
		
		printTrade (&trade);

	}//for 


	trade.buy = special;
	trade.sell = e_silver;
	trade.nBuy = 1;
	float val = itemA[special].value ;
	if (val < 1)
		trade.nBuy = 2;
	trade.nSell = itemA[special].value * trade.nBuy;

	printTrade (&trade);
}//donear

///////////////////////////////////////
void doFar (int cnt) {
	int i;
	int basicSelA [10];
	struct t_trade trade;

	printf ("------------------\n");
	printf ("------------------\n");
	printf ("      --- Far ---\n");
	printf ("Selling  this for that\n");

	int range = e_s_jewelry - e_silver;
	enum e_item special = rand()%range + e_silver + 1;

	range = e_salt - e_silk + 1;
	enum e_item exotic = rand()%range + e_silk ;

	// Loop for the number of times 
	//		First one allows access to "special"
	for (i=0; i<cnt; i++) {

		float bonus = 1.0;
		int which = rand()%3;
		if (which)
				bonus = 1 + (rand()%30/100.0);
		else
				bonus = 1 - (rand()%20/100.0);

		enum e_item buy = rand ()%e_millStones ;
		enum e_item sell = rand ()%e_millStones ;


		// Check for collisions
		if (buy == sell){
			//printf ("Match %d %d\n", buy, sell);
			i--;
			continue;
		}//skip if perfect match

		// If we are on the first one, set it to exotic
		if (i == 0) buy = exotic;
		// If we are on the second one, trade special for exotic
		if (i == 1) {
			range = e_s_jewelry - e_silver;
			buy = rand()%range + e_silk ;
			sell = special;
		}//sell special

		// Calculate for a sale of one (1)
		int factor = 1;		// Start assuming selling 1
		float silver = itemA[sell].value * bonus;	// what does 1 sell for
		silver *= 4;	// double selling value
		float numBuy = silver / itemA[buy].value ;


		// Recalculate if you need more than one item
		if (numBuy < 1) 
			factor = (int) (1.0 / (numBuy));
		numBuy = silver * factor / itemA[buy].value ;

		//printf ("Selling %d %s for %3.1f %s\n", factor, nameA[sell], numBuy, nameA[buy]);


		// Bump if losing too much on rounding
		float remainder = numBuy - (int) numBuy;
		if ((remainder < .7) && (remainder > .1)){
			factor ++;	
			numBuy = silver * factor / itemA[buy].value ;
			//printf ("Bump:   Selling %d %s for %3.1f %s\n", factor, nameA[sell], numBuy, nameA[buy]);
		}//if low round

		numBuy = (int) (numBuy + .6);


		// Set the system and print
		trade.buy = buy;
		trade.sell = sell;
		trade.nBuy = (int) numBuy;
		trade.nSell = (int) factor;;
		
		printTrade (&trade);

	}//for 


	trade.buy = exotic;
	trade.sell = e_silver;
	trade.nBuy = 1;
	float val = itemA[exotic].value ;
	if (val < 1)
		trade.nBuy = 2;
	trade.nSell = itemA[exotic].value * trade.nBuy;

	printTrade (&trade);

}//dofar

///////////////////////////////////////
void doCards () {
	int i;
    
	printf ("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf ("-- Near --\n");
	for (i=0; i<6; i++) 
		doNear(5);

    printf ("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf ("-- Far --\n");
    for (i=0; i<4; i++) 
		doFar(6);
    
	printf ("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf ("-- Age 1 Goals --\n");
	for (i=0; i<10; i++) 			{
		printf ("Goal: %s\n", setGoal (1) );
    	printf ("      Award: %s\n", award (1) );
	}//for

}//cards

///////////////////////////////////////
int main (int argc, char *argv[]){

	int i;
	int val;
	time_t t;

	//srand ((unsigned) time (&t));
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
		printf ("	r - Raid a neighboring clan\n");		
		printf ("	b - Be attacked by a neighboring clan\n");
		printf ("	g - Goal (%s)\n", ageStrA [age] );
		printf ("	a - Award  (%s)\n", ageStrA [age] );
		printf ("	c - Change Age from %s\n", ageStrA [age] );

		printf ("	n - Explor 'near' \n");
		printf ("	f - Explor 'far' \n");
      printf ("	1 - Print Cards\n");

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
			doNear(4);
			break;
		case 'M':		
		case 'm':		
		case 'F':		
		case 'f':		
			location = 3;
			doFar(5);
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

