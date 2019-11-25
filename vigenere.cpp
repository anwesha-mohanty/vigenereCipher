#include<iostream>
#include<string.h>
using namespace std;

void encrypt(char msg[],char key[])
{
    int len_m=strlen(msg);
    int len_k=strlen(key);
    char temp[len_m],cipher[len_m];
    int i,r,exp;
    r=-1;
    for(i=0;i<len_m;i++)
    {
        if(r==len_k-1) //to keep looping over the key in a circular way
           r=0;
        else
           r++;
        temp[i]=key[r];

    }
    temp[i]='\0';
    for(i=0;i<len_m;i++)
    {
        exp=((msg[i]-65+temp[i]-65)%26);
        //cout<<"Exp="<<exp<<endl;
        cipher[i]=char(exp+65);
    }
    cipher[i]='\0';
    cout<<"Cipher text = "<<cipher<<endl;
}

void decrypt(char encr[],char key[])
{
    int len_e=strlen(encr);
    int len_k=strlen(key);
    char decr[len_e],temp[len_e];
    int i,r,exp;
    r=-1;
    for(i=0;i<len_e;i++)
    {
        if(r==len_k-1)
           r=0;
        else
           r++;
        temp[i]=key[r];
    }
    temp[i]='\0';
    for(i=0;i<len_e;i++)
    {
        exp=((encr[i]-65)-(temp[i]-65))%26;
        exp=exp>=0?exp+65:exp+91; //if exp is -ve, it must be added to 91 to get an uppercase alphabet.
        decr[i]=char(exp);
    }
    decr[i]='\0';
    cout<<"Decryted message = "<<decr<<endl;

}

int main()
{
    char key[10000];
    char msg[1000];
    int ch;
    cout<<"1. Encrypt \n2.Decrypt\n";
    cin>>ch;
    switch(ch)
    {
        case 1:
              cout<<"Enter message ";
              cin>>msg;
              cout<<"Enter key ";
              cin>>key;
              encrypt(msg,key);
              break;
        case 2:
              cout<<"Enter ciphertext ";
              cin>>msg;
              cout<<"Enter key ";
              cin>>key;
              decrypt(msg,key);
              break;
        default:
                cout<<"invalid choice!";

    }

}
