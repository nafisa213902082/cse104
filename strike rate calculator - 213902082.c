/**
 * 
 * author: 	Nafisa Lubaba Khan 
 * id: 		213902082
 * email: 	nraisa02@gmail.com
 * 
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

// ----------------------------------------
// structures
// -----------------------

typedef struct batter_strikerate_info{
	char batter_name[31];
	char team[31];
	char against_team[31];
	char current_time[31];
	int batting_position, ball_faced, runs;
	float strike_rate;
} batter_info;

typedef struct bowler_strikerate_info{
	char bowler_name[31];
	char bowler_type[31];
	char team[31];
	char against_team[31];
	char current_time[31];
	int overs, wickets, runs;
	float strike_rate;
} bowler_info;

typedef struct all_batter_strikerate_info{
	batter_info * single_batter_info;
	struct all_batter_strikerate_info * next_batter_info;
} singly_batter;

typedef struct all_bowler_strikerate_info{
	bowler_info * single_bowler_info;
	struct all_bowler_strikerate_info * next_bowler_info;
} singly_bowler;


singly_batter * all_batter_infolist = NULL;
singly_bowler * all_bowler_infolist = NULL;

// ----------------------------------------
// function prototype
// -----------------------

batter_info * init_BatterInfo(); bowler_info * init_BowlerInfo(); singly_batter * init_SinglyBatter(); singly_bowler * init_SinglyBowler();

batter_info * insertion_BatterInfo(
	char * batter_name,	char * team, char * against_team, char * current_time, int batting_position, int ball_faced, int runs
);
bowler_info * insertion_BowlerInfo(
	char * bowler_name,	char * team, char * against_team, char * current_time, char * bowler_type, int overs, int runs,	int wickets
);

singly_batter * insertion_SinglyBatter(singly_batter * all_batter_infolist, batter_info * new_batter_info);
singly_bowler * insertion_singly_bowler(singly_bowler * all_bowler_infolist, bowler_info * new_bowler_info);

void screen_singly_batter(singly_batter * all_batter_infolist);
void screen_singly_bowler(singly_bowler * all_bowler_infolist);

float calculate_BowlingStrikeRate(int overs, int wickets);
float calculate_BattingStrikeRate(int ball_faced, int runs);

char * CurrentTime();
void niceHeader(char * header_text); void clickAndContinue(int clear_screen);

void optionPanel();
void option1(); void option2(); void option3(); void option4(); void option5(); void option6();

// ----------------------------------------
// functions processing
// -----------------------

char * CurrentTime(){
	time_t time_function = time(NULL);
    struct tm *time_pointer = localtime(&time_function);

    char temp[51];
    strftime(temp, sizeof(temp), "%c", time_pointer);

    char * current_time = (char *) malloc(sizeof(char));
    strcpy(current_time, temp);

    return (char *) current_time;
}

batter_info * init_BatterInfo(){
	batter_info * blank = (batter_info *) malloc(sizeof(batter_info));
	return blank;
}
bowler_info * init_BowlerInfo(){
	bowler_info * blank = (bowler_info *) malloc(sizeof(bowler_info));
	return blank;
}

singly_batter * init_SinglyBatter(){
	singly_batter * blank = (singly_batter *) malloc(sizeof(singly_batter));
	blank -> next_batter_info = NULL;
	return blank;
}
singly_bowler * init_SinglyBowler(){
	singly_bowler * blank = (singly_bowler *) malloc(sizeof(singly_bowler));
	blank -> next_bowler_info = NULL;
	return blank;
}

batter_info * insertion_BatterInfo(
	char batter_name[31], char team[31], char against_team[31], char current_time[31], int batting_position, int ball_faced, int runs){
	batter_info * single_batter_info = init_BatterInfo();
	strcpy(single_batter_info -> batter_name, batter_name);
	strcpy(single_batter_info -> team, team);
	strcpy(single_batter_info -> against_team, against_team);
	strcpy(single_batter_info -> current_time, current_time);
	single_batter_info -> batting_position = batting_position;
	single_batter_info -> ball_faced = ball_faced;
	single_batter_info -> runs = runs;
	single_batter_info -> strike_rate = calculate_BattingStrikeRate(ball_faced, runs);
	return single_batter_info;
}
bowler_info * insertion_BowlerInfo(
	char bowler_name[31], char team[31], char against_team[31], char current_time[31], char bowler_type[31], int overs, int runs, int wickets){
	bowler_info * single_bowler_info = init_BowlerInfo();
	strcpy(single_bowler_info -> bowler_name, bowler_name);
	strcpy(single_bowler_info -> bowler_type, bowler_type);
	strcpy(single_bowler_info -> team, team);
	strcpy(single_bowler_info -> against_team, against_team);
	strcpy(single_bowler_info -> current_time, current_time);
	single_bowler_info -> overs = overs; 
	single_bowler_info -> wickets = wickets; 
	single_bowler_info -> runs = runs;
	single_bowler_info -> strike_rate = calculate_BowlingStrikeRate(overs, wickets);
	return single_bowler_info;
}

singly_batter * insertion_SinglyBatter(
	singly_batter * all_batter_infolist, batter_info * new_batter_info){

	singly_batter * new_batter = init_SinglyBatter();
	new_batter -> single_batter_info = new_batter_info;

	singly_batter * temp = init_SinglyBatter();
	temp = all_batter_infolist;

	if(temp == NULL){	
		all_batter_infolist = new_batter;
	}else{
		while(temp -> next_batter_info != NULL){
			printf("%s", temp -> single_batter_info -> batter_name);
			temp = temp -> next_batter_info;
		} temp -> next_batter_info = new_batter;
	}
	return all_batter_infolist;
}
singly_bowler * insertion_singly_bowler(singly_bowler * all_bowler_infolist, bowler_info * new_bowler_info){
	singly_bowler * new_bowler = init_SinglyBowler();
	new_bowler -> single_bowler_info = new_bowler_info;

	singly_bowler * temp = init_SinglyBowler();
	temp = all_bowler_infolist;

	if(temp == NULL){	
		all_bowler_infolist = new_bowler;
	}else{
		while(temp -> next_bowler_info != NULL){
			printf("%s",temp -> single_bowler_info -> bowler_name);
			temp = temp -> next_bowler_info;
		} temp -> next_bowler_info = new_bowler;
	}
	return all_bowler_infolist;
}

void screen_singly_batter(singly_batter * all_batter_infolist){
	singly_batter * each_batter = init_SinglyBatter();
	each_batter = all_batter_infolist;
	while(each_batter != NULL){
		printf(
			"Batter Name\t: %s\n"
			"Team\t\t: %s\n"
			"Against Team\t: %s\n"
			"Current Time\t: %s\n"
			"Position\t: %d\n"
			"Bowl Faced\t: %d\n"
			"runs\t\t: %d\n"
			"Strike Rate\t: %.2f\n",
			each_batter -> single_batter_info -> batter_name, each_batter -> single_batter_info -> team, each_batter -> single_batter_info -> against_team, each_batter -> single_batter_info -> current_time, each_batter -> single_batter_info -> batting_position, each_batter -> single_batter_info -> ball_faced, each_batter -> single_batter_info -> runs, each_batter -> single_batter_info -> strike_rate);
		printf("\n""-------------------\n");
		each_batter = each_batter -> next_batter_info;
	}
}

void screen_singly_bowler(singly_bowler * all_bowler_infolist){
	singly_bowler * each_bowler = init_SinglyBowler();
	each_bowler = all_bowler_infolist;
	while(each_bowler != NULL){
		printf(
			"bowler_name: %s\n"
			"bowler_type: %s\n"
			"team: %s\n"
			"against_team: %s\n"
			"current_time: %s\n"
			"overs: %d\n"
			"wickets: %d\n"
			"runs: %d\n"
			"Strike Rate: %.2f\n",
			each_bowler -> single_bowler_info -> bowler_name, each_bowler -> single_bowler_info -> bowler_type, each_bowler -> single_bowler_info -> team, each_bowler -> single_bowler_info -> against_team, each_bowler -> single_bowler_info -> current_time, each_bowler -> single_bowler_info -> overs, each_bowler -> single_bowler_info -> wickets, each_bowler -> single_bowler_info -> runs, each_bowler -> single_bowler_info -> strike_rate);
		each_bowler = each_bowler -> next_bowler_info;
		printf("\n\n");
	}
}

void niceHeader(char * header_text){
	printf(
		"-=-=-=-=-=-=-=--=-=-=-=\n"
		" %s: \n"
		"=-=-=-=-=-=-=--=-=-=-=-\n""\n",
		header_text);
}

void clickAndContinue(int clear_screen){
	printf("click and continue ");
	getch();

	printf("\n");
	if(clear_screen){ system("cls"); }
}

float calculate_BowlingStrikeRate(int overs, int wickets){
	float strike_rate = (overs * 6) / (float) wickets;
	return strike_rate;
}

float calculate_BattingStrikeRate(int ball_faced, int runs){
	float strike_rate = (runs / (float) ball_faced) * 100;
	return strike_rate;
}

void optionPanel(){
	int option;
	while(option != 6){
		niceHeader("OptionPanel");

		printf(
			"\t1 -add batter stats\n"
			"\t2 -add bowler stats\n"
			"\t3 -display all batter stats\n"
			"\t4 -display all bowler stats\n"
			"\t5 -use strike rate calculator\n"
			"\t6 -exit\n""\n");

		printf("$$ your option: ");	
		scanf("%d", &option);
		if(option == 1){ option1(); }
		else if(option == 2){ option2(); }
		else if(option == 3){ option3(); }
		else if(option == 4){ option4(); }
		else if(option == 5){ option5(); }
		else{
			option = 6;
			option6();
		}	

		printf("\n");
		clickAndContinue(1);
	}
}

void option1(){ 
	char batter_name[31]; char team[31]; char against_team[31]; int batting_position, ball_faced, runs;

	system("cls");
	niceHeader("add batsman stats");
	
	printf("\tBatter name: ");
	getchar();
	gets(batter_name);

	printf("\tBatting position: ");
	scanf("%d", &batting_position);

	printf("\tBowl faced: ");
	scanf("%d", &ball_faced);

	printf("\tRuns: ");
	scanf("%d", &runs);

	printf("\tTeam: ");
	getchar();
	gets(team);

	printf("\tAgainst team: ");
	gets(against_team);

	all_batter_infolist = insertion_SinglyBatter(
		all_batter_infolist,
		insertion_BatterInfo(batter_name, team, against_team, CurrentTime(), batting_position, ball_faced, runs)
	);
}

void option2(){
	char bowler_name[31]; char team[31]; char against_team[31]; char current_time[31]; char bowler_type[31]; int overs; int runs; int wickets;

	system("cls");
	niceHeader("add bowler stats");
	
	printf("\tBowler name: ");
	getchar();
	gets(bowler_name);

	printf("\tBowler type: ");
	gets(bowler_type);

	printf("\tOvers: ");
	scanf("%d", &overs);

	printf("\tRuns: ");
	scanf("%d", &runs);

	printf("\tWickets: ");
	scanf("%d", &wickets);

	printf("\tTeam: ");
	getchar();
	gets(team);

	printf("\tAgainst team: ");
	gets(against_team);


	all_bowler_infolist = insertion_singly_bowler(
		all_bowler_infolist,
		insertion_BowlerInfo(bowler_name, team, against_team, CurrentTime(), bowler_type, overs, runs, wickets)
	);
}

void option3(){
	system("cls");
	niceHeader("all batter stats");
	screen_singly_batter(all_batter_infolist);
}

void option4(){
	system("cls");
	niceHeader("all bowler stats");
	screen_singly_bowler(all_bowler_infolist);
}

void option5(){
	system("cls");
	niceHeader("strike rate calculator");

	printf(
		"calculate strike rate for\n"
		"\t1. batter\n""\t2. bowler\n""\n");
	int option;

	printf("$$ option: ");
	scanf("%d", &option);

	printf("\n");

	system("cls");
	if(option == 1){
		niceHeader("batter strike rate calculator");
		printf("\tRuns: ");
		int runs;
		scanf("%d", &runs);

		printf("\tBall faced: ");
		int ball_faced;
		scanf("%d", &ball_faced);

		printf(
			"\n"
			"@. strike rate: %.2f",
			calculate_BattingStrikeRate(ball_faced, runs));
	}else{
		niceHeader("bowler strike rate calculator");
		printf("\tOvers: ");
		int overs;
		scanf("%d", &overs);

		printf("\tWickets: ");
		int wickets;
		scanf("%d", &wickets);

		printf(
			"\n""@. strike rate: %.2f",
			calculate_BowlingStrikeRate(overs, wickets));
	}
	printf("\n\n");
}

void option6(){
	printf("\n");
	printf("!! Thanks for using this program. \n");
	exit(0);
}

// ----------------------------------------
// main function
// -----------------------

int main(){
	optionPanel();
	return 0;
}