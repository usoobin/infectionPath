//
//  ifct_element.h
//  infection path
//
//  Created by Juyeop Kim on 2022/10/20.
//

#ifndef ifct_element_h
#define ifct_element_h

#define N_PLACE                     40
#define N_HISTORY                   5
#define MAX_PLACENAME               100

void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY]); // 각 patient의 전체적인 정보 
char* ifctele_getPlaceName(int placeIndex);																// 숫자를 입력 받아 장소 이릅 출력 
int ifctele_getHistPlaceIndex(void* obj, int index);													// 감염 장소 순서에 대한 내용 
unsigned int ifctele_getinfestedTime(void* obj);														// 감염 확인 일자 
int ifctele_getAge(void* obj);																			// 감염된 환자의 나이 
void ifctele_printElement(void* obj);																	// 값을 출력 
#endif /* ifct_element_h */
