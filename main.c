#include "list.h"

int main(void){
	Score slist[100];
	int choice;
	int count = 0;
	int curcount = 0;
	
	count = loadData(slist);
	curcount = count;	
	while(1){
		choice = scoreMenu();
		if(choice == 0) break;
		else if(choice == 1){
			if(count > 0){
				listScore(slist, count);
			}else{
				printf("아무런 정보도 입력되지 않았습니다.\n");
			}
		}
		else if(choice == 2){
			count += addScore(&slist[curcount++]);
		}
		else if(choice == 3){
			if(count > 0){
				int select = selectDataNo(slist, curcount);
				if(select == 0){
					printf("==> 수정이 취소됩니다.\n");
					continue;
				}
				updateScore(&slist[select -1]);	
			}else{
				printf("아무런 정보도 입력되지 않았습니다.\n");
			}
		}
		else if(choice == 4){
			int deletok;
			if(count > 0){
				int select = selectDataNo(slist, curcount);
				if(select == 0){
					printf("==> 삭제가 취소됩니다.\n");
					continue;
				}
				printf("정말 삭제하시겠습니까? (예:1) : ");
				scanf("%d", &deletok);
				if(deletok == 1){
					deleteScore(&slist[select - 1]);
					printf("==> 삭제됨!\n");
					count--;
				}
				else printf("==> 제품삭제 취소");
			}else{
				printf("아무런 정보도 입력되지 않았습니다.\n");
			}
		}else if(choice == 5){
			if(count > 0){
				saveData(slist, curcount);
			}else{
				printf("아무런 정보도 입력되지 않았습니다 .\n");
			}
		}else if(choice == 6){
			if(count > 0)
				searchName(slist, curcount);
			else
				printf("아무런 정보도 입력되지 않았습니다.\n");
		}else if(choice == 7){
			if(count > 0)
				searchAvg(slist, curcount);
			else
				printf("아무런 정보도 입력되지 않았습니다.\n");
		}else if(choice == 8){
			if(count > 0)
				searchRank(slist, curcount);
			else
				printf("아무런 정보도 입력되지 않았습니다.\n");
		}else if(choice == 9){
			if(count > 0)
				listByScore(slist, curcount);
			else
				printf("아무런 정보도 입력되지 않았습니다.\n");
		}else if(choice == 10){
			if(count > 0)
				deleteAllScore(slist, curcount);
			else
				printf("아무런 정보도 입력되지 않았습니다.\n");
		}			
	}
	printf("==>종료됨!\n");
	return 0;
}
