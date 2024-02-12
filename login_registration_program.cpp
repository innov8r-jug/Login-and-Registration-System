#include<bits/stdc++.h>
using namespace std;


//                                                   //The reason for both declaring the functions at the beginning and defining them later is
//                                                   to allow for the separation of interface (declaration) from implementation.
//                                                   This practice is a part of modular programming and helps in making the code more readable,
//                                                   maintainable, and easier to understand. Helps in modular programming.

//function declaration  
void login();
void registration();
void forgot_password();
void change_password();
void user_menu();
void user_view_profile();
void user_edit_profile();
void user_logout();
void main_menu();


void admin_menu();
void admin_view_users();
void admin_delete_users();
void admin_add_users();
void admin_edit_users();
void admin_logout();


//Global variables
string username, password, password2, email, phone, address, city, state, country, pincode, admin_username, admin_password;

//create an array of structure to store user data
struct user
{
    string username;
    string password;
    string email;
    string phone;
    string address;
    string city;
    string state;
    string country;
    string pincode;
} user[100];


//function for drawing a line
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
    {
        cout<<symbol;
    }
    cout<<endl;
}

int i=0;
//function for registration
void registration()
{
    system("cls");  //it will clear the terminal when program hits
    drawLine(80,'-');
    cout<<"\t\tRegistration"<<endl;
    drawLine(80,'-');

    cout<<"Enter Username: ";
    cin>>username;
    user[i].username = username;
    cin.ignore();
    cout<<endl;

    cout<<"Enter Password: ";
    cin>>password;
    user[i].password = password;
    cin.ignore();
    cout<<endl;

    cout<<"Enter Email: ";
    cin>>email;
    user[i].email = email;
    cin.ignore();
    cout<<endl;
    
    cout<<"Enter Phone: ";
    cin>>phone;
    user[i].phone = phone;
    cin.ignore();
    cout<<endl;

    cout<<"Enter Address: ";
    cin>>address;
    user[i].address = address;
    cin.ignore();
    cout<<endl;

    cout<<"Enter City: ";
    cin>>city;
    user[i].city = city;
    cin.ignore();
    cout<<endl;

    cout<<"Enter Country: ";
    cin>>country;
    user[i].country = country;
    cin.ignore();
    cout<<endl;

    cout<<"Enter Pincode: ";
    cin>>pincode;
    cin.ignore();  //                                    have to add cin.ignore() because newline character left 
    //                                                   in the input buffer after you input the firled is the one causing the issue of getchar()
    user[i].pincode = pincode;
    cout<<endl;

    cout<<endl;
    drawLine(80,'-');
    cout<<"Registration Successfully Done!"<<endl;
    cout<<endl;
    i++;
    cout<<"Press any key to continue......"<<endl;
    getchar();
}

//function for login
void login()
{
    system("cls");
    drawLine(80,'-');
    cout<<"\t\tLogin"<<endl;;
    drawLine(80, '-');

    cout<<"Enter Username: "<<endl;
    cin>>username;
    cout<<"Enter Password: "<<endl;
    cin>>password;
    cin.ignore();
    cout<<endl;

    if(username == "admin" && password == "admin")
    {
        cout<<"Login Successfull!"<<endl;
        cout<<endl;
        cout<<"Welcome Admin!"<<endl;
        admin_menu();
    }

    bool b1=0;
    for(int j=0; j<i; j++)   
    //                        <i isiliye kara kyunki i++ baad mein kar rahe hai registration ke time toh ek i jyada hi rhega hai
    //                        like agar i++ karne pe i 4 ho gaya, toh i=3 tak bhar chuka hai input toh usi mein search karenge ye login id and password
    {
        if(username == user[j].username && password == user[j].password)
        {
            b1=1;
            cout<<"Login Successful!"<<endl;
            cout<<endl;
            cout<<"Welcome"<<" "<<username<<"!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue...";
            getchar();
            user_menu();
        }
    }

    if(b1==0)
    cout<<"Login Failed!"<<endl;
    cout<<endl;
    cout<<"Press any key to continue"<<endl;
    getchar();
    main_menu();   
}

