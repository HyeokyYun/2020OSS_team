#include "list.h"

void listScore(Score *s, int count){
	printf("\n등록번호   이름    국어    영어    수학    총점    평균\n");
	for(int i = 0; i < count; i++){
		if(s[i].kor == -1 && s[i].eng == -1 && s[i].math == -1) continue;
		printf("%d          ", i + 1);
		readScore(s[i]);
	}
	printf("\n");
}

int selectDataNo(Score *s, int count){
	int num;
	listScore(s, count);
	printf("작업할 제품번호(취소: 0): ");
	scanf("%d", &num);
	return num;
}

int scoreMenu(){
    int num;
    printf("====메뉴목록====\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("0. 종료\n");
    printf("원하는 메뉴는 ? ");
    scanf("%d", &num);
    return num;
}

void saveData(Score* s, int count){
	FILE* fp = fopen("data.txt", "wt");
	for(int i=0; i<count; i++){
		if(s[i].kor == -1) continue;
	fprintf(fp, "%d %d %d %d %.1f %s\n", s[i].kor, s[i].eng, 
		s[i].math, s[i].sum, s[i].avg, s[i].name);
	}
	fclose(fp);
	printf("저장됨!\n");
}

int loadData(Score* s){
	int c = 0;
	FILE* fp = fopen("data.txt", "rt");
	if(fp == NULL){
		printf("파일없음\n");
		return 0;
	}
	for(;;c++){
		fscanf(fp, "%d %d %d %d %f ", &s[c].kor, &s[c].eng, &s[c].math,&s[c].sum, &s[c].avg);
		fgets(s[c].name, 20, fp);
		s[c].name[strlen(s[c].name)-1] = '\0';
		if(feof(fp)) break;
	}

	printf("로딩 성공 !\n");
	return c;
}

void searchName(Score *s, int count){
	int nameCount = 0;
	char searchName[20];
	printf("검색할 이름: ");
	scanf("%s", searchName);
	
	printf("\n== = = [검색한 이름] = = ==\n");
	for(int i = 0; i < count; i++){
		if(s[i].kor == -1 && s[i].math == -1 && s[i].eng)continue;
		if(strstr(s[i].name, searchName)){
			readScore(s[i]);
			nameCount++;
		}
	}
	if(nameCount == 0){
		printf("==> \"%s\" 는 없습니다.\n", searchName);
	}
}
