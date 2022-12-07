

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define CAR 1
#define TRICYCLE 2
#include <stdlib.h>



struct car_management
{
	int car_number ;
	int car_row ;
	int car_column ;
  int car_type ;
  struct tm *at;
} ;
struct car_management *car[2][10] ;
struct car_management *tricycle[2][10] ;
int parking_information[4][10] ;
int vehicle_counting ;
int car_counting ;
int tricycleCount ;


void display_main_menu( ) ;
void column_change ( struct car_management * ) ;
struct car_management * add ( int, int, int, int ) ;
void car_delete ( struct car_management * ) ;
void getting_free_column_row ( int, int * ) ;
void getrcbyinfo ( int, int, int * ) ;
void view() ;
int running_car_int();
int backward_upward();
int backward_upper();
struct car_management * addonstart ( int, int, int, int ) ;
void car_total_billing(int ,struct tm *ct1,struct tm *ct2);
void get_arrival_time(int);

void column_change ( struct car_management *v )
{
	v -> car_column--;
}

struct tm* datetime()
{



           time_t ts;
        struct tm *ct;


        ts = time(NULL);
        ct = localtime(&ts);


return ct ;

}
int insertrecord(int veh,int car_type,int car_row,int car_column, struct tm *ct )
{
FILE *fptr;
    fptr = fopen("arival.dat", "a");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }

    fprintf(fptr,"\n");
    fprintf(fptr,"%d ",veh);
        fprintf(fptr,"%d ",car_type);
        fprintf(fptr,"%d ",car_row);
        fprintf(fptr,"%d ",car_column);

         fprintf(fptr,"%d/%d/%d  ",
                ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);

   fprintf(fptr,"%d:%d:%d  ",
                ct->tm_hour, ct->tm_min, ct->tm_sec);



        fclose(fptr);
}


int insertrecord2(int veh, struct tm *ct )
{
FILE *fptr;
    fptr = fopen("depart.dat", "a");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }

    fprintf(fptr,"\n");
    fprintf(fptr,"%d ",veh);


         fprintf(fptr,"%d/%d/%d  ",
                ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);

   fprintf(fptr,"%d:%d:%d  ",
                ct->tm_hour, ct->tm_min, ct->tm_sec);



        fclose(fptr);
}
void get_arrival_time(int car_number)
{


    int veh ,car_type,car_row,car_column ;
    int mon,day,year,hour,min,sec;
    int mon2,day2,year2,hour2,min2,sec2;

    int mon1,day1,year1,hour1,min1,sec1;
    int mon3,day3,year3,hour3,min3,sec3;

    FILE *fptr;
    fptr = fopen("arival.dat", "r");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }

 while(!feof(fptr))
 {
     fscanf(fptr,"\n");
     fscanf(fptr,"%d ",&veh);
        fscanf(fptr,"%d ",&car_type);
       fscanf(fptr,"%d ",&car_row);
        fscanf(fptr,"%d ",&car_column);
    fscanf(fptr,"%d/%d/%d  ",
                &day, &mon, &year);

   fscanf(fptr,"%d:%d:%d  ",
                &hour, &min, &sec);

   if(veh == car_number){
     day2 = day;
     mon2 = mon;
     year2 = year;
     hour2 = hour;
     min2 = min;
     sec2 = sec ;
}


 }
 fclose(fptr);



 FILE *fptr1;
    fptr1 = fopen("depart.dat", "r");

    if (fptr1 == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }

 while(!feof(fptr1))
 {
     fscanf(fptr1,"\n");
     fscanf(fptr1,"%d ",&veh);

    fscanf(fptr1,"%d/%d/%d  ",
                &day1, &mon1, &year1);

   fscanf(fptr1,"%d:%d:%d  ",
                &hour1, &min1, &sec1);

   if(veh == car_number){
     day3 = day1;
     mon3 = mon1;
     year3 = year1;
     hour3 = hour1;
     min3 = min1;
     sec3 = sec1 ;
}


 }
 fclose(fptr1);



     int tsec1,tsec2,tsec3;
     tsec1 =  sec3;
      tsec1 += min3*60;
      tsec1 += (hour3*60)*60;
 tsec2 =  sec2;
      tsec2 += min2*60;
      tsec2 += (hour2*60)*60;

   tsec3 = tsec1 - tsec2 ;
   int secnd , minute ,hours;
   int secc , temp1,temp2,temp3,temp4 ;
      secnd = tsec3 % 60 ;
       temp1 = tsec3 - secnd ;
       temp2 = temp1/60 ;
       minute = temp2 % 60 ;
        temp4 = temp2 - minute ;
         hours = temp4 /60 ;

 printf("you have parked your vehicle for %d hours %d minutes %d seconds ",hours,minute,secnd);



}