//function for forgot password
void forgot_password()
{
    system("cls");
    drawLine(80, '-');  
    cout<<"\t\t Forgot Password "<<endl;
    drawLine(80,'-');

    cout<<"Enter Username: "<<endl; //abc
    cin>>username;
    cout<<"Enter Email: "<<endl; //abc@gmail
    cin>>email;
    cin.ignore();
    bool b2=0;
    for(int j=0; j<i; j++)
    {
        if(username == user[j].username && email == user[j].email)
        {   
            b2=1;
            cout<<"Enter New Password: ";
            cin>>password;
            cout<<"Confirm Password: ";
            cin>>password2; 
            cin.ignore();           

            if(password == password2)
            {
                user[j].password = password;
                cout<<"Password changed Successfully"<<endl;
                cout<<endl;
                cout<<"Press any key to continue...";
                getchar();
                login();
            }
            else
            {
                cout<<"Password does not match!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue...";
                getchar();
                forgot_password();
            }    
        }
    }
    if(b2==0)
    {
        cout<<"Entered Username or Email is not correct!";
        cout<<endl;
        cout<<"Press any key to continue..."<<endl;
        getchar();
        forgot_password();
    }
}

void change_password()
{
    system("cls");  //it will clear the terminal when program hits
    drawLine(80,'-');
    cout<<"\t\tChange Password"<<endl;
    drawLine(80,'-');

    cout<<"Enter Username: ";
    cin>>username;
    cout<<"Enter Password: ";
    cin>>password;
    cin.ignore();
    bool b3=0;
    for(int j=0; j<i; j++)
    {
        b3=1;
        if(username==user[j].username && password==user[j].password)
        {
            cout<<"Enter New Password: ";
            cin>>password;
            cout<<"Confirm Password: ";
            cin>>password2;
            cin.ignore();

            if(password==password2)
            {
                user[j].password = password;
                cout<<"Password Changed Successfully!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue...";
                getchar();
                login();
            }
            else
            {
                cout<<"Password does not match!"<<endl;
                cout<<endl;
                getchar();
                change_password();
            }
        }
    }
    if(b3==0)
    {
        cout<<"Entered Username or Password is not correct!";
        cout<<endl;
        cout<<"Press any key to continue..."<<endl;
        getchar();
        change_password();        
    }

}

//function for user menu
void user_menu()
{
    int choice;
    system("cls");
    drawLine(80,'-');
    cout<<"\t\tUser Menu"<<endl;
    drawLine(80,'-');

    cout<<"1. View Profile"<<endl;
    cout<<"2. Edit Profile"<<endl;
    cout<<"3. Logout"<<endl;
    cout<<"4. Exit"<<endl;

    cout<<endl;
    cout<<"Enter Your Choice: "<<endl;
    cin>>choice;
    cin.ignore();

    switch ( choice)
    {
        case 1: 
        user_view_profile();
        break;

        case 2:
        user_edit_profile();
        break;

        case 3:
        main_menu();
        break; 

        case 4:
        exit(0);
        break;

        default:
        cout<<"Invalid Choice!"<<endl;
        cout<<endl;
        cout<<"Press any key to continue...";
        getchar();
    }
}

//function for main menu
void main_menu()
{
int choice;
    //now I'll create an infinite loop
    while(1)
    {
        system("cls");
        drawLine(80, '-');
        cout<<"\t\tWelcome to Login System "<<endl;
        drawLine(80, '-');
        cout<<"1. Login"<<endl;
        cout<<"2. Registration"<<endl;
        cout<<"3. Forgot Password"<<endl;
        cout<<"4. Change Password"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;

        //now I'll write here a switch case, depends upon what user is selecting basically
        switch(choice)
        {
            case 1:
            login();
            break;

            case 2:
            registration();
            break;

            case 3:
            forgot_password();
            break;

            case 4:
            change_password();
            break;

            case 5:
            exit(0);
            break;

            default:
            cout<<"Invalid Choice!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue...";
            getchar();

        }    
    }    
}

//function to view user profile
void user_view_profile()
{
    system("cls");  
    drawLine(80,'-');
    cout<<"\t\tView Profile"<<endl;
    drawLine(80,'-');
    cout<<endl;

    cout<<"Please enter the username once again: "<<endl;
    cin>>username;
    cout<<"Please enter the password again: "<<endl;
    cin>>password;
    cin.ignore();
    int index=0;
    bool b7=0;
    for(int j=0; j<i; j++)
    {
        if(username == user[j].username && password == user[j].password)
        {
            b7=1;
            index = j;
            break;
        } 
    }
    if(b7==1)
    {
        cout<<"User found!"<<endl;
        cout<<endl;
        cout<<"Showing Profile: "<<endl;
        cout<<endl;
        drawLine(80, '-');
        cout<<endl;

        cout<<"Username: "<<user[index].username<<endl;
        cout<<"Password: "<<user[index].password<<endl;
        cout<<"Email: "<<user[index].email<<endl;
        cout<<"Phone: "<<user[index].phone<<endl;

        cout<<"Address: "<<user[index].address<<endl;
        cout<<"City: "<<user[index].city<<endl;
        cout<<"State: "<<user[index].state<<endl;
        cout<<"Country: "<<user[index].country<<endl;
        cout<<"Pincode: "<<user[index].pincode<<endl;
        cout<<endl;

        cout<<"Press any key to continue: "<<endl;
        getchar();
        user_menu();
    }

    else
    {
        cout<<"Wrong username and password entered!"<<endl;
        cout<<endl;
        cout<<"Press any key to continue..."<<endl;
        getchar();
        user_menu();
    }
}

