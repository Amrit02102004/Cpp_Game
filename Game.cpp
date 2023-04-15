#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

void display_leaderboard(){
    ifstream foi;
    foi.open("leaderboard.txt");
    string line;
    while (getline(foi,line))
    {
        cout<<line<<endl;
    }
    foi.close();
}
void update_leaderboard(string n , int s){
    fstream foi;
    foi.open("leaderboard.txt",ios::app);
    foi<<"\t\t"<<n<<"\t"<<s<<"\n";
    foi.close();
}

int main(){
    int score = 100;
    srand(time(0));
    int random = rand() % 101 ; // This generates from 0 to 101-1 100
    // cout<<"The random Number : "<<random<<endl;
    int input;

    string name;
    cout<<"Enter your Name : ";
    getline(cin,name);

    do
    {
        
        cout<<"\nEnter your guess : ";
        cin>>input;
        if (input == random)
        {
            cout<<"You Got the random Number !";
            cout<<"\nYour Score is "<<score;
        }
        else
        {
            if (input>random)
            {
                cout<<"Your guess is Higher !";
            }
            else
            {
                cout<<"Your Guess is Lower !";
            }
            score--;
            
        }
        
        
    } while (input!=random);
    
    update_leaderboard(name,score);
    display_leaderboard();


    return 0;
}