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


int trackInfester(int patient_no, int *detected_time, int *place); //������ ���� �Լ� 

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
   
    while(3 == fscanf(fp, "%d %d %d", &index ,&age, &time)) //3 == fscanf("3���� �б�",������) 
    {
    	for(i=0; i<N_HISTORY; i++) //N_HISTORY =5
    	{
    		fscanf(fp, "%d", &placeHist[i]); //fscanf�� 5�� �б�
		}
		
		ifct_element = ifctele_genElement(index, age, time); //element �ۼ�
		
		ifctdb_addTail(ifct_element); 
 
		
		//���� �����ö� �̷��� age = ifctele_getAge(ifct_element); ������ ���⼭ ����ϸ� �ȵ�
		 
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
            
			//Ư�� ȯ�ڿ� ���� ���� ���     
            case MENU_PATIENT:  //menu 1
            //scanf�� patient index�� ���� 
            	printf("Patient index : ");
            	scanf("%d",&index);
            	ifctele_getElement();
            	ifctele_printElement(index);
            
                break;
                
                
             //Ư�� ��ҿ��� ������ Ȯ�ε� ȯ�� ���� ���� ���     
            case MENU_PLACE:  //menu 2
            	printf("Place Name : ");
            	scanf("%d", &place);
            	ifctele_getPlaceName();
            	
                break;
                
                
             //Ư�� ������ ���̿� �ش��ϴ� ȯ�� ���� ���� ���   
            case MENU_AGE:  //menu 3
                printf("minimal age : "); //�ּҳ��� ������ min_age 
                scanf("%d", &min_age);
                
                printf("maximal age : "); //�ְ��� ������ max_age 
                scanf("%d", &max_age);
                
				ifctele_getAge();
                ifctele_printElement(index);
                
                break;
                
                
            //���� ��� �� ���� ������ ����    
            case MENU_TRACK:   //menu 4
            	printf("Patient index : ");  //�Է¹��� index�� ���� track 
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
