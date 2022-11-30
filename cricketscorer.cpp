#include<iostream>
#include<cstdlib>
#include<string.h>
#include<string>
#include<time.h>
#include<fstream>
#include<Windows.h>
using namespace std;
void MainMenu();

int match_number;
char ball_by_ball;

void Match_Centre();
void Toss_Centre();
void display(int toss, int choice);
void match_time(int toss, int choice);
void first_innings(string first, string second);
void second_innings(int target, int out1, string first, string second);
void final_centre(int score1, int score2, int out2, string first, string second);
void Home();

void Home() {
    int direct;
    system("cls");
    cout << "\n\n\n\n\t\033[1;90;103m=================================================================================\033[0m\n";
    cout << "\t\033[1;90;103m******************************\033[0m\033[4;34;47mCricket Data Analyzer\033[0m\033[1;90;103m******************************\033[0m\n";
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";
    cout << "\n\t\033[5;32;94mEnter choices:\033[0m\n\n";
error:
    cout << "\t\033[0;34;42m1.Continue\033[0m\n\n\t\033[0;34;101m2.Exit\033[0m\n\n\t";
    cin >> direct;
    switch (direct) {
    case 1:
        MainMenu();
        break;
    case 2:
        Sleep(1000);
        system("cls");
        exit;
        break;
    default:
        cout << "\n\n\tSorry Type Again!!\n";
        goto error;
        break;
    }

}
void MainMenu() {
    int direct;
    system("cls");
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";
    cout << "\t\033[1;90;103m******************************\033[0m\033[4;34;47mCricket Data Analyzer\033[0m\033[1;90;103m******************************\033[0m\n";
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";


    cout << "\n\n\t\033[1;35;47m=================================================================================\033[0m\n";
    cout << "\t\033[1;35;47m************************************\033[0m\033[4;31;47mMain Menu\033[0m\033[1;35;47m************************************\033[0m\n";
    cout << "\t\033[1;35;47m=================================================================================\033[0m\n";
    cout << "\n\n\t\033[5;97;104mChoose:\033[0m";
again:
    cout << "\n\n\t\033[0;31;106m1.New Match\033[0m\n\n\t\033[0;31;47m2.Back\033[0m\n\n\t";
    cin >> direct;
    switch (direct) {
    case 1:
        Match_Centre();
        break;
    case 2:
        Home();
        break;
    default:
        cout << "\tSorry Type Again!\n";
        goto again;
    }
}


void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

typedef struct {
    string name;
    float ovr;
    int rans;
    int wickets;
}bowler;

bowler bf[9];
bowler bs[9];

typedef struct {
    string name;
    int bowl, ran, four, six;
}batman;
batman bfirst[11];
batman bsecond[11];


string rest;
int BALLS;
string ch, venue, result, team1, team2;
int n, total_overs;


