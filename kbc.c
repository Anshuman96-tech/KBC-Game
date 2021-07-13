#include <stdio.h>
#include <stdlib.h>
struct user
{
    char name[50];
    int points;

}a,b;
int lifeline=1;
void header();
void welcomepage();
void mainmenu();
void showrules();
int getcount();
void qset1();
void qset2();
void showscore(int);
void correct();
void wrong();
void quit();
int sethighscore();
void showhighscore();
void aboutgame();
void timer();
int main()
{
    welcomepage();
    printf("\n\t\t\t\tPress any key to continue");
    getch();
    mainmenu();
    return 0;
}
void header()
{
    system("cls");
    printf("===================================================================================================");
    printf("\t\t\t\t\t\t\t  >>> KAUN BANEGA CROREPATI <<<\t\t\tUser Name - %s",a.name);
    printf("\n===================================================================================================");
}
void welcomepage()
{
    system("cls");
    printf("\n\n\n\n\n\n*****************************************");
    printf("*****************************************");
    printf("\n\n\t\t\t\t>>> WELCOME TO KAUN BANEGA CROREPATI <<<");
     printf("\n\n\t\t\t\t Coded By Anshuman Tiwari..   !!!! ");
    printf("\n\n*****************************************");
    printf("*****************************************");
    printf("\n\n\n\n\t\t\t\t     Enter your name to begin");
    printf("\n\t\t\t\t     ");
    gets(a.name);

    if (a.name[0]=='\0')
    {
        printf("\n\t\t\tPlease enter your name");
        getch();
        welcomepage();
    }

return;

}
void mainmenu()
{
    while (1)

    {
        int choice;

        header();
        printf("\n\n\t\t\t\t\t** MAIN MENU **");
        printf("\n\n\t\t\t\t\t1. Start Game");
        printf("\n\t\t\t\t\t2. High Score");
        printf("\n\t\t\t\t\t3. Rules");
        printf("\n\t\t\t\t\t4. About the Game");
        printf("\n\t\t\t\t\t5. Log out User");
        printf("\n\t\t\t\t\t6. Exit");


        printf("\n\n\t\t\t\t\tEnter your choice >>>");
        fflush(stdin);
        scanf("%d",&choice);

        switch(choice)
        {      case 1:
                   showrules();
                   printf("\n\n\t\t\t\t  BEST OF LUCK !");
                   printf("\n\n\t\t\t\t<<<Press any key to begin the game>>>");
                   getch();
                   lifeline=1;
                   a.points=0;
                   switch(getcount())
                        {
                            case 1:
                            qset1();
                            break;

                            case 2:
                            qset2();
                            break;
                        }
                  break;
                case 2:
                	showhighscore();
                    break;

               case 3:
                   showrules();
                   printf("\n\n\t\t\t\t<<<Press any key for main menu >>>");
                   getch();
                   break;
               case 4:
                aboutgame();
                break;
               case 5:
                   main();

               case 6:
                    exit(0);
               case 7:
                   exit(0);
					printf("\n\n\t\t\t\t Enter your choice >>>");
               default:
                    printf("\nEnter any valid choice");

        }

     }
}
void showrules()
{
    header();
    printf("\n\n\t\t\t\t\t** Game Rules **");
    printf("\n\n\t\t1. You have to answer 14 questions one by one");
    printf("\n\t\t2. Each question has a fixed prize money starting from Rs. 5,000 to 5 Crore");
    printf("\n\t\t3. Game is divided into three levels");
    printf("\n\t\t4. If you will give a wrong answer you will fall down to level's starting point");
    printf("\n\t\t5. You have 1 Life Line: 50-50 ");
    printf("\n\t\t6.You may quit the game anytime ");
}


int getcount()
{
    int count=0;
    FILE *fp;
    fp=fopen("counter.DAT","rb");
	if(fp==NULL)
	{
    fp=fopen("counter.DAT","wb");
	count=2;
	if(fp==NULL)
    {
		printf("\nErorr");
        getch();
        exit(0);
	}
	fwrite(&count,sizeof(int),1,fp);
	count=1;
	}

   else
   {
       fread(&count,sizeof(int),1,fp);
       fclose(fp);
       fp=fopen("counter.DAT","wb");
       if(fp==NULL)
        {
			printf("\nErorr");
            getch();
            exit(0);
		}
       count++;
       fwrite(&count,sizeof(int),1,fp);
       count--;
   }	
    while(count>2)
	{
		count=count-2;
	}

 	fclose(fp);
    return count;
}



