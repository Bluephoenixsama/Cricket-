#include<iostream>
#include<cstdlib>
#include<string.h>
#include<string>
#include<time.h>

using namespace std;

class Team1;
class Team2;



void Toss_Centre();
void display(int toss,int choice);
void match_time(int toss, int choice);
void first_innings(string first,string second);
void second_innings(int target,int out1,string first,string second);
void final_centre(int score1,int score2,int out2,string first,string second);

string rest;
int BALLS;
string ch,venue,result,team1,team2;
int n,total_overs;
void Match_Centre()
			{
				system("cls");
				cout<<endl<<"Match  INFO"<<endl;
				cout<<endl<<"Overs : ";
				cin>>total_overs;
				BALLS=(total_overs)*6;
				getline(cin,ch);
				cout<<endl<<"Team 1 : ";
				getline(cin,team1);
				cout<<endl<<"Team 2 : ";
				getline(cin,team2);
				cout<<endl<<"Venue : ";
				getline(cin,venue);
				Toss_Centre();
			}	
void Toss_Centre(){
	int toss,choice;
	cout<<"Who won the toss?\n\t1."<<team1<<"\t2."<<team2<<"\t: ";
	cin>>toss;
	cout<<"What choice?\n1.Bat\t2.Bowl\t: ";
	cin>>choice;
	display(toss,choice);
}
void display(int toss,int choice){
    system("cls");
	cout<<"\n\n\t\tWelcome to the match between\n\n\n\t\t\t\t"<<team1<<"\tVS\t"<<team2<<endl;
	cout<<"\n\n\t\tIt's a "<<total_overs<<" overs game per side.\n";
	cout<<"\n\t\tSo it's a "<<BALLS<<" balls game per side.\n";
	cout<<"\n\n\n\t\t\tIt's being played at : "<<venue<<endl;
	cout<<"\n\n\n\n";
	switch (toss)
    {

    case 1:
        cout<<"\t\t" <<team1<<" WON THE TOSS and decided to ";
        switch (choice)
        {
        case 1:
            cout << "BAT FIRST\n";
            break;
        case 2:
            cout << "BOWL FIRST\n";
            break;
        }
        break;

    case 2:
        cout<<"\t\t" <<team2<<" WON THE TOSS and decided to ";
        switch (choice)
        {
        case 1:
            cout << "BAT FIRST.\n";
            break;
        case 2:
            cout << "BOWL FIRST.\n";
            break;
        }
        break;
    }
	getline(cin,ch);
	cout<<"\n\nPress enter to continue:\n";
	getline(cin,rest);
	match_time(toss,choice);
}
void match_time(int toss, int choice)
{
	if (toss == 1 && choice == 1)
        	first_innings(team1,team2);
    	else
        	first_innings(team2,team1);
}



void first_innings(string first,string second){
	system("cls");
	cout<<"\n\tStart of the first inning:\n\n";
	cout<<first<<" is batting now:\n\n";
	cout<<"please enter ball by ball entries below: ";

	cout<<"\n\nPress enter to continue:\n";
	getline(cin,rest);
int over,ball,out,runs;
int overRuns=0;
int outs=0;
int score=0;
 for (over = 0; over < total_overs; over++)
    {
	system("cls");
        out = 0;
	cout<<first<<" is batting now (FIRST INNING):\n\n";
	cout<<"Over number: "<<over+1<<endl<<endl;
        for (ball = 0; ball < 6; ball++)
        {
            cout << "Enter run scored in ball " << ball + 1 << " (11 for out, 22 for wide, 33 for no ball): ";
            cin >> runs;
            if (runs == 11)
            {
                out++;
                runs = 0;
		    overRuns+=0;
            }
            else if (runs == 22)
            {
                ball--;
                runs = 1;
		    overRuns+=1;
            }
            else if (runs == 33)
            {
                ball--;
                runs = 1;
		    overRuns+=1;
            }
		else
            	overRuns += runs;
            if (outs + out == 10)
                break;
        }
        outs += out;
        score += overRuns;
        if (outs == 10)
            break;
        cout << "\n\n";
        cout << "at the end of " <<over+1<< "overs,\t";
        cout << "score is " <<score<< "/" << outs;
        cout << "\n in this over, " <<overRuns<< "/" << out;
	  getline(cin,ch);
	  cout<<"\n\nPress enter to continue:\n";
	  getline(cin,rest);
    }
    int score1 = score;
    int out1 = outs;

	if (ball<6)
		cout << "\nIN " << over - 1 << "." << ball << " they scored " <<score<< "/" << outs;
	else if (ball==6)
		cout << "\nIN " << over<< " overs, they scored " <<score<< "/" << outs;

	cout<<"\n\nPress enter to continue...";
	getline(cin,rest);
	system("cls");
	cout << "\n\nAfter first inning,"<<first<<"'s score is " <<score<< "/" <<outs;

	cout<<"\n\nPress enter to proceed to Second inning:\n";
	getline(cin,rest);
	system("cls");
	second_innings(score1+1,out1,first,second);

}



