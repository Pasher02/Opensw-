#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DELIM_CHARS ", "
#define MAX_WORDS 512
#define MAX_LENGTH 50 //�ִ� ũ��� �ܾ� ����

char word[MAX_WORDS][MAX_LENGTH] = { "account", "account for", "benefit from", "condense", "condense into", "better", "conduct", "accrue", "conductor", "confirmation", "be aware of", "biannual", "accumulation",
    "confirmed", "beneficial", "beneficiary", "confiscate", "binding", "bill", "accurately", "achievement", "irretrievable", "issue", "be laid off", "landfill", "landslide", "itinerary", "agenda",
    "mutually", "natural disaster", "needlessly", "keynote speech", "laboratory", "lack", "municipal", "multiply", "mutual", "largely", "lastingly", "support", "irritate", "generous", "tolerant",
    "liberal", "reject", "substitute", "occur", "despise", "contempt", "gain", "avail", "educate", "resemble", "grasp", "reconsider", "prove", "illustrate", "exemplify", "conservative", "progressive",
    "fortify", "strengthen", "reproduce", "elicit", "extract", "implore", "appoint", "disgust", "preach", "worship", "yawn", "hiccup", "pillar", "servitude", "recreation", "punctuality",
    "fascination", "attraction", "vicious", "distrust", "suspicion", "endeavor", "devote", "pride", "proud", "discontinue", "ignore", "disregard", "neglect", "depend" };

char meaning[MAX_WORDS][MAX_LENGTH] = { "���", "~�� �����ϴ�", "~�κ��� ������ �޴�", "�����ϴ�", "~�� �����ϴ�", "~�� �����ϴ�", "�ǽ��ϴ�, �����ϴ�", "�����, �������", "������, ����", "Ȯ����", "~�� �����ϴ�",
    "�ݳ⸶����", "����, ������", "Ȯ�ε�", "������ ����", "������", "�м��ϴ�, �����ϴ�", "���ӷ� �ִ�", "��꼭, û����, ����", "��Ȯ��", "����, ����", "����ų �� ����", "�����ϴ�, �߱�, ����",
    "�ذ�Ǵ�", "�Ÿ���", "����, �����", "���ེ����", "�ǻ�����", "����", "����", "���ʿ��ϰ�", "��������", "�����", "�����ϴ�", "����", "�����ϴ�", "��ȣ��", "�ַ�, �뷮����",
    "��������, ��������", "����, ����", "¥�������ϴ�", "������, ������ ����", "������, �Ʒ��� �ִ�", "����������, �������", "�����ϴ�", "��ü, ����ϴ�", "�Ͼ��, ��Ÿ����",
    "����ϴ�", "���, ���", "����, ����, ���", "������ �Ǵ�", "�����ϴ�, �缺�ϴ�", "���", "���", "����ϴ�", "�����ϴ�", "�����ϴ�", "���� ���, �����ϴ�", "��������, ��������",
    "�����ϴ�, ��������", "�߰��ϰ� �ϴ�", "���ϰ��ϴ�, ��������", "�����Ű��;�����ϴ�", "�����", "�����, �����", "��û�ϴ�, ź���ϴ�", "�Ӹ��ϴ�", "������ϴ�, ������", "�����ϴ�", "�����ϴ�, ����",
    "��ǰ�ϴ�", "������", "���, �ּ�", "�뿹 ����", "�޾�, ����ȸ��", "�ð�����", "��Ȥ, �ŷ�", "����, �ŷ�", "�����, ������, Ÿ����", "�ҽ�, ��Ȥ", "�ǽ�, ����", "����ϴ�, ���",
    "��ġ��, ~�� �����ϴ�", "�ںν�, �ڶ�������", "�ڶ�������", "�����ϴ�, �����ϴ�", "�����ϴ�, �𸣴�ü�ϴ�", "�����ϴ�", "�¸�, ��Ȧ", "�����ϴ�, ~�����̴�" };

char** WAword;
char** WAmeaning;
int numwords = 90;
int WAnumwords = 0;

// Ʋ�� �ܾ� ������
void WrongAnswer(const char* wrongWord, const char* wrongMeaning) {
    if (WAnumwords >= MAX_WORDS) {
        printf("���� �ܾ �߰��� �� �����ϴ�. �ִ� ũ�⿡ �����߽��ϴ�.\n");
        return;
    }

    // ���� ���� ������ �迭 ����
    WAword = (char**)realloc(WAword, (WAnumwords + 1) * sizeof(char*));
    WAmeaning = (char**)realloc(WAmeaning, (WAnumwords + 1) * sizeof(char*));

    // �޸� �Ҵ�
    WAword[WAnumwords] = (char*)malloc(MAX_LENGTH * sizeof(char));
    WAmeaning[WAnumwords] = (char*)malloc(MAX_LENGTH * sizeof(char));

    // ���� �迭�� �߰�
    strcpy(WAword[WAnumwords], wrongWord);
    strcpy(WAmeaning[WAnumwords], wrongMeaning);
    WAnumwords++;
}

