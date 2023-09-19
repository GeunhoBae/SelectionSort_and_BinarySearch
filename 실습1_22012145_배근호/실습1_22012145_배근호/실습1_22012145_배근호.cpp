#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define SIZE 100000
#define COMPARE(m,k) (((m) < (k)) ? -1 : ((m) == (k)) ? 0 : 1))
#pragma warning(disable:4996)

void Sort(int list[], int n) {// 정렬함수
	int min, temp;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);

	}
}

int is_Sorted(int list[], int n) {//정렬확인 함수
	int isTrue = 1; //정렬이 올바르면 1 잘못됬다면 0
	for (int i = 0; i < n - 1; i++) {
		if (list[i] > list[i + 1]) {
			isTrue = 0;
			break;
		}
	}
	if (isTrue == 1)
		return 1;
	else return 0;
}

int bin_Search(int list[], int key, int left, int right, int* counter) { //이진검색 함수
	int middle;
	*counter = 0;
	while (left <= right) {
		*counter += 1;
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], key) {
		case -1: left = middle + 1; break;
		case 0: return middle;
		case 1: right = middle - 1;
		}
	}
	return -1;
}

int main() {
	printf("1.1	\n100,000만개의 무작위 정수 생성중\n");
	int A[SIZE];//배열생성
	for (int i = 0; i < SIZE; i++) { //배열에 수 넣기
		A[i] = (rand() % SIZE) + 1;
		printf("%d  ", A[i]);
	}
	printf("\n정수생성 완료\n정수정렬 시작\n");
	Sort(A, SIZE); //정렬시작
	for (int i = 0; i < SIZE; i++)
		printf("%d  ", A[i]);
	printf("\n정렬완료 \n정렬확인 시작\n");
	if (is_Sorted(A, SIZE) == 1) //정렬확인
		printf("정렬이 올바릅니다.");
	else printf("정렬이 올바르지 않습니다.");

	//1.2 시작
	printf("\n1.2\n 배열의 크기를 설정하시오.(종료는 -1)\n");
	static int B[1000000]; int size2; //두번째 배열
	while (1) {	//배열 반복설정
		scanf("%d", &size2);
		if (size2 == -1) { printf("배열설정을 종료합니다.\n"); break; }
		else for (int i = size2; i > 0; i--) {
			B[i - 1] = i;
		}
		double time = 0.0; //시간계산을 위한 걸린시간 변수
		clock_t start = clock();
		Sort(B, size2); //순차정렬 시작
		clock_t end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		char is_Clear[10] = "정렬됨";
		if (is_Sorted(B, size2) == 1) { //출력
			printf("크기: %d		시간: %f		정렬: %s\n", size2, time, is_Clear);
		}
		else printf("정렬되지않음");
	}

	//1.3
	printf("1.3");
	int key, left = 0, right = SIZE - 1, counter;
	while (1) {
		printf("\n검색어 입력(범위:1~100000, 종료: -1): ");
		scanf("%d", &key);
		if (key == -1) break;
		bin_Search(A, key, left, right, &counter);
		if (bin_Search(A, key, left, right, &counter) != -1) {
			printf("검색어: %d  Counter: %d:\n", key, counter);
		}
		else {
			printf("검색어: %d  Counter: -1:\n", key);
		}
	}

	//1.4
	printf("1.4 배열생성 및 정렬중\n");
	int c_size = 50000, d_size = 100000;
	int C[50000], D[100000];
	for (int i = c_size; i > 0; i--) {
		C[i - 1] = i;
	}
	for (int i = d_size; i > 0; i--) {
		D[i - 1] = i;
	}
	Sort(C, c_size); Sort(D, d_size);
	is_Sorted(C, c_size); is_Sorted(D, d_size);

	if (is_Sorted(C, c_size) == 1) //C 정렬확인
		printf("C의 정렬이 올바릅니다.\n");
	else printf("C의 정렬이 올바르지 않습니다.\n");

	if (is_Sorted(D, d_size) == 1) //D정렬확인
		printf("D의 정렬이 올바릅니다.");
	else printf("D의 정렬이 올바르지 않습니다.");

	//C배열 검색
	int key_c, left_c = 0, right_c = c_size - 1, counter_c;
	while (1) {
		printf("\nC배열 검색어 입력(범위:1~50000, 종료: -1): ");
		scanf("%d", &key_c);
		if (key_c == -1) break;
		bin_Search(C, key_c, left_c, right_c, &counter_c);
		if (bin_Search(C, key_c, left_c, right_c, &counter_c) != -1) {
			printf("검색어: %d  Counter: %d:\n", key_c, counter_c);
		}
		else {
			printf("검색어: %d  Counter: -1:\n", key_c);
		}
	}
	//D배열 검색
	int key_d, left_d = 0, right_d = d_size - 1, counter_d;
	while (1) {
		printf("\nD배열 검색어 입력(범위:1~100000, 종료: -1): ");
		scanf("%d", &key_d);
		if (key_d == -1) break;
		bin_Search(D, key_d, left_d, right_d, &counter_d);
		if (bin_Search(D, key_d, left_d, right_d, &counter_d) != -1) {
			printf("검색어: %d  Counter: %d:\n", key_d, counter_d);
		}
		else {
			printf("검색어: %d  Counter: -1:\n", key_d);
		}
	}
	printf("모든과정이 종료되었습니다.");
}