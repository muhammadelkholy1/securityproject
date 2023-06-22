#include <bits/stdc++.h>
#include <iostream>
#include<string>
#include<vector>
#include<map>
char caesar(char);
char decryption(char);
using namespace std;

string caesar_encryption()
{
    string p, p_output = "";
    cin >> p;

    // encryption
    for (int x = 0; x < p.length(); x++)
    {
        p_output += caesar(p[x]);
    }
    return p_output;
}
string caesar_decryption()
{
    string c, c_output = "";
    cin >> c;
    // decryption
    for (int j = 0; j < c.length(); j++)
    {
        c_output += decryption(c[j]);
    }
    return c_output;
}
char caesar(char c)
{
    if (isalpha(c))
    {
        c = toupper(c); //use upper to keep from having to use two separate for A…Z a…z
        c = (((c - 65) + 4) % 26) + 65;
    }
    //if c isn't alpha, just send it back.
    return c;
}
char decryption (char p)
{
    if (isalpha(p))
    {
        p = toupper(p); //use upper to keep from having to use two separate for A…Z a…z
        p = (((p - 65) - 4) % 26) + 65;
    }
    //if p isn't alpha, just send it back.
return p;
}


string playfair(){

 int i,j,k,n;
    cout<<"Enter the message:";
    string s,origin;
    cin>>origin;
    cout<<"Enter the key:";
    string key;
    cin>>key;
    for(i=0;i<origin.size();i++){
        if(origin[i]!=' ')
            s+= origin[i];
    }
    vector<vector<char> > a(5,vector<char>(5,' '));
    n=5;
    map<char,int> mp;
    k=0;
    int pi,pj;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            while(mp[key[k]]>0&&k<key.size()){
                k++;
            }
            if(k<key.size()){
                a[i][j]=key[k];
                mp[key[k]]++;
                pi=i;
                pj=j;
            }
            if(k==key.size())
            break;
        }
        if(k==key.size())
            break;
    }
    k=0;
    for(;i<n;i++){
        for(;j<n;j++){
            while(mp[char(k+'a')]>0&&k<26){
                k++;
            }
            if(char(k+'a')=='j'){
                j--;
                k++;
                continue;
            }
            if(k<26){
                a[i][j]=char(k+'a');
                mp[char(k+'a')]++;
            }
        }
        j=0;
    }
    string ans;
    if(s.size()%2==1)
        s+="x";
    for(i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1])
            s[i+1]='x';
    }
    map<char,pair<int,int> > mp2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mp2[a[i][j]] = make_pair(i,j);
        }
    }

    for(i=0;i<s.size()-1;i+=2){
        int y1 = mp2[s[i]].first;
        int x1 = mp2[s[i]].second;
        int y2 = mp2[s[i+1]].first;
        int x2 = mp2[s[i+1]].second;
        if(y1==y2){
            ans+=a[y1][(x1+1)%5];
            ans+=a[y1][(x2+1)%5];
        }
        else if(x1==x2){
            ans+=a[(y1+1)%5][x1];
            ans+=a[(y2+1)%5][x2];
        }
        else {
            ans+=a[y1][x2];
            ans+=a[y2][x1];
        }
    }

    return ans;
}


string vigenereEncode ()
{    string plainText ,key;
cout<<"enter plaintext: ";
cin>>plainText;
cout<<"enter key: ";
cin>>key;
    string cipherText="";
    int now= 0;
    for (int i = 0 ; i < plainText.size() ; i++)
    {
        now= ((int)(plainText[i]) - 97) + ((int)(key[i%key.size()]) - 97);
        //if And false
        now = now>= 26 ? now-26 : now;
        now+=97;
        cipherText+= (char)(now);
    }
    return cipherText;
}

string vigenereDecode ()
{    string cipherText , key;
cout<<"enter cipherText: ";
cin>>cipherText;
cout<<"enter key: ";
cin>>key;
    string plainText="";

    int now = 0;
    for (int i = 0 ; i < cipherText.size() ; i++)
    {
        now = ((int)(cipherText[i]) - 97) - ((int)(key[i%key.size()]) - 97);
        now = now < 0 ? now+26 : now;
        now+=97;
        plainText+= (char)(now);
    }
    return plainText;
}




void Menu(){
    int choice;
    do{
        cout<<"1>== caesar cipher"<<endl;
        cout<<"2>== play fair cipher"<<endl;
        cout<<"3>== vigenere cipher"<<endl;
        cout<<"4>== Exit from program"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout << "1. Caesar Cipher Encryption\n";
                cout << "2. Caesar Cipher Decryption\n";
                int sub_choice;
                cin >> sub_choice;
                if (sub_choice == 1) {
                    cout << "Encrypted Text: " ;
                     string x="";
                    x=caesar_encryption();
                    cout<<x<<endl;
                    Menu();
                } else if (sub_choice == 2) {
                    cout << "Decrypted Text: " ;
                    string x="";
                    x=caesar_decryption();
                    cout<<x<<endl;
                    Menu();
                } else {
                    cout << "Invalid choice\n";
                }
                break;
            case 2:

                cout << "1. playfair Encryption\n";
                cout << "2. playfair Decryption\n";
                cin >> sub_choice;
                if (sub_choice == 1) {
                     string x="";
                    x= playfair();
                    cout<<x<<endl;
                    Menu();
                } else if (sub_choice == 2) {

                    string x="";
                    x= playfair();
                    cout<<x<<endl;
                    Menu();
                } else {
                    cout << "Invalid choice\n";
                }
                break;
            case 3:
                 cout << "1. vigenere Encryption\n";
                cout << "2. vigenere Decryption\n";
                cin >> sub_choice;
                if (sub_choice == 1) {
                     string x="";
                    x= vigenereEncode ();
                    cout<<x<<endl;
                    Menu();
                } else if (sub_choice == 2) {

                    string x="";
                    x= vigenereDecode ();
                    cout<<x<<endl;
                    Menu();
                } else {
                    cout << "Invalid choice\n";
                }
                break;
            case 4:
               break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice!=4);
}
int main()
{
 Menu();
}