int randint()
{
    int r ;
    srand(time(NULL));
 r = rand() % 20;
 return r ;
}

void finesheet(int veh,int car_type,int car_row,int car_column, struct tm *ct)
{

FILE *fptr;
    fptr = fopen("finesheet.dat", "a");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }

    fprintf(fptr,"\n");
    fprintf(fptr,"%d ",veh);
        fprintf(fptr,"%d ",car_type);
        fprintf(fptr,"%d ",car_row);
        fprintf(fptr,"%d ",car_column);

         fprintf(fptr,"%d/%d/%d  ",
                ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);

   fprintf(fptr,"%d:%d:%d  ",
                ct->tm_hour, ct->tm_min, ct->tm_sec);
 fprintf(fptr,"%d ",50);


        fclose(fptr);


}

int historyrec(int val)
{
  FILE *fptr;
if(val==1)
fptr = fopen("arival.dat", "r");
else if(val ==2)
fptr = fopen("depart.dat", "r");
else if(val==3)
  fptr = fopen("finesheet.dat", "r");
else
{printf("invalid input");
return 0 ;}
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }
 char strg;
 strg = getc(fptr);
while(!feof(fptr))
{
	printf("%c",strg);
  strg = getc(fptr);
}
return 0 ;
}

int backward_upward()
{
    int r,c ;

  FILE *fptr;
    fptr = fopen("backupward.dat", "w");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }


  for(r=0;r<4;r++)
   for(c=0;c<10;c++)
    {

    fprintf(fptr,"\n");
    fprintf(fptr,"%d ",parking_information[r][c]);

        fprintf(fptr,"%d ",r);
        fprintf(fptr,"%d ",c);

         fprintf(fptr,"%d ",vehicle_counting);
         fprintf(fptr,"%d ",car_counting);
         fprintf(fptr,"%d ",tricycleCount);

    }
        fclose(fptr);
}

int backupr()
{
     int r,c ;
    int park[4][10];
  FILE *fptr;
    fptr = fopen("backingupward.dat", "r");
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }

 int rr ,cc ,veh,carrr,scoot,numb;
  for(r=0;r<4;r++)
   for(c=0;c<10;c++)
    {

    fscanf(fptr,"\n");
    fscanf(fptr,"%d ",&park[r][c]);
   numb = park[r][c];

        fscanf(fptr,"%d ",&rr);
        fscanf(fptr,"%d ",&cc);

         fscanf(fptr,"%d ",&veh);
         fscanf(fptr,"%d ",&carrr);
         fscanf(fptr,"%d ",&scoot);

 if(numb!=0)
 {

        	  if ( r == 0 || r == 1 )
     car[r][c] = addonstart(1,numb,r,c);
    else
    	tricycle[r][c] = addonstart(2,numb,r,c);
 }
    }
        fclose(fptr);

}
/* adds a data of vehicle */
struct car_management * add ( int t, int car_number, int car_row, int car_column )
{
    struct car_management *v ;
    int r ;

    v = ( struct car_management * ) malloc ( sizeof ( struct car_management ) ) ;

    v -> car_type = t ;
    v -> car_row = car_row ;
    v -> car_column = car_column ;

	  if ( t == CAR )
      car_counting++ ;
    else
    	tricycleCount++ ;

    vehicle_counting++ ;
	  parking_information[car_row][car_column] = car_number ;
     v->at = datetime();
	  insertrecord(car_number,t,car_row,car_column,datetime());
	   backward_upward(t);
	  r = randint();
	  if(r < 5 )
      {
          printf("\a");
          printf("\a");
          finesheet(car_number,t,car_row,car_column,datetime());

      }

