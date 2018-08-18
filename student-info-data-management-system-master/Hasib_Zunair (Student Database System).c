#include<stdio.h>

void add_student_detail();
void search_student();                                                         //FUNCTION PROTOTYPES!!!
void modify_student_detail();
void view_student_detail();
void del_student_detail();

   typedef struct                                                              //Struct for student info

{
   int std_num;
   char std_fname[10];
   char std_sname[10];
   int age;
   char gender[5];
   int d_o_b;
   char m_o_b[5];
   int y_o_b;
   char sm_name[15];
   int id;
   char dept[8],major[8];
   int t_courses;
   int t_credit;
   float gradepoint_sum;
   float cgpa;



}transcript;                                                                         //end of structure

int main()
{

      char choice;
      printf("________________________________________________________________________________");
      printf("\n            ****** WELCOME TO HZ's STUDENT INFORMATION DATABASE ******\n");
      printf("________________________________________________________________________________");



do
  {

      printf("\n A- Wish to add student details: \n\n");
      printf(" S- Wish to look up a student by student number: \n\n");                                 //print menu
      printf(" M- Wish to update student detail: \n\n");
      printf(" V- Wish to view all current student details in database: \n\n");
      printf(" D- Wish to delete a student record: \n\n");
      printf(" X- Exit from database: \n\n");
      printf("________________________________________________________________________________\n");
      printf("********************************************************************************\n");
      printf(" Enter you choice(A, S, M, V, D, X): ");
      choice=getchar();
      getchar();

      switch(choice)                                                                       //choice selection, calling of functions
      {
          case 'A':
          case 'a':
                   printf("\n This is the ADD function, enter the following inputs to add student detail.\n Thank You.....\n");
                   add_student_detail();
                   break;


          case 'S':
          case 's':
                   printf("\n This is the SEARCH function,enter student number to display information.\n Thank You......\n");
                   search_student();
                   break;



          case 'M':
          case 'm':
                   printf("\n This is the MODIFY function.\n Enter student number to update his/her record.\n Thank You.....\n");
                   modify_student_detail();
                   break;


          case 'V':
          case 'v':
                   printf("\n This is the VIEW function. All information of students are displayed here.\n Thank You.....\n");
                   view_student_detail();
                   break;


          case 'D':
          case 'd':
                   printf("\n This is the DELETE function. Enter student's number to delete his/her record.\n Thank you...\n");
                   del_student_detail();
                   break;


          case 'X':
          case 'x':
                   printf("\n HAVE A GOOD DAY :) !");
                   printf("\n Exiting from database.....\n");
                   break;


          default: printf("\n INVALID INPUT! ENTER THE ABOVE GIVEN ALPHABETS TO PROCEED.\a\n");
                   break;

      }


  }  while(choice!='X' && choice!='x');


     return 0;

}                                                                                //end of MAIN function

     void add_student_detail()                                                   //add function starts
{

     transcript s1;


     printf("\n Enter student number in list(eg. 1,2..): ");                           //Taking information as inputs
     scanf("%d",&s1.std_num);


     printf("\n Enter the first name of student(eg. Paul..): ");
     scanf("%s",s1.std_fname);


     printf("\n Enter the surname name of student(eg. Walker..): ");
     scanf("%s",s1.std_sname);



     printf("\n Enter the age of student(eg. 17,55..): ");
     scanf("%d",&s1.age);


     printf("\n Enter gender of student(Male/Female): ");
     scanf("%s",s1.gender);


     printf("\n Enter date of birth of student(eg. 23,30..): ");
     scanf("%d",&s1.d_o_b);


     printf("\n Enter month of birth(eg. May,Dec..): ");
     scanf("%s",&s1.m_o_b);


     printf("\n Enter year of birth of student(eg. 1994,2020..): ");
     scanf("%d",&s1.y_o_b);


     printf("\n Enter Semester name of student(eg. Fall,Summer..): ");
     scanf("%s",&s1.sm_name);

     printf("\n Enter ID of student(eg. 131,111..): ");
     scanf("%d",&s1.id);


     printf("\n Enter department name of student(eg. BENG,ECE..): ");
     scanf("%s",&s1.dept);


     printf("\n Enter major of student(eg. BBA,CSE,EEE..): ");
     scanf("%s",&s1.major);


     printf("\n Enter total number of courses completed by student(eg. 10,20..): ");
     scanf("%d",&s1.t_courses);


     printf("\n Enter total number of credits completed by student(eg. 20,100..): ");
     scanf("%d",&s1.t_credit);


     printf("\n Enter total gradepoints of student(eg. 45.6,130.4): ");                               //End of info as input
     scanf("%f",&s1.gradepoint_sum);


     s1.cgpa=s1.gradepoint_sum/s1.t_credit;                                                           //cgpa calc


     printf("\n Thank You. A record has been successfully stored database....... :) \n");
     printf("________________________________________________________________________________\n");


    FILE *pfile;               //OPEN FILE

    pfile=fopen("E:\\student_database_file.txt","a");



   if(pfile!=NULL)
   {

        //print in file
       fprintf(pfile,"%d  %s  %s  %d  %s  %d  %s  %d  %s  %d  %s  %s  %d  %d  %.2f  %.2f\n\n",s1.std_num,s1.std_fname,s1.std_sname,s1.age,s1.gender,s1.d_o_b,s1.m_o_b,s1.y_o_b,s1.sm_name,s1.id,s1.dept,s1.major,s1.t_courses,s1.t_credit,s1.gradepoint_sum,s1.cgpa);


       fclose(pfile);           //close file

   }


   else
   {
       printf("\n SYSTEM BREACH!!\n");

   }

    getchar();
}                                                                                           //END OF ADD FUNCTION