void Match_Centre()
{
    system("cls");
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";
    cout << "\t\033[1;90;103m******************************\033[0m\033[4;34;47mCricket Data Analyzer\033[0m\033[1;90;103m******************************\033[0m\n";
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";
    cout << endl << "\n\n\t\t\t\033[1;30;101m---------- SET MATCH  INFO ! ----------\033[0m" << endl;
    cout << "\n\n\t\033[3;36;45mMatch number: \033[28m";
    cin >> match_number;
    cout << endl << "\n\tOvers : ";
    cin >> total_overs;
    BALLS = (total_overs) * 6;
    getline(cin, ch);
    cout << endl << "\n\tTeam 1 : ";
    getline(cin, team1);
    cout << endl << "\n\tTeam 2 : ";
    getline(cin, team2);
    cout << endl << "\n\tVenue : ";
    getline(cin, venue);
    Toss_Centre();
}
void Toss_Centre() {
    int toss, choice;
    cout << "\n\tWho won the toss?\n\n\t1." << team1 << "\n\n\t2." << team2 << "\n\n\t: ";
    cin >> toss;
    cout << "\n\tWhat choice?\n\n\t1.Bat\n\n\t2.Bowl\n\n\t: ";
    cin >> choice;
    cout << "\033[0m";
    display(toss, choice);
}
void display(int toss, int choice) {
    system("cls");
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";
    cout << "\t\033[1;90;103m******************************\033[0m\033[4;34;47mCricket Data Analyzer\033[0m\033[1;90;103m******************************\033[0m\n";
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";
    cout << endl << "\n\n\t\t   \033[1;30;101m---------- Match Details ----------\033[0m" << endl;

    cout << "\n\n\n\t\t\t\t\033[4;35;47m" << team1 << "\033[0m\t  \033[4;90;104mVS\033[0m\t\033[4;34;103m" << team2 << endl;
    cout << "\033[0m\n\n\t\t\t\t\033[1;32;101mIt's a " << total_overs << " overs game per side.\033[28m\n";
    cout << "\n\t\t\t    So, it's a " << BALLS << " balls game per side.\n";
    cout << "\n\n\n\t\t\t\tIt's being played at :\033[0m \033[4;97;100m" << venue << "\033[0m";
    cout << "\n\n\n\n\t\t\t\033[0;45;106m";
    switch (toss)
    {

    case 1:
        cout << team1 << " WON THE TOSS and decided to \033[28m";
        switch (choice)
        {
        case 1:
            cout << "BAT FIRST";
            break;
        case 2:
            cout << "BOWL FIRST";
            break;
        }
        break;

    case 2:
        cout << team2 << " WON THE TOSS and decided to ";
        switch (choice)
        {
        case 1:
            cout << "BAT FIRST.";
            break;
        case 2:
            cout << "BOWL FIRST.";
            break;
        }
        break;
    }
    getline(cin, ch);
    cout << "\033[0m\n\n\n\n\033[0;97;100mPress enter to continue...\033[0m\n";
    getline(cin, rest);
    system("cls");
    match_time(toss, choice);
}
void match_time(int toss, int choice)
{
    if (toss == 1 && choice == 1)
        first_innings(team1, team2);
    else
        first_innings(team2, team1);
}



