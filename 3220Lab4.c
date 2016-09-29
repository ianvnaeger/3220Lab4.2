/*
 ============================================================================
 Name        : 3220Lab4.c
 Author      : Ian Naeger
 Version     :
 Copyright   : N/A
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double output[2000];
int array[2000];
int len , max , mean;


void ReadFile( int num );
void ScaleIt( double scale );
void OffsetIt( double offset );
double FindMean( );
int FindMax( );
void CenterIt( double mean );
void NormalizeIt( double max );

int main(int argc , char *argv)
{
	int num , choice , Offyn , Scyn , Styn , Ceyn , Noyn , RFyn , Heyn , k;
	double scale;
	char Output[50];
	double Offset;
	FILE *fp;


/*	for( k = 0; k <= argc; k++ )
	{
		if( argv[k] == "-n")
		{

		}
		else if( argv[k] == "-o")
		{

		}
		else if( argv[k] == "-s")
		{

		}
		else if( argv[k] == "-S")
		{

		}
		else if( argv[k] == "-C")
		{

		}
		else if(argv[k] == "-N")
		{

		}
		else if(argv[k] == "-r")
		{

		}
		else if(argv[k] == "-h")
		{

		}
	}

*/
	printf("Enter File to Open: \n");
	scanf("%d", &num);
	getchar();
	printf("Would you like to Scale or Offset the Data? \n1. Scale \n2. Offset \n");
	scanf("%d", &choice);
	getchar();
// Gets file and mode from user
	ReadFile( num );
// gets array from file
	if( choice == 1 )
	{
		printf("Enter Scaling Factor:");
		scanf("%lf", &scale);
		getchar();

		ScaleIt( scale );
	
		sprintf(Output, "Scaled_data_%02d.txt", num);
	
		fp = fopen(Output , "w");
	
		fprintf(fp , "%d %lf\n" , len , scale);
	
		for(k = 0; k < len; k++)
		{
			fprintf( fp , "%f\n" , output[k]);
		}
//		
		fclose(fp);
// takes array, scales it, puts it in a new array and prints it to a file
	}
	else if( choice == 2 )
	{
		printf("Enter Offset:");
		scanf("%lf", &Offset);
		getchar();

		OffsetIt(Offset );

		sprintf(Output, "Offset_data_%02d.txt", num);
		FILE* fp = fopen(Output , "w");

		fprintf(fp , "%d %lf\n" , len , Offset);

		for(k = 0; k < len; k++)
		{
			fprintf( fp , "%f\n" , Output[k]);
		}
		fclose(fp);
// takes array, offsets it, puts it in a new array and prints it to a file
	}

	double mean , max;
	char *OutputA;
	char *OutputB;
	char *OutputC;

	OutputA = malloc( 50 * sizeof(char));

	mean = FindMean(  );
	max = FindMax(  );

	sprintf(OutputA, "Statistics_data_%02d.txt", num);
	FILE* fpA = fopen(OutputA , "w");

	fprintf(fpA, "%lf %lf\n" , mean , max);

	fclose( fpA );
	// finds the mean and max of the array and prints it to a file
	CenterIt(mean);

	OutputB = malloc( 50 * sizeof(char));

	sprintf(OutputB, "Centered_data_%02d.txt", num);
	FILE* fpB = fopen(OutputB , "w");

	fprintf(fpB , "%d %lf\n" , len , mean);

	for(k = 0; k < len; k++)
	{
		fprintf( fpB , "%f\n" , output[k] );
	}
	fclose(fpB);
// centers the array and prints it to a file

	NormalizeIt(max);
	OutputC = malloc( 50 * sizeof(char) );

	sprintf(OutputC, "Normalized_data_%02d.txt", num);
	FILE* fpC = fopen(OutputC , "w");

	fprintf(fpC , "%d %lf\n" , len , max);

	for(k = 0; k < len; k++)
	{
		fprintf( fpC , "%f\n" , output[k]);
	}
	fclose(fpC);
	// normalizes the array and prints it to a file
	return 0;
}

void ReadFile( int num )
{
	int max , k;
	char *Filename = malloc( 50 * sizeof( char ));
	
	sprintf(Filename, "Raw_data_%02d.txt", num);
	FILE *fp = fopen(Filename, "r");

	fscanf( fp , "%d %d" , &len , &max);

	for(k = 0; k < len; k++)
	{
		fscanf(fp, "%d", &array[k]);
	}

	fclose(fp);
	free( Filename );
// Takes file number, finds the file, and makes it into an array
}

void ScaleIt( double scale )
{
	int k;
	for(k = 0; k < len; k++)
	{
		output[k] = (double)array[k] * scale;
	}
// scales the array
}

void OffsetIt( double offset )
{
	int k;
		for(k = 0; k < len; k++)
		{
			output[k] = (double)array[k] + offset;
		}
// offsets the array
}

void NormalizeIt( double max )
{
	int k;
	for(k = 0; k < len; k++)
	{
		output[k] = (double)array[k] / max;
	}
// normalizes the array
}

void CenterIt( double mean )
{
	int k;
	for(k = 0; k < len; k++)
	{
		output[k] = (double)array[k] - mean;
	}
// Centers the array
}

double FindMean( )
{
	int k;
	double mean = 0;
	for(k = 0; k < len; k++)
	{
		mean = mean + (double)array[k];
	}
	mean = mean / len;
// Finds the mean of the array
	return mean;
}

int FindMax( )
{
	int k;
	double max = 0;
	for( k = 0; k < len; k++)
	{
		if( array[k] > max )
		{
			max = array[k];
		}
	}
// Finds the max of the array
	return max;
}




