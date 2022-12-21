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
    int menu_selection,i,j;
    int patient;
    void *ifct_element;
    FILE* fp;
    int index, age, time;
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
   
    while(3 == fscanf(fp, "%d %d %d", &index ,&age, &time)) //3 == fscanf("3가지 읽기",변수들) 
    {
    	for(i=0; i<N_HISTORY; i++) //N_HISTORY =5
    	{
    		fscanf(fp, "%d", &placeHist[i]); //fscanf로 5개 읽기
		}
		
		ifct_element = ifctele_genElement(index, age, time); //element 작성
		
		ifctdb_addTail(ifct_element); 
 
		
		//값을 가져올때 이렇게 age = ifctele_getAge(ifct_element); 하지만 여기서 사용하면 안됨
		 
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
            case MENU_EXIT: //menu 0
                printf("Exiting the program... Bye bye.\n");
                break;
            
			//특정 환자에 대한 정보 출력     
            case MENU_PATIENT:  //menu 1
            //scanf로 patient index를 받음 
            	printf("Patient index : ");
            	scanf("%d",&index);
            	ifctele_getElement();
            	ifctele_printElement(index);
            
                break;
                
                
             //특정 장소에서 감염이 확인된 환자 관련 정보 출력     
            case MENU_PLACE:  //menu 2
            	printf("Place Name : ");
            	scanf("%d", &place);
            	ifctele_getPlaceName();
            	
                break;
                
                
             //특정 범위의 나이에 해당하는 환자 관련 정보 출력   
            case MENU_AGE:  //menu 3
                printf("minimal age : "); //최소나이 변수를 min_age 
                scanf("%d", &min_age);
                
                printf("maximal age : "); //최고나이 변수를 max_age 
                scanf("%d", &max_age);
                
				ifctele_getAge();
                ifctele_printElement(index);
                
                break;
                
                
            //감염 경로 및 최초 전파자 추적    
            case MENU_TRACK:   //menu 4
            	printf("Patient index : ");  //입력받은 index를 통해 track 
            	scanf("%d",&index);
				 
                 ifctele_getHistPlaceIndex();
                 
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}
