# include <iostream>
using namespace std;

void getInput(double sal[][2], int numEmps); 
void calcNetSal(double sal[][2], int numEmps); 
void findUnluckies(double sal[][2], int numEmps, int lucky[]); 
void markIfUnlucky(double sal[][2], int numEmps, int lucky[], int upperBound, int empNbr); 
void printUnluckies(int lucky[], int numEmps); 

void main(void) 
{ 
 const int arraySize=100; 
 double sal[arraySize][2]; 
 int lucky[arraySize] = {0}; 
 int numEmps; 
 
 /* Read the actual number of employees in the company */ 
cout << "\n Please enter the total number of employees in your company: ";
cin >> numEmps;
cout << '\n';

/* Read the gross salaries of the employees into the array 'sal' */ 
getInput(sal, numEmps); 

/* Calculate net salaries of the employees and store them in the array */ 
cout << "\n\n Calculating the net salaries...";
calcNetSal(sal, numEmps); 

/* Find the unlucky employees */ 
cout << "\n\n Locating the unlucky employees ... "; 
findUnluckies(sal, numEmps, lucky);

 /* Print the unlucky employee numbers */ 
cout << "\n\n Printing the unlucky employees ... "; 
printUnluckies(lucky, numEmps); 

}

void getinput(double sal[][2], int numEmps) 
{ 
    for (int i = 0; i < numEmps; i++) //Note that this numEmps is local to this function 
    {
        cout << "\n Please enter the gross salary for employee no " << i << ":";
        cin >> sal[i][0]; // Store the gross salary for each employee 
    }
}

void calcNetSal(double sal[][2], int numEmps) 
{ 
    for (int i = 0; i < numEmps; i++) //Note that this numEmps is local to this function
    {
        if(sal[i][0] >= 0 && sal[i][0] <= 5000) 
        {
            /* There is no tax deduction */ 
            sal[i][1] = sal[i][0]; 
        }
        else if(sal[i][0] >= 5001 && sal[i][0] <= 10000) 
        { 
            /* Tax deduction is 5% */ 
            sal[i][1] = sal[i][0] - (.05 * sal[i][0]); 
        } 
        else if (sal[i][0] >= 10001 && sal[i][0] <= 20000) 
        { 
            /* Tax deduction is 10% */ 
            sal[i][1] = sal[i][0] - (.10 * sal[i][0]); 
        } 
        else 
        {
            /* Tax deduction is 15% */
            sal[i][1] = sal[i][0] - (.15 * sal[i][0]); 
        }
        
    }
}

void findUnluckies(double sal[][2], int numEmps, int lucky[]) 
{ 
 for (int i = 0; i< numEmps; i++) //Note that this numEmps is local to this function 
 {
    if(sal[i][0] >= 5001 && sal[i][0] <= 10000)
    {
        markIfUnlucky(sal, numEmps, lucky, 5001, i);
    }
    else if (sal[i][0] >= 10001 && sal[i][0] <= 20000) 
    { 
        markIfUnlucky(sal, numEmps, lucky, 10001, i); 
    } 
    else if (sal[i][0] >= 20001) 
    { 
        markIfUnlucky(sal, numEmps, lucky, 20001, i); 
    }
 } 

}

void markIfUnlucky(double sal[][2], int numEmps, int lucky[], int upperBound, int empNbr)
{ 
 for (int i = 0; i < numEmps; i++) 
 { 
 /* 
 See the if the condition below, it will mark the employee 
 unlucky even if an employee in the higher tax bracket is getting 
 the same amount of net salary as that of a person in the lower 
 tax bracket
 */
    if (sal[i][0] < upperBound && sal[i][1] >= sal[empNbr][1]) 
    {
        lucky[empNbr] = 1; //Employee marked as unlucky 
        break;
    }
 }

}

void printUnluckies(int lucky[], int numEmps) 
{
    for (int i = 0; i < numEmps; i++) 
    {
        if(lucky[i] == 1) 
        {
            cout <<"\n Employee No.: " << i; 
        }

    }

}

 
