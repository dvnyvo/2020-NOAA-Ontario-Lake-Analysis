#include <stdio.h>
#define size 366
#define lakes 6
#define summer 94
#define winter 90
FILE* file;


double average(double array[size], int sizes); //q1 avg of each lake
double average_172_265(double array_editing[size]); //q5 avg of the lake in summer day 172 to 265
double average_winter(double array_editing[winter]);
void compare(double var, double avg); //q2 comparing each lake avg with total avg
double wday(double arr[size]); //highest value of array_editing..
double cday(double arr[size]); //lowest value of array
int date(double lake[size], double temp); // For loop to find (i) that matches with temp and gives it to day_to_date_leap
int day_to_date_leap(int i); //q3 finds/prints date given day(i)

int main(void)
{
	int year[size], day[size];
	double sup[size], mic[size], hur[size], eri[size], ont[size], stc[size];
	file=fopen("data.txt", "r");

	for(int i=0; i<size; i++)
	{
		fscanf(file, "%d", &year[i]);
		fscanf(file, "%d", &day[i]);
		fscanf(file, "%lf", &sup[i]);
		fscanf(file, "%lf", &mic[i]);
		fscanf(file, "%lf", &hur[i]);
		fscanf(file, "%lf", &eri[i]);
		fscanf(file, "%lf", &ont[i]);
		fscanf(file, "%lf", &stc[i]);
	}

	double avgs[lakes], avgt;
	//															QUESTION 1

	printf("\033[10;33mQuestion 1 \033[0m\n");
	avgs[0] = average(sup, size);
	printf("Average temp for lake Sup. is: %.2f degrees C\n", avgs[0]);
	avgt+=avgs[0];
	avgs[1] = average(mic, size);
	printf("Average temp for lake Mich. is: %.2f degrees C\n", avgs[1]);
	avgt+=avgs[1];
	avgs[2] = average(hur, size);
	printf("Average temp for lake Huron is: %.2f degrees C\n", avgs[2]);
	avgt+=avgs[2];
	avgs[3] = average(eri, size);
	printf("Average temp for lake Erie is: %.2f degrees C\n", avgs[3]);
	avgt+=avgs[3];
	avgs[4] = average(ont, size);
	printf("Average temp for lake Ont. is: %.2f degrees C\n", avgs[4]);
	avgt+=avgs[4];
	avgs[5] = average(stc, size);
	printf("Average temp for lake St.Clr is: %.2f degrees C\n", avgs[5]);
	avgt+=avgs[5];
    printf("Average temp for all 6 lakes is: %.2f degrees C\n", avgt/lakes);
	//															QUESTION 2

	printf("\033[10;33mQuestion 2 \033[0m\n");

	double tempss=avgs[0];
	for(int i=0; i<lakes; i++){
		if(avgs[i]<tempss)
			tempss = avgs[i];	
	}
	printf("\nThe \033[10;34mcoldest\033[10;0m lake on average is Lake ");
	if(tempss == avgs[0])
	{
		printf("Superior with a temperature of %.2f °C.\n", avgs[0]);
	}
	if(tempss == avgs[1])
	{
		printf("Michigan with a temperature of %.2f °C.\n", avgs[1]);
	}
	if(tempss == avgs[2])
	{
		printf("Huron with a temperature of %.2f °C.\n", avgs[2]);
	}
	if(tempss == avgs[3])
	{
		printf("Erie with a temperature of %.2f °C.\n", avgs[3]);
	}
	if(tempss == avgs[4])
	{
		printf("Ontario with a temperature of %.2f °C.\n", avgs[4]);
	}

	if(tempss == avgs[5])
	{
		printf("St. Clair with a temperature of %.2f °C.\n", avgs[5]);
	}
	
	double temps=avgs[0];
	for(int i=0; i<lakes; i++){
		if(avgs[i]>temps)
			temps = avgs[i];	
	}
	printf("\nThe \033[10;31mwarmest\033[10;0m lake on average is Lake ");
	if(temps == avgs[0])
	{
		printf("Superior with a temperature of %.2f .\n", avgs[0]);
	}
	if(temps == avgs[1])
	{
		printf("Michigan with a temperature of %.2f °C.\n", avgs[1]);
	}
	if(temps == avgs[2])
	{
		printf("Huron with a temperature of %.2f °C °C.\n", avgs[2]);
	}
	if(temps == avgs[3])
	{
		printf("Erie with a temperature of %.2f °c.\n", avgs[3]);
	}
	if(temps == avgs[4])
	{
		printf("Ontario with a temperature of %.2f °C.\n", avgs[4]);
	}

	if(temps == avgs[5])
	{
		printf("St. Clair with a temperature of %.2f °C.\n", avgs[5]);
	}

	printf("\nThe temperature of Lake Superior is ");
	compare(avgs[0], avgt);
	printf("\nThe temperature of Lake Michigan is ");
	compare(avgs[1], avgt);
	printf("\nThe temperature of Lake Huron is ");
	compare(avgs[2], avgt);
	printf("\nThe temperature of Lake Erie is ");
	compare(avgs[3], avgt);
	printf("\nThe temperature of Lake Ontario is ");
	compare(avgs[4], avgt);
	printf("\nThe temperature of Lake St. Clair is ");
	compare(avgs[5], avgt);

	//															QUESTION 3

	printf("\n\n\033[10;33mQuestion 3 \033[0m\n\n");
	double twarm[lakes], tcold[lakes];
	// lake sup
	printf("\nLake Superior's \033[1;31mwarmest\033[0m days is %.2f degrees C on: \n", wday(sup));
	date(sup, wday(sup));
	printf("\nLake Superior's \033[1;34mcoldest\033[0m days is %.2f degrees C on: \n", cday(sup));
	date(sup, cday(sup));
	twarm[0]=wday(sup);
	tcold[0]=cday(sup);
	
	// lake mich
	printf("\nLake Michigan's \033[1;31mwarmest\033[0m days is %.2f degrees C on: \n", wday(mic));
	date(mic, wday(mic));
	printf("\nLake Michigan's \033[1;34mcoldest\033[0m days is %.2f degrees C on: \n", cday(mic));
	date(mic, cday(mic));
	twarm[1]=wday(mic);
	tcold[1]=cday(mic);

	// lake huron
	printf("\nLake Huron's \033[1;31mwarmest\033[0m days is %.2f degrees C on: \n", wday(hur));
	date(hur, wday(hur));
	printf("\nLake Huron's \033[1;34mcoldest\033[0m days is %.2f degrees C on: \n", cday(hur));
	date(hur, cday(hur));
	twarm[2]=wday(hur);
	tcold[2]=cday(hur);

	// lake erie
	printf("\nLake Erie's \033[1;31mwarmest\033[0m days is %.2f degrees C on: \n", wday(eri));
	date(eri, wday(eri));
	printf("\nLake Erie's \033[1;34mcoldest\033[0m days is %.2f degrees C on: \n", cday(eri));
	date(eri, cday(eri));
	twarm[3]=wday(eri);
	tcold[3]=cday(eri);

	// lake ont
	printf("\nLake Ontario's \033[1;31mwarmest\033[0m days is %.2f degrees C on: \n", wday(ont));
	date(ont, wday(ont));
	printf("\nLake Ontario's \033[1;34mcoldest\033[0m days is %.2f degrees C on: \n", cday(ont));
	date(ont, cday(ont));
	twarm[4]=wday(ont);
	tcold[4]=cday(ont);

	// lake st.clr
	printf("\nLake Saint Clair's \033[1;31mwarmest\033[0m days is %.2f degrees C on: \n", wday(stc));
	date(stc, wday(stc));
	printf("\nLake Saint Clair's \033[1;34mcoldest\033[0m days is %.2f degrees C on: \n", cday(stc));
	date(stc, cday(stc));
	twarm[5]=wday(stc);
	tcold[5]=cday(stc);

	
	//															QUESTION 4

	printf("\n\n\033[10;33mQuestion 4 \033[0m\n\n");
	double warmm=twarm[0];
	char *lakename;
	for(int i=0; i<lakes; i++)
	{
		if(twarm[i]>warmm)
		{
			warmm=twarm[i];
			
		}
	}
			printf("The \033[1;31mwarmest\033[0m temperature of all 6 lakes is ");
            if(warmm == twarm[0]){
            lakename = "Superior";
            printf("%.2f degrees C in Lake %s on day(s):\n", warmm, lakename);
            date(sup, warmm);
            
            }
            if(warmm == twarm[1]){
            lakename = "Michigan";
            printf("%.2f degrees C in Lake %s on day(s):\n", warmm, lakename);
            date(mic, warmm);
            
            }
            if(warmm == twarm[2]){
            lakename = "Huron";
            printf("%.2f degrees C in Lake %s on day(s):\n", warmm, lakename);
            date(hur, warmm);
            
            }
            if(warmm == twarm[3]){
            lakename = "Erie";
            printf("%.2f degrees C in Lake %s on day(s):\n", warmm, lakename);
            date(eri, warmm);
            }
            
            if(warmm == twarm[4]){
            lakename = "Ontario";
            printf("%.2f degrees C in Lake %s on day(s):\n", warmm, lakename);
            date(ont, warmm);
            }
            
            if(warmm == twarm[5]){
            lakename = "Saint Clair";
            printf("%.2f degrees C in Lake %s on day(s):\n", warmm, lakename);
            date(stc, warmm);
            }
	


	double coldd=tcold[0];
	for(int i=0; i<lakes; i++)
	{
		if(tcold[i]<coldd)
		{
			coldd=tcold[i];
		}
	}
			printf("The \033[1;34mcoldest\033[0m temperature of all 6 lakes is ");
            if(coldd == tcold[0]){
            lakename = "Superior";
            printf("%.2f degrees C in Lake %s on day(s):\n", coldd, lakename);
            date(sup, coldd);
            }
            
            if(coldd == tcold[1]){
            lakename = "Michigan";
            printf("%.2f degrees C in Lake %s on day(s):\n", coldd, lakename);
            date(mic, coldd);
            }
            
            if(coldd == tcold[2]){
            lakename = "Huron";
            printf("%.2f degrees C in Lake %s on day(s):\n", coldd, lakename);
            date(hur, coldd);
            }
            
            if(coldd == tcold[3]){
            lakename = "Erie";
            printf("%.2f degrees C in Lake %s on day(s):\n", coldd, lakename);
            date(eri, coldd);
            }
            
            if(coldd == tcold[4]){
            lakename = "Ontario";
            printf("%.2f degrees C in Lake %s on day(s):\n", coldd, lakename);
            date(ont, coldd);
            }
            
            if(coldd == tcold[5]){
            lakename = "Saint Clair";
            printf("%.2f degrees C in Lake %s on day(s):\n", coldd, lakename);
            date(stc, coldd);
            }
	
//                              								        QUESTION 5
	printf("\n\n\033[10;33mQuestion 5 \033[0m\n\n");
	double aavgs[lakes], temp;
	aavgs[0] = average_172_265(sup);
	aavgs[1] = average_172_265(mic);
	aavgs[2] = average_172_265(hur);
	aavgs[3] = average_172_265(eri);
	aavgs[4] = average_172_265(ont);
	aavgs[5] = average_172_265(stc);
	
	
	printf("The average summer temperature in degrees celsius for each lake from warmest to coldest is: \n");
	printf("\033[4;31m| 2020  |     Lakes    |\033[0m\n");
	for(int i=0;i<lakes;i++) //position
	{
    	for(int j=i+1; j<lakes; j++) //for each lake
    	{
    		if(aavgs[i]<aavgs[j])
    		{
    			temp=aavgs[i];
    			aavgs[i] = aavgs[j];
    			aavgs[j] = temp;
    		}
    	}
				if(aavgs[i] == average_172_265(sup)){
					lakename = "Superior";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
                if(aavgs[i] == average_172_265(mic)){
					lakename = "Michigan";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
                if(aavgs[i] == average_172_265(hur)){
					lakename = "Huron";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
                if(aavgs[i] == average_172_265(eri)){
					lakename = "Erie";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
                if(aavgs[i] == average_172_265(ont)){
					lakename = "Ontario";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
                if(aavgs[i] == average_172_265(stc)){
					lakename = "Saint Clair";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
    			
	}	

	// 															Q6
	printf("\n\n\033[10;33mQuestion 6 \033[0m\n\n");
	
	
	aavgs[0] = average_winter(sup);
	aavgs[1] = average_winter(mic);
	aavgs[2] = average_winter(hur);
	aavgs[3] = average_winter(eri);
	aavgs[4] = average_winter(ont);
	aavgs[5] = average_winter(stc);
	
	
	printf("The average winter temperature in degrees celsius for each lake from warmest to coldest is: \n");
	printf("\033[4;34m| 2020 |     Lakes    |\033[0m\n");
	for(int i=0;i<lakes;i++) //position
	{
    	for(int j=i+1; j<lakes; j++) //for each lake
    	{
    		if(aavgs[i]<aavgs[j])
    		{
    			temp=aavgs[i];
    			aavgs[i] = aavgs[j];
    			aavgs[j] = temp;
    		}
    	}
				if(aavgs[i] == average_winter(sup)){
					lakename = "Superior";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
                if(aavgs[i] == average_winter(mic)){
					lakename = "Michigan";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
                if(aavgs[i] == average_winter(hur)){
					lakename = "Huron";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
                if(aavgs[i] == average_winter(eri)){
					lakename = "Erie";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
                if(aavgs[i] == average_winter(ont)){
					lakename = "Ontario";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
                if(aavgs[i] == average_winter(stc)){
					lakename = "Saint Clair";
					printf("\033[4m| %.2f | %12s |\033[0m\n", aavgs[i], lakename);
                }
    			
	}	
	
	
	//                                     Q7
	
	printf("\n\nQuestion 7");
	
	printf("\nThere are : %d days that you can swim in Lake Superior", swim(sup));
	printf("\nThere are : %d days that you can swim in Lake Michigan", swim(mic));
	printf("\nThere are : %d days that you can swim in Lake Huron", swim(hur));
	printf("\nThere are : %d days that you can swim in Lake Erie", swim(eri));
	printf("\nThere are : %d days that you can swim in Lake Ontario", swim(ont));
	printf("\nThere are : %d days that you can swim in Lake St. Clair", swim(stc));
	
	//                                     Q8
	printf("\n\nQuestion 8");
	
	printf("\nLake Superior is frozen for %d days in 2020", frz(sup));
	printf("\nLake Michigan is frozen for %d days in 2020", frz(mic));
	printf("\nLake Huron is frozen for %d days in 2020", frz(hur));
	printf("\nLake Erie is frozen for %d days in 2020", frz(eri));
	printf("\nLake Ontario is frozen for %d days in 2020", frz(ont));
	printf("\nLake St. Clair is frozen for %d days in 2020", frz(stc));
	

	//																				QUESTION 9
	
	printf("\n\033[10;33mQuestion 9 \033[0m\n");
    int year19[size], day19[size];
    double sup19[size], mic19[size], hur19[size], eri19[size], ont19[size], stc19[size];
    FILE *d2019=fopen("data19.txt", "r");
    /*loop distributes values from data set to appropriate arrays*/
    for(int i=0; i<size; i++)
    {
        fscanf(d2019, "%d", &year19[i]);
        fscanf(d2019, "%d", &day19[i]);
        fscanf(d2019, "%lf", &sup19[i]);
        fscanf(d2019, "%lf", &mic19[i]);
        fscanf(d2019, "%lf", &hur19[i]);
        fscanf(d2019, "%lf", &eri19[i]);
        fscanf(d2019, "%lf", &ont19[i]);
        fscanf(d2019, "%lf", &stc19[i]);
    }
    printf("\nAverage Temperatures:\n");
    printf("\n\033[4m                2019      2020|\n");
    double avgs19[lakes];
    int size19=365;
  	double avgt19;

	
	avgs19[0] = average(sup19, size19);
	printf("lake Sup. \t%.2f\t%6.2f|\n", avgs19[0], avgs[0]);
	avgt19 += avgs19[0];
	avgs19[1] = average(mic19, size19);
	printf("lake Mich. \t%.2f\t%6.2f|\n", avgs19[1], avgs[1]);
	avgt19 += avgs19[1];
	avgs19[2] = average(hur19, size19);
	printf("lake Huron \t%.2f\t%6.2f|\n", avgs19[2], avgs[2]);
	avgt19 += avgs19[2];
	avgs19[3] = average(eri19, size19);
	printf("lake Erie \t%.2f\t%6.2f|\n", avgs19[3], avgs[3]);
	avgt19 += avgs19[3];
	avgs19[4] = average(ont19, size19);
	printf("lake Ont. \t%.2f\t%6.2f|\n", avgs19[4], avgs[4]);
	avgt19 += avgs19[4];
	avgs19[5] = average(stc19, size19);
	printf("lake St.Clr \t%.2f\t%6.2f|\n", avgs19[5], avgs[5]);
	avgt19 += avgs19[5];
    printf("all 6 lakes \t%.2f\t%6.2f|\033[0m\n", avgt19/lakes, avgs[6]);															
	return 0;
}

// Average of a lake array
double average(double array[size], int sizes)
{
	double avg = 0;
	int i;
	for(i=0; i<size; i++)
	{
		avg += array[i];
	}
	avg /= sizes;
	return(avg);
}

// Comparing a average of a lake with total average
void compare(double var, double avg)
{	
	avg/=lakes;
	if(var<=avg)
	printf("below average.");
	else if(var>avg)
	printf("above average.");
}

// Getting the date given lake array and temperature
int date(double lake[size], double temp)
{
	int i;
	for(i=0; i<size; i++)
	{
		if(lake[i] == temp)
		{
			day_to_date_leap(i);
		}
	}
	
}

/*wday takes an array and returns the highest value*/
double wday(double arr[size])
{
	double warmest=arr[0];
	int i;
	for(i=0; i<size; i++)
	{
		if(arr[i]>warmest)
		warmest = arr[i];
	}
	
return(warmest);
}

/*cday takes an array and returns the lowest value*/
double cday(double arr[size])
{
	double coldest=arr[0];
	int i;
	for(i=0; i<size; i++)
	{
		if(arr[i]<coldest)
		coldest = arr[i];
	}
	
return(coldest);
}

// finds the month based on the days(i)
int day_to_date_leap(int i)
{
if((i>=1)&&(i<31))
{
printf("%d/1\n", i+1);
}
else if((i>=31)&&(i<=59))
{
printf("%d/2\n", i-30);
}
else if((i>=60)&&(i<=91))
{
printf("%d/3\n", i-59);
}	
else if((i>=92)&&(i<=121))
{
printf("%d/4\n", i-90);
}
else if((i>=122)&&(i<=152))
{
printf("%d/5\n", i-120);
}
else if((i>=153)&&(i<=182))
{
printf("%d/'6'\n", i-151);
}	
else if((i>=183)&&(i<=213))
{
printf("%d/7\n", i-181);
}
else if((i>=214)&&(i<=244))
{
printf("%d/8\n", i-212);
}	
else if((i>=245)&&(i<=274))
{
printf("%d/9\n", i-243);
}
else if((i>=275)&&(i<=305))
{
printf("%d/10\n", i-273);
}
else if((i>306)&&(i<=335))
{
printf("%d/11\n", i-304);
}
else if((i>=336)&&(i<=366))
{
printf("%d/12", i-334);
}	
}

// calculates the average of the lakes during summer day 172 to day 265
double average_172_265(double array[summer])
{
	double avg = 0;
	int i;
	for(i=171; i<=264; i++)
	{
		avg += array[i];
	}
	avg /= summer;
	return(avg);
}

// calculates the avg of lakes in winter days
double average_winter(double array[winter])
{
	double avg = 0;
	int i;
	for(i=0; i<=78; i++)
	{
		avg += array[i];
	}
	for(i=354; i<=364; i++)
	{
		avg += array[i];
	}
	avg /= winter;
	return(avg);
}

// amount of days that is swimmable 
int swim(double lakee[size])
{
	int days=0, i; 
	for (i=0; i<size; ++i)
	{
		if (lakee[i] > 20)
		{
			days++;
		} 
	}
	return days;		 
}		 

// amount of days the lake is frozen
int frz(double lakee[size])
{
	int frzdays=0, i; 
	for (i=0; i<size; ++i)
	{
		if (lakee[i] < 0)
		{
			frzdays++;
		} 
	}
	return frzdays;	
}