void second_innings(int target,int out1,string first,string second){
	cout<<"\n\tStart of the second inning:\n\n";
	cout<<second<<" is batting now:\n\n";
	cout<<"please enter ball by ball entries below: ";
	cout<<"\n\nPress enter to continue:\n";
	getline(cin,rest);

	system("cls");

int over,ball,out,runs;
int overRuns=0;
int outs=0;
int score=0;

 for (over = 0; over < total_overs; over++)
    {
        out = 0;
	  cout<<second<<" is batting now(SECOND INNING):\n\n";

	  cout<<"Over number: "<<over+1<<endl<<endl;
        for (ball = 0; ball < 6; ball++)
        {
            cout << "Enter run scored in ball " << ball + 1 << " (11 for out, 22 for wide, 33 for no ball): ";
            cin >> runs;
            if (runs == 11)
            {
                out++;
                runs = 0;
	          overRuns+=0;
            }
            else if (runs == 22)
            {
                ball--;
                runs = 1;
   		    overRuns+=1;
            }
            else if (runs == 33)
            {
                ball--;
                runs = 1;
		    overRuns+=1;
            }
		else
            overRuns += runs;
            if (outs + out == 10)
                break;
		if (overRuns >=target)
		    break;
        }
        outs += out;
        score += overRuns;
        if (outs == 10)
            break;
        cout << "\n\n";
        cout << "at the end of " <<over+1<< " over[s],\t";
        cout << "score is " <<score<< "/" << outs;
        cout << "\n in this over, " << overRuns << "/" << out;
		getline(cin,ch);
	  cout<<"\n\nPress enter to continue:\n";
	  getline(cin,rest);
	  
        system("cls");
	
    }
    int score2 = score;
    int out2 = outs;
	if (ball<6)
		cout << "\nIN " << over - 1 << "." << ball << " they scored " <<score<< "/" << outs;
	else if (ball==6)
		cout << "\nIN " << over<< " overs, they scored " <<score<< "/" << outs;

	cout<<"\n\nPress enter to continue...";
	getline(cin,rest);
	system("cls");
	cout << "\n\nAfter second inning,"<<second<<"'s score is " <<score<< "/" << outs;
	
	cout<<"\n\nMatch has ended!, Press enter to go to the result:\n";
	getline(cin,rest);
	final_centre(target-1,score2,out2,first,second);
}



void final_centre(int score1,int score2,int out2,string first,string second){

	system("cls");
	cout<<"\n\n\t\tFINALLY, WE HAVE THE WINNER!\n\n";
	if (score2>score1)
		cout<<"\n\n\t\t"<<second<<"\t WINS BY "<<10-out2<<" WICKETS!!!\n\n";
	else if (score2 == score1)
            cout << "The match is tied.";
	else
		cout<<"\n\n\t\t"<<first<<"\t WINS BY "<<score1-score2<<" RUNS!!!\n\n";
}


int main()
{
    Match_Centre();
    return 0;
}