void first_innings(string first, string second) {
    int i = 0;
    int j = 1;
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";
    cout << "\t\033[1;90;103m******************************\033[0m\033[4;34;47mCricket Data Analyzer\033[0m\033[1;90;103m******************************\033[0m\n";
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";

    cout << endl << "\n\n\t\t   \033[1;30;101m---------- FIRST INNINGS ----------\033[0m" << endl;

    cout << "\n\t\033[0;45;106mStart of the first inning:\033[28m\n\n";
    cout << first << " is batting now:\n\n";
    cout << "Enter the name of batsman1: ";
    getline(cin, bfirst[i].name);
    cout << "Enter the name of batsman2: ";
    getline(cin, bfirst[j].name);
    cout << "\nplease enter ball by ball entries below: ";

    cout << "\n\nPress enter to continue:\n";
    getline(cin, rest);
    int over, ball, out, runs;

    int outs = 0;
    int score = 0;
    int k = 0;
    for (over = 0; over < total_overs; over++)
    {
        int overRuns = 0;
        system("cls");
        cout << "\033[0m\t\033[1;90;103m=================================================================================\033[0m\n";
        cout << "\t\033[1;90;103m******************************\033[0m\033[4;34;47mCricket Data Analyzer\033[0m\033[1;90;103m******************************\033[0m\n";
        cout << "\t\033[1;90;103m=================================================================================\033[0m\n";
        cout << endl << "\n\n\t\t   \033[1;30;101m---------- FIRST INNINGS ----------\033[0m\n\n\033[0;45;106m" << endl;

        out = 0;
        cout << first << " is batting now (FIRST INNING):\033[28m\n\n";
        cout << "Enter the name of the bowler: ";
        getline(cin, bf[k].name);

        cout << "Over number: " << over + 1 << " bowler: " << bf[k].name << endl;
        cout << "\n\033[5;90;104mEnter Runs Scored\033[0m  \033[1;30;41m O for Out\033[0m  \033[1;34;47mN for No Ball  \033[1;90;105mW for Wide Ball\033[0m\n\n";
        for (ball = 0; ball < 6; ball++)
        {
            cout << "\033[5;90;104mBall " << ball + 1 << " \033[0m";
            cout << bfirst[j].name <<"->"<< bfirst[j].ran << "(" << bfirst[j].bowl << ")" << endl;
            cout << "\033[0m      \033[28m"<<bfirst[i].name << "->" << bfirst[i].ran << "(" << bfirst[i].bowl << ") *:";
        A:
            cin >> ball_by_ball;
            if (ball_by_ball == 'O' || ball_by_ball == 'o')
            {
                out++;
                runs = 0;
                overRuns += runs;
                bfirst[i].bowl++;
                i = i + 1;
                if (i == j)
                {
                    i = i + 1;
                }
                getline(cin, ch);
                cout << "\nEnter the name of next batsman: ";
                getline(cin, bfirst[i].name);
            }
            else if (ball_by_ball == 'W' || ball_by_ball == 'w')
            {
                ball--;
                runs = 1;
                overRuns += runs;
            }
            else if (ball_by_ball == 'N' || ball_by_ball == 'n')
            {
                ball--;
                runs = 1;
                overRuns += runs;
            }
            else if (ball_by_ball == '0')
            {
                runs = 0;
                overRuns += runs;
                bfirst[i].ran += runs;
                bfirst[i].bowl++;
            }
            else if (ball_by_ball == '1')
            {
                runs = 1;
                overRuns += runs;
                bfirst[i].ran += runs;
                bfirst[i].bowl++;
                swap(i, j);
            }
            else if (ball_by_ball == '2')
            {
                runs = 2;
                overRuns += runs;
                bfirst[i].ran += runs;
                bfirst[i].bowl++;
            }
            else if (ball_by_ball == '3')
            {
                runs = 3;
                overRuns += runs;
                bfirst[i].ran += runs;
                bfirst[i].bowl++;
                swap(i, j);
            }
            else if (ball_by_ball == '4')
            {
                runs = 4;
                overRuns += runs;
                bfirst[i].ran += runs;
                bfirst[i].bowl++;
                bfirst[i].four++;
            }
            else if (ball_by_ball == '5')
            {
                runs = 5;
                overRuns += runs;
                bfirst[i].ran += runs;
                bfirst[i].bowl++;
                swap(i, j);
            }
            else if (ball_by_ball == '6')
            {
                runs = 6;
                overRuns += runs;
                bfirst[i].ran += runs;
                bfirst[i].bowl++;
                bfirst[i].six++;
            }
            else {
                cout << "type again";
                goto A;
            }
            if (outs + out == 10)
                break;
        }
        outs += out;
        score += overRuns;
        if (outs == 10)
            break;
        cout << "\n\n";
        if (ball < 6)
        {
            bf[k].ovr += ball / 10;
        }
        else {
            bf[k].ovr += 1;
        }
        bf[k].rans += overRuns;
        bf[k].wickets += out;

        cout << "at the end of " << over + 1 << "  overs,\t";
        cout << "score is " << score << "/" << outs;
        cout << "\n in this over, " << overRuns << "/" << out;
        getline(cin, ch);
        cout << "\n\nPress enter to continue:\033[0m\n";
        getline(cin, rest);
        k++;
        swap(i, j);
    }
    int score1 = score;
    int out1 = outs;

    if (ball < 6)
    {
        cout << "\nIN " << over - 1 << "." << ball << " they scored " << score << "/" << outs;
    }
    else if (ball == 6)
        cout << "\nIN " << over << " overs, they scored " << score << "/" << outs;

    cout << "\n\nAfter first inning," << first << "'s score is " << score << "/" << outs;

    Sleep(1000);
    system("cls");
    cout << "\t\033[0m\033[1;90;103m=================================================================================\033[0m\n";
    cout << "\t\033[1;90;103m******************************\033[0m\033[4;34;47mCricket Data Analyzer\033[0m\033[1;90;103m******************************\033[0m\n";
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";

    cout << endl << "\n\n\t\t   \033[1;30;101m---------- FIRST INNINGS BATTING SCORECARD ----------\033[0m" << endl;

    cout << endl << "Batsman Name\t\t\t      runs(balls)  fours  sixes\n";
    for (i = 0; i < 11; i++) {
        if (bfirst[i].name == "")
            break;
        cout << endl << bfirst[i].name << "        \t\t\t" << bfirst[i].ran << "(" << bfirst[i].bowl << ")   " << bfirst[i].four << "   " << bfirst[i].six << endl;

    }
    Sleep(10000);
    system("cls");

    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";
    cout << "\t\033[1;90;103m******************************\033[0m\033[4;34;47mCricket Data Analyzer\033[0m\033[1;90;103m******************************\033[0m\n";
    cout << "\t\033[1;90;103m=================================================================================\033[0m\n";

    cout << endl << "\n\n\t\t   \033[1;30;101m---------- FIRST INNINGS BOWLING SCORECARD ----------\033[0m" << endl;
    cout << endl << "Bowler Name\t       overs\t   runs\t  wickets\n";
    for (i = 0; i < 9; i++) {
        if (bf[i].name == "")
            break;
        cout << endl << bf[i].name << " \t\t" << bf[i].ovr << "\t" << bf[i].rans << "\t" << bf[i].wickets << endl;

    }


    cout << "\n\nPress enter to proceed to Second inning:\n";
    getline(cin, rest);
    system("cls");
    second_innings(score1 + 1, out1, first, second);

}