void qset1()
{
	char q;
    q111:
        header();
        printf("\n Question no 1");
        printf("\t\t\t\t\t\t\t\t\t\tRS.5,000/-");
        printf("\n\n\t\t\tIn Ramayan Which of the following is a bird?");
        printf("\n\n\t\t\t\tA. Jatayu");
        printf("\n\t\t\t\tB. Bali");
        printf("\n\t\t\t\tC. Sugreev");
        printf("\n\t\t\t\tD. Jammvant");        
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}
        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
       scanf("%c",&q);
        
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      { q112:
          lifeline=0;
          header();
        printf("\n Question no 1    You are using life line");
        printf("\t\t\t\t\t\t\t\t\t\tRS.5,000/-");
        printf("\n\n\t\t\tIn Ramayan Which of the following is a bird?");
        printf("\n\n\t\t\t\tA. Jatayu");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Jammvant");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'D' :
        wrong();
        break;

        case 'F':
        	quit();
        	break;

       break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q112;
       }

        }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q111;

       }



        /*  QUESTION 2 */


        q121:
        header();
        printf("\n Question no 2");
        printf("\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\t‘Daga’ and ‘Teja’ was henchmen of Which Filmi Character?");
        printf("\n\n\t\t\t\tA. Shakal");
        printf("\n\t\t\t\tB. Gabbar Singh");
        printf("\n\t\t\t\tC. Kancha Cheena");
        printf("\n\t\t\t\tD. Mogambo");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :case 'B' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {  q122:
          lifeline=0;
         header();
        printf("\n Question no 2    You are using life line");
        printf("\t\t\t\t\t\t\t\t\t\tRS.10,000/-");

        printf("\n\n\t\t\t‘Daga’ and ‘Teja’ was henchmen of Which Filmi Character?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Kancha Cheena");
        printf("\n\t\t\t\tD. Mogambo");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q122;
       }

        }

         break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q121;}
   /*  QUESTION 3 */


        q131:
        header();
        printf("\n Question no 3");
        printf("\t\t\t\t\t\t\t\t\t\tRS.20,000/-");
        printf("\n\n\t\t\tWhat did Facebook buy a staggering amount of $19 billion earlier this year ?");
        printf("\n\n\t\t\t\tA. Youtube");
        printf("\n\t\t\t\tB. Instagram");
        printf("\n\t\t\t\tC. Nokia");
        printf("\n\t\t\t\tD. Whatsapp");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :case 'B' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {   q132:
          lifeline=0;
          header();
        printf("\n Question no 3   You are using lifeline");
        printf("\t\t\t\t\t\t\t\t\t\tRS.20,000/-");
        printf("\n\n\t\t\tWhat did Facebook buy a staggering amount of $19 billion earlier this year ?");

        printf("\n\n\t\t\t\tA. Youtube");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Whatsapp");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
      fflush(stdin);
       scanf("%c",&q);

       switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q132;
       }

        }
         break;
        default:
            printf("\nEnter any valid choice");
            getch();
           goto q131 ;}



        /*  QUESTION 4 */


        q141:
        header();
        printf("\n Question no 4");
        printf("\t\t\t\t\t\t\t\t\t\tRS.40,000/-");
        printf("\n\n\t\t\tWhich group did Sampat Pal Devi start in Bundelkhand to fight violence against women ?");
        printf("\n\n\t\t\t\tA. Narimukt Wahini");
        printf("\n\t\t\t\tB. Mahila Morcha");
        printf("\n\t\t\t\tC. Laxmibai Sena");
        printf("\n\t\t\t\tD. Gulabi Gang");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :case 'B' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {   q142:
          lifeline=0;
          header();
        printf("\n Question no 4  You are using life line");
        printf("\t\t\t\t\t\t\t\t\t\tRS.40,000/-");
        printf("\n\n\t\t\tWhich group did Sampat Pal Devi start in Bundelkhand to fight violence against women ?");
        printf("\n\n\t\t\t\tA. Narimukt Wahini");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Gulabi Gang ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
           goto q142;

       }

        }
         break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q141;}



        /*  QUESTION 5 */


        q151:
        header();
        printf("\n Question no 5");
        printf("\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\tWhere was the BRICS summit held in 2014?");
        printf("\n\n\t\t\t\tA. Brazil");
        printf("\n\t\t\t\tB. India");
        printf("\n\t\t\t\tC. Russia");
        printf("\n\t\t\t\tD. China ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'D' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {q152:
          lifeline=0;

        header();
        printf("\n Question no 5");
        printf("\t\t\t\t\t\t\t\t\t\tRS.80,000/-  You are using your lifeline");
        printf("\n\n\t\t\tWhere was the BRICS summit held in 2014?");
        printf("\n\n\t\t\t\tA. Brazil");
        printf("\n\t\t\t\tB. India");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q152;

       }

        }

        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q151;

            }

         /*  QUESTION 6 */


        q161:
        header();
        printf("\n Question no 6");
        printf("\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWho wrote the introduction to the English translation of Rabindranath Tagore’s Gitanjali?");
        printf("\n\n\t\t\t\tA. P.B. Shelley ");
        printf("\n\t\t\t\tB. Alfred Tennyson ");
        printf("\n\t\t\t\tC. W.B. Yeats ");
        printf("\n\t\t\t\tD. T.S. Elliot  ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'A' :case 'D' :case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {  q162:
          lifeline=0;

        header();
        printf("\n Question no 6   You are using your lifeline");
        printf("\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWho wrote the introduction to the English translation of Rabindranath Tagore’s Gitanjali?");
        printf("\n\n\t\t\t\t ");
        printf("\n\t\t\t\tB. Alfred Tennyson ");
        printf("\n\t\t\t\tC. W.B. Yeats ");
        printf("\n\t\t\t\t ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q162;

       }

        }

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q161;}




         /*  QUESTION 7 */


        q171:
        header();
        printf("\n Question no 7");
        printf("\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\tWhich of these leaders was a recipient of a gallantry award in 1987 by a state government for saving two girls from drowning?");
        printf("\n\n\t\t\t\tA. Anandiben Patel  ");
        printf("\n\t\t\t\tB. Vasundhara Raje Scindia  ");
        printf("\n\t\t\t\tC. Uma Bharti");
        printf("\n\t\t\t\tD. Mamata Banerjee ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'D' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {q172:
          lifeline=0;

        header();
        printf("\n Question no 7  You are using your life line");
        printf("\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\tWhich of these leaders was a recipient of a gallantry award in 1987 by a state government for saving two girls from drowning?");
        printf("\n\n\t\t\t\tA. Anandiben Patel  ");
        printf("\n\t\t\t\tB. Vasundhara Raje Scindia  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q172;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q171;
        }



          /*  QUESTION 8 */


        q181:
        header();
        printf("\n Question no 8");
        printf("\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tThe wife of which of these famous sports persons was once captain of Indian volleyball team?");
        printf("\n\n\t\t\t\tA. K.D.Jadav  ");
        printf("\n\t\t\t\tB. Dhyan Chand  ");
        printf("\n\t\t\t\tC. Prakash Padukone");
        printf("\n\t\t\t\tD. Milkha Singh ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'A' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {q182:
          header();
        printf("\n Question no 8    You are using your lifeline");
        printf("\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tThe wife of which of these famous sports persons was once captain of Indian volleyball team?");
        printf("\n\n\t\t\t\tA. K.D.Jadav  ");
        printf("\n\t\t\t\t  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Milkha Singh ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q182;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q181;}



           /*  QUESTION 9 */


        q191:
        header();
        printf("\n Question no 9");
        printf("\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\t Which of these chief ministers is a former officer of the Indian Army?");
        printf("\n\n\t\t\t\tA. Ashok Gehlot  ");
        printf("\n\t\t\t\tB. P S Golay  ");
        printf("\n\t\t\t\tC. Amarinder Singh");
        printf("\n\t\t\t\tD. Pinarayi Vijayan");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'D' :case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {q192:
          header();
        printf("\n Question no 9  You are using your lifeline");
        printf("\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\t Which of these chief ministers is a former officer of the Indian Army?");
        printf("\n\n\t\t\t\tA. Ashok Gehlot  ");
        printf("\n\t\t\t\t  ");
        printf("\n\t\t\t\tC. Amarinder Singh");
        printf("\n\t\t\t\t");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q192;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q191;}



      /*  QUESTION 10*/


        q1101:
        header();
        printf("\n Question no 10");
        printf("\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\t According to Hindu scriptures, which of these rishis was named after a type of weapon he carried?");
        printf("\n\n\t\t\t\tA. Rishi Vishwamitra  ");
        printf("\n\t\t\t\tB. Rishi Jamadagni  ");
        printf("\n\t\t\t\tC.Rishi Ashtavakra");
        printf("\n\t\t\t\tD. Rishi Parshurama");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'A' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {q1102:
          lifeline=0;
          header();
        printf("\n Question no 10");
        printf("\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\t According to Hindu scriptures, which of these rishis was named after a type of weapon he carried?");
        printf("\n\n\t\t\t\t ");
        printf("\n\t\t\t\t ");
        printf("\n\t\t\t\tC. Rishi Ashtavakra");
        printf("\n\t\t\t\tD. Rishi Parshurama");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1102;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1101;}



             /*  QUESTION 11 */


        q1111:
        header();
        printf("\n Question no 11");
        printf("\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\t.. Name the England Cricket Captain who became the youngestBatsman to score 7000 Runs ");
        printf("\n\n\t\t\t\tA. Kevin Peitersen  ");
        printf("\n\t\t\t\tB. Alastair Cook ");
        printf("\n\t\t\t\tC. Daniel Vettori");
        printf("\n\t\t\t\tD. Andrew Strauss ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'D' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {q1112:
          lifeline=0;

        header();
        printf("\n Question no 11  You are using your life line");
        printf("\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tName the England Cricket Captain who became the youngestBatsman to score 7000 Runs");
        printf("\n\n\t\t\t\tA. Kevin Peitersen ");
        printf("\n\t\t\t\tB.Alastair Cook  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1112;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1111;
        }



            /*  QUESTION 12 */


        q1121:
        header();
        printf("\n Question no 12");
        printf("\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t The Naga and the Chin Hills from the boundary between which two countries?");
        printf("\n\n\t\t\t\tA. India – Bangladesh  ");
        printf("\n\t\t\t\tB. India – China  ");
        printf("\n\t\t\t\tC. India – Bhutan");
        printf("\n\t\t\t\tD. India – Myanmar  ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :case 'C' :case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {q1122:
          lifeline=0;

        header();
        printf("\n Question no 12  you are using lifeline");
        printf("\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t The Naga and the Chin Hills from the boundary between which two countries?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\t  ");
        printf("\n\t\t\t\tC. India – Bhutan");
        printf("\n\t\t\t\tD. India – Myanmar");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1122;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1121;
        }


/*  QUESTION 13 */


        q1131:
        header();
        printf("\n Question no 13");
        printf("\t\t\t\t\t\t\t\t\t\tRS.1,00,00,000/-");
        printf("\n\n\t\t\t Which British Resident at Hyderabad, the subject of a book titled White Mughals” was married to a noble women called Khair un-Nissa?");
        printf("\n\n\t\t\t\tA. William Achilies Kirkpatrick  ");
        printf("\n\t\t\t\tB. James Achilies Kirkpatrick  ");
        printf("\n\t\t\t\tC. Louis George Gregory");
        printf("\n\t\t\t\tD. George Chinnari ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {q1132:
          lifeline=0;

        header();
        printf("\n Question no 12  You are using lifeline");
        printf("\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t  Which British Resident at Hyderabad, the subject of a book titled White Mughals” was married to a noble women called Khair un-Nissa?");

        printf("\n\t\t\t\tB. James Achilies Kirkpatrick  ");

        printf("\n\t\t\t\tD. George Chinnari  ");


        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
       case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1132;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1131;
        }





        /*  QUESTION 14 */


        q1141:
        header();
        printf("\n Question no 14");
        printf("\t\t\t\t\t\t\t\t\t\tRS.5,00,00,000/-");
        printf("\n\n\t\t\t Who was the first Governor General of India ?");
        printf("\n\n\t\t\t\t(A) Lord Amherst ");
        printf("\n\t\t\t\t(B) Lord William Bentinck  ");
        printf("\n\t\t\t\t(C) Sir Charles Metcalfe");
        printf("\n\t\t\t\t(D) Robert Clive  ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {q1142:
          lifeline=0;

        header();
        printf("\n Question no 14");
        printf("\t\t\t\t\t\t\t\t\t\tRS.5,00,00,000/-");
        printf("\n\n\t\t\t Who was the first Governor General of India ?");
        printf("\n\n\t\t\t\t(A) Lord Amherst ");
        printf("\n\t\t\t\t(B) Lord William Bentinck  ");
        printf("\n\t\t\t\t(C) ");
        printf("\n\t\t\t\t(D)   ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1142;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1141;
        }

return;
}




void showscore(int temp)
{
 switch(temp)
 {
    case 0:
    printf("No money !");
    break;

    case 1:
    printf("Rs.5,000");
    break;

    case 2:
    printf("Rs.10,000");
    break;

    case 3:
    printf("Rs.20,000");
    break;

    case 4:
    printf("Rs.40,000");
    break;

    case 5:
    printf("Rs.80,000");
    break;

    case 6:
    printf("Rs.1,60,000");
    break;

    case 7:
    printf("Rs.2,50,000");
    break;

    case 8:
    printf("Rs.3,20,000");
    break;

    case 9:
    printf("Rs.6,40,000");
    break;

    case 10:
    printf("Rs.12,50,000");
    break;

    case 11:
    printf("Rs.25,00,000");
    break;

    case 12:
    printf("Rs.50,00,000");
    break;

    case 13:
    printf("Rs.1 Crore");
    break;

    case 14:
    printf("Rs.5 Crore");
    break;
 }
}



void correct()
{
        header();
        a.points++;
        printf("\n\n \t\t\tCORRECT ANSWER !");
        printf("\n\n \t\t\tYOU HAVE WON ");
        showscore(a.points);
        printf("\n\n\t\t\t\t Press any key for next question for ");
        showscore(a.points+1);
        getch();
        return;

}
void wrong()
{header();

        printf("\n\n \t\t\tWRONG ANSWER !");
        printf("\n\n \t\t\tPRIZE MONEY WON ");
        if (a.points>=1 && a.points<5)
        {
            printf("Rs.5,000");
            a.points=1;
        }
        if (a.points>=5 && a.points<10)
        {
            printf("Rs.80,000");
            a.points=5;
        }
        if (a.points>=10 && a.points<14)
        {
            printf("Rs.25,00,000");
            a.points=10;
        }

        if (sethighscore()==1)
        {
            printf("\n\t\t\tNew High Score !");
        }
        else
        {
            printf("\n\t\t\tNo highscore");
        }
        printf("\n\t\t Press any key for main menu>>");
        getch();
        mainmenu();

}
void quit ()
{
        header();

        printf("\n\n \t\t\tYou just quit the game");
        printf("\n\n \t\t\tYOU HAVE WON ");
        showscore(a.points);
        if (sethighscore()==1)
        {
            printf("\nNew High Score !");
        }
        else
        {
            printf("\nNo highscore");
        }
        printf("\n\n\t\t\t\t Press any key for Main menu >> ");
       getch();
        mainmenu();

}
void qset2()
{char q;
     /*  QUESTION 1 */

        qa111:
        header();
        printf("\n Question no 1");
        printf("\t\t\t\t\t\t\t\t\t\tRS.5,000/-");
        printf("\n\n\t\t\tThe Leave of which of these trees is the shortest in length?");
        printf("\n\n\t\t\t\tA. Coconut");
        printf("\n\t\t\t\tB. Date");
        printf("\n\t\t\t\tC. Papaya");
        printf("\n\t\t\t\tD. Mango");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      { qa112:
          lifeline=0;
          header();
          printf("\n Question no 1 You are using your lifeline");
        printf("\t\t\t\t\t\t\t\t\t\tRS.5,000/-");
       printf("\n\n\t\t\tThe Leave of which of these trees is the shortest in length?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Papaya");
        printf("\n\t\t\t\tD. Mango");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

       break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto qa112;
       }

        }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa111;

       }



        /*  QUESTION 2 */


        qa121:
        header();
        printf("\n Question no 2");
        printf("\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\tTwo Brothers named Ravi Verma and Vijay Verma are the main characters of which of these films?");
        printf("\n\n\t\t\t\tA. Zanzeer");
        printf("\n\t\t\t\tB. Sharabee");
        printf("\n\t\t\t\tC. Deewaar");
        printf("\n\t\t\t\tD. Trishul");
        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'A' :case 'B' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {  qa122:
          lifeline=0;
         header();
        printf("\n Question no 2    You are using life line");
        printf("\t\t\t\t\t\t\t\t\t\tRS.10,000/-");

       printf("\n\n\t\t\tTwo Brothers named Ravi Verma and Vijay Verma are the main characters of which of these films?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. Sharabee");
        printf("\n\t\t\t\tC. Deewaar ");
        printf("\n\t\t\t\t");


        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto qa122;
       }

        }

         break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa121;}





   /*  QUESTION 3 */


        qa131:
        header();
        printf("\n Question no 3");
        printf("\t\t\t\t\t\t\t\t\t\tRS.20,000/-");
        printf("\n\n\t\t\tWhat happens to red litmus paper when exposed to a base?");
        printf("\n\n\t\t\t\tA. Become Transparent");
        printf("\n\t\t\t\tB. Turns Blue");
        printf("\n\t\t\t\tC. Turns White");
        printf("\n\t\t\t\tD. Stays Red");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {   qa132:
          lifeline=0;
          header();
        printf("\n Question no 3   You are using lifeline");
        printf("\t\t\t\t\t\t\t\t\t\tRS.20,000/-");
        printf("\n\n\t\t\tWhat happens to red litmus paper when exposed to a base?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. Turns Blue");
        printf("\n\t\t\t\tC. Turns White");
        printf("\n\t\t\t\t");


        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
      fflush(stdin);
       scanf("%c",&q);

       switch(q)
       {case 'B':
        correct();
        break;
        case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto qa132;
       }

        }
         break;
        default:
            printf("\nEnter any valid choice");
            getch();
           goto qa131 ;}



        /*  QUESTION 4 */


        qa141:
        header();
        printf("\n Question no 4");
        printf("\t\t\t\t\t\t\t\t\t\tRS.40,000/-");
        printf("\n\n\t\t\t.If you are attending the Kala Ghoda Arts Festivals, in which city would you be?");
        printf("\n\n\t\t\t\tA. Mumbai");
        printf("\n\t\t\t\tB. Chandigadh");
        printf("\n\t\t\t\tC. Delhi");
        printf("\n\t\t\t\tD. Kolkata ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'D' :case 'B' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {   qa142:
          lifeline=0;
          header();
        printf("\n Question no 4  You are using life line");
        printf("\t\t\t\t\t\t\t\t\t\tRS.40,000/-");
        printf("\n\n\t\t\t.If you are attending the Kala Ghoda Arts Festivals, in which city would you be?");
        printf("\n\n\t\t\t\tA. Mumbai");

        printf("\n\t\t\t\tD. Kolkata ");


        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
           goto qa142;

       }

        }
         break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa141;}



        /*  QUESTION 5 */


        qa151:
        header();
        printf("\n Question no 5");
        printf("\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\tMilind-panha is a dialogue between king Menander or Milinda and Which Buddhist Monk?");
        printf("\n\n\t\t\t\tA. Asanga");
        printf("\n\t\t\t\tB. Naagsena");
        printf("\n\t\t\t\tC. Mahadharmrmarsita");
        printf("\n\t\t\t\tD. Dharmrakshit   ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'D' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {qa152:
          lifeline=0;

        header();
        printf("\n Question no 5");
        printf("\t\t\t\t\t\t\t\t\t\tRS.80,000/-  You are using your lifeline");
        printf("\n\n\t\t\tMilind-panha is a dialogue between king Menander or Milinda and Which Buddhist Monk?");
        printf("\n\n\t\t\t\tA. Asanga");
        printf("\n\t\t\t\tB. Naagsena");
        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa152;

       }

        }

        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa151;

            }





         /*  QUESTION 6 */


        qa161:
        header();
        printf("\n Question no 6");
        printf("\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tThe site of Harappa of the Indus Vally Civilisation was primarily excavated by which of the following archaelogists?");
        printf("\n\n\t\t\t\tA.  NP Chakrvarti  ");
        printf("\n\t\t\t\tB. Mortimer Wheeler  ");
        printf("\n\t\t\t\tC. Guyseooe Fuirekku ");
        printf("\n\t\t\t\tD. Daya Ram Sahni   ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :case 'C' :case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {  qa162:
          lifeline=0;

        header();
        printf("\n Question no 6   You are using your lifeline");
        printf("\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tThe site of Harappa of the Indus Vally Civilisation was primarily excavated by which of the following archaelogists?");
        printf("\n\t\t\t\tB. Mortimer Wheeler  ");
        printf("\n\t\t\t\tD. Daya Ram Sahni   ");
        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa162;

       }

        }

        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa161;}




         /*  QUESTION 7 */


        qa171:
        header();
        printf("\n Question no 7");
        printf("\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\t Out of the given countries which got independence on 15 August 1971 ?");
        printf("\n\n\t\t\t\tA.  Congoi  ");
        printf("\n\t\t\t\tB. Bahrain   ");
        printf("\n\t\t\t\tC.  Pakistan ");
        printf("\n\t\t\t\tD. India");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'D' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {qa172:
          lifeline=0;

        header();
        printf("\n Question no 7  You are using your life line");
        printf("\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\t Out of the given countries which got independence on 15 August 1971 ?");
        printf("\n\n\t\t\t\tA.  Congoi  ");
        printf("\n\t\t\t\tB. Bahrain   ");



        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa172;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa171;
        }



          /*  QUESTION 8 */


        qa181:
        header();
        printf("\n Question no 8");
        printf("\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tParallel bars, trampoline, pommel horse and balancing beams are some of the equipment used in which sport? ");
        printf("\n\n\t\t\t\tA. Steeplechase  ");
        printf("\n\t\t\t\tB. Pole vault  ");
        printf("\n\t\t\t\tC. Decathlon");
        printf("\n\t\t\t\tD. Gymnastics ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'A' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {qa182:
          header();
        printf("\n Question no 8    You are using your lifeline");
        printf("\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
         printf("\n\n\t\t\tParallel bars, trampoline, pommel horse and balancing beams are some of the equipment used in which sport?");
        printf("\n\n\t\t\t\tA. Steeplechase  ");
        printf("\n\t\t\t\tD. Gymnastics  ");



        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa182;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa181;}



           /*  QUESTION 9 */


        qa191:
        header();
        printf("\n Question no 9");
        printf("\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\t Inspired by the Dandi March, who undertook the Vedaranyam March in April 1930?");
        printf("\n\n\t\t\t\tA. Lakshmi Swaminathan ");
        printf("\n\t\t\t\tB. George Joseph  ");
        printf("\n\t\t\t\tC. C Rajagopalachari ");
        printf("\n\t\t\t\tD. E M S Namboodiripad");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'D' :case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {qa192:
          header();
        printf("\n Question no 9  You are using your lifeline");
        printf("\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
         printf("\n\n\t\t\t Inspired by the Dandi March, who undertook the Vedaranyam March in April 1930?");
        printf("\n\n\t\t\t\tA. Lakshmi Swaminathan ");
        printf("\n\t\t\t\tC. C Rajagopalachari ");

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa192;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa191;}



      /*  QUESTION 10*/


        qa1101:
        header();
        printf("\n Question no 10");
        printf("\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\t Which of these protected forest areas was initially established to provide clean water to its nearby city?");
        printf("\n\n\t\t\t\tA. Kaziranga  ");
        printf("\n\t\t\t\tB. Bandhavgarh ");
        printf("\n\t\t\t\tC. Kanha");
        printf("\n\t\t\t\tD. Dachigam ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'A' :case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {qa1102:
          lifeline=0;
          header();
        printf("\n Question no 10");
        printf("\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\t Which of these protected forest areas was initially established to provide clean water to its nearby city?");
        printf("\n\n\t\t\t\tA. Kaziranga  ");
        printf("\n\t\t\t\tD. Dachigam ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa1102;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa1101;}



             /*  QUESTION 11 */


        qa1111:
        header();
        printf("\n Question no 11");
        printf("\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tWho is the author of travelogues such as “Cheen Mein Kya Dekha”, “Meri Ladakh Yatra”, “Meri Tibet Yatra” and “Roos Mein Pachchees Maas”?");
        printf("\n\n\t\t\t\tA. Kedarnath Singh   ");
        printf("\n\t\t\t\tB. Kashinath Singh ");
        printf("\n\t\t\t\tC. Rahul Sankrityayan");
        printf("\n\t\t\t\tD. Vishnu Prabhakar ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'A' :case 'D' :case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {qa1112:
          lifeline=0;

        header();
        printf("\n Question no 11  You are using your life line");
        printf("\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tWho is the author of travelogues such as “Cheen Mein Kya Dekha”, “Meri Ladakh Yatra”, “Meri Tibet Yatra” and “Roos Mein Pachchees Maas”?");
        printf("\n\n\t\t\t\tA. Kedarnath Singh ");
        printf("\n\t\t\t\tC. Rahul Sankrityayan ");



        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa1112;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa1111;
        }



            /*  QUESTION 12 */


        qa1121:
        header();
        printf("\n Question no 12");
        printf("\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t Which was the first spacecraft to successfully land on the Moon? ");
        printf("\n\n\t\t\t\tA. Explorer 33  ");
        printf("\n\t\t\t\tB. Pioneer 0  ");
        printf("\n\t\t\t\tC. Ranger 4");
        printf("\n\t\t\t\tD. Luna 9 ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :case 'C' :case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {qa1122:
          lifeline=0;

        header();
        printf("\n Question no 12  you are using lifeline");
        printf("\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t Which was the first spacecraft to successfully land on the Moon? ");

        printf("\n\t\t\t\tB. Pioneer 0  ");
        printf("\n\t\t\t\tD. Luna 9");

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
       case 'B' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa1122;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa1121;
        }


/*  QUESTION 13 */


        qa1131:
        header();
        printf("\n Question no 13");
        printf("\t\t\t\t\t\t\t\t\t\tRS.1,00,00,000/-");
        printf("\n\n\t\t\t India’s first driverless metro train was inaugurated in December 2020 in which city?");
        printf("\n\n\t\t\t\tA. Delhi  ");
        printf("\n\t\t\t\tB. Kolkatta  ");
        printf("\n\t\t\t\tC.  Mumbai");
        printf("\n\t\t\t\tD. Bengaluru ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {qa1132:
          lifeline=0;

        header();
        printf("\n Question no 13");
        printf("\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
         printf("\n\n\t\t\t India’s first driverless metro train was inaugurated in December 2020 in which city?");
        printf("\n\n\t\t\t\tA. Delhi  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC.  Mumbai");
        printf("\n\t\t\t\t ");

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa1132;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa1131;
        }





        /*  QUESTION 14 */


        qa1141:
        header();
        printf("\n Question no 14");
        printf("\t\t\t\t\t\t\t\t\t\tRS.5,00,00,000/-");
        printf("\n\n\t\t\t Which two players scored for India in the football of the 1962 Asian Games, to give India a gold medal?");
        printf("\n\n\t\t\t\t(A)  P K Banerjee, Jarnail Singh  ");
        printf("\n\t\t\t\t(B) Neville D’SouzTulsidas Balaram  ");
        printf("\n\t\t\t\t(C)  Chuni Goswami, Yousuf Khan");
        printf("\n\t\t\t\t(D) Syed Nayeemuddin, Arun Ghosh  ");
        if (lifeline==1)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':
      {qa1142:
          lifeline=0;

        header();
        printf("\n Question no 14");
        printf("\t\t\t\t\t\t\t\t\t\tRS.5,00,00,000/-");
         printf("\n\n\t\t\t Which two players scored for India in the football of the 1962 Asian Games, to give India a gold medal?");

        printf("\n\t\t\t\t(A) P K Banerjee, Jarnail Singh  ");
        printf("\n\t\t\t\t(C)  Chuni Goswami, Yousuf Khan");



        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
       case 'C' :
        wrong();
        break;

        case 'F':
        quit();
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa1142;
       }

        }
        default:
            printf("\nEnter any valid choice");
            getch();
            goto qa1141;
        }

}





int sethighscore()
{
    int temp,temp2=0;
    FILE *fr;
    fr=fopen("highscore.DAT","rb");


	if(fr==NULL)
	{
    fr=fopen("highscore.DAT","wb");

	                if(fr==NULL)
                           {printf("\nErorr");
                            getch();
                            exit(0);}

		fwrite(&a,sizeof(struct user),1,fr);
		temp2=1;


	}

   else
   {
       fread(&b,sizeof(struct user),1,fr);
       fclose(fr);

        if (a.points>b.points)
       {temp2=1;

      fr=fopen("highscore.DAT","wb");
                    if(fr==NULL)
                        {printf("\nErorr");
                            getch();
                            exit(0);}

       fwrite(&a,sizeof(struct user),1,fr);
       fclose(fr);

       }

   }


    return temp2;
}


void showhighscore()
{ FILE *ft;
    header();

        printf("\n\n\t\t\tHIGH SCORE");

    ft=fopen("highscore.DAT","rb");


	if(ft==NULL)
	{

      printf("\n\t\t\tNo high score available");

	}

   else
   {
       fread(&b,sizeof(struct user),1,ft);
       fclose(ft);
       printf("\nName   ");
       puts(b.name);

     printf("\nPrize Money Won = ");
     showscore(b.points);


       }

getch();
}



void aboutgame()
{
    header();
    printf("\n\n\t\t\t\t\t** ABOUT THE GAME**");
    printf("\n\n\t\tKaun Banega Crorepati");
    printf("\n\t\tMade in C language");
    printf("\n\t\tBy Anshuman Tiwari... ");

  getch();

}
