// System security

#include <iostream>
#include <fstream> // file read write append
#include <sstream> // this header file provide templets and types that interpoletion between string buffers and stream buffers
#include <string>

using namespace std;

int main()
{
    int a;
    int i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1, mob;
    string creds[2], cp[2];

    cout << "           System Security     " << endl;
    cout << " _________________________________" << endl;
    cout << "|            1. Register          |" << endl;
    cout << "|            2. Login             |" << endl;
    cout << "|            3. Change Password   |" << endl;
    cout << "|____________4. End Program_______|" << endl;

    do
    {
        cout<<endl<< endl;
        cout<<"Enter Your Choice:-";
        cin>>a;
        switch(a)
        {
            case 1:
            {
                cout<<"____________________________"<<endl;
                cout<<"-------------Register-------"<<endl;
                cout<<"____________________________"<<endl<< endl;
                cout<<"Enter Username:- ";
                cin>>name;
                cout<<"Enter Password:- ";
                cin>>password0;
                cout<<"Enter age:- ";
                cin>>age;
                cout<<"Enter Mobile Number:";
                cin >>mob;

                ofstream of1;
                of1.open("file.txt");
                if (of1.is_open())
                {
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Registration is successful"<<endl;
                }
                break;
            }
            case 2:
            {
                i = 0;
                cout << "_____________________________" << endl<< endl;
                cout << "-----------Login-------------" << endl;
                cout << "_____________________________" << endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"Enter username:-";
                cin>>user;
                cout<<"Enter Password:-";
                cin>>pass;

                if (of2.is_open())
                {
                    while (!of2.eof())
                    {
                        while (getline(of2, text))
                        {
                            istringstream iss(text);
                            iss>>word;
                            creds[i] = word;
                            i++;
                        }
                        if (user == creds[0] && pass == creds[1])
                        {
                            cout<<"-----Login successful-------"<<endl<<endl;

                            cout<<"Details:"<<endl;

                            cout<<"Username: " + name<<endl;
                            cout<<"Password: " + pass<<endl;
                            cout<<"Age: " + age<<endl;
                            cout<<"Mobile Number: " + mob<<endl;
                        }
                        else
                        {
                            cout<<"Incorrect Credentials:" << endl;
                            cout<<"|      1. Press 2 to Login.               |"<<endl;
                            cout<<"|      2. Press 3 to change the password. |"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                i = 0;
                cout<<"----------------Change Password----------------"<<endl;
                ifstream of3;
                of3.open("file.txt");
                cout<<"Enter the old Password:-";
                cin>>old;
                if(of3.is_open())
                {
                    while(!of3.eof())
                    {
                        while(getline(of3, text))
                        {
                            istringstream iss(text);
                            iss>>word1;
                            cp[i] = word1;
                            i++;
                        }
                        if(old == cp[1])
                        {
                            of3.close();

                            ofstream of4;
                            if(of4.is_open())
                            {
                                cout<<"Enter New Password:-";
                                cin>>password1;
                                cout<<"Enter Password Again:-";
                                cin>>password2;

                                if(password1 == password2)
                                {
                                    of4<<cp[0]<<"\n";
                                    of4<<password1;
                                    cout<<"Password change Successful"<<endl;
                                }
                                else
                                {
                                    of4<<cp[0]<<"\n";
                                    of4<<old;
                                    cout<<"Password do not match"<<endl;
                                }
                            }
                        }
                        else
                        {
                            cout<<"Enter Valid Password"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                cout<<"_______________________THANK YOU____________________";
                break;
            }
            default:
            {
                cout<<"Enter a valid choice";
                break;
            }
        }
    }while (a != 4);

    return 0;
}
