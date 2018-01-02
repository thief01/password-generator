/** @author @WRH @thief01 */

#include "main.hpp"

char char_set_l[26][2];
char char_set_n[10];
char char_set_chars[16];

class password
{
public:
    void setter()
    {
        cout << "CHAR SET LOADING: \n";
        cout << "LETTERS: 26 SMALL 26 BIG\n";
         for(int i=0; i<26; i++)
        {
            char_set_l[i][0] = 65+i;
            cout << char_set_l[i][0];
            char_set_l[i][1] = 97+i;
            cout << char_set_l[i][1];
        }
        cout << "\n\nNUMBERS: 10\n";
        for(int i=0; i<10; i++)
        {
            char_set_n[i] = 48+i;
            cout << char_set_n[i];
        }
        cout << "\n\nCHARS: 16\n";
        for(int i=0; i<16; i++)
        {
            char_set_chars[i] = 32+i;
            cout << char_set_chars[i];
        }
    }
public:
    int pass( bool ch1, bool ch2, bool ch3, bool ch4, unsigned short max_chars )
    {
        srand( time( NULL ) );
        int rand = 0;
        string passx = "";
        for(int i=0; i<max_chars; i++)
        {
            system("cls");
            rand = ( std::rand() % 4 ) + 1;
            if(rand == 1 && ch1 == 1)
            {
                rand = ( std::rand() % 26 ) + 0;
                passx = passx + char_set_l[rand][0];
            }
            else if(rand == 2 && ch2 == 1)
            {
                rand = ( std::rand() % 26 ) + 0;
                passx = passx + char_set_l[rand][1];
            }
            else if(rand == 3 && ch3 == 1)
            {
                rand = ( std::rand() % 10 ) + 0;
                passx = passx + char_set_n[rand];
            }
            else if(rand == 4 && ch4 == 1)
            {
                rand = ( std::rand() % 16 ) + 0;
                passx = passx + char_set_chars[rand];
            }
            else
            {
                i--;
            }
            cout << "Your passowrd: " << passx;
            cout << "\n";
        }
        fstream file;
        file.open("password.txt", std::ios::app);
        file << passx;
        file << "\n";
        cout << "\nPassowrd save to file. Check password.txt";
        file.close();
        return 0;
    }
};
class menu
{
public:
    int listt()
    {
        bool choice[4];
        unsigned short char_max;
        cout << "\nEnter 1 for yes, 0 for no, in next four options must be one value true";
        cout << "\nDo you want use big letters? ";
        cin >> choice[0];
        cout << "\nDo you want use small letters? ";
        cin >> choice[1];
        cout << "\nDo you want use numbers? ";
        cin >> choice[2];
        cout << "\nDo you want use chars? ";
        cin >> choice[3];
        cout << "\nHow much chars you want? (min 1) ";
        cin >> char_max;
        password password;
        password.pass(choice[0], choice[1], choice[2], choice[3], char_max );
        return 0;
    }
};

int main()
{
    password password;
    password.setter();
    menu menu;
    menu.listt();

    cout << "\nPress whatever key for end.";
    getch();
    return 0;
}
