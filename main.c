#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DELIM_CHARS ", "
#define MAX_WORDS 512
#define MAX_LENGTH 50 //최대 크기와 단어 길이

char word[MAX_WORDS][MAX_LENGTH] = { "account", "account for", "benefit from", "condense", "condense into", "better", "conduct", "accrue", "conductor", "confirmation", "be aware of", "biannual", "accumulation",
    "confirmed", "beneficial", "beneficiary", "confiscate", "binding", "bill", "accurately", "achievement", "irretrievable", "issue", "be laid off", "landfill", "landslide", "itinerary", "agenda",
    "mutually", "natural disaster", "needlessly", "keynote speech", "laboratory", "lack", "municipal", "multiply", "mutual", "largely", "lastingly", "support", "irritate", "generous", "tolerant",
    "liberal", "reject", "substitute", "occur", "despise", "contempt", "gain", "avail", "educate", "resemble", "grasp", "reconsider", "prove", "illustrate", "exemplify", "conservative", "progressive",
    "fortify", "strengthen", "reproduce", "elicit", "extract", "implore", "appoint", "disgust", "preach", "worship", "yawn", "hiccup", "pillar", "servitude", "recreation", "punctuality",
    "fascination", "attraction", "vicious", "distrust", "suspicion", "endeavor", "devote", "pride", "proud", "discontinue", "ignore", "disregard", "neglect", "depend" };

char meaning[MAX_WORDS][MAX_LENGTH] = { "계산", "~를 설명하다", "~로부터 혜택을 받다", "압축하다", "~로 압축하다", "~를 개선하다", "실시하다, 시행하다", "생기다, 얻어지다", "지휘자, 차장", "확정서", "~를 조심하다",
    "반년마다의", "축적, 축적물", "확인된", "혜택이 많은", "수혜자", "압수하다, 몰수하다", "구속력 있는", "계산서, 청구서, 법안", "정확히", "업적, 성과", "돌이킬 수 없는", "발행하다, 발급, 문제",
    "해고되다", "매립지", "사태, 산사태", "여행스케줄", "의사일정", "서로", "재해", "불필요하게", "기조연설", "실험실", "부족하다", "시의", "급증하다", "상호의", "주로, 대량으로",
    "영속적인, 영구적인", "지지, 지주", "짜증나게하다", "관대한, 마음이 넓은", "관대한, 아량이 있는", "자유주의자, 자유당원", "거절하다", "대체, 대신하다", "일어나다, 나타나다",
    "경멸하다", "경멸, 멸시", "이익, 증가, 얻다", "도움이 되다", "교육하다, 양성하다", "닮다", "쥐다", "재고하다", "입증하다", "설명하다", "예를 들다, 예증하다", "보수적인, 전통적인",
    "전진하는, 누진적인", "견고하게 하다", "강하게하다, 강해지다", "재생시키다;재현하다", "끌어내다", "끌어내다, 빼어내다", "간청하다, 탄원하다", "임명하다", "역겹게하다, 혐오감", "설교하다", "예배하다, 예배",
    "하품하다", "딸꾹질", "기둥, 주석", "노예 상태", "휴양, 원기회복", "시간엄수", "매혹, 매력", "끌림, 매력", "사악한, 잔인한, 타락한", "불신, 의혹", "의심, 혐의", "노력하다, 노력",
    "바치다, ~에 몰두하다", "자부심, 자랑스러움", "자랑스러운", "중지하다, 정지하다", "무시하다, 모르는체하다", "무시하다", "태만, 소홀", "의지하다, ~나름이다" };

char** WAword;
char** WAmeaning;
int numwords = 90;
int WAnumwords = 0;

// 틀린 단어 모으기
void WrongAnswer(const char* wrongWord, const char* wrongMeaning) {
    if (WAnumwords >= MAX_WORDS) {
        printf("오답 단어를 추가할 수 없습니다. 최대 크기에 도달했습니다.\n");
        return;
    }

    // 오답 생길 때마다 배열 증가
    WAword = (char**)realloc(WAword, (WAnumwords + 1) * sizeof(char*));
    WAmeaning = (char**)realloc(WAmeaning, (WAnumwords + 1) * sizeof(char*));

    // 메모리 할당
    WAword[WAnumwords] = (char*)malloc(MAX_LENGTH * sizeof(char));
    WAmeaning[WAnumwords] = (char*)malloc(MAX_LENGTH * sizeof(char));

    // 오답 배열에 추가
    strcpy(WAword[WAnumwords], wrongWord);
    strcpy(WAmeaning[WAnumwords], wrongMeaning);
    WAnumwords++;
}

