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
	int index;//��ȣ
	int age;//����
	int time;//�ɸ��ð�
	place_t place[N_HISTORY]; //���(N_HISTORY) 
} ifs_ele_t;





 void* ifctele_getElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY])
 { // �� ȯ���� ��ü���� ������ ����ü �ϴ� �Լ� 
 	ifs_ele_t* ptr;
 	ptr = malloc();
 	
 	ptr -> index = index;
	ptr -> age = age;
	ptr -> detected_time = time;
	ptr -> history_place[N_HISTORY] = history_place[N_HISTORY];	
	
	return ptr; //free(ptr)�ϸ� �ȵ� main.c�� ������ �Ѱ�����ϱ� ������
 }

 char* ifctele_getPlaceName(int placeIndex)
 { //placeIndex ��ȣ�� �޾� ��ȣ�� �´� �����̸��� ��ȯ�ϴ� �Լ� 
	place_t* ptr;
	//�Է¹��� place�� place�迭 ���� �� ���ڰ� ������� �� ���ڿ� �ش��ϴ� �����̸��� ����Ѵ�. 
	if(place[N_HISTORY] == place)
	{
		printf("%c(%d) ->",placeHist[place-1],placeHist[place-1]); 
		//�迭�� 0���� �����ؼ� place���� �մܰ� ���� �ִٰ� �����Ͽ� place-1�� ����
	}
	
	
	return countryName[placeIndex];
 } 
 
 
 int ifctele_getHistPlaceIndex(void* obj, int index)
 { //���� Ȯ�����ڷ� ���� 5�ϰ�(���� Ȯ�� ��� ����) �ִ� ����� PlaceIndex��ȣ�� �޾� ��ȣ�� �´� �����̸��� ��ȯ�ϴ� �Լ� 
 	/*
		for���� ���ؼ� ��Ҹ� �� ���	 
	*/
	 
	if( index == index) //�Է¹��� index ���� ������ ��� 
	{
		//���� patient�� ù��° ������ �ϰ��
		if(place[N_HISTORY] = place[0])
		{
			printf("--> [TRACKING] patient %d is infected by %d (time : %d, place : %c)", index, index,place[N_HISTORY],place[N_HISTORY])
		}
		
		//���� patient�� ù��° �����ڰ� �ƴҰ�� for���� �̿��� ������ ���� �����Ǿ����� ���� 
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
 { //���� Ȯ�� ���ڸ� ��� �Լ� 
 	
	//for���� ���ؼ� time�� ���� ����
	if (index = index)
	{
		for(i=0; i<)
	}
	
	
 }
 
 void ifctele_getAge(void* obj)
 { //�������� ���̸�  ��� �Լ� 
 	
 	//min_age���� max_age���� ���� ���̰� ������ �Ʒ� ���� ��� 
	for(j = min_age; j<max_age+1; j++) 
	{
    	ifctele_printElement();
	}
	
	ifs_ele_t* ptr = (ifs_ele_t*).obj; //����ü�� ������ְ� 
	
	return ptr->age; //�� ����ü �ȿ� �ִ� �ʿ��� ������ ��������. 
 }
 
 
 void ifctele_printElement(void* obj)
 { //���� ������ ����ϴ� �Լ� 
	
	ifs_ele_t* ptr = (ifs_ele_t*).obj;

	for(i=0; i<N_PEOPLE; i++) //N_PEOPLE = 5 
	{
		if( index == index) //index��ȣ�� �Է¹��� index�� ���� ������ ��� �Ʒ��� ���� ���� 
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