    return v ;
}
struct car_management * addonstart ( int t, int car_number, int car_row, int car_column )
{
    struct car_management *v ;
    int r ;

    v = ( struct car_management * ) malloc ( sizeof ( struct car_management ) ) ;

    v -> car_type = t ;
    v -> car_row = car_row ;
    v -> car_column = car_column ;

	  if ( t == CAR )
      car_counting++ ;
    else
    	tricycleCount++ ;

    vehicle_counting++ ;
	  parking_information[car_row][car_column] = car_number ;
    return v ;
}

void car_delete ( struct car_management *v )
{
  int c ;

	parking_information[v -> car_row][v -> car_column] = 0 ;

	if ( v -> car_type == CAR )
    car_counting-- ;
  else
    tricycleCount-- ;

	vehicle_counting-- ;
	backward_upward();
}


void getting_free_column_row ( int car_type, int *arr )
{
  int r, c, fromrow = 0, torow = 2 ;

  if ( car_type == TRICYCLE )
  {
    fromrow += 2 ;
    torow += 2 ;
  }

	for ( r = fromrow ; r < torow ; r++ )
	{
		for ( c = 0 ; c < 10 ; c++ )
		{
			if ( parking_information[r][c] == 0 )
			{
				arr[0] = r ;
				arr[1] = c ;
        return ;
			}
		}
	}

	if ( r == 2 || r == 4 )
	{
   	arr[0] = -1 ;
    arr[1] = -1 ;
  }
}

/* get the row-col position for the vehicle with specified number */
void getrcbyinfo ( int car_type, int car_number, int *arr )
{
  int r, c, fromrow = 0, torow = 2 ;

  if ( car_type == TRICYCLE )
	{
    fromrow += 2 ;
    torow += 2 ;
	}

	for ( r = fromrow ; r < torow ; r++ )
	{
		for ( c = 0 ; c < 10 ; c++ )
		{
			if ( parking_information[r][c] == car_number )
			{
				arr[0] = r ;
				arr[1] = c ;
        return ;
			}
		}
	}

	if ( r == 2 || r == 4 )
	{
		arr[0] = -1 ;
		arr[1] = -1 ;
	}
}


void display_main_menu( )
{
  int r, c ;

  printf ( "Cars ->\n" ) ;

  for ( r = 0 ; r < 4 ; r++ )
  {
    if ( r == 2 )
		  printf ( "tricycle ->\n" ) ;

    for ( c = 0 ; c < 10 ; c++ )
      printf ( "%d\t", parking_information[r][c] ) ;
    printf ( "\n" ) ;
	}
}

