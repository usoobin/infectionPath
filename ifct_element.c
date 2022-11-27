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

 void* ifctele_getElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY])
 { // 각 환자의 전체적인 정보 
	/*
		for 문을 사용해서 환자 정보를 받는다
	*/
	
	for(i=0; i<N_PEOPLE;)
 }

 char* ifctele_getPlaceName(int placeIndex)
 { //placeIndex 번호를 받아 번호에 맞는 지역이름을 반환하는 함수 
	/*
		
	*/
	return countryName[placeIndex];
 } 
 
 
 void* ifctele_getHistPlaceIndex(void* obj, int index)
 { //감염 확인일자로 부터 5일간(감염 확인 당시 포함) 있던 장소의 PlaceIndex번호를 받아 번호에 맞는 지역이름을 반환하는 함수 
 	/*
		for문을 통해서 장소를 다 출력	 
	*/
	 
	return countryName[placeIndex];	
 }


 int* ifctele_getinfestedTime(void* obj)
 { //감염 확인 일자를 얻는 함수 
 	/*
		for문을 통해서 time의 값을 얻음	
	*/
 }
 
 int* ifctele_getAge(void* obj)
 { //감염자의 나이를  얻는 함수 
 	/*
		for 문을 이용해서 최소 나이를 찾는다
		
		for 문을 이용해서 최고 나이를 찾는다 
	*/
 }
 
 int* ifctele_printElement(void* obj)
 { //얻은 정보를 출력하는 함수 
 	/*
		bingo_print 이용 
	*/
 	
 }