void search_student()                                                             //start of search func
{

    int search, found = 0;

    transcript s1;


    printf("\n Enter student number to search his/her information: ");
    scanf("%d", &search);

    FILE *pfile;            //open file

    pfile = fopen("E:\\student_database_file.txt","r");

    if (pfile!=NULL)
    {

        while(!feof(pfile) && found==0)
        {
             //read from file for search function
            fscanf(pfile,"%d  %s  %s  %d  %s  %d  %s  %d  %s  %d  %s  %s  %d  %d  %f  %f\n\n",&s1.std_num,&s1.std_fname,&s1.std_sname,&s1.age,&s1.gender,&s1.d_o_b,&s1.m_o_b,&s1.y_o_b,&s1.sm_name,&s1.id,&s1.dept,&s1.major,&s1.t_courses,&s1.t_credit,&s1.gradepoint_sum,&s1.cgpa);

            if (s1.std_num == search)
            {
                found = 1;

            printf("________________________________________________________________________________\n");
            printf(" The information of student number %d is given below:  \n",s1.std_num);
            printf("________________________________________________________________________________\n");
            printf("No. Name Age Gender DOB Semester ID Dept. Major Course Credit Grade-points CGPA\n");
            printf("________________________________________________________________________________\n");
            printf("%d %s %s  %d  %s  %d %s  %d %s  %d %s %s  %d %d  %.2f  %.2f\n",s1.std_num,s1.std_fname,s1.std_sname,s1.age,s1.gender,s1.d_o_b,s1.m_o_b,s1.y_o_b,s1.sm_name,s1.id,s1.dept,s1.major,s1.t_courses,s1.t_credit,s1.gradepoint_sum,s1.cgpa);
            printf("________________________________________________________________________________\n");


            }

        }

        if (found == 0)
        {
            printf("________________________________________________________________________________\n");
            printf("\n Record not found.\n\n");
        }

        printf("****************************  END OF CONTENTS  *********************************");
        printf("\n\n HAVE A GOOD DAY... :) !\n\n");
        printf("________________________________________________________________________________\n");
        fclose(pfile);                                      //close file
    }
    else
    {
        printf("\nError opening file\n");
    }


    getchar();
}                                                                                 //end of search func


void modify_student_detail()                                                      //start mod func
{

    int search, found = 0;

    transcript s1;

    printf("\n Enter student number to change information: ");
    scanf("%d", &search);

    FILE *pfile;
    FILE *pTemp;

    pfile = fopen("E:\\student_database_file.txt","r");
    pTemp = fopen("E:\\temp.txt", "w");

    if (pfile!=NULL && pTemp!=NULL)
    {

        while(!feof(pfile))
        {
           fscanf(pfile,"%d  %s  %s  %d  %s  %d  %s  %d  %s  %d  %s  %s  %d  %d  %f  %f\n\n",&s1.std_num,&s1.std_fname,&s1.std_sname,&s1.age,&s1.gender,&s1.d_o_b,&s1.m_o_b,&s1.y_o_b,&s1.sm_name,&s1.id,&s1.dept,&s1.major,&s1.t_courses,&s1.t_credit,&s1.gradepoint_sum,&s1.cgpa);


            if (s1.std_num != search)
            {
                 fprintf(pTemp,"%d  %s  %s  %d  %s  %d  %s  %d  %s  %d  %s  %s  %d  %d  %.2f  %.2f\n\n",s1.std_num,s1.std_fname,s1.std_sname,s1.age,s1.gender,s1.d_o_b,s1.m_o_b,s1.y_o_b,s1.sm_name,s1.id,s1.dept,s1.major,s1.t_courses,s1.t_credit,s1.gradepoint_sum,s1.cgpa);

            }
            else
            {
                found = 1;

                printf("\n Enter %s's new number of courses(eg. 10,25...): ",s1.std_fname);
                scanf("%d",&s1.t_courses);

                printf("\n Enter %s's new number of credits(eg. 20,60...): ",s1.std_fname);
                scanf("%d",&s1.t_credit);

                printf("\n Enter %s's new grade points(eg. 45.5,110.3...): ",s1.std_fname);
                scanf("%f",&s1.gradepoint_sum);



                fprintf(pTemp,"%d  %s  %s  %d  %s  %d  %s  %d  %s  %d  %s  %s  %d  %d  %.2f  %.2f\n\n",s1.std_num,s1.std_fname,s1.std_sname,s1.age,s1.gender,s1.d_o_b,s1.m_o_b,s1.y_o_b,s1.sm_name,s1.id,s1.dept,s1.major,s1.t_courses,s1.t_credit,s1.gradepoint_sum,s1.cgpa);

            }
        }

        if (found == 0)
        {
            printf("\n Record not found.\n");
        }

        printf("\n________________________________________________________________________________\n");
        printf("\n The record was updated successfully in the database. Thank you!\n");
        printf("________________________________________________________________________________\n");
        fclose(pfile);
        fclose(pTemp);

        remove("E:\\student_database_file.txt");
        rename("E:\\temp.txt","E:\\student_database_file.txt");
        remove("E:\\temp.txt");
    }
    else
    {
        printf("\n Error opening file\n");
    }


    getchar();
}                                                                                 //end of mod func