void second_innings(int target, int out1, string first, string second) {
    int l = 0;
    int i = 0;
    int j = 1;
    cout << "\n\tStart of the second inning:\n\n";
    cout << second << " is batting now:\n\n";
    cout << "Enter the name of batsman1: ";
    getline(cin, bsecond[i].name);
    cout << "Enter the name of batsman2: ";
    getline(cin, bsecond[j].name);

    cout << "please enter ball by ball entries below: ";
    cout << "\n\nPress enter to continue:\n";
    getline(cin, rest);

    system("cls");

    int over, ball, out, runs;

    int outs = 0;
    int score = 0;

    for (over = 0; over < total_overs; over++)
    {

        out = 0;
        int overRuns = 0;
        cout << second << " is batting now(SECOND INNING):\n\n";
        cout << "Enter the name of the bowler: ";
        getline(cin, bs[l].name);

        cout << "Over number: " << over + 1 << " bowler: " << bs[l].name << endl;

        cout << "\033[5;90;104mEnter Runs Scored\033[0m  \033[1;30;41m O for Out\033[0m  \033[1;34;47mN for No Ball  \033[1;90;105mW for Wide Ball\033[0m\n\n";

        for (ball = 0; ball < 6; ball++)
        {
            cout << bsecond[j].name << endl;
            cout << bsecond[i].name << "* : ";
        B:
            cin >> runs;
            if (runs == 79 || runs == 111)
            {
                out++;
                runs = 0;
                overRuns += 0;
                bsecond[i].bowl++;
                i = i + 1;
                if (i == j)
                {
                    i = i + 1;
                }
                getline(cin, ch);
                cout << "\nEnter the name of next batsman: ";

                getline(cin, bsecond[i].name);
            }
            else if (runs == 87 || runs == 119)
            {
                ball--;
                runs = 1;
                overRuns += 1;
            }
            else if (runs == 79 || runs == 110)
            {
                ball--;
                runs = 1;
                overRuns += 1;
            }
            else if (runs == 0)
            {
                overRuns += runs;
                bsecond[i].ran += runs;
                bsecond[i].bowl++;
            }
            else if (runs == 1)
            {
                overRuns += runs;
                bsecond[i].ran += runs;
                bsecond[i].bowl++;
                swap(i, j);
            }
            else if (runs == 2)
            {
                overRuns += runs;
                bsecond[i].ran += runs;
                bsecond[i].bowl++;
            }
            else if (runs == 3)
            {
                overRuns += runs;
                bsecond[i].ran += runs;
                bsecond[i].bowl++;
                swap(i, j);
            }
            else if (runs == 4)
            {
                overRuns += runs;
                bsecond[i].ran += runs;
                bsecond[i].bowl++;
                bsecond[i].four++;
            }
            else if (runs == 5)
            {
                overRuns += runs;
                bsecond[i].ran += runs;
                bsecond[i].bowl++;
                swap(i, j);
            }
            else if (runs == 6)
            {
                overRuns += runs;
                bsecond[i].ran += runs;
                bsecond[i].bowl++;
                bsecond[i].six++;
            }
            else {
                cout << "type again";
                goto B;
            }
            if (outs + out == 10)
                break;
            if (score + overRuns >= target)
                break;
        }
        outs += out;
        score += overRuns;
        if (ball < 6)
        {
            bs[l].ovr += ball / 10;
        }
        else {
            bs[l].ovr += 1;
        }
        bs[l].rans += overRuns;
        bs[l].wickets += out;
        if (score >= target)
            break;
        if (outs == 10)
            break;
        cout << "\n\n";
        cout << "at the end of " << over + 1 << "overs,\t";
        cout << "score is " << score << "/" << outs;
        cout << "\n in this over, " << overRuns << "/" << out;
        getline(cin, ch);
        cout << "\n\nPress enter to continue:\n";
        getline(cin, rest);
        l++;
        system("cls");
        swap(i, j);
    }
    int score2 = score;
    int out2 = outs;
    if (ball < 6)
        cout << "\nIN " << over - 1 << "." << ball << " they scored " << score << "/" << outs;
    else if (ball == 6)
        cout << "\nIN " << over << " overs, they scored " << score << "/" << outs;
    cout << "\n\nAfter second inning," << second << "'s score is " << score << "/" << outs;

    Sleep(200);
    system("cls");
    cout << "second innings scorecard\n\n";
    cout << "Second innings batting scorecard\n\n";
    cout << endl << "Batsman Name\t\truns(balls)\t\tfours\t\tsixs\n";
    for (i = 0; i < 11; i++) {
        if (bsecond[i].name == "")
            break;
        cout << endl << bsecond[i].name << "\t\t" << bsecond[i].ran << "(" << bsecond[i].bowl << ")\t\t\t" << bsecond[i].four << "\t\t\t" << bsecond[i].six << endl;

    }

    cout << "\n\nsecond innings bowlings corecard\n\n";
    cout << endl << "Bowler Name\t\tovers\t\truns\t\twickets\n";
    for (i = 0; i < 9; i++) {
        if (bs[i].name == "")
            break;
        cout << endl << bs[i].name << "\t\t" << bs[i].ovr << "\t\t\t" << bs[i].rans << "\t\t\t" << bs[i].wickets << endl;

    }
    getline(cin, ch);
    cout << "\n\nMatch has ended!, Press enter to go to the result:\n";
    getline(cin, rest);
    final_centre(target - 1, score2, out2, first, second);
}



void final_centre(int score1, int score2, int out2, string first, string second) {

    system("cls");
    cout << "\n\n\t\tFINALLY, WE HAVE THE WINNER!\n\n";
    if (score2 > score1)
        cout << "\n\n\t\t" << second << "\t WINS BY " << 10 - out2 << " WICKETS!!!\n\n";
    else if (score2 == score1)
        cout << "The match is tied.";
    else
        cout << "\n\n\t\t" << first << "\t WINS BY " << score1 - score2 << " RUNS!!!\n\n";
    cout << "\n\nPress enter to continue:\n";
    getline(cin, rest);
    system("cls");

    fstream(nam);
    nam.open("Record.txt", ios::app);
    if (nam.is_open())
    {
        nam << "Match no: " << match_number << "\t" << first << " vs " << second << "\n Results:\n";
        if (score2 > score1)
            nam << second << "\t WINS BY " << 10 - out2 << " WICKETS!!!\n\n";
        else if (score2 == score1)
            nam << "The match is tied.";
        else
            nam << first << "\t WINS BY " << score1 - score2 << " RUNS!!!\n\n";
    }
}


int main()
{
    Home();
    return 0;
}

