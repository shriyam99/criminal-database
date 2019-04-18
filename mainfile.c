//this is the main project file:
#include<stdio.h>
#include<string.h>

struct date{                //date structure
int d, m, y;
};

struct police{              //police structure
char police_code[10];
char incharge[100];
char area[100];
int staff;
int no_of_criminals;
struct police* next;
struct criminal* cr;
};

struct criminal{            //criminal structure
char name[100];
int crime_code;
int criminalno;
char caseincharge[100];
int tenure;
struct date admit;
struct date release;
struct criminal* next;
};

struct police* p = NULL;        //police station head declared globally

struct criminal* newcriminal(char pcode[], char n[], int crimecode,  int criminaln, char incharge[], int t, int d1, int d2, int m1, int m2, int y1, int y2){
if(p==NULL){
    printf("The police station does not exist!!");
    return NULL;
}
else{
    struct police* temp=p;
    while(temp!=NULL && strcmp(temp->police_code, pcode)!=0)
        temp = temp->next;
    if(temp==NULL){
    printf("The police station does not exist!!");
    return NULL;
    }
    else{
        temp->no_of_criminals++;
        struct criminal* c =(struct criminal*)malloc(sizeof(struct criminal));
        strcpy(c->name, n);
        c->crime_code = crimecode;
        c->criminalno = criminaln;
        strcpy(c->caseincharge, incharge);
        c->tenure = t;
        c->admit.d = d1; c->admit.m = m1; c->admit.y = y1; c->release.d = d2; c->release.m = m2; c->release.y = y2;
        c->next = NULL;
        struct criminal* temp1 = temp->cr;
        if(temp1==NULL){
            temp->cr = c;
            return p;
        }
        else{
        while(temp1->next!=NULL)
            temp1 = temp1->next;
        temp1->next = c;
        return p;
        }
    }
}
}
int number_of_criminals(struct criminal* ptr){      //counts the number of criminals in a police station
if(ptr==NULL)
    return 0;
int i=0;
while(ptr!=NULL){
    i++;
    ptr = ptr->next;
}
return i;
}

void newpolicestation(char pcode[], char inchrg[], char a[], int s){
struct police* p1 = (struct police*)malloc(sizeof(struct police));
strcpy(p1->police_code, pcode);
strcpy(p1->incharge, inchrg);
strcpy(p1->area, a);
p1->staff=s;
p1->no_of_criminals = 0;
p1->next = NULL;
p1->cr = NULL;
if(p==NULL){
    p=p1;
    return;
}
else{
    struct police* temp =p;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = p1;
    return;
}
}
int main(){

newpolicestation("DEH", "Rajesh Khanna", "delhi", 12, 40);      //adding new police stations
newpolicestation("KAN", "Suresh Rajpoot", "kanpur", 8, 32);
newcriminal("DEH", "bagdadi", 420, 2993, "skjgbkbg", 2, 32, 432, 43, 24, 42, 26);   //adding new criminals
newcriminal("DEH", "sudhant", 420, 2389, "ejkgne", 2, 32, 432, 43, 24, 42, 26);
newcriminal("DEH", "genign", 420, 7777, "iw3oiwn", 2, 32, 432, 43, 24, 42, 26);
struct criminal* c = p->cr;
while(c!=NULL){                         //printing the criminals in first police station
    printf("%s %d %d %s %d %d %d %d %d %d %d\n\n", c->name, c->crime_code, c->criminalno, c->caseincharge, c->tenure, c->admit.d, c->admit.m, c->admit.y, c->release.d, c->release.m, c->release.y);
    c = c->next;
}
return 0;
}