//function for user to edit profile
void user_edit_profile()
{
    system("cls");  
    drawLine(80,'-');
    cout<<"\t\tEdit Profile"<<endl;
    drawLine(80,'-');
    cout<<endl;

    cout<<"Enter Email:";
    cin>>email;
    cout<<"Enter Phone: ";
    cin>>phone;
    cout<<"Enter Address: ";
    cin>>address;
    cout<<"Enter City: ";
    cin>>city;
    cout<<"Enter State: ";
    cin>>state;
    cout<<"Enter Country: ";
    cin>>country;
    cout<<"Enter Pincode: ";
    cin>>pincode;
    cin.ignore();

    cout<<endl;
    cout<<"Enter Username and Password to confirm: "<<endl;
    cout<<"Username: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;
    cin.ignore();
    cout<<endl;
    bool b4=0;
    for (int j=0; j<i; j++)
    {
        
        if(username == user[j].username && password == user[j].password)
        {
            b4=1;
            user[j].email = email;
            user[j].phone = phone;
            user[j].address = address;
            user[j].city = city;
            user[j].state = state;
            user[j].country = country;
            user[j].pincode = pincode;
            cout<<endl;
            cout<<"Profile Updated Successfully!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue...";
            getchar();
            user_menu();
        }
    }
    if(b4==0)
    {
        cout<<"Entered Username or Password is incorrect!"<<endl;
        cout<<endl;
        cout<<"Press any key to continue...";
        getchar();
        user_menu();
    }
}

//function for user to logout
void user_logout()
{
    system("cls");  
    drawLine(80,'-');
    cout<<"\t\tLogout"<<endl;
    drawLine(80,'-');
    cout<<endl; 

    char logout;
    cout<<"Are you sure you want to logout? (y/n): "<<endl;
    cin>>logout;

    if(logout == 'y' || logout == 'Y')
    {
        main_menu();
    }
    else
    {
        user_menu();
    }
}

//function for admin menu
void admin_menu()
{
    int choice;
    system("cls");  
    drawLine(80,'-');
    cout<<"\t\tAdmin Menu"<<endl;
    drawLine(80,'-');
    cout<<endl;

    while(1)
    {
        cout<<" 1.  View All Users "<<endl;
        cout<<" 2.  Delete User "<<endl;
        cout<<" 3.  Add User "<<endl;
        cout<<" 4.  Edit User "<<endl;
        cout<<" 5.  Logout "<<endl;
    }
    
    switch (choice)
    {
        case 1:
        admin_view_users();
        break;

        case 2:
        admin_delete_users();
        break;

        case 3:
        admin_add_users();
        break;

        case 4:
        admin_edit_users();
        break;

        case 5:
        admin_logout();
        break;

        default:
        cout<<"Invalid Choice!"<<endl;
        cout<<endl;
        cout<<"Press any key to continue..."<<endl;
        getchar();

    }
}

//function for admin to view users
void admin_view_users()
{
    system("cls");
    drawLine(80, '-');
    cout<<"\t\t All users available in the database: "<<endl;
    drawLine(80, '-');

    for(int j=0; j<i; j++)
    {
        cout<<user[j].username<<setw(20)<<user[j].password<<setw(20)<<user[j].email<<setw(20)<<user[j].phone<<setw(20)<<user[j].address<<setw(20)<<user[j].pincode<<setw(20)<<user[j].country<<setw(20)<<user[j].state<<setw(20)<<user[j].city<<endl;
    }
    
    cout<<endl;
    cout<<"Press any key to continue..."<<endl;
    getchar();
    admin_menu();
}