// ���ܾ� ���� 
void Quiz() {
    srand((unsigned int)time(NULL)); //���� �õ� ����

    printf("��� �����մϴ�.\n");

    int score = 0;
    int questionNum = 0;

    //���� 10����
    while (questionNum < 10 && numwords > 0) { 

        int Index = rand() % numwords;  // ���� �ε��� ����

        printf("\nQ%d. ���� �ܾ��� ����?\n", questionNum + 1); // ������ ������ȣ ���
        printf("%s: ", word[Index]);

        char ans[MAX_LENGTH];
        fgets(ans, MAX_LENGTH, stdin); // �� �Է�

        // ���� ���� ����
        if ((strlen(ans) > 0) && (ans[strlen(ans) - 1] == '\n')) {
            ans[strlen(ans) - 1] = '\0';
        }

        char* token = strtok(meaning[Index], DELIM_CHARS); //�ܾ� �� ','�� ����
        int correct = 0;

        // ����� �� �� �ϳ��� ���߸� ����ó��
        while (token != NULL) {
            if (strstr(ans, token) != NULL) {
                correct = 1;
                break;
            }
            token = strtok(NULL, DELIM_CHARS); 
        }

        if (correct) {
            printf("�����Դϴ�!\n");
            score++;
        }
        else {
            printf("Ʋ�Ƚ��ϴ�. ������ \"%s\"�Դϴ�.\n", meaning[Index]);
            // ���� �ܾ��忡 �߰�
            WrongAnswer(word[Index], meaning[Index]);
        }
        questionNum++;
    }

    printf("\n����: %d / %d\n", score, 10);
}

int main() {
    // ���� �ܾ��� �ʱ�ȭ
    WAword = (char**)malloc(MAX_WORDS * sizeof(char*));
    WAmeaning = (char**)malloc(MAX_WORDS * sizeof(char*));
    if (WAword == NULL || WAmeaning == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }
    for (int i = 0; i < MAX_WORDS; i++) {
        WAword[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
        WAmeaning[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
        if (WAword[i] == NULL || WAmeaning[i] == NULL) {
            printf("�޸� �Ҵ� ����\n");
            return 1;
        }
    }

    int menu;
    while (1) {
        // �޴� ǥ��
        printf("���� �ܾ���\n");
        printf("1. �ܾ� �߰�\n");
        printf("2. �ܾ��� ���\n");
        printf("3. ���� �ܾ��� ���\n");
        printf("4. ���� ����\n");
        printf("5. ����\n");
        printf("\n�޴��� �����ϼ���: ");
        scanf("%d", &menu);
        getchar();

        switch (menu) {
        case 1:
            if (numwords < MAX_WORDS) {
                printf("�ܾ� �߰�\n");                
                printf("�ܾ �Է��ϼ���: ");
                fgets(word[numwords], MAX_LENGTH, stdin);
                word[numwords][strlen(word[numwords]) - 1] = '\0'; // ���� ���� ����
                printf("���� �Է��ϼ���: ");
                fgets(meaning[numwords], MAX_LENGTH, stdin);
                meaning[numwords][strlen(meaning[numwords]) - 1] = '\0'; // ���� ���� ����

                numwords++;
            }
            else {
                printf("�� �̻� �ܾ �߰��� �� �����ϴ�.\n");
            }
            break;

        case 2:
            // ����� �ܾ� ���   
            printf("�ܾ��� ���\n");        
            if (numwords > 0) {
                for (int i = 0; i < numwords; i++) {
                    printf("%d. %s - %s\n", i + 1, word[i], meaning[i]);
                }
                printf("\n");
            }
            else {
                printf("����� �ܾ �����ϴ�\n\n");
            }
            break;

        case 3:
            //���� �ܾ� ���
            printf("���� �ܾ���:\n");
            if (WAnumwords > 0) {
                for (int i = 0; i < WAnumwords; i++) {
                    printf("%d. %s - %s\n", i + 1, WAword[i], WAmeaning[i]);
                }
                printf("\n");
            }
            else {
                printf("����� �ܾ �����ϴ�\n\n");
            }
            break;

        case 4:
            if (numwords == 0) {
                printf("��� ������ �ܾ �����ϴ�. ���� �ܾ �߰��ϼ���.\n");
            }
            else {
                Quiz();
            }
            break;

        case 5:
            // �޸� ����
            printf("����\n\n");
            for (int i = 0; i < MAX_WORDS; i++) {
                free(WAword[i]);
                free(WAmeaning[i]);
            }
            free(WAword);
            free(WAmeaning);
            return 0;

        default:
            printf("�߸��� �޴��� �����߽��ϴ�. �ٽ� �����ϼ���.\n");
        }
    }

    return 0;
}
