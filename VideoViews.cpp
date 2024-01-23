/*My name is Isis Gonsalves and my student ID number is 816026980. 

ASSIGNMENT 3 for COMP 1601

I believe my program is working efficiently and performs all the required tasks. 

This program will open an input file (View.txt) and determine certain statistics.

Inputs from file: -URL of the video
				  -Start date
				  -Views on that day
				  -Likes on that day
				  -Dislikes on that day
		
		
To display in Output File (stats): -First date video was posted
								   -Last date of analysis
								   -Amount of days being processed
								   -Total views, likes and dislikes 
								   -Average views, likes and dislikes 
								   -Dates with Most and second most likes
								   -Dates with Most and second most views

To display in Output File (views): - Dates with views more than 5000

To display in Output File (dislikes): - Dates with more dislikes than likes on the video
									  - Amount of likes and dislikes


*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <windows.h>

using namespace std;


void showVideo (string URL) {
	char cURL [50];
	int i;

	for (i = 0; i < URL.length(); i=i+1){
    	cURL[i] = URL[i];
	}

	cURL[URL.length()] = '\0';
    
    ShellExecute(NULL, "open", cURL, NULL, NULL, SW_SHOWNORMAL);
}



int main() {
	
	ifstream input_data; //declare input file
	ofstream output_stats; //declare output file
	ofstream output_views; //declare output file
	ofstream output_dislikes; //declare output file
	
	string url_video; //declare url of the video
	
	int first_day; //first day video was posted
	int first_month; //first month video was posted
	int first_year; //first year video was posted
	
	int start_day; //first day to start incrementing from
	int start_month; //first month to start incrementing from 
	int start_year; //first year to start incrementing from
	
	int end_day; //last day of analysis
	int end_month;//last month of analysis
	int end_year;//last year of analysis
	
	int days_permonth=0; //amount of days in any month
	int days_permonth2=0; // amount of days in month 2
	
	int views;//views read from input file
	int likes;//likes read from input file
	int dislikes;//dislikes read from input file
	
	int num_of_days=0; //to track and update number of days 
	int total_views=0; //to calculate total views
	int total_likes=0; //to calculate total likes
	int total_dislikes=0; //to calculate total dislikes
	
	int diff_likes=0; //to calculate difference in likes and dislikes

	int max_likes1 = INT_MIN; //to store the highest amount of likes
	int max_daylikesnum1=0;
	int max_day1=0; //to store day with the highest amount of likes
	int max_month1=0; //to store month with the highest amount of likes
	int max_year1=0; //to store year with the highest amount of likes
	
	
	int max_likes2 = INT_MIN; //to store the second highest amount of likes
	int max_daylikesnum2=0;
	int max_day2 =0; //to store day with the second highest amount of likes
	int max_month2 =0; //to store month with the second highest amount of likes
	int max_year2 =0; //to store year with the second highest amount of likes;
	
	int max_views1 = INT_MIN; //to store the highest amount of views
	int max_daynum1 = 0;
	int max_dayviews1=0; //to store day with the highest amount of views
	int max_monthviews1=0; //to store month with the highest amount of views
	int max_yearviews1=0; //to store year with the highest amount of views
	
	int max_views2 = INT_MIN; //to store the second highest amount of views
	int max_daynum2 = 0;
	int max_dayviews2=0; //to store day with the second highest amount of views
	int max_monthviews2=0;//to store month with the second highest amount of views
	int max_yearviews2=0;//to store year with the second highest amount of views
	
	float avg_views=0;//to store average views
	float avg_likes=0;//to store average likes
	float avg_dislikes=0;//to store average dislikes
	
	char option;//to store the option Yes or No ( y / n) from the user
	
	//opening files to be used
	
	input_data.open("Views.txt");
	output_stats.open("VideoStats.txt");
	output_views.open("Views_Greater_5000.txt");
	output_dislikes.open("Likes_LessThan_Dislikes.txt");
	
	//displaying header for this file
	
	output_views <<"More than 5000 views"<<endl;
	output_views <<"Dates			Views"<<endl;
	output_views <<"-----------------------------"<<endl;
	
	
	//displaying header for this file
	
	output_dislikes <<"More Dislikes than Likes"<<endl;
	output_dislikes <<"Dates			Likes		Dislikes	Difference"<<endl;
	output_dislikes <<"-------------------------------------------------------------------"<<endl;
	
	//error message incase file cannot be found or opened.
	
	if (!input_data.is_open()) {
		cout << "ERROR: File cannot be found...Try again";
		return 0;
	}
	
	//read data from the iput file first to check condition of views
	
	input_data >> url_video;
	input_data >> first_day;
	input_data >> first_month;
	input_data >> first_year;
	input_data >> views;
	
	
	start_day=first_day; //equated first day from file to start day to keep first day constant and increment start day only.
	start_month=first_month;//equated first month from file to start month to keep first month constant and increment start month only.
	start_year=first_year;//equated first year from file to start year to keep first year constant and increment start year only.


	while (views!=-1){
		
		input_data >> likes;
		input_data >> dislikes;
		
		num_of_days=num_of_days + 1; //Part b (i): to update the days being processed 
		total_views=total_views + views; //Part b (ii): to update number of views one day at a time
		total_likes=total_likes + likes; //Part b (ii): to update number of likes one day at a time
		total_dislikes=total_dislikes + dislikes; //Part b (ii): to update number of dislikes one day at a time
		
		//to check if year is a leap year or not, to determine amount of days in February.
		
			if (start_year % 4 == 0) {
				
		        if (start_year % 100 == 0){
		        	
		            if (start_year % 400 == 0)
		            
		                days_permonth2= 29;
		            else
		                days_permonth2= 28;
		        }
		        else
	           		 days_permonth2= 29;
		    }
		    else
		    	days_permonth2= 28;
		    
		// determining how much days in each month based on the number month 
		//1 = January...Therefore month==1...so days_permonth=31     		
		if((start_month == 1)|| (start_month == 3 )|| (start_month == 5 )||( start_month == 7 )|| (start_month == 8 )|| (start_month == 10) || (start_month==12))
			
			days_permonth= 31;
			
		else if (start_month==2)
			
			days_permonth= days_permonth2;
		
		else
		
			days_permonth=30;
		
		//to set start day back to 1 and increment the month at the end of the month.
		if (start_day > days_permonth){
			
			start_month=start_month+1;
			start_day =1;
		}
		
		//to keep track of my end date after each date/day processed before incrementing my start date at the end of loop.
		end_day = start_day; 
		end_month= start_month;
		end_year=start_year;
		
		
		//Part b (iii): to determine if there are more dislikes than likes on this day.
		if (likes < dislikes ){
			
			diff_likes=dislikes-likes; //calculate difference
			
			output_dislikes <<start_day<<"."<<start_month<<"."<<start_year<<"		"<<likes<<"		"<<dislikes<<"		"<<diff_likes<<endl;
	
			}
		
		 
		//Part b (iv): to update the date with the most amount of likes and the date with the second highest.
		
		//illustration for some understanding 
		//likes		max2	max1
		//			0		0
		//20		0		20
		//40		20		40
		//60		40		60
		//45		45		60
		
		if(likes> max_likes1){
			max_likes2= max_likes1; //set second highest to the value of highest
			max_daylikesnum2 = max_daylikesnum1;
			max_day2= max_day1;
			max_month2= max_month1;
			max_year2= max_year1; 

			max_likes1= likes; //set highest to value of likes 
			max_daylikesnum1= num_of_days;
			max_day1= start_day;
			max_month1= start_month;
			max_year1= start_year; 
		}
		
		else if(likes> max_likes2){
			max_likes2= likes; //set second highest to value of likes
			max_daylikesnum2=num_of_days;
			max_day2= start_day;
			max_month2= start_month;
			max_year2= start_year;  
		}
		
		//to update the date with the most amount of views and the date with the second highest.
		
		if(views>= max_views1){
			max_views2= max_views1; //set second highest to the value of highest
			max_daynum2 = max_daynum1;
			max_dayviews2= max_dayviews1;
			max_monthviews2= max_monthviews1;
			max_yearviews2= max_yearviews1; 

			max_views1= views; //set highest to value of views
			max_daynum1= num_of_days;
			max_dayviews1= start_day;
			max_monthviews1= start_month;
			max_yearviews1= start_year; 
		}
		
		else if(views>= max_views2){
			max_views2= views; //set second highest to value of views
			max_daynum2=num_of_days;
			max_dayviews2= start_day;
			max_monthviews2= start_month;
			max_yearviews2= start_year;  
			max_daynum2=num_of_days;
		}
	
			
		//Part b (v): to determine if there are more than 5000 views on this day.	
		
		if (views > 5000){
			
			output_views <<start_day<<"."<<start_month<<"."<<start_year<<"		"<<views<<endl;
		}
		
		
		//To increment year after December 31
		
		if ((start_month == 12)&& (start_day==31)){
			
			start_year=start_year+1;
			start_month =0;
		}
		
		//To increment day 
		 
		if (start_day <= days_permonth)
			start_day= start_day+1;
	
		//Read in the next value 
		
		input_data >> views;
		
	}
	
	
	//Part c (iv): Average number of views, likes and dislikes per day.
	
	avg_views= total_views*1.0/num_of_days;
	avg_likes= total_likes*1.0/num_of_days;
	avg_dislikes= total_dislikes*1.0/num_of_days;
	
	
	//Part c: displaying statistics to output txt file (VideoStats.txt). 
	
	output_stats << "Start date: " << first_day<<"\t"<<first_month<<"\t"<<first_year<<endl;
	output_stats << "End Date:   " <<end_day<<"\t"<<end_month<<"\t"<<end_year<<endl;
	output_stats << "Total Days being processed: " <<num_of_days<<endl<<endl<<endl;
	output_stats << "\tViews\t\tLikes\t\tDislikes"<<endl;
	output_stats << "\t-----------------------------------------"<<endl;	
	output_stats << "Total:  " <<total_views<<"		"<<total_likes<<"		"<<total_dislikes<<endl<<endl;
	output_stats << "Average: " <<avg_views<<"	"<<avg_likes<<"		"<<avg_dislikes<<endl<<endl<<endl;
	
	output_stats <<"Most likes: "<<max_likes1<<"	    Day: "<<max_daylikesnum1<<" 		Date: "<<max_day1<<"."<<max_month1<<"."<<max_year1<<endl;
	output_stats <<"Second most likes: " <<max_likes2<<"	    Day: "<<max_daylikesnum2<<"		Date: "<<max_day2<<"."<<max_month2<<"."<<max_year2<<endl<<endl<<endl;
	
	output_stats <<"Most Views: "<<max_views1<<"		Day: " <<max_daynum1<< "        Date: "<<max_dayviews1<<"."<<max_monthviews1<<"."<<max_yearviews1<<endl;
    output_stats <<"Second most views: " <<max_views2<<"		Day: " <<max_daynum2 <<"		Date: "<<max_dayviews2<<"."<<max_monthviews2<<"."<<max_yearviews2<<endl;
    
    
    //Part d: Asking the user if they would like to view the video.
    
    cout<<"Would you like to view the video?: " <<endl;
    cin>>option;
    
    if((option== 'Y')||(option == 'y'))
    	showVideo(url_video);
    
    
    //Part e: Closing message and closing all open files.
    
    cout<<"\n\nThank you! Be Covid Safe & Social Distance :) ";
	
	input_data.close(); 
	output_stats.close(); 
	output_views.close(); 
	output_dislikes.close(); 
	
    return 0;
    
}

