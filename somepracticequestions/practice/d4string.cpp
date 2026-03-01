#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void stringDemo(){

    // -------- INPUT METHODS --------
    string word;
    string sentence;

    cout<<"Enter a single word: ";
    cin>>word;

    cin.ignore();  // clear newline

    cout<<"Enter a full sentence: ";
    getline(cin, sentence);

    cout<<"\n----- Basic String Info -----\n";

    // length() / size()
    cout<<"Length using length(): "<<sentence.length()<<endl;
    cout<<"Length using size(): "<<sentence.size()<<endl;

    // accessing characters
    cout<<"First character using []: "<<sentence[0]<<endl;
    cout<<"Second character using at(): "<<sentence.at(1)<<endl;

    // find()
    int pos = sentence.find("a");
    if(pos != -1)
        cout<<"First occurrence of 'a' at index: "<<pos<<endl;
    else
        cout<<"Character 'a' not found\n";

    // substr()
    if(sentence.length() >= 5){
        string part1 = sentence.substr(0,5);
        string part2 = sentence.substr(4,9);
        cout<<"Substring (first 5 chars): "<<part1<<" &(4 to 9 char): "<<part2<<endl;
    }

    // append()
    string s1 = "Hello ";
    string s2 = "World";

    s1.append(s2);
    cout<<"After append(): "<<s1<<endl;

    // + operator
    string combine = word + "_TCS";
    cout<<"Using + operator: "<<combine<<endl;

    // empty()
    string temp="";
    if(temp.empty())
        cout<<"temp string is empty\n";

    // clear()
    temp="temporary data";
    temp.clear();
    cout<<"After clear(), length: "<<temp.length()<<endl;

    cout<<"\n----- C Style String Functions -----\n";

    char c1[50]="Hello ";
    char c2[]="World";
    char c3[50];

    // strlen()
    cout<<"Length of c2 using strlen(): "<<strlen(c2)<<endl;

    // strcpy()
    strcpy(c3,c2);
    cout<<"After strcpy(), c3: "<<c3<<endl;

    // strcmp()
    int cmp = strcmp(c2,c3);
    if(cmp==0)
        cout<<"Strings c2 and c3 are equal\n";
    else
        cout<<"Strings are different\n";

    // strcat()
    strcat(c1,c2);
    cout<<"After strcat(): "<<c1<<endl;

}

bool ispalindrom(string s){
    if (s.length() == 0 || s.length() == 1) return true;
    int start =0;
    int end = s.length()-1;

    while(start<end){
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void reverse(string &s){
    int start =0;
    int end = s.length()-1;

    while(start<end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int lengthcheck(string s){
    // manual length check
    int length=0;
   for(int i=0; s[i] != '\0' ; i++){
     length++;
   }
   cout<<"1-> length of: "<< s <<" is: "<<length<<endl;

    //  by predefined method

   cout<<"2->length of: "<< s <<" is: "<<s.length()<<endl;

}

void somemethods(string s){
    cout<<"------inside somemethod function----"<<endl;
    cout<<"lenth is :"<<s.length()<<endl;
    cout<<"size is :"<<s.size()<<endl;
}

void caseToggle(){
    string s;
    // cin.ignore();
    cout<<"enter a line to toggle case: ";
    getline(cin, s);

    for(int i=0; i<s.length(); i++){
        if(isupper(s[i]))
            s[i] = tolower(s[i]);
        else if(islower(s[i]))
            s[i] = toupper(s[i]);
    }
    cout<<"Toggled case: "<<s<<endl;
}

void specificCharacterFrequency(){
    string s;
    char target;
    cout<<"enter a line: ";
    getline(cin, s);
    cout<<"enter a charater for frequency count:";
    cin>>target;
    int frequency = 0;

    for(int i=0 ; i<=s.length();i++){
        if (s[i] == target) frequency++ ;
    }

    cout<<"frequency of :"<< target <<" is "<<frequency<<endl;
}

void countConsonentVowel(){
    string s;
    cout<<"enter a line: ";
    if (!(getline(cin, s))) return ;
    int vowelcount=0, consonentcount=0;

    for(int i=0; i<s.length(); i++){
        if(s[i]== 'a' || s[i]== 'e' || s[i]== 'i' || s[i]== 'o' || s[i]== 'u' || s[i]== 'A' || s[i]== 'E' || s[i]== 'I' || s[i]== 'O' || s[i]== 'U')
            vowelcount++;
        else if(isalpha(s[i]))
            consonentcount++;
    }
    cout<<"Vowel count: "<<vowelcount<<endl;
    cout<<"Consonant count: "<<consonentcount<<endl;
}

void wholeSentenceFrequency(){
    string s;
    cout<<"enter a line: ";
    if (!(getline(cin, s))) return ;

    int freq[256] = {0};
    for(int i=0; i<s.length(); i++){
        if(s[i] != ' ')
            freq[s[i]]++;
    }
    cout<<"Character frequencies:\n";
    int maxfreq = 0, secondmaxfreq = 0;
    char mostfreqchar='\0', secondmostfreqchar='\0';
    for(int i=0; i<256; i++){
        if(freq[i] > 0)
            cout<<char(i)<<": "<<freq[i]<<endl;
        if (freq[i] > maxfreq){
            secondmaxfreq = maxfreq;
            secondmostfreqchar = mostfreqchar;
            maxfreq = freq[i];
            mostfreqchar = char(i);
        } else if (freq[i] > secondmaxfreq && freq[i] != maxfreq){
            secondmaxfreq = freq[i];
            secondmostfreqchar = char(i);
        }   
    }

    cout<<"Most frequent character: "<<mostfreqchar<<" (Count: "<<maxfreq<<")"<<endl;
    cout<<"Second most frequent character: "<<secondmostfreqchar<<" (Count: "<<secondmaxfreq<<")"<<endl;

}

int main(){

    // stringDemo();

    // caseToggle();
    // specificCharacterFrequency();
    // countConsonentVowel();
    wholeSentenceFrequency();


    // string s;
    // cout<<"enter a string:";
    // cin>>s;

    // cout<<"-> the string is: "<<s<<endl;

    // //  length check
    // lengthcheck(s);
    // somemethods(s);

    // if(ispalindrom(s)==true)
    //     cout<<s<<" is a palindrome string"<<endl;
    // else
    //     cout<<s<<" is not a palindrome string"<<endl;
        
    // reverse(s);
    // // function is type void so direct string passed , and no variable is used to store it
    // cout<<"-> the reverse of string is: "<<s<<endl;    

    return 0;
}
