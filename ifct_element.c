//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place 
{
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};

typedef struct ifs_ele
{	
	int index;//번호
	int age;//나이
	int time;//걸린시간
	place_t place[N_HISTORY]; //장소(N_HISTORY) 
} ifs_ele_t;





 void* ifctele_getElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY])
 { // 각 환자의 전체적인 정보를 구조체 하는 함수 
 	ifs_ele_t* ptr;
 	ptr = malloc();
 	
 	ptr -> index = index;
	ptr -> age = age;
	ptr -> detected_time = time;
	ptr -> history_place[N_HISTORY] = history_place[N_HISTORY];	
	
	return ptr; //free(ptr)하면 안됨 main.c로 정보를 넘겨줘야하기 때문에
 }

 char* ifctele_getPlaceName(int placeIndex)
 { //placeIndex 번호를 받아 번호에 맞는 지역이름을 반환하는 함수 
	place_t* ptr;
	//입력받은 place와 place배열 순서 속 숫자가 같을경우 그 숫자에 해당하는 지역이름을 출력한다. 
	if(place[N_HISTORY] == place)
	{
		printf("%c(%d) ->",placeHist[place-1],placeHist[place-1]); 
		//배열은 0부터 시작해서 place보다 앞단계 위에 있다고 생각하여 place-1을 해줌
	}
	
	
	return countryName[placeIndex];
 } 
 
 
 int ifctele_getHistPlaceIndex(void* obj, int index)
 { //감염 확인일자로 부터 5일간(감염 확인 당시 포함) 있던 장소의 PlaceIndex번호를 받아 번호에 맞는 지역이름을 반환하는 함수 
 	/*
		for문을 통해서 장소를 다 출력	 
	*/
	 
	if( index == index) //입력받은 index 값이 동일할 경우 
	{
		//만약 patient가 첫번째 감염자 일경우
		if(place[N_HISTORY] = place[0])
		{
			printf("--> [TRACKING] patient %d is infected by %d (time : %d, place : %c)", index, index,place[N_HISTORY],place[N_HISTORY])
		}
		
		//만약 patient가 첫번째 감염자가 아닐경우 for문을 이용해 누구로 부터 감염되었는지 추적 
		else
		{
			for(i =0; i<N_HISTORY; i++)
			{
				printf("--> [TRACKING] patient %d is infected by %d (time : %d, place : %c)", index, index,place[N_HISTORY],place[N_HISTORY])
			}	
		}
		
	}
	 
	return countryName[placeIndex];	
 }


 unsigned int ifctele_getinfestedTime(void* obj)
 { //감염 확인 일자를 얻는 함수 
 	
	//for문을 통해서 time의 값을 얻음
	if (index = index)
	{
		for(i=0; i<)
	}
	
	
 }
 
 void ifctele_getAge(void* obj)
 { //감염자의 나이를  얻는 함수 
 	
 	//min_age부터 max_age까지 내에 나이가 맞으면 아래 값을 출력 
	for(j = min_age; j<max_age+1; j++) 
	{
    	ifctele_printElement();
	}
	
	ifs_ele_t* ptr = (ifs_ele_t*).obj; //구조체를 만들어주고 
	
	return ptr->age; //그 구조체 안에 있는 필요한 내용을 내보낸다. 
 }
 
 
 void ifctele_printElement(void* obj)
 { //얻은 정보를 출력하는 함수 
	
	ifs_ele_t* ptr = (ifs_ele_t*).obj;

	for(i=0; i<N_PEOPLE; i++) //N_PEOPLE = 5 
	{
		if( index == index) //index번호와 입력받은 index의 값이 동일한 경우 아래와 같이 실행 
		{
			printf("----------------------------------------");
			printf("Patient index : %i\n", ptr -> index); 
			printf("Patient age : %i\n", ptr -> age); 
			printf("Detected time : %i\n", ptr -> time); 
			
            for(j=0; j<N_HISTORY; j++) //N_HISTORY = 40
            {
            	printf("%c(%d) ->",placeHist[j],placeHist[j]);
            	ifctele_getPlaceName();
			}
			printf("----------------------------------------");
		}
	}
 }
