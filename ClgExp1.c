#include <stdio.h>

int main()
{

    float hsp, intp, workyrs;
    int a, num, jobs;
    char name[30], mail[50], ad[150], exp[200], skill[200], lang[50], inters[150], company[100], role[50];

    printf("\t\t\t*****CV TEMPLATE PROGRAM*****\n");

    printf("Your name : ");
    scanf("%s", &name);

    printf("\nYour age: ");
    scanf("%d", &a);

    printf("\nYour address: ");
    scanf("%s", &ad);
    printf("\n");

    printf("\nYour email id: ");
    scanf("%s", &mail);
    printf("\n");

    printf("\nMob. No.: ");
    scanf("%d", &num);
    printf("\n");

    printf("\t\t*****EDUCATIONAL QUALIFICATIONS*****\n");
    printf("\n");

    printf("10th Std Percentage : ");
    scanf("%f", &hsp);
    printf("\n");

    printf("12th Std Percentage : ");
    scanf("%f", &intp);
    printf("\n");

    printf("\t\t-------EXPERIENCE AND SKILLS------");

    printf("\nEnter your work experience : ");
    scanf("%s", &exp);
    printf("\n");

    printf("Enter your skills : ");
    scanf("%s", &skill);
    printf("\n");

    printf("Languages Known : ");
    scanf("%s", &lang);
    printf("\n");

    printf("\t\t-------CURRENT JOB STATUS------");

    printf("\n0 if you are currently unemployed; 1 if you are working somewhere.");
    scanf("%d", &jobs);
    printf("\n");

    if (jobs == 1)
    {

        printf("Company :");
        scanf("%s", &company);
        printf("\n");

        printf("Your Role :");
        scanf("%s", &role);
        printf("\n");

        printf("Years Working :");
        scanf("%f", &workyrs);
        printf("\n");
    }

    printf("\t\t\t-------****YOUR CV****------\n");

    printf("\t\t-----PERSONAL DETAILS-----");
    printf("\nName :%s", name);
    printf("\nAge :%d", a);
    printf("\nAddress :%s", ad);
    printf("\nEmail :%s", mail);
    printf("\nContact Number :%d", num);

    printf("\n\t\t-----EDUCATIONAL QUALIFICATIONS-----\n");
    printf("10th Std Percentage : %f", hsp);

    printf("\n12th Std Percentage : %f", intp);

    printf("\n\t\t-------EXPERIENCE AND SKILLS------");

    printf("\nWork Experience : %s", exp);

    printf("\nSkills : %s", skill);

    printf("\nLanguages Known : %s", lang);

    printf("\n\t\t-------CURRENT JOB STATUS------");

    if (jobs == 1)
    {

        printf("\nCompany :%s", company);

        printf("\nYour Role :%s", role);
        printf("\nYears Working :%s", workyrs);
    }
    else if (jobs == 0)
    {
        printf("\nUnemployed");
    }

    return 0;
}