int main( )
{
	int choice, car_type, number, car_row = 0, car_column = 0 ;
	int i, tarr[2] ;
	int finish = 1 ;
	backupr();



  system ( "cls" ) ;


	while ( finish )
	{
    system ( "cls" ) ;

		printf ( "\n  WELCOME TO MY PARKING SYSTEM PROJECT \n\n\n" ) ;
		printf ( "1. Arrival of a vehicle\n" ) ;
		printf ( "2. Total no. of vehicles parked\n" ) ;
		printf ( "3. Total no. of cars parked\n" ) ;
		printf ( "4. Total no. of tricycle parked\n" ) ;
		printf ( "5. Display order in which vehicles are parked\n" ) ;
		printf ( "6. Departure of vehicle\n" ) ;
		printf ( "7. Check History\n" ) ;
		printf ( "8. Exit\n" ) ;

		scanf ( "%d", &choice ) ;

		switch ( choice )
		{
			case 1 :
          system ( "cls" ) ;
				  printf ( "\nAdd: \n" ) ;

          car_type = 0 ;


          while ( car_type != CAR && car_type != TRICYCLE )
          {
					  printf ( "Enter vehicle type (1 for Car / 2 for tricycle ): \n" ) ;
            scanf ( "%d", &car_type ) ;
	          if ( car_type != CAR && car_type != TRICYCLE )
						  printf ( "\nInvalid vehicle type.\n" ) ;
          }

				  printf ( "Enter vehicle number: " ) ;
				  scanf ( "%d", &number ) ;


				  if ( car_type == CAR || car_type == TRICYCLE )
				  {
					  getting_free_column_row ( car_type, tarr ) ;

					  if ( tarr[0] != -1 && tarr[1] != -1 )
					  {
						  car_row = tarr[0] ;
						  car_column = tarr[1] ;

              if ( car_type == CAR )
                car[car_row][car_column] =  add ( car_type, number, car_row, car_column ) ;
              else
							  tricycle[car_row - 2][car_column] = add ( car_type, number, car_row, car_column ) ; ;
            }
					  else
            {
              if ( car_type == CAR )
                printf ( "\nNo parking slot free to park a car\n" ) ;
              else
                printf ( "\nNo parking slot free to park a tricycle\n" ) ;
            }
          }
				  else
				  {
            printf ( "Invalid type\n" ) ;
					  break ;
          }

          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

      case 2 :
          system ( "cls" ) ;
				  printf ( "Total vehicles parked: %d\n", vehicle_counting ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 3 :
          system ( "cls" ) ;
				  printf ( "Total cars parked: %d\n", car_counting ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 4 :
          system ( "cls" ) ;
				  printf ( "Total tricycle parked: %d\n", tricycleCount ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 5 :
          system ( "cls" ) ;
				  printf ( "Display\n" ) ;
				  display_main_menu( ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 6 :
          system ( "cls" ) ;
				  printf ( "Departure\n" ) ;
          car_type = 0 ;

          while ( car_type != CAR && car_type != TRICYCLE )
          {
					  printf ( "Enter vehicle type (1 for Car / 2 for tricycle ): \n" ) ;
            scanf ( "%d", &car_type ) ;
	          if ( car_type != CAR && car_type != TRICYCLE )
						  printf ( "\nInvalid vehicle type.\n" ) ;
          }
				  printf ( "Enter number: "  ) ;
				  scanf ( "%d", &number ) ;

  				if ( car_type == CAR || car_type == TRICYCLE )
	  			{


		  			getrcbyinfo ( car_type, number, tarr ) ;
			  		if ( tarr[0] != -1 && tarr[1] != -1 )
				  	{
				  	    insertrecord2(number,datetime());
				  	    get_arrival_time(number);
              car_column = tarr [1] ;

              if ( car_type == CAR )
              {
                car_row = tarr [0] ;
	              car_delete ( car [car_row][car_column] ) ;

				                    for ( i = car_column ; i < 9 ; i++ )
							  {
								  car[car_row][i] = car[car_row][i + 1] ;

							  }
                free ( car[car_row][i] ) ;

					  car[car_row][i] = NULL ;
              }

						  else
              {
                car_row = tarr[0] - 2 ;
							  if ( ! ( car_row < 0 ) )
							  {
								  car_delete ( tricycle[car_row][car_column] ) ;
								  for ( i = car_column ; i < 9 ; i++ )
								  {
									  tricycle[car_row][i] = tricycle[car_row][i + 1] ;

								  }
								  tricycle[car_row][i] = NULL ;
                }
              }
            }
					  else
            {
              if ( car_type == CAR )
							  printf ( "\nInvalid car number, or a car with such number has not been parked here.\n" ) ;
              else
                printf ( "\nInvalid tricycle number, or a tricycle with such number has not been parked here.\n" ) ;
            }
          }
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 8 :

          system ( "cls" ) ;
          for ( car_row = 0 ; car_row < 2 ; car_row++ )
          {
            for ( car_column = 0 ; car_column < 10 ; car_column++ )
            {
              if ( car[car_row][car_column] -> car_number != 0 )
                free ( car[car_row][car_column] ) ;
              if ( tricycle[car_row][car_column] -> car_number != 0 )
							  free ( tricycle[car_row+2][car_column] ) ;
            }
          }
				  finish = 0 ;




				   getch();
				  break ;

            case 7 :
              system ( "cls" ) ;
     int opt ;
		printf ( "RECORD TABLES\n" ) ;
  			 printf ( "Press 1 for Arrival history\n" ) ;
                         printf ( "Press 2 for Departure history\n" ) ;
                                printf ( "Press 3 for Fine Sheet\n" ) ;
     			scanf ( "%d", &opt ) ;
           historyrec(opt);
 printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
                break ;
    }
	}
  return 0 ;
}