void view_student_detail()                                                        //start of view func
{

    transcript s1;

    printf("\n The complete list of contents in the database are as printed below:  \n");
    printf("________________________________________________________________________________\n");
    printf("No. Name Age Gender DOB Semester ID Dept. Major Course Credit Grade-points CGPA\n");
    printf("________________________________________________________________________________\n");
    FILE *pfile;

    pfile=fopen("E:\\student_database_file.txt","r");

    if (pfile!=NULL)
    {

        while(!feof(pfile))
    {

        fscanf(pfile,"%d  %s  %s  %d  %s  %d  %s  %d  %s  %d  %s  %s  %d  %d  %f  %f\n\n",&s1.std_num,&s1.std_fname,&s1.std_sname,&s1.age,&s1.gender,&s1.d_o_b,&s1.m_o_b,&s1.y_o_b,&s1.sm_name,&s1.id,&s1.dept,&s1.major,&s1.t_courses,&s1.t_credit,&s1.gradepoint_sum,&s1.cgpa);
        printf("%d %s %s  %d  %s  %d %s  %d %s  %d %s %s  %d %d  %.2f  %.2f\n",s1.std_num,s1.std_fname,s1.std_sname,s1.age,s1.gender,s1.d_o_b,s1.m_o_b,s1.y_o_b,s1.sm_name,s1.id,s1.dept,s1.major,s1.t_courses,s1.t_credit,s1.gradepoint_sum,s1.cgpa);
        printf("________________________________________________________________________________\n");

    }

        rewind(pfile);


        printf("****************************  END OF CONTENTS  *********************************");
        printf("\n\n HAVE A GOOD DAY... :) !\n\n");
        printf("________________________________________________________________________________\n");
        fclose(pfile);
    }
    else
    {
        printf("\nError opening file\n");
    }

}                                                                                     //End of view func



void del_student_detail()                                                    //Start of del function
{

    int search, found = 0;

    transcript s1;

    printf("\n Enter the student number to delete his/her record: ");

    scanf("%d", &search);

    FILE *pfile;
    FILE *pTemp;

    pfile = fopen("E:\\student_database_file.txt","r");

    pTemp = fopen("E:\\temp.txt", "w");


    if (pfile!=NULL && pTemp!=NULL)
    {

        while(!feof(pfile))
        {

           fscanf(pfile,"%d  %s  %s  %d  %s  %d  %s  %d  %s  %d  %s  %s  %d  %d  %f  %f\n\n",&s1.std_num,&s1.std_fname,&s1.std_sname,&s1.age,&s1.gender,&s1.d_o_b,&s1.m_o_b,&s1.y_o_b,&s1.sm_name,&s1.id,&s1.dept,&s1.major,&s1.t_courses,&s1.t_credit,&s1.gradepoint_sum,&s1.cgpa);


            if (s1.std_num != search)
            {

                fprintf(pTemp,"%d  %s  %s  %d  %s  %d  %s  %d  %s  %d  %s  %s  %d  %d  %.2f  %.2f\n\n",s1.std_num,s1.std_fname,s1.std_sname,s1.age,s1.gender,s1.d_o_b,s1.m_o_b,s1.y_o_b,s1.sm_name,s1.id,s1.dept,s1.major,s1.t_courses,s1.t_credit,s1.gradepoint_sum,s1.cgpa);
            }
            else
            {
                found = 1;
            }
        }

        if (found == 0)
        {
            printf("\n Record not found.\n");
        }

        printf("\n________________________________________________________________________________\n");
        printf("\n The record was deleted successfully.\n");
        printf("________________________________________________________________________________\n");
        fclose(pfile);

        fclose(pTemp);


        remove("E:\\student_database_file.txt");

        rename("E:\\temp.txt","E:\\student_database_file.txt");

    }

    else
 {
        printf("\n Error opening file\n");
 }

   getchar();
}                                                                               //End of del function

