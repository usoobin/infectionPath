//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2


int trackInfester(int patient_no, int *detected_time, int *place); //감염자 추적 함수 

int main(int argc, const char * argv[]) 
{    
    int menu_selection,i;
    int patient;
    void *ifct_element;
    FILE* fp;
    int pIndex, age, time;
    int placeHist[N_HISTORY];
    
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc != 2)
    {
        printf("[ERROR] syntax : infestPath (file path).");
        return -1;
    }
    
    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);
        return -1;
    }
    
    //1-2. loading each patient informations
   
    while(fscanf(fp, "%d %d %d", &pIndex ,&age, &time))
    {
    	for(i=0; i<5; i++)
    	{
    		fscanf(fp, "%d", &placeHist[i]);
		}
	}
    
    
    
    //1-3. FILE pointer close
    fclose(fp);
    
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");         //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");           //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        
        switch(menu_selection)
        {
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
            
			//특정 환자에 대한 정보 출력     
            case MENU_PATIENT: 
            	printf("Patient index : ");
            	scanf("%d", &patient);
            	
            	if(patient = pIndex) 
            	{
            		printf("Patient index :%d\n",pIndex);
            		printf("Patient age :%d\n",age);
            		printf("detected time :%d\n",time);
            		printf("Path History : %c(%d) -> %c(%d) -> %c(%d) -> %c(%d) -> %c(%d)" ,placeHist[i],placeHist[i],placeHist[i+1],placeHist[i+1]
					,placeHist[i+2],placeHist[i+2],placeHist[i+3],placeHist[i+3],placeHist[i+4],placeHist[i+4]);
				}
                break;
             //특정 장소에서 감염이 확인된 환자 관련 정보 출력     
            case MENU_PLACE:
            	printf("Place Name : ");
            	scanf("%d", &place);
            	
            	if(place = placeHist[i])
            	{
            		printf("There are %d patients detected in %d", pIndex,placeHist[i]);
				}
                break;
             //특정 범위의 나이에 해당하는 환자 관련 정보 출력   
            case MENU_AGE:
                printf("minimal age : "); //최소나이 변수를 min_age 
                scanf("%d", &min_age);
                
                printf("maximal age : "); //최고나이 변수를 max_age 
                scanf("%d", &max_age);
                
                for(j = min_age; j<max_age+1; j++) //min_age부터 max_age까지 내에 나이가 맞으면 아래 값을 출력 
                {
                	printf("Patient index :%d\n",pIndex);
            		printf("Patient age :%d\n",age);
            		printf("detected time :%d\n",time);
            		printf("Path History : %c(%d) -> %c(%d) -> %c(%d) -> %c(%d) -> %c(%d)" ,placeHist[i],placeHist[i],placeHist[i+1],placeHist[i+1]
					,placeHist[i+2],placeHist[i+2],placeHist[i+3],placeHist[i+3],placeHist[i+4],placeHist[i+4]);
				}
                 
                break;
            //감염 경로 및 최초 전파자 추적    
            case MENU_TRACK:
            	printf("Patient index : ");
            	scanf("%d",&patient_track);
				 
                 
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}