//function for admin to delete user
void admin_delete_users()
{   
    system("cls");
    drawLine(80, '-');
    cout<<"\t\tDelete Users "<<endl;
    drawLine(80, '-');
    cout<<endl;

    cout<<"enter the username of the user you want to delete: "<<endl;
    cin>>username;
    cin.ignore();
    cout<<endl;
    bool b5=0;
    for(int j=0; j<i; j++)
    {
        if(username == user[j].username)
        {
            b5=1;
            for(int k=j; k<i; k++)
            {
                user[k] = user[k+1];
            }
            i--;
            cout<<"User Deleted Successfully!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue...";
            getchar();
            admin_menu();
        }
    }
    if(b5==0)
    {
        cout<<"User not found!"<<endl;
        cout<<endl;
        cout<<"Press any key to continue...";
        getchar();
        admin_delete_users();
    }
}

//function for admin logout
void admin_logout()
{
    system("cls");
    drawLine(80, '-');
    cout<<"\t\tLogout "<<endl;
    drawLine(80, '-');
    cout<<endl;

    char logout;
    cout<<"Are you sure you want to logout? (y/n): ";
    cin>>logout;
    cin.ignore();
    cout<<endl;

    if(logout=='Y' or logout=='y')
    {
        main_menu();
    }
    else
    {
        admin_menu();
    }

}

//function for adding new user by admin
void admin_add_users()
{
    system("cls");
    drawLine(80, '-');
    cout<<"\t\tAdd User "<<endl;
    drawLine(80, '-');
    cout<<endl;

    cout<<"Enter the username : "<<endl;
    cin>>username;
    cout<<endl;

    cout<<"Enter the password: "<<endl;
    cin>>password;
    cout<<endl;

    cout<<"Enter the email: "<<endl;
    cin>>email;
    cout<<endl;

    cout<<"Enter the phone: "<<endl;
    cin>>phone;
    cout<<endl;

    cout<<"Enter the address: "<<endl;
    cin>>address;
    cout<<endl;

    cout<<"Enter the city: "<<endl;
    cin>>city;
    cout<<endl;

    cout<<"Enter the state: "<<endl;
    cin>>state;
    cout<<endl;

    cout<<"Enter the country: "<<endl;
    cin>>country;
    cout<<endl;

    cout<<"Enter the pincode: "<<endl;
    cin>>pincode;
    cin.ignore();
    cout<<endl;
    

    i++;
    user[i].username = username;
    user[i].password = password;
    user[i].email = email;
    user[i].phone = phone;
    user[i].address = address;
    user[i].city = city;
    user[i].state = state;
    user[i].country = country;
    user[i].pincode = pincode;
    cout<<"User Added Successfully!"<<endl;
    cout<<endl;
    cout<<"Press any key to continue..."<<endl;
    getchar();
    admin_menu(); 
}


//function for adding user by admin
void admin_edit_users()
{
    system("cls");
    drawLine(80, '-');
    cout<<"\t\tEdit User "<<endl;
    drawLine(80, '-');
    cout<<endl;

    cout<<"Enter the username of the user you want to edit: ";
    cin>>username;
    cin.ignore();
    cout<<endl;
    bool b6=0;
    for(int j=0; j<i; j++)
    {
        if(username == user[j].username)
        {
            b6=1;
            cout<<"Enter the new email: ";
            cin>>email;
            cout<<"Enter the new phone: ";
            cin>>phone;
            cout<<"Enter the new address: ";
            cin>>address;
            cout<<"Enter the new city: ";
            cin>>city;
            cout<<"Enter the new state: ";
            cin>>state;
            cout<<"Enter the new country: ";
            cin>>country;
            cout<<"Enter the new pincode: ";
            cin>>pincode;
            cin.ignore();
            
            cout<<endl;
            user[j].email = email;
            user[j].phone = phone;
            user[j].address = address;
            user[j].city = city;
            user[j].state = state;
            user[j].country = country;
            user[j].pincode = pincode;
            cout<<endl;
            cout<<"User Edited Successfully!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue...";
            getchar();
            admin_menu();
        }
    }
    if(b6==0)
    {
        cout<<"User not found!"<<endl;
        cout<<endl;

        cout<<"Press any key to continue..."<<endl;
        getchar();
        cout<<endl;
        char add;
        cout<<"Do you want to add a new user? (y/n): ";
        cin>>add;
        cin.ignore();
        if(add == 'Y'|| add=='y')
        {

            admin_add_users();
        } 
        else
        {
            admin_menu();
        }
    }
}
int main()
{  
    main_menu();
    return 0;
}