// 영단어 퀴즈 
void Quiz() {
    srand((unsigned int)time(NULL)); //랜덤 시드 설정

    printf("퀴즈를 시작합니다.\n");

    int score = 0;
    int questionNum = 0;

    //퀴즈 10문제
    while (questionNum < 10 && numwords > 0) { 

        int Index = rand() % numwords;  // 랜덤 인덱스 선택

        printf("\nQ%d. 다음 단어의 뜻은?\n", questionNum + 1); // 문제와 문제번호 출력
        printf("%s: ", word[Index]);

        char ans[MAX_LENGTH];
        fgets(ans, MAX_LENGTH, stdin); // 답 입력

        // 개행 문자 제거
        if ((strlen(ans) > 0) && (ans[strlen(ans) - 1] == '\n')) {
            ans[strlen(ans) - 1] = '\0';
        }

        char* token = strtok(meaning[Index], DELIM_CHARS); //단어 뜻 ','로 구분
        int correct = 0;

        // 저장된 뜻 중 하나라도 맞추면 정답처리
        while (token != NULL) {
            if (strstr(ans, token) != NULL) {
                correct = 1;
                break;
            }
            token = strtok(NULL, DELIM_CHARS); 
        }

        if (correct) {
            printf("정답입니다!\n");
            score++;
        }
        else {
            printf("틀렸습니다. 정답은 \"%s\"입니다.\n", meaning[Index]);
            // 오답 단어장에 추가
            WrongAnswer(word[Index], meaning[Index]);
        }
        questionNum++;
    }

    printf("\n점수: %d / %d\n", score, 10);
}

int main() {
    // 오답 단어장 초기화
    WAword = (char**)malloc(MAX_WORDS * sizeof(char*));
    WAmeaning = (char**)malloc(MAX_WORDS * sizeof(char*));
    if (WAword == NULL || WAmeaning == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    for (int i = 0; i < MAX_WORDS; i++) {
        WAword[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
        WAmeaning[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
        if (WAword[i] == NULL || WAmeaning[i] == NULL) {
            printf("메모리 할당 실패\n");
            return 1;
        }
    }

    int menu;
    while (1) {
        // 메뉴 표시
        printf("영어 단어장\n");
        printf("1. 단어 추가\n");
        printf("2. 단어장 출력\n");
        printf("3. 오답 단어장 출력\n");
        printf("4. 퀴즈 시작\n");
        printf("5. 종료\n");
        printf("\n메뉴를 선택하세요: ");
        scanf("%d", &menu);
        getchar();

        switch (menu) {
        case 1:
            if (numwords < MAX_WORDS) {
                printf("단어 추가\n");                
                printf("단어를 입력하세요: ");
                fgets(word[numwords], MAX_LENGTH, stdin);
                word[numwords][strlen(word[numwords]) - 1] = '\0'; // 개행 문자 제거
                printf("뜻을 입력하세요: ");
                fgets(meaning[numwords], MAX_LENGTH, stdin);
                meaning[numwords][strlen(meaning[numwords]) - 1] = '\0'; // 개행 문자 제거

                numwords++;
            }
            else {
                printf("더 이상 단어를 추가할 수 없습니다.\n");
            }
            break;

        case 2:
            // 저장된 단어 출력   
            printf("단어장 출력\n");        
            if (numwords > 0) {
                for (int i = 0; i < numwords; i++) {
                    printf("%d. %s - %s\n", i + 1, word[i], meaning[i]);
                }
                printf("\n");
            }
            else {
                printf("저장된 단어가 없습니다\n\n");
            }
            break;

        case 3:
            //오답 단어 출력
            printf("오답 단어장:\n");
            if (WAnumwords > 0) {
                for (int i = 0; i < WAnumwords; i++) {
                    printf("%d. %s - %s\n", i + 1, WAword[i], WAmeaning[i]);
                }
                printf("\n");
            }
            else {
                printf("저장된 단어가 없습니다\n\n");
            }
            break;

        case 4:
            if (numwords == 0) {
                printf("퀴즈를 시작할 단어가 없습니다. 먼저 단어를 추가하세요.\n");
            }
            else {
                Quiz();
            }
            break;

        case 5:
            // 메모리 해제
            printf("종료\n\n");
            for (int i = 0; i < MAX_WORDS; i++) {
                free(WAword[i]);
                free(WAmeaning[i]);
            }
            free(WAword);
            free(WAmeaning);
            return 0;

        default:
            printf("잘못된 메뉴를 선택했습니다. 다시 선택하세요.\n");
        }
    }

    return 0